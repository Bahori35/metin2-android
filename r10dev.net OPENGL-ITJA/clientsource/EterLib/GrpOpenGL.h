#pragma once

// OpenGL Headers for Mobile (GLES2 default for high compatibility)
#ifdef ANDROID
    #include <GLES2/gl2.h>
    #include <GLES2/gl2ext.h>
#else
    #include <GL/gl.h>
    #include <GL/glext.h>
#endif

#include <math.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

#ifndef HRESULT
typedef long HRESULT;
#endif
#ifndef S_OK
#define S_OK ((HRESULT)0L)
#endif
#ifndef S_FALSE
#define S_FALSE ((HRESULT)1L)
#endif
#ifndef FAILED
#define FAILED(hr) (((HRESULT)(hr)) < 0)
#endif
#ifndef SUCCEEDED
#define SUCCEEDED(hr) (((HRESULT)(hr)) >= 0)
#endif

#include <stdint.h>

#ifndef CONST
#define CONST const
#endif

typedef uint32_t UINT;
typedef uint32_t DWORD;
typedef uint8_t BYTE;
typedef uint16_t WORD;
typedef int32_t LONG;
typedef int BOOL;
typedef uint32_t ULONG;
typedef const void* LPCVOID;
typedef void* LPVOID;
typedef const char* LPCSTR;
typedef char* LPSTR;

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#ifndef _WIN32
typedef void* HWND;
typedef void* HDC;
typedef void* HGLRC;
#endif

#ifndef _RECT_DEFINED
#define _RECT_DEFINED
#ifndef RECT
typedef struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT, *PRECT, *LPRECT;
#endif
#endif

#ifndef _POINT_DEFINED
#define _POINT_DEFINED
#ifndef POINT
typedef struct tagPOINT {
    LONG x;
    LONG y;
} POINT, *PPOINT, *LPPOINT;
#endif
#endif

#ifndef SIZE
typedef struct tagSIZE {
    LONG cx;
    LONG cy;
} SIZE, *PSIZE, *LPSIZE;
#endif

#ifndef PALETTEENTRY
typedef struct tagPALETTEENTRY {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
} PALETTEENTRY;
#endif

// D3D Enum Types Stubbed
typedef int D3DFORMAT;
typedef int D3DPRIMITIVETYPE;
typedef int D3DDEVTYPE;
typedef int D3DTEXTUREOP;
typedef int D3DRENDERSTATETYPE;
typedef int D3DTEXTURESTAGESTATETYPE;
typedef int D3DBLEND;
typedef int D3DCMPFUNC;
typedef int D3DCULL;
typedef int D3DLIGHTSTATETYPE;
typedef int D3DCOLORVALUE;
typedef int D3DFILLMODE;
typedef int D3DMULTISAMPLE_TYPE;
typedef int D3DTRANSFORMSTATETYPE;
typedef int D3DBACKBUFFER_TYPE;

#define D3DX_DEFAULT ((UINT)-1)
#define D3DX_DEFAULT_NONPOW2 ((UINT)-2)

#define D3DFMT_UNKNOWN 0
#define D3DFMT_R8G8B8 1
#define D3DFMT_A8R8G8B8 21
#define D3DFMT_X8R8G8B8 22
#define D3DFMT_A4R4G4B4 4
#define D3DFMT_A1R5G5B5 5
#define D3DFMT_X1R5G5B5 6
#define D3DFMT_A16B16G16R16 7
#define D3DFMT_DXT1 8
#define D3DFMT_DXT3 9
#define D3DFMT_DXT5 10
#define D3DFMT_D16 80
#define D3DFMT_D15S1 12
#define D3DFMT_D24X8 13
#define D3DFMT_D24S8 14
#define D3DFMT_D24X4S4 15
#define D3DFMT_D32 16
#define D3DFMT_INDEX16 17
#define D3DFMT_R5G6B5 18

#define D3DPOOL_MANAGED 1
#define D3DPOOL_SYSTEMMEM 2
#define D3DPOOL_DEFAULT 3
#define D3DPOOL_SCRATCH 4
typedef int D3DPOOL;

#define D3DX_FILTER_NONE 1
#define D3DX_FILTER_LINEAR 2

#define D3DTS_WORLD 1
#define D3DTS_VIEW 2
#define D3DTS_PROJECTION 3

#define D3DCLEAR_TARGET 1
#define D3DCLEAR_ZBUFFER 2

#define D3DFVF_XYZ 0x002
#define D3DFVF_XYZRHW 0x004
#define D3DFVF_NORMAL 0x010
#define D3DFVF_DIFFUSE 0x040
#define D3DFVF_SPECULAR 0x080
#define D3DFVF_TEX1 0x100
#define D3DFVF_TEX2 0x200
#define D3DFVF_TEXCOUNT_MASK 0xf00
#define D3DFVF_TEXCOUNT_SHIFT 8

#define D3DRS_ZENABLE 7
#define D3DRS_FILLMODE 8
#define D3DRS_SHADEMODE 9
#define D3DRS_ZWRITEENABLE 14
#define D3DRS_ALPHATESTENABLE 15
#define D3DRS_SRCBLEND 19
#define D3DRS_DESTBLEND 20
#define D3DRS_CULLMODE 22
#define D3DRS_ZFUNC 23
#define D3DRS_ALPHAREF 24
#define D3DRS_ALPHAFUNC 25
#define D3DRS_ALPHABLENDENABLE 27
#define D3DRS_LIGHTING 137
#define D3DRS_TEXTUREFACTOR 60
#define D3DTSS_COLORARG1 1
#define D3DTSS_COLORARG2 2
#define D3DTSS_COLOROP 3
#define D3DTSS_ALPHAARG1 4
#define D3DTSS_ALPHAARG2 5
#define D3DTSS_ALPHAOP 6
#define D3DTSS_MINFILTER 7
#define D3DTSS_MAGFILTER 8
#define D3DTSS_MIPFILTER 9
#define D3DTSS_ADDRESSU 10
#define D3DTSS_ADDRESSV 11

#define D3DPT_POINTLIST 1
#define D3DPT_LINELIST 2
#define D3DPT_LINESTRIP 3
#define D3DPT_TRIANGLELIST 4
#define D3DPT_TRIANGLESTRIP 5
#define D3DPT_TRIANGLEFAN 6

typedef struct _D3DLOCKED_RECT {
    int Pitch;
    void* pBits;
} D3DLOCKED_RECT;

#define D3DTA_TFACTOR 1
#define D3DTA_TEXTURE 2
#define D3DTA_CURRENT 3
#define D3DTA_DIFFUSE 4

#define D3DTOP_SELECTARG1 1
#define D3DTOP_DISABLE 2
#define D3DTOP_MODULATE 3
#define D3DTOP_ADD 4

#define D3DBLEND_INVDESTCOLOR 1
#define D3DBLEND_ONE 2
#define D3DBLEND_ZERO 3
#define D3DBLEND_SRCCOLOR 4
#define D3DBLEND_SRCALPHA 5
#define D3DBLEND_INVSRCALPHA 6

#define D3DCULL_CCW 1
#define D3DCULL_CW 2
#define D3DCULL_NONE 3

#define D3DFILL_SOLID 1
#define D3DFILL_WIREFRAME 2

#define D3DLIGHT_POINT 1
#define D3DSHADE_FLAT 1

#define D3DCMP_LESSEQUAL 1

#define D3DTEXF_POINT 1
#define D3DTADDRESS_CLAMP 1

#define D3DLOCK_READONLY 1
#define D3DLOCK_NO_DIRTY_UPDATE 2
#define D3DLOCK_DISCARD 3
#define D3DUSAGE_WRITEONLY 1
#define D3DUSAGE_DYNAMIC 2
#define D3DUSAGE_DEPTHSTENCIL 3
#define D3DUSAGE_RENDERTARGET 4

