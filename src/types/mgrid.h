#pragma once

#include <jampio/shared/shared.h>
#include <jampio/common/filefmt.h>

typedef struct 
{
	byte		ambientLight[MAXLIGHTMAPS][3];
	byte		directLight[MAXLIGHTMAPS][3];
	byte		styles[MAXLIGHTMAPS];
	byte		latLong[2];
//	byte		pad[2];								// to align to a cache line
} mgrid_t;