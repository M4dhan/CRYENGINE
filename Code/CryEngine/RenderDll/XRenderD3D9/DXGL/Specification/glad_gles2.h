// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#ifndef __glad_h_

#ifdef __gl_h_
	#error OpenGL header already included, remove this include, glad already provides it
#endif

#define __glad_h_
#define __gl_h_

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN 1
	#endif
	#include <windows.h>
#endif

#ifndef APIENTRY
	#define APIENTRY
#endif
#ifndef APIENTRYP
	#define APIENTRYP APIENTRY *
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct gladGLversionStruct
{
	int major;
	int minor;
};

extern struct gladGLversionStruct GLVersion;

#ifndef __gladloadproc__
	#define __gladloadproc__
typedef void* (* GLADloadproc)(const char* name);
#endif

#ifndef GLAPI
	#if defined(GLAD_GLAPI_EXPORT)
		#if defined(WIN32) || defined(__CYGWIN__)
			#if defined(GLAD_GLAPI_EXPORT_BUILD)
				#if defined(__GNUC__)
					#define GLAPI __attribute__ ((dllexport)) extern
				#else
					#define GLAPI __declspec(dllexport) extern
				#endif
			#else
				#if defined(__GNUC__)
					#define GLAPI __attribute__ ((dllimport)) extern
				#else
					#define GLAPI __declspec(dllimport) extern
				#endif
			#endif
		#elif defined(__GNUC__) && defined(GLAD_GLAPI_EXPORT_BUILD)
			#define GLAPI __attribute__ ((visibility("default"))) extern
		#else
			#define GLAPI extern
		#endif
	#else
		#define GLAPI extern
	#endif
#endif

GLAPI int gladLoadGL(void);

GLAPI int gladLoadGLES2Loader(GLADloadproc);

#include <stddef.h>
#include "khrplatform.h"
#ifndef GLEXT_64_TYPES_DEFINED
/* This code block is duplicated in glxext.h, so must be protected */
	#define GLEXT_64_TYPES_DEFINED
/* Define int32_t, int64_t, and uint64_t types for UST/MSC */
/* (as used in the GL_EXT_timer_query extension). */
	#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
		#include <inttypes.h>
	#elif defined(__sun__) || defined(__digital__)
		#include <inttypes.h>
		#if defined(__STDC__)
			#if defined(__arch64__) || defined(_LP64)
typedef long int               int64_t;
typedef unsigned long int      uint64_t;
			#else
typedef long long int          int64_t;
typedef unsigned long long int uint64_t;
			#endif /* __arch64__ */
		#endif   /* __STDC__ */
	#elif defined(__VMS) || defined(__sgi)
		#include <inttypes.h>
	#elif defined(__SCO__) || defined(__USLC__)
		#include <stdint.h>
	#elif defined(__UNIXOS2__) || defined(__SOL64__)
typedef long int               int32_t;
typedef long long int          int64_t;
typedef unsigned long long int uint64_t;
	#elif defined(_WIN32) && defined(__GNUC__)
		#include <stdint.h>
	#elif defined(_WIN32)
typedef __int32          int32_t;
typedef __int64          int64_t;
typedef unsigned __int64 uint64_t;
	#else
/* Fallback if nothing above works */
		#include <inttypes.h>
	#endif