#define D3D_OK 0
#define D3DERR_DEVICELOST 1
#define D3DERR_DEVICENOTRESET 2
#define D3DERR_INVALIDCALL 3
#define D3DERR_NOTAVAILABLE 4
#define D3DERR_OUTOFVIDEOMEMORY 5
#define D3DERR_WASSTILLDRAWING 6

#define D3DADAPTER_DEFAULT 0
#define D3DSWAPEFFECT_COPY 1
#define D3DSWAPEFFECT_DISCARD 2
#define D3DPRESENT_INTERVAL_IMMEDIATE 1
#define D3DPRESENTFLAG_LOCKABLE_BACKBUFFER 1
#define D3DENUM_NO_WHQL_LEVEL 1

#define D3DCREATE_PUREDEVICE 1
#define D3DCREATE_HARDWARE_VERTEXPROCESSING 2
#define D3DCREATE_MIXED_VERTEXPROCESSING 3
#define D3DCREATE_SOFTWARE_VERTEXPROCESSING 4

#define D3DRTYPE_SURFACE 1
#define D3DRTYPE_TEXTURE 2
#define D3DMULTISAMPLE_NONE 0

#define D3DDEVICETYPE_HAL 1
#define D3DDEVICETYPE_REF 2

#define D3DPMISCCAPS_CLIPTLVERTS 1
#define D3DVTXPCAPS_DIRECTIONALLIGHTS 1
#define D3DVTXPCAPS_POSITIONALLIGHTS 2
#define D3DVTXPCAPS_TEXGEN 3
#define D3DCAPS2_CANRENDERWINDOWED 1
#define D3DDEVCAPS_HWTRANSFORMANDLIGHT 1
#define D3DDEVCAPS_PUREDEVICE 2

#define D3DRS_FOGENABLE 0
#define D3DTSS_TEXTURETRANSFORMFLAGS 0
#define D3DTS_TEXTURE0 0
#define D3DRS_DIFFUSEMATERIALSOURCE 0
#define D3DRS_SPECULARMATERIALSOURCE 0
#define D3DRS_AMBIENTMATERIALSOURCE 0
#define D3DRS_EMISSIVEMATERIALSOURCE 0
#define D3DRS_LINEPATTERN 0
#define D3DRS_LASTPIXEL 0
#define D3DRS_ALPHAREF 0
#define D3DRS_ALPHAFUNC 0
#define D3DRS_ZVISIBLE 0
#define D3DRS_FOGSTART 0
#define D3DRS_FOGEND 0
#define D3DRS_FOGDENSITY 0
#define D3DRS_EDGEANTIALIAS 0
#define D3DRS_ZBIAS 0
#define D3DRS_STENCILWRITEMASK 0
#define D3DRS_AMBIENT 0
#define D3DRS_LOCALVIEWER 0
#define D3DRS_NORMALIZENORMALS 0
#define D3DRS_VERTEXBLEND 0
#define D3DRS_CLIPPLANEENABLE 0
#define D3DRS_SOFTWAREVERTEXPROCESSING 0
#define D3DRS_MULTISAMPLEANTIALIAS 0
#define D3DRS_MULTISAMPLEMASK 0
#define D3DRS_INDEXEDVERTEXBLENDENABLE 0
#define D3DRS_COLORWRITEENABLE 0
#define D3DRS_BLENDOP 0
#define D3DRS_POSITIONDEGREE 0
#define D3DRS_NORMALDEGREE 0
#define D3DRS_SCISSORTESTENABLE 0
#define D3DRS_SLOPESCALEDEPTHBIAS 0
#define D3DRS_ANTIALIASEDLINEENABLE 0
#define D3DRS_MINTESSELLATIONLEVEL 0
#define D3DRS_MAXTESSELLATIONLEVEL 0
#define D3DRS_ADAPTIVETESS_X 0
#define D3DRS_ADAPTIVETESS_Y 0
#define D3DRS_ADAPTIVETESS_Z 0
#define D3DRS_ADAPTIVETESS_W 0
#define D3DRS_ENABLEADAPTIVETESSELLATION 0
#define D3DRS_TWOSIDEDSTENCILMODE 0
#define D3DRS_CCW_STENCILFAIL 0
#define D3DRS_CCW_STENCILZFAIL 0
#define D3DRS_CCW_STENCILPASS 0
#define D3DRS_CCW_STENCILFUNC 0
#define D3DRS_COLORWRITEENABLE1 0
#define D3DRS_COLORWRITEENABLE2 0
#define D3DRS_COLORWRITEENABLE3 0
#define D3DRS_BLENDFACTOR 0
#define D3DRS_SRGBWRITEENABLE 0
#define D3DRS_DEPTHBIAS 0
#define D3DRS_WRAP8 0
#define D3DRS_WRAP9 0
#define D3DRS_WRAP10 0
#define D3DRS_WRAP11 0
#define D3DRS_WRAP12 0
#define D3DRS_WRAP13 0
#define D3DRS_WRAP14 0
#define D3DRS_WRAP15 0
#define D3DRS_SEPARATEALPHABLENDENABLE 0
#define D3DRS_SRCBLENDALPHA 0
#define D3DRS_DESTBLENDALPHA 0
#define D3DRS_BLENDOPALPHA 0
#define D3DRS_FOGCOLOR 0
#define D3DRS_FOGTABLEMODE 0
#define D3DRS_FOGVERTEXMODE 0
#define D3DRS_RANGEFOGENABLE 0
#define D3DRS_DITHERENABLE 0
#define D3DRS_STENCILENABLE 0
#define D3DRS_CLIPPING 0
#define D3DRS_SPECULARENABLE 0
#define D3DRS_COLORVERTEX 0
#define D3DRS_WRAP0 0
#define D3DRS_WRAP2 0
#define D3DRS_WRAP3 0
#define D3DRS_WRAP4 0
#define D3DRS_WRAP5 0
#define D3DRS_WRAP6 0
#define D3DRS_WRAP7 0
#define D3DTSS_TEXCOORDINDEX 0
#define D3DDEVTYPE_HAL 1
#define D3DDEVTYPE_REF 2
#define D3DPTADDRESSCAPS_BORDER 0x00000080
#define D3DDEVCAPS_HWTRANSFORMANDLIGHT 0x00000010
#define D3DDEVCAPS_PUREDEVICE 0x00000010
#define D3DCAPS2_CANRENDERWINDOWED 0x00080000
#define D3DPMISCCAPS_CLIPTLVERTS 0x00000100
#define D3DVTXPCAPS_DIRECTIONALLIGHTS 0x00000008
#define D3DVTXPCAPS_POSITIONALLIGHTS 0x00000010
#define D3DVTXPCAPS_TEXGEN 0x00000040

#define D3DVS_VERSION(major, minor) (0)
#define D3D_SDK_VERSION 0
#define D3DX_PI 3.141592654f
#define D3DXToRadian( degree ) ((degree) * (D3DX_PI / 180.0f))
#define D3DXToDegree( radian ) ((radian) * (180.0f / D3DX_PI))

struct D3DVIEWPORT8 {
    DWORD X, Y, Width, Height;
    float MinZ, MaxZ;
};

struct D3DCAPS8 {
    DWORD TextureCaps;
    DWORD MaxTextureWidth, MaxTextureHeight;
    DWORD DevCaps;
    DWORD Caps2;
    DWORD VertexProcessingCaps;
    DWORD PrimitiveMiscCaps;
    DWORD TextureAddressCaps;
};

struct D3DPRESENT_PARAMETERS {
    UINT BackBufferWidth, BackBufferHeight;
    int Windowed;
};

struct D3DADAPTER_IDENTIFIER8 {
    char Driver[512];
    char Description[512];
};

