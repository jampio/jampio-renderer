#pragma once

#include <jampio/common/renderer/types/surfaceType.h>

// fwd declare
// TODO: remove
class CTRLandScape;

typedef struct srfTerrain_s
{
	surfaceType_t surfaceType;
	CTRLandScape *landscape;
} srfTerrain_t;