#endif
typedef unsigned int     GLenum;
typedef unsigned char    GLboolean;
typedef unsigned int     GLbitfield;
typedef void             GLvoid;
typedef signed char      GLbyte;
typedef short            GLshort;
typedef int              GLint;
typedef int              GLclampx;
typedef unsigned char    GLubyte;
typedef unsigned short   GLushort;
typedef unsigned int     GLuint;
typedef int              GLsizei;
typedef float            GLfloat;
typedef float            GLclampf;
typedef double           GLdouble;
typedef double           GLclampd;
typedef void*            GLeglImageOES;
typedef char             GLchar;
typedef char             GLcharARB;
#ifdef __APPLE__
typedef void*            GLhandleARB;
#else
typedef unsigned int     GLhandleARB;
#endif
typedef unsigned short   GLhalfARB;
typedef unsigned short   GLhalf;
typedef GLint            GLfixed;
typedef ptrdiff_t        GLintptr;
typedef ptrdiff_t        GLsizeiptr;
typedef int64_t          GLint64;
typedef uint64_t         GLuint64;
typedef ptrdiff_t        GLintptrARB;
typedef ptrdiff_t        GLsizeiptrARB;
typedef int64_t          GLint64EXT;
typedef uint64_t         GLuint64EXT;
typedef struct __GLsync* GLsync;
struct _cl_context;
struct _cl_event;
typedef void (APIENTRY * GLDEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
typedef void (APIENTRY * GLDEBUGPROCARB)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
typedef void (APIENTRY * GLDEBUGPROCKHR)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
typedef void (APIENTRY * GLDEBUGPROCAMD)(GLuint id, GLenum category, GLenum severity, GLsizei length, const GLchar* message, void* userParam);
typedef unsigned short   GLhalfNV;
typedef GLintptr         GLvdpauSurfaceNV;
#define GL_DEPTH_BUFFER_BIT                              0x00000100
#define GL_STENCIL_BUFFER_BIT                            0x00000400
#define GL_COLOR_BUFFER_BIT                              0x00004000
#define GL_FALSE                                         0
#define GL_TRUE                                          1
#define GL_POINTS                                        0x0000
#define GL_LINES                                         0x0001
#define GL_LINE_LOOP                                     0x0002
#define GL_LINE_STRIP                                    0x0003
#define GL_TRIANGLES                                     0x0004
#define GL_TRIANGLE_STRIP                                0x0005
#define GL_TRIANGLE_FAN                                  0x0006
#define GL_ZERO                                          0
#define GL_ONE                                           1
#define GL_SRC_COLOR                                     0x0300
#define GL_ONE_MINUS_SRC_COLOR                           0x0301
#define GL_SRC_ALPHA                                     0x0302
#define GL_ONE_MINUS_SRC_ALPHA                           0x0303
#define GL_DST_ALPHA                                     0x0304
#define GL_ONE_MINUS_DST_ALPHA                           0x0305
#define GL_DST_COLOR                                     0x0306
#define GL_ONE_MINUS_DST_COLOR                           0x0307
#define GL_SRC_ALPHA_SATURATE                            0x0308
#define GL_FUNC_ADD                                      0x8006
#define GL_BLEND_EQUATION                                0x8009
#define GL_BLEND_EQUATION_RGB                            0x8009
#define GL_BLEND_EQUATION_ALPHA                          0x883D
#define GL_FUNC_SUBTRACT                                 0x800A
#define GL_FUNC_REVERSE_SUBTRACT                         0x800B
#define GL_BLEND_DST_RGB                                 0x80C8
#define GL_BLEND_SRC_RGB                                 0x80C9
#define GL_BLEND_DST_ALPHA                               0x80CA
#define GL_BLEND_SRC_ALPHA                               0x80CB
#define GL_CONSTANT_COLOR                                0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR                      0x8002
#define GL_CONSTANT_ALPHA                                0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA                      0x8004
#define GL_BLEND_COLOR                                   0x8005
#define GL_ARRAY_BUFFER                                  0x8892
#define GL_ELEMENT_ARRAY_BUFFER                          0x8893
#define GL_ARRAY_BUFFER_BINDING                          0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING                  0x8895
#define GL_STREAM_DRAW                                   0x88E0
#define GL_STATIC_DRAW                                   0x88E4
#define GL_DYNAMIC_DRAW                                  0x88E8
#define GL_BUFFER_SIZE                                   0x8764
#define GL_BUFFER_USAGE                                  0x8765
#define GL_CURRENT_VERTEX_ATTRIB                         0x8626
#define GL_FRONT                                         0x0404
#define GL_BACK                                          0x0405
#define GL_FRONT_AND_BACK                                0x0408
#define GL_TEXTURE_2D                                    0x0DE1
#define GL_CULL_FACE                                     0x0B44
#define GL_BLEND                                         0x0BE2
#define GL_DITHER                                        0x0BD0
#define GL_STENCIL_TEST                                  0x0B90
#define GL_DEPTH_TEST                                    0x0B71
#define GL_SCISSOR_TEST                                  0x0C11
#define GL_POLYGON_OFFSET_FILL                           0x8037
#define GL_SAMPLE_ALPHA_TO_COVERAGE                      0x809E
#define GL_SAMPLE_COVERAGE                               0x80A0
#define GL_NO_ERROR                                      0
#define GL_INVALID_ENUM                                  0x0500
#define GL_INVALID_VALUE                                 0x0501
#define GL_INVALID_OPERATION                             0x0502
#define GL_OUT_OF_MEMORY                                 0x0505
#define GL_CW                                            0x0900
#define GL_CCW                                           0x0901
#define GL_LINE_WIDTH                                    0x0B21
#define GL_ALIASED_LINE_WIDTH_RANGE                      0x846E
#define GL_CULL_FACE_MODE                                0x0B45
#define GL_FRONT_FACE                                    0x0B46
#define GL_DEPTH_RANGE                                   0x0B70
#define GL_DEPTH_WRITEMASK                               0x0B72
#define GL_DEPTH_CLEAR_VALUE                             0x0B73
#define GL_DEPTH_FUNC                                    0x0B74
#define GL_STENCIL_CLEAR_VALUE                           0x0B91
#define GL_STENCIL_FUNC                                  0x0B92
#define GL_STENCIL_FAIL                                  0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL                       0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS                       0x0B96
#define GL_STENCIL_REF                                   0x0B97
#define GL_STENCIL_VALUE_MASK                            0x0B93
#define GL_STENCIL_WRITEMASK                             0x0B98
#define GL_STENCIL_BACK_FUNC                             0x8800
#define GL_STENCIL_BACK_FAIL                             0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL                  0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS                  0x8803
#define GL_STENCIL_BACK_REF                              0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK                       0x8CA4
#define GL_STENCIL_BACK_WRITEMASK                        0x8CA5
#define GL_VIEWPORT                                      0x0BA2
#define GL_SCISSOR_BOX                                   0x0C10
#define GL_COLOR_CLEAR_VALUE                             0x0C22
#define GL_COLOR_WRITEMASK                               0x0C23
#define GL_UNPACK_ALIGNMENT                              0x0CF5
#define GL_PACK_ALIGNMENT                                0x0D05
#define GL_MAX_TEXTURE_SIZE                              0x0D33
#define GL_MAX_VIEWPORT_DIMS                             0x0D3A
#define GL_SUBPIXEL_BITS                                 0x0D50
#define GL_POLYGON_OFFSET_UNITS                          0x2A00
#define GL_POLYGON_OFFSET_FACTOR                         0x8038
#define GL_TEXTURE_BINDING_2D                            0x8069
#define GL_SAMPLE_BUFFERS                                0x80A8
#define GL_SAMPLES                                       0x80A9
#define GL_SAMPLE_COVERAGE_VALUE                         0x80AA
#define GL_SAMPLE_COVERAGE_INVERT                        0x80AB
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS                0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS                    0x86A3
#define GL_DONT_CARE                                     0x1100
#define GL_FASTEST                                       0x1101
#define GL_NICEST                                        0x1102
#define GL_BYTE                                          0x1400
#define GL_UNSIGNED_BYTE                                 0x1401
#define GL_SHORT                                         0x1402
#define GL_UNSIGNED_SHORT                                0x1403
#define GL_INT                                           0x1404
#define GL_UNSIGNED_INT                                  0x1405
#define GL_FLOAT                                         0x1406
#define GL_FIXED                                         0x140C
#define GL_DEPTH_COMPONENT                               0x1902
#define GL_ALPHA                                         0x1906
#define GL_RGB                                           0x1907
#define GL_RGBA                                          0x1908
#define GL_UNSIGNED_SHORT_4_4_4_4                        0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1                        0x8034
#define GL_UNSIGNED_SHORT_5_6_5                          0x8363
#define GL_FRAGMENT_SHADER                               0x8B30
#define GL_VERTEX_SHADER                                 0x8B31
#define GL_MAX_VERTEX_ATTRIBS                            0x8869
#define GL_MAX_VERTEX_UNIFORM_VECTORS                    0x8DFB
#define GL_MAX_VARYING_VECTORS                           0x8DFC
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS              0x8B4D
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS                0x8B4C
#define GL_MAX_TEXTURE_IMAGE_UNITS                       0x8872
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS                  0x8DFD
#define GL_SHADER_TYPE                                   0x8B4F
#define GL_DELETE_STATUS                                 0x8B80
#define GL_LINK_STATUS                                   0x8B82
#define GL_VALIDATE_STATUS                               0x8B83
#define GL_ATTACHED_SHADERS                              0x8B85
#define GL_ACTIVE_UNIFORMS                               0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH                     0x8B87
#define GL_ACTIVE_ATTRIBUTES                             0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH                   0x8B8A
#define GL_SHADING_LANGUAGE_VERSION                      0x8B8C
#define GL_CURRENT_PROGRAM                               0x8B8D
#define GL_NEVER                                         0x0200
#define GL_LESS                                          0x0201
#define GL_EQUAL                                         0x0202
#define GL_LEQUAL                                        0x0203
#define GL_GREATER                                       0x0204
#define GL_NOTEQUAL                                      0x0205
#define GL_GEQUAL                                        0x0206
#define GL_ALWAYS                                        0x0207
#define GL_KEEP                                          0x1E00
#define GL_REPLACE                                       0x1E01
#define GL_INCR                                          0x1E02
#define GL_DECR                                          0x1E03
#define GL_INVERT                                        0x150A
#define GL_INCR_WRAP                                     0x8507
#define GL_DECR_WRAP                                     0x8508
#define GL_VENDOR                                        0x1F00
#define GL_RENDERER                                      0x1F01
#define GL_VERSION                                       0x1F02
#define GL_EXTENSIONS                                    0x1F03
#define GL_NEAREST                                       0x2600
#define GL_LINEAR                                        0x2601
#define GL_NEAREST_MIPMAP_NEAREST                        0x2700
#define GL_LINEAR_MIPMAP_NEAREST                         0x2701
#define GL_NEAREST_MIPMAP_LINEAR                         0x2702
#define GL_LINEAR_MIPMAP_LINEAR                          0x2703
#define GL_TEXTURE_MAG_FILTER                            0x2800
#define GL_TEXTURE_MIN_FILTER                            0x2801
#define GL_TEXTURE_WRAP_S                                0x2802
#define GL_TEXTURE_WRAP_T                                0x2803
#define GL_TEXTURE                                       0x1702
#define GL_TEXTURE_CUBE_MAP                              0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP                      0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X                   0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X                   0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y                   0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y                   0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z                   0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z                   0x851A
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE                     0x851C
#define GL_TEXTURE0                                      0x84C0
#define GL_TEXTURE1                                      0x84C1
#define GL_TEXTURE2                                      0x84C2
#define GL_TEXTURE3                                      0x84C3
#define GL_TEXTURE4                                      0x84C4
#define GL_TEXTURE5                                      0x84C5
#define GL_TEXTURE6                                      0x84C6
#define GL_TEXTURE7                                      0x84C7
#define GL_TEXTURE8                                      0x84C8
#define GL_TEXTURE9                                      0x84C9
#define GL_TEXTURE10                                     0x84CA
#define GL_TEXTURE11                                     0x84CB
#define GL_TEXTURE12                                     0x84CC
#define GL_TEXTURE13                                     0x84CD
#define GL_TEXTURE14                                     0x84CE
#define GL_TEXTURE15                                     0x84CF
#define GL_TEXTURE16                                     0x84D0
#define GL_TEXTURE17                                     0x84D1
#define GL_TEXTURE18                                     0x84D2
#define GL_TEXTURE19                                     0x84D3
#define GL_TEXTURE20                                     0x84D4
#define GL_TEXTURE21                                     0x84D5
#define GL_TEXTURE22                                     0x84D6
#define GL_TEXTURE23                                     0x84D7
#define GL_TEXTURE24                                     0x84D8
#define GL_TEXTURE25                                     0x84D9
#define GL_TEXTURE26                                     0x84DA
#define GL_TEXTURE27                                     0x84DB
#define GL_TEXTURE28                                     0x84DC
#define GL_TEXTURE29                                     0x84DD
#define GL_TEXTURE30                                     0x84DE
#define GL_TEXTURE31                                     0x84DF
#define GL_ACTIVE_TEXTURE                                0x84E0
#define GL_REPEAT                                        0x2901
#define GL_CLAMP_TO_EDGE                                 0x812F
#define GL_MIRRORED_REPEAT                               0x8370
#define GL_FLOAT_VEC2                                    0x8B50
#define GL_FLOAT_VEC3                                    0x8B51
#define GL_FLOAT_VEC4                                    0x8B52
#define GL_INT_VEC2                                      0x8B53
#define GL_INT_VEC3                                      0x8B54
#define GL_INT_VEC4                                      0x8B55
#define GL_BOOL                                          0x8B56
#define GL_BOOL_VEC2                                     0x8B57
#define GL_BOOL_VEC3                                     0x8B58
#define GL_BOOL_VEC4                                     0x8B59
#define GL_FLOAT_MAT2                                    0x8B5A
#define GL_FLOAT_MAT3                                    0x8B5B
#define GL_FLOAT_MAT4                                    0x8B5C
#define GL_SAMPLER_2D                                    0x8B5E
#define GL_SAMPLER_CUBE                                  0x8B60
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED                   0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE                      0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE                    0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE                      0x8625
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED                0x886A
#define GL_VERTEX_ATTRIB_ARRAY_POINTER                   0x8645
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING            0x889F
#define GL_IMPLEMENTATION_COLOR_READ_TYPE                0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT              0x8B9B
#define GL_COMPILE_STATUS                                0x8B81
#define GL_INFO_LOG_LENGTH                               0x8B84
#define GL_SHADER_SOURCE_LENGTH                          0x8B88
#define GL_SHADER_COMPILER                               0x8DFA
#define GL_SHADER_BINARY_FORMATS                         0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS                     0x8DF9
#define GL_LOW_FLOAT                                     0x8DF0
#define GL_MEDIUM_FLOAT                                  0x8DF1
#define GL_HIGH_FLOAT                                    0x8DF2
#define GL_LOW_INT                                       0x8DF3
#define GL_MEDIUM_INT                                    0x8DF4
#define GL_HIGH_INT                                      0x8DF5
#define GL_FRAMEBUFFER                                   0x8D40
#define GL_RENDERBUFFER                                  0x8D41
#define GL_RGBA4                                         0x8056
#define GL_RGB5_A1                                       0x8057
#define GL_RGB565                                        0x8D62
#define GL_DEPTH_COMPONENT16                             0x81A5
#define GL_STENCIL_INDEX8                                0x8D48
#define GL_RENDERBUFFER_WIDTH                            0x8D42
#define GL_RENDERBUFFER_HEIGHT                           0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT                  0x8D44
#define GL_RENDERBUFFER_RED_SIZE                         0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE                       0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE                        0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE                       0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE                       0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE                     0x8D55
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE            0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME            0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL          0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE  0x8CD3
#define GL_COLOR_ATTACHMENT0                             0x8CE0
#define GL_DEPTH_ATTACHMENT                              0x8D00
#define GL_STENCIL_ATTACHMENT                            0x8D20
#define GL_NONE                                          0
#define GL_FRAMEBUFFER_COMPLETE                          0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT             0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT     0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS             0x8CD9
#define GL_FRAMEBUFFER_UNSUPPORTED                       0x8CDD
#define GL_FRAMEBUFFER_BINDING                           0x8CA6
#define GL_RENDERBUFFER_BINDING                          0x8CA7
#define GL_MAX_RENDERBUFFER_SIZE                         0x84E8
#define GL_INVALID_FRAMEBUFFER_OPERATION                 0x0506
#define GL_READ_BUFFER                                   0x0C02
#define GL_UNPACK_ROW_LENGTH                             0x0CF2
#define GL_UNPACK_SKIP_ROWS                              0x0CF3
#define GL_UNPACK_SKIP_PIXELS                            0x0CF4
#define GL_PACK_ROW_LENGTH                               0x0D02
#define GL_PACK_SKIP_ROWS                                0x0D03
#define GL_PACK_SKIP_PIXELS                              0x0D04
#define GL_COLOR                                         0x1800
#define GL_DEPTH                                         0x1801
#define GL_STENCIL                                       0x1802
#define GL_RED                                           0x1903
#define GL_RGB8                                          0x8051
#define GL_RGBA8                                         0x8058
#define GL_RGB10_A2                                      0x8059
#define GL_TEXTURE_BINDING_3D                            0x806A
#define GL_UNPACK_SKIP_IMAGES                            0x806D
#define GL_UNPACK_IMAGE_HEIGHT                           0x806E
#define GL_TEXTURE_3D                                    0x806F
#define GL_TEXTURE_WRAP_R                                0x8072
#define GL_MAX_3D_TEXTURE_SIZE                           0x8073
#define GL_UNSIGNED_INT_2_10_10_10_REV                   0x8368
#define GL_MAX_ELEMENTS_VERTICES                         0x80E8
#define GL_MAX_ELEMENTS_INDICES                          0x80E9
#define GL_TEXTURE_MIN_LOD                               0x813A
#define GL_TEXTURE_MAX_LOD                               0x813B
#define GL_TEXTURE_BASE_LEVEL                            0x813C
#define GL_TEXTURE_MAX_LEVEL                             0x813D
#define GL_MIN                                           0x8007
#define GL_MAX                                           0x8008
#define GL_DEPTH_COMPONENT24                             0x81A6
#define GL_MAX_TEXTURE_LOD_BIAS                          0x84FD
#define GL_TEXTURE_COMPARE_MODE                          0x884C
#define GL_TEXTURE_COMPARE_FUNC                          0x884D
#define GL_CURRENT_QUERY                                 0x8865
#define GL_QUERY_RESULT                                  0x8866
#define GL_QUERY_RESULT_AVAILABLE                        0x8867
#define GL_BUFFER_MAPPED                                 0x88BC
#define GL_BUFFER_MAP_POINTER                            0x88BD
#define GL_STREAM_READ                                   0x88E1
#define GL_STREAM_COPY                                   0x88E2
#define GL_STATIC_READ                                   0x88E5
#define GL_STATIC_COPY                                   0x88E6
#define GL_DYNAMIC_READ                                  0x88E9
#define GL_DYNAMIC_COPY                                  0x88EA
#define GL_MAX_DRAW_BUFFERS                              0x8824
#define GL_DRAW_BUFFER0                                  0x8825
#define GL_DRAW_BUFFER1                                  0x8826
#define GL_DRAW_BUFFER2                                  0x8827
#define GL_DRAW_BUFFER3                                  0x8828
#define GL_DRAW_BUFFER4                                  0x8829
#define GL_DRAW_BUFFER5                                  0x882A
#define GL_DRAW_BUFFER6                                  0x882B
#define GL_DRAW_BUFFER7                                  0x882C
#define GL_DRAW_BUFFER8                                  0x882D
#define GL_DRAW_BUFFER9                                  0x882E
#define GL_DRAW_BUFFER10                                 0x882F
#define GL_DRAW_BUFFER11                                 0x8830
#define GL_DRAW_BUFFER12                                 0x8831
#define GL_DRAW_BUFFER13                                 0x8832
#define GL_DRAW_BUFFER14                                 0x8833
#define GL_DRAW_BUFFER15                                 0x8834
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS               0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS                 0x8B4A
#define GL_SAMPLER_3D                                    0x8B5F
#define GL_SAMPLER_2D_SHADOW                             0x8B62
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT               0x8B8B
#define GL_PIXEL_PACK_BUFFER                             0x88EB
#define GL_PIXEL_UNPACK_BUFFER                           0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING                     0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING                   0x88EF
#define GL_FLOAT_MAT2x3                                  0x8B65
#define GL_FLOAT_MAT2x4                                  0x8B66
#define GL_FLOAT_MAT3x2                                  0x8B67
#define GL_FLOAT_MAT3x4                                  0x8B68
#define GL_FLOAT_MAT4x2                                  0x8B69
#define GL_FLOAT_MAT4x3                                  0x8B6A
#define GL_SRGB                                          0x8C40
#define GL_SRGB8                                         0x8C41
#define GL_SRGB8_ALPHA8                                  0x8C43
#define GL_COMPARE_REF_TO_TEXTURE                        0x884E
#define GL_MAJOR_VERSION                                 0x821B
#define GL_MINOR_VERSION                                 0x821C
#define GL_NUM_EXTENSIONS                                0x821D
#define GL_RGBA32F                                       0x8814
#define GL_RGB32F                                        0x8815
#define GL_RGBA16F                                       0x881A
#define GL_RGB16F                                        0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER                   0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS                      0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET                      0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET                      0x8905
#define GL_MAX_VARYING_COMPONENTS                        0x8B4B
#define GL_TEXTURE_2D_ARRAY                              0x8C1A
#define GL_TEXTURE_BINDING_2D_ARRAY                      0x8C1D
#define GL_R11F_G11F_B10F                                0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV                  0x8C3B
#define GL_RGB9_E5                                       0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV                      0x8C3E
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH         0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE                0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS    0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS                   0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START               0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE                0x8C85
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN         0x8C88
#define GL_RASTERIZER_DISCARD                            0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS       0x8C8B
#define GL_INTERLEAVED_ATTRIBS                           0x8C8C
#define GL_SEPARATE_ATTRIBS                              0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER                     0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING             0x8C8F
#define GL_RGBA32UI                                      0x8D70
#define GL_RGB32UI                                       0x8D71
#define GL_RGBA16UI                                      0x8D76
#define GL_RGB16UI                                       0x8D77
#define GL_RGBA8UI                                       0x8D7C
#define GL_RGB8UI                                        0x8D7D
#define GL_RGBA32I                                       0x8D82
#define GL_RGB32I                                        0x8D83
#define GL_RGBA16I                                       0x8D88
#define GL_RGB16I                                        0x8D89
#define GL_RGBA8I                                        0x8D8E
#define GL_RGB8I                                         0x8D8F
#define GL_RED_INTEGER                                   0x8D94
#define GL_RGB_INTEGER                                   0x8D98
#define GL_RGBA_INTEGER                                  0x8D99
#define GL_SAMPLER_2D_ARRAY                              0x8DC1
#define GL_SAMPLER_2D_ARRAY_SHADOW                       0x8DC4
#define GL_SAMPLER_CUBE_SHADOW                           0x8DC5
#define GL_UNSIGNED_INT_VEC2                             0x8DC6
#define GL_UNSIGNED_INT_VEC3                             0x8DC7
#define GL_UNSIGNED_INT_VEC4                             0x8DC8
#define GL_INT_SAMPLER_2D                                0x8DCA
#define GL_INT_SAMPLER_3D                                0x8DCB
#define GL_INT_SAMPLER_CUBE                              0x8DCC
#define GL_INT_SAMPLER_2D_ARRAY                          0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_2D                       0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D                       0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE                     0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY                 0x8DD7
#define GL_BUFFER_ACCESS_FLAGS                           0x911F
#define GL_BUFFER_MAP_LENGTH                             0x9120
#define GL_BUFFER_MAP_OFFSET                             0x9121
#define GL_DEPTH_COMPONENT32F                            0x8CAC
#define GL_DEPTH32F_STENCIL8                             0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV                0x8DAD
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING         0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE         0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE               0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE             0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE              0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE             0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE             0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE           0x8217
#define GL_FRAMEBUFFER_DEFAULT                           0x8218
#define GL_FRAMEBUFFER_UNDEFINED                         0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT                      0x821A
#define GL_DEPTH_STENCIL                                 0x84F9
#define GL_UNSIGNED_INT_24_8                             0x84FA
#define GL_DEPTH24_STENCIL8                              0x88F0
#define GL_UNSIGNED_NORMALIZED                           0x8C17
#define GL_DRAW_FRAMEBUFFER_BINDING                      0x8CA6
#define GL_READ_FRAMEBUFFER                              0x8CA8
#define GL_DRAW_FRAMEBUFFER                              0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING                      0x8CAA
#define GL_RENDERBUFFER_SAMPLES                          0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER          0x8CD4
#define GL_MAX_COLOR_ATTACHMENTS                         0x8CDF
#define GL_COLOR_ATTACHMENT1                             0x8CE1
#define GL_COLOR_ATTACHMENT2                             0x8CE2
#define GL_COLOR_ATTACHMENT3                             0x8CE3
#define GL_COLOR_ATTACHMENT4                             0x8CE4
#define GL_COLOR_ATTACHMENT5                             0x8CE5
#define GL_COLOR_ATTACHMENT6                             0x8CE6
#define GL_COLOR_ATTACHMENT7                             0x8CE7
#define GL_COLOR_ATTACHMENT8                             0x8CE8
#define GL_COLOR_ATTACHMENT9                             0x8CE9
#define GL_COLOR_ATTACHMENT10                            0x8CEA
#define GL_COLOR_ATTACHMENT11                            0x8CEB
#define GL_COLOR_ATTACHMENT12                            0x8CEC
#define GL_COLOR_ATTACHMENT13                            0x8CED
#define GL_COLOR_ATTACHMENT14                            0x8CEE
#define GL_COLOR_ATTACHMENT15                            0x8CEF
#define GL_COLOR_ATTACHMENT16                            0x8CF0
#define GL_COLOR_ATTACHMENT17                            0x8CF1
#define GL_COLOR_ATTACHMENT18                            0x8CF2
#define GL_COLOR_ATTACHMENT19                            0x8CF3
#define GL_COLOR_ATTACHMENT20                            0x8CF4
#define GL_COLOR_ATTACHMENT21                            0x8CF5
#define GL_COLOR_ATTACHMENT22                            0x8CF6
#define GL_COLOR_ATTACHMENT23                            0x8CF7
#define GL_COLOR_ATTACHMENT24                            0x8CF8
#define GL_COLOR_ATTACHMENT25                            0x8CF9
#define GL_COLOR_ATTACHMENT26                            0x8CFA
#define GL_COLOR_ATTACHMENT27                            0x8CFB
#define GL_COLOR_ATTACHMENT28                            0x8CFC
#define GL_COLOR_ATTACHMENT29                            0x8CFD
#define GL_COLOR_ATTACHMENT30                            0x8CFE
#define GL_COLOR_ATTACHMENT31                            0x8CFF
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE            0x8D56
#define GL_MAX_SAMPLES                                   0x8D57
#define GL_HALF_FLOAT                                    0x140B
#define GL_MAP_READ_BIT                                  0x0001
#define GL_MAP_WRITE_BIT                                 0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT                      0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT                     0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT                        0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT                        0x0020
#define GL_RG                                            0x8227
#define GL_RG_INTEGER                                    0x8228
#define GL_R8                                            0x8229
#define GL_RG8                                           0x822B
#define GL_R16F                                          0x822D
#define GL_R32F                                          0x822E
#define GL_RG16F                                         0x822F
#define GL_RG32F                                         0x8230
#define GL_R8I                                           0x8231
#define GL_R8UI                                          0x8232
#define GL_R16I                                          0x8233
#define GL_R16UI                                         0x8234
#define GL_R32I                                          0x8235
#define GL_R32UI                                         0x8236
#define GL_RG8I                                          0x8237
#define GL_RG8UI                                         0x8238
#define GL_RG16I                                         0x8239
#define GL_RG16UI                                        0x823A
#define GL_RG32I                                         0x823B
#define GL_RG32UI                                        0x823C
#define GL_VERTEX_ARRAY_BINDING                          0x85B5
#define GL_R8_SNORM                                      0x8F94
#define GL_RG8_SNORM                                     0x8F95
#define GL_RGB8_SNORM                                    0x8F96
#define GL_RGBA8_SNORM                                   0x8F97
#define GL_SIGNED_NORMALIZED                             0x8F9C
#define GL_PRIMITIVE_RESTART_FIXED_INDEX                 0x8D69
#define GL_COPY_READ_BUFFER                              0x8F36
#define GL_COPY_WRITE_BUFFER                             0x8F37
#define GL_COPY_READ_BUFFER_BINDING                      0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING                     0x8F37
#define GL_UNIFORM_BUFFER                                0x8A11
#define GL_UNIFORM_BUFFER_BINDING                        0x8A28
#define GL_UNIFORM_BUFFER_START                          0x8A29
#define GL_UNIFORM_BUFFER_SIZE                           0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS                     0x8A2B
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS                   0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS                   0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS                   0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE                        0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS        0x8A31
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS      0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT               0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH          0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS                         0x8A36
#define GL_UNIFORM_TYPE                                  0x8A37
#define GL_UNIFORM_SIZE                                  0x8A38
#define GL_UNIFORM_NAME_LENGTH                           0x8A39
#define GL_UNIFORM_BLOCK_INDEX                           0x8A3A
#define GL_UNIFORM_OFFSET                                0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE                          0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE                         0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR                          0x8A3E
#define GL_UNIFORM_BLOCK_BINDING                         0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE                       0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH                     0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS                 0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES          0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER     0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER   0x8A46
#define GL_INVALID_INDEX                                 0xFFFFFFFF
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS                  0x9122
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS                 0x9125
#define GL_MAX_SERVER_WAIT_TIMEOUT                       0x9111
#define GL_OBJECT_TYPE                                   0x9112
#define GL_SYNC_CONDITION                                0x9113
#define GL_SYNC_STATUS                                   0x9114
#define GL_SYNC_FLAGS                                    0x9115
#define GL_SYNC_FENCE                                    0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE                    0x9117
#define GL_UNSIGNALED                                    0x9118
#define GL_SIGNALED                                      0x9119
#define GL_ALREADY_SIGNALED                              0x911A
#define GL_TIMEOUT_EXPIRED                               0x911B
#define GL_CONDITION_SATISFIED                           0x911C
#define GL_WAIT_FAILED                                   0x911D
#define GL_SYNC_FLUSH_COMMANDS_BIT                       0x00000001
#define GL_TIMEOUT_IGNORED                               0xFFFFFFFFFFFFFFFF
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR                   0x88FE
#define GL_ANY_SAMPLES_PASSED                            0x8C2F
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE               0x8D6A
#define GL_SAMPLER_BINDING                               0x8919
#define GL_RGB10_A2UI                                    0x906F
#define GL_TEXTURE_SWIZZLE_R                             0x8E42
#define GL_TEXTURE_SWIZZLE_G                             0x8E43
#define GL_TEXTURE_SWIZZLE_B                             0x8E44
#define GL_TEXTURE_SWIZZLE_A                             0x8E45
#define GL_GREEN                                         0x1904
#define GL_BLUE                                          0x1905
#define GL_INT_2_10_10_10_REV                            0x8D9F
#define GL_TRANSFORM_FEEDBACK                            0x8E22
#define GL_TRANSFORM_FEEDBACK_PAUSED                     0x8E23
#define GL_TRANSFORM_FEEDBACK_ACTIVE                     0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING                    0x8E25
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT               0x8257
#define GL_PROGRAM_BINARY_LENGTH                         0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS                    0x87FE
#define GL_PROGRAM_BINARY_FORMATS                        0x87FF
#define GL_COMPRESSED_R11_EAC                            0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC                     0x9271
#define GL_COMPRESSED_RG11_EAC                           0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC                    0x9273
#define GL_COMPRESSED_RGB8_ETC2                          0x9274
#define GL_COMPRESSED_SRGB8_ETC2                         0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2      0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2     0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC                     0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC              0x9279
#define GL_TEXTURE_IMMUTABLE_FORMAT                      0x912F
#define GL_MAX_ELEMENT_INDEX                             0x8D6B
#define GL_NUM_SAMPLE_COUNTS                             0x9380
#define GL_TEXTURE_IMMUTABLE_LEVELS                      0x82DF
#define GL_COMPUTE_SHADER                                0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS                    0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS               0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS                    0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE                0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS                0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS            0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS                   0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS       0x8266
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS            0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT                  0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE                   0x91BF
#define GL_COMPUTE_WORK_GROUP_SIZE                       0x8267
#define GL_DISPATCH_INDIRECT_BUFFER                      0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING              0x90EF
#define GL_COMPUTE_SHADER_BIT                            0x00000020
#define GL_DRAW_INDIRECT_BUFFER                          0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING                  0x8F43
#define GL_MAX_UNIFORM_LOCATIONS                         0x826E
#define GL_FRAMEBUFFER_DEFAULT_WIDTH                     0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT                    0x9311
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES                   0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS    0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH                         0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT                        0x9316
#define GL_MAX_FRAMEBUFFER_SAMPLES                       0x9318
#define GL_UNIFORM                                       0x92E1
#define GL_UNIFORM_BLOCK                                 0x92E2
#define GL_PROGRAM_INPUT                                 0x92E3
#define GL_PROGRAM_OUTPUT                                0x92E4
#define GL_BUFFER_VARIABLE                               0x92E5
#define GL_SHADER_STORAGE_BLOCK                          0x92E6
#define GL_ATOMIC_COUNTER_BUFFER                         0x92C0
#define GL_TRANSFORM_FEEDBACK_VARYING                    0x92F4
#define GL_ACTIVE_RESOURCES                              0x92F5
#define GL_MAX_NAME_LENGTH                               0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES                      0x92F7
#define GL_NAME_LENGTH                                   0x92F9
#define GL_TYPE                                          0x92FA
#define GL_ARRAY_SIZE                                    0x92FB
#define GL_OFFSET                                        0x92FC
#define GL_BLOCK_INDEX                                   0x92FD
#define GL_ARRAY_STRIDE                                  0x92FE
#define GL_MATRIX_STRIDE                                 0x92FF
#define GL_IS_ROW_MAJOR                                  0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX                   0x9301
#define GL_BUFFER_BINDING                                0x9302
#define GL_BUFFER_DATA_SIZE                              0x9303
#define GL_NUM_ACTIVE_VARIABLES                          0x9304
#define GL_ACTIVE_VARIABLES                              0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER                   0x9306
#define GL_REFERENCED_BY_FRAGMENT_SHADER                 0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER                  0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE                          0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE                        0x930D
#define GL_LOCATION                                      0x930E
#define GL_VERTEX_SHADER_BIT                             0x00000001
#define GL_FRAGMENT_SHADER_BIT                           0x00000002
#define GL_ALL_SHADER_BITS                               0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE                             0x8258
#define GL_ACTIVE_PROGRAM                                0x8259
#define GL_PROGRAM_PIPELINE_BINDING                      0x825A
#define GL_ATOMIC_COUNTER_BUFFER_BINDING                 0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START                   0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE                    0x92C3
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS             0x92CC
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS           0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS           0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS                    0x92D2
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS                  0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS                  0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE                0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS            0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS                 0x92D9
#define GL_UNSIGNED_INT_ATOMIC_COUNTER                   0x92DB
#define GL_MAX_IMAGE_UNITS                               0x8F38
#define GL_MAX_VERTEX_IMAGE_UNIFORMS                     0x90CA
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS                   0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS                   0x90CF
#define GL_IMAGE_BINDING_NAME                            0x8F3A
#define GL_IMAGE_BINDING_LEVEL                           0x8F3B
#define GL_IMAGE_BINDING_LAYERED                         0x8F3C
#define GL_IMAGE_BINDING_LAYER                           0x8F3D
#define GL_IMAGE_BINDING_ACCESS                          0x8F3E
#define GL_IMAGE_BINDING_FORMAT                          0x906E
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT               0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT                     0x00000002
#define GL_UNIFORM_BARRIER_BIT                           0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT                     0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT               0x00000020
#define GL_COMMAND_BARRIER_BIT                           0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT                      0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT                    0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT                     0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT                       0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT                0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT                    0x00001000
#define GL_ALL_BARRIER_BITS                              0xFFFFFFFF
#define GL_IMAGE_2D                                      0x904D
#define GL_IMAGE_3D                                      0x904E
#define GL_IMAGE_CUBE                                    0x9050
#define GL_IMAGE_2D_ARRAY                                0x9053
#define GL_INT_IMAGE_2D                                  0x9058
#define GL_INT_IMAGE_3D                                  0x9059
#define GL_INT_IMAGE_CUBE                                0x905B
#define GL_INT_IMAGE_2D_ARRAY                            0x905E
#define GL_UNSIGNED_INT_IMAGE_2D                         0x9063
#define GL_UNSIGNED_INT_IMAGE_3D                         0x9064
#define GL_UNSIGNED_INT_IMAGE_CUBE                       0x9066
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY                   0x9069
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE               0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE            0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS           0x90C9
#define GL_READ_ONLY                                     0x88B8
#define GL_WRITE_ONLY                                    0x88B9
#define GL_READ_WRITE                                    0x88BA
#define GL_SHADER_STORAGE_BUFFER                         0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING                 0x90D3
#define GL_SHADER_STORAGE_BUFFER_START                   0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE                    0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS              0x90D6
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS            0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS             0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS            0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS            0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE                 0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT        0x90DF
#define GL_SHADER_STORAGE_BARRIER_BIT                    0x00002000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES          0x8F39
#define GL_DEPTH_STENCIL_TEXTURE_MODE                    0x90EA
#define GL_STENCIL_INDEX                                 0x1901
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET             0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET             0x8E5F
#define GL_SAMPLE_POSITION                               0x8E50
#define GL_SAMPLE_MASK                                   0x8E51
#define GL_SAMPLE_MASK_VALUE                             0x8E52
#define GL_TEXTURE_2D_MULTISAMPLE                        0x9100
#define GL_MAX_SAMPLE_MASK_WORDS                         0x8E59
#define GL_MAX_COLOR_TEXTURE_SAMPLES                     0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES                     0x910F
#define GL_MAX_INTEGER_SAMPLES                           0x9110
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE                0x9104
#define GL_TEXTURE_SAMPLES                               0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS                0x9107
#define GL_TEXTURE_WIDTH                                 0x1000
#define GL_TEXTURE_HEIGHT                                0x1001
#define GL_TEXTURE_DEPTH                                 0x8071
#define GL_TEXTURE_INTERNAL_FORMAT                       0x1003
#define GL_TEXTURE_RED_SIZE                              0x805C
#define GL_TEXTURE_GREEN_SIZE                            0x805D
#define GL_TEXTURE_BLUE_SIZE                             0x805E
#define GL_TEXTURE_ALPHA_SIZE                            0x805F
#define GL_TEXTURE_DEPTH_SIZE                            0x884A
#define GL_TEXTURE_STENCIL_SIZE                          0x88F1
#define GL_TEXTURE_SHARED_SIZE                           0x8C3F
#define GL_TEXTURE_RED_TYPE                              0x8C10
#define GL_TEXTURE_GREEN_TYPE                            0x8C11
#define GL_TEXTURE_BLUE_TYPE                             0x8C12
#define GL_TEXTURE_ALPHA_TYPE                            0x8C13
#define GL_TEXTURE_DEPTH_TYPE                            0x8C16
#define GL_TEXTURE_COMPRESSED                            0x86A1
#define GL_SAMPLER_2D_MULTISAMPLE                        0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE                    0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE           0x910A
#define GL_VERTEX_ATTRIB_BINDING                         0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET                 0x82D5
#define GL_VERTEX_BINDING_DIVISOR                        0x82D6
#define GL_VERTEX_BINDING_OFFSET                         0x82D7
#define GL_VERTEX_BINDING_STRIDE                         0x82D8
#define GL_VERTEX_BINDING_BUFFER                         0x8F4F
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET             0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS                    0x82DA
#define GL_MAX_VERTEX_ATTRIB_STRIDE                      0x82E5
#ifndef GL_ES_VERSION_2_0
	#define GL_ES_VERSION_2_0                              1
GLAPI int GLAD_GL_ES_VERSION_2_0;
typedef void (APIENTRYP           PFNGLACTIVETEXTUREPROC)(GLenum);
GLAPI PFNGLACTIVETEXTUREPROC glad_glActiveTexture;
typedef void (APIENTRYP           PFNGLATTACHSHADERPROC)(GLuint, GLuint);
GLAPI PFNGLATTACHSHADERPROC glad_glAttachShader;
typedef void (APIENTRYP           PFNGLBINDATTRIBLOCATIONPROC)(GLuint, GLuint, const GLchar*);
GLAPI PFNGLBINDATTRIBLOCATIONPROC glad_glBindAttribLocation;
typedef void (APIENTRYP           PFNGLBINDBUFFERPROC)(GLenum, GLuint);
GLAPI PFNGLBINDBUFFERPROC glad_glBindBuffer;
typedef void (APIENTRYP           PFNGLBINDFRAMEBUFFERPROC)(GLenum, GLuint);
GLAPI PFNGLBINDFRAMEBUFFERPROC glad_glBindFramebuffer;
typedef void (APIENTRYP           PFNGLBINDRENDERBUFFERPROC)(GLenum, GLuint);
GLAPI PFNGLBINDRENDERBUFFERPROC glad_glBindRenderbuffer;
typedef void (APIENTRYP           PFNGLBINDTEXTUREPROC)(GLenum, GLuint);
GLAPI PFNGLBINDTEXTUREPROC glad_glBindTexture;
typedef void (APIENTRYP           PFNGLBLENDCOLORPROC)(GLfloat, GLfloat, GLfloat, GLfloat);
GLAPI PFNGLBLENDCOLORPROC glad_glBlendColor;
typedef void (APIENTRYP           PFNGLBLENDEQUATIONPROC)(GLenum);
GLAPI PFNGLBLENDEQUATIONPROC glad_glBlendEquation;
typedef void (APIENTRYP           PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum, GLenum);
GLAPI PFNGLBLENDEQUATIONSEPARATEPROC glad_glBlendEquationSeparate;
typedef void (APIENTRYP           PFNGLBLENDFUNCPROC)(GLenum, GLenum);
GLAPI PFNGLBLENDFUNCPROC glad_glBlendFunc;
typedef void (APIENTRYP           PFNGLBLENDFUNCSEPARATEPROC)(GLenum, GLenum, GLenum, GLenum);
GLAPI PFNGLBLENDFUNCSEPARATEPROC glad_glBlendFuncSeparate;
typedef void (APIENTRYP           PFNGLBUFFERDATAPROC)(GLenum, GLsizeiptr, const void*, GLenum);
GLAPI PFNGLBUFFERDATAPROC glad_glBufferData;
typedef void (APIENTRYP           PFNGLBUFFERSUBDATAPROC)(GLenum, GLintptr, GLsizeiptr, const void*);
GLAPI PFNGLBUFFERSUBDATAPROC glad_glBufferSubData;
typedef GLenum (APIENTRYP         PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum);
GLAPI PFNGLCHECKFRAMEBUFFERSTATUSPROC glad_glCheckFramebufferStatus;
typedef void (APIENTRYP           PFNGLCLEARPROC)(GLbitfield);
GLAPI PFNGLCLEARPROC glad_glClear;
typedef void (APIENTRYP           PFNGLCLEARCOLORPROC)(GLfloat, GLfloat, GLfloat, GLfloat);
GLAPI PFNGLCLEARCOLORPROC glad_glClearColor;
typedef void (APIENTRYP           PFNGLCLEARDEPTHFPROC)(GLfloat);
GLAPI PFNGLCLEARDEPTHFPROC glad_glClearDepthf;
typedef void (APIENTRYP           PFNGLCLEARSTENCILPROC)(GLint);
GLAPI PFNGLCLEARSTENCILPROC glad_glClearStencil;
typedef void (APIENTRYP           PFNGLCOLORMASKPROC)(GLboolean, GLboolean, GLboolean, GLboolean);
GLAPI PFNGLCOLORMASKPROC glad_glColorMask;
typedef void (APIENTRYP           PFNGLCOMPILESHADERPROC)(GLuint);
GLAPI PFNGLCOMPILESHADERPROC glad_glCompileShader;
typedef void (APIENTRYP           PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void*);
GLAPI PFNGLCOMPRESSEDTEXIMAGE2DPROC glad_glCompressedTexImage2D;
typedef void (APIENTRYP           PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void*);
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glad_glCompressedTexSubImage2D;
typedef void (APIENTRYP           PFNGLCOPYTEXIMAGE2DPROC)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
GLAPI PFNGLCOPYTEXIMAGE2DPROC glad_glCopyTexImage2D;
typedef void (APIENTRYP           PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
GLAPI PFNGLCOPYTEXSUBIMAGE2DPROC glad_glCopyTexSubImage2D;
typedef GLuint (APIENTRYP         PFNGLCREATEPROGRAMPROC)();
GLAPI PFNGLCREATEPROGRAMPROC glad_glCreateProgram;
typedef GLuint (APIENTRYP         PFNGLCREATESHADERPROC)(GLenum);
GLAPI PFNGLCREATESHADERPROC glad_glCreateShader;
typedef void (APIENTRYP           PFNGLCULLFACEPROC)(GLenum);
GLAPI PFNGLCULLFACEPROC glad_glCullFace;
typedef void (APIENTRYP           PFNGLDELETEBUFFERSPROC)(GLsizei, const GLuint*);
GLAPI PFNGLDELETEBUFFERSPROC glad_glDeleteBuffers;
typedef void (APIENTRYP           PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei, const GLuint*);
GLAPI PFNGLDELETEFRAMEBUFFERSPROC glad_glDeleteFramebuffers;
typedef void (APIENTRYP           PFNGLDELETEPROGRAMPROC)(GLuint);
GLAPI PFNGLDELETEPROGRAMPROC glad_glDeleteProgram;
typedef void (APIENTRYP           PFNGLDELETERENDERBUFFERSPROC)(GLsizei, const GLuint*);
GLAPI PFNGLDELETERENDERBUFFERSPROC glad_glDeleteRenderbuffers;
typedef void (APIENTRYP           PFNGLDELETESHADERPROC)(GLuint);
GLAPI PFNGLDELETESHADERPROC glad_glDeleteShader;
typedef void (APIENTRYP           PFNGLDELETETEXTURESPROC)(GLsizei, const GLuint*);
GLAPI PFNGLDELETETEXTURESPROC glad_glDeleteTextures;
typedef void (APIENTRYP           PFNGLDEPTHFUNCPROC)(GLenum);
GLAPI PFNGLDEPTHFUNCPROC glad_glDepthFunc;
typedef void (APIENTRYP           PFNGLDEPTHMASKPROC)(GLboolean);
GLAPI PFNGLDEPTHMASKPROC glad_glDepthMask;
typedef void (APIENTRYP           PFNGLDEPTHRANGEFPROC)(GLfloat, GLfloat);
GLAPI PFNGLDEPTHRANGEFPROC glad_glDepthRangef;
typedef void (APIENTRYP           PFNGLDETACHSHADERPROC)(GLuint, GLuint);
GLAPI PFNGLDETACHSHADERPROC glad_glDetachShader;
typedef void (APIENTRYP           PFNGLDISABLEPROC)(GLenum);
GLAPI PFNGLDISABLEPROC glad_glDisable;
typedef void (APIENTRYP           PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint);
GLAPI PFNGLDISABLEVERTEXATTRIBARRAYPROC glad_glDisableVertexAttribArray;
typedef void (APIENTRYP           PFNGLDRAWARRAYSPROC)(GLenum, GLint, GLsizei);
GLAPI PFNGLDRAWARRAYSPROC glad_glDrawArrays;
typedef void (APIENTRYP           PFNGLDRAWELEMENTSPROC)(GLenum, GLsizei, GLenum, const void*);
GLAPI PFNGLDRAWELEMENTSPROC glad_glDrawElements;
typedef void (APIENTRYP           PFNGLENABLEPROC)(GLenum);
GLAPI PFNGLENABLEPROC glad_glEnable;
typedef void (APIENTRYP           PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint);
GLAPI PFNGLENABLEVERTEXATTRIBARRAYPROC glad_glEnableVertexAttribArray;
typedef void (APIENTRYP           PFNGLFINISHPROC)();
GLAPI PFNGLFINISHPROC glad_glFinish;
typedef void (APIENTRYP           PFNGLFLUSHPROC)();
GLAPI PFNGLFLUSHPROC glad_glFlush;
typedef void (APIENTRYP           PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum, GLenum, GLenum, GLuint);
GLAPI PFNGLFRAMEBUFFERRENDERBUFFERPROC glad_glFramebufferRenderbuffer;
typedef void (APIENTRYP           PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum, GLenum, GLenum, GLuint, GLint);
GLAPI PFNGLFRAMEBUFFERTEXTURE2DPROC glad_glFramebufferTexture2D;
typedef void (APIENTRYP           PFNGLFRONTFACEPROC)(GLenum);
GLAPI PFNGLFRONTFACEPROC glad_glFrontFace;
typedef void (APIENTRYP           PFNGLGENBUFFERSPROC)(GLsizei, GLuint*);
GLAPI PFNGLGENBUFFERSPROC glad_glGenBuffers;
typedef void (APIENTRYP           PFNGLGENERATEMIPMAPPROC)(GLenum);
GLAPI PFNGLGENERATEMIPMAPPROC glad_glGenerateMipmap;
typedef void (APIENTRYP           PFNGLGENFRAMEBUFFERSPROC)(GLsizei, GLuint*);
GLAPI PFNGLGENFRAMEBUFFERSPROC glad_glGenFramebuffers;
typedef void (APIENTRYP           PFNGLGENRENDERBUFFERSPROC)(GLsizei, GLuint*);
GLAPI PFNGLGENRENDERBUFFERSPROC glad_glGenRenderbuffers;
typedef void (APIENTRYP           PFNGLGENTEXTURESPROC)(GLsizei, GLuint*);
GLAPI PFNGLGENTEXTURESPROC glad_glGenTextures;
typedef void (APIENTRYP           PFNGLGETACTIVEATTRIBPROC)(GLuint, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLchar*);
GLAPI PFNGLGETACTIVEATTRIBPROC glad_glGetActiveAttrib;
typedef void (APIENTRYP           PFNGLGETACTIVEUNIFORMPROC)(GLuint, GLuint, GLsizei, GLsizei*, GLint*, GLenum*, GLchar*);
GLAPI PFNGLGETACTIVEUNIFORMPROC glad_glGetActiveUniform;
typedef void (APIENTRYP           PFNGLGETATTACHEDSHADERSPROC)(GLuint, GLsizei, GLsizei*, GLuint*);
GLAPI PFNGLGETATTACHEDSHADERSPROC glad_glGetAttachedShaders;
typedef GLint (APIENTRYP          PFNGLGETATTRIBLOCATIONPROC)(GLuint, const GLchar*);
GLAPI PFNGLGETATTRIBLOCATIONPROC glad_glGetAttribLocation;
typedef void (APIENTRYP           PFNGLGETBOOLEANVPROC)(GLenum, GLboolean*);
GLAPI PFNGLGETBOOLEANVPROC glad_glGetBooleanv;
typedef void (APIENTRYP           PFNGLGETBUFFERPARAMETERIVPROC)(GLenum, GLenum, GLint*);
GLAPI PFNGLGETBUFFERPARAMETERIVPROC glad_glGetBufferParameteriv;
typedef GLenum (APIENTRYP         PFNGLGETERRORPROC)();
GLAPI PFNGLGETERRORPROC glad_glGetError;
typedef void (APIENTRYP           PFNGLGETFLOATVPROC)(GLenum, GLfloat*);
GLAPI PFNGLGETFLOATVPROC glad_glGetFloatv;
typedef void (APIENTRYP           PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum, GLenum, GLenum, GLint*);
GLAPI PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glad_glGetFramebufferAttachmentParameteriv;
typedef void (APIENTRYP           PFNGLGETINTEGERVPROC)(GLenum, GLint*);
GLAPI PFNGLGETINTEGERVPROC glad_glGetIntegerv;
typedef void (APIENTRYP           PFNGLGETPROGRAMIVPROC)(GLuint, GLenum, GLint*);
GLAPI PFNGLGETPROGRAMIVPROC glad_glGetProgramiv;
typedef void (APIENTRYP           PFNGLGETPROGRAMINFOLOGPROC)(GLuint, GLsizei, GLsizei*, GLchar*);
GLAPI PFNGLGETPROGRAMINFOLOGPROC glad_glGetProgramInfoLog;
typedef void (APIENTRYP           PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum, GLenum, GLint*);
GLAPI PFNGLGETRENDERBUFFERPARAMETERIVPROC glad_glGetRenderbufferParameteriv;
typedef void (APIENTRYP           PFNGLGETSHADERIVPROC)(GLuint, GLenum, GLint*);
GLAPI PFNGLGETSHADERIVPROC glad_glGetShaderiv;
typedef void (APIENTRYP           PFNGLGETSHADERINFOLOGPROC)(GLuint, GLsizei, GLsizei*, GLchar*);
GLAPI PFNGLGETSHADERINFOLOGPROC glad_glGetShaderInfoLog;
typedef void (APIENTRYP           PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum, GLenum, GLint*, GLint*);
GLAPI PFNGLGETSHADERPRECISIONFORMATPROC glad_glGetShaderPrecisionFormat;
typedef void (APIENTRYP           PFNGLGETSHADERSOURCEPROC)(GLuint, GLsizei, GLsizei*, GLchar*);
GLAPI PFNGLGETSHADERSOURCEPROC glad_glGetShaderSource;
typedef const GLubyte* (APIENTRYP PFNGLGETSTRINGPROC)(GLenum);
GLAPI PFNGLGETSTRINGPROC glad_glGetString;
typedef void (APIENTRYP           PFNGLGETTEXPARAMETERFVPROC)(GLenum, GLenum, GLfloat*);
GLAPI PFNGLGETTEXPARAMETERFVPROC glad_glGetTexParameterfv;
typedef void (APIENTRYP           PFNGLGETTEXPARAMETERIVPROC)(GLenum, GLenum, GLint*);
GLAPI PFNGLGETTEXPARAMETERIVPROC glad_glGetTexParameteriv;
typedef void (APIENTRYP           PFNGLGETUNIFORMFVPROC)(GLuint, GLint, GLfloat*);
GLAPI PFNGLGETUNIFORMFVPROC glad_glGetUniformfv;
typedef void (APIENTRYP           PFNGLGETUNIFORMIVPROC)(GLuint, GLint, GLint*);
GLAPI PFNGLGETUNIFORMIVPROC glad_glGetUniformiv;
typedef GLint (APIENTRYP          PFNGLGETUNIFORMLOCATIONPROC)(GLuint, const GLchar*);
GLAPI PFNGLGETUNIFORMLOCATIONPROC glad_glGetUniformLocation;
typedef void (APIENTRYP           PFNGLGETVERTEXATTRIBFVPROC)(GLuint, GLenum, GLfloat*);
GLAPI PFNGLGETVERTEXATTRIBFVPROC glad_glGetVertexAttribfv;
typedef void (APIENTRYP           PFNGLGETVERTEXATTRIBIVPROC)(GLuint, GLenum, GLint*);
GLAPI PFNGLGETVERTEXATTRIBIVPROC glad_glGetVertexAttribiv;
typedef void (APIENTRYP           PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint, GLenum, void**);
GLAPI PFNGLGETVERTEXATTRIBPOINTERVPROC glad_glGetVertexAttribPointerv;
typedef void (APIENTRYP           PFNGLHINTPROC)(GLenum, GLenum);
GLAPI PFNGLHINTPROC glad_glHint;
typedef GLboolean (APIENTRYP      PFNGLISBUFFERPROC)(GLuint);
GLAPI PFNGLISBUFFERPROC glad_glIsBuffer;
typedef GLboolean (APIENTRYP      PFNGLISENABLEDPROC)(GLenum);
GLAPI PFNGLISENABLEDPROC glad_glIsEnabled;
typedef GLboolean (APIENTRYP      PFNGLISFRAMEBUFFERPROC)(GLuint);
GLAPI PFNGLISFRAMEBUFFERPROC glad_glIsFramebuffer;
typedef GLboolean (APIENTRYP      PFNGLISPROGRAMPROC)(GLuint);
GLAPI PFNGLISPROGRAMPROC glad_glIsProgram;
typedef GLboolean (APIENTRYP      PFNGLISRENDERBUFFERPROC)(GLuint);
GLAPI PFNGLISRENDERBUFFERPROC glad_glIsRenderbuffer;
typedef GLboolean (APIENTRYP      PFNGLISSHADERPROC)(GLuint);
GLAPI PFNGLISSHADERPROC glad_glIsShader;
typedef GLboolean (APIENTRYP      PFNGLISTEXTUREPROC)(GLuint);
GLAPI PFNGLISTEXTUREPROC glad_glIsTexture;
typedef void (APIENTRYP           PFNGLLINEWIDTHPROC)(GLfloat);
GLAPI PFNGLLINEWIDTHPROC glad_glLineWidth;
typedef void (APIENTRYP           PFNGLLINKPROGRAMPROC)(GLuint);
GLAPI PFNGLLINKPROGRAMPROC glad_glLinkProgram;
typedef void (APIENTRYP           PFNGLPIXELSTOREIPROC)(GLenum, GLint);
GLAPI PFNGLPIXELSTOREIPROC glad_glPixelStorei;
typedef void (APIENTRYP           PFNGLPOLYGONOFFSETPROC)(GLfloat, GLfloat);
GLAPI PFNGLPOLYGONOFFSETPROC glad_glPolygonOffset;
typedef void (APIENTRYP           PFNGLREADPIXELSPROC)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, void*);
GLAPI PFNGLREADPIXELSPROC glad_glReadPixels;
typedef void (APIENTRYP           PFNGLRELEASESHADERCOMPILERPROC)();
GLAPI PFNGLRELEASESHADERCOMPILERPROC glad_glReleaseShaderCompiler;
typedef void (APIENTRYP           PFNGLRENDERBUFFERSTORAGEPROC)(GLenum, GLenum, GLsizei, GLsizei);
GLAPI PFNGLRENDERBUFFERSTORAGEPROC glad_glRenderbufferStorage;
typedef void (APIENTRYP           PFNGLSAMPLECOVERAGEPROC)(GLfloat, GLboolean);
GLAPI PFNGLSAMPLECOVERAGEPROC glad_glSampleCoverage;
typedef void (APIENTRYP           PFNGLSCISSORPROC)(GLint, GLint, GLsizei, GLsizei);
GLAPI PFNGLSCISSORPROC glad_glScissor;
typedef void (APIENTRYP           PFNGLSHADERBINARYPROC)(GLsizei, const GLuint*, GLenum, const void*, GLsizei);
GLAPI PFNGLSHADERBINARYPROC glad_glShaderBinary;
typedef void (APIENTRYP           PFNGLSHADERSOURCEPROC)(GLuint, GLsizei, const GLchar**, const GLint*);
GLAPI PFNGLSHADERSOURCEPROC glad_glShaderSource;
typedef void (APIENTRYP           PFNGLSTENCILFUNCPROC)(GLenum, GLint, GLuint);
GLAPI PFNGLSTENCILFUNCPROC glad_glStencilFunc;
typedef void (APIENTRYP           PFNGLSTENCILFUNCSEPARATEPROC)(GLenum, GLenum, GLint, GLuint);
GLAPI PFNGLSTENCILFUNCSEPARATEPROC glad_glStencilFuncSeparate;
typedef void (APIENTRYP           PFNGLSTENCILMASKPROC)(GLuint);
GLAPI PFNGLSTENCILMASKPROC glad_glStencilMask;
typedef void (APIENTRYP           PFNGLSTENCILMASKSEPARATEPROC)(GLenum, GLuint);
GLAPI PFNGLSTENCILMASKSEPARATEPROC glad_glStencilMaskSeparate;
typedef void (APIENTRYP           PFNGLSTENCILOPPROC)(GLenum, GLenum, GLenum);
GLAPI PFNGLSTENCILOPPROC glad_glStencilOp;
typedef void (APIENTRYP           PFNGLSTENCILOPSEPARATEPROC)(GLenum, GLenum, GLenum, GLenum);
GLAPI PFNGLSTENCILOPSEPARATEPROC glad_glStencilOpSeparate;
typedef void (APIENTRYP           PFNGLTEXIMAGE2DPROC)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void*);
GLAPI PFNGLTEXIMAGE2DPROC glad_glTexImage2D;
typedef void (APIENTRYP           PFNGLTEXPARAMETERFPROC)(GLenum, GLenum, GLfloat);
GLAPI PFNGLTEXPARAMETERFPROC glad_glTexParameterf;
typedef void (APIENTRYP           PFNGLTEXPARAMETERFVPROC)(GLenum, GLenum, const GLfloat*);
GLAPI PFNGLTEXPARAMETERFVPROC glad_glTexParameterfv;
typedef void (APIENTRYP           PFNGLTEXPARAMETERIPROC)(GLenum, GLenum, GLint);
GLAPI PFNGLTEXPARAMETERIPROC glad_glTexParameteri;
typedef void (APIENTRYP           PFNGLTEXPARAMETERIVPROC)(GLenum, GLenum, const GLint*);
GLAPI PFNGLTEXPARAMETERIVPROC glad_glTexParameteriv;
typedef void (APIENTRYP           PFNGLTEXSUBIMAGE2DPROC)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void*);
GLAPI PFNGLTEXSUBIMAGE2DPROC glad_glTexSubImage2D;
typedef void (APIENTRYP           PFNGLUNIFORM1FPROC)(GLint, GLfloat);
GLAPI PFNGLUNIFORM1FPROC glad_glUniform1f;
typedef void (APIENTRYP           PFNGLUNIFORM1FVPROC)(GLint, GLsizei, const GLfloat*);
GLAPI PFNGLUNIFORM1FVPROC glad_glUniform1fv;
typedef void (APIENTRYP           PFNGLUNIFORM1IPROC)(GLint, GLint);
GLAPI PFNGLUNIFORM1IPROC glad_glUniform1i;
typedef void (APIENTRYP           PFNGLUNIFORM1IVPROC)(GLint, GLsizei, const GLint*);
GLAPI PFNGLUNIFORM1IVPROC glad_glUniform1iv;
typedef void (APIENTRYP           PFNGLUNIFORM2FPROC)(GLint, GLfloat, GLfloat);
GLAPI PFNGLUNIFORM2FPROC glad_glUniform2f;
typedef void (APIENTRYP           PFNGLUNIFORM2FVPROC)(GLint, GLsizei, const GLfloat*);
GLAPI PFNGLUNIFORM2FVPROC glad_glUniform2fv;
typedef void (APIENTRYP           PFNGLUNIFORM2IPROC)(GLint, GLint, GLint);
GLAPI PFNGLUNIFORM2IPROC glad_glUniform2i;
typedef void (APIENTRYP           PFNGLUNIFORM2IVPROC)(GLint, GLsizei, const GLint*);
GLAPI PFNGLUNIFORM2IVPROC glad_glUniform2iv;
typedef void (APIENTRYP           PFNGLUNIFORM3FPROC)(GLint, GLfloat, GLfloat, GLfloat);
GLAPI PFNGLUNIFORM3FPROC glad_glUniform3f;
typedef void (APIENTRYP           PFNGLUNIFORM3FVPROC)(GLint, GLsizei, const GLfloat*);
GLAPI PFNGLUNIFORM3FVPROC glad_glUniform3fv;
typedef void (APIENTRYP           PFNGLUNIFORM3IPROC)(GLint, GLint, GLint, GLint);
GLAPI PFNGLUNIFORM3IPROC glad_glUniform3i;
typedef void (APIENTRYP           PFNGLUNIFORM3IVPROC)(GLint, GLsizei, const GLint*);
GLAPI PFNGLUNIFORM3IVPROC glad_glUniform3iv;
typedef void (APIENTRYP           PFNGLUNIFORM4FPROC)(GLint, GLfloat, GLfloat, GLfloat, GLfloat);
GLAPI PFNGLUNIFORM4FPROC glad_glUniform4f;
typedef void (APIENTRYP           PFNGLUNIFORM4FVPROC)(GLint, GLsizei, const GLfloat*);
GLAPI PFNGLUNIFORM4FVPROC glad_glUniform4fv;
typedef void (APIENTRYP           PFNGLUNIFORM4IPROC)(GLint, GLint, GLint, GLint, GLint);
GLAPI PFNGLUNIFORM4IPROC glad_glUniform4i;
typedef void (APIENTRYP           PFNGLUNIFORM4IVPROC)(GLint, GLsizei, const GLint*);
GLAPI PFNGLUNIFORM4IVPROC glad_glUniform4iv;
typedef void (APIENTRYP           PFNGLUNIFORMMATRIX2FVPROC)(GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLUNIFORMMATRIX2FVPROC glad_glUniformMatrix2fv;
typedef void (APIENTRYP           PFNGLUNIFORMMATRIX3FVPROC)(GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLUNIFORMMATRIX3FVPROC glad_glUniformMatrix3fv;
typedef void (APIENTRYP           PFNGLUNIFORMMATRIX4FVPROC)(GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLUNIFORMMATRIX4FVPROC glad_glUniformMatrix4fv;
typedef void (APIENTRYP           PFNGLUSEPROGRAMPROC)(GLuint);
GLAPI PFNGLUSEPROGRAMPROC glad_glUseProgram;
typedef void (APIENTRYP           PFNGLVALIDATEPROGRAMPROC)(GLuint);
GLAPI PFNGLVALIDATEPROGRAMPROC glad_glValidateProgram;
typedef void (APIENTRYP           PFNGLVERTEXATTRIB1FPROC)(GLuint, GLfloat);
GLAPI PFNGLVERTEXATTRIB1FPROC glad_glVertexAttrib1f;
typedef void (APIENTRYP           PFNGLVERTEXATTRIB1FVPROC)(GLuint, const GLfloat*);
GLAPI PFNGLVERTEXATTRIB1FVPROC glad_glVertexAttrib1fv;
typedef void (APIENTRYP           PFNGLVERTEXATTRIB2FPROC)(GLuint, GLfloat, GLfloat);
GLAPI PFNGLVERTEXATTRIB2FPROC glad_glVertexAttrib2f;
typedef void (APIENTRYP           PFNGLVERTEXATTRIB2FVPROC)(GLuint, const GLfloat*);
GLAPI PFNGLVERTEXATTRIB2FVPROC glad_glVertexAttrib2fv;
typedef void (APIENTRYP           PFNGLVERTEXATTRIB3FPROC)(GLuint, GLfloat, GLfloat, GLfloat);
GLAPI PFNGLVERTEXATTRIB3FPROC glad_glVertexAttrib3f;
typedef void (APIENTRYP           PFNGLVERTEXATTRIB3FVPROC)(GLuint, const GLfloat*);
GLAPI PFNGLVERTEXATTRIB3FVPROC glad_glVertexAttrib3fv;
typedef void (APIENTRYP           PFNGLVERTEXATTRIB4FPROC)(GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
GLAPI PFNGLVERTEXATTRIB4FPROC glad_glVertexAttrib4f;
typedef void (APIENTRYP           PFNGLVERTEXATTRIB4FVPROC)(GLuint, const GLfloat*);
GLAPI PFNGLVERTEXATTRIB4FVPROC glad_glVertexAttrib4fv;
typedef void (APIENTRYP           PFNGLVERTEXATTRIBPOINTERPROC)(GLuint, GLint, GLenum, GLboolean, GLsizei, const void*);
GLAPI PFNGLVERTEXATTRIBPOINTERPROC glad_glVertexAttribPointer;
typedef void (APIENTRYP           PFNGLVIEWPORTPROC)(GLint, GLint, GLsizei, GLsizei);
GLAPI PFNGLVIEWPORTPROC glad_glViewport;
#endif
#ifndef GL_ES_VERSION_3_0
	#define GL_ES_VERSION_3_0 1
GLAPI int GLAD_GL_ES_VERSION_3_0;
typedef void (APIENTRYP           PFNGLREADBUFFERPROC)(GLenum);
GLAPI PFNGLREADBUFFERPROC glad_glReadBuffer;
typedef void (APIENTRYP           PFNGLDRAWRANGEELEMENTSPROC)(GLenum, GLuint, GLuint, GLsizei, GLenum, const void*);
GLAPI PFNGLDRAWRANGEELEMENTSPROC glad_glDrawRangeElements;
typedef void (APIENTRYP           PFNGLTEXIMAGE3DPROC)(GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void*);
GLAPI PFNGLTEXIMAGE3DPROC glad_glTexImage3D;
typedef void (APIENTRYP           PFNGLTEXSUBIMAGE3DPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void*);
GLAPI PFNGLTEXSUBIMAGE3DPROC glad_glTexSubImage3D;
typedef void (APIENTRYP           PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
GLAPI PFNGLCOPYTEXSUBIMAGE3DPROC glad_glCopyTexSubImage3D;
typedef void (APIENTRYP           PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const void*);
GLAPI PFNGLCOMPRESSEDTEXIMAGE3DPROC glad_glCompressedTexImage3D;
typedef void (APIENTRYP           PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void*);
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glad_glCompressedTexSubImage3D;
typedef void (APIENTRYP           PFNGLGENQUERIESPROC)(GLsizei, GLuint*);
GLAPI PFNGLGENQUERIESPROC glad_glGenQueries;
typedef void (APIENTRYP           PFNGLDELETEQUERIESPROC)(GLsizei, const GLuint*);
GLAPI PFNGLDELETEQUERIESPROC glad_glDeleteQueries;
typedef GLboolean (APIENTRYP      PFNGLISQUERYPROC)(GLuint);
GLAPI PFNGLISQUERYPROC glad_glIsQuery;
typedef void (APIENTRYP           PFNGLBEGINQUERYPROC)(GLenum, GLuint);
GLAPI PFNGLBEGINQUERYPROC glad_glBeginQuery;
typedef void (APIENTRYP           PFNGLENDQUERYPROC)(GLenum);
GLAPI PFNGLENDQUERYPROC glad_glEndQuery;
typedef void (APIENTRYP           PFNGLGETQUERYIVPROC)(GLenum, GLenum, GLint*);
GLAPI PFNGLGETQUERYIVPROC glad_glGetQueryiv;
typedef void (APIENTRYP           PFNGLGETQUERYOBJECTUIVPROC)(GLuint, GLenum, GLuint*);
GLAPI PFNGLGETQUERYOBJECTUIVPROC glad_glGetQueryObjectuiv;
typedef GLboolean (APIENTRYP      PFNGLUNMAPBUFFERPROC)(GLenum);
GLAPI PFNGLUNMAPBUFFERPROC glad_glUnmapBuffer;
typedef void (APIENTRYP           PFNGLGETBUFFERPOINTERVPROC)(GLenum, GLenum, void**);
GLAPI PFNGLGETBUFFERPOINTERVPROC glad_glGetBufferPointerv;
typedef void (APIENTRYP           PFNGLDRAWBUFFERSPROC)(GLsizei, const GLenum*);
GLAPI PFNGLDRAWBUFFERSPROC glad_glDrawBuffers;
typedef void (APIENTRYP           PFNGLUNIFORMMATRIX2X3FVPROC)(GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLUNIFORMMATRIX2X3FVPROC glad_glUniformMatrix2x3fv;
typedef void (APIENTRYP           PFNGLUNIFORMMATRIX3X2FVPROC)(GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLUNIFORMMATRIX3X2FVPROC glad_glUniformMatrix3x2fv;
typedef void (APIENTRYP           PFNGLUNIFORMMATRIX2X4FVPROC)(GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLUNIFORMMATRIX2X4FVPROC glad_glUniformMatrix2x4fv;
typedef void (APIENTRYP           PFNGLUNIFORMMATRIX4X2FVPROC)(GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLUNIFORMMATRIX4X2FVPROC glad_glUniformMatrix4x2fv;
typedef void (APIENTRYP           PFNGLUNIFORMMATRIX3X4FVPROC)(GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLUNIFORMMATRIX3X4FVPROC glad_glUniformMatrix3x4fv;
typedef void (APIENTRYP           PFNGLUNIFORMMATRIX4X3FVPROC)(GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLUNIFORMMATRIX4X3FVPROC glad_glUniformMatrix4x3fv;
typedef void (APIENTRYP           PFNGLBLITFRAMEBUFFERPROC)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum);
GLAPI PFNGLBLITFRAMEBUFFERPROC glad_glBlitFramebuffer;
typedef void (APIENTRYP           PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum, GLsizei, GLenum, GLsizei, GLsizei);
GLAPI PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glad_glRenderbufferStorageMultisample;
typedef void (APIENTRYP           PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum, GLenum, GLuint, GLint, GLint);
GLAPI PFNGLFRAMEBUFFERTEXTURELAYERPROC glad_glFramebufferTextureLayer;
typedef void* (APIENTRYP          PFNGLMAPBUFFERRANGEPROC)(GLenum, GLintptr, GLsizeiptr, GLbitfield);
GLAPI PFNGLMAPBUFFERRANGEPROC glad_glMapBufferRange;
typedef void (APIENTRYP           PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum, GLintptr, GLsizeiptr);
GLAPI PFNGLFLUSHMAPPEDBUFFERRANGEPROC glad_glFlushMappedBufferRange;
typedef void (APIENTRYP           PFNGLBINDVERTEXARRAYPROC)(GLuint);
GLAPI PFNGLBINDVERTEXARRAYPROC glad_glBindVertexArray;
typedef void (APIENTRYP           PFNGLDELETEVERTEXARRAYSPROC)(GLsizei, const GLuint*);
GLAPI PFNGLDELETEVERTEXARRAYSPROC glad_glDeleteVertexArrays;
typedef void (APIENTRYP           PFNGLGENVERTEXARRAYSPROC)(GLsizei, GLuint*);
GLAPI PFNGLGENVERTEXARRAYSPROC glad_glGenVertexArrays;
typedef GLboolean (APIENTRYP      PFNGLISVERTEXARRAYPROC)(GLuint);
GLAPI PFNGLISVERTEXARRAYPROC glad_glIsVertexArray;
typedef void (APIENTRYP           PFNGLGETINTEGERI_VPROC)(GLenum, GLuint, GLint*);
GLAPI PFNGLGETINTEGERI_VPROC glad_glGetIntegeri_v;
typedef void (APIENTRYP           PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum);
GLAPI PFNGLBEGINTRANSFORMFEEDBACKPROC glad_glBeginTransformFeedback;
typedef void (APIENTRYP           PFNGLENDTRANSFORMFEEDBACKPROC)();
GLAPI PFNGLENDTRANSFORMFEEDBACKPROC glad_glEndTransformFeedback;
typedef void (APIENTRYP           PFNGLBINDBUFFERRANGEPROC)(GLenum, GLuint, GLuint, GLintptr, GLsizeiptr);
GLAPI PFNGLBINDBUFFERRANGEPROC glad_glBindBufferRange;
typedef void (APIENTRYP           PFNGLBINDBUFFERBASEPROC)(GLenum, GLuint, GLuint);
GLAPI PFNGLBINDBUFFERBASEPROC glad_glBindBufferBase;
typedef void (APIENTRYP           PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint, GLsizei, const GLchar**, GLenum);
GLAPI PFNGLTRANSFORMFEEDBACKVARYINGSPROC glad_glTransformFeedbackVaryings;
typedef void (APIENTRYP           PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint, GLuint, GLsizei, GLsizei*, GLsizei*, GLenum*, GLchar*);
GLAPI PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glad_glGetTransformFeedbackVarying;
typedef void (APIENTRYP           PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint, GLint, GLenum, GLsizei, const void*);
GLAPI PFNGLVERTEXATTRIBIPOINTERPROC glad_glVertexAttribIPointer;
typedef void (APIENTRYP           PFNGLGETVERTEXATTRIBIIVPROC)(GLuint, GLenum, GLint*);
GLAPI PFNGLGETVERTEXATTRIBIIVPROC glad_glGetVertexAttribIiv;
typedef void (APIENTRYP           PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint, GLenum, GLuint*);
GLAPI PFNGLGETVERTEXATTRIBIUIVPROC glad_glGetVertexAttribIuiv;
typedef void (APIENTRYP           PFNGLVERTEXATTRIBI4IPROC)(GLuint, GLint, GLint, GLint, GLint);
GLAPI PFNGLVERTEXATTRIBI4IPROC glad_glVertexAttribI4i;
typedef void (APIENTRYP           PFNGLVERTEXATTRIBI4UIPROC)(GLuint, GLuint, GLuint, GLuint, GLuint);
GLAPI PFNGLVERTEXATTRIBI4UIPROC glad_glVertexAttribI4ui;
typedef void (APIENTRYP           PFNGLVERTEXATTRIBI4IVPROC)(GLuint, const GLint*);
GLAPI PFNGLVERTEXATTRIBI4IVPROC glad_glVertexAttribI4iv;
typedef void (APIENTRYP           PFNGLVERTEXATTRIBI4UIVPROC)(GLuint, const GLuint*);
GLAPI PFNGLVERTEXATTRIBI4UIVPROC glad_glVertexAttribI4uiv;
typedef void (APIENTRYP           PFNGLGETUNIFORMUIVPROC)(GLuint, GLint, GLuint*);
GLAPI PFNGLGETUNIFORMUIVPROC glad_glGetUniformuiv;
typedef GLint (APIENTRYP          PFNGLGETFRAGDATALOCATIONPROC)(GLuint, const GLchar*);
GLAPI PFNGLGETFRAGDATALOCATIONPROC glad_glGetFragDataLocation;
typedef void (APIENTRYP           PFNGLUNIFORM1UIPROC)(GLint, GLuint);
GLAPI PFNGLUNIFORM1UIPROC glad_glUniform1ui;
typedef void (APIENTRYP           PFNGLUNIFORM2UIPROC)(GLint, GLuint, GLuint);
GLAPI PFNGLUNIFORM2UIPROC glad_glUniform2ui;
typedef void (APIENTRYP           PFNGLUNIFORM3UIPROC)(GLint, GLuint, GLuint, GLuint);
GLAPI PFNGLUNIFORM3UIPROC glad_glUniform3ui;
typedef void (APIENTRYP           PFNGLUNIFORM4UIPROC)(GLint, GLuint, GLuint, GLuint, GLuint);
GLAPI PFNGLUNIFORM4UIPROC glad_glUniform4ui;
typedef void (APIENTRYP           PFNGLUNIFORM1UIVPROC)(GLint, GLsizei, const GLuint*);
GLAPI PFNGLUNIFORM1UIVPROC glad_glUniform1uiv;
typedef void (APIENTRYP           PFNGLUNIFORM2UIVPROC)(GLint, GLsizei, const GLuint*);
GLAPI PFNGLUNIFORM2UIVPROC glad_glUniform2uiv;
typedef void (APIENTRYP           PFNGLUNIFORM3UIVPROC)(GLint, GLsizei, const GLuint*);
GLAPI PFNGLUNIFORM3UIVPROC glad_glUniform3uiv;
typedef void (APIENTRYP           PFNGLUNIFORM4UIVPROC)(GLint, GLsizei, const GLuint*);
GLAPI PFNGLUNIFORM4UIVPROC glad_glUniform4uiv;
typedef void (APIENTRYP           PFNGLCLEARBUFFERIVPROC)(GLenum, GLint, const GLint*);
GLAPI PFNGLCLEARBUFFERIVPROC glad_glClearBufferiv;
typedef void (APIENTRYP           PFNGLCLEARBUFFERUIVPROC)(GLenum, GLint, const GLuint*);
GLAPI PFNGLCLEARBUFFERUIVPROC glad_glClearBufferuiv;
typedef void (APIENTRYP           PFNGLCLEARBUFFERFVPROC)(GLenum, GLint, const GLfloat*);
GLAPI PFNGLCLEARBUFFERFVPROC glad_glClearBufferfv;
typedef void (APIENTRYP           PFNGLCLEARBUFFERFIPROC)(GLenum, GLint, GLfloat, GLint);
GLAPI PFNGLCLEARBUFFERFIPROC glad_glClearBufferfi;
typedef const GLubyte* (APIENTRYP PFNGLGETSTRINGIPROC)(GLenum, GLuint);
GLAPI PFNGLGETSTRINGIPROC glad_glGetStringi;
typedef void (APIENTRYP           PFNGLCOPYBUFFERSUBDATAPROC)(GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr);
GLAPI PFNGLCOPYBUFFERSUBDATAPROC glad_glCopyBufferSubData;
typedef void (APIENTRYP           PFNGLGETUNIFORMINDICESPROC)(GLuint, GLsizei, const GLchar**, GLuint*);
GLAPI PFNGLGETUNIFORMINDICESPROC glad_glGetUniformIndices;
typedef void (APIENTRYP           PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint, GLsizei, const GLuint*, GLenum, GLint*);
GLAPI PFNGLGETACTIVEUNIFORMSIVPROC glad_glGetActiveUniformsiv;
typedef GLuint (APIENTRYP         PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint, const GLchar*);
GLAPI PFNGLGETUNIFORMBLOCKINDEXPROC glad_glGetUniformBlockIndex;
typedef void (APIENTRYP           PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint, GLuint, GLenum, GLint*);
GLAPI PFNGLGETACTIVEUNIFORMBLOCKIVPROC glad_glGetActiveUniformBlockiv;
typedef void (APIENTRYP           PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint, GLuint, GLsizei, GLsizei*, GLchar*);
GLAPI PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glad_glGetActiveUniformBlockName;
typedef void (APIENTRYP           PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint, GLuint, GLuint);
GLAPI PFNGLUNIFORMBLOCKBINDINGPROC glad_glUniformBlockBinding;
typedef void (APIENTRYP           PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum, GLint, GLsizei, GLsizei);
GLAPI PFNGLDRAWARRAYSINSTANCEDPROC glad_glDrawArraysInstanced;
typedef void (APIENTRYP           PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum, GLsizei, GLenum, const void*, GLsizei);
GLAPI PFNGLDRAWELEMENTSINSTANCEDPROC glad_glDrawElementsInstanced;
typedef GLsync (APIENTRYP         PFNGLFENCESYNCPROC)(GLenum, GLbitfield);
GLAPI PFNGLFENCESYNCPROC glad_glFenceSync;
typedef GLboolean (APIENTRYP      PFNGLISSYNCPROC)(GLsync);
GLAPI PFNGLISSYNCPROC glad_glIsSync;
typedef void (APIENTRYP           PFNGLDELETESYNCPROC)(GLsync);
GLAPI PFNGLDELETESYNCPROC glad_glDeleteSync;
typedef GLenum (APIENTRYP         PFNGLCLIENTWAITSYNCPROC)(GLsync, GLbitfield, GLuint64);
GLAPI PFNGLCLIENTWAITSYNCPROC glad_glClientWaitSync;
typedef void (APIENTRYP           PFNGLWAITSYNCPROC)(GLsync, GLbitfield, GLuint64);
GLAPI PFNGLWAITSYNCPROC glad_glWaitSync;
typedef void (APIENTRYP           PFNGLGETINTEGER64VPROC)(GLenum, GLint64*);
GLAPI PFNGLGETINTEGER64VPROC glad_glGetInteger64v;
typedef void (APIENTRYP           PFNGLGETSYNCIVPROC)(GLsync, GLenum, GLsizei, GLsizei*, GLint*);
GLAPI PFNGLGETSYNCIVPROC glad_glGetSynciv;
typedef void (APIENTRYP           PFNGLGETINTEGER64I_VPROC)(GLenum, GLuint, GLint64*);
GLAPI PFNGLGETINTEGER64I_VPROC glad_glGetInteger64i_v;
typedef void (APIENTRYP           PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum, GLenum, GLint64*);
GLAPI PFNGLGETBUFFERPARAMETERI64VPROC glad_glGetBufferParameteri64v;
typedef void (APIENTRYP           PFNGLGENSAMPLERSPROC)(GLsizei, GLuint*);
GLAPI PFNGLGENSAMPLERSPROC glad_glGenSamplers;
typedef void (APIENTRYP           PFNGLDELETESAMPLERSPROC)(GLsizei, const GLuint*);
GLAPI PFNGLDELETESAMPLERSPROC glad_glDeleteSamplers;
typedef GLboolean (APIENTRYP      PFNGLISSAMPLERPROC)(GLuint);
GLAPI PFNGLISSAMPLERPROC glad_glIsSampler;
typedef void (APIENTRYP           PFNGLBINDSAMPLERPROC)(GLuint, GLuint);
GLAPI PFNGLBINDSAMPLERPROC glad_glBindSampler;
typedef void (APIENTRYP           PFNGLSAMPLERPARAMETERIPROC)(GLuint, GLenum, GLint);
GLAPI PFNGLSAMPLERPARAMETERIPROC glad_glSamplerParameteri;
typedef void (APIENTRYP           PFNGLSAMPLERPARAMETERIVPROC)(GLuint, GLenum, const GLint*);
GLAPI PFNGLSAMPLERPARAMETERIVPROC glad_glSamplerParameteriv;
typedef void (APIENTRYP           PFNGLSAMPLERPARAMETERFPROC)(GLuint, GLenum, GLfloat);
GLAPI PFNGLSAMPLERPARAMETERFPROC glad_glSamplerParameterf;
typedef void (APIENTRYP           PFNGLSAMPLERPARAMETERFVPROC)(GLuint, GLenum, const GLfloat*);
GLAPI PFNGLSAMPLERPARAMETERFVPROC glad_glSamplerParameterfv;
typedef void (APIENTRYP           PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint, GLenum, GLint*);
GLAPI PFNGLGETSAMPLERPARAMETERIVPROC glad_glGetSamplerParameteriv;
typedef void (APIENTRYP           PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint, GLenum, GLfloat*);
GLAPI PFNGLGETSAMPLERPARAMETERFVPROC glad_glGetSamplerParameterfv;
typedef void (APIENTRYP           PFNGLVERTEXATTRIBDIVISORPROC)(GLuint, GLuint);
GLAPI PFNGLVERTEXATTRIBDIVISORPROC glad_glVertexAttribDivisor;
typedef void (APIENTRYP           PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum, GLuint);
GLAPI PFNGLBINDTRANSFORMFEEDBACKPROC glad_glBindTransformFeedback;
typedef void (APIENTRYP           PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei, const GLuint*);
GLAPI PFNGLDELETETRANSFORMFEEDBACKSPROC glad_glDeleteTransformFeedbacks;
typedef void (APIENTRYP           PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei, GLuint*);
GLAPI PFNGLGENTRANSFORMFEEDBACKSPROC glad_glGenTransformFeedbacks;
typedef GLboolean (APIENTRYP      PFNGLISTRANSFORMFEEDBACKPROC)(GLuint);
GLAPI PFNGLISTRANSFORMFEEDBACKPROC glad_glIsTransformFeedback;
typedef void (APIENTRYP           PFNGLPAUSETRANSFORMFEEDBACKPROC)();
GLAPI PFNGLPAUSETRANSFORMFEEDBACKPROC glad_glPauseTransformFeedback;
typedef void (APIENTRYP           PFNGLRESUMETRANSFORMFEEDBACKPROC)();
GLAPI PFNGLRESUMETRANSFORMFEEDBACKPROC glad_glResumeTransformFeedback;
typedef void (APIENTRYP           PFNGLGETPROGRAMBINARYPROC)(GLuint, GLsizei, GLsizei*, GLenum*, void*);
GLAPI PFNGLGETPROGRAMBINARYPROC glad_glGetProgramBinary;
typedef void (APIENTRYP           PFNGLPROGRAMBINARYPROC)(GLuint, GLenum, const void*, GLsizei);
GLAPI PFNGLPROGRAMBINARYPROC glad_glProgramBinary;
typedef void (APIENTRYP           PFNGLPROGRAMPARAMETERIPROC)(GLuint, GLenum, GLint);
GLAPI PFNGLPROGRAMPARAMETERIPROC glad_glProgramParameteri;
typedef void (APIENTRYP           PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum, GLsizei, const GLenum*);
GLAPI PFNGLINVALIDATEFRAMEBUFFERPROC glad_glInvalidateFramebuffer;
typedef void (APIENTRYP           PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum, GLsizei, const GLenum*, GLint, GLint, GLsizei, GLsizei);
GLAPI PFNGLINVALIDATESUBFRAMEBUFFERPROC glad_glInvalidateSubFramebuffer;
typedef void (APIENTRYP           PFNGLTEXSTORAGE2DPROC)(GLenum, GLsizei, GLenum, GLsizei, GLsizei);
GLAPI PFNGLTEXSTORAGE2DPROC glad_glTexStorage2D;
typedef void (APIENTRYP           PFNGLTEXSTORAGE3DPROC)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei);
GLAPI PFNGLTEXSTORAGE3DPROC glad_glTexStorage3D;
typedef void (APIENTRYP           PFNGLGETINTERNALFORMATIVPROC)(GLenum, GLenum, GLenum, GLsizei, GLint*);
GLAPI PFNGLGETINTERNALFORMATIVPROC glad_glGetInternalformativ;
#endif
#ifndef GL_ES_VERSION_3_1
	#define GL_ES_VERSION_3_1 1
GLAPI int GLAD_GL_ES_VERSION_3_1;
typedef void (APIENTRYP      PFNGLDISPATCHCOMPUTEPROC)(GLuint, GLuint, GLuint);
GLAPI PFNGLDISPATCHCOMPUTEPROC glad_glDispatchCompute;
typedef void (APIENTRYP      PFNGLDISPATCHCOMPUTEINDIRECTPROC)(GLintptr);
GLAPI PFNGLDISPATCHCOMPUTEINDIRECTPROC glad_glDispatchComputeIndirect;
typedef void (APIENTRYP      PFNGLDRAWARRAYSINDIRECTPROC)(GLenum, const void*);
GLAPI PFNGLDRAWARRAYSINDIRECTPROC glad_glDrawArraysIndirect;
typedef void (APIENTRYP      PFNGLDRAWELEMENTSINDIRECTPROC)(GLenum, GLenum, const void*);
GLAPI PFNGLDRAWELEMENTSINDIRECTPROC glad_glDrawElementsIndirect;
typedef void (APIENTRYP      PFNGLFRAMEBUFFERPARAMETERIPROC)(GLenum, GLenum, GLint);
GLAPI PFNGLFRAMEBUFFERPARAMETERIPROC glad_glFramebufferParameteri;
typedef void (APIENTRYP      PFNGLGETFRAMEBUFFERPARAMETERIVPROC)(GLenum, GLenum, GLint*);
GLAPI PFNGLGETFRAMEBUFFERPARAMETERIVPROC glad_glGetFramebufferParameteriv;
typedef void (APIENTRYP      PFNGLGETPROGRAMINTERFACEIVPROC)(GLuint, GLenum, GLenum, GLint*);
GLAPI PFNGLGETPROGRAMINTERFACEIVPROC glad_glGetProgramInterfaceiv;
typedef GLuint (APIENTRYP    PFNGLGETPROGRAMRESOURCEINDEXPROC)(GLuint, GLenum, const GLchar*);
GLAPI PFNGLGETPROGRAMRESOURCEINDEXPROC glad_glGetProgramResourceIndex;
typedef void (APIENTRYP      PFNGLGETPROGRAMRESOURCENAMEPROC)(GLuint, GLenum, GLuint, GLsizei, GLsizei*, GLchar*);
GLAPI PFNGLGETPROGRAMRESOURCENAMEPROC glad_glGetProgramResourceName;
typedef void (APIENTRYP      PFNGLGETPROGRAMRESOURCEIVPROC)(GLuint, GLenum, GLuint, GLsizei, const GLenum*, GLsizei, GLsizei*, GLint*);
GLAPI PFNGLGETPROGRAMRESOURCEIVPROC glad_glGetProgramResourceiv;
typedef GLint (APIENTRYP     PFNGLGETPROGRAMRESOURCELOCATIONPROC)(GLuint, GLenum, const GLchar*);
GLAPI PFNGLGETPROGRAMRESOURCELOCATIONPROC glad_glGetProgramResourceLocation;
typedef void (APIENTRYP      PFNGLUSEPROGRAMSTAGESPROC)(GLuint, GLbitfield, GLuint);
GLAPI PFNGLUSEPROGRAMSTAGESPROC glad_glUseProgramStages;
typedef void (APIENTRYP      PFNGLACTIVESHADERPROGRAMPROC)(GLuint, GLuint);
GLAPI PFNGLACTIVESHADERPROGRAMPROC glad_glActiveShaderProgram;
typedef GLuint (APIENTRYP    PFNGLCREATESHADERPROGRAMVPROC)(GLenum, GLsizei, const GLchar**);
GLAPI PFNGLCREATESHADERPROGRAMVPROC glad_glCreateShaderProgramv;
typedef void (APIENTRYP      PFNGLBINDPROGRAMPIPELINEPROC)(GLuint);
GLAPI PFNGLBINDPROGRAMPIPELINEPROC glad_glBindProgramPipeline;
typedef void (APIENTRYP      PFNGLDELETEPROGRAMPIPELINESPROC)(GLsizei, const GLuint*);
GLAPI PFNGLDELETEPROGRAMPIPELINESPROC glad_glDeleteProgramPipelines;
typedef void (APIENTRYP      PFNGLGENPROGRAMPIPELINESPROC)(GLsizei, GLuint*);
GLAPI PFNGLGENPROGRAMPIPELINESPROC glad_glGenProgramPipelines;
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEPROC)(GLuint);
GLAPI PFNGLISPROGRAMPIPELINEPROC glad_glIsProgramPipeline;
typedef void (APIENTRYP      PFNGLGETPROGRAMPIPELINEIVPROC)(GLuint, GLenum, GLint*);
GLAPI PFNGLGETPROGRAMPIPELINEIVPROC glad_glGetProgramPipelineiv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM1IPROC)(GLuint, GLint, GLint);
GLAPI PFNGLPROGRAMUNIFORM1IPROC glad_glProgramUniform1i;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM2IPROC)(GLuint, GLint, GLint, GLint);
GLAPI PFNGLPROGRAMUNIFORM2IPROC glad_glProgramUniform2i;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM3IPROC)(GLuint, GLint, GLint, GLint, GLint);
GLAPI PFNGLPROGRAMUNIFORM3IPROC glad_glProgramUniform3i;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM4IPROC)(GLuint, GLint, GLint, GLint, GLint, GLint);
GLAPI PFNGLPROGRAMUNIFORM4IPROC glad_glProgramUniform4i;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM1UIPROC)(GLuint, GLint, GLuint);
GLAPI PFNGLPROGRAMUNIFORM1UIPROC glad_glProgramUniform1ui;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM2UIPROC)(GLuint, GLint, GLuint, GLuint);
GLAPI PFNGLPROGRAMUNIFORM2UIPROC glad_glProgramUniform2ui;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM3UIPROC)(GLuint, GLint, GLuint, GLuint, GLuint);
GLAPI PFNGLPROGRAMUNIFORM3UIPROC glad_glProgramUniform3ui;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM4UIPROC)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint);
GLAPI PFNGLPROGRAMUNIFORM4UIPROC glad_glProgramUniform4ui;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM1FPROC)(GLuint, GLint, GLfloat);
GLAPI PFNGLPROGRAMUNIFORM1FPROC glad_glProgramUniform1f;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM2FPROC)(GLuint, GLint, GLfloat, GLfloat);
GLAPI PFNGLPROGRAMUNIFORM2FPROC glad_glProgramUniform2f;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM3FPROC)(GLuint, GLint, GLfloat, GLfloat, GLfloat);
GLAPI PFNGLPROGRAMUNIFORM3FPROC glad_glProgramUniform3f;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM4FPROC)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat);
GLAPI PFNGLPROGRAMUNIFORM4FPROC glad_glProgramUniform4f;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM1IVPROC)(GLuint, GLint, GLsizei, const GLint*);
GLAPI PFNGLPROGRAMUNIFORM1IVPROC glad_glProgramUniform1iv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM2IVPROC)(GLuint, GLint, GLsizei, const GLint*);
GLAPI PFNGLPROGRAMUNIFORM2IVPROC glad_glProgramUniform2iv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM3IVPROC)(GLuint, GLint, GLsizei, const GLint*);
GLAPI PFNGLPROGRAMUNIFORM3IVPROC glad_glProgramUniform3iv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM4IVPROC)(GLuint, GLint, GLsizei, const GLint*);
GLAPI PFNGLPROGRAMUNIFORM4IVPROC glad_glProgramUniform4iv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM1UIVPROC)(GLuint, GLint, GLsizei, const GLuint*);
GLAPI PFNGLPROGRAMUNIFORM1UIVPROC glad_glProgramUniform1uiv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM2UIVPROC)(GLuint, GLint, GLsizei, const GLuint*);
GLAPI PFNGLPROGRAMUNIFORM2UIVPROC glad_glProgramUniform2uiv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM3UIVPROC)(GLuint, GLint, GLsizei, const GLuint*);
GLAPI PFNGLPROGRAMUNIFORM3UIVPROC glad_glProgramUniform3uiv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM4UIVPROC)(GLuint, GLint, GLsizei, const GLuint*);
GLAPI PFNGLPROGRAMUNIFORM4UIVPROC glad_glProgramUniform4uiv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM1FVPROC)(GLuint, GLint, GLsizei, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORM1FVPROC glad_glProgramUniform1fv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM2FVPROC)(GLuint, GLint, GLsizei, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORM2FVPROC glad_glProgramUniform2fv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM3FVPROC)(GLuint, GLint, GLsizei, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORM3FVPROC glad_glProgramUniform3fv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM4FVPROC)(GLuint, GLint, GLsizei, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORM4FVPROC glad_glProgramUniform4fv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX2FVPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2FVPROC glad_glProgramUniformMatrix2fv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX3FVPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3FVPROC glad_glProgramUniformMatrix3fv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX4FVPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4FVPROC glad_glProgramUniformMatrix4fv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glad_glProgramUniformMatrix2x3fv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glad_glProgramUniformMatrix3x2fv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glad_glProgramUniformMatrix2x4fv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glad_glProgramUniformMatrix4x2fv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glad_glProgramUniformMatrix3x4fv;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glad_glProgramUniformMatrix4x3fv;
typedef void (APIENTRYP      PFNGLVALIDATEPROGRAMPIPELINEPROC)(GLuint);
GLAPI PFNGLVALIDATEPROGRAMPIPELINEPROC glad_glValidateProgramPipeline;
typedef void (APIENTRYP      PFNGLGETPROGRAMPIPELINEINFOLOGPROC)(GLuint, GLsizei, GLsizei*, GLchar*);
GLAPI PFNGLGETPROGRAMPIPELINEINFOLOGPROC glad_glGetProgramPipelineInfoLog;
typedef void (APIENTRYP      PFNGLBINDIMAGETEXTUREPROC)(GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLenum);
GLAPI PFNGLBINDIMAGETEXTUREPROC glad_glBindImageTexture;
typedef void (APIENTRYP      PFNGLGETBOOLEANI_VPROC)(GLenum, GLuint, GLboolean*);
GLAPI PFNGLGETBOOLEANI_VPROC glad_glGetBooleani_v;
typedef void (APIENTRYP      PFNGLMEMORYBARRIERPROC)(GLbitfield);
GLAPI PFNGLMEMORYBARRIERPROC glad_glMemoryBarrier;
typedef void (APIENTRYP      PFNGLMEMORYBARRIERBYREGIONPROC)(GLbitfield);
GLAPI PFNGLMEMORYBARRIERBYREGIONPROC glad_glMemoryBarrierByRegion;
typedef void (APIENTRYP      PFNGLTEXSTORAGE2DMULTISAMPLEPROC)(GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean);
GLAPI PFNGLTEXSTORAGE2DMULTISAMPLEPROC glad_glTexStorage2DMultisample;
typedef void (APIENTRYP      PFNGLGETMULTISAMPLEFVPROC)(GLenum, GLuint, GLfloat*);
GLAPI PFNGLGETMULTISAMPLEFVPROC glad_glGetMultisamplefv;
typedef void (APIENTRYP      PFNGLSAMPLEMASKIPROC)(GLuint, GLbitfield);
GLAPI PFNGLSAMPLEMASKIPROC glad_glSampleMaski;
typedef void (APIENTRYP      PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum, GLint, GLenum, GLint*);
GLAPI PFNGLGETTEXLEVELPARAMETERIVPROC glad_glGetTexLevelParameteriv;
typedef void (APIENTRYP      PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum, GLint, GLenum, GLfloat*);
GLAPI PFNGLGETTEXLEVELPARAMETERFVPROC glad_glGetTexLevelParameterfv;
typedef void (APIENTRYP      PFNGLBINDVERTEXBUFFERPROC)(GLuint, GLuint, GLintptr, GLsizei);
GLAPI PFNGLBINDVERTEXBUFFERPROC glad_glBindVertexBuffer;
typedef void (APIENTRYP      PFNGLVERTEXATTRIBFORMATPROC)(GLuint, GLint, GLenum, GLboolean, GLuint);
GLAPI PFNGLVERTEXATTRIBFORMATPROC glad_glVertexAttribFormat;
typedef void (APIENTRYP      PFNGLVERTEXATTRIBIFORMATPROC)(GLuint, GLint, GLenum, GLuint);
GLAPI PFNGLVERTEXATTRIBIFORMATPROC glad_glVertexAttribIFormat;
typedef void (APIENTRYP      PFNGLVERTEXATTRIBBINDINGPROC)(GLuint, GLuint);
GLAPI PFNGLVERTEXATTRIBBINDINGPROC glad_glVertexAttribBinding;
typedef void (APIENTRYP      PFNGLVERTEXBINDINGDIVISORPROC)(GLuint, GLuint);
GLAPI PFNGLVERTEXBINDINGDIVISORPROC glad_glVertexBindingDivisor;
#endif
#if defined(__cplusplus) && defined(GLAD_INSTRUMENT_CALL)
struct glad_tag_glGenProgramPipelines {};
inline void glad_wrapped_glGenProgramPipelines(GLsizei _n, GLuint* _pipelines) { GLAD_INSTRUMENT_CALL(glGenProgramPipelines, _n, _pipelines); }
	#define glGenProgramPipelines glad_wrapped_glGenProgramPipelines
struct glad_tag_glFlush {};
inline void glad_wrapped_glFlush() { GLAD_INSTRUMENT_CALL(glFlush); }
	#define glFlush glad_wrapped_glFlush
struct glad_tag_glGetRenderbufferParameteriv {};
inline void glad_wrapped_glGetRenderbufferParameteriv(GLenum _target, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetRenderbufferParameteriv, _target, _pname, _params); }
	#define glGetRenderbufferParameteriv glad_wrapped_glGetRenderbufferParameteriv
