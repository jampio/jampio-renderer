#pragma once

#include <jampio/shared/renderer_types.h> /* for glconfig_t */
#include <jampio/common/renderer/types/image.h>
#include "types/glstate.h"
#include "qgl.h"

int R_Images_StartIteration(void);
image_t *R_Images_GetNextIteration(void);
image_t *R_CreateImage(const glconfig_t& glConfig, glstate_t& glState, const char *name, const byte *pic, int width, int height, GLenum format, qboolean mipmap, qboolean allowPicmip, qboolean allowTC, int wrapClampMode, bool bRectangle = false);