struct D3DDISPLAYMODE {
    UINT Width, Height, RefreshRate;
    D3DFORMAT Format;
};

struct D3DXIMAGE_INFO {
    UINT Width;
    UINT Height;
    UINT Depth;
    UINT MipLevels;
    int Format;
    int ResourceType;
    int ImageFileFormat;
};

// Simple D3DX Math simulation for OpenGL
struct GLMATRIX {
    float m[4][4];
    
    GLMATRIX() {
        memset(m, 0, sizeof(m));
        m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.0f;
    }
};

struct GLVECTOR3 {
    float x, y, z;
    
    GLVECTOR3() : x(0), y(0), z(0) {}
    GLVECTOR3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    
    GLVECTOR3 operator+(const GLVECTOR3& rhs) const { return GLVECTOR3(x+rhs.x, y+rhs.y, z+rhs.z); }
    GLVECTOR3 operator*(float s) const { return GLVECTOR3(x*s, y*s, z*s); }
};

inline GLVECTOR3 operator*(float s, const GLVECTOR3& v) {
    return GLVECTOR3(v.x * s, v.y * s, v.z * s);
}

inline GLVECTOR3* D3DXVec3Normalize(GLVECTOR3* pOut, const GLVECTOR3* pV) {
    float len = sqrtf(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z);
    if (len > 0.0f) {
        pOut->x = pV->x / len;
        pOut->y = pV->y / len;
        pOut->z = pV->z / len;
    } else {
        pOut->x = pOut->y = pOut->z = 0.0f;
    }
    return pOut;
}

struct GLVECTOR2 {
    float x, y;
};

struct GLCOLOR {
    float r, g, b, a;
};

struct GLVECTOR4 { float x, y, z, w; };
struct GLQUATERNION { float x, y, z, w; };
struct GLPLANE { float a, b, c, d; };

inline float D3DXVec3Dot(const GLVECTOR3* pV1, const GLVECTOR3* pV2) {
    return pV1->x*pV2->x + pV1->y*pV2->y + pV1->z*pV2->z;
}
inline GLVECTOR3* D3DXVec3Cross(GLVECTOR3* pOut, const GLVECTOR3* pV1, const GLVECTOR3* pV2) {
    pOut->x = pV1->y * pV2->z - pV1->z * pV2->y;
    pOut->y = pV1->z * pV2->x - pV1->x * pV2->z;
    pOut->z = pV1->x * pV2->y - pV1->y * pV2->x;
    return pOut;
}
inline float D3DXVec3LengthSq(const GLVECTOR3* pV) {
    return pV->x*pV->x + pV->y*pV->y + pV->z*pV->z;
}
inline float D3DXVec3Length(const GLVECTOR3* pV) {
    return sqrtf(D3DXVec3LengthSq(pV));
}
inline float D3DXVec2Length(const GLVECTOR2* pV) {
    return sqrtf(pV->x*pV->x + pV->y*pV->y);
}
inline float D3DXVec2Dot(const GLVECTOR2* pV1, const GLVECTOR2* pV2) {
    return pV1->x*pV2->x + pV1->y*pV2->y;
}
inline GLVECTOR2* D3DXVec2Normalize(GLVECTOR2* pOut, const GLVECTOR2* pV) {
    float len = D3DXVec2Length(pV);
    if (len > 0) { pOut->x = pV->x/len; pOut->y = pV->y/len; }
    else { pOut->x = pOut->y = 0; }
    return pOut;
}
inline GLVECTOR3* D3DXVec3TransformCoord(GLVECTOR3* pOut, const GLVECTOR3* pV, const GLMATRIX* pM) {
    *pOut = *pV; // stub
    return pOut;
}
inline GLMATRIX* D3DXMatrixIdentity(GLMATRIX* pOut) {
    memset(pOut->m, 0, sizeof(pOut->m));
    pOut->m[0][0] = pOut->m[1][1] = pOut->m[2][2] = pOut->m[3][3] = 1.0f;
    return pOut;
}
inline GLMATRIX* D3DXMatrixInverse(GLMATRIX* pOut, float* pDeterminant, const GLMATRIX* pM) {
    *pOut = *pM; // temporary
    return pOut;
}
inline GLMATRIX* D3DXMatrixMultiply(GLMATRIX* pOut, const GLMATRIX* pM1, const GLMATRIX* pM2) {
    GLMATRIX out;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            out.m[i][j] = pM1->m[i][0] * pM2->m[0][j] + pM1->m[i][1] * pM2->m[1][j] +
                          pM1->m[i][2] * pM2->m[2][j] + pM1->m[i][3] * pM2->m[3][j];
        }
    }
    *pOut = out;
    return pOut;
}
inline GLMATRIX* D3DXMatrixTranslation(GLMATRIX* pOut, float x, float y, float z) {
    D3DXMatrixIdentity(pOut);
    pOut->m[3][0] = x; pOut->m[3][1] = y; pOut->m[3][2] = z;
    return pOut;
}
inline GLMATRIX* D3DXMatrixScaling(GLMATRIX* pOut, float x, float y, float z) {
    D3DXMatrixIdentity(pOut);
    pOut->m[0][0] = x; pOut->m[1][1] = y; pOut->m[2][2] = z;
    return pOut;
}
inline GLMATRIX* D3DXMatrixRotationX(GLMATRIX* pOut, float angle) {
    float s = sinf(angle), c = cosf(angle);
    D3DXMatrixIdentity(pOut);
    pOut->m[1][1] = c; pOut->m[1][2] = s;
    pOut->m[2][1] = -s; pOut->m[2][2] = c;
    return pOut;
}
inline GLMATRIX* D3DXMatrixRotationY(GLMATRIX* pOut, float angle) {
    float s = sinf(angle), c = cosf(angle);
    D3DXMatrixIdentity(pOut);
    pOut->m[0][0] = c; pOut->m[0][2] = -s;
    pOut->m[2][0] = s; pOut->m[2][2] = c;
    return pOut;
}
inline GLMATRIX* D3DXMatrixRotationZ(GLMATRIX* pOut, float angle) {
    float s = sinf(angle), c = cosf(angle);
    D3DXMatrixIdentity(pOut);
    pOut->m[0][0] = c; pOut->m[0][1] = s;
    pOut->m[1][0] = -s; pOut->m[1][1] = c;
    return pOut;
}
inline GLMATRIX* D3DXMatrixRotationQuaternion(GLMATRIX* pOut, const GLQUATERNION* pQ) { return D3DXMatrixIdentity(pOut); }
inline GLQUATERNION* D3DXQuaternionMultiply(GLQUATERNION* pOut, const GLQUATERNION* pQ1, const GLQUATERNION* pQ2) { *pOut = *pQ1; return pOut; }
inline GLQUATERNION* D3DXQuaternionConjugate(GLQUATERNION* pOut, const GLQUATERNION* pQ) { *pOut = *pQ; return pOut; }
inline GLVECTOR3* D3DXVec3Rotation(GLVECTOR3* pOut, const GLVECTOR3* pV, const GLQUATERNION* pQ) { *pOut = *pV; return pOut; }
inline GLVECTOR3* D3DXVec3Translation(GLVECTOR3* pOut, const GLVECTOR3* pV, const GLMATRIX* pM) { *pOut = *pV; return pOut; }
inline float D3DXPlaneDotCoord(const GLPLANE* pP, const GLVECTOR3* pV) { return 0.0f; }
inline float D3DXMatrixfDeterminant(const GLMATRIX* pM) { return 1.0f; }
inline GLMATRIX* D3DXMatrixLookAtRH(GLMATRIX* pOut, const GLVECTOR3* pEye, const GLVECTOR3* pAt, const GLVECTOR3* pUp) {
    GLVECTOR3 f, s, u;
    GLVECTOR3 tmp(pAt->x - pEye->x, pAt->y - pEye->y, pAt->z - pEye->z);
    D3DXVec3Normalize(&f, &tmp);
    D3DXVec3Cross(&s, &f, pUp);
    D3DXVec3Normalize(&s, &s);
    D3DXVec3Cross(&u, &s, &f);

    D3DXMatrixIdentity(pOut);
    pOut->m[0][0] = s.x; pOut->m[1][0] = s.y; pOut->m[2][0] = s.z;
    pOut->m[0][1] = u.x; pOut->m[1][1] = u.y; pOut->m[2][1] = u.z;
    pOut->m[0][2] = -f.x; pOut->m[1][2] = -f.y; pOut->m[2][2] = -f.z;
    pOut->m[3][0] = -D3DXVec3Dot(&s, pEye);
    pOut->m[3][1] = -D3DXVec3Dot(&u, pEye);
    pOut->m[3][2] = D3DXVec3Dot(&f, pEye);
    return pOut;
}
inline GLMATRIX* D3DXMatrixPerspectiveFovRH(GLMATRIX* pOut, float fovy, float Aspect, float zn, float zf) {
    float h = 1.0f / tanf(fovy / 2.0f);
    float w = h / Aspect;
    D3DXMatrixIdentity(pOut);
    pOut->m[0][0] = w;
    pOut->m[1][1] = h;
    pOut->m[2][2] = zf / (zn - zf);
    pOut->m[2][3] = -1.0f;
    pOut->m[3][2] = (zn * zf) / (zn - zf);
    pOut->m[3][3] = 0.0f;
    return pOut;
}
inline GLMATRIX* D3DXMatrixOrthoRH(GLMATRIX* pOut, float w, float h, float zn, float zf) {
    D3DXMatrixIdentity(pOut);
    pOut->m[0][0] = 2.0f / w;
    pOut->m[1][1] = 2.0f / h;
    pOut->m[2][2] = 1.0f / (zn - zf);
    pOut->m[3][2] = zn / (zn - zf);
    return pOut;
}
inline GLMATRIX* D3DXMatrixOrthoOffCenterRH(GLMATRIX* pOut, float l, float r, float b, float t, float zn, float zf) { 
    D3DXMatrixIdentity(pOut);
    if (r != l) pOut->m[0][0] = 2.0f / (r - l);
    if (t != b) pOut->m[1][1] = 2.0f / (t - b);
    if (zn != zf) {
        pOut->m[2][2] = 1.0f / (zn - zf);
        pOut->m[3][2] = zn / (zn - zf);
    }
    if (r != l) pOut->m[3][0] = (l + r) / (l - r);
    if (t != b) pOut->m[3][1] = (t + b) / (b - t);
    return pOut; 
}
inline HRESULT D3DXGetImageInfoFromFileInMemory(LPCVOID pSrcData, UINT SrcDataSize, D3DXIMAGE_INFO* pSrcInfo) {
    if (pSrcInfo) {
        pSrcInfo->Width = 256; pSrcInfo->Height = 256; pSrcInfo->Format = D3DFMT_A8R8G8B8;
    }
    return S_OK;
}
inline GLMATRIX* D3DXMatrixRotationAxis(GLMATRIX* pOut, const GLVECTOR3* pV, float angle) { return D3DXMatrixIdentity(pOut); }
inline GLMATRIX* D3DXMatrixRotationYawPitchRoll(GLMATRIX* pOut, float y, float p, float r) {
    GLMATRIX my, mp, mr;
    D3DXMatrixRotationY(&my, y);
    D3DXMatrixRotationX(&mp, p);
    D3DXMatrixRotationZ(&mr, r);
    D3DXMatrixMultiply(pOut, &mr, &mp);
    D3DXMatrixMultiply(pOut, pOut, &my);
    return pOut;
}
inline GLVECTOR3* D3DXVec3Project(GLVECTOR3* pOut, const GLVECTOR3* pV, const D3DVIEWPORT8* pViewport, const GLMATRIX* pProjection, const GLMATRIX* pView, const GLMATRIX* pWorld) {
    GLMATRIX mat;
    D3DXMatrixMultiply(&mat, pWorld, pView);
    D3DXMatrixMultiply(&mat, &mat, pProjection);
    *pOut = *pV; 
    return pOut;
}
inline GLVECTOR3* D3DXVec3Unproject(GLVECTOR3* pOut, const GLVECTOR3* pV, const D3DVIEWPORT8* pViewport, const GLMATRIX* pProjection, const GLMATRIX* pView, const GLMATRIX* pWorld) {
    *pOut = *pV;
    return pOut;
}
inline GLQUATERNION* D3DXQuaternionBlend(GLQUATERNION* pOut, const GLQUATERNION* pQ1, const GLQUATERNION* pQ2, float t) { *pOut = *pQ1; return pOut; }
inline GLVECTOR3* D3DXVec3Blend(GLVECTOR3* pOut, const GLVECTOR3* pV1, const GLVECTOR3* pV2, float t) { *pOut = *pV1; return pOut; }
inline GLVECTOR2* D3DXVec2CCW(GLVECTOR2* pOut, const GLVECTOR2* pV) { *pOut = *pV; return pOut; }