struct glad_tag_glClearColor {};
inline void glad_wrapped_glClearColor(GLfloat _red, GLfloat _green, GLfloat _blue, GLfloat _alpha) { GLAD_INSTRUMENT_CALL(glClearColor, _red, _green, _blue, _alpha); }
	#define glClearColor glad_wrapped_glClearColor
struct glad_tag_glProgramUniform3iv {};
inline void glad_wrapped_glProgramUniform3iv(GLuint _program, GLint _location, GLsizei _count, const GLint* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform3iv, _program, _location, _count, _value); }
	#define glProgramUniform3iv glad_wrapped_glProgramUniform3iv
struct glad_tag_glGetUniformBlockIndex {};
inline GLuint glad_wrapped_glGetUniformBlockIndex(GLuint _program, const GLchar* _uniformBlockName) { return GLAD_INSTRUMENT_CALL(glGetUniformBlockIndex, _program, _uniformBlockName); }
	#define glGetUniformBlockIndex glad_wrapped_glGetUniformBlockIndex
struct glad_tag_glProgramUniform4ui {};
inline void glad_wrapped_glProgramUniform4ui(GLuint _program, GLint _location, GLuint _v0, GLuint _v1, GLuint _v2, GLuint _v3) { GLAD_INSTRUMENT_CALL(glProgramUniform4ui, _program, _location, _v0, _v1, _v2, _v3); }
	#define glProgramUniform4ui glad_wrapped_glProgramUniform4ui
