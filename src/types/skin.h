#pragma once

#include <jampio/shared/shared.h>
#include "skinSurface.h"

typedef struct skin_s {
	char		name[MAX_QPATH];		// game path, including extension
	int			numSurfaces;
	skinSurface_t	*surfaces[128];
} skin_t;