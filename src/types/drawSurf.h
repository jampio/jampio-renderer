#pragma once

#include <jampio/common/renderer/types/surfaceType.h>

typedef struct drawSurf_s {
	unsigned			sort;			// bit combination for fast compares
	surfaceType_t		*surface;		// any of surface*_t
} drawSurf_t;