struct glad_tag_glClearBufferiv {};
inline void glad_wrapped_glClearBufferiv(GLenum _buffer, GLint _drawbuffer, const GLint* _value) { GLAD_INSTRUMENT_CALL(glClearBufferiv, _buffer, _drawbuffer, _value); }
	#define glClearBufferiv glad_wrapped_glClearBufferiv
struct glad_tag_glStencilMaskSeparate {};
inline void glad_wrapped_glStencilMaskSeparate(GLenum _face, GLuint _mask) { GLAD_INSTRUMENT_CALL(glStencilMaskSeparate, _face, _mask); }
	#define glStencilMaskSeparate glad_wrapped_glStencilMaskSeparate
struct glad_tag_glGetVertexAttribPointerv {};
inline void glad_wrapped_glGetVertexAttribPointerv(GLuint _index, GLenum _pname, void** _pointer) { GLAD_INSTRUMENT_CALL(glGetVertexAttribPointerv, _index, _pname, _pointer); }
	#define glGetVertexAttribPointerv glad_wrapped_glGetVertexAttribPointerv
struct glad_tag_glProgramUniform2ui {};
inline void glad_wrapped_glProgramUniform2ui(GLuint _program, GLint _location, GLuint _v0, GLuint _v1) { GLAD_INSTRUMENT_CALL(glProgramUniform2ui, _program, _location, _v0, _v1); }
	#define glProgramUniform2ui glad_wrapped_glProgramUniform2ui
struct glad_tag_glLinkProgram {};
inline void glad_wrapped_glLinkProgram(GLuint _program) { GLAD_INSTRUMENT_CALL(glLinkProgram, _program); }
	#define glLinkProgram glad_wrapped_glLinkProgram
struct glad_tag_glProgramUniformMatrix4fv {};
inline void glad_wrapped_glProgramUniformMatrix4fv(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix4fv, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix4fv glad_wrapped_glProgramUniformMatrix4fv
struct glad_tag_glBindTexture {};
inline void glad_wrapped_glBindTexture(GLenum _target, GLuint _texture) { GLAD_INSTRUMENT_CALL(glBindTexture, _target, _texture); }
	#define glBindTexture glad_wrapped_glBindTexture
struct glad_tag_glGetStringi {};
inline const GLubyte* glad_wrapped_glGetStringi(GLenum _name, GLuint _index) { return GLAD_INSTRUMENT_CALL(glGetStringi, _name, _index); }
	#define glGetStringi glad_wrapped_glGetStringi
struct glad_tag_glFenceSync {};
inline GLsync glad_wrapped_glFenceSync(GLenum _condition, GLbitfield _flags) { return GLAD_INSTRUMENT_CALL(glFenceSync, _condition, _flags); }
	#define glFenceSync glad_wrapped_glFenceSync
struct glad_tag_glUniform3ui {};
inline void glad_wrapped_glUniform3ui(GLint _location, GLuint _v0, GLuint _v1, GLuint _v2) { GLAD_INSTRUMENT_CALL(glUniform3ui, _location, _v0, _v1, _v2); }
	#define glUniform3ui glad_wrapped_glUniform3ui
struct glad_tag_glFramebufferRenderbuffer {};
inline void glad_wrapped_glFramebufferRenderbuffer(GLenum _target, GLenum _attachment, GLenum _renderbuffertarget, GLuint _renderbuffer) { GLAD_INSTRUMENT_CALL(glFramebufferRenderbuffer, _target, _attachment, _renderbuffertarget, _renderbuffer); }
	#define glFramebufferRenderbuffer glad_wrapped_glFramebufferRenderbuffer
struct glad_tag_glGetString {};
inline const GLubyte* glad_wrapped_glGetString(GLenum _name) { return GLAD_INSTRUMENT_CALL(glGetString, _name); }
	#define glGetString glad_wrapped_glGetString
struct glad_tag_glDispatchCompute {};
inline void glad_wrapped_glDispatchCompute(GLuint _num_groups_x, GLuint _num_groups_y, GLuint _num_groups_z) { GLAD_INSTRUMENT_CALL(glDispatchCompute, _num_groups_x, _num_groups_y, _num_groups_z); }
	#define glDispatchCompute glad_wrapped_glDispatchCompute
struct glad_tag_glCompressedTexSubImage3D {};
inline void glad_wrapped_glCompressedTexSubImage3D(GLenum _target, GLint _level, GLint _xoffset, GLint _yoffset, GLint _zoffset, GLsizei _width, GLsizei _height, GLsizei _depth, GLenum _format, GLsizei _imageSize, const void* _data) { GLAD_INSTRUMENT_CALL(glCompressedTexSubImage3D, _target, _level, _xoffset, _yoffset, _zoffset, _width, _height, _depth, _format, _imageSize, _data); }
	#define glCompressedTexSubImage3D glad_wrapped_glCompressedTexSubImage3D
struct glad_tag_glDetachShader {};
inline void glad_wrapped_glDetachShader(GLuint _program, GLuint _shader) { GLAD_INSTRUMENT_CALL(glDetachShader, _program, _shader); }
	#define glDetachShader glad_wrapped_glDetachShader
struct glad_tag_glVertexAttribI4uiv {};
inline void glad_wrapped_glVertexAttribI4uiv(GLuint _index, const GLuint* _v) { GLAD_INSTRUMENT_CALL(glVertexAttribI4uiv, _index, _v); }
	#define glVertexAttribI4uiv glad_wrapped_glVertexAttribI4uiv
struct glad_tag_glEndQuery {};
inline void glad_wrapped_glEndQuery(GLenum _target) { GLAD_INSTRUMENT_CALL(glEndQuery, _target); }
	#define glEndQuery glad_wrapped_glEndQuery
struct glad_tag_glGetTexLevelParameteriv {};
inline void glad_wrapped_glGetTexLevelParameteriv(GLenum _target, GLint _level, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetTexLevelParameteriv, _target, _level, _pname, _params); }
	#define glGetTexLevelParameteriv glad_wrapped_glGetTexLevelParameteriv
struct glad_tag_glBindSampler {};
inline void glad_wrapped_glBindSampler(GLuint _unit, GLuint _sampler) { GLAD_INSTRUMENT_CALL(glBindSampler, _unit, _sampler); }
	#define glBindSampler glad_wrapped_glBindSampler
struct glad_tag_glLineWidth {};
inline void glad_wrapped_glLineWidth(GLfloat _width) { GLAD_INSTRUMENT_CALL(glLineWidth, _width); }
	#define glLineWidth glad_wrapped_glLineWidth
struct glad_tag_glUniform2fv {};
inline void glad_wrapped_glUniform2fv(GLint _location, GLsizei _count, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glUniform2fv, _location, _count, _value); }
	#define glUniform2fv glad_wrapped_glUniform2fv
struct glad_tag_glGetProgramResourceName {};
inline void glad_wrapped_glGetProgramResourceName(GLuint _program, GLenum _programInterface, GLuint _index, GLsizei _bufSize, GLsizei* _length, GLchar* _name) { GLAD_INSTRUMENT_CALL(glGetProgramResourceName, _program, _programInterface, _index, _bufSize, _length, _name); }
	#define glGetProgramResourceName glad_wrapped_glGetProgramResourceName
struct glad_tag_glGetProgramResourceIndex {};
inline GLuint glad_wrapped_glGetProgramResourceIndex(GLuint _program, GLenum _programInterface, const GLchar* _name) { return GLAD_INSTRUMENT_CALL(glGetProgramResourceIndex, _program, _programInterface, _name); }
	#define glGetProgramResourceIndex glad_wrapped_glGetProgramResourceIndex
struct glad_tag_glGetIntegeri_v {};
inline void glad_wrapped_glGetIntegeri_v(GLenum _target, GLuint _index, GLint* _data) { GLAD_INSTRUMENT_CALL(glGetIntegeri_v, _target, _index, _data); }
	#define glGetIntegeri_v glad_wrapped_glGetIntegeri_v
struct glad_tag_glGetInternalformativ {};
inline void glad_wrapped_glGetInternalformativ(GLenum _target, GLenum _internalformat, GLenum _pname, GLsizei _bufSize, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetInternalformativ, _target, _internalformat, _pname, _bufSize, _params); }
	#define glGetInternalformativ glad_wrapped_glGetInternalformativ
struct glad_tag_glCompileShader {};
inline void glad_wrapped_glCompileShader(GLuint _shader) { GLAD_INSTRUMENT_CALL(glCompileShader, _shader); }
	#define glCompileShader glad_wrapped_glCompileShader
struct glad_tag_glGetTransformFeedbackVarying {};
inline void glad_wrapped_glGetTransformFeedbackVarying(GLuint _program, GLuint _index, GLsizei _bufSize, GLsizei* _length, GLsizei* _size, GLenum* _type, GLchar* _name) { GLAD_INSTRUMENT_CALL(glGetTransformFeedbackVarying, _program, _index, _bufSize, _length, _size, _type, _name); }
	#define glGetTransformFeedbackVarying glad_wrapped_glGetTransformFeedbackVarying
struct glad_tag_glDeleteTextures {};
inline void glad_wrapped_glDeleteTextures(GLsizei _n, const GLuint* _textures) { GLAD_INSTRUMENT_CALL(glDeleteTextures, _n, _textures); }
	#define glDeleteTextures glad_wrapped_glDeleteTextures
struct glad_tag_glDispatchComputeIndirect {};
inline void glad_wrapped_glDispatchComputeIndirect(GLintptr _indirect) { GLAD_INSTRUMENT_CALL(glDispatchComputeIndirect, _indirect); }
	#define glDispatchComputeIndirect glad_wrapped_glDispatchComputeIndirect
struct glad_tag_glStencilOpSeparate {};
inline void glad_wrapped_glStencilOpSeparate(GLenum _face, GLenum _sfail, GLenum _dpfail, GLenum _dppass) { GLAD_INSTRUMENT_CALL(glStencilOpSeparate, _face, _sfail, _dpfail, _dppass); }
	#define glStencilOpSeparate glad_wrapped_glStencilOpSeparate
struct glad_tag_glDrawArraysIndirect {};
inline void glad_wrapped_glDrawArraysIndirect(GLenum _mode, const void* _indirect) { GLAD_INSTRUMENT_CALL(glDrawArraysIndirect, _mode, _indirect); }
	#define glDrawArraysIndirect glad_wrapped_glDrawArraysIndirect
struct glad_tag_glStencilFuncSeparate {};
inline void glad_wrapped_glStencilFuncSeparate(GLenum _face, GLenum _func, GLint _ref, GLuint _mask) { GLAD_INSTRUMENT_CALL(glStencilFuncSeparate, _face, _func, _ref, _mask); }
	#define glStencilFuncSeparate glad_wrapped_glStencilFuncSeparate
struct glad_tag_glBindBufferRange {};
inline void glad_wrapped_glBindBufferRange(GLenum _target, GLuint _index, GLuint _buffer, GLintptr _offset, GLsizeiptr _size) { GLAD_INSTRUMENT_CALL(glBindBufferRange, _target, _index, _buffer, _offset, _size); }
	#define glBindBufferRange glad_wrapped_glBindBufferRange
struct glad_tag_glVertexAttrib4f {};
inline void glad_wrapped_glVertexAttrib4f(GLuint _index, GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _w) { GLAD_INSTRUMENT_CALL(glVertexAttrib4f, _index, _x, _y, _z, _w); }
	#define glVertexAttrib4f glad_wrapped_glVertexAttrib4f
struct glad_tag_glGenQueries {};
inline void glad_wrapped_glGenQueries(GLsizei _n, GLuint* _ids) { GLAD_INSTRUMENT_CALL(glGenQueries, _n, _ids); }
	#define glGenQueries glad_wrapped_glGenQueries
struct glad_tag_glGetBufferParameteri64v {};
inline void glad_wrapped_glGetBufferParameteri64v(GLenum _target, GLenum _pname, GLint64* _params) { GLAD_INSTRUMENT_CALL(glGetBufferParameteri64v, _target, _pname, _params); }
	#define glGetBufferParameteri64v glad_wrapped_glGetBufferParameteri64v
struct glad_tag_glDepthRangef {};
inline void glad_wrapped_glDepthRangef(GLfloat _n, GLfloat _f) { GLAD_INSTRUMENT_CALL(glDepthRangef, _n, _f); }
	#define glDepthRangef glad_wrapped_glDepthRangef
struct glad_tag_glUniform4iv {};
inline void glad_wrapped_glUniform4iv(GLint _location, GLsizei _count, const GLint* _value) { GLAD_INSTRUMENT_CALL(glUniform4iv, _location, _count, _value); }
	#define glUniform4iv glad_wrapped_glUniform4iv
struct glad_tag_glGetTexParameteriv {};
inline void glad_wrapped_glGetTexParameteriv(GLenum _target, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetTexParameteriv, _target, _pname, _params); }
	#define glGetTexParameteriv glad_wrapped_glGetTexParameteriv
struct glad_tag_glClearStencil {};
inline void glad_wrapped_glClearStencil(GLint _s) { GLAD_INSTRUMENT_CALL(glClearStencil, _s); }
	#define glClearStencil glad_wrapped_glClearStencil
struct glad_tag_glProgramUniform2fv {};
inline void glad_wrapped_glProgramUniform2fv(GLuint _program, GLint _location, GLsizei _count, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform2fv, _program, _location, _count, _value); }
	#define glProgramUniform2fv glad_wrapped_glProgramUniform2fv
struct glad_tag_glUniformMatrix2x3fv {};
inline void glad_wrapped_glUniformMatrix2x3fv(GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glUniformMatrix2x3fv, _location, _count, _transpose, _value); }
	#define glUniformMatrix2x3fv glad_wrapped_glUniformMatrix2x3fv
struct glad_tag_glGenTransformFeedbacks {};
inline void glad_wrapped_glGenTransformFeedbacks(GLsizei _n, GLuint* _ids) { GLAD_INSTRUMENT_CALL(glGenTransformFeedbacks, _n, _ids); }
	#define glGenTransformFeedbacks glad_wrapped_glGenTransformFeedbacks
struct glad_tag_glGetVertexAttribIuiv {};
inline void glad_wrapped_glGetVertexAttribIuiv(GLuint _index, GLenum _pname, GLuint* _params) { GLAD_INSTRUMENT_CALL(glGetVertexAttribIuiv, _index, _pname, _params); }
	#define glGetVertexAttribIuiv glad_wrapped_glGetVertexAttribIuiv
struct glad_tag_glUseProgramStages {};
inline void glad_wrapped_glUseProgramStages(GLuint _pipeline, GLbitfield _stages, GLuint _program) { GLAD_INSTRUMENT_CALL(glUseProgramStages, _pipeline, _stages, _program); }
	#define glUseProgramStages glad_wrapped_glUseProgramStages
struct glad_tag_glSampleCoverage {};
inline void glad_wrapped_glSampleCoverage(GLfloat _value, GLboolean _invert) { GLAD_INSTRUMENT_CALL(glSampleCoverage, _value, _invert); }
	#define glSampleCoverage glad_wrapped_glSampleCoverage
struct glad_tag_glSamplerParameteri {};
inline void glad_wrapped_glSamplerParameteri(GLuint _sampler, GLenum _pname, GLint _param) { GLAD_INSTRUMENT_CALL(glSamplerParameteri, _sampler, _pname, _param); }
	#define glSamplerParameteri glad_wrapped_glSamplerParameteri
struct glad_tag_glGenTextures {};
inline void glad_wrapped_glGenTextures(GLsizei _n, GLuint* _textures) { GLAD_INSTRUMENT_CALL(glGenTextures, _n, _textures); }
	#define glGenTextures glad_wrapped_glGenTextures
struct glad_tag_glSamplerParameterf {};
inline void glad_wrapped_glSamplerParameterf(GLuint _sampler, GLenum _pname, GLfloat _param) { GLAD_INSTRUMENT_CALL(glSamplerParameterf, _sampler, _pname, _param); }
	#define glSamplerParameterf glad_wrapped_glSamplerParameterf
struct glad_tag_glDepthFunc {};
inline void glad_wrapped_glDepthFunc(GLenum _func) { GLAD_INSTRUMENT_CALL(glDepthFunc, _func); }
	#define glDepthFunc glad_wrapped_glDepthFunc
struct glad_tag_glCompressedTexSubImage2D {};
inline void glad_wrapped_glCompressedTexSubImage2D(GLenum _target, GLint _level, GLint _xoffset, GLint _yoffset, GLsizei _width, GLsizei _height, GLenum _format, GLsizei _imageSize, const void* _data) { GLAD_INSTRUMENT_CALL(glCompressedTexSubImage2D, _target, _level, _xoffset, _yoffset, _width, _height, _format, _imageSize, _data); }
	#define glCompressedTexSubImage2D glad_wrapped_glCompressedTexSubImage2D
struct glad_tag_glIsVertexArray {};
inline GLboolean glad_wrapped_glIsVertexArray(GLuint _array) { return GLAD_INSTRUMENT_CALL(glIsVertexArray, _array); }
	#define glIsVertexArray glad_wrapped_glIsVertexArray
struct glad_tag_glUniform1f {};
inline void glad_wrapped_glUniform1f(GLint _location, GLfloat _v0) { GLAD_INSTRUMENT_CALL(glUniform1f, _location, _v0); }
	#define glUniform1f glad_wrapped_glUniform1f
struct glad_tag_glGetVertexAttribfv {};
inline void glad_wrapped_glGetVertexAttribfv(GLuint _index, GLenum _pname, GLfloat* _params) { GLAD_INSTRUMENT_CALL(glGetVertexAttribfv, _index, _pname, _params); }
	#define glGetVertexAttribfv glad_wrapped_glGetVertexAttribfv
struct glad_tag_glProgramBinary {};
inline void glad_wrapped_glProgramBinary(GLuint _program, GLenum _binaryFormat, const void* _binary, GLsizei _length) { GLAD_INSTRUMENT_CALL(glProgramBinary, _program, _binaryFormat, _binary, _length); }
	#define glProgramBinary glad_wrapped_glProgramBinary
struct glad_tag_glGetTexParameterfv {};
inline void glad_wrapped_glGetTexParameterfv(GLenum _target, GLenum _pname, GLfloat* _params) { GLAD_INSTRUMENT_CALL(glGetTexParameterfv, _target, _pname, _params); }
	#define glGetTexParameterfv glad_wrapped_glGetTexParameterfv
struct glad_tag_glProgramUniformMatrix3x2fv {};
inline void glad_wrapped_glProgramUniformMatrix3x2fv(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix3x2fv, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix3x2fv glad_wrapped_glProgramUniformMatrix3x2fv
struct glad_tag_glGetFramebufferParameteriv {};
inline void glad_wrapped_glGetFramebufferParameteriv(GLenum _target, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetFramebufferParameteriv, _target, _pname, _params); }
	#define glGetFramebufferParameteriv glad_wrapped_glGetFramebufferParameteriv
struct glad_tag_glCreateShader {};
inline GLuint glad_wrapped_glCreateShader(GLenum _type) { return GLAD_INSTRUMENT_CALL(glCreateShader, _type); }
	#define glCreateShader glad_wrapped_glCreateShader
struct glad_tag_glIsBuffer {};
inline GLboolean glad_wrapped_glIsBuffer(GLuint _buffer) { return GLAD_INSTRUMENT_CALL(glIsBuffer, _buffer); }
	#define glIsBuffer glad_wrapped_glIsBuffer
struct glad_tag_glUniform1i {};
inline void glad_wrapped_glUniform1i(GLint _location, GLint _v0) { GLAD_INSTRUMENT_CALL(glUniform1i, _location, _v0); }
	#define glUniform1i glad_wrapped_glUniform1i
struct glad_tag_glGenRenderbuffers {};
inline void glad_wrapped_glGenRenderbuffers(GLsizei _n, GLuint* _renderbuffers) { GLAD_INSTRUMENT_CALL(glGenRenderbuffers, _n, _renderbuffers); }
	#define glGenRenderbuffers glad_wrapped_glGenRenderbuffers
struct glad_tag_glCopyTexSubImage2D {};
inline void glad_wrapped_glCopyTexSubImage2D(GLenum _target, GLint _level, GLint _xoffset, GLint _yoffset, GLint _x, GLint _y, GLsizei _width, GLsizei _height) { GLAD_INSTRUMENT_CALL(glCopyTexSubImage2D, _target, _level, _xoffset, _yoffset, _x, _y, _width, _height); }
	#define glCopyTexSubImage2D glad_wrapped_glCopyTexSubImage2D
struct glad_tag_glCompressedTexImage2D {};
inline void glad_wrapped_glCompressedTexImage2D(GLenum _target, GLint _level, GLenum _internalformat, GLsizei _width, GLsizei _height, GLint _border, GLsizei _imageSize, const void* _data) { GLAD_INSTRUMENT_CALL(glCompressedTexImage2D, _target, _level, _internalformat, _width, _height, _border, _imageSize, _data); }
	#define glCompressedTexImage2D glad_wrapped_glCompressedTexImage2D
struct glad_tag_glDisable {};
inline void glad_wrapped_glDisable(GLenum _cap) { GLAD_INSTRUMENT_CALL(glDisable, _cap); }
	#define glDisable glad_wrapped_glDisable
struct glad_tag_glUniform2i {};
inline void glad_wrapped_glUniform2i(GLint _location, GLint _v0, GLint _v1) { GLAD_INSTRUMENT_CALL(glUniform2i, _location, _v0, _v1); }
	#define glUniform2i glad_wrapped_glUniform2i
struct glad_tag_glBlendFuncSeparate {};
inline void glad_wrapped_glBlendFuncSeparate(GLenum _sfactorRGB, GLenum _dfactorRGB, GLenum _sfactorAlpha, GLenum _dfactorAlpha) { GLAD_INSTRUMENT_CALL(glBlendFuncSeparate, _sfactorRGB, _dfactorRGB, _sfactorAlpha, _dfactorAlpha); }
	#define glBlendFuncSeparate glad_wrapped_glBlendFuncSeparate
struct glad_tag_glProgramUniformMatrix3x4fv {};
inline void glad_wrapped_glProgramUniformMatrix3x4fv(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix3x4fv, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix3x4fv glad_wrapped_glProgramUniformMatrix3x4fv
struct glad_tag_glGetProgramiv {};
inline void glad_wrapped_glGetProgramiv(GLuint _program, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetProgramiv, _program, _pname, _params); }
	#define glGetProgramiv glad_wrapped_glGetProgramiv
struct glad_tag_glColorMask {};
inline void glad_wrapped_glColorMask(GLboolean _red, GLboolean _green, GLboolean _blue, GLboolean _alpha) { GLAD_INSTRUMENT_CALL(glColorMask, _red, _green, _blue, _alpha); }
	#define glColorMask glad_wrapped_glColorMask
struct glad_tag_glProgramUniform1ui {};
inline void glad_wrapped_glProgramUniform1ui(GLuint _program, GLint _location, GLuint _v0) { GLAD_INSTRUMENT_CALL(glProgramUniform1ui, _program, _location, _v0); }
	#define glProgramUniform1ui glad_wrapped_glProgramUniform1ui
struct glad_tag_glHint {};
inline void glad_wrapped_glHint(GLenum _target, GLenum _mode) { GLAD_INSTRUMENT_CALL(glHint, _target, _mode); }
	#define glHint glad_wrapped_glHint
struct glad_tag_glFramebufferTextureLayer {};
inline void glad_wrapped_glFramebufferTextureLayer(GLenum _target, GLenum _attachment, GLuint _texture, GLint _level, GLint _layer) { GLAD_INSTRUMENT_CALL(glFramebufferTextureLayer, _target, _attachment, _texture, _level, _layer); }
	#define glFramebufferTextureLayer glad_wrapped_glFramebufferTextureLayer
struct glad_tag_glProgramUniform4fv {};
inline void glad_wrapped_glProgramUniform4fv(GLuint _program, GLint _location, GLsizei _count, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform4fv, _program, _location, _count, _value); }
	#define glProgramUniform4fv glad_wrapped_glProgramUniform4fv
struct glad_tag_glBlendEquation {};
inline void glad_wrapped_glBlendEquation(GLenum _mode) { GLAD_INSTRUMENT_CALL(glBlendEquation, _mode); }
	#define glBlendEquation glad_wrapped_glBlendEquation
struct glad_tag_glGetUniformLocation {};
inline GLint glad_wrapped_glGetUniformLocation(GLuint _program, const GLchar* _name) { return GLAD_INSTRUMENT_CALL(glGetUniformLocation, _program, _name); }
	#define glGetUniformLocation glad_wrapped_glGetUniformLocation
struct glad_tag_glSampleMaski {};
inline void glad_wrapped_glSampleMaski(GLuint _maskNumber, GLbitfield _mask) { GLAD_INSTRUMENT_CALL(glSampleMaski, _maskNumber, _mask); }
	#define glSampleMaski glad_wrapped_glSampleMaski
struct glad_tag_glBindFramebuffer {};
inline void glad_wrapped_glBindFramebuffer(GLenum _target, GLuint _framebuffer) { GLAD_INSTRUMENT_CALL(glBindFramebuffer, _target, _framebuffer); }
	#define glBindFramebuffer glad_wrapped_glBindFramebuffer
struct glad_tag_glEndTransformFeedback {};
inline void glad_wrapped_glEndTransformFeedback() { GLAD_INSTRUMENT_CALL(glEndTransformFeedback); }
	#define glEndTransformFeedback glad_wrapped_glEndTransformFeedback
struct glad_tag_glCullFace {};
inline void glad_wrapped_glCullFace(GLenum _mode) { GLAD_INSTRUMENT_CALL(glCullFace, _mode); }
	#define glCullFace glad_wrapped_glCullFace
struct glad_tag_glUniformMatrix3x2fv {};
inline void glad_wrapped_glUniformMatrix3x2fv(GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glUniformMatrix3x2fv, _location, _count, _transpose, _value); }
	#define glUniformMatrix3x2fv glad_wrapped_glUniformMatrix3x2fv
struct glad_tag_glPauseTransformFeedback {};
inline void glad_wrapped_glPauseTransformFeedback() { GLAD_INSTRUMENT_CALL(glPauseTransformFeedback); }
	#define glPauseTransformFeedback glad_wrapped_glPauseTransformFeedback
struct glad_tag_glTexStorage2D {};
inline void glad_wrapped_glTexStorage2D(GLenum _target, GLsizei _levels, GLenum _internalformat, GLsizei _width, GLsizei _height) { GLAD_INSTRUMENT_CALL(glTexStorage2D, _target, _levels, _internalformat, _width, _height); }
	#define glTexStorage2D glad_wrapped_glTexStorage2D
struct glad_tag_glUniform4fv {};
inline void glad_wrapped_glUniform4fv(GLint _location, GLsizei _count, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glUniform4fv, _location, _count, _value); }
	#define glUniform4fv glad_wrapped_glUniform4fv
struct glad_tag_glProgramUniform4i {};
inline void glad_wrapped_glProgramUniform4i(GLuint _program, GLint _location, GLint _v0, GLint _v1, GLint _v2, GLint _v3) { GLAD_INSTRUMENT_CALL(glProgramUniform4i, _program, _location, _v0, _v1, _v2, _v3); }
	#define glProgramUniform4i glad_wrapped_glProgramUniform4i
struct glad_tag_glIsProgramPipeline {};
inline GLboolean glad_wrapped_glIsProgramPipeline(GLuint _pipeline) { return GLAD_INSTRUMENT_CALL(glIsProgramPipeline, _pipeline); }
	#define glIsProgramPipeline glad_wrapped_glIsProgramPipeline
struct glad_tag_glProgramUniform4f {};
inline void glad_wrapped_glProgramUniform4f(GLuint _program, GLint _location, GLfloat _v0, GLfloat _v1, GLfloat _v2, GLfloat _v3) { GLAD_INSTRUMENT_CALL(glProgramUniform4f, _program, _location, _v0, _v1, _v2, _v3); }
	#define glProgramUniform4f glad_wrapped_glProgramUniform4f
struct glad_tag_glGetProgramResourceiv {};
inline void glad_wrapped_glGetProgramResourceiv(GLuint _program, GLenum _programInterface, GLuint _index, GLsizei _propCount, const GLenum* _props, GLsizei _bufSize, GLsizei* _length, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetProgramResourceiv, _program, _programInterface, _index, _propCount, _props, _bufSize, _length, _params); }
	#define glGetProgramResourceiv glad_wrapped_glGetProgramResourceiv
struct glad_tag_glBeginTransformFeedback {};
inline void glad_wrapped_glBeginTransformFeedback(GLenum _primitiveMode) { GLAD_INSTRUMENT_CALL(glBeginTransformFeedback, _primitiveMode); }
	#define glBeginTransformFeedback glad_wrapped_glBeginTransformFeedback
struct glad_tag_glGetProgramPipelineInfoLog {};
inline void glad_wrapped_glGetProgramPipelineInfoLog(GLuint _pipeline, GLsizei _bufSize, GLsizei* _length, GLchar* _infoLog) { GLAD_INSTRUMENT_CALL(glGetProgramPipelineInfoLog, _pipeline, _bufSize, _length, _infoLog); }
	#define glGetProgramPipelineInfoLog glad_wrapped_glGetProgramPipelineInfoLog
struct glad_tag_glDeleteProgram {};
inline void glad_wrapped_glDeleteProgram(GLuint _program) { GLAD_INSTRUMENT_CALL(glDeleteProgram, _program); }
	#define glDeleteProgram glad_wrapped_glDeleteProgram
struct glad_tag_glIsSampler {};
inline GLboolean glad_wrapped_glIsSampler(GLuint _sampler) { return GLAD_INSTRUMENT_CALL(glIsSampler, _sampler); }
	#define glIsSampler glad_wrapped_glIsSampler
struct glad_tag_glVertexAttribDivisor {};
inline void glad_wrapped_glVertexAttribDivisor(GLuint _index, GLuint _divisor) { GLAD_INSTRUMENT_CALL(glVertexAttribDivisor, _index, _divisor); }
	#define glVertexAttribDivisor glad_wrapped_glVertexAttribDivisor
struct glad_tag_glRenderbufferStorage {};
inline void glad_wrapped_glRenderbufferStorage(GLenum _target, GLenum _internalformat, GLsizei _width, GLsizei _height) { GLAD_INSTRUMENT_CALL(glRenderbufferStorage, _target, _internalformat, _width, _height); }
	#define glRenderbufferStorage glad_wrapped_glRenderbufferStorage
struct glad_tag_glWaitSync {};
inline void glad_wrapped_glWaitSync(GLsync _sync, GLbitfield _flags, GLuint64 _timeout) { GLAD_INSTRUMENT_CALL(glWaitSync, _sync, _flags, _timeout); }
	#define glWaitSync glad_wrapped_glWaitSync
struct glad_tag_glAttachShader {};
inline void glad_wrapped_glAttachShader(GLuint _program, GLuint _shader) { GLAD_INSTRUMENT_CALL(glAttachShader, _program, _shader); }
	#define glAttachShader glad_wrapped_glAttachShader
struct glad_tag_glUniformMatrix4x3fv {};
inline void glad_wrapped_glUniformMatrix4x3fv(GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glUniformMatrix4x3fv, _location, _count, _transpose, _value); }
	#define glUniformMatrix4x3fv glad_wrapped_glUniformMatrix4x3fv
struct glad_tag_glUniform3i {};
inline void glad_wrapped_glUniform3i(GLint _location, GLint _v0, GLint _v1, GLint _v2) { GLAD_INSTRUMENT_CALL(glUniform3i, _location, _v0, _v1, _v2); }
	#define glUniform3i glad_wrapped_glUniform3i
struct glad_tag_glClearBufferfv {};
inline void glad_wrapped_glClearBufferfv(GLenum _buffer, GLint _drawbuffer, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glClearBufferfv, _buffer, _drawbuffer, _value); }
	#define glClearBufferfv glad_wrapped_glClearBufferfv
struct glad_tag_glDeleteTransformFeedbacks {};
inline void glad_wrapped_glDeleteTransformFeedbacks(GLsizei _n, const GLuint* _ids) { GLAD_INSTRUMENT_CALL(glDeleteTransformFeedbacks, _n, _ids); }
	#define glDeleteTransformFeedbacks glad_wrapped_glDeleteTransformFeedbacks
struct glad_tag_glDeleteSamplers {};
inline void glad_wrapped_glDeleteSamplers(GLsizei _count, const GLuint* _samplers) { GLAD_INSTRUMENT_CALL(glDeleteSamplers, _count, _samplers); }
	#define glDeleteSamplers glad_wrapped_glDeleteSamplers
struct glad_tag_glCheckFramebufferStatus {};
inline GLenum glad_wrapped_glCheckFramebufferStatus(GLenum _target) { return GLAD_INSTRUMENT_CALL(glCheckFramebufferStatus, _target); }
	#define glCheckFramebufferStatus glad_wrapped_glCheckFramebufferStatus
struct glad_tag_glTexSubImage3D {};
inline void glad_wrapped_glTexSubImage3D(GLenum _target, GLint _level, GLint _xoffset, GLint _yoffset, GLint _zoffset, GLsizei _width, GLsizei _height, GLsizei _depth, GLenum _format, GLenum _type, const void* _pixels) { GLAD_INSTRUMENT_CALL(glTexSubImage3D, _target, _level, _xoffset, _yoffset, _zoffset, _width, _height, _depth, _format, _type, _pixels); }
	#define glTexSubImage3D glad_wrapped_glTexSubImage3D
struct glad_tag_glGetInteger64i_v {};
inline void glad_wrapped_glGetInteger64i_v(GLenum _target, GLuint _index, GLint64* _data) { GLAD_INSTRUMENT_CALL(glGetInteger64i_v, _target, _index, _data); }
	#define glGetInteger64i_v glad_wrapped_glGetInteger64i_v
struct glad_tag_glShaderBinary {};
inline void glad_wrapped_glShaderBinary(GLsizei _count, const GLuint* _shaders, GLenum _binaryformat, const void* _binary, GLsizei _length) { GLAD_INSTRUMENT_CALL(glShaderBinary, _count, _shaders, _binaryformat, _binary, _length); }
	#define glShaderBinary glad_wrapped_glShaderBinary
struct glad_tag_glCopyTexImage2D {};
inline void glad_wrapped_glCopyTexImage2D(GLenum _target, GLint _level, GLenum _internalformat, GLint _x, GLint _y, GLsizei _width, GLsizei _height, GLint _border) { GLAD_INSTRUMENT_CALL(glCopyTexImage2D, _target, _level, _internalformat, _x, _y, _width, _height, _border); }
	#define glCopyTexImage2D glad_wrapped_glCopyTexImage2D
struct glad_tag_glUniform3f {};
inline void glad_wrapped_glUniform3f(GLint _location, GLfloat _v0, GLfloat _v1, GLfloat _v2) { GLAD_INSTRUMENT_CALL(glUniform3f, _location, _v0, _v1, _v2); }
	#define glUniform3f glad_wrapped_glUniform3f
struct glad_tag_glBlitFramebuffer {};
inline void glad_wrapped_glBlitFramebuffer(GLint _srcX0, GLint _srcY0, GLint _srcX1, GLint _srcY1, GLint _dstX0, GLint _dstY0, GLint _dstX1, GLint _dstY1, GLbitfield _mask, GLenum _filter) { GLAD_INSTRUMENT_CALL(glBlitFramebuffer, _srcX0, _srcY0, _srcX1, _srcY1, _dstX0, _dstY0, _dstX1, _dstY1, _mask, _filter); }
	#define glBlitFramebuffer glad_wrapped_glBlitFramebuffer
