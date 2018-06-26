#pragma once

#include <jampio/shared/renderer_types.h>

// a trMiniRefEntity_t has all the information passed in by
// the client game, other info will come from it's parent main ref entity
typedef struct 
{
	miniRefEntity_t	e;
} trMiniRefEntity_t;
