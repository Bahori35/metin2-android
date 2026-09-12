#pragma once

#ifndef __ANDROID__
  #error "This windows.h is only for Android!"
#endif

// Minimum stub for Windows types required by the engine.

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define WIN32_LEAN_AND_MEAN
#ifndef _WIN32
#define _WIN32
#endif

typedef int BOOL;
typedef int32_t LONG;
typedef uint32_t DWORD;
typedef uint16_t WORD;
typedef uint8_t BYTE;
typedef int HANDLE;
typedef void* LPVOID;
typedef const void* LPCVOID;
typedef uint32_t UINT;
typedef int32_t INT;
typedef float FLOAT;
typedef void* HWND;
typedef void* HDC;
typedef void* HGLRC;
typedef void* HMODULE;
typedef void* HINSTANCE;
typedef long LRESULT;
typedef long HRESULT;

#define TRUE 1
#define FALSE 0

#define S_OK 0
#define S_FALSE 1
#define E_FAIL -1
#define E_NOTIMPL -2
#define E_OUTOFMEMORY -3
#define E_INVALIDARG -4
#define E_POINTER -5
#define E_HANDLE -6
#define E_ABORT -7
#define E_ACCESSDENIED -8
#define E_PENDING -9

#define WINAPI
#define CALLBACK
#define __stdcall
#define STDMETHODCALLTYPE

typedef struct _RECT {
  LONG left;
  LONG top;
  LONG right;
  LONG bottom;
} RECT, *PRECT;

typedef struct _POINT {
  LONG x;
  LONG y;
} POINT, *PPOINT;

typedef struct _SIZE {
  LONG cx;
  LONG cy;
} SIZE, *PSIZE;

// D3D types for GrpOpenGL.h
typedef struct _D3DXIMAGE_INFO {
    UINT Width;
    UINT Height;
    UINT Depth;
    UINT MipLevels;
    uint32_t Format;
    uint32_t ResourceType;
    uint32_t ImageFileFormat;
} D3DXIMAGE_INFO;

typedef struct _PALETTEENTRY {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
} PALETTEENTRY;

typedef struct _D3DVIEWPORT8 {
    DWORD       X;
    DWORD       Y;
    DWORD       Width;
    DWORD       Height;
    float       MinZ;
    float       MaxZ;
} D3DVIEWPORT8;

typedef uint32_t D3DCOLOR;
typedef uint32_t D3DFORMAT;
typedef uint32_t D3DPOOL;

#define D3DX_DEFAULT            ((UINT)-1)
#define D3DFMT_A8R8G8B8         21
#define D3DPOOL_MANAGED         1

typedef struct IDirect3DDevice8 *LPDIRECT3DDEVICE8;
typedef struct IDirect3DTexture8 *LPDIRECT3DTEXTURE8;

#ifdef __cplusplus
}
#endif