struct glad_tag_glBindAttribLocation {};
inline void glad_wrapped_glBindAttribLocation(GLuint _program, GLuint _index, const GLchar* _name) { GLAD_INSTRUMENT_CALL(glBindAttribLocation, _program, _index, _name); }
	#define glBindAttribLocation glad_wrapped_glBindAttribLocation
struct glad_tag_glUniformMatrix4x2fv {};
inline void glad_wrapped_glUniformMatrix4x2fv(GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glUniformMatrix4x2fv, _location, _count, _transpose, _value); }
	#define glUniformMatrix4x2fv glad_wrapped_glUniformMatrix4x2fv
struct glad_tag_glDrawElements {};
inline void glad_wrapped_glDrawElements(GLenum _mode, GLsizei _count, GLenum _type, const void* _indices) { GLAD_INSTRUMENT_CALL(glDrawElements, _mode, _count, _type, _indices); }
	#define glDrawElements glad_wrapped_glDrawElements
struct glad_tag_glProgramUniform4iv {};
inline void glad_wrapped_glProgramUniform4iv(GLuint _program, GLint _location, GLsizei _count, const GLint* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform4iv, _program, _location, _count, _value); }
	#define glProgramUniform4iv glad_wrapped_glProgramUniform4iv
struct glad_tag_glTexStorage2DMultisample {};
inline void glad_wrapped_glTexStorage2DMultisample(GLenum _target, GLsizei _samples, GLenum _internalformat, GLsizei _width, GLsizei _height, GLboolean _fixedsamplelocations) { GLAD_INSTRUMENT_CALL(glTexStorage2DMultisample, _target, _samples, _internalformat, _width, _height, _fixedsamplelocations); }
	#define glTexStorage2DMultisample glad_wrapped_glTexStorage2DMultisample
struct glad_tag_glProgramUniform3ui {};
inline void glad_wrapped_glProgramUniform3ui(GLuint _program, GLint _location, GLuint _v0, GLuint _v1, GLuint _v2) { GLAD_INSTRUMENT_CALL(glProgramUniform3ui, _program, _location, _v0, _v1, _v2); }
	#define glProgramUniform3ui glad_wrapped_glProgramUniform3ui
struct glad_tag_glProgramUniform2uiv {};
inline void glad_wrapped_glProgramUniform2uiv(GLuint _program, GLint _location, GLsizei _count, const GLuint* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform2uiv, _program, _location, _count, _value); }
	#define glProgramUniform2uiv glad_wrapped_glProgramUniform2uiv
struct glad_tag_glProgramUniform3i {};
inline void glad_wrapped_glProgramUniform3i(GLuint _program, GLint _location, GLint _v0, GLint _v1, GLint _v2) { GLAD_INSTRUMENT_CALL(glProgramUniform3i, _program, _location, _v0, _v1, _v2); }
	#define glProgramUniform3i glad_wrapped_glProgramUniform3i
struct glad_tag_glUniform2iv {};
inline void glad_wrapped_glUniform2iv(GLint _location, GLsizei _count, const GLint* _value) { GLAD_INSTRUMENT_CALL(glUniform2iv, _location, _count, _value); }
	#define glUniform2iv glad_wrapped_glUniform2iv
struct glad_tag_glVertexAttrib1fv {};
inline void glad_wrapped_glVertexAttrib1fv(GLuint _index, const GLfloat* _v) { GLAD_INSTRUMENT_CALL(glVertexAttrib1fv, _index, _v); }
	#define glVertexAttrib1fv glad_wrapped_glVertexAttrib1fv
struct glad_tag_glGenVertexArrays {};
inline void glad_wrapped_glGenVertexArrays(GLsizei _n, GLuint* _arrays) { GLAD_INSTRUMENT_CALL(glGenVertexArrays, _n, _arrays); }
	#define glGenVertexArrays glad_wrapped_glGenVertexArrays
struct glad_tag_glBindBufferBase {};
inline void glad_wrapped_glBindBufferBase(GLenum _target, GLuint _index, GLuint _buffer) { GLAD_INSTRUMENT_CALL(glBindBufferBase, _target, _index, _buffer); }
	#define glBindBufferBase glad_wrapped_glBindBufferBase
struct glad_tag_glBufferSubData {};
inline void glad_wrapped_glBufferSubData(GLenum _target, GLintptr _offset, GLsizeiptr _size, const void* _data) { GLAD_INSTRUMENT_CALL(glBufferSubData, _target, _offset, _size, _data); }
	#define glBufferSubData glad_wrapped_glBufferSubData
struct glad_tag_glUniform1iv {};
inline void glad_wrapped_glUniform1iv(GLint _location, GLsizei _count, const GLint* _value) { GLAD_INSTRUMENT_CALL(glUniform1iv, _location, _count, _value); }
	#define glUniform1iv glad_wrapped_glUniform1iv
struct glad_tag_glCreateShaderProgramv {};
inline GLuint glad_wrapped_glCreateShaderProgramv(GLenum _type, GLsizei _count, const GLchar** _strings) { return GLAD_INSTRUMENT_CALL(glCreateShaderProgramv, _type, _count, _strings); }
	#define glCreateShaderProgramv glad_wrapped_glCreateShaderProgramv
struct glad_tag_glGetBufferParameteriv {};
inline void glad_wrapped_glGetBufferParameteriv(GLenum _target, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetBufferParameteriv, _target, _pname, _params); }
	#define glGetBufferParameteriv glad_wrapped_glGetBufferParameteriv
struct glad_tag_glProgramUniform4uiv {};
inline void glad_wrapped_glProgramUniform4uiv(GLuint _program, GLint _location, GLsizei _count, const GLuint* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform4uiv, _program, _location, _count, _value); }
	#define glProgramUniform4uiv glad_wrapped_glProgramUniform4uiv
struct glad_tag_glProgramUniform1uiv {};
inline void glad_wrapped_glProgramUniform1uiv(GLuint _program, GLint _location, GLsizei _count, const GLuint* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform1uiv, _program, _location, _count, _value); }
	#define glProgramUniform1uiv glad_wrapped_glProgramUniform1uiv
struct glad_tag_glMapBufferRange {};
inline void* glad_wrapped_glMapBufferRange(GLenum _target, GLintptr _offset, GLsizeiptr _length, GLbitfield _access) { return GLAD_INSTRUMENT_CALL(glMapBufferRange, _target, _offset, _length, _access); }
	#define glMapBufferRange glad_wrapped_glMapBufferRange
struct glad_tag_glReadBuffer {};
inline void glad_wrapped_glReadBuffer(GLenum _src) { GLAD_INSTRUMENT_CALL(glReadBuffer, _src); }
	#define glReadBuffer glad_wrapped_glReadBuffer
struct glad_tag_glTexStorage3D {};
inline void glad_wrapped_glTexStorage3D(GLenum _target, GLsizei _levels, GLenum _internalformat, GLsizei _width, GLsizei _height, GLsizei _depth) { GLAD_INSTRUMENT_CALL(glTexStorage3D, _target, _levels, _internalformat, _width, _height, _depth); }
	#define glTexStorage3D glad_wrapped_glTexStorage3D
struct glad_tag_glBindImageTexture {};
inline void glad_wrapped_glBindImageTexture(GLuint _unit, GLuint _texture, GLint _level, GLboolean _layered, GLint _layer, GLenum _access, GLenum _format) { GLAD_INSTRUMENT_CALL(glBindImageTexture, _unit, _texture, _level, _layered, _layer, _access, _format); }
	#define glBindImageTexture glad_wrapped_glBindImageTexture
struct glad_tag_glClientWaitSync {};
inline GLenum glad_wrapped_glClientWaitSync(GLsync _sync, GLbitfield _flags, GLuint64 _timeout) { return GLAD_INSTRUMENT_CALL(glClientWaitSync, _sync, _flags, _timeout); }
	#define glClientWaitSync glad_wrapped_glClientWaitSync
struct glad_tag_glProgramUniformMatrix4x2fv {};
inline void glad_wrapped_glProgramUniformMatrix4x2fv(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix4x2fv, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix4x2fv glad_wrapped_glProgramUniformMatrix4x2fv
struct glad_tag_glDrawArraysInstanced {};
inline void glad_wrapped_glDrawArraysInstanced(GLenum _mode, GLint _first, GLsizei _count, GLsizei _instancecount) { GLAD_INSTRUMENT_CALL(glDrawArraysInstanced, _mode, _first, _count, _instancecount); }
	#define glDrawArraysInstanced glad_wrapped_glDrawArraysInstanced
struct glad_tag_glDeleteProgramPipelines {};
inline void glad_wrapped_glDeleteProgramPipelines(GLsizei _n, const GLuint* _pipelines) { GLAD_INSTRUMENT_CALL(glDeleteProgramPipelines, _n, _pipelines); }
	#define glDeleteProgramPipelines glad_wrapped_glDeleteProgramPipelines
struct glad_tag_glGenerateMipmap {};
inline void glad_wrapped_glGenerateMipmap(GLenum _target) { GLAD_INSTRUMENT_CALL(glGenerateMipmap, _target); }
	#define glGenerateMipmap glad_wrapped_glGenerateMipmap
struct glad_tag_glGetMultisamplefv {};
inline void glad_wrapped_glGetMultisamplefv(GLenum _pname, GLuint _index, GLfloat* _val) { GLAD_INSTRUMENT_CALL(glGetMultisamplefv, _pname, _index, _val); }
	#define glGetMultisamplefv glad_wrapped_glGetMultisamplefv
struct glad_tag_glGetShaderiv {};
inline void glad_wrapped_glGetShaderiv(GLuint _shader, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetShaderiv, _shader, _pname, _params); }
	#define glGetShaderiv glad_wrapped_glGetShaderiv
struct glad_tag_glProgramUniformMatrix2fv {};
inline void glad_wrapped_glProgramUniformMatrix2fv(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix2fv, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix2fv glad_wrapped_glProgramUniformMatrix2fv
struct glad_tag_glActiveShaderProgram {};
inline void glad_wrapped_glActiveShaderProgram(GLuint _pipeline, GLuint _program) { GLAD_INSTRUMENT_CALL(glActiveShaderProgram, _pipeline, _program); }
	#define glActiveShaderProgram glad_wrapped_glActiveShaderProgram
struct glad_tag_glProgramUniformMatrix3fv {};
inline void glad_wrapped_glProgramUniformMatrix3fv(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix3fv, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix3fv glad_wrapped_glProgramUniformMatrix3fv
struct glad_tag_glUniformMatrix3x4fv {};
inline void glad_wrapped_glUniformMatrix3x4fv(GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glUniformMatrix3x4fv, _location, _count, _transpose, _value); }
	#define glUniformMatrix3x4fv glad_wrapped_glUniformMatrix3x4fv
struct glad_tag_glVertexAttrib3f {};
inline void glad_wrapped_glVertexAttrib3f(GLuint _index, GLfloat _x, GLfloat _y, GLfloat _z) { GLAD_INSTRUMENT_CALL(glVertexAttrib3f, _index, _x, _y, _z); }
	#define glVertexAttrib3f glad_wrapped_glVertexAttrib3f
struct glad_tag_glGetActiveAttrib {};
inline void glad_wrapped_glGetActiveAttrib(GLuint _program, GLuint _index, GLsizei _bufSize, GLsizei* _length, GLint* _size, GLenum* _type, GLchar* _name) { GLAD_INSTRUMENT_CALL(glGetActiveAttrib, _program, _index, _bufSize, _length, _size, _type, _name); }
	#define glGetActiveAttrib glad_wrapped_glGetActiveAttrib
struct glad_tag_glBlendColor {};
inline void glad_wrapped_glBlendColor(GLfloat _red, GLfloat _green, GLfloat _blue, GLfloat _alpha) { GLAD_INSTRUMENT_CALL(glBlendColor, _red, _green, _blue, _alpha); }
	#define glBlendColor glad_wrapped_glBlendColor
struct glad_tag_glGetShaderPrecisionFormat {};
inline void glad_wrapped_glGetShaderPrecisionFormat(GLenum _shadertype, GLenum _precisiontype, GLint* _range, GLint* _precision) { GLAD_INSTRUMENT_CALL(glGetShaderPrecisionFormat, _shadertype, _precisiontype, _range, _precision); }
	#define glGetShaderPrecisionFormat glad_wrapped_glGetShaderPrecisionFormat
struct glad_tag_glResumeTransformFeedback {};
inline void glad_wrapped_glResumeTransformFeedback() { GLAD_INSTRUMENT_CALL(glResumeTransformFeedback); }
	#define glResumeTransformFeedback glad_wrapped_glResumeTransformFeedback
struct glad_tag_glUnmapBuffer {};
inline GLboolean glad_wrapped_glUnmapBuffer(GLenum _target) { return GLAD_INSTRUMENT_CALL(glUnmapBuffer, _target); }
	#define glUnmapBuffer glad_wrapped_glUnmapBuffer
struct glad_tag_glDepthMask {};
inline void glad_wrapped_glDepthMask(GLboolean _flag) { GLAD_INSTRUMENT_CALL(glDepthMask, _flag); }
	#define glDepthMask glad_wrapped_glDepthMask
struct glad_tag_glUseProgram {};
inline void glad_wrapped_glUseProgram(GLuint _program) { GLAD_INSTRUMENT_CALL(glUseProgram, _program); }
	#define glUseProgram glad_wrapped_glUseProgram
struct glad_tag_glProgramUniformMatrix2x4fv {};
inline void glad_wrapped_glProgramUniformMatrix2x4fv(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix2x4fv, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix2x4fv glad_wrapped_glProgramUniformMatrix2x4fv
struct glad_tag_glProgramUniform1iv {};
inline void glad_wrapped_glProgramUniform1iv(GLuint _program, GLint _location, GLsizei _count, const GLint* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform1iv, _program, _location, _count, _value); }
	#define glProgramUniform1iv glad_wrapped_glProgramUniform1iv
struct glad_tag_glCopyBufferSubData {};
inline void glad_wrapped_glCopyBufferSubData(GLenum _readTarget, GLenum _writeTarget, GLintptr _readOffset, GLintptr _writeOffset, GLsizeiptr _size) { GLAD_INSTRUMENT_CALL(glCopyBufferSubData, _readTarget, _writeTarget, _readOffset, _writeOffset, _size); }
	#define glCopyBufferSubData glad_wrapped_glCopyBufferSubData
struct glad_tag_glProgramUniform2iv {};
inline void glad_wrapped_glProgramUniform2iv(GLuint _program, GLint _location, GLsizei _count, const GLint* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform2iv, _program, _location, _count, _value); }
	#define glProgramUniform2iv glad_wrapped_glProgramUniform2iv
struct glad_tag_glValidateProgramPipeline {};
inline void glad_wrapped_glValidateProgramPipeline(GLuint _pipeline) { GLAD_INSTRUMENT_CALL(glValidateProgramPipeline, _pipeline); }
	#define glValidateProgramPipeline glad_wrapped_glValidateProgramPipeline
struct glad_tag_glShaderSource {};
inline void glad_wrapped_glShaderSource(GLuint _shader, GLsizei _count, const GLchar** _string, const GLint* _length) { GLAD_INSTRUMENT_CALL(glShaderSource, _shader, _count, _string, _length); }
	#define glShaderSource glad_wrapped_glShaderSource
struct glad_tag_glBindRenderbuffer {};
inline void glad_wrapped_glBindRenderbuffer(GLenum _target, GLuint _renderbuffer) { GLAD_INSTRUMENT_CALL(glBindRenderbuffer, _target, _renderbuffer); }
	#define glBindRenderbuffer glad_wrapped_glBindRenderbuffer
struct glad_tag_glDeleteRenderbuffers {};
inline void glad_wrapped_glDeleteRenderbuffers(GLsizei _n, const GLuint* _renderbuffers) { GLAD_INSTRUMENT_CALL(glDeleteRenderbuffers, _n, _renderbuffers); }
	#define glDeleteRenderbuffers glad_wrapped_glDeleteRenderbuffers
struct glad_tag_glIsSync {};
inline GLboolean glad_wrapped_glIsSync(GLsync _sync) { return GLAD_INSTRUMENT_CALL(glIsSync, _sync); }
	#define glIsSync glad_wrapped_glIsSync
struct glad_tag_glIsTransformFeedback {};
inline GLboolean glad_wrapped_glIsTransformFeedback(GLuint _id) { return GLAD_INSTRUMENT_CALL(glIsTransformFeedback, _id); }
	#define glIsTransformFeedback glad_wrapped_glIsTransformFeedback
struct glad_tag_glDeleteFramebuffers {};
inline void glad_wrapped_glDeleteFramebuffers(GLsizei _n, const GLuint* _framebuffers) { GLAD_INSTRUMENT_CALL(glDeleteFramebuffers, _n, _framebuffers); }
	#define glDeleteFramebuffers glad_wrapped_glDeleteFramebuffers
struct glad_tag_glDrawArrays {};
inline void glad_wrapped_glDrawArrays(GLenum _mode, GLint _first, GLsizei _count) { GLAD_INSTRUMENT_CALL(glDrawArrays, _mode, _first, _count); }
	#define glDrawArrays glad_wrapped_glDrawArrays
struct glad_tag_glUniform1ui {};
inline void glad_wrapped_glUniform1ui(GLint _location, GLuint _v0) { GLAD_INSTRUMENT_CALL(glUniform1ui, _location, _v0); }
	#define glUniform1ui glad_wrapped_glUniform1ui
struct glad_tag_glIsProgram {};
inline GLboolean glad_wrapped_glIsProgram(GLuint _program) { return GLAD_INSTRUMENT_CALL(glIsProgram, _program); }
	#define glIsProgram glad_wrapped_glIsProgram
struct glad_tag_glFramebufferParameteri {};
inline void glad_wrapped_glFramebufferParameteri(GLenum _target, GLenum _pname, GLint _param) { GLAD_INSTRUMENT_CALL(glFramebufferParameteri, _target, _pname, _param); }
	#define glFramebufferParameteri glad_wrapped_glFramebufferParameteri
struct glad_tag_glTexSubImage2D {};
inline void glad_wrapped_glTexSubImage2D(GLenum _target, GLint _level, GLint _xoffset, GLint _yoffset, GLsizei _width, GLsizei _height, GLenum _format, GLenum _type, const void* _pixels) { GLAD_INSTRUMENT_CALL(glTexSubImage2D, _target, _level, _xoffset, _yoffset, _width, _height, _format, _type, _pixels); }
	#define glTexSubImage2D glad_wrapped_glTexSubImage2D
struct glad_tag_glGetSynciv {};
inline void glad_wrapped_glGetSynciv(GLsync _sync, GLenum _pname, GLsizei _bufSize, GLsizei* _length, GLint* _values) { GLAD_INSTRUMENT_CALL(glGetSynciv, _sync, _pname, _bufSize, _length, _values); }
	#define glGetSynciv glad_wrapped_glGetSynciv
struct glad_tag_glGetUniformiv {};
inline void glad_wrapped_glGetUniformiv(GLuint _program, GLint _location, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetUniformiv, _program, _location, _params); }
	#define glGetUniformiv glad_wrapped_glGetUniformiv
struct glad_tag_glUniform4i {};
inline void glad_wrapped_glUniform4i(GLint _location, GLint _v0, GLint _v1, GLint _v2, GLint _v3) { GLAD_INSTRUMENT_CALL(glUniform4i, _location, _v0, _v1, _v2, _v3); }
	#define glUniform4i glad_wrapped_glUniform4i
struct glad_tag_glVertexAttribFormat {};
inline void glad_wrapped_glVertexAttribFormat(GLuint _attribindex, GLint _size, GLenum _type, GLboolean _normalized, GLuint _relativeoffset) { GLAD_INSTRUMENT_CALL(glVertexAttribFormat, _attribindex, _size, _type, _normalized, _relativeoffset); }
	#define glVertexAttribFormat glad_wrapped_glVertexAttribFormat
struct glad_tag_glClear {};
inline void glad_wrapped_glClear(GLbitfield _mask) { GLAD_INSTRUMENT_CALL(glClear, _mask); }
	#define glClear glad_wrapped_glClear
struct glad_tag_glVertexAttrib4fv {};
inline void glad_wrapped_glVertexAttrib4fv(GLuint _index, const GLfloat* _v) { GLAD_INSTRUMENT_CALL(glVertexAttrib4fv, _index, _v); }
	#define glVertexAttrib4fv glad_wrapped_glVertexAttrib4fv
struct glad_tag_glProgramParameteri {};
inline void glad_wrapped_glProgramParameteri(GLuint _program, GLenum _pname, GLint _value) { GLAD_INSTRUMENT_CALL(glProgramParameteri, _program, _pname, _value); }
	#define glProgramParameteri glad_wrapped_glProgramParameteri
struct glad_tag_glReleaseShaderCompiler {};
inline void glad_wrapped_glReleaseShaderCompiler() { GLAD_INSTRUMENT_CALL(glReleaseShaderCompiler); }
	#define glReleaseShaderCompiler glad_wrapped_glReleaseShaderCompiler
struct glad_tag_glProgramUniform2i {};
inline void glad_wrapped_glProgramUniform2i(GLuint _program, GLint _location, GLint _v0, GLint _v1) { GLAD_INSTRUMENT_CALL(glProgramUniform2i, _program, _location, _v0, _v1); }
	#define glProgramUniform2i glad_wrapped_glProgramUniform2i
struct glad_tag_glUniform2f {};
inline void glad_wrapped_glUniform2f(GLint _location, GLfloat _v0, GLfloat _v1) { GLAD_INSTRUMENT_CALL(glUniform2f, _location, _v0, _v1); }
	#define glUniform2f glad_wrapped_glUniform2f
struct glad_tag_glMemoryBarrier {};
inline void glad_wrapped_glMemoryBarrier(GLbitfield _barriers) { GLAD_INSTRUMENT_CALL(glMemoryBarrier, _barriers); }
	#define glMemoryBarrier glad_wrapped_glMemoryBarrier
struct glad_tag_glActiveTexture {};
inline void glad_wrapped_glActiveTexture(GLenum _texture) { GLAD_INSTRUMENT_CALL(glActiveTexture, _texture); }
	#define glActiveTexture glad_wrapped_glActiveTexture
struct glad_tag_glEnableVertexAttribArray {};
inline void glad_wrapped_glEnableVertexAttribArray(GLuint _index) { GLAD_INSTRUMENT_CALL(glEnableVertexAttribArray, _index); }
	#define glEnableVertexAttribArray glad_wrapped_glEnableVertexAttribArray
struct glad_tag_glDrawRangeElements {};
inline void glad_wrapped_glDrawRangeElements(GLenum _mode, GLuint _start, GLuint _end, GLsizei _count, GLenum _type, const void* _indices) { GLAD_INSTRUMENT_CALL(glDrawRangeElements, _mode, _start, _end, _count, _type, _indices); }
	#define glDrawRangeElements glad_wrapped_glDrawRangeElements
struct glad_tag_glBindBuffer {};
inline void glad_wrapped_glBindBuffer(GLenum _target, GLuint _buffer) { GLAD_INSTRUMENT_CALL(glBindBuffer, _target, _buffer); }
	#define glBindBuffer glad_wrapped_glBindBuffer
struct glad_tag_glIsEnabled {};
inline GLboolean glad_wrapped_glIsEnabled(GLenum _cap) { return GLAD_INSTRUMENT_CALL(glIsEnabled, _cap); }
	#define glIsEnabled glad_wrapped_glIsEnabled
struct glad_tag_glStencilOp {};
inline void glad_wrapped_glStencilOp(GLenum _fail, GLenum _zfail, GLenum _zpass) { GLAD_INSTRUMENT_CALL(glStencilOp, _fail, _zfail, _zpass); }
	#define glStencilOp glad_wrapped_glStencilOp
struct glad_tag_glReadPixels {};
inline void glad_wrapped_glReadPixels(GLint _x, GLint _y, GLsizei _width, GLsizei _height, GLenum _format, GLenum _type, void* _pixels) { GLAD_INSTRUMENT_CALL(glReadPixels, _x, _y, _width, _height, _format, _type, _pixels); }
	#define glReadPixels glad_wrapped_glReadPixels
struct glad_tag_glGetQueryObjectuiv {};
inline void glad_wrapped_glGetQueryObjectuiv(GLuint _id, GLenum _pname, GLuint* _params) { GLAD_INSTRUMENT_CALL(glGetQueryObjectuiv, _id, _pname, _params); }
	#define glGetQueryObjectuiv glad_wrapped_glGetQueryObjectuiv
struct glad_tag_glGetTexLevelParameterfv {};
inline void glad_wrapped_glGetTexLevelParameterfv(GLenum _target, GLint _level, GLenum _pname, GLfloat* _params) { GLAD_INSTRUMENT_CALL(glGetTexLevelParameterfv, _target, _level, _pname, _params); }
	#define glGetTexLevelParameterfv glad_wrapped_glGetTexLevelParameterfv
struct glad_tag_glBindTransformFeedback {};
inline void glad_wrapped_glBindTransformFeedback(GLenum _target, GLuint _id) { GLAD_INSTRUMENT_CALL(glBindTransformFeedback, _target, _id); }
	#define glBindTransformFeedback glad_wrapped_glBindTransformFeedback
struct glad_tag_glUniform4f {};
inline void glad_wrapped_glUniform4f(GLint _location, GLfloat _v0, GLfloat _v1, GLfloat _v2, GLfloat _v3) { GLAD_INSTRUMENT_CALL(glUniform4f, _location, _v0, _v1, _v2, _v3); }
	#define glUniform4f glad_wrapped_glUniform4f
struct glad_tag_glFramebufferTexture2D {};
inline void glad_wrapped_glFramebufferTexture2D(GLenum _target, GLenum _attachment, GLenum _textarget, GLuint _texture, GLint _level) { GLAD_INSTRUMENT_CALL(glFramebufferTexture2D, _target, _attachment, _textarget, _texture, _level); }
	#define glFramebufferTexture2D glad_wrapped_glFramebufferTexture2D
struct glad_tag_glGetFramebufferAttachmentParameteriv {};
inline void glad_wrapped_glGetFramebufferAttachmentParameteriv(GLenum _target, GLenum _attachment, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetFramebufferAttachmentParameteriv, _target, _attachment, _pname, _params); }
	#define glGetFramebufferAttachmentParameteriv glad_wrapped_glGetFramebufferAttachmentParameteriv
struct glad_tag_glUniformMatrix2x4fv {};
inline void glad_wrapped_glUniformMatrix2x4fv(GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glUniformMatrix2x4fv, _location, _count, _transpose, _value); }
	#define glUniformMatrix2x4fv glad_wrapped_glUniformMatrix2x4fv
struct glad_tag_glUniform2uiv {};
inline void glad_wrapped_glUniform2uiv(GLint _location, GLsizei _count, const GLuint* _value) { GLAD_INSTRUMENT_CALL(glUniform2uiv, _location, _count, _value); }
	#define glUniform2uiv glad_wrapped_glUniform2uiv
struct glad_tag_glUniform3fv {};
inline void glad_wrapped_glUniform3fv(GLint _location, GLsizei _count, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glUniform3fv, _location, _count, _value); }
	#define glUniform3fv glad_wrapped_glUniform3fv
struct glad_tag_glBufferData {};
inline void glad_wrapped_glBufferData(GLenum _target, GLsizeiptr _size, const void* _data, GLenum _usage) { GLAD_INSTRUMENT_CALL(glBufferData, _target, _size, _data, _usage); }
	#define glBufferData glad_wrapped_glBufferData
struct glad_tag_glCompressedTexImage3D {};
inline void glad_wrapped_glCompressedTexImage3D(GLenum _target, GLint _level, GLenum _internalformat, GLsizei _width, GLsizei _height, GLsizei _depth, GLint _border, GLsizei _imageSize, const void* _data) { GLAD_INSTRUMENT_CALL(glCompressedTexImage3D, _target, _level, _internalformat, _width, _height, _depth, _border, _imageSize, _data); }
	#define glCompressedTexImage3D glad_wrapped_glCompressedTexImage3D
struct glad_tag_glDrawElementsIndirect {};
inline void glad_wrapped_glDrawElementsIndirect(GLenum _mode, GLenum _type, const void* _indirect) { GLAD_INSTRUMENT_CALL(glDrawElementsIndirect, _mode, _type, _indirect); }
	#define glDrawElementsIndirect glad_wrapped_glDrawElementsIndirect
struct glad_tag_glDeleteSync {};
inline void glad_wrapped_glDeleteSync(GLsync _sync) { GLAD_INSTRUMENT_CALL(glDeleteSync, _sync); }
	#define glDeleteSync glad_wrapped_glDeleteSync
struct glad_tag_glCopyTexSubImage3D {};
inline void glad_wrapped_glCopyTexSubImage3D(GLenum _target, GLint _level, GLint _xoffset, GLint _yoffset, GLint _zoffset, GLint _x, GLint _y, GLsizei _width, GLsizei _height) { GLAD_INSTRUMENT_CALL(glCopyTexSubImage3D, _target, _level, _xoffset, _yoffset, _zoffset, _x, _y, _width, _height); }
	#define glCopyTexSubImage3D glad_wrapped_glCopyTexSubImage3D
struct glad_tag_glGetFragDataLocation {};
inline GLint glad_wrapped_glGetFragDataLocation(GLuint _program, const GLchar* _name) { return GLAD_INSTRUMENT_CALL(glGetFragDataLocation, _program, _name); }
	#define glGetFragDataLocation glad_wrapped_glGetFragDataLocation
struct glad_tag_glGetError {};
inline GLenum glad_wrapped_glGetError() { return GLAD_INSTRUMENT_CALL(glGetError); }
	#define glGetError glad_wrapped_glGetError
struct glad_tag_glGetActiveUniformBlockName {};
inline void glad_wrapped_glGetActiveUniformBlockName(GLuint _program, GLuint _uniformBlockIndex, GLsizei _bufSize, GLsizei* _length, GLchar* _uniformBlockName) { GLAD_INSTRUMENT_CALL(glGetActiveUniformBlockName, _program, _uniformBlockIndex, _bufSize, _length, _uniformBlockName); }
	#define glGetActiveUniformBlockName glad_wrapped_glGetActiveUniformBlockName
struct glad_tag_glGetVertexAttribiv {};
inline void glad_wrapped_glGetVertexAttribiv(GLuint _index, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetVertexAttribiv, _index, _pname, _params); }
	#define glGetVertexAttribiv glad_wrapped_glGetVertexAttribiv
struct glad_tag_glTexParameteriv {};
inline void glad_wrapped_glTexParameteriv(GLenum _target, GLenum _pname, const GLint* _params) { GLAD_INSTRUMENT_CALL(glTexParameteriv, _target, _pname, _params); }
	#define glTexParameteriv glad_wrapped_glTexParameteriv
struct glad_tag_glGetProgramBinary {};
inline void glad_wrapped_glGetProgramBinary(GLuint _program, GLsizei _bufSize, GLsizei* _length, GLenum* _binaryFormat, void* _binary) { GLAD_INSTRUMENT_CALL(glGetProgramBinary, _program, _bufSize, _length, _binaryFormat, _binary); }
	#define glGetProgramBinary glad_wrapped_glGetProgramBinary
struct glad_tag_glVertexAttrib3fv {};
inline void glad_wrapped_glVertexAttrib3fv(GLuint _index, const GLfloat* _v) { GLAD_INSTRUMENT_CALL(glVertexAttrib3fv, _index, _v); }
	#define glVertexAttrib3fv glad_wrapped_glVertexAttrib3fv
struct glad_tag_glGetFloatv {};
inline void glad_wrapped_glGetFloatv(GLenum _pname, GLfloat* _data) { GLAD_INSTRUMENT_CALL(glGetFloatv, _pname, _data); }
	#define glGetFloatv glad_wrapped_glGetFloatv
struct glad_tag_glUniform3iv {};
inline void glad_wrapped_glUniform3iv(GLint _location, GLsizei _count, const GLint* _value) { GLAD_INSTRUMENT_CALL(glUniform3iv, _location, _count, _value); }
	#define glUniform3iv glad_wrapped_glUniform3iv
struct glad_tag_glVertexAttrib2fv {};
inline void glad_wrapped_glVertexAttrib2fv(GLuint _index, const GLfloat* _v) { GLAD_INSTRUMENT_CALL(glVertexAttrib2fv, _index, _v); }
	#define glVertexAttrib2fv glad_wrapped_glVertexAttrib2fv
struct glad_tag_glBindVertexArray {};
inline void glad_wrapped_glBindVertexArray(GLuint _array) { GLAD_INSTRUMENT_CALL(glBindVertexArray, _array); }
	#define glBindVertexArray glad_wrapped_glBindVertexArray
struct glad_tag_glGenFramebuffers {};
inline void glad_wrapped_glGenFramebuffers(GLsizei _n, GLuint* _framebuffers) { GLAD_INSTRUMENT_CALL(glGenFramebuffers, _n, _framebuffers); }
	#define glGenFramebuffers glad_wrapped_glGenFramebuffers
struct glad_tag_glDrawBuffers {};
inline void glad_wrapped_glDrawBuffers(GLsizei _n, const GLenum* _bufs) { GLAD_INSTRUMENT_CALL(glDrawBuffers, _n, _bufs); }
	#define glDrawBuffers glad_wrapped_glDrawBuffers
struct glad_tag_glGetProgramResourceLocation {};
inline GLint glad_wrapped_glGetProgramResourceLocation(GLuint _program, GLenum _programInterface, const GLchar* _name) { return GLAD_INSTRUMENT_CALL(glGetProgramResourceLocation, _program, _programInterface, _name); }
	#define glGetProgramResourceLocation glad_wrapped_glGetProgramResourceLocation
struct glad_tag_glGetActiveUniformBlockiv {};
inline void glad_wrapped_glGetActiveUniformBlockiv(GLuint _program, GLuint _uniformBlockIndex, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetActiveUniformBlockiv, _program, _uniformBlockIndex, _pname, _params); }
	#define glGetActiveUniformBlockiv glad_wrapped_glGetActiveUniformBlockiv
struct glad_tag_glVertexAttribBinding {};
inline void glad_wrapped_glVertexAttribBinding(GLuint _attribindex, GLuint _bindingindex) { GLAD_INSTRUMENT_CALL(glVertexAttribBinding, _attribindex, _bindingindex); }
	#define glVertexAttribBinding glad_wrapped_glVertexAttribBinding
struct glad_tag_glStencilFunc {};
inline void glad_wrapped_glStencilFunc(GLenum _func, GLint _ref, GLuint _mask) { GLAD_INSTRUMENT_CALL(glStencilFunc, _func, _ref, _mask); }
	#define glStencilFunc glad_wrapped_glStencilFunc
struct glad_tag_glGetIntegerv {};
inline void glad_wrapped_glGetIntegerv(GLenum _pname, GLint* _data) { GLAD_INSTRUMENT_CALL(glGetIntegerv, _pname, _data); }
	#define glGetIntegerv glad_wrapped_glGetIntegerv
struct glad_tag_glGetAttachedShaders {};
inline void glad_wrapped_glGetAttachedShaders(GLuint _program, GLsizei _maxCount, GLsizei* _count, GLuint* _shaders) { GLAD_INSTRUMENT_CALL(glGetAttachedShaders, _program, _maxCount, _count, _shaders); }
	#define glGetAttachedShaders glad_wrapped_glGetAttachedShaders
struct glad_tag_glUniformBlockBinding {};
inline void glad_wrapped_glUniformBlockBinding(GLuint _program, GLuint _uniformBlockIndex, GLuint _uniformBlockBinding) { GLAD_INSTRUMENT_CALL(glUniformBlockBinding, _program, _uniformBlockIndex, _uniformBlockBinding); }
	#define glUniformBlockBinding glad_wrapped_glUniformBlockBinding