#ifdef ENABLE_OPENGL
    #define D3DXMATRIX GLMATRIX
    #define D3DXVECTOR3 GLVECTOR3
    #define D3DVECTOR GLVECTOR3
    #define D3DXVECTOR2 GLVECTOR2
    #define D3DCOLOR GLCOLOR
    #define D3DXCOLOR GLCOLOR
    
    struct GL_LIGHT {
        int Type;
        GLCOLOR Diffuse;
        GLCOLOR Specular;
        GLCOLOR Ambient;
        GLVECTOR3 Position;
        GLVECTOR3 Direction;
        float Range;
        float Falloff;
        float Attenuation0;
        float Attenuation1;
        float Attenuation2;
        float Theta;
        float Phi;
    };
    #define D3DLIGHT8 GL_LIGHT
    
    struct GL_MATERIAL {
        GLCOLOR Diffuse;
        GLCOLOR Ambient;
        GLCOLOR Specular;
        GLCOLOR Emissive;
        float Power;
    };
    #define D3DMATERIAL8 GL_MATERIAL
    
    #define D3DXQUATERNION GLQUATERNION
    #define D3DXPLANE GLPLANE
    #define D3DXVECTOR4 GLVECTOR4

    struct IDirect3D8;
    struct IDirect3DDevice8;
    struct IDirect3DTexture8;
    struct IDirect3DSurface8;
    struct IDirect3DBaseTexture8;
    struct IDirect3DVertexBuffer8;
    struct IDirect3DIndexBuffer8;
    struct ID3DXBuffer;
    struct ID3DXMesh;

    typedef IDirect3D8* LPDIRECT3D8;
    typedef IDirect3DDevice8* LPDIRECT3DDEVICE8;
    typedef IDirect3DTexture8* LPDIRECT3DTEXTURE8;
    typedef IDirect3DBaseTexture8* LPDIRECT3DBaseTexture8;
    typedef IDirect3DSurface8* LPDIRECT3DSURFACE8;
    typedef IDirect3DVertexBuffer8* LPDIRECT3DVERTEXBUFFER8; // VBO
    typedef IDirect3DIndexBuffer8* LPDIRECT3DINDEXBUFFER8; // IBO/EBO
    typedef ID3DXMesh* LPD3DXMESH;
    typedef ID3DXBuffer* LPD3DXBUFFER;
    typedef void* LPD3DXMATRIXSTACK;

    #define D3DCOLOR_XRGB(r,g,b) GLCOLOR{ (r)/255.f, (g)/255.f, (b)/255.f, 1.0f }
    #define D3DCOLOR_ARGB(a,r,g,b) GLCOLOR{ (r)/255.f, (g)/255.f, (b)/255.f, (a)/255.f }

    #define D3DVSD_STREAM(s) (s)
    #define D3DVSD_REG(r, t) (r)
    #define D3DVSD_END() 0
    #define D3DVSDT_FLOAT3 0
    #define D3DVSDT_FLOAT2 0
    #define D3DVSDE_TEXCOORD1 0
    #define D3DVSDE_POSITION2 0
    #define D3DVSDE_NORMAL2 0

    // DirectInput Stubs
    typedef void* LPDIRECTINPUT8;
    typedef void* LPDIRECTINPUTDEVICE8;
    #define DIRECTINPUT_VERSION 0x0800
    #define IID_IDirectInput8 (void*)0
    #define GUID_SysKeyboard (void*)0
    #define DISCL_FOREGROUND 0
    #define DISCL_EXCLUSIVE 0
    #define DISCL_NONEXCLUSIVE 0
    #define DISCL_BACKGROUND 0
    #define SAFE_RELEASE(p) if(p) { p = NULL; }
    inline int DirectInput8Create(void*, int, void*, void**, void*) { return 0; }
    struct IDirectInputDevice8 {
        int SetDataFormat(void*) { return 0; }
        int SetCooperativeLevel(void*, int) { return 0; }
        int Acquire() { return 0; }
        int Unacquire() { return 0; }
        int GetDeviceState(int, void*) { return 0; }
        void Release() {}
    };
    extern void* c_dfDIKeyboard;

    struct IDirect3DTexture8 {
        GLuint glId;
        int width, height;
        void* pLockedData;
        IDirect3DTexture8() : glId(0), width(0), height(0), pLockedData(NULL) {}
        HRESULT LockRect(UINT Level,D3DLOCKED_RECT* pLockedRect,const RECT* pRect,DWORD Flags) { 
            if (!pLockedData) pLockedData = malloc(width * height * 4);
            pLockedRect->pBits = pLockedData;
            pLockedRect->Pitch = width * 4;
            return S_OK; 
        }
        HRESULT UnlockRect(UINT Level) { 
            if (glId && pLockedData) {
                glBindTexture(GL_TEXTURE_2D, glId);
                glTexSubImage2D(GL_TEXTURE_2D, Level, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pLockedData);
            }
            return S_OK; 
        }
        ULONG Release() { 
            if (glId) glDeleteTextures(1, &glId);
            if (pLockedData) free(pLockedData);
            delete this;
            return 0; 
        }
        HRESULT GetSurfaceLevel(UINT,LPDIRECT3DSURFACE8*) { return S_OK; }
    };

    struct IDirect3DSurface8 {
        ULONG Release() { return 0; }
    };
    struct IDirect3DBaseTexture8 {
        ULONG Release() { return 0; }
    };
    struct IDirect3DVertexBuffer8 {
        GLuint glVbo;
        UINT length;
        void* pData;
        IDirect3DVertexBuffer8(UINT len) : glVbo(0), length(len), pData(NULL) {
            glGenBuffers(1, &glVbo);
            pData = malloc(len);
        }
        HRESULT Lock(UINT OffsetToLock, UINT SizeToLock, BYTE** ppbData, DWORD Flags) { 
            *ppbData = (BYTE*)pData + OffsetToLock;
            return S_OK; 
        }
        HRESULT Unlock() { 
            glBindBuffer(GL_ARRAY_BUFFER, glVbo);
            glBufferData(GL_ARRAY_BUFFER, length, pData, GL_STATIC_DRAW);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            return S_OK; 
        }
        ULONG Release() { 
            if (glVbo) glDeleteBuffers(1, &glVbo);
            if (pData) free(pData);
            delete this;
            return 0; 
        }
    };
    struct IDirect3DIndexBuffer8 {
        GLuint glIbo;
        UINT length;
        void* pData;
        IDirect3DIndexBuffer8(UINT len) : glIbo(0), length(len), pData(NULL) {
            glGenBuffers(1, &glIbo);
            pData = malloc(len);
        }
        HRESULT Lock(UINT OffsetToLock, UINT SizeToLock, BYTE** ppbData, DWORD Flags) { 
            *ppbData = (BYTE*)pData + OffsetToLock;
            return S_OK; 
        }
        HRESULT Unlock() { 
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glIbo);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, length, pData, GL_STATIC_DRAW);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            return S_OK; 
        }
        ULONG Release() { 
            if (glIbo) glDeleteBuffers(1, &glIbo);
            if (pData) free(pData);
            delete this;
            return 0; 
        }
    };
    struct ID3DXMatrixStack {
        std::vector<GLMATRIX> m_stack;
        ID3DXMatrixStack() { m_stack.push_back(GLMATRIX()); }
        
        HRESULT Push() { m_stack.push_back(m_stack.back()); return S_OK; }
        HRESULT Pop() { if (m_stack.size() > 1) m_stack.pop_back(); return S_OK; }
        HRESULT LoadIdentity() { D3DXMatrixIdentity(&m_stack.back()); return S_OK; }
        HRESULT LoadMatrix(const GLMATRIX* pMat) { m_stack.back() = *pMat; return S_OK; }
        HRESULT MultMatrix(const GLMATRIX* pMat) { D3DXMatrixMultiply(&m_stack.back(), &m_stack.back(), pMat); return S_OK; }
        HRESULT MultMatrixLocal(const GLMATRIX* pMat) { D3DXMatrixMultiply(&m_stack.back(), pMat, &m_stack.back()); return S_OK; }
        HRESULT Scale(float x, float y, float z) { 
            GLMATRIX s; D3DXMatrixScaling(&s, x, y, z);
            MultMatrix(&s); return S_OK; 
        }
        HRESULT Translate(float x, float y, float z) {
            GLMATRIX t; D3DXMatrixTranslation(&t, x, y, z);
            MultMatrix(&t); return S_OK;
        }
        HRESULT RotateAxis(const GLVECTOR3* pV, float angle) {
            return S_OK;
        }
        HRESULT RotateAxisLocal(const GLVECTOR3* pV, float angle) {
            return S_OK;
        }
        HRESULT RotateYawPitchRollLocal(float y, float p, float r) {
            GLMATRIX m; D3DXMatrixRotationYawPitchRoll(&m, y, p, r);
            MultMatrixLocal(&m); return S_OK;
        }
        GLMATRIX* GetTop() { return &m_stack.back(); }
        ULONG Release() { delete this; return 0; }
    };

    struct ID3DXBuffer {
        void* GetBufferPointer() { return 0; }
        DWORD GetBufferSize() { return 0; }
        ULONG Release() { delete this; return 0; }
    };
    struct ID3DXMesh {
        HRESULT GetIndexBuffer(LPDIRECT3DINDEXBUFFER8*) { return S_OK; }
        HRESULT GetVertexBuffer(LPDIRECT3DVERTEXBUFFER8*) { return S_OK; }
        DWORD GetFVF() { return 0; }
        DWORD GetNumVertices() { return 0; }
        DWORD GetNumFaces() { return 0; }
        ULONG Release() { return 0; }
    };

    struct IDirect3D8 {
        UINT GetAdapterCount() { return 1; }
        HRESULT GetAdapterIdentifier(UINT, DWORD, D3DADAPTER_IDENTIFIER8* pIdentifier) {
            if (pIdentifier) {
                strcpy(pIdentifier->Driver, "OpenGL Generic");
                strcpy(pIdentifier->Description, "OpenGL Port");
            }
            return S_OK;
        }
        UINT GetAdapterModeCount(UINT) { return 1; }
        HRESULT EnumAdapterModes(UINT, UINT, D3DDISPLAYMODE* pMode) {
            if (pMode) { pMode->Width = 1024; pMode->Height = 768; pMode->RefreshRate = 60; pMode->Format = D3DFMT_X8R8G8B8; }
            return S_OK;
        }
        HRESULT GetAdapterDisplayMode(UINT, D3DDISPLAYMODE* pMode) {
            if (pMode) { pMode->Width = 1024; pMode->Height = 768; pMode->RefreshRate = 60; pMode->Format = D3DFMT_X8R8G8B8; }
            return S_OK;
        }
        HRESULT CheckDeviceType(UINT, D3DDEVTYPE, D3DFORMAT, D3DFORMAT, BOOL) { return S_OK; }
        HRESULT CheckDeviceFormat(UINT, int, int, DWORD, int, int) { return S_OK; }
        HRESULT CheckDepthStencilMatch(UINT, int, int, int, int) { return S_OK; }
        HRESULT GetDeviceCaps(UINT, int, D3DCAPS8* pCaps) {
            if (pCaps) {
                memset(pCaps, 0, sizeof(D3DCAPS8));
                pCaps->MaxTextureWidth = 8192;
                pCaps->MaxTextureHeight = 8192;
                pCaps->DevCaps = D3DDEVCAPS_HWTRANSFORMANDLIGHT;
                pCaps->Caps2 = D3DCAPS2_CANRENDERWINDOWED;
                pCaps->VertexProcessingCaps = D3DVTXPCAPS_DIRECTIONALLIGHTS | D3DVTXPCAPS_POSITIONALLIGHTS | D3DVTXPCAPS_TEXGEN;
                pCaps->PrimitiveMiscCaps = D3DPMISCCAPS_CLIPTLVERTS;
                pCaps->TextureAddressCaps = D3DPTADDRESSCAPS_BORDER;
            }
            return S_OK;
        }
        HRESULT CreateDevice(UINT, int, HWND hWnd, DWORD, D3DPRESENT_PARAMETERS*, IDirect3DDevice8** ppDevice);
        ULONG Release() { delete this; return 0; }
    };

    struct IDirect3DDevice8 {
#ifndef ANDROID
        HDC m_hDC;
#endif
        IDirect3DDevice8() {
#ifndef ANDROID
            m_hDC = NULL;
#endif
        }
        HRESULT CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, LPDIRECT3DTEXTURE8* ppTexture) { 
            IDirect3DTexture8* tex = new IDirect3DTexture8();
            tex->width = Width;
            tex->height = Height;
            glGenTextures(1, &tex->glId);
            glBindTexture(GL_TEXTURE_2D, tex->glId);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            *ppTexture = tex;
            return S_OK; 
        }
        HRESULT SetLight(DWORD,const void*) { return S_OK; }
        HRESULT LightEnable(DWORD,BOOL) { return S_OK; }
        DWORD m_dwFVF;
        HRESULT GetVertexShader(DWORD* pShader) { *pShader = m_dwFVF; return S_OK; }
        HRESULT SetVertexShader(DWORD Shader) { m_dwFVF = Shader; return S_OK; }
        HRESULT CreateVertexShader(const DWORD* pDeclaration, const DWORD* pFunction, DWORD* pHandle, DWORD Usage) { *pHandle = 1; return S_OK; }
        HRESULT DeleteVertexShader(DWORD Handle) { return S_OK; }
        HRESULT CreatePixelShader(const DWORD* pFunction, DWORD* pHandle) { *pHandle = 2; return S_OK; }
        HRESULT DeletePixelShader(DWORD Handle) { return S_OK; }
        HRESULT SetPixelShader(DWORD Handle) { return S_OK; }
        HRESULT SetVertexShaderConstant(DWORD Register, const void* pData, DWORD Count) { return S_OK; }
        HRESULT SetPixelShaderConstant(DWORD Register, const void* pData, DWORD Count) { return S_OK; }
        HRESULT Clear(DWORD n, const void* pRects, DWORD flags, D3DCOLOR color, float z, DWORD stencil) { 
            GLbitfield mask = 0;
            if (flags & 1) { // D3DCLEAR_TARGET
                glClearColor(color.r, color.g, color.b, color.a);
                mask |= GL_COLOR_BUFFER_BIT;
            }
            if (flags & 2) { // D3DCLEAR_ZBUFFER
                #ifndef ANDROID
                    glClearDepth(z);
                #else
                    glClearDepthf(z);
                #endif
                mask |= GL_DEPTH_BUFFER_BIT;
            }
            if (mask) glClear(mask);
            return S_OK; 
        }
        HRESULT TestCooperativeLevel() { return S_OK; }
        HRESULT Reset(D3DPRESENT_PARAMETERS*) { return S_OK; }
        HRESULT Present(const RECT*,const RECT*,HWND,const void*) { 
#ifndef ANDROID
            if (m_hDC) SwapBuffers(m_hDC);
#endif
            return S_OK; 
        }
        HRESULT CreateDepthStencilSurface(UINT,UINT,D3DFORMAT,D3DMULTISAMPLE_TYPE,LPDIRECT3DSURFACE8*) { return S_OK; }
        HRESULT GetRenderTarget(LPDIRECT3DSURFACE8*) { return S_OK; }
        HRESULT GetDepthStencilSurface(LPDIRECT3DSURFACE8*) { return S_OK; }
        HRESULT GetViewport(D3DVIEWPORT8*) { return S_OK; }
        HRESULT SetRenderTarget(LPDIRECT3DSURFACE8,LPDIRECT3DSURFACE8) { return S_OK; }
        HRESULT SetViewport(const D3DVIEWPORT8* v) { 
            glViewport(v->X, v->Y, v->Width, v->Height);
            return S_OK; 
        }
        HRESULT BeginScene() { return S_OK; }
        HRESULT EndScene() { return S_OK; }
        HRESULT GetDeviceCaps(D3DCAPS8*) { return S_OK; }
        void SetGammaRamp(DWORD,DWORD,const void*) {}
        HRESULT GetBackBuffer(UINT,D3DBACKBUFFER_TYPE,LPDIRECT3DSURFACE8*) { return S_OK; }
        UINT GetAvailableTextureMem() { return 128 * 1024 * 1024; }
        LPDIRECT3DVERTEXBUFFER8 m_pStreamSource;
        UINT m_StreamStride;
        HRESULT SetStreamSource(UINT StreamNumber, LPDIRECT3DVERTEXBUFFER8 pStreamData, UINT Stride) { 
            m_pStreamSource = pStreamData;
            m_StreamStride = Stride;
            if (pStreamData) glBindBuffer(GL_ARRAY_BUFFER, pStreamData->glVbo);
            else glBindBuffer(GL_ARRAY_BUFFER, 0);
            return S_OK; 
        }
        HRESULT CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, LPDIRECT3DVERTEXBUFFER8* ppVertexBuffer) { 
            *ppVertexBuffer = new IDirect3DVertexBuffer8(Length);
            return S_OK; 
        }
        HRESULT CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, LPDIRECT3DINDEXBUFFER8* ppIndexBuffer) { 
            *ppIndexBuffer = new IDirect3DIndexBuffer8(Length);
            return S_OK; 
        }
        LPDIRECT3DINDEXBUFFER8 m_pIndexBuffer;
        HRESULT SetIndices(LPDIRECT3DINDEXBUFFER8 pIndexBuffer, UINT BaseVertexIndex) {
            m_pIndexBuffer = pIndexBuffer;
            if (pIndexBuffer) glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pIndexBuffer->glIbo);
            else glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            return S_OK;
        }
        HRESULT DrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT minIndex, UINT NumVertices, UINT startIndex, UINT primCount) {
            GLenum mode = GL_TRIANGLES;
            GLsizei count = 0;
            switch(PrimitiveType) {
                case 1: mode = GL_POINTS; count = (GLsizei)primCount; break;
                case 2: mode = GL_LINES; count = (GLsizei)primCount * 2; break;
                case 3: mode = GL_LINE_STRIP; count = (GLsizei)primCount + 1; break;
                case 4: mode = GL_TRIANGLES; count = (GLsizei)primCount * 3; break;
                case 5: mode = GL_TRIANGLE_STRIP; count = (GLsizei)primCount + 2; break;
                case 6: mode = GL_TRIANGLE_FAN; count = (GLsizei)primCount + 2; break;
            }
            
            #ifndef ANDROID
            glEnableClientState(GL_VERTEX_ARRAY);
            
            int offset = 0;
            // Position (XYZ)
            glVertexPointer(3, GL_FLOAT, (GLsizei)m_StreamStride, (void*)(size_t)offset);
            offset += 12; 

            if (m_dwFVF & D3DFVF_XYZRHW) {
            }

            if (m_dwFVF & D3DFVF_NORMAL) {
                glEnableClientState(GL_NORMAL_ARRAY);
                glNormalPointer(GL_FLOAT, (GLsizei)m_StreamStride, (void*)(size_t)offset);
                offset += 12;
            } else {
                glDisableClientState(GL_NORMAL_ARRAY);
            }

            if (m_dwFVF & D3DFVF_DIFFUSE) {
                glEnableClientState(GL_COLOR_ARRAY);
                glColorPointer(4, GL_UNSIGNED_BYTE, (GLsizei)m_StreamStride, (void*)(size_t)offset);
                offset += 4;
            } else {
                glDisableClientState(GL_COLOR_ARRAY);
            }

            if (m_dwFVF & D3DFVF_SPECULAR) {
                offset += 4;
            }

            // Texture Coordinates
            int numTex = (m_dwFVF & D3DFVF_TEXCOUNT_MASK) >> D3DFVF_TEXCOUNT_SHIFT;
            if (numTex > 0) {
                glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                glTexCoordPointer(2, GL_FLOAT, (GLsizei)m_StreamStride, (void*)(size_t)offset);
                offset += 8 * numTex;
            } else if (m_dwFVF & D3DFVF_TEX1) {
                glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                glTexCoordPointer(2, GL_FLOAT, (GLsizei)m_StreamStride, (void*)(size_t)offset);
                offset += 8;
            } else {
                glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            }
            
            glDrawElements(mode, count, GL_UNSIGNED_SHORT, (void*)(size_t)(startIndex * 2));
            
            glDisableClientState(GL_VERTEX_ARRAY);
            glDisableClientState(GL_NORMAL_ARRAY);
            glDisableClientState(GL_COLOR_ARRAY);
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            #endif
            return S_OK;
        }
        HRESULT DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertexIndices, UINT PrimitiveCount, const void* pIndexData, D3DFORMAT IndexDataFormat, const void* pVertexStreamZeroData, UINT VertexStreamZeroStride) {
            #ifndef ANDROID
            glEnableClientState(GL_VERTEX_ARRAY);
            if (VertexStreamZeroStride >= 20) {
                glEnableClientState(GL_COLOR_ARRAY);
                glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                glVertexPointer(3, GL_FLOAT, VertexStreamZeroStride, pVertexStreamZeroData);
                glColorPointer(4, GL_UNSIGNED_BYTE, VertexStreamZeroStride, (char*)pVertexStreamZeroData + 12);
                glTexCoordPointer(2, GL_FLOAT, VertexStreamZeroStride, (char*)pVertexStreamZeroData + 16);
            } else {
                glVertexPointer(3, GL_FLOAT, VertexStreamZeroStride, pVertexStreamZeroData);
            }

            GLenum mode = GL_TRIANGLES;
            GLsizei count = 0;
            switch(PrimitiveType) {
                case 4: mode = GL_TRIANGLES; count = PrimitiveCount * 3; break;
                case 5: mode = GL_TRIANGLE_STRIP; count = PrimitiveCount + 2; break;
                case 6: mode = GL_TRIANGLE_FAN; count = PrimitiveCount + 2; break;
            }

            glDrawElements(mode, count, (IndexDataFormat == 17 ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT), pIndexData);

            glDisableClientState(GL_VERTEX_ARRAY);
            glDisableClientState(GL_COLOR_ARRAY);
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            #endif
            return S_OK;
        }
        HRESULT DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount) { 
            GLenum mode = GL_TRIANGLES;
            GLsizei count = 0;
            switch(PrimitiveType) {
                case 1: mode = GL_POINTS; count = PrimitiveCount; break;
                case 2: mode = GL_LINES; count = PrimitiveCount * 2; break;
                case 3: mode = GL_LINE_STRIP; count = PrimitiveCount + 1; break;
                case 4: mode = GL_TRIANGLES; count = PrimitiveCount * 3; break;
                case 5: mode = GL_TRIANGLE_STRIP; count = PrimitiveCount + 2; break;
                case 6: mode = GL_TRIANGLE_FAN; count = PrimitiveCount + 2; break;
            }
            glDrawArrays(mode, StartVertex, count);
            return S_OK; 
        }
        HRESULT DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, const void* pVertexStreamZeroData, UINT VertexStreamZeroStride) {
            #ifndef ANDROID
            glEnableClientState(GL_VERTEX_ARRAY);
            if (VertexStreamZeroStride >= 20) { // XYZ + COLOR + TEX
                glEnableClientState(GL_COLOR_ARRAY);
                glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                glVertexPointer(3, GL_FLOAT, VertexStreamZeroStride, pVertexStreamZeroData);
                glColorPointer(4, GL_UNSIGNED_BYTE, VertexStreamZeroStride, (char*)pVertexStreamZeroData + 12);
                glTexCoordPointer(2, GL_FLOAT, VertexStreamZeroStride, (char*)pVertexStreamZeroData + 16);
            } else {
                glVertexPointer(3, GL_FLOAT, VertexStreamZeroStride, pVertexStreamZeroData);
            }
            DrawPrimitive(PrimitiveType, 0, PrimitiveCount);
            glDisableClientState(GL_VERTEX_ARRAY);
            glDisableClientState(GL_COLOR_ARRAY);
            glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            #endif
            return S_OK;
        }
        HRESULT SetTextureStageState(DWORD stage, D3DTEXTURESTAGESTATETYPE type, DWORD value) {
            #ifndef ANDROID
            glActiveTexture(GL_TEXTURE0 + stage);
            switch(type) {
                case 10: // D3DTSS_ADDRESSU
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, (value == 1 ? GL_CLAMP : GL_REPEAT));
                    break;
                case 11: // D3DTSS_ADDRESSV
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, (value == 1 ? GL_CLAMP : GL_REPEAT));
                    break;
                case 7: // D3DTSS_MINFILTER
                case 8: // D3DTSS_MAGFILTER
                    glTexParameteri(GL_TEXTURE_2D, (type == 7 ? GL_TEXTURE_MIN_FILTER : GL_TEXTURE_MAG_FILTER), (value == 2 ? GL_LINEAR : GL_NEAREST));
                    break;
                case 3: // D3DTSS_COLOROP (simplified)
                    if (value == 2) glDisable(GL_TEXTURE_2D); // D3DTOP_DISABLE
                    else glEnable(GL_TEXTURE_2D);
                    break;
            }
            #endif
            return S_OK;
        }
        HRESULT SetRenderState(DWORD Type, DWORD Value) {
            switch(Type) {
                case D3DRS_ZENABLE:
                    if (Value) glEnable(GL_DEPTH_TEST); else glDisable(GL_DEPTH_TEST);
                    break;
                case D3DRS_ZFUNC:
                    glDepthFunc(GL_LEQUAL); // simplified mapping
                    break;
                case D3DRS_ALPHABLENDENABLE:
                    if (Value) glEnable(GL_BLEND); else glDisable(GL_BLEND);
                    break;
                case D3DRS_ZWRITEENABLE:
                    glDepthMask(Value ? GL_TRUE : GL_FALSE);
                    break;
                case D3DRS_ALPHATESTENABLE:
                    #ifndef ANDROID
                    if (Value) glEnable(GL_ALPHA_TEST); else glDisable(GL_ALPHA_TEST);
                    #endif
                    break;
                case D3DRS_ALPHAFUNC:
                    #ifndef ANDROID
                    glAlphaFunc(GL_GREATER, 0.5f); // simplified mapping
                    #endif
                    break;
                case D3DRS_SRCBLEND:
                    {
                        GLenum factor = GL_ONE;
                        switch(Value) {
                            case D3DBLEND_ZERO: factor = GL_ZERO; break;
                            case D3DBLEND_ONE: factor = GL_ONE; break;
                            case D3DBLEND_SRCCOLOR: factor = GL_SRC_COLOR; break;
                            case D3DBLEND_SRCALPHA: factor = GL_SRC_ALPHA; break;
                            case D3DBLEND_INVSRCALPHA: factor = GL_ONE_MINUS_SRC_ALPHA; break;
                            case D3DBLEND_INVDESTCOLOR: factor = GL_ONE_MINUS_DST_COLOR; break;
                        }
                        glBlendFunc(factor, GL_ONE_MINUS_SRC_ALPHA); // partial mapping
                    }
                    break;
                case D3DRS_DESTBLEND:
                    break;
                case D3DCULL_CW:
                case D3DCULL_CCW:
                case D3DCULL_NONE:
                    if (Value == D3DCULL_NONE) glDisable(GL_CULL_FACE);
                    else {
                        glEnable(GL_CULL_FACE);
                        glCullFace(Value == D3DCULL_CW ? GL_FRONT : GL_BACK);
                    }
                    break;
            }
            return S_OK;
        }
        HRESULT SetTexture(DWORD stage, LPDIRECT3DBaseTexture8 tex) { 
            #ifndef ANDROID
            glActiveTexture(GL_TEXTURE0 + stage);
            if (tex) {
                IDirect3DTexture8* gtex = (IDirect3DTexture8*)tex;
                glBindTexture(GL_TEXTURE_2D, gtex->glId);
                glEnable(GL_TEXTURE_2D);
            } else {
                glBindTexture(GL_TEXTURE_2D, 0);
                glDisable(GL_TEXTURE_2D);
            }
            #endif
            return S_OK; 
        }
        HRESULT SetTransform(DWORD type, const GLMATRIX* mat) { 
            #ifndef ANDROID
            if (type == 3) glMatrixMode(GL_PROJECTION);
            else glMatrixMode(GL_MODELVIEW);
            glLoadMatrixf(&mat->m[0][0]);
            #endif
            return S_OK; 
        }
        HRESULT GetTransform(DWORD type, GLMATRIX* mat) { return S_OK; }
    };

    inline HRESULT IDirect3D8::CreateDevice(UINT, int, HWND hWnd, DWORD, D3DPRESENT_PARAMETERS*, IDirect3DDevice8** ppDevice) {
#ifndef ANDROID
        HDC hDC = GetDC(hWnd);
        static PIXELFORMATDESCRIPTOR pfd = {
            sizeof(PIXELFORMATDESCRIPTOR), 1,
            PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
            PFD_TYPE_RGBA, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 8, 0,
            PFD_MAIN_PLANE, 0, 0, 0, 0
        };
        int pixelFormat = ChoosePixelFormat(hDC, &pfd);
        SetPixelFormat(hDC, pixelFormat, &pfd);
        HGLRC hRC = wglCreateContext(hDC);
        wglMakeCurrent(hDC, hRC);

        *ppDevice = new IDirect3DDevice8();
        (*ppDevice)->m_hDC = hDC;
#else
        *ppDevice = new IDirect3DDevice8();
#endif
        return S_OK;
    }

    inline IDirect3D8* Direct3DCreate8(UINT) { return new IDirect3D8(); }

    inline HRESULT D3DXCreateTexture(LPDIRECT3DDEVICE8 pDevice, UINT Width, UINT Height, UINT MipLevels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, LPDIRECT3DTEXTURE8* ppTexture) {
        if (!pDevice) return S_OK;
        return pDevice->CreateTexture(Width, Height, MipLevels, Usage, Format, Pool, ppTexture);
    }

    inline HRESULT D3DXCreateTextureFromFileInMemoryEx(LPDIRECT3DDEVICE8 pDevice, LPCVOID pSrcData, UINT SrcDataSize, UINT Width, UINT Height, UINT MipLevels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, DWORD Filter, DWORD MipFilter, D3DCOLOR ColorKey, D3DXIMAGE_INFO* pSrcInfo, PALETTEENTRY* pPalette, LPDIRECT3DTEXTURE8* ppTexture) {
        if (pSrcInfo) {
            pSrcInfo->Width = (Width == D3DX_DEFAULT) ? 256 : Width;
            pSrcInfo->Height = (Height == D3DX_DEFAULT) ? 256 : Height;
            pSrcInfo->MipLevels = 1;
            pSrcInfo->Format = D3DFMT_A8R8G8B8;
        }
        if (pDevice) {
            return pDevice->CreateTexture(256, 256, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, ppTexture);
        }
        return S_OK;
    }

    inline HRESULT D3DXLoadSurfaceFromSurface(LPDIRECT3DSURFACE8 pDestSurface, CONST PALETTEENTRY* pDestPalette, CONST RECT* pDestRect, LPDIRECT3DSURFACE8 pSrcSurface, CONST PALETTEENTRY* pSrcPalette, CONST RECT* pSrcRect, DWORD Filter, D3DCOLOR ColorKey) {
        return S_OK;
    }

    // Stub functions
    inline HRESULT D3DXCreateMatrixStack(DWORD flags, LPD3DXMATRIXSTACK* ppStack) { if (ppStack) *ppStack = new ID3DXMatrixStack(); return S_OK; }
    inline HRESULT D3DXCreateSphere(LPDIRECT3DDEVICE8 pDevice, float radius, UINT slices, UINT stacks, LPD3DXMESH* ppMesh, LPD3DXBUFFER* ppAdjacency) { if (ppMesh) *ppMesh = new ID3DXMesh(); return S_OK; }
    inline HRESULT D3DXCreateCylinder(LPDIRECT3DDEVICE8 pDevice, float radius1, float radius2, float length, UINT slices, UINT stacks, LPD3DXMESH* ppMesh, LPD3DXBUFFER* ppAdjacency) { if (ppMesh) *ppMesh = new ID3DXMesh(); return S_OK; }
    inline HRESULT D3DXAssembleShaderFromFile(LPCSTR pSrcFile, DWORD flags, LPD3DXBUFFER* ppConstants, LPD3DXBUFFER* ppCompiledShader, LPD3DXBUFFER* ppCompilationErrors) { 
        if (ppCompiledShader) *ppCompiledShader = new ID3DXBuffer();
        if (ppCompilationErrors) *ppCompilationErrors = new ID3DXBuffer();
        return S_OK; 
    }

    inline HRESULT D3DXAssembleShader(LPCSTR pSrcData, UINT SrcDataLen, DWORD flags, LPD3DXBUFFER* ppConstants, LPD3DXBUFFER* ppCompiledShader, LPD3DXBUFFER* ppCompilationErrors) { 
        if (ppCompiledShader) *ppCompiledShader = new ID3DXBuffer();
        if (ppCompilationErrors) *ppCompilationErrors = new ID3DXBuffer();
        return S_OK; 
    }
#endif
