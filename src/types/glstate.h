#pragma once

#include <jampio/shared/shared.h>

// the renderer front end should never modify glstate_t
typedef struct {
	int			currenttextures[2];
	int			currenttmu;
	qboolean	finishCalled;
	int			texEnv[2];
	int			faceCulling;
	unsigned long	glStateBits;
} glstate_t;