struct glad_tag_glIsRenderbuffer {};
inline GLboolean glad_wrapped_glIsRenderbuffer(GLuint _renderbuffer) { return GLAD_INSTRUMENT_CALL(glIsRenderbuffer, _renderbuffer); }
	#define glIsRenderbuffer glad_wrapped_glIsRenderbuffer
struct glad_tag_glGetBufferPointerv {};
inline void glad_wrapped_glGetBufferPointerv(GLenum _target, GLenum _pname, void** _params) { GLAD_INSTRUMENT_CALL(glGetBufferPointerv, _target, _pname, _params); }
	#define glGetBufferPointerv glad_wrapped_glGetBufferPointerv
struct glad_tag_glDeleteVertexArrays {};
inline void glad_wrapped_glDeleteVertexArrays(GLsizei _n, const GLuint* _arrays) { GLAD_INSTRUMENT_CALL(glDeleteVertexArrays, _n, _arrays); }
	#define glDeleteVertexArrays glad_wrapped_glDeleteVertexArrays
struct glad_tag_glUniform1fv {};
inline void glad_wrapped_glUniform1fv(GLint _location, GLsizei _count, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glUniform1fv, _location, _count, _value); }
	#define glUniform1fv glad_wrapped_glUniform1fv
struct glad_tag_glBeginQuery {};
inline void glad_wrapped_glBeginQuery(GLenum _target, GLuint _id) { GLAD_INSTRUMENT_CALL(glBeginQuery, _target, _id); }
	#define glBeginQuery glad_wrapped_glBeginQuery
struct glad_tag_glRenderbufferStorageMultisample {};
inline void glad_wrapped_glRenderbufferStorageMultisample(GLenum _target, GLsizei _samples, GLenum _internalformat, GLsizei _width, GLsizei _height) { GLAD_INSTRUMENT_CALL(glRenderbufferStorageMultisample, _target, _samples, _internalformat, _width, _height); }
	#define glRenderbufferStorageMultisample glad_wrapped_glRenderbufferStorageMultisample
struct glad_tag_glProgramUniform3f {};
inline void glad_wrapped_glProgramUniform3f(GLuint _program, GLint _location, GLfloat _v0, GLfloat _v1, GLfloat _v2) { GLAD_INSTRUMENT_CALL(glProgramUniform3f, _program, _location, _v0, _v1, _v2); }
	#define glProgramUniform3f glad_wrapped_glProgramUniform3f
struct glad_tag_glUniform4uiv {};
inline void glad_wrapped_glUniform4uiv(GLint _location, GLsizei _count, const GLuint* _value) { GLAD_INSTRUMENT_CALL(glUniform4uiv, _location, _count, _value); }
	#define glUniform4uiv glad_wrapped_glUniform4uiv
struct glad_tag_glIsQuery {};
inline GLboolean glad_wrapped_glIsQuery(GLuint _id) { return GLAD_INSTRUMENT_CALL(glIsQuery, _id); }
	#define glIsQuery glad_wrapped_glIsQuery
struct glad_tag_glUniformMatrix2fv {};
inline void glad_wrapped_glUniformMatrix2fv(GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glUniformMatrix2fv, _location, _count, _transpose, _value); }
	#define glUniformMatrix2fv glad_wrapped_glUniformMatrix2fv
struct glad_tag_glDisableVertexAttribArray {};
inline void glad_wrapped_glDisableVertexAttribArray(GLuint _index) { GLAD_INSTRUMENT_CALL(glDisableVertexAttribArray, _index); }
	#define glDisableVertexAttribArray glad_wrapped_glDisableVertexAttribArray
struct glad_tag_glVertexAttribI4iv {};
inline void glad_wrapped_glVertexAttribI4iv(GLuint _index, const GLint* _v) { GLAD_INSTRUMENT_CALL(glVertexAttribI4iv, _index, _v); }
	#define glVertexAttribI4iv glad_wrapped_glVertexAttribI4iv
struct glad_tag_glGetQueryiv {};
inline void glad_wrapped_glGetQueryiv(GLenum _target, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetQueryiv, _target, _pname, _params); }
	#define glGetQueryiv glad_wrapped_glGetQueryiv
struct glad_tag_glTexImage2D {};
inline void glad_wrapped_glTexImage2D(GLenum _target, GLint _level, GLint _internalformat, GLsizei _width, GLsizei _height, GLint _border, GLenum _format, GLenum _type, const void* _pixels) { GLAD_INSTRUMENT_CALL(glTexImage2D, _target, _level, _internalformat, _width, _height, _border, _format, _type, _pixels); }
	#define glTexImage2D glad_wrapped_glTexImage2D
struct glad_tag_glGetProgramInfoLog {};
inline void glad_wrapped_glGetProgramInfoLog(GLuint _program, GLsizei _bufSize, GLsizei* _length, GLchar* _infoLog) { GLAD_INSTRUMENT_CALL(glGetProgramInfoLog, _program, _bufSize, _length, _infoLog); }
	#define glGetProgramInfoLog glad_wrapped_glGetProgramInfoLog
struct glad_tag_glGetSamplerParameterfv {};
inline void glad_wrapped_glGetSamplerParameterfv(GLuint _sampler, GLenum _pname, GLfloat* _params) { GLAD_INSTRUMENT_CALL(glGetSamplerParameterfv, _sampler, _pname, _params); }
	#define glGetSamplerParameterfv glad_wrapped_glGetSamplerParameterfv
struct glad_tag_glStencilMask {};
inline void glad_wrapped_glStencilMask(GLuint _mask) { GLAD_INSTRUMENT_CALL(glStencilMask, _mask); }
	#define glStencilMask glad_wrapped_glStencilMask
struct glad_tag_glUniform4ui {};
inline void glad_wrapped_glUniform4ui(GLint _location, GLuint _v0, GLuint _v1, GLuint _v2, GLuint _v3) { GLAD_INSTRUMENT_CALL(glUniform4ui, _location, _v0, _v1, _v2, _v3); }
	#define glUniform4ui glad_wrapped_glUniform4ui
struct glad_tag_glSamplerParameterfv {};
inline void glad_wrapped_glSamplerParameterfv(GLuint _sampler, GLenum _pname, const GLfloat* _param) { GLAD_INSTRUMENT_CALL(glSamplerParameterfv, _sampler, _pname, _param); }
	#define glSamplerParameterfv glad_wrapped_glSamplerParameterfv
struct glad_tag_glProgramUniformMatrix4x3fv {};
inline void glad_wrapped_glProgramUniformMatrix4x3fv(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix4x3fv, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix4x3fv glad_wrapped_glProgramUniformMatrix4x3fv
struct glad_tag_glGetShaderInfoLog {};
inline void glad_wrapped_glGetShaderInfoLog(GLuint _shader, GLsizei _bufSize, GLsizei* _length, GLchar* _infoLog) { GLAD_INSTRUMENT_CALL(glGetShaderInfoLog, _shader, _bufSize, _length, _infoLog); }
	#define glGetShaderInfoLog glad_wrapped_glGetShaderInfoLog
struct glad_tag_glIsTexture {};
inline GLboolean glad_wrapped_glIsTexture(GLuint _texture) { return GLAD_INSTRUMENT_CALL(glIsTexture, _texture); }
	#define glIsTexture glad_wrapped_glIsTexture
struct glad_tag_glGetUniformIndices {};
inline void glad_wrapped_glGetUniformIndices(GLuint _program, GLsizei _uniformCount, const GLchar** _uniformNames, GLuint* _uniformIndices) { GLAD_INSTRUMENT_CALL(glGetUniformIndices, _program, _uniformCount, _uniformNames, _uniformIndices); }
	#define glGetUniformIndices glad_wrapped_glGetUniformIndices
struct glad_tag_glIsShader {};
inline GLboolean glad_wrapped_glIsShader(GLuint _shader) { return GLAD_INSTRUMENT_CALL(glIsShader, _shader); }
	#define glIsShader glad_wrapped_glIsShader
struct glad_tag_glDeleteBuffers {};
inline void glad_wrapped_glDeleteBuffers(GLsizei _n, const GLuint* _buffers) { GLAD_INSTRUMENT_CALL(glDeleteBuffers, _n, _buffers); }
	#define glDeleteBuffers glad_wrapped_glDeleteBuffers
struct glad_tag_glGetInteger64v {};
inline void glad_wrapped_glGetInteger64v(GLenum _pname, GLint64* _data) { GLAD_INSTRUMENT_CALL(glGetInteger64v, _pname, _data); }
	#define glGetInteger64v glad_wrapped_glGetInteger64v
struct glad_tag_glBindProgramPipeline {};
inline void glad_wrapped_glBindProgramPipeline(GLuint _pipeline) { GLAD_INSTRUMENT_CALL(glBindProgramPipeline, _pipeline); }
	#define glBindProgramPipeline glad_wrapped_glBindProgramPipeline
struct glad_tag_glVertexAttribPointer {};
inline void glad_wrapped_glVertexAttribPointer(GLuint _index, GLint _size, GLenum _type, GLboolean _normalized, GLsizei _stride, const void* _pointer) { GLAD_INSTRUMENT_CALL(glVertexAttribPointer, _index, _size, _type, _normalized, _stride, _pointer); }
	#define glVertexAttribPointer glad_wrapped_glVertexAttribPointer
struct glad_tag_glTexParameterfv {};
inline void glad_wrapped_glTexParameterfv(GLenum _target, GLenum _pname, const GLfloat* _params) { GLAD_INSTRUMENT_CALL(glTexParameterfv, _target, _pname, _params); }
	#define glTexParameterfv glad_wrapped_glTexParameterfv
struct glad_tag_glInvalidateSubFramebuffer {};
inline void glad_wrapped_glInvalidateSubFramebuffer(GLenum _target, GLsizei _numAttachments, const GLenum* _attachments, GLint _x, GLint _y, GLsizei _width, GLsizei _height) { GLAD_INSTRUMENT_CALL(glInvalidateSubFramebuffer, _target, _numAttachments, _attachments, _x, _y, _width, _height); }
	#define glInvalidateSubFramebuffer glad_wrapped_glInvalidateSubFramebuffer
struct glad_tag_glUniformMatrix3fv {};
inline void glad_wrapped_glUniformMatrix3fv(GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glUniformMatrix3fv, _location, _count, _transpose, _value); }
	#define glUniformMatrix3fv glad_wrapped_glUniformMatrix3fv
struct glad_tag_glDrawElementsInstanced {};
inline void glad_wrapped_glDrawElementsInstanced(GLenum _mode, GLsizei _count, GLenum _type, const void* _indices, GLsizei _instancecount) { GLAD_INSTRUMENT_CALL(glDrawElementsInstanced, _mode, _count, _type, _indices, _instancecount); }
	#define glDrawElementsInstanced glad_wrapped_glDrawElementsInstanced
struct glad_tag_glProgramUniform1fv {};
inline void glad_wrapped_glProgramUniform1fv(GLuint _program, GLint _location, GLsizei _count, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform1fv, _program, _location, _count, _value); }
	#define glProgramUniform1fv glad_wrapped_glProgramUniform1fv
struct glad_tag_glEnable {};
inline void glad_wrapped_glEnable(GLenum _cap) { GLAD_INSTRUMENT_CALL(glEnable, _cap); }
	#define glEnable glad_wrapped_glEnable
struct glad_tag_glGetActiveUniformsiv {};
inline void glad_wrapped_glGetActiveUniformsiv(GLuint _program, GLsizei _uniformCount, const GLuint* _uniformIndices, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetActiveUniformsiv, _program, _uniformCount, _uniformIndices, _pname, _params); }
	#define glGetActiveUniformsiv glad_wrapped_glGetActiveUniformsiv
struct glad_tag_glVertexAttribI4i {};
inline void glad_wrapped_glVertexAttribI4i(GLuint _index, GLint _x, GLint _y, GLint _z, GLint _w) { GLAD_INSTRUMENT_CALL(glVertexAttribI4i, _index, _x, _y, _z, _w); }
	#define glVertexAttribI4i glad_wrapped_glVertexAttribI4i
struct glad_tag_glVertexAttribI4ui {};
inline void glad_wrapped_glVertexAttribI4ui(GLuint _index, GLuint _x, GLuint _y, GLuint _z, GLuint _w) { GLAD_INSTRUMENT_CALL(glVertexAttribI4ui, _index, _x, _y, _z, _w); }
	#define glVertexAttribI4ui glad_wrapped_glVertexAttribI4ui
struct glad_tag_glDeleteQueries {};
inline void glad_wrapped_glDeleteQueries(GLsizei _n, const GLuint* _ids) { GLAD_INSTRUMENT_CALL(glDeleteQueries, _n, _ids); }
	#define glDeleteQueries glad_wrapped_glDeleteQueries
struct glad_tag_glMemoryBarrierByRegion {};
inline void glad_wrapped_glMemoryBarrierByRegion(GLbitfield _barriers) { GLAD_INSTRUMENT_CALL(glMemoryBarrierByRegion, _barriers); }
	#define glMemoryBarrierByRegion glad_wrapped_glMemoryBarrierByRegion
struct glad_tag_glProgramUniform3fv {};
inline void glad_wrapped_glProgramUniform3fv(GLuint _program, GLint _location, GLsizei _count, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform3fv, _program, _location, _count, _value); }
	#define glProgramUniform3fv glad_wrapped_glProgramUniform3fv
struct glad_tag_glBlendEquationSeparate {};
inline void glad_wrapped_glBlendEquationSeparate(GLenum _modeRGB, GLenum _modeAlpha) { GLAD_INSTRUMENT_CALL(glBlendEquationSeparate, _modeRGB, _modeAlpha); }
	#define glBlendEquationSeparate glad_wrapped_glBlendEquationSeparate
struct glad_tag_glGenBuffers {};
inline void glad_wrapped_glGenBuffers(GLsizei _n, GLuint* _buffers) { GLAD_INSTRUMENT_CALL(glGenBuffers, _n, _buffers); }
	#define glGenBuffers glad_wrapped_glGenBuffers
struct glad_tag_glFinish {};
inline void glad_wrapped_glFinish() { GLAD_INSTRUMENT_CALL(glFinish); }
	#define glFinish glad_wrapped_glFinish
struct glad_tag_glGetAttribLocation {};
inline GLint glad_wrapped_glGetAttribLocation(GLuint _program, const GLchar* _name) { return GLAD_INSTRUMENT_CALL(glGetAttribLocation, _program, _name); }
	#define glGetAttribLocation glad_wrapped_glGetAttribLocation
struct glad_tag_glProgramUniform3uiv {};
inline void glad_wrapped_glProgramUniform3uiv(GLuint _program, GLint _location, GLsizei _count, const GLuint* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform3uiv, _program, _location, _count, _value); }
	#define glProgramUniform3uiv glad_wrapped_glProgramUniform3uiv
struct glad_tag_glGetProgramInterfaceiv {};
inline void glad_wrapped_glGetProgramInterfaceiv(GLuint _program, GLenum _programInterface, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetProgramInterfaceiv, _program, _programInterface, _pname, _params); }
	#define glGetProgramInterfaceiv glad_wrapped_glGetProgramInterfaceiv
struct glad_tag_glDeleteShader {};
inline void glad_wrapped_glDeleteShader(GLuint _shader) { GLAD_INSTRUMENT_CALL(glDeleteShader, _shader); }
	#define glDeleteShader glad_wrapped_glDeleteShader
struct glad_tag_glBlendFunc {};
inline void glad_wrapped_glBlendFunc(GLenum _sfactor, GLenum _dfactor) { GLAD_INSTRUMENT_CALL(glBlendFunc, _sfactor, _dfactor); }
	#define glBlendFunc glad_wrapped_glBlendFunc
struct glad_tag_glCreateProgram {};
inline GLuint glad_wrapped_glCreateProgram() { return GLAD_INSTRUMENT_CALL(glCreateProgram); }
	#define glCreateProgram glad_wrapped_glCreateProgram
struct glad_tag_glTexImage3D {};
inline void glad_wrapped_glTexImage3D(GLenum _target, GLint _level, GLint _internalformat, GLsizei _width, GLsizei _height, GLsizei _depth, GLint _border, GLenum _format, GLenum _type, const void* _pixels) { GLAD_INSTRUMENT_CALL(glTexImage3D, _target, _level, _internalformat, _width, _height, _depth, _border, _format, _type, _pixels); }
	#define glTexImage3D glad_wrapped_glTexImage3D
struct glad_tag_glGenSamplers {};
inline void glad_wrapped_glGenSamplers(GLsizei _count, GLuint* _samplers) { GLAD_INSTRUMENT_CALL(glGenSamplers, _count, _samplers); }
	#define glGenSamplers glad_wrapped_glGenSamplers
struct glad_tag_glGetSamplerParameteriv {};
inline void glad_wrapped_glGetSamplerParameteriv(GLuint _sampler, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetSamplerParameteriv, _sampler, _pname, _params); }
	#define glGetSamplerParameteriv glad_wrapped_glGetSamplerParameteriv
struct glad_tag_glIsFramebuffer {};
inline GLboolean glad_wrapped_glIsFramebuffer(GLuint _framebuffer) { return GLAD_INSTRUMENT_CALL(glIsFramebuffer, _framebuffer); }
	#define glIsFramebuffer glad_wrapped_glIsFramebuffer
struct glad_tag_glProgramUniform2f {};
inline void glad_wrapped_glProgramUniform2f(GLuint _program, GLint _location, GLfloat _v0, GLfloat _v1) { GLAD_INSTRUMENT_CALL(glProgramUniform2f, _program, _location, _v0, _v1); }
	#define glProgramUniform2f glad_wrapped_glProgramUniform2f
struct glad_tag_glFlushMappedBufferRange {};
inline void glad_wrapped_glFlushMappedBufferRange(GLenum _target, GLintptr _offset, GLsizeiptr _length) { GLAD_INSTRUMENT_CALL(glFlushMappedBufferRange, _target, _offset, _length); }
	#define glFlushMappedBufferRange glad_wrapped_glFlushMappedBufferRange
struct glad_tag_glViewport {};
inline void glad_wrapped_glViewport(GLint _x, GLint _y, GLsizei _width, GLsizei _height) { GLAD_INSTRUMENT_CALL(glViewport, _x, _y, _width, _height); }
	#define glViewport glad_wrapped_glViewport
struct glad_tag_glInvalidateFramebuffer {};
inline void glad_wrapped_glInvalidateFramebuffer(GLenum _target, GLsizei _numAttachments, const GLenum* _attachments) { GLAD_INSTRUMENT_CALL(glInvalidateFramebuffer, _target, _numAttachments, _attachments); }
	#define glInvalidateFramebuffer glad_wrapped_glInvalidateFramebuffer
struct glad_tag_glUniform1uiv {};
inline void glad_wrapped_glUniform1uiv(GLint _location, GLsizei _count, const GLuint* _value) { GLAD_INSTRUMENT_CALL(glUniform1uiv, _location, _count, _value); }
	#define glUniform1uiv glad_wrapped_glUniform1uiv
struct glad_tag_glTransformFeedbackVaryings {};
inline void glad_wrapped_glTransformFeedbackVaryings(GLuint _program, GLsizei _count, const GLchar** _varyings, GLenum _bufferMode) { GLAD_INSTRUMENT_CALL(glTransformFeedbackVaryings, _program, _count, _varyings, _bufferMode); }
	#define glTransformFeedbackVaryings glad_wrapped_glTransformFeedbackVaryings
struct glad_tag_glVertexAttrib2f {};
inline void glad_wrapped_glVertexAttrib2f(GLuint _index, GLfloat _x, GLfloat _y) { GLAD_INSTRUMENT_CALL(glVertexAttrib2f, _index, _x, _y); }
	#define glVertexAttrib2f glad_wrapped_glVertexAttrib2f
struct glad_tag_glVertexAttrib1f {};
inline void glad_wrapped_glVertexAttrib1f(GLuint _index, GLfloat _x) { GLAD_INSTRUMENT_CALL(glVertexAttrib1f, _index, _x); }
	#define glVertexAttrib1f glad_wrapped_glVertexAttrib1f
struct glad_tag_glVertexBindingDivisor {};
inline void glad_wrapped_glVertexBindingDivisor(GLuint _bindingindex, GLuint _divisor) { GLAD_INSTRUMENT_CALL(glVertexBindingDivisor, _bindingindex, _divisor); }
	#define glVertexBindingDivisor glad_wrapped_glVertexBindingDivisor
struct glad_tag_glUniform2ui {};
inline void glad_wrapped_glUniform2ui(GLint _location, GLuint _v0, GLuint _v1) { GLAD_INSTRUMENT_CALL(glUniform2ui, _location, _v0, _v1); }
	#define glUniform2ui glad_wrapped_glUniform2ui
struct glad_tag_glGetUniformfv {};
inline void glad_wrapped_glGetUniformfv(GLuint _program, GLint _location, GLfloat* _params) { GLAD_INSTRUMENT_CALL(glGetUniformfv, _program, _location, _params); }
	#define glGetUniformfv glad_wrapped_glGetUniformfv
struct glad_tag_glGetUniformuiv {};
inline void glad_wrapped_glGetUniformuiv(GLuint _program, GLint _location, GLuint* _params) { GLAD_INSTRUMENT_CALL(glGetUniformuiv, _program, _location, _params); }
	#define glGetUniformuiv glad_wrapped_glGetUniformuiv
struct glad_tag_glProgramUniformMatrix2x3fv {};
inline void glad_wrapped_glProgramUniformMatrix2x3fv(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix2x3fv, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix2x3fv glad_wrapped_glProgramUniformMatrix2x3fv
struct glad_tag_glProgramUniform1f {};
inline void glad_wrapped_glProgramUniform1f(GLuint _program, GLint _location, GLfloat _v0) { GLAD_INSTRUMENT_CALL(glProgramUniform1f, _program, _location, _v0); }
	#define glProgramUniform1f glad_wrapped_glProgramUniform1f
struct glad_tag_glUniformMatrix4fv {};
inline void glad_wrapped_glUniformMatrix4fv(GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glUniformMatrix4fv, _location, _count, _transpose, _value); }
	#define glUniformMatrix4fv glad_wrapped_glUniformMatrix4fv
struct glad_tag_glGetVertexAttribIiv {};
inline void glad_wrapped_glGetVertexAttribIiv(GLuint _index, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetVertexAttribIiv, _index, _pname, _params); }
	#define glGetVertexAttribIiv glad_wrapped_glGetVertexAttribIiv
struct glad_tag_glVertexAttribIFormat {};
inline void glad_wrapped_glVertexAttribIFormat(GLuint _attribindex, GLint _size, GLenum _type, GLuint _relativeoffset) { GLAD_INSTRUMENT_CALL(glVertexAttribIFormat, _attribindex, _size, _type, _relativeoffset); }
	#define glVertexAttribIFormat glad_wrapped_glVertexAttribIFormat
struct glad_tag_glGetActiveUniform {};
inline void glad_wrapped_glGetActiveUniform(GLuint _program, GLuint _index, GLsizei _bufSize, GLsizei* _length, GLint* _size, GLenum* _type, GLchar* _name) { GLAD_INSTRUMENT_CALL(glGetActiveUniform, _program, _index, _bufSize, _length, _size, _type, _name); }
	#define glGetActiveUniform glad_wrapped_glGetActiveUniform
struct glad_tag_glBindVertexBuffer {};
inline void glad_wrapped_glBindVertexBuffer(GLuint _bindingindex, GLuint _buffer, GLintptr _offset, GLsizei _stride) { GLAD_INSTRUMENT_CALL(glBindVertexBuffer, _bindingindex, _buffer, _offset, _stride); }
	#define glBindVertexBuffer glad_wrapped_glBindVertexBuffer
struct glad_tag_glTexParameterf {};
inline void glad_wrapped_glTexParameterf(GLenum _target, GLenum _pname, GLfloat _param) { GLAD_INSTRUMENT_CALL(glTexParameterf, _target, _pname, _param); }
	#define glTexParameterf glad_wrapped_glTexParameterf
struct glad_tag_glClearBufferfi {};
inline void glad_wrapped_glClearBufferfi(GLenum _buffer, GLint _drawbuffer, GLfloat _depth, GLint _stencil) { GLAD_INSTRUMENT_CALL(glClearBufferfi, _buffer, _drawbuffer, _depth, _stencil); }
	#define glClearBufferfi glad_wrapped_glClearBufferfi
struct glad_tag_glTexParameteri {};
inline void glad_wrapped_glTexParameteri(GLenum _target, GLenum _pname, GLint _param) { GLAD_INSTRUMENT_CALL(glTexParameteri, _target, _pname, _param); }
	#define glTexParameteri glad_wrapped_glTexParameteri
struct glad_tag_glFrontFace {};
inline void glad_wrapped_glFrontFace(GLenum _mode) { GLAD_INSTRUMENT_CALL(glFrontFace, _mode); }
	#define glFrontFace glad_wrapped_glFrontFace
struct glad_tag_glGetProgramPipelineiv {};
inline void glad_wrapped_glGetProgramPipelineiv(GLuint _pipeline, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetProgramPipelineiv, _pipeline, _pname, _params); }
	#define glGetProgramPipelineiv glad_wrapped_glGetProgramPipelineiv
struct glad_tag_glClearDepthf {};
inline void glad_wrapped_glClearDepthf(GLfloat _d) { GLAD_INSTRUMENT_CALL(glClearDepthf, _d); }
	#define glClearDepthf glad_wrapped_glClearDepthf
struct glad_tag_glGetShaderSource {};
inline void glad_wrapped_glGetShaderSource(GLuint _shader, GLsizei _bufSize, GLsizei* _length, GLchar* _source) { GLAD_INSTRUMENT_CALL(glGetShaderSource, _shader, _bufSize, _length, _source); }
	#define glGetShaderSource glad_wrapped_glGetShaderSource
struct glad_tag_glSamplerParameteriv {};
inline void glad_wrapped_glSamplerParameteriv(GLuint _sampler, GLenum _pname, const GLint* _param) { GLAD_INSTRUMENT_CALL(glSamplerParameteriv, _sampler, _pname, _param); }
	#define glSamplerParameteriv glad_wrapped_glSamplerParameteriv
struct glad_tag_glScissor {};
inline void glad_wrapped_glScissor(GLint _x, GLint _y, GLsizei _width, GLsizei _height) { GLAD_INSTRUMENT_CALL(glScissor, _x, _y, _width, _height); }
	#define glScissor glad_wrapped_glScissor
struct glad_tag_glGetBooleanv {};
inline void glad_wrapped_glGetBooleanv(GLenum _pname, GLboolean* _data) { GLAD_INSTRUMENT_CALL(glGetBooleanv, _pname, _data); }
	#define glGetBooleanv glad_wrapped_glGetBooleanv
struct glad_tag_glProgramUniform1i {};
inline void glad_wrapped_glProgramUniform1i(GLuint _program, GLint _location, GLint _v0) { GLAD_INSTRUMENT_CALL(glProgramUniform1i, _program, _location, _v0); }
	#define glProgramUniform1i glad_wrapped_glProgramUniform1i
struct glad_tag_glPixelStorei {};
inline void glad_wrapped_glPixelStorei(GLenum _pname, GLint _param) { GLAD_INSTRUMENT_CALL(glPixelStorei, _pname, _param); }
	#define glPixelStorei glad_wrapped_glPixelStorei
struct glad_tag_glValidateProgram {};
inline void glad_wrapped_glValidateProgram(GLuint _program) { GLAD_INSTRUMENT_CALL(glValidateProgram, _program); }
	#define glValidateProgram glad_wrapped_glValidateProgram
struct glad_tag_glPolygonOffset {};
inline void glad_wrapped_glPolygonOffset(GLfloat _factor, GLfloat _units) { GLAD_INSTRUMENT_CALL(glPolygonOffset, _factor, _units); }
	#define glPolygonOffset glad_wrapped_glPolygonOffset
struct glad_tag_glClearBufferuiv {};
inline void glad_wrapped_glClearBufferuiv(GLenum _buffer, GLint _drawbuffer, const GLuint* _value) { GLAD_INSTRUMENT_CALL(glClearBufferuiv, _buffer, _drawbuffer, _value); }
	#define glClearBufferuiv glad_wrapped_glClearBufferuiv
struct glad_tag_glUniform3uiv {};
inline void glad_wrapped_glUniform3uiv(GLint _location, GLsizei _count, const GLuint* _value) { GLAD_INSTRUMENT_CALL(glUniform3uiv, _location, _count, _value); }
	#define glUniform3uiv glad_wrapped_glUniform3uiv
struct glad_tag_glGetBooleani_v {};
inline void glad_wrapped_glGetBooleani_v(GLenum _target, GLuint _index, GLboolean* _data) { GLAD_INSTRUMENT_CALL(glGetBooleani_v, _target, _index, _data); }
	#define glGetBooleani_v glad_wrapped_glGetBooleani_v
struct glad_tag_glVertexAttribIPointer {};
inline void glad_wrapped_glVertexAttribIPointer(GLuint _index, GLint _size, GLenum _type, GLsizei _stride, const void* _pointer) { GLAD_INSTRUMENT_CALL(glVertexAttribIPointer, _index, _size, _type, _stride, _pointer); }
	#define glVertexAttribIPointer                glad_wrapped_glVertexAttribIPointer
