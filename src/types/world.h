#pragma once

#include <jampio/shared/shared.h>
#include <jampio/common/filefmt.h>
#include <jampio/common/renderer/types/bmodel.h>
#include "mnode.h"
#include "fog.h"
#include "mgrid.h"

typedef struct {
	char		name[MAX_QPATH];		// ie: maps/tim_dm2.bsp
	char		baseName[MAX_QPATH];	// ie: tim_dm2

	int			dataSize;

	int			numShaders;
	dshader_t	*shaders;

	bmodel_t	*bmodels;

	int			numplanes;
	cplane_t	*planes;

	int			numnodes;		// includes leafs
	int			numDecisionNodes;
	mnode_t		*nodes;

	int			numsurfaces;
	msurface_t	*surfaces;

	int			nummarksurfaces;
	msurface_t	**marksurfaces;

	int			numfogs;
	fog_t		*fogs;
	int			globalFog;


	vec3_t		lightGridOrigin;
	vec3_t		lightGridSize;
	vec3_t		lightGridInverseSize;
	int			lightGridBounds[3];

	int			lightGridOffsets[8];

	vec3_t		lightGridStep;

	mgrid_t			*lightGridData;
	word		*lightGridArray;
	int			numGridArrayElements;


	int			numClusters;
	int			clusterBytes;
	const byte	*vis;			// may be passed in by CM_LoadMap to save space

	byte		*novis;			// clusterBytes of 0xff

	char		*entityString;
	char		*entityParsePoint;
} world_t;