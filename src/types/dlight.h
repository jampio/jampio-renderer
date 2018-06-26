#pragma once

#include <jampio/shared/vec.h>

typedef enum
{
	DLIGHT_VERTICAL	= 0,
	DLIGHT_PROJECTED
} eDLightTypes;

typedef struct dlight_s {
	eDLightTypes	mType;

	vec3_t			origin;
	vec3_t			mProjOrigin;		// projected light's origin

	vec3_t			color;				// range from 0.0 to 1.0, should be color normalized

	float			radius;
	float			mProjRadius;		// desired radius of light 

	int				additive;			// texture detail is lost tho when the lightmap is dark

	vec3_t			transformed;		// origin in local coordinate system
	vec3_t			mProjTransformed;	// projected light's origin in local coordinate system

	vec3_t			mDirection;
	vec3_t			mBasis2;
	vec3_t			mBasis3;

	vec3_t			mTransDirection;
	vec3_t			mTransBasis2;
	vec3_t			mTransBasis3;
} dlight_t;
