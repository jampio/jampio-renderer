#pragma once
// Known chunk types

#define PNG_IHDR 'IHDR'
#define PNG_IDAT 'IDAT' 
#define PNG_IEND 'IEND'
#define PNG_tEXt 'tEXt'
#define PNG_PLTE 'PLTE'
#define PNG_bKGD 'bKGD'
#define PNG_cHRM 'cHRM'
#define PNG_gAMA 'gAMA'
#define PNG_hIST 'hIST'
#define PNG_iCCP 'iCCP'
#define PNG_iTXt 'iTXt'
#define PNG_oFFs 'oFFs'
#define PNG_pCAL 'pCAL'
#define PNG_sCAL 'sCAL'
#define PNG_pHYs 'pHYs'
#define PNG_sBIT 'sBIT'
#define PNG_sPLT 'sPLT'
#define PNG_sRGB 'sRGB'
#define PNG_tIME 'tIME'
#define PNG_tRNS 'tRNS'
#define PNG_zTXt 'zTXt'

// Filter values 

#define PNG_FILTER_VALUE_NONE	0
#define PNG_FILTER_VALUE_SUB	1
#define PNG_FILTER_VALUE_UP		2
#define PNG_FILTER_VALUE_AVG	3
#define PNG_FILTER_VALUE_PAETH	4
#define PNG_FILTER_NUM			5

// Common defines and typedefs

#define MAX_PNG_WIDTH			4096
#define MAX_PNG_DEPTH			4

typedef unsigned char	png_byte;
typedef unsigned long	png_ulong;

typedef struct png_ihdr_s
{
	png_ulong			width;
	png_ulong			height;
	png_byte			bitdepth;			// Bits per sample (not per pixel)
	png_byte			colortype;			// bit 0 - palette; bit 1 - RGB; bit 2 - alpha channel
	png_byte			compression;		// 0 for zip - error otherwise
	png_byte			filter;				// 0 for adaptive with the 5 basic types - error otherwise
	png_byte			interlace;			// 0 for no interlace - 1 for Adam7 interlace
} png_ihdr_t;

typedef struct png_image_s
{
	png_byte			*data;
	png_ulong			width;
	png_ulong			height;
	png_ulong			bytedepth;
	bool			isimage;
} png_image_t;

bool LoadPNG32(const char *name, png_byte **pixels, int *width, int *height, int *bytedepth);
bool LoadPNG8(const char *name, png_byte **pixels, int *width, int *height);
bool PNG_Save(const char *name, png_byte *data, int width, int height, int bytedepth);
