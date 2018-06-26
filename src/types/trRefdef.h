#pragma once

#include <jampio/shared/shared.h>
#include <jampio/shared/renderer_types.h>
#include "trRefEntity.h"
#include "trMiniRefEntity.h"
#include "dlight.h"
#include "srfPoly.h"
#include "drawSurf.h"

// trRefdef_t holds everything that comes in refdef_t,
// as well as the locally generated scene information
typedef struct {
	int			x, y, width, height;
	float		fov_x, fov_y;
	vec3_t		vieworg;
	vec3_t		viewaxis[3];		// transformation matrix

	int			time;				// time in milliseconds for shader effects and other time dependent rendering issues
	int			frametime;
	int			rdflags;			// RDF_NOWORLDMODEL, etc

	// 1 bits will prevent the associated area from rendering at all
	byte		areamask[MAX_MAP_AREA_BYTES];
	qboolean	areamaskModified;	// qtrue if areamask changed since last scene

	float		floatTime;			// tr.refdef.time / 1000.0

	// text messages for deform text shaders
	char		text[MAX_RENDER_STRINGS][MAX_RENDER_STRING_LENGTH];

	int			num_entities;
	trRefEntity_t	*entities;
	trMiniRefEntity_t	*miniEntities;

#ifndef VV_LIGHTING
	int			num_dlights;
	dlight_t *dlights;
#endif

	int			numPolys;
	srfPoly_t	*polys;

	int			numDrawSurfs;
	drawSurf_t *drawSurfs;
} trRefdef_t;