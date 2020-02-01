#ifndef TYPES_H
#define TYPES_H
/* Common shared definitions, typedefs and structs. */

#include <stdint.h>
#include <stdlib.h>

// Common Constants and Enumerations
enum SR_PRIMITIVE_TYPE
    {SR_POINTS = 1,
     SR_LINES,
     SR_TRIANGLES};

enum SR_BUFFER_TYPE
    { SR_VERTEX_BUFFER,
      SR_INDEX_BUFFER};

enum SR_SHADER_TYPE
    { SR_VERTEX_SHADER,
      SR_FRAGMENT_SHADER };

enum SR_RENDER_TARGET_BIT
    {SR_COLOR_BUFFER_BIT = 1,
     SR_DEPTH_BUFFER_BIT = 2};


// Texturebuffer
typedef struct {
    size_t width;
    size_t height;
    uint8_t fsize;
    uint8_t *values;
} SR_TexBuffer2D;
#define SR_NULL_TEXBUFFER (SR_TexBuffer2D){.width=0,.height=0,.fsize=0,.values=NULL}

// Texture Format
// Avaliable texture formats defined as sizes (in bytes).
#define SR_TEX_FORMAT_R8     1
#define SR_TEX_FORMAT_RG16   2
#define SR_TEX_FORMAT_RGB8   3
#define SR_TEX_FORMAT_RGBA8  4
#define SR_TEX_FORMAT_RGB16  6
#define SR_TEX_FORMAT_RGBA16 8
#define SR_TEX_FORMAT_32F    (sizeof(float))


// Common vector types
typedef struct { double x; }          SR_Vec1f;
typedef struct { double x, y; }       SR_Vec2f;
typedef struct { double x, y, z; }    SR_Vec3f;
typedef struct { double x, y, z, w; } SR_Vec4f;
typedef union {
    SR_Vec1f vec1f;
    SR_Vec2f vec2f;
    SR_Vec3f vec3f;
    SR_Vec4f vec4f;
} SR_Vecf;

// Vertex attribute data
typedef struct {
    size_t count;  // Package size
    size_t stride; // Stride in bytes
    size_t offset; // Offset in bytes
} SR_VertexAttribute;

// Vertex, index and attribute data collection
typedef struct {
    double* vertexBuffer;
    size_t* indexBuffer;
    size_t vertexBufferSize;
    size_t indexBufferSize;
    size_t attributesCount;
    SR_VertexAttribute* attributes;
} SR_VertexArray; 

// Framebuffer 
typedef struct {
    SR_TexBuffer2D color;
    SR_TexBuffer2D depth;
} SR_FrameBuffer;

// Shader functions
typedef void(*SR_Shader)(size_t, SR_Vecf*, SR_Vec4f*);

// Collection of shader objects in a pipeline
typedef struct {
    SR_Shader vertexShader;
    SR_Shader fragmentShader;
} SR_Pipeline;

// Write functions
typedef void(*SR_Write)(SR_FrameBuffer*, const int*, const SR_Shader shader);

#endif // TYPES_H
