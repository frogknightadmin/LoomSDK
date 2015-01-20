/*
 * Copyright 2011-2013 Branimir Karadzic. All rights reserved.
 * License: http://www.opensource.org/licenses/BSD-2-Clause
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#ifndef BGFX_CONFIG_DEBUG
#	define BGFX_CONFIG_DEBUG 0
#endif // BGFX_CONFIG_DEBUG

#if !defined(BGFX_CONFIG_RENDERER_DIRECT3D9) \
	&& !defined(BGFX_CONFIG_RENDERER_DIRECT3D11) \
	&& !defined(BGFX_CONFIG_RENDERER_OPENGL) \
	&& !defined(BGFX_CONFIG_RENDERER_OPENGLES2) \
	&& !defined(BGFX_CONFIG_RENDERER_OPENGLES3) \
	&& !defined(BGFX_CONFIG_RENDERER_NULL)

#	ifndef BGFX_CONFIG_RENDERER_DIRECT3D9
#		define BGFX_CONFIG_RENDERER_DIRECT3D9 (0 \
					| (BX_PLATFORM_WINDOWS && _WIN32_WINNT < 0x0602 /*_WIN32_WINNT_WIN8*/) \
					| BX_PLATFORM_XBOX360 \
					)
#	endif // BGFX_CONFIG_RENDERER_DIRECT3D9

#	ifndef BGFX_CONFIG_RENDERER_DIRECT3D11
#		define BGFX_CONFIG_RENDERER_DIRECT3D11 (0 \
					| (BX_PLATFORM_WINDOWS && _WIN32_WINNT >= 0x0602 /*_WIN32_WINNT_WIN8*/) \
					)
#	endif // BGFX_CONFIG_RENDERER_DIRECT3D11

#	ifndef BGFX_CONFIG_RENDERER_OPENGL
#		define BGFX_CONFIG_RENDERER_OPENGL (0 \
					| BX_PLATFORM_LINUX \
					| BX_PLATFORM_OSX \
					)
#	endif // BGFX_CONFIG_RENDERER_OPENGL

#	ifndef BGFX_CONFIG_RENDERER_OPENGLES2
#		define BGFX_CONFIG_RENDERER_OPENGLES2 (0 \
					| BX_PLATFORM_EMSCRIPTEN \
					| BX_PLATFORM_NACL \
					| BX_PLATFORM_ANDROID \
					| BX_PLATFORM_IOS \
					| BX_PLATFORM_QNX \
					)
#	endif // BGFX_CONFIG_RENDERER_OPENGLES2

#	ifndef BGFX_CONFIG_RENDERER_OPENGLES3
#		define BGFX_CONFIG_RENDERER_OPENGLES3 (0 \
					)
#	endif // BGFX_CONFIG_RENDERER_OPENGLES3

#	ifndef BGFX_CONFIG_RENDERER_NULL
#		define BGFX_CONFIG_RENDERER_NULL (!(0 \
					| BGFX_CONFIG_RENDERER_DIRECT3D9 \
					| BGFX_CONFIG_RENDERER_DIRECT3D11 \
					| BGFX_CONFIG_RENDERER_OPENGL \
					| BGFX_CONFIG_RENDERER_OPENGLES2 \
					| BGFX_CONFIG_RENDERER_OPENGLES3 \
					) )
#	endif // BGFX_CONFIG_RENDERER_NULL
#else
#	ifndef BGFX_CONFIG_RENDERER_DIRECT3D9
#		define BGFX_CONFIG_RENDERER_DIRECT3D9 0
#	endif // BGFX_CONFIG_RENDERER_DIRECT3D9

#	ifndef BGFX_CONFIG_RENDERER_DIRECT3D11
#		define BGFX_CONFIG_RENDERER_DIRECT3D11 0
#	endif // BGFX_CONFIG_RENDERER_DIRECT3D11

#	ifndef BGFX_CONFIG_RENDERER_OPENGL
#		define BGFX_CONFIG_RENDERER_OPENGL 0
#	endif // BGFX_CONFIG_RENDERER_OPENGL

#	ifndef BGFX_CONFIG_RENDERER_OPENGLES2
#		define BGFX_CONFIG_RENDERER_OPENGLES2 0
#	endif // BGFX_CONFIG_RENDERER_OPENGLES2