#else
	#define glGenProgramPipelines                 glad_glGenProgramPipelines
	#define glFlush                               glad_glFlush
	#define glGetRenderbufferParameteriv          glad_glGetRenderbufferParameteriv
	#define glClearColor                          glad_glClearColor
	#define glProgramUniform3iv                   glad_glProgramUniform3iv
	#define glGetUniformBlockIndex                glad_glGetUniformBlockIndex
	#define glProgramUniform4ui                   glad_glProgramUniform4ui
	#define glClearBufferiv                       glad_glClearBufferiv
	#define glStencilMaskSeparate                 glad_glStencilMaskSeparate
	#define glGetVertexAttribPointerv             glad_glGetVertexAttribPointerv
	#define glProgramUniform2ui                   glad_glProgramUniform2ui
	#define glLinkProgram                         glad_glLinkProgram
	#define glProgramUniformMatrix4fv             glad_glProgramUniformMatrix4fv
	#define glBindTexture                         glad_glBindTexture
	#define glGetStringi                          glad_glGetStringi
	#define glFenceSync                           glad_glFenceSync
	#define glUniform3ui                          glad_glUniform3ui
	#define glFramebufferRenderbuffer             glad_glFramebufferRenderbuffer
	#define glGetString                           glad_glGetString
	#define glDispatchCompute                     glad_glDispatchCompute
	#define glCompressedTexSubImage3D             glad_glCompressedTexSubImage3D
	#define glDetachShader                        glad_glDetachShader
	#define glVertexAttribI4uiv                   glad_glVertexAttribI4uiv
	#define glEndQuery                            glad_glEndQuery
	#define glGetTexLevelParameteriv              glad_glGetTexLevelParameteriv
	#define glBindSampler                         glad_glBindSampler
	#define glLineWidth                           glad_glLineWidth
	#define glUniform2fv                          glad_glUniform2fv
	#define glGetProgramResourceName              glad_glGetProgramResourceName
	#define glGetProgramResourceIndex             glad_glGetProgramResourceIndex
	#define glGetIntegeri_v                       glad_glGetIntegeri_v
	#define glGetInternalformativ                 glad_glGetInternalformativ
	#define glCompileShader                       glad_glCompileShader
	#define glGetTransformFeedbackVarying         glad_glGetTransformFeedbackVarying
	#define glDeleteTextures                      glad_glDeleteTextures
	#define glDispatchComputeIndirect             glad_glDispatchComputeIndirect
	#define glStencilOpSeparate                   glad_glStencilOpSeparate
	#define glDrawArraysIndirect                  glad_glDrawArraysIndirect
	#define glStencilFuncSeparate                 glad_glStencilFuncSeparate
	#define glBindBufferRange                     glad_glBindBufferRange
	#define glVertexAttrib4f                      glad_glVertexAttrib4f
	#define glGenQueries                          glad_glGenQueries
	#define glGetBufferParameteri64v              glad_glGetBufferParameteri64v
	#define glDepthRangef                         glad_glDepthRangef
	#define glUniform4iv                          glad_glUniform4iv
	#define glGetTexParameteriv                   glad_glGetTexParameteriv
	#define glClearStencil                        glad_glClearStencil
	#define glProgramUniform2fv                   glad_glProgramUniform2fv
	#define glUniformMatrix2x3fv                  glad_glUniformMatrix2x3fv
	#define glGenTransformFeedbacks               glad_glGenTransformFeedbacks
	#define glGetVertexAttribIuiv                 glad_glGetVertexAttribIuiv
	#define glUseProgramStages                    glad_glUseProgramStages
	#define glSampleCoverage                      glad_glSampleCoverage
	#define glSamplerParameteri                   glad_glSamplerParameteri
	#define glGenTextures                         glad_glGenTextures
	#define glSamplerParameterf                   glad_glSamplerParameterf
	#define glDepthFunc                           glad_glDepthFunc
	#define glCompressedTexSubImage2D             glad_glCompressedTexSubImage2D
	#define glIsVertexArray                       glad_glIsVertexArray
	#define glUniform1f                           glad_glUniform1f
	#define glGetVertexAttribfv                   glad_glGetVertexAttribfv
	#define glProgramBinary                       glad_glProgramBinary
	#define glGetTexParameterfv                   glad_glGetTexParameterfv
	#define glProgramUniformMatrix3x2fv           glad_glProgramUniformMatrix3x2fv
	#define glGetFramebufferParameteriv           glad_glGetFramebufferParameteriv
	#define glCreateShader                        glad_glCreateShader
	#define glIsBuffer                            glad_glIsBuffer
	#define glUniform1i                           glad_glUniform1i
	#define glGenRenderbuffers                    glad_glGenRenderbuffers
	#define glCopyTexSubImage2D                   glad_glCopyTexSubImage2D
	#define glCompressedTexImage2D                glad_glCompressedTexImage2D
	#define glDisable                             glad_glDisable
	#define glUniform2i                           glad_glUniform2i
	#define glBlendFuncSeparate                   glad_glBlendFuncSeparate
	#define glProgramUniformMatrix3x4fv           glad_glProgramUniformMatrix3x4fv
	#define glGetProgramiv                        glad_glGetProgramiv
	#define glColorMask                           glad_glColorMask
	#define glProgramUniform1ui                   glad_glProgramUniform1ui
	#define glHint                                glad_glHint
	#define glFramebufferTextureLayer             glad_glFramebufferTextureLayer
	#define glProgramUniform4fv                   glad_glProgramUniform4fv
	#define glBlendEquation                       glad_glBlendEquation
	#define glGetUniformLocation                  glad_glGetUniformLocation
	#define glSampleMaski                         glad_glSampleMaski
	#define glBindFramebuffer                     glad_glBindFramebuffer
	#define glEndTransformFeedback                glad_glEndTransformFeedback
	#define glCullFace                            glad_glCullFace
	#define glUniformMatrix3x2fv                  glad_glUniformMatrix3x2fv
	#define glPauseTransformFeedback              glad_glPauseTransformFeedback
	#define glTexStorage2D                        glad_glTexStorage2D
	#define glUniform4fv                          glad_glUniform4fv
	#define glProgramUniform4i                    glad_glProgramUniform4i
	#define glIsProgramPipeline                   glad_glIsProgramPipeline
	#define glProgramUniform4f                    glad_glProgramUniform4f
	#define glGetProgramResourceiv                glad_glGetProgramResourceiv
	#define glBeginTransformFeedback              glad_glBeginTransformFeedback
	#define glGetProgramPipelineInfoLog           glad_glGetProgramPipelineInfoLog
	#define glDeleteProgram                       glad_glDeleteProgram
	#define glIsSampler                           glad_glIsSampler
	#define glVertexAttribDivisor                 glad_glVertexAttribDivisor
	#define glRenderbufferStorage                 glad_glRenderbufferStorage
	#define glWaitSync                            glad_glWaitSync
	#define glAttachShader                        glad_glAttachShader
	#define glUniformMatrix4x3fv                  glad_glUniformMatrix4x3fv
	#define glUniform3i                           glad_glUniform3i
	#define glClearBufferfv                       glad_glClearBufferfv
	#define glDeleteTransformFeedbacks            glad_glDeleteTransformFeedbacks
	#define glDeleteSamplers                      glad_glDeleteSamplers
	#define glCheckFramebufferStatus              glad_glCheckFramebufferStatus
	#define glTexSubImage3D                       glad_glTexSubImage3D
	#define glGetInteger64i_v                     glad_glGetInteger64i_v
	#define glShaderBinary                        glad_glShaderBinary
	#define glCopyTexImage2D                      glad_glCopyTexImage2D
	#define glUniform3f                           glad_glUniform3f
	#define glBlitFramebuffer                     glad_glBlitFramebuffer
	#define glBindAttribLocation                  glad_glBindAttribLocation
	#define glUniformMatrix4x2fv                  glad_glUniformMatrix4x2fv
	#define glDrawElements                        glad_glDrawElements
	#define glProgramUniform4iv                   glad_glProgramUniform4iv
	#define glTexStorage2DMultisample             glad_glTexStorage2DMultisample
	#define glProgramUniform3ui                   glad_glProgramUniform3ui
	#define glProgramUniform2uiv                  glad_glProgramUniform2uiv
	#define glProgramUniform3i                    glad_glProgramUniform3i
	#define glUniform2iv                          glad_glUniform2iv
	#define glVertexAttrib1fv                     glad_glVertexAttrib1fv
	#define glGenVertexArrays                     glad_glGenVertexArrays
	#define glBindBufferBase                      glad_glBindBufferBase
	#define glBufferSubData                       glad_glBufferSubData
	#define glUniform1iv                          glad_glUniform1iv
	#define glCreateShaderProgramv                glad_glCreateShaderProgramv
	#define glGetBufferParameteriv                glad_glGetBufferParameteriv
	#define glProgramUniform4uiv                  glad_glProgramUniform4uiv
	#define glProgramUniform1uiv                  glad_glProgramUniform1uiv
	#define glMapBufferRange                      glad_glMapBufferRange
	#define glReadBuffer                          glad_glReadBuffer
	#define glTexStorage3D                        glad_glTexStorage3D
	#define glBindImageTexture                    glad_glBindImageTexture
	#define glClientWaitSync                      glad_glClientWaitSync
	#define glProgramUniformMatrix4x2fv           glad_glProgramUniformMatrix4x2fv
	#define glDrawArraysInstanced                 glad_glDrawArraysInstanced
	#define glDeleteProgramPipelines              glad_glDeleteProgramPipelines
	#define glGenerateMipmap                      glad_glGenerateMipmap
	#define glGetMultisamplefv                    glad_glGetMultisamplefv
	#define glGetShaderiv                         glad_glGetShaderiv
	#define glProgramUniformMatrix2fv             glad_glProgramUniformMatrix2fv
	#define glActiveShaderProgram                 glad_glActiveShaderProgram
	#define glProgramUniformMatrix3fv             glad_glProgramUniformMatrix3fv
	#define glUniformMatrix3x4fv                  glad_glUniformMatrix3x4fv
	#define glVertexAttrib3f                      glad_glVertexAttrib3f
	#define glGetActiveAttrib                     glad_glGetActiveAttrib
	#define glBlendColor                          glad_glBlendColor
	#define glGetShaderPrecisionFormat            glad_glGetShaderPrecisionFormat
	#define glResumeTransformFeedback             glad_glResumeTransformFeedback
	#define glUnmapBuffer                         glad_glUnmapBuffer
	#define glDepthMask                           glad_glDepthMask
	#define glUseProgram                          glad_glUseProgram
	#define glProgramUniformMatrix2x4fv           glad_glProgramUniformMatrix2x4fv
	#define glProgramUniform1iv                   glad_glProgramUniform1iv
	#define glCopyBufferSubData                   glad_glCopyBufferSubData
	#define glProgramUniform2iv                   glad_glProgramUniform2iv
	#define glValidateProgramPipeline             glad_glValidateProgramPipeline
	#define glShaderSource                        glad_glShaderSource
	#define glBindRenderbuffer                    glad_glBindRenderbuffer
	#define glDeleteRenderbuffers                 glad_glDeleteRenderbuffers
	#define glIsSync                              glad_glIsSync
	#define glIsTransformFeedback                 glad_glIsTransformFeedback
	#define glDeleteFramebuffers                  glad_glDeleteFramebuffers
	#define glDrawArrays                          glad_glDrawArrays
	#define glUniform1ui                          glad_glUniform1ui
	#define glIsProgram                           glad_glIsProgram
	#define glFramebufferParameteri               glad_glFramebufferParameteri
	#define glTexSubImage2D                       glad_glTexSubImage2D
	#define glGetSynciv                           glad_glGetSynciv
	#define glGetUniformiv                        glad_glGetUniformiv
	#define glUniform4i                           glad_glUniform4i
	#define glVertexAttribFormat                  glad_glVertexAttribFormat
	#define glClear                               glad_glClear
	#define glVertexAttrib4fv                     glad_glVertexAttrib4fv
	#define glProgramParameteri                   glad_glProgramParameteri
	#define glReleaseShaderCompiler               glad_glReleaseShaderCompiler
	#define glProgramUniform2i                    glad_glProgramUniform2i
	#define glUniform2f                           glad_glUniform2f
	#define glMemoryBarrier                       glad_glMemoryBarrier
	#define glActiveTexture                       glad_glActiveTexture
	#define glEnableVertexAttribArray             glad_glEnableVertexAttribArray
	#define glDrawRangeElements                   glad_glDrawRangeElements
	#define glBindBuffer                          glad_glBindBuffer
	#define glIsEnabled                           glad_glIsEnabled
	#define glStencilOp                           glad_glStencilOp
	#define glReadPixels                          glad_glReadPixels
	#define glGetQueryObjectuiv                   glad_glGetQueryObjectuiv
	#define glGetTexLevelParameterfv              glad_glGetTexLevelParameterfv
	#define glBindTransformFeedback               glad_glBindTransformFeedback
	#define glUniform4f                           glad_glUniform4f
	#define glFramebufferTexture2D                glad_glFramebufferTexture2D
	#define glGetFramebufferAttachmentParameteriv glad_glGetFramebufferAttachmentParameteriv
	#define glUniformMatrix2x4fv                  glad_glUniformMatrix2x4fv
	#define glUniform2uiv                         glad_glUniform2uiv
	#define glUniform3fv                          glad_glUniform3fv
	#define glBufferData                          glad_glBufferData
	#define glCompressedTexImage3D                glad_glCompressedTexImage3D
	#define glDrawElementsIndirect                glad_glDrawElementsIndirect
	#define glDeleteSync                          glad_glDeleteSync
	#define glCopyTexSubImage3D                   glad_glCopyTexSubImage3D
	#define glGetFragDataLocation                 glad_glGetFragDataLocation
	#define glGetError                            glad_glGetError
	#define glGetActiveUniformBlockName           glad_glGetActiveUniformBlockName
	#define glGetVertexAttribiv                   glad_glGetVertexAttribiv
	#define glTexParameteriv                      glad_glTexParameteriv
	#define glGetProgramBinary                    glad_glGetProgramBinary
	#define glVertexAttrib3fv                     glad_glVertexAttrib3fv
	#define glGetFloatv                           glad_glGetFloatv
	#define glUniform3iv                          glad_glUniform3iv
	#define glVertexAttrib2fv                     glad_glVertexAttrib2fv
	#define glBindVertexArray                     glad_glBindVertexArray
	#define glGenFramebuffers                     glad_glGenFramebuffers
	#define glDrawBuffers                         glad_glDrawBuffers
	#define glGetProgramResourceLocation          glad_glGetProgramResourceLocation
	#define glGetActiveUniformBlockiv             glad_glGetActiveUniformBlockiv
	#define glVertexAttribBinding                 glad_glVertexAttribBinding
	#define glStencilFunc                         glad_glStencilFunc
	#define glGetIntegerv                         glad_glGetIntegerv
	#define glGetAttachedShaders                  glad_glGetAttachedShaders
	#define glUniformBlockBinding                 glad_glUniformBlockBinding
	#define glIsRenderbuffer                      glad_glIsRenderbuffer
	#define glGetBufferPointerv                   glad_glGetBufferPointerv
	#define glDeleteVertexArrays                  glad_glDeleteVertexArrays
	#define glUniform1fv                          glad_glUniform1fv
	#define glBeginQuery                          glad_glBeginQuery
	#define glRenderbufferStorageMultisample      glad_glRenderbufferStorageMultisample
	#define glProgramUniform3f                    glad_glProgramUniform3f
	#define glUniform4uiv                         glad_glUniform4uiv
	#define glIsQuery                             glad_glIsQuery
	#define glUniformMatrix2fv                    glad_glUniformMatrix2fv
	#define glDisableVertexAttribArray            glad_glDisableVertexAttribArray
	#define glVertexAttribI4iv                    glad_glVertexAttribI4iv
	#define glGetQueryiv                          glad_glGetQueryiv
	#define glTexImage2D                          glad_glTexImage2D
	#define glGetProgramInfoLog                   glad_glGetProgramInfoLog
	#define glGetSamplerParameterfv               glad_glGetSamplerParameterfv
	#define glStencilMask                         glad_glStencilMask
	#define glUniform4ui                          glad_glUniform4ui
	#define glSamplerParameterfv                  glad_glSamplerParameterfv
	#define glProgramUniformMatrix4x3fv           glad_glProgramUniformMatrix4x3fv
	#define glGetShaderInfoLog                    glad_glGetShaderInfoLog
	#define glIsTexture                           glad_glIsTexture
	#define glGetUniformIndices                   glad_glGetUniformIndices
	#define glIsShader                            glad_glIsShader
	#define glDeleteBuffers                       glad_glDeleteBuffers
	#define glGetInteger64v                       glad_glGetInteger64v
	#define glBindProgramPipeline                 glad_glBindProgramPipeline
	#define glVertexAttribPointer                 glad_glVertexAttribPointer
	#define glTexParameterfv                      glad_glTexParameterfv
	#define glInvalidateSubFramebuffer            glad_glInvalidateSubFramebuffer
	#define glUniformMatrix3fv                    glad_glUniformMatrix3fv
	#define glDrawElementsInstanced               glad_glDrawElementsInstanced
	#define glProgramUniform1fv                   glad_glProgramUniform1fv
	#define glEnable                              glad_glEnable
	#define glGetActiveUniformsiv                 glad_glGetActiveUniformsiv
	#define glVertexAttribI4i                     glad_glVertexAttribI4i
	#define glVertexAttribI4ui                    glad_glVertexAttribI4ui
	#define glDeleteQueries                       glad_glDeleteQueries
	#define glMemoryBarrierByRegion               glad_glMemoryBarrierByRegion
	#define glProgramUniform3fv                   glad_glProgramUniform3fv
	#define glBlendEquationSeparate               glad_glBlendEquationSeparate
	#define glGenBuffers                          glad_glGenBuffers
	#define glFinish                              glad_glFinish
	#define glGetAttribLocation                   glad_glGetAttribLocation
	#define glProgramUniform3uiv                  glad_glProgramUniform3uiv
	#define glGetProgramInterfaceiv               glad_glGetProgramInterfaceiv
	#define glDeleteShader                        glad_glDeleteShader
	#define glBlendFunc                           glad_glBlendFunc
	#define glCreateProgram                       glad_glCreateProgram
	#define glTexImage3D                          glad_glTexImage3D
	#define glGenSamplers                         glad_glGenSamplers
	#define glGetSamplerParameteriv               glad_glGetSamplerParameteriv
	#define glIsFramebuffer                       glad_glIsFramebuffer
	#define glProgramUniform2f                    glad_glProgramUniform2f
	#define glFlushMappedBufferRange              glad_glFlushMappedBufferRange
	#define glViewport                            glad_glViewport
	#define glInvalidateFramebuffer               glad_glInvalidateFramebuffer
	#define glUniform1uiv                         glad_glUniform1uiv
	#define glTransformFeedbackVaryings           glad_glTransformFeedbackVaryings
	#define glVertexAttrib2f                      glad_glVertexAttrib2f
	#define glVertexAttrib1f                      glad_glVertexAttrib1f
	#define glVertexBindingDivisor                glad_glVertexBindingDivisor
	#define glUniform2ui                          glad_glUniform2ui
	#define glGetUniformfv                        glad_glGetUniformfv
	#define glGetUniformuiv                       glad_glGetUniformuiv
	#define glProgramUniformMatrix2x3fv           glad_glProgramUniformMatrix2x3fv
	#define glProgramUniform1f                    glad_glProgramUniform1f
	#define glUniformMatrix4fv                    glad_glUniformMatrix4fv
	#define glGetVertexAttribIiv                  glad_glGetVertexAttribIiv
	#define glVertexAttribIFormat                 glad_glVertexAttribIFormat
	#define glGetActiveUniform                    glad_glGetActiveUniform
	#define glBindVertexBuffer                    glad_glBindVertexBuffer
	#define glTexParameterf                       glad_glTexParameterf
	#define glClearBufferfi                       glad_glClearBufferfi
	#define glTexParameteri                       glad_glTexParameteri
	#define glFrontFace                           glad_glFrontFace
	#define glGetProgramPipelineiv                glad_glGetProgramPipelineiv
	#define glClearDepthf                         glad_glClearDepthf
	#define glGetShaderSource                     glad_glGetShaderSource
	#define glSamplerParameteriv                  glad_glSamplerParameteriv
	#define glScissor                             glad_glScissor
	#define glGetBooleanv                         glad_glGetBooleanv
	#define glProgramUniform1i                    glad_glProgramUniform1i
	#define glPixelStorei                         glad_glPixelStorei
	#define glValidateProgram                     glad_glValidateProgram
	#define glPolygonOffset                       glad_glPolygonOffset
	#define glClearBufferuiv                      glad_glClearBufferuiv
	#define glUniform3uiv                         glad_glUniform3uiv
	#define glGetBooleani_v                       glad_glGetBooleani_v
	#define glVertexAttribIPointer                glad_glVertexAttribIPointer
#endif
#define GL_TEXTURE_MAX_ANISOTROPY_EXT           0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT       0x84FF
#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT         0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT        0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT        0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT        0x83F3
#define GL_SLUMINANCE_NV                        0x8C46
#define GL_SLUMINANCE_ALPHA_NV                  0x8C44
#define GL_SRGB8_NV                             0x8C41
#define GL_SLUMINANCE8_NV                       0x8C47
#define GL_SLUMINANCE8_ALPHA8_NV                0x8C45
#define GL_COMPRESSED_SRGB_S3TC_DXT1_NV         0x8C4C
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_NV   0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_NV   0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_NV   0x8C4F
#define GL_ETC1_SRGB8_NV                        0x88EE
#define GL_DEBUG_OUTPUT_SYNCHRONOUS             0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH     0x8243
#define GL_DEBUG_CALLBACK_FUNCTION              0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM            0x8245
#define GL_DEBUG_SOURCE_API                     0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM           0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER         0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY             0x8249
#define GL_DEBUG_SOURCE_APPLICATION             0x824A
#define GL_DEBUG_SOURCE_OTHER                   0x824B
#define GL_DEBUG_TYPE_ERROR                     0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR       0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR        0x824E
#define GL_DEBUG_TYPE_PORTABILITY               0x824F
#define GL_DEBUG_TYPE_PERFORMANCE               0x8250
#define GL_DEBUG_TYPE_OTHER                     0x8251
#define GL_DEBUG_TYPE_MARKER                    0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP                0x8269
#define GL_DEBUG_TYPE_POP_GROUP                 0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION          0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH          0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH              0x826D
#define GL_BUFFER                               0x82E0
#define GL_SHADER                               0x82E1
#define GL_PROGRAM                              0x82E2
#define GL_VERTEX_ARRAY                         0x8074
#define GL_QUERY                                0x82E3
#define GL_PROGRAM_PIPELINE                     0x82E4
#define GL_SAMPLER                              0x82E6
#define GL_MAX_LABEL_LENGTH                     0x82E8
#define GL_MAX_DEBUG_MESSAGE_LENGTH             0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES            0x9144
#define GL_DEBUG_LOGGED_MESSAGES                0x9145
#define GL_DEBUG_SEVERITY_HIGH                  0x9146
#define GL_DEBUG_SEVERITY_MEDIUM                0x9147
#define GL_DEBUG_SEVERITY_LOW                   0x9148
#define GL_DEBUG_OUTPUT                         0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT               0x00000002
#define GL_STACK_OVERFLOW                       0x0503
#define GL_STACK_UNDERFLOW                      0x0504
#define GL_DEBUG_OUTPUT_SYNCHRONOUS_KHR         0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_KHR 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_KHR          0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_KHR        0x8245
#define GL_DEBUG_SOURCE_API_KHR                 0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_KHR       0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_KHR     0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_KHR         0x8249
#define GL_DEBUG_SOURCE_APPLICATION_KHR         0x824A
#define GL_DEBUG_SOURCE_OTHER_KHR               0x824B
#define GL_DEBUG_TYPE_ERROR_KHR                 0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_KHR   0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_KHR    0x824E
#define GL_DEBUG_TYPE_PORTABILITY_KHR           0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_KHR           0x8250
#define GL_DEBUG_TYPE_OTHER_KHR                 0x8251
#define GL_DEBUG_TYPE_MARKER_KHR                0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP_KHR            0x8269
#define GL_DEBUG_TYPE_POP_GROUP_KHR             0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION_KHR      0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH_KHR      0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH_KHR          0x826D
#define GL_BUFFER_KHR                           0x82E0
#define GL_SHADER_KHR                           0x82E1
#define GL_PROGRAM_KHR                          0x82E2
#define GL_VERTEX_ARRAY_KHR                     0x8074
#define GL_QUERY_KHR                            0x82E3
#define GL_PROGRAM_PIPELINE_KHR                 0x82E4
#define GL_SAMPLER_KHR                          0x82E6
#define GL_MAX_LABEL_LENGTH_KHR                 0x82E8
#define GL_MAX_DEBUG_MESSAGE_LENGTH_KHR         0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_KHR        0x9144
#define GL_DEBUG_LOGGED_MESSAGES_KHR            0x9145
#define GL_DEBUG_SEVERITY_HIGH_KHR              0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_KHR            0x9147
#define GL_DEBUG_SEVERITY_LOW_KHR               0x9148
#define GL_DEBUG_OUTPUT_KHR                     0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT_KHR           0x00000002
#define GL_STACK_OVERFLOW_KHR                   0x0503
#define GL_STACK_UNDERFLOW_KHR                  0x0504
#define GL_DISPLAY_LIST                         0x82E7
#define GL_TEXTURE_VIEW_MIN_LEVEL_EXT           0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS_EXT          0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER_EXT           0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS_EXT          0x82DE
#define GL_TEXTURE_BORDER_COLOR_EXT             0x1004
#define GL_CLAMP_TO_BORDER_EXT                  0x812D
#define GL_ACTIVE_PROGRAM_EXT                   0x8B8D
#define GL_VERTEX_SHADER_BIT_EXT                0x00000001
#define GL_FRAGMENT_SHADER_BIT_EXT              0x00000002
#define GL_ALL_SHADER_BITS_EXT                  0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE_EXT                0x8258
#define GL_PROGRAM_PIPELINE_BINDING_EXT         0x825A
#ifndef GL_EXT_texture_filter_anisotropic
	#define GL_EXT_texture_filter_anisotropic     1
GLAPI int GLAD_GL_EXT_texture_filter_anisotropic;
#endif
#ifndef GL_EXT_texture_compression_s3tc
	#define GL_EXT_texture_compression_s3tc 1
GLAPI int GLAD_GL_EXT_texture_compression_s3tc;
#endif
#ifndef GL_NV_sRGB_formats
	#define GL_NV_sRGB_formats 1
GLAPI int GLAD_GL_NV_sRGB_formats;
#endif
#ifndef GL_KHR_debug
	#define GL_KHR_debug 1
GLAPI int GLAD_GL_KHR_debug;
typedef void (APIENTRYP   PFNGLDEBUGMESSAGECONTROLPROC)(GLenum, GLenum, GLenum, GLsizei, const GLuint*, GLboolean);
GLAPI PFNGLDEBUGMESSAGECONTROLPROC glad_glDebugMessageControl;
typedef void (APIENTRYP   PFNGLDEBUGMESSAGEINSERTPROC)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar*);
GLAPI PFNGLDEBUGMESSAGEINSERTPROC glad_glDebugMessageInsert;
typedef void (APIENTRYP   PFNGLDEBUGMESSAGECALLBACKPROC)(GLDEBUGPROC, const void*);
GLAPI PFNGLDEBUGMESSAGECALLBACKPROC glad_glDebugMessageCallback;
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGPROC)(GLuint, GLsizei, GLenum*, GLenum*, GLuint*, GLenum*, GLsizei*, GLchar*);
GLAPI PFNGLGETDEBUGMESSAGELOGPROC glad_glGetDebugMessageLog;
typedef void (APIENTRYP   PFNGLPUSHDEBUGGROUPPROC)(GLenum, GLuint, GLsizei, const GLchar*);
GLAPI PFNGLPUSHDEBUGGROUPPROC glad_glPushDebugGroup;
typedef void (APIENTRYP   PFNGLPOPDEBUGGROUPPROC)();
GLAPI PFNGLPOPDEBUGGROUPPROC glad_glPopDebugGroup;
typedef void (APIENTRYP   PFNGLOBJECTLABELPROC)(GLenum, GLuint, GLsizei, const GLchar*);
GLAPI PFNGLOBJECTLABELPROC glad_glObjectLabel;
typedef void (APIENTRYP   PFNGLGETOBJECTLABELPROC)(GLenum, GLuint, GLsizei, GLsizei*, GLchar*);
GLAPI PFNGLGETOBJECTLABELPROC glad_glGetObjectLabel;
typedef void (APIENTRYP   PFNGLOBJECTPTRLABELPROC)(const void*, GLsizei, const GLchar*);
GLAPI PFNGLOBJECTPTRLABELPROC glad_glObjectPtrLabel;
typedef void (APIENTRYP   PFNGLGETOBJECTPTRLABELPROC)(const void*, GLsizei, GLsizei*, GLchar*);
GLAPI PFNGLGETOBJECTPTRLABELPROC glad_glGetObjectPtrLabel;
typedef void (APIENTRYP   PFNGLGETPOINTERVPROC)(GLenum, void**);
GLAPI PFNGLGETPOINTERVPROC glad_glGetPointerv;
typedef void (APIENTRYP   PFNGLDEBUGMESSAGECONTROLKHRPROC)(GLenum, GLenum, GLenum, GLsizei, const GLuint*, GLboolean);
GLAPI PFNGLDEBUGMESSAGECONTROLKHRPROC glad_glDebugMessageControlKHR;
typedef void (APIENTRYP   PFNGLDEBUGMESSAGEINSERTKHRPROC)(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar*);
GLAPI PFNGLDEBUGMESSAGEINSERTKHRPROC glad_glDebugMessageInsertKHR;
typedef void (APIENTRYP   PFNGLDEBUGMESSAGECALLBACKKHRPROC)(GLDEBUGPROCKHR, const void*);
GLAPI PFNGLDEBUGMESSAGECALLBACKKHRPROC glad_glDebugMessageCallbackKHR;
typedef GLuint (APIENTRYP PFNGLGETDEBUGMESSAGELOGKHRPROC)(GLuint, GLsizei, GLenum*, GLenum*, GLuint*, GLenum*, GLsizei*, GLchar*);
GLAPI PFNGLGETDEBUGMESSAGELOGKHRPROC glad_glGetDebugMessageLogKHR;
typedef void (APIENTRYP   PFNGLPUSHDEBUGGROUPKHRPROC)(GLenum, GLuint, GLsizei, const GLchar*);
GLAPI PFNGLPUSHDEBUGGROUPKHRPROC glad_glPushDebugGroupKHR;
typedef void (APIENTRYP   PFNGLPOPDEBUGGROUPKHRPROC)();
GLAPI PFNGLPOPDEBUGGROUPKHRPROC glad_glPopDebugGroupKHR;
typedef void (APIENTRYP   PFNGLOBJECTLABELKHRPROC)(GLenum, GLuint, GLsizei, const GLchar*);
GLAPI PFNGLOBJECTLABELKHRPROC glad_glObjectLabelKHR;
typedef void (APIENTRYP   PFNGLGETOBJECTLABELKHRPROC)(GLenum, GLuint, GLsizei, GLsizei*, GLchar*);
GLAPI PFNGLGETOBJECTLABELKHRPROC glad_glGetObjectLabelKHR;
typedef void (APIENTRYP   PFNGLOBJECTPTRLABELKHRPROC)(const void*, GLsizei, const GLchar*);
GLAPI PFNGLOBJECTPTRLABELKHRPROC glad_glObjectPtrLabelKHR;
typedef void (APIENTRYP   PFNGLGETOBJECTPTRLABELKHRPROC)(const void*, GLsizei, GLsizei*, GLchar*);
GLAPI PFNGLGETOBJECTPTRLABELKHRPROC glad_glGetObjectPtrLabelKHR;
typedef void (APIENTRYP   PFNGLGETPOINTERVKHRPROC)(GLenum, void**);
GLAPI PFNGLGETPOINTERVKHRPROC glad_glGetPointervKHR;
#endif
#ifndef GL_EXT_texture_view
	#define GL_EXT_texture_view 1
GLAPI int GLAD_GL_EXT_texture_view;
typedef void (APIENTRYP PFNGLTEXTUREVIEWEXTPROC)(GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint);
GLAPI PFNGLTEXTUREVIEWEXTPROC glad_glTextureViewEXT;
#endif
#ifndef GL_EXT_texture_border_clamp
	#define GL_EXT_texture_border_clamp 1
GLAPI int GLAD_GL_EXT_texture_border_clamp;
typedef void (APIENTRYP PFNGLTEXPARAMETERIIVEXTPROC)(GLenum, GLenum, const GLint*);
GLAPI PFNGLTEXPARAMETERIIVEXTPROC glad_glTexParameterIivEXT;
typedef void (APIENTRYP PFNGLTEXPARAMETERIUIVEXTPROC)(GLenum, GLenum, const GLuint*);
GLAPI PFNGLTEXPARAMETERIUIVEXTPROC glad_glTexParameterIuivEXT;
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIIVEXTPROC)(GLenum, GLenum, GLint*);
GLAPI PFNGLGETTEXPARAMETERIIVEXTPROC glad_glGetTexParameterIivEXT;
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIUIVEXTPROC)(GLenum, GLenum, GLuint*);
GLAPI PFNGLGETTEXPARAMETERIUIVEXTPROC glad_glGetTexParameterIuivEXT;
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIIVEXTPROC)(GLuint, GLenum, const GLint*);
GLAPI PFNGLSAMPLERPARAMETERIIVEXTPROC glad_glSamplerParameterIivEXT;
typedef void (APIENTRYP PFNGLSAMPLERPARAMETERIUIVEXTPROC)(GLuint, GLenum, const GLuint*);
GLAPI PFNGLSAMPLERPARAMETERIUIVEXTPROC glad_glSamplerParameterIuivEXT;
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIIVEXTPROC)(GLuint, GLenum, GLint*);
GLAPI PFNGLGETSAMPLERPARAMETERIIVEXTPROC glad_glGetSamplerParameterIivEXT;
typedef void (APIENTRYP PFNGLGETSAMPLERPARAMETERIUIVEXTPROC)(GLuint, GLenum, GLuint*);
GLAPI PFNGLGETSAMPLERPARAMETERIUIVEXTPROC glad_glGetSamplerParameterIuivEXT;
#endif
#ifndef GL_EXT_separate_shader_objects
	#define GL_EXT_separate_shader_objects 1
GLAPI int GLAD_GL_EXT_separate_shader_objects;
typedef void (APIENTRYP      PFNGLUSESHADERPROGRAMEXTPROC)(GLenum, GLuint);
GLAPI PFNGLUSESHADERPROGRAMEXTPROC glad_glUseShaderProgramEXT;
typedef void (APIENTRYP      PFNGLACTIVEPROGRAMEXTPROC)(GLuint);
GLAPI PFNGLACTIVEPROGRAMEXTPROC glad_glActiveProgramEXT;
typedef GLuint (APIENTRYP    PFNGLCREATESHADERPROGRAMEXTPROC)(GLenum, const GLchar*);
GLAPI PFNGLCREATESHADERPROGRAMEXTPROC glad_glCreateShaderProgramEXT;
typedef void (APIENTRYP      PFNGLACTIVESHADERPROGRAMEXTPROC)(GLuint, GLuint);
GLAPI PFNGLACTIVESHADERPROGRAMEXTPROC glad_glActiveShaderProgramEXT;
typedef void (APIENTRYP      PFNGLBINDPROGRAMPIPELINEEXTPROC)(GLuint);
GLAPI PFNGLBINDPROGRAMPIPELINEEXTPROC glad_glBindProgramPipelineEXT;
typedef GLuint (APIENTRYP    PFNGLCREATESHADERPROGRAMVEXTPROC)(GLenum, GLsizei, const GLchar**);
GLAPI PFNGLCREATESHADERPROGRAMVEXTPROC glad_glCreateShaderProgramvEXT;
typedef void (APIENTRYP      PFNGLDELETEPROGRAMPIPELINESEXTPROC)(GLsizei, const GLuint*);
GLAPI PFNGLDELETEPROGRAMPIPELINESEXTPROC glad_glDeleteProgramPipelinesEXT;
typedef void (APIENTRYP      PFNGLGENPROGRAMPIPELINESEXTPROC)(GLsizei, GLuint*);
GLAPI PFNGLGENPROGRAMPIPELINESEXTPROC glad_glGenProgramPipelinesEXT;
typedef void (APIENTRYP      PFNGLGETPROGRAMPIPELINEINFOLOGEXTPROC)(GLuint, GLsizei, GLsizei*, GLchar*);
GLAPI PFNGLGETPROGRAMPIPELINEINFOLOGEXTPROC glad_glGetProgramPipelineInfoLogEXT;
typedef void (APIENTRYP      PFNGLGETPROGRAMPIPELINEIVEXTPROC)(GLuint, GLenum, GLint*);
GLAPI PFNGLGETPROGRAMPIPELINEIVEXTPROC glad_glGetProgramPipelineivEXT;
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPIPELINEEXTPROC)(GLuint);
GLAPI PFNGLISPROGRAMPIPELINEEXTPROC glad_glIsProgramPipelineEXT;
typedef void (APIENTRYP      PFNGLPROGRAMPARAMETERIEXTPROC)(GLuint, GLenum, GLint);
GLAPI PFNGLPROGRAMPARAMETERIEXTPROC glad_glProgramParameteriEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM1FEXTPROC)(GLuint, GLint, GLfloat);
GLAPI PFNGLPROGRAMUNIFORM1FEXTPROC glad_glProgramUniform1fEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM1FVEXTPROC)(GLuint, GLint, GLsizei, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORM1FVEXTPROC glad_glProgramUniform1fvEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM1IEXTPROC)(GLuint, GLint, GLint);
GLAPI PFNGLPROGRAMUNIFORM1IEXTPROC glad_glProgramUniform1iEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM1IVEXTPROC)(GLuint, GLint, GLsizei, const GLint*);
GLAPI PFNGLPROGRAMUNIFORM1IVEXTPROC glad_glProgramUniform1ivEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM2FEXTPROC)(GLuint, GLint, GLfloat, GLfloat);
GLAPI PFNGLPROGRAMUNIFORM2FEXTPROC glad_glProgramUniform2fEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM2FVEXTPROC)(GLuint, GLint, GLsizei, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORM2FVEXTPROC glad_glProgramUniform2fvEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM2IEXTPROC)(GLuint, GLint, GLint, GLint);
GLAPI PFNGLPROGRAMUNIFORM2IEXTPROC glad_glProgramUniform2iEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM2IVEXTPROC)(GLuint, GLint, GLsizei, const GLint*);
GLAPI PFNGLPROGRAMUNIFORM2IVEXTPROC glad_glProgramUniform2ivEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM3FEXTPROC)(GLuint, GLint, GLfloat, GLfloat, GLfloat);
GLAPI PFNGLPROGRAMUNIFORM3FEXTPROC glad_glProgramUniform3fEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM3FVEXTPROC)(GLuint, GLint, GLsizei, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORM3FVEXTPROC glad_glProgramUniform3fvEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM3IEXTPROC)(GLuint, GLint, GLint, GLint, GLint);
GLAPI PFNGLPROGRAMUNIFORM3IEXTPROC glad_glProgramUniform3iEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM3IVEXTPROC)(GLuint, GLint, GLsizei, const GLint*);
GLAPI PFNGLPROGRAMUNIFORM3IVEXTPROC glad_glProgramUniform3ivEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM4FEXTPROC)(GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat);
GLAPI PFNGLPROGRAMUNIFORM4FEXTPROC glad_glProgramUniform4fEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM4FVEXTPROC)(GLuint, GLint, GLsizei, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORM4FVEXTPROC glad_glProgramUniform4fvEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM4IEXTPROC)(GLuint, GLint, GLint, GLint, GLint, GLint);
GLAPI PFNGLPROGRAMUNIFORM4IEXTPROC glad_glProgramUniform4iEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM4IVEXTPROC)(GLuint, GLint, GLsizei, const GLint*);
GLAPI PFNGLPROGRAMUNIFORM4IVEXTPROC glad_glProgramUniform4ivEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC glad_glProgramUniformMatrix2fvEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC glad_glProgramUniformMatrix3fvEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC glad_glProgramUniformMatrix4fvEXT;
typedef void (APIENTRYP      PFNGLUSEPROGRAMSTAGESEXTPROC)(GLuint, GLbitfield, GLuint);
GLAPI PFNGLUSEPROGRAMSTAGESEXTPROC glad_glUseProgramStagesEXT;
typedef void (APIENTRYP      PFNGLVALIDATEPROGRAMPIPELINEEXTPROC)(GLuint);
GLAPI PFNGLVALIDATEPROGRAMPIPELINEEXTPROC glad_glValidateProgramPipelineEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM1UIEXTPROC)(GLuint, GLint, GLuint);
GLAPI PFNGLPROGRAMUNIFORM1UIEXTPROC glad_glProgramUniform1uiEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM2UIEXTPROC)(GLuint, GLint, GLuint, GLuint);
GLAPI PFNGLPROGRAMUNIFORM2UIEXTPROC glad_glProgramUniform2uiEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM3UIEXTPROC)(GLuint, GLint, GLuint, GLuint, GLuint);
GLAPI PFNGLPROGRAMUNIFORM3UIEXTPROC glad_glProgramUniform3uiEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM4UIEXTPROC)(GLuint, GLint, GLuint, GLuint, GLuint, GLuint);
GLAPI PFNGLPROGRAMUNIFORM4UIEXTPROC glad_glProgramUniform4uiEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM1UIVEXTPROC)(GLuint, GLint, GLsizei, const GLuint*);
GLAPI PFNGLPROGRAMUNIFORM1UIVEXTPROC glad_glProgramUniform1uivEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM2UIVEXTPROC)(GLuint, GLint, GLsizei, const GLuint*);
GLAPI PFNGLPROGRAMUNIFORM2UIVEXTPROC glad_glProgramUniform2uivEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM3UIVEXTPROC)(GLuint, GLint, GLsizei, const GLuint*);
GLAPI PFNGLPROGRAMUNIFORM3UIVEXTPROC glad_glProgramUniform3uivEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORM4UIVEXTPROC)(GLuint, GLint, GLsizei, const GLuint*);
GLAPI PFNGLPROGRAMUNIFORM4UIVEXTPROC glad_glProgramUniform4uivEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC glad_glProgramUniformMatrix2x3fvEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC glad_glProgramUniformMatrix3x2fvEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC glad_glProgramUniformMatrix2x4fvEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC glad_glProgramUniformMatrix4x2fvEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC glad_glProgramUniformMatrix3x4fvEXT;
typedef void (APIENTRYP      PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC)(GLuint, GLint, GLsizei, GLboolean, const GLfloat*);
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC glad_glProgramUniformMatrix4x3fvEXT;
#endif
#if defined(__cplusplus) && defined(GLAD_INSTRUMENT_CALL)
struct glad_tag_glGetObjectLabelKHR {};
inline void glad_wrapped_glGetObjectLabelKHR(GLenum _identifier, GLuint _name, GLsizei _bufSize, GLsizei* _length, GLchar* _label) { GLAD_INSTRUMENT_CALL(glGetObjectLabelKHR, _identifier, _name, _bufSize, _length, _label); }
	#define glGetObjectLabelKHR glad_wrapped_glGetObjectLabelKHR
