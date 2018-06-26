#pragma once

#include <jampio/common/Cvar.h>

extern Cvar *r_ignore;				// used for debugging anything
extern Cvar *r_verbose;				// used for verbose debug spew
extern Cvar *r_znear;				// near Z clip plane
extern Cvar *r_stencilbits;			// number of desired stencil bits
extern Cvar *r_depthbits;			// number of desired depth bits
extern Cvar *r_colorbits;			// number of desired color bits, only relevant for fullscreen
extern Cvar *r_stereo;				// desired pixelformat stereo flag
extern Cvar *r_texturebits;			// number of desired texture bits
										// 0 = use framebuffer depth
										// 16 = use 16-bit textures
										// 32 = use 32-bit textures
										// all else = error
extern Cvar *r_texturebitslm;		// number of desired lightmap texture bits
extern Cvar *r_measureOverdraw;		// enables stencil buffer overdraw measurement
extern Cvar *r_lodbias;				// push/pull LOD transitions
extern Cvar *r_lodscale;
extern Cvar *r_autolodscalevalue;
extern Cvar *r_primitives;			// "0" = based on compiled vertex array existance
										// "1" = glDrawElemet tristrips
										// "2" = glDrawElements triangles
										// "-1" = no drawing
extern Cvar *r_inGameVideo;				// controls whether in game video should be draw
extern Cvar *r_fastsky;				// controls whether sky should be cleared or drawn
extern Cvar *r_drawSun;				// controls drawing of sun quad
extern Cvar *r_dynamiclight;		// dynamic lights enabled/disabled
// rjr - removed for hacking extern cvar_t	*r_dlightBacks;			// dlight non-facing surfaces for continuity
extern Cvar *r_norefresh;			// bypasses the ref rendering
extern Cvar *r_drawentities;		// disable/enable entity rendering
extern Cvar *r_drawworld;			// disable/enable world rendering
extern Cvar *r_drawfog;				// disable/enable fog rendering
extern Cvar *r_speeds;				// various levels of information display
extern Cvar *r_detailTextures;		// enables/disables detail texturing stages
extern Cvar *r_novis;				// disable/enable usage of PVS
extern Cvar *r_nocull;
extern Cvar *r_facePlaneCull;		// enables culling of planar surfaces with back side test
extern Cvar *r_cullRoofFaces; //attempted smart method of culling out upwards facing surfaces on roofs for automap shots -rww
extern Cvar *r_roofCullCeilDist; //ceiling distance cull tolerance -rww
extern Cvar *r_roofCullFloorDist; //floor distance cull tolerance -rww
extern Cvar *r_nocurves;
extern Cvar *r_showcluster;
extern Cvar *r_autoMap; //automap renderside toggle for debugging -rww
extern Cvar *r_autoMapBackAlpha; //alpha of automap bg -rww
extern Cvar *r_autoMapDisable;
extern Cvar *r_dlightStyle;
extern Cvar *r_surfaceSprites;
extern Cvar *r_surfaceWeather;
extern Cvar *r_windSpeed;
extern Cvar *r_windAngle;
extern Cvar *r_windGust;
extern Cvar *r_windDampFactor;
extern Cvar *r_windPointForce;
extern Cvar *r_windPointX;
extern Cvar *r_windPointY;
extern Cvar *r_mode;				// video mode
extern Cvar *r_fullscreen;
extern Cvar *r_gamma;
extern Cvar *r_displayRefresh;		// optional display refresh option
extern Cvar *r_ignorehwgamma;		// overrides hardware gamma capabilities
extern Cvar *r_allowExtensions;				// global enable/disable of OpenGL extensions
extern Cvar *r_ext_compressed_textures;		// these control use of specific extensions
extern Cvar *r_ext_compressed_lightmaps;	// turns on compression of lightmaps, off by default
extern Cvar *r_ext_preferred_tc_method;
extern Cvar *r_ext_gamma_control;
extern Cvar *r_ext_texenv_op;
extern Cvar *r_ext_multitexture;
extern Cvar *r_ext_compiled_vertex_array;
extern Cvar *r_ext_texture_env_add;
extern Cvar *r_ext_texture_filter_anisotropic;
extern Cvar *r_DynamicGlow;
extern Cvar *r_DynamicGlowPasses;
extern Cvar *r_DynamicGlowDelta;
extern Cvar *r_DynamicGlowIntensity;
extern Cvar *r_DynamicGlowSoft;
extern Cvar *r_DynamicGlowWidth;
extern Cvar *r_DynamicGlowHeight;
extern Cvar *r_nobind;						// turns off binding to appropriate textures
extern Cvar *r_singleShader;				// make most world faces use default shader
extern Cvar *r_colorMipLevels;				// development aid to see texture mip usage
extern Cvar *r_picmip;						// controls picmip values
extern Cvar *r_finish;
extern Cvar *r_swapInterval;
extern Cvar *r_markcount;
extern Cvar *r_textureMode;
extern Cvar *r_offsetFactor;
extern Cvar *r_offsetUnits;
extern Cvar *r_fullbright;					// avoid lightmap pass
extern Cvar *r_lightmap;					// render lightmaps only
extern Cvar *r_vertexLight;					// vertex lighting mode for better performance
extern Cvar *r_uiFullScreen;				// ui is running fullscreen
extern Cvar *r_logFile;						// number of frames to emit GL logs
extern Cvar *r_showtris;					// enables wireframe rendering of the world
extern Cvar *r_showsky;						// forces sky in front of all surfaces
extern Cvar *r_shownormals;					// draws wireframe normals
extern Cvar *r_clear;						// force screen clear every frame
extern Cvar *r_shadows;						// controls shadows: 0 = none, 1 = blur, 2 = stencil, 3 = black planar projection
extern Cvar *r_flares;						// light flares
extern Cvar *r_intensity;
extern Cvar *r_lockpvs;
extern Cvar *r_noportals;
extern Cvar *r_portalOnly;
extern Cvar *r_subdivisions;
extern Cvar *r_lodCurveError;
extern Cvar *r_skipBackEnd;
extern Cvar *r_ignoreGLErrors;
extern Cvar *r_overBrightBits;
extern Cvar *r_debugSurface;
extern Cvar *r_simpleMipMaps;
extern Cvar *r_showImages;
extern Cvar *r_debugSort;

#ifdef _DEBUG
extern Cvar *r_noPrecacheGLA;
#endif

extern Cvar *r_noServerGhoul2;