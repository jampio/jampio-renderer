#pragma once

#include "../qgl.h"
#include <jampio/shared/shared.h>
#include <jampio/common/renderer/types/image.h>
#include <jampio/common/renderer/types/shader.h>
#include <jampio/common/renderer/types/model.h>
#include "world.h"
#include "trRefEntity.h"
#include "viewParms.h"
#include "trRefdef.h"
#include "frontEndCounters.h"
#include "skin.h"
#include "srfTerrain.h"

constexpr auto NUM_SCRATCH_IMAGES = 16;
constexpr auto MAX_LIGHTMAPS = 256;
constexpr auto MAX_SHADERS = 16384;
constexpr auto MAX_MOD_KNOWN = 1024;
constexpr auto MAX_SKINS = 1024;
constexpr auto FUNCTABLE_SIZE = 1024;
constexpr auto FOG_TABLE_SIZE = 256;

typedef struct {
	qboolean				registered;		// cleared at shutdown, set at beginRegistration

	int						visCount;		// incremented every time a new vis cluster is entered
	int						frameCount;		// incremented every frame
	int						sceneCount;		// incremented every scene
	int						viewCount;		// incremented every view (twice a scene if portaled)
											// and every R_MarkFragments call

	int						frameSceneNum;	// zeroed at RE_BeginFrame

	qboolean				worldMapLoaded;
	world_t					*world;

#ifdef _XBOX
	SPARC<byte>				*externalVisData;	// from RE_SetWorldVisData, shared with CM_Load
#else
	const byte				*externalVisData;	// from RE_SetWorldVisData, shared with CM_Load
#endif

	image_t					*defaultImage;
	image_t					*scratchImage[NUM_SCRATCH_IMAGES];
	image_t					*fogImage;
	image_t					*dlightImage;	// inverse-quare highlight for projective adding
	image_t					*flareImage;
	image_t					*whiteImage;			// full of 0xff
	image_t					*identityLightImage;	// full of tr.identityLightByte

	image_t					*screenImage; //reserve us a gl texnum to use with RF_DISTORTION

#ifndef _XBOX	// GLOWXXX
	// Handle to the Glow Effect Vertex Shader. - AReis
	GLuint					glowVShader;

	// Handle to the Glow Effect Pixel Shader. - AReis
	GLuint					glowPShader;

	// Image the glowing objects are rendered to. - AReis
	GLuint					screenGlow;

	// A rectangular texture representing the normally rendered scene.
	GLuint					sceneImage;

	// Image used to downsample and blur scene to.	- AReis
	GLuint					blurImage;
#endif

	shader_t				*defaultShader;
	shader_t				*shadowShader;
	shader_t				*distortionShader;
	shader_t				*projectionShadowShader;

	shader_t				*sunShader;

	int						numLightmaps;
	image_t					*lightmaps[MAX_LIGHTMAPS];

	trRefEntity_t			*currentEntity;
	trRefEntity_t			worldEntity;		// point currentEntity at this when rendering world
	int						currentEntityNum;
	int						shiftedEntityNum;	// currentEntityNum << QSORT_ENTITYNUM_SHIFT
	model_t					*currentModel;

	viewParms_t				viewParms;

	float					identityLight;		// 1.0 / ( 1 << overbrightBits )
	int						identityLightByte;	// identityLight * 255
	int						overbrightBits;		// r_overbrightBits->integer, but set to 0 if no hw gamma

	orientationr_t			ori;					// for current entity

	trRefdef_t				refdef;

	int						viewCluster;

	vec3_t					sunLight;			// from the sky shader for this level
	vec3_t					sunDirection;
	int						sunSurfaceLight;	// from the sky shader for this level
	vec3_t					sunAmbient;			// from the sky shader	(only used for John's terrain system)

	frontEndCounters_t		pc;
	int						frontEndMsec;		// not in pc due to clearing issue

	//
	// put large tables at the end, so most elements will be
	// within the +/32K indexed range on risc processors
	//
	model_t					*models[MAX_MOD_KNOWN];
	int						numModels;

	world_t					bspModels[MAX_SUB_BSP];
	int						numBSPModels;

	// shader indexes from other modules will be looked up in tr.shaders[]
	// shader indexes from drawsurfs will be looked up in sortedShaders[]
	// lower indexed sortedShaders must be rendered first (opaque surfaces before translucent)
	int						numShaders;
	shader_t				*shaders[MAX_SHADERS];
	shader_t				*sortedShaders[MAX_SHADERS];

	int						numSkins;
	skin_t					*skins[MAX_SKINS];

	float					sinTable[FUNCTABLE_SIZE];
	float					squareTable[FUNCTABLE_SIZE];
	float					triangleTable[FUNCTABLE_SIZE];
	float					sawToothTable[FUNCTABLE_SIZE];
	float					inverseSawToothTable[FUNCTABLE_SIZE];
	float					fogTable[FOG_TABLE_SIZE];

	float					rangedFog;
	float					distanceCull, distanceCullSquared; //rwwRMG - added

	srfTerrain_t			landScape; //rwwRMG - added
} trGlobals_t;