#	ifndef BGFX_CONFIG_RENDERER_OPENGLES3
#		define BGFX_CONFIG_RENDERER_OPENGLES3 0
#	endif // BGFX_CONFIG_RENDERER_OPENGLES3

#	ifndef BGFX_CONFIG_RENDERER_NULL
#		define BGFX_CONFIG_RENDERER_NULL 0
#	endif // BGFX_CONFIG_RENDERER_NULL
#endif // !defined...

#ifndef BGFX_CONFIG_DEBUG_PERFHUD
#	define BGFX_CONFIG_DEBUG_PERFHUD 0
#endif // BGFX_CONFIG_DEBUG_NVPERFHUD

/// DX9 PIX markers
#ifndef BGFX_CONFIG_DEBUG_PIX
#	define BGFX_CONFIG_DEBUG_PIX BGFX_CONFIG_DEBUG
#endif // BGFX_CONFIG_DEBUG_PIX

/// AMD gDEBugger markers
#ifndef BGFX_CONFIG_DEBUG_GREMEDY
#	define BGFX_CONFIG_DEBUG_GREMEDY 0
#endif // BGFX_CONFIG_DEBUG_GREMEDY

/// DX11 object names
#ifndef BGFX_CONFIG_DEBUG_OBJECT_NAME
#	define BGFX_CONFIG_DEBUG_OBJECT_NAME BGFX_CONFIG_DEBUG
#endif // BGFX_CONFIG_DEBUG_OBJECT_NAME

/*#ifndef BGFX_CONFIG_MULTITHREADED
#	define BGFX_CONFIG_MULTITHREADED ( (!BGFX_CONFIG_RENDERER_NULL)&(0 \
						| BX_PLATFORM_ANDROID \
						| BX_PLATFORM_IOS \
						| BX_PLATFORM_LINUX \
						| BX_PLATFORM_NACL \
						| BX_PLATFORM_OSX \
						| BX_PLATFORM_QNX \
						| BX_PLATFORM_WINDOWS \
						| BX_PLATFORM_XBOX360 \
						) )
#endif // BGFX_CONFIG_MULTITHREADED */
#define BGFX_CONFIG_MULTITHREADED 0

#ifndef BGFX_CONFIG_MAX_DRAW_CALLS
#	define BGFX_CONFIG_MAX_DRAW_CALLS (8<<10)
#endif // BGFX_CONFIG_MAX_DRAW_CALLS

#ifndef BGFX_CONFIG_MAX_MATRIX_CACHE
#	define BGFX_CONFIG_MAX_MATRIX_CACHE (16<<10)
#endif // BGFX_CONFIG_MAX_MATRIX_CACHE

#ifndef BGFX_CONFIG_MAX_RECT_CACHE
#	define BGFX_CONFIG_MAX_RECT_CACHE 512
#endif //  BGFX_CONFIG_MAX_RECT_CACHE

#ifndef BGFX_CONFIG_MAX_VIEWS
#	define BGFX_CONFIG_MAX_VIEWS 32
#endif // BGFX_CONFIG_MAX_VIEWS

#ifndef BGFX_CONFIG_MAX_VERTEX_DECLS
#	define BGFX_CONFIG_MAX_VERTEX_DECLS 64
#endif // BGFX_CONFIG_MAX_VERTEX_DECLS

#ifndef BGFX_CONFIG_MAX_INDEX_BUFFERS
#	define BGFX_CONFIG_MAX_INDEX_BUFFERS (4<<10)
#endif // BGFX_CONFIG_MAX_INDEX_BUFFERS

#ifndef BGFX_CONFIG_MAX_VERTEX_BUFFERS
#	define BGFX_CONFIG_MAX_VERTEX_BUFFERS (4<<10)
#endif // BGFX_CONFIG_MAX_VERTEX_BUFFERS

#ifndef BGFX_CONFIG_MAX_DYNAMIC_INDEX_BUFFERS
#	define BGFX_CONFIG_MAX_DYNAMIC_INDEX_BUFFERS (4<<10)
#endif // BGFX_CONFIG_MAX_DYNAMIC_INDEX_BUFFERS

#ifndef BGFX_CONFIG_MAX_DYNAMIC_VERTEX_BUFFERS
#	define BGFX_CONFIG_MAX_DYNAMIC_VERTEX_BUFFERS (4<<10)
#endif // BGFX_CONFIG_MAX_DYNAMIC_VERTEX_BUFFERS

