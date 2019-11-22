#ifndef RASTERIZER_H
#define RASTERIZER_H
/* Rasterizing primitives onto a texturebuffer. */

#include "texturebuffer.h"

void SR_WritePixel(SR_TextureBuffer *buffer, const size_t *pos, const SR_Texel *value);

void SR_WriteLine(SR_TextureBuffer *buffer, const size_t *pos, const SR_Texel *value);

void SR_WriteTriangle(SR_TextureBuffer *buffer, const size_t *pos, const SR_Texel *value);

void SR_WriteTriangleLine(SR_TextureBuffer *buffer, const size_t* pos,  const SR_Texel *value);

#endif // RASTERIZER_H
