#pragma once

#include <jampio/shared/shared.h>
#include <jampio/shared/renderer_types.h>
#include <jampio/common/renderer/types/surfaceType.h>

// when cgame directly specifies a polygon, it becomes a srfPoly_t
// as soon as it is called
typedef struct srfPoly_s {
	surfaceType_t	surfaceType;
	qhandle_t		hShader;
	int				fogIndex;
	int				numVerts;
	polyVert_t		*verts;
} srfPoly_t;
