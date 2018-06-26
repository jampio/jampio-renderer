#pragma once

#include <jampio/common/filefmt.h>
#include <jampio/common/renderer/types/shader.h>

constexpr auto LIGHTMAP_2D = -4;        // shader is for 2D rendering
constexpr auto LIGHTMAP_BY_VERTEX = -3; // pre-lit triangle models
constexpr auto LIGHTMAP_WHITEIMAGE = -2;
constexpr auto LIGHTMAP_NONE = -1;

static const int lightmapsNone[MAXLIGHTMAPS] = 
{
	LIGHTMAP_NONE,
	LIGHTMAP_NONE,
	LIGHTMAP_NONE,
	LIGHTMAP_NONE
};

static const byte stylesDefault[MAXLIGHTMAPS] = 
{
	LS_NORMAL,
	LS_LSNONE,
	LS_LSNONE,
	LS_LSNONE
};

shader_t *R_FindShader(const char *name, const int *lightmapIndex, const byte *styles, qboolean mipRawImage);