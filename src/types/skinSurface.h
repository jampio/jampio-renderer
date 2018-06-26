#pragma once

#include <jampio/shared/shared.h>
#include <jampio/common/renderer/types/shader.h>

typedef struct {
	char		name[MAX_QPATH];
	shader_t	*shader;
} skinSurface_t;