#ifndef BGFX_CONFIG_DYNAMIC_INDEX_BUFFER_SIZE
#	define BGFX_CONFIG_DYNAMIC_INDEX_BUFFER_SIZE (1<<20)
#endif // BGFX_CONFIG_DYNAMIC_INDEX_BUFFER_SIZE

#ifndef BGFX_CONFIG_DYNAMIC_VERTEX_BUFFER_SIZE
#	define BGFX_CONFIG_DYNAMIC_VERTEX_BUFFER_SIZE (3<<20)
#endif // BGFX_CONFIG_DYNAMIC_VERTEX_BUFFER_SIZE

#ifndef BGFX_CONFIG_MAX_VERTEX_SHADERS
#	define BGFX_CONFIG_MAX_VERTEX_SHADERS 256
#endif // BGFX_CONFIG_MAX_VERTEX_SHADERS

#ifndef BGFX_CONFIG_MAX_FRAGMENT_SHADERS
#	define BGFX_CONFIG_MAX_FRAGMENT_SHADERS 256
#endif // BGFX_CONFIG_MAX_FRAGMENT_SHADERS

#ifndef BGFX_CONFIG_MAX_PROGRAMS
#	define BGFX_CONFIG_MAX_PROGRAMS 512
#endif // BGFX_CONFIG_MAX_PROGRAMS

#ifndef BGFX_CONFIG_MAX_PROGRAMS
#	define BGFX_CONFIG_MAX_PROGRAMS (4<<10)
#endif // BGFX_CONFIG_MAX_PROGRAMS

#ifndef BGFX_CONFIG_MAX_TEXTURES
#	define BGFX_CONFIG_MAX_TEXTURES (4<<10)
#endif // BGFX_CONFIG_MAX_TEXTURES

#ifndef BGFX_CONFIG_MAX_RENDER_TARGETS
#	define BGFX_CONFIG_MAX_RENDER_TARGETS 64
#endif // BGFX_CONFIG_MAX_RENDER_TARGETS

#ifndef BGFX_CONFIG_MAX_UNIFORMS
#	define BGFX_CONFIG_MAX_UNIFORMS 512
#endif // BGFX_CONFIG_MAX_CONSTANTS

#ifndef BGFX_CONFIG_MAX_COMMAND_BUFFER_SIZE
#	define BGFX_CONFIG_MAX_COMMAND_BUFFER_SIZE (64<<10)
#endif // BGFX_CONFIG_MAX_COMMAND_BUFFER_SIZE

#ifndef BGFX_CONFIG_TRANSIENT_VERTEX_BUFFER_SIZE
#	define BGFX_CONFIG_TRANSIENT_VERTEX_BUFFER_SIZE (6<<20)
#endif // BGFX_CONFIG_TRANSIENT_VERTEX_BUFFER_SIZE

#ifndef BGFX_CONFIG_TRANSIENT_INDEX_BUFFER_SIZE
#	define BGFX_CONFIG_TRANSIENT_INDEX_BUFFER_SIZE (2<<20)
#endif // BGFX_CONFIG_TRANSIENT_INDEX_BUFFER_SIZE

#ifndef BGFX_CONFIG_MAX_CONSTANT_BUFFER_SIZE
#	define BGFX_CONFIG_MAX_CONSTANT_BUFFER_SIZE (512<<10)
#endif // BGFX_CONFIG_MAX_CONSTANT_BUFFER_SIZE

#ifndef BGFX_CONFIG_USE_TINYSTL
#	define BGFX_CONFIG_USE_TINYSTL 0
#endif // BGFX_CONFIG_USE_TINYSTL

#ifndef BGFX_CONFIG_MAX_INSTANCE_DATA_COUNT
#	define BGFX_CONFIG_MAX_INSTANCE_DATA_COUNT 5
#endif // BGFX_CONFIG_MAX_INSTANCE_DATA_COUNT

#ifndef BGFX_CONFIG_CLEAR_QUAD
#	define BGFX_CONFIG_CLEAR_QUAD (BGFX_CONFIG_RENDERER_DIRECT3D11|BGFX_CONFIG_RENDERER_OPENGL)
#endif // BGFX_CONFIG_CLEAR_QUAD

#endif // __CONFIG_H__