struct glad_tag_glGetDebugMessageLog {};
inline GLuint glad_wrapped_glGetDebugMessageLog(GLuint _count, GLsizei _bufSize, GLenum* _sources, GLenum* _types, GLuint* _ids, GLenum* _severities, GLsizei* _lengths, GLchar* _messageLog) { return GLAD_INSTRUMENT_CALL(glGetDebugMessageLog, _count, _bufSize, _sources, _types, _ids, _severities, _lengths, _messageLog); }
	#define glGetDebugMessageLog glad_wrapped_glGetDebugMessageLog
struct glad_tag_glGetSamplerParameterIuivEXT {};
inline void glad_wrapped_glGetSamplerParameterIuivEXT(GLuint _sampler, GLenum _pname, GLuint* _params) { GLAD_INSTRUMENT_CALL(glGetSamplerParameterIuivEXT, _sampler, _pname, _params); }
	#define glGetSamplerParameterIuivEXT glad_wrapped_glGetSamplerParameterIuivEXT
struct glad_tag_glProgramUniform1uivEXT {};
inline void glad_wrapped_glProgramUniform1uivEXT(GLuint _program, GLint _location, GLsizei _count, const GLuint* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform1uivEXT, _program, _location, _count, _value); }
	#define glProgramUniform1uivEXT glad_wrapped_glProgramUniform1uivEXT
struct glad_tag_glGetTexParameterIivEXT {};
inline void glad_wrapped_glGetTexParameterIivEXT(GLenum _target, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetTexParameterIivEXT, _target, _pname, _params); }
	#define glGetTexParameterIivEXT glad_wrapped_glGetTexParameterIivEXT
struct glad_tag_glObjectLabel {};
inline void glad_wrapped_glObjectLabel(GLenum _identifier, GLuint _name, GLsizei _length, const GLchar* _label) { GLAD_INSTRUMENT_CALL(glObjectLabel, _identifier, _name, _length, _label); }
	#define glObjectLabel glad_wrapped_glObjectLabel
struct glad_tag_glProgramUniform2fvEXT {};
inline void glad_wrapped_glProgramUniform2fvEXT(GLuint _program, GLint _location, GLsizei _count, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform2fvEXT, _program, _location, _count, _value); }
	#define glProgramUniform2fvEXT glad_wrapped_glProgramUniform2fvEXT
struct glad_tag_glGetObjectPtrLabelKHR {};
inline void glad_wrapped_glGetObjectPtrLabelKHR(const void* _ptr, GLsizei _bufSize, GLsizei* _length, GLchar* _label) { GLAD_INSTRUMENT_CALL(glGetObjectPtrLabelKHR, _ptr, _bufSize, _length, _label); }
	#define glGetObjectPtrLabelKHR glad_wrapped_glGetObjectPtrLabelKHR
struct glad_tag_glUseProgramStagesEXT {};
inline void glad_wrapped_glUseProgramStagesEXT(GLuint _pipeline, GLbitfield _stages, GLuint _program) { GLAD_INSTRUMENT_CALL(glUseProgramStagesEXT, _pipeline, _stages, _program); }
	#define glUseProgramStagesEXT glad_wrapped_glUseProgramStagesEXT
struct glad_tag_glProgramUniform4ivEXT {};
inline void glad_wrapped_glProgramUniform4ivEXT(GLuint _program, GLint _location, GLsizei _count, const GLint* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform4ivEXT, _program, _location, _count, _value); }
	#define glProgramUniform4ivEXT glad_wrapped_glProgramUniform4ivEXT
struct glad_tag_glTexParameterIuivEXT {};
inline void glad_wrapped_glTexParameterIuivEXT(GLenum _target, GLenum _pname, const GLuint* _params) { GLAD_INSTRUMENT_CALL(glTexParameterIuivEXT, _target, _pname, _params); }
	#define glTexParameterIuivEXT glad_wrapped_glTexParameterIuivEXT
struct glad_tag_glDebugMessageControlKHR {};
inline void glad_wrapped_glDebugMessageControlKHR(GLenum _source, GLenum _type, GLenum _severity, GLsizei _count, const GLuint* _ids, GLboolean _enabled) { GLAD_INSTRUMENT_CALL(glDebugMessageControlKHR, _source, _type, _severity, _count, _ids, _enabled); }
	#define glDebugMessageControlKHR glad_wrapped_glDebugMessageControlKHR
struct glad_tag_glProgramUniformMatrix4x3fvEXT {};
inline void glad_wrapped_glProgramUniformMatrix4x3fvEXT(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix4x3fvEXT, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix4x3fvEXT glad_wrapped_glProgramUniformMatrix4x3fvEXT
struct glad_tag_glGetObjectPtrLabel {};
inline void glad_wrapped_glGetObjectPtrLabel(const void* _ptr, GLsizei _bufSize, GLsizei* _length, GLchar* _label) { GLAD_INSTRUMENT_CALL(glGetObjectPtrLabel, _ptr, _bufSize, _length, _label); }
	#define glGetObjectPtrLabel glad_wrapped_glGetObjectPtrLabel
struct glad_tag_glObjectLabelKHR {};
inline void glad_wrapped_glObjectLabelKHR(GLenum _identifier, GLuint _name, GLsizei _length, const GLchar* _label) { GLAD_INSTRUMENT_CALL(glObjectLabelKHR, _identifier, _name, _length, _label); }
	#define glObjectLabelKHR glad_wrapped_glObjectLabelKHR
struct glad_tag_glUseShaderProgramEXT {};
inline void glad_wrapped_glUseShaderProgramEXT(GLenum _type, GLuint _program) { GLAD_INSTRUMENT_CALL(glUseShaderProgramEXT, _type, _program); }
	#define glUseShaderProgramEXT glad_wrapped_glUseShaderProgramEXT
struct glad_tag_glTextureViewEXT {};
inline void glad_wrapped_glTextureViewEXT(GLuint _texture, GLenum _target, GLuint _origtexture, GLenum _internalformat, GLuint _minlevel, GLuint _numlevels, GLuint _minlayer, GLuint _numlayers) { GLAD_INSTRUMENT_CALL(glTextureViewEXT, _texture, _target, _origtexture, _internalformat, _minlevel, _numlevels, _minlayer, _numlayers); }
	#define glTextureViewEXT glad_wrapped_glTextureViewEXT
struct glad_tag_glProgramUniform1iEXT {};
inline void glad_wrapped_glProgramUniform1iEXT(GLuint _program, GLint _location, GLint _v0) { GLAD_INSTRUMENT_CALL(glProgramUniform1iEXT, _program, _location, _v0); }
	#define glProgramUniform1iEXT glad_wrapped_glProgramUniform1iEXT
struct glad_tag_glProgramUniformMatrix2x3fvEXT {};
inline void glad_wrapped_glProgramUniformMatrix2x3fvEXT(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix2x3fvEXT, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix2x3fvEXT glad_wrapped_glProgramUniformMatrix2x3fvEXT
struct glad_tag_glProgramUniform3fEXT {};
inline void glad_wrapped_glProgramUniform3fEXT(GLuint _program, GLint _location, GLfloat _v0, GLfloat _v1, GLfloat _v2) { GLAD_INSTRUMENT_CALL(glProgramUniform3fEXT, _program, _location, _v0, _v1, _v2); }
	#define glProgramUniform3fEXT glad_wrapped_glProgramUniform3fEXT
struct glad_tag_glGetObjectLabel {};
inline void glad_wrapped_glGetObjectLabel(GLenum _identifier, GLuint _name, GLsizei _bufSize, GLsizei* _length, GLchar* _label) { GLAD_INSTRUMENT_CALL(glGetObjectLabel, _identifier, _name, _bufSize, _length, _label); }
	#define glGetObjectLabel glad_wrapped_glGetObjectLabel
struct glad_tag_glDebugMessageControl {};
inline void glad_wrapped_glDebugMessageControl(GLenum _source, GLenum _type, GLenum _severity, GLsizei _count, const GLuint* _ids, GLboolean _enabled) { GLAD_INSTRUMENT_CALL(glDebugMessageControl, _source, _type, _severity, _count, _ids, _enabled); }
	#define glDebugMessageControl glad_wrapped_glDebugMessageControl
struct glad_tag_glProgramUniformMatrix3x4fvEXT {};
inline void glad_wrapped_glProgramUniformMatrix3x4fvEXT(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix3x4fvEXT, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix3x4fvEXT glad_wrapped_glProgramUniformMatrix3x4fvEXT
struct glad_tag_glDebugMessageInsert {};
inline void glad_wrapped_glDebugMessageInsert(GLenum _source, GLenum _type, GLuint _id, GLenum _severity, GLsizei _length, const GLchar* _buf) { GLAD_INSTRUMENT_CALL(glDebugMessageInsert, _source, _type, _id, _severity, _length, _buf); }
	#define glDebugMessageInsert glad_wrapped_glDebugMessageInsert
struct glad_tag_glProgramUniform2uivEXT {};
inline void glad_wrapped_glProgramUniform2uivEXT(GLuint _program, GLint _location, GLsizei _count, const GLuint* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform2uivEXT, _program, _location, _count, _value); }
	#define glProgramUniform2uivEXT glad_wrapped_glProgramUniform2uivEXT
struct glad_tag_glProgramUniform4uiEXT {};
inline void glad_wrapped_glProgramUniform4uiEXT(GLuint _program, GLint _location, GLuint _v0, GLuint _v1, GLuint _v2, GLuint _v3) { GLAD_INSTRUMENT_CALL(glProgramUniform4uiEXT, _program, _location, _v0, _v1, _v2, _v3); }
	#define glProgramUniform4uiEXT glad_wrapped_glProgramUniform4uiEXT
struct glad_tag_glProgramUniformMatrix2fvEXT {};
inline void glad_wrapped_glProgramUniformMatrix2fvEXT(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix2fvEXT, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix2fvEXT glad_wrapped_glProgramUniformMatrix2fvEXT
struct glad_tag_glDeleteProgramPipelinesEXT {};
inline void glad_wrapped_glDeleteProgramPipelinesEXT(GLsizei _n, const GLuint* _pipelines) { GLAD_INSTRUMENT_CALL(glDeleteProgramPipelinesEXT, _n, _pipelines); }
	#define glDeleteProgramPipelinesEXT glad_wrapped_glDeleteProgramPipelinesEXT
struct glad_tag_glProgramUniformMatrix4x2fvEXT {};
inline void glad_wrapped_glProgramUniformMatrix4x2fvEXT(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix4x2fvEXT, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix4x2fvEXT glad_wrapped_glProgramUniformMatrix4x2fvEXT
struct glad_tag_glGetProgramPipelineInfoLogEXT {};
inline void glad_wrapped_glGetProgramPipelineInfoLogEXT(GLuint _pipeline, GLsizei _bufSize, GLsizei* _length, GLchar* _infoLog) { GLAD_INSTRUMENT_CALL(glGetProgramPipelineInfoLogEXT, _pipeline, _bufSize, _length, _infoLog); }
	#define glGetProgramPipelineInfoLogEXT glad_wrapped_glGetProgramPipelineInfoLogEXT
struct glad_tag_glSamplerParameterIuivEXT {};
inline void glad_wrapped_glSamplerParameterIuivEXT(GLuint _sampler, GLenum _pname, const GLuint* _param) { GLAD_INSTRUMENT_CALL(glSamplerParameterIuivEXT, _sampler, _pname, _param); }
	#define glSamplerParameterIuivEXT glad_wrapped_glSamplerParameterIuivEXT
struct glad_tag_glProgramUniform4iEXT {};
inline void glad_wrapped_glProgramUniform4iEXT(GLuint _program, GLint _location, GLint _v0, GLint _v1, GLint _v2, GLint _v3) { GLAD_INSTRUMENT_CALL(glProgramUniform4iEXT, _program, _location, _v0, _v1, _v2, _v3); }
	#define glProgramUniform4iEXT glad_wrapped_glProgramUniform4iEXT
struct glad_tag_glGetDebugMessageLogKHR {};
inline GLuint glad_wrapped_glGetDebugMessageLogKHR(GLuint _count, GLsizei _bufSize, GLenum* _sources, GLenum* _types, GLuint* _ids, GLenum* _severities, GLsizei* _lengths, GLchar* _messageLog) { return GLAD_INSTRUMENT_CALL(glGetDebugMessageLogKHR, _count, _bufSize, _sources, _types, _ids, _severities, _lengths, _messageLog); }
	#define glGetDebugMessageLogKHR glad_wrapped_glGetDebugMessageLogKHR
struct glad_tag_glProgramUniformMatrix3fvEXT {};
inline void glad_wrapped_glProgramUniformMatrix3fvEXT(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix3fvEXT, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix3fvEXT glad_wrapped_glProgramUniformMatrix3fvEXT
struct glad_tag_glGetPointervKHR {};
inline void glad_wrapped_glGetPointervKHR(GLenum _pname, void** _params) { GLAD_INSTRUMENT_CALL(glGetPointervKHR, _pname, _params); }
	#define glGetPointervKHR glad_wrapped_glGetPointervKHR
struct glad_tag_glProgramUniformMatrix3x2fvEXT {};
inline void glad_wrapped_glProgramUniformMatrix3x2fvEXT(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix3x2fvEXT, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix3x2fvEXT glad_wrapped_glProgramUniformMatrix3x2fvEXT
struct glad_tag_glProgramUniform2fEXT {};
inline void glad_wrapped_glProgramUniform2fEXT(GLuint _program, GLint _location, GLfloat _v0, GLfloat _v1) { GLAD_INSTRUMENT_CALL(glProgramUniform2fEXT, _program, _location, _v0, _v1); }
	#define glProgramUniform2fEXT glad_wrapped_glProgramUniform2fEXT
struct glad_tag_glProgramUniform3ivEXT {};
inline void glad_wrapped_glProgramUniform3ivEXT(GLuint _program, GLint _location, GLsizei _count, const GLint* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform3ivEXT, _program, _location, _count, _value); }
	#define glProgramUniform3ivEXT glad_wrapped_glProgramUniform3ivEXT
struct glad_tag_glProgramUniform1ivEXT {};
inline void glad_wrapped_glProgramUniform1ivEXT(GLuint _program, GLint _location, GLsizei _count, const GLint* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform1ivEXT, _program, _location, _count, _value); }
	#define glProgramUniform1ivEXT glad_wrapped_glProgramUniform1ivEXT
struct glad_tag_glProgramUniform2uiEXT {};
inline void glad_wrapped_glProgramUniform2uiEXT(GLuint _program, GLint _location, GLuint _v0, GLuint _v1) { GLAD_INSTRUMENT_CALL(glProgramUniform2uiEXT, _program, _location, _v0, _v1); }
	#define glProgramUniform2uiEXT glad_wrapped_glProgramUniform2uiEXT
struct glad_tag_glBindProgramPipelineEXT {};
inline void glad_wrapped_glBindProgramPipelineEXT(GLuint _pipeline) { GLAD_INSTRUMENT_CALL(glBindProgramPipelineEXT, _pipeline); }
	#define glBindProgramPipelineEXT glad_wrapped_glBindProgramPipelineEXT
struct glad_tag_glProgramUniform3uiEXT {};
inline void glad_wrapped_glProgramUniform3uiEXT(GLuint _program, GLint _location, GLuint _v0, GLuint _v1, GLuint _v2) { GLAD_INSTRUMENT_CALL(glProgramUniform3uiEXT, _program, _location, _v0, _v1, _v2); }
	#define glProgramUniform3uiEXT glad_wrapped_glProgramUniform3uiEXT
struct glad_tag_glCreateShaderProgramvEXT {};
inline GLuint glad_wrapped_glCreateShaderProgramvEXT(GLenum _type, GLsizei _count, const GLchar** _strings) { return GLAD_INSTRUMENT_CALL(glCreateShaderProgramvEXT, _type, _count, _strings); }
	#define glCreateShaderProgramvEXT glad_wrapped_glCreateShaderProgramvEXT
struct glad_tag_glDebugMessageCallbackKHR {};
inline void glad_wrapped_glDebugMessageCallbackKHR(GLDEBUGPROCKHR _callback, const void* _userParam) { GLAD_INSTRUMENT_CALL(glDebugMessageCallbackKHR, _callback, _userParam); }
	#define glDebugMessageCallbackKHR glad_wrapped_glDebugMessageCallbackKHR
struct glad_tag_glPushDebugGroup {};
inline void glad_wrapped_glPushDebugGroup(GLenum _source, GLuint _id, GLsizei _length, const GLchar* _message) { GLAD_INSTRUMENT_CALL(glPushDebugGroup, _source, _id, _length, _message); }
	#define glPushDebugGroup glad_wrapped_glPushDebugGroup
struct glad_tag_glProgramUniform1fEXT {};
inline void glad_wrapped_glProgramUniform1fEXT(GLuint _program, GLint _location, GLfloat _v0) { GLAD_INSTRUMENT_CALL(glProgramUniform1fEXT, _program, _location, _v0); }
	#define glProgramUniform1fEXT glad_wrapped_glProgramUniform1fEXT
struct glad_tag_glGetProgramPipelineivEXT {};
inline void glad_wrapped_glGetProgramPipelineivEXT(GLuint _pipeline, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetProgramPipelineivEXT, _pipeline, _pname, _params); }
	#define glGetProgramPipelineivEXT glad_wrapped_glGetProgramPipelineivEXT
struct glad_tag_glProgramUniform4fEXT {};
inline void glad_wrapped_glProgramUniform4fEXT(GLuint _program, GLint _location, GLfloat _v0, GLfloat _v1, GLfloat _v2, GLfloat _v3) { GLAD_INSTRUMENT_CALL(glProgramUniform4fEXT, _program, _location, _v0, _v1, _v2, _v3); }
	#define glProgramUniform4fEXT glad_wrapped_glProgramUniform4fEXT
struct glad_tag_glActiveProgramEXT {};
inline void glad_wrapped_glActiveProgramEXT(GLuint _program) { GLAD_INSTRUMENT_CALL(glActiveProgramEXT, _program); }
	#define glActiveProgramEXT glad_wrapped_glActiveProgramEXT
struct glad_tag_glGetPointerv {};
inline void glad_wrapped_glGetPointerv(GLenum _pname, void** _params) { GLAD_INSTRUMENT_CALL(glGetPointerv, _pname, _params); }
	#define glGetPointerv glad_wrapped_glGetPointerv
struct glad_tag_glProgramUniform2iEXT {};
inline void glad_wrapped_glProgramUniform2iEXT(GLuint _program, GLint _location, GLint _v0, GLint _v1) { GLAD_INSTRUMENT_CALL(glProgramUniform2iEXT, _program, _location, _v0, _v1); }
	#define glProgramUniform2iEXT glad_wrapped_glProgramUniform2iEXT
struct glad_tag_glPushDebugGroupKHR {};
inline void glad_wrapped_glPushDebugGroupKHR(GLenum _source, GLuint _id, GLsizei _length, const GLchar* _message) { GLAD_INSTRUMENT_CALL(glPushDebugGroupKHR, _source, _id, _length, _message); }
	#define glPushDebugGroupKHR glad_wrapped_glPushDebugGroupKHR
struct glad_tag_glGenProgramPipelinesEXT {};
inline void glad_wrapped_glGenProgramPipelinesEXT(GLsizei _n, GLuint* _pipelines) { GLAD_INSTRUMENT_CALL(glGenProgramPipelinesEXT, _n, _pipelines); }
	#define glGenProgramPipelinesEXT glad_wrapped_glGenProgramPipelinesEXT
struct glad_tag_glProgramUniform1uiEXT {};
inline void glad_wrapped_glProgramUniform1uiEXT(GLuint _program, GLint _location, GLuint _v0) { GLAD_INSTRUMENT_CALL(glProgramUniform1uiEXT, _program, _location, _v0); }
	#define glProgramUniform1uiEXT glad_wrapped_glProgramUniform1uiEXT
struct glad_tag_glProgramUniform2ivEXT {};
inline void glad_wrapped_glProgramUniform2ivEXT(GLuint _program, GLint _location, GLsizei _count, const GLint* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform2ivEXT, _program, _location, _count, _value); }
	#define glProgramUniform2ivEXT glad_wrapped_glProgramUniform2ivEXT
struct glad_tag_glDebugMessageCallback {};
inline void glad_wrapped_glDebugMessageCallback(GLDEBUGPROC _callback, const void* _userParam) { GLAD_INSTRUMENT_CALL(glDebugMessageCallback, _callback, _userParam); }
	#define glDebugMessageCallback glad_wrapped_glDebugMessageCallback
struct glad_tag_glDebugMessageInsertKHR {};
inline void glad_wrapped_glDebugMessageInsertKHR(GLenum _source, GLenum _type, GLuint _id, GLenum _severity, GLsizei _length, const GLchar* _buf) { GLAD_INSTRUMENT_CALL(glDebugMessageInsertKHR, _source, _type, _id, _severity, _length, _buf); }
	#define glDebugMessageInsertKHR glad_wrapped_glDebugMessageInsertKHR
struct glad_tag_glPopDebugGroupKHR {};
inline void glad_wrapped_glPopDebugGroupKHR() { GLAD_INSTRUMENT_CALL(glPopDebugGroupKHR); }
	#define glPopDebugGroupKHR glad_wrapped_glPopDebugGroupKHR
struct glad_tag_glActiveShaderProgramEXT {};
inline void glad_wrapped_glActiveShaderProgramEXT(GLuint _pipeline, GLuint _program) { GLAD_INSTRUMENT_CALL(glActiveShaderProgramEXT, _pipeline, _program); }
	#define glActiveShaderProgramEXT glad_wrapped_glActiveShaderProgramEXT
struct glad_tag_glObjectPtrLabel {};
inline void glad_wrapped_glObjectPtrLabel(const void* _ptr, GLsizei _length, const GLchar* _label) { GLAD_INSTRUMENT_CALL(glObjectPtrLabel, _ptr, _length, _label); }
	#define glObjectPtrLabel glad_wrapped_glObjectPtrLabel
struct glad_tag_glValidateProgramPipelineEXT {};
inline void glad_wrapped_glValidateProgramPipelineEXT(GLuint _pipeline) { GLAD_INSTRUMENT_CALL(glValidateProgramPipelineEXT, _pipeline); }
	#define glValidateProgramPipelineEXT glad_wrapped_glValidateProgramPipelineEXT
struct glad_tag_glProgramUniform3fvEXT {};
inline void glad_wrapped_glProgramUniform3fvEXT(GLuint _program, GLint _location, GLsizei _count, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform3fvEXT, _program, _location, _count, _value); }
	#define glProgramUniform3fvEXT glad_wrapped_glProgramUniform3fvEXT
struct glad_tag_glGetTexParameterIuivEXT {};
inline void glad_wrapped_glGetTexParameterIuivEXT(GLenum _target, GLenum _pname, GLuint* _params) { GLAD_INSTRUMENT_CALL(glGetTexParameterIuivEXT, _target, _pname, _params); }
	#define glGetTexParameterIuivEXT glad_wrapped_glGetTexParameterIuivEXT
struct glad_tag_glProgramUniform4uivEXT {};
inline void glad_wrapped_glProgramUniform4uivEXT(GLuint _program, GLint _location, GLsizei _count, const GLuint* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform4uivEXT, _program, _location, _count, _value); }
	#define glProgramUniform4uivEXT glad_wrapped_glProgramUniform4uivEXT
struct glad_tag_glProgramUniform1fvEXT {};
inline void glad_wrapped_glProgramUniform1fvEXT(GLuint _program, GLint _location, GLsizei _count, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform1fvEXT, _program, _location, _count, _value); }
	#define glProgramUniform1fvEXT glad_wrapped_glProgramUniform1fvEXT
struct glad_tag_glObjectPtrLabelKHR {};
inline void glad_wrapped_glObjectPtrLabelKHR(const void* _ptr, GLsizei _length, const GLchar* _label) { GLAD_INSTRUMENT_CALL(glObjectPtrLabelKHR, _ptr, _length, _label); }
	#define glObjectPtrLabelKHR glad_wrapped_glObjectPtrLabelKHR
struct glad_tag_glGetSamplerParameterIivEXT {};
inline void glad_wrapped_glGetSamplerParameterIivEXT(GLuint _sampler, GLenum _pname, GLint* _params) { GLAD_INSTRUMENT_CALL(glGetSamplerParameterIivEXT, _sampler, _pname, _params); }
	#define glGetSamplerParameterIivEXT glad_wrapped_glGetSamplerParameterIivEXT
struct glad_tag_glProgramUniform3uivEXT {};
inline void glad_wrapped_glProgramUniform3uivEXT(GLuint _program, GLint _location, GLsizei _count, const GLuint* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform3uivEXT, _program, _location, _count, _value); }
	#define glProgramUniform3uivEXT glad_wrapped_glProgramUniform3uivEXT
struct glad_tag_glPopDebugGroup {};
inline void glad_wrapped_glPopDebugGroup() { GLAD_INSTRUMENT_CALL(glPopDebugGroup); }
	#define glPopDebugGroup glad_wrapped_glPopDebugGroup
struct glad_tag_glIsProgramPipelineEXT {};
inline GLboolean glad_wrapped_glIsProgramPipelineEXT(GLuint _pipeline) { return GLAD_INSTRUMENT_CALL(glIsProgramPipelineEXT, _pipeline); }
	#define glIsProgramPipelineEXT glad_wrapped_glIsProgramPipelineEXT
struct glad_tag_glProgramUniformMatrix2x4fvEXT {};
inline void glad_wrapped_glProgramUniformMatrix2x4fvEXT(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix2x4fvEXT, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix2x4fvEXT glad_wrapped_glProgramUniformMatrix2x4fvEXT
struct glad_tag_glSamplerParameterIivEXT {};
inline void glad_wrapped_glSamplerParameterIivEXT(GLuint _sampler, GLenum _pname, const GLint* _param) { GLAD_INSTRUMENT_CALL(glSamplerParameterIivEXT, _sampler, _pname, _param); }
	#define glSamplerParameterIivEXT glad_wrapped_glSamplerParameterIivEXT
struct glad_tag_glProgramUniformMatrix4fvEXT {};
inline void glad_wrapped_glProgramUniformMatrix4fvEXT(GLuint _program, GLint _location, GLsizei _count, GLboolean _transpose, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniformMatrix4fvEXT, _program, _location, _count, _transpose, _value); }
	#define glProgramUniformMatrix4fvEXT glad_wrapped_glProgramUniformMatrix4fvEXT
struct glad_tag_glTexParameterIivEXT {};
inline void glad_wrapped_glTexParameterIivEXT(GLenum _target, GLenum _pname, const GLint* _params) { GLAD_INSTRUMENT_CALL(glTexParameterIivEXT, _target, _pname, _params); }
	#define glTexParameterIivEXT glad_wrapped_glTexParameterIivEXT
struct glad_tag_glProgramUniform4fvEXT {};
inline void glad_wrapped_glProgramUniform4fvEXT(GLuint _program, GLint _location, GLsizei _count, const GLfloat* _value) { GLAD_INSTRUMENT_CALL(glProgramUniform4fvEXT, _program, _location, _count, _value); }
	#define glProgramUniform4fvEXT glad_wrapped_glProgramUniform4fvEXT
struct glad_tag_glProgramUniform3iEXT {};
inline void glad_wrapped_glProgramUniform3iEXT(GLuint _program, GLint _location, GLint _v0, GLint _v1, GLint _v2) { GLAD_INSTRUMENT_CALL(glProgramUniform3iEXT, _program, _location, _v0, _v1, _v2); }
	#define glProgramUniform3iEXT glad_wrapped_glProgramUniform3iEXT
struct glad_tag_glProgramParameteriEXT {};
inline void glad_wrapped_glProgramParameteriEXT(GLuint _program, GLenum _pname, GLint _value) { GLAD_INSTRUMENT_CALL(glProgramParameteriEXT, _program, _pname, _value); }
	#define glProgramParameteriEXT glad_wrapped_glProgramParameteriEXT
struct glad_tag_glCreateShaderProgramEXT {};
inline GLuint glad_wrapped_glCreateShaderProgramEXT(GLenum _type, const GLchar* _string) { return GLAD_INSTRUMENT_CALL(glCreateShaderProgramEXT, _type, _string); }
	#define glCreateShaderProgramEXT       glad_wrapped_glCreateShaderProgramEXT
#else
	#define glGetObjectLabelKHR            glad_glGetObjectLabelKHR
	#define glGetDebugMessageLog           glad_glGetDebugMessageLog
	#define glGetSamplerParameterIuivEXT   glad_glGetSamplerParameterIuivEXT
	#define glProgramUniform1uivEXT        glad_glProgramUniform1uivEXT
	#define glGetTexParameterIivEXT        glad_glGetTexParameterIivEXT
	#define glObjectLabel                  glad_glObjectLabel
	#define glProgramUniform2fvEXT         glad_glProgramUniform2fvEXT
	#define glGetObjectPtrLabelKHR         glad_glGetObjectPtrLabelKHR
	#define glUseProgramStagesEXT          glad_glUseProgramStagesEXT
	#define glProgramUniform4ivEXT         glad_glProgramUniform4ivEXT
	#define glTexParameterIuivEXT          glad_glTexParameterIuivEXT
	#define glDebugMessageControlKHR       glad_glDebugMessageControlKHR
	#define glProgramUniformMatrix4x3fvEXT glad_glProgramUniformMatrix4x3fvEXT
	#define glGetObjectPtrLabel            glad_glGetObjectPtrLabel
	#define glObjectLabelKHR               glad_glObjectLabelKHR
	#define glUseShaderProgramEXT          glad_glUseShaderProgramEXT
	#define glTextureViewEXT               glad_glTextureViewEXT
	#define glProgramUniform1iEXT          glad_glProgramUniform1iEXT
	#define glProgramUniformMatrix2x3fvEXT glad_glProgramUniformMatrix2x3fvEXT
	#define glProgramUniform3fEXT          glad_glProgramUniform3fEXT
	#define glGetObjectLabel               glad_glGetObjectLabel
	#define glDebugMessageControl          glad_glDebugMessageControl
	#define glProgramUniformMatrix3x4fvEXT glad_glProgramUniformMatrix3x4fvEXT
	#define glDebugMessageInsert           glad_glDebugMessageInsert
	#define glProgramUniform2uivEXT        glad_glProgramUniform2uivEXT
	#define glProgramUniform4uiEXT         glad_glProgramUniform4uiEXT
	#define glProgramUniformMatrix2fvEXT   glad_glProgramUniformMatrix2fvEXT
	#define glDeleteProgramPipelinesEXT    glad_glDeleteProgramPipelinesEXT
	#define glProgramUniformMatrix4x2fvEXT glad_glProgramUniformMatrix4x2fvEXT
	#define glGetProgramPipelineInfoLogEXT glad_glGetProgramPipelineInfoLogEXT
	#define glSamplerParameterIuivEXT      glad_glSamplerParameterIuivEXT
	#define glProgramUniform4iEXT          glad_glProgramUniform4iEXT
	#define glGetDebugMessageLogKHR        glad_glGetDebugMessageLogKHR
	#define glProgramUniformMatrix3fvEXT   glad_glProgramUniformMatrix3fvEXT
	#define glGetPointervKHR               glad_glGetPointervKHR
	#define glProgramUniformMatrix3x2fvEXT glad_glProgramUniformMatrix3x2fvEXT
	#define glProgramUniform2fEXT          glad_glProgramUniform2fEXT
	#define glProgramUniform3ivEXT         glad_glProgramUniform3ivEXT
	#define glProgramUniform1ivEXT         glad_glProgramUniform1ivEXT
	#define glProgramUniform2uiEXT         glad_glProgramUniform2uiEXT
	#define glBindProgramPipelineEXT       glad_glBindProgramPipelineEXT
	#define glProgramUniform3uiEXT         glad_glProgramUniform3uiEXT
	#define glCreateShaderProgramvEXT      glad_glCreateShaderProgramvEXT
	#define glDebugMessageCallbackKHR      glad_glDebugMessageCallbackKHR
	#define glPushDebugGroup               glad_glPushDebugGroup
	#define glProgramUniform1fEXT          glad_glProgramUniform1fEXT
	#define glGetProgramPipelineivEXT      glad_glGetProgramPipelineivEXT
	#define glProgramUniform4fEXT          glad_glProgramUniform4fEXT
	#define glActiveProgramEXT             glad_glActiveProgramEXT
	#define glGetPointerv                  glad_glGetPointerv
	#define glProgramUniform2iEXT          glad_glProgramUniform2iEXT
	#define glPushDebugGroupKHR            glad_glPushDebugGroupKHR
	#define glGenProgramPipelinesEXT       glad_glGenProgramPipelinesEXT
	#define glProgramUniform1uiEXT         glad_glProgramUniform1uiEXT
	#define glProgramUniform2ivEXT         glad_glProgramUniform2ivEXT
	#define glDebugMessageCallback         glad_glDebugMessageCallback
	#define glDebugMessageInsertKHR        glad_glDebugMessageInsertKHR
	#define glPopDebugGroupKHR             glad_glPopDebugGroupKHR
	#define glActiveShaderProgramEXT       glad_glActiveShaderProgramEXT
	#define glObjectPtrLabel               glad_glObjectPtrLabel
	#define glValidateProgramPipelineEXT   glad_glValidateProgramPipelineEXT
	#define glProgramUniform3fvEXT         glad_glProgramUniform3fvEXT
	#define glGetTexParameterIuivEXT       glad_glGetTexParameterIuivEXT
	#define glProgramUniform4uivEXT        glad_glProgramUniform4uivEXT
	#define glProgramUniform1fvEXT         glad_glProgramUniform1fvEXT
	#define glObjectPtrLabelKHR            glad_glObjectPtrLabelKHR
	#define glGetSamplerParameterIivEXT    glad_glGetSamplerParameterIivEXT
	#define glProgramUniform3uivEXT        glad_glProgramUniform3uivEXT
	#define glPopDebugGroup                glad_glPopDebugGroup
	#define glIsProgramPipelineEXT         glad_glIsProgramPipelineEXT
	#define glProgramUniformMatrix2x4fvEXT glad_glProgramUniformMatrix2x4fvEXT
	#define glSamplerParameterIivEXT       glad_glSamplerParameterIivEXT
	#define glProgramUniformMatrix4fvEXT   glad_glProgramUniformMatrix4fvEXT
	#define glTexParameterIivEXT           glad_glTexParameterIivEXT
	#define glProgramUniform4fvEXT         glad_glProgramUniform4fvEXT
	#define glProgramUniform3iEXT          glad_glProgramUniform3iEXT
	#define glProgramParameteriEXT         glad_glProgramParameteriEXT
	#define glCreateShaderProgramEXT       glad_glCreateShaderProgramEXT
#endif

#ifdef __cplusplus
}
#endif

#endif
