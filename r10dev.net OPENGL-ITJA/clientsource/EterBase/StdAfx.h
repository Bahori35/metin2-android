#pragma once

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#pragma warning(disable: 4100 4127 4189 4231 4505 4512 4706) // cryptopp
#pragma warning(disable:4995)	// pragma deprecated

#pragma warning(disable:4710)	// not inlined
#pragma warning(disable:4786)	// character 255 �Ѿ�°� ����
#pragma warning(disable:4244)	// type conversion possible lose of data
#include "../UserInterface/Locale_inc.h"

#ifdef __ANDROID__
    #include <stdlib.h>
    #include <string.h>
    #include <stdint.h>
    
    // Win32 stub types for Android
    typedef uint32_t DWORD;
    typedef uint16_t WORD;
    typedef uint8_t BYTE;
    typedef int32_t LONG;
    typedef uint32_t UINT;
    typedef void* HWND;
    typedef void* HINSTANCE;
    typedef void* HDC;
    typedef void* HGLRC;
    typedef void* HICON;
    typedef void* HCURSOR;
    typedef void* HMENU;
    typedef void* HANDLE;
    typedef struct {
        DWORD dwFileAttributes;
        uint64_t ftCreationTime;
        uint64_t ftLastAccessTime;
        uint64_t ftLastWriteTime;
        DWORD nFileSizeHigh;
        DWORD nFileSizeLow;
        DWORD dwReserved0;
        DWORD dwReserved1;
        char cFileName[260];
        char cAlternateFileName[14];
    } WIN32_FIND_DATA;
    #define FILE_ATTRIBUTE_DIRECTORY 0x00000010
    typedef struct { int dummy; } CRITICAL_SECTION;
    inline void InitializeCriticalSection(CRITICAL_SECTION* lp) {}
    inline void DeleteCriticalSection(CRITICAL_SECTION* lp) {}
    inline void EnterCriticalSection(CRITICAL_SECTION* lp) {}
    inline void LeaveCriticalSection(CRITICAL_SECTION* lp) {}
    typedef struct { LONG x; LONG y; } POINT;
    typedef struct { LONG left; LONG top; LONG right; LONG bottom; } RECT;
    typedef const char* LPCSTR;
    typedef char* LPSTR;
    typedef int BOOL;
    #ifndef TRUE
    #define TRUE 1
    #define FALSE 0
    #endif
    #define CALLBACK
    #define WINAPI
    #define APIENTRY
    #define stricmp strcasecmp
    #define strnicmp strncasecmp
    #define _vsnprintf vsnprintf
    #define _snprintf snprintf
    typedef const void* LPCVOID;
    typedef void* LPVOID;
    #ifndef MAX_PATH
    #define MAX_PATH 260
    #endif

    // Socket stubs for Android
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <netdb.h>
    #include <errno.h>
    #include <sys/ioctl.h>
    #include <unistd.h>
    #define INVALID_SOCKET (SOCKET)(~0)
    #define SOCKET_ERROR (-1)
    #define closesocket close
    #define ioctlsocket ioctl
    #define WSAGetLastError() errno
    #define WSAEWOULDBLOCK EWOULDBLOCK
    #define WSAEINPROGRESS EINPROGRESS
    #define WSAETIMEDOUT ETIMEDOUT
    typedef int SOCKET;
    typedef struct sockaddr_in SOCKADDR_IN;
    typedef struct sockaddr SOCKADDR;
    typedef struct sockaddr* PSOCKADDR;
#else
    #include <windows.h>
    #include <mmsystem.h>
    #include <imagehlp.h>
#endif

#include <assert.h>
#include <stdio.h>
#include <time.h>

#pragma warning ( push, 3 )

#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <map>

#pragma warning ( pop )

#if _MSC_VER >= 1400
#define stricmp _stricmp
#define strnicmp _strnicmp
#define strupt _strupr
#define strcmpi _strcmpi
#define fileno _fileno
//#define access _access_s
//#define _access _access_s
#define atoi _atoi64
#endif

// Armadillo nanomite protection
#ifndef NANOBEGIN
#ifdef __BORLANDC__
#define NANOBEGIN     __emit__ (0xEB,0x03,0xD6,0xD7,0x01)
#define NANOEND       __emit__ (0xEB,0x03,0xD6,0xD7,0x00)
#else
#define NANOBEGIN     __asm _emit 0xEB __asm _emit 0x03 __asm _emit 0xD6 __asm _emit 0xD7 __asm _emit 0x01
#define NANOEND       __asm _emit 0xEB __asm _emit 0x03 __asm _emit 0xD6 __asm _emit 0xD7 __asm _emit 0x00
#endif
#endif

#include "vk.h"
#include "Filename.h"
#include "ServiceDefs.h"
