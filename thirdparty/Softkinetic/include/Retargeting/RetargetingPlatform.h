/*************************************************************************************************************************/
//  SOFTKINETIC DISCLAIMER
//
// COPYRIGHT AND CONFIDENTIALITY NOTICE – SOFTKINETIC CONFIDENTIAL INFORMATION      
// The source code of the SoftKinetic Retargeting SDK is proprietary and confidential information of Softkinetic Software SA
// All rights reserved to SOFTKINETIC SOFTWARE SA (a company incorporated and existing under the laws of Belgium, with 
// its principal place of business at Boulevard de la Plainelaan 15, 1050 Brussels (Belgium), registered with the Crossroads 
// bank for enterprises under company number 0890 705 864 - “Softkinetic Software”)
//
// For any question about terms and conditions, please contact: info@softkinetic.com
// Copyright (c) 2002-2013 Softkinetic Software SA
/*************************************************************************************************************************/

#ifndef RETARGETING_PLATFORM_H
#define RETARGETING_PLATFORM_H

/**
 * \file RetargetingPlatform.h
 * \brief API Platform specific definitions
 */

#ifdef _WIN32
#pragma warning (push, 0)
#endif

//common std include
#include <assert.h>
#include <limits>

// Supported compiler
#define SKA_COMPILER_MSVC 1
#define SKA_COMPILER_GCC  2
#define SKA_COMPILER_INTEL 3
#define SKA_COMPILER_ARMCC 4

// Supported platform
#define SKA_PLATFORM_WIN32       	1
#define SKA_PLATFORM_LINUX_x86   	2


/* Finds the compiler type and version.
*/
#if defined( _MSC_VER )
	#define SKA_COMPILER SKA_COMPILER_MSVC
	#define SKA_COMPILER_VERSION _MSC_VER
#elif defined(__arm__) && defined(__ARMCC_VERSION)
	#define SKA_COMPILER SKA_COMPILER_ARMCC
	/* the format is PVbbbb - P is the major version, V is the minor version,
 	 bbbb is the build number*/
	#define SKA_COMPILER_VERSION (__ARMCC_VERSION)
#elif defined( __GNUC__ )
	#define SKA_COMPILER SKA_COMPILER_GCC
	#define SKA_COMPILER_VERSION (((__GNUC__)*100) + \
		(__GNUC_MINOR__*10) + \
		__GNUC_PATCHLEVEL__)
#else
	#error "Compilation error: Unsupported compiler."
#endif

/* Finds the platform - architecture
*/
#if defined( __WIN32__ ) || defined( _WIN32 )
	#define SKA_PLATFORM SKA_PLATFORM_WIN32
#elif defined(__linux__) || defined(__LINUX__)
	#define SKA_PLATFORM_LINUX (1)

	#if (__TARGET_ARCH_ARM == 5 || __ARM_ARCH_5TEJ__ == 1 || __ARM_ARCH_5TE__ == 1 || __ARM_ARCH_5T__ == 1)
		#define SKA_PLATFORM SKA_PLATFORM_LINUX_ARMv5
	#elif (__TARGET_ARCH_ARM == 7 || __ARM_ARCH_7A__ == 1)
		#define SKA_PLATFORM SKA_PLATFORM_LINUX_ARMv7
	#elif defined(__x86) || defined(__x86__) || defined(__i386__) || defined(__i486__) || defined(__i586__) || defined(__i686__)
		#define SKA_PLATFORM SKA_PLATFORM_LINUX_x86
		#define SKA_ENABLE_SSE
	#else
		#error "Compilation error: Unsupported version of Linux platform."
	#endif
#else
	#error "Compilation error: Unsupported platform."
#endif


//-------------------COMPILER SPECIFIC ---------------------------------------

// inlining
#if (SKA_COMPILER == SKA_COMPILER_MSVC)
	#if (SKA_COMPILER_VERSION >= 1200)
		#define SKA_ALWAYS_INLINE __forceinline
	#else
		#error "Compilation error: Unsupported compiler. Version must be >= VS 2005"
	#endif
#else
	#define SKA_ALWAYS_INLINE __inline
#endif

#ifdef SKA_DEBUG
	// no inline in debug excepted for SKA_ALWAYS_INLINE
	#define	SKA_INLINE
	#define	SKA_FORCE_INLINE
	
	#if SKA_COMPILER == SKA_COMPILER_MSVC
		#if SKA_COMPILER_VERSION >= 1200
			#define SKA_ALWAYS_INLINE __forceinline
		#else
			#error "Compilation error: Unsupported compiler. Version must be >= VS 2005"
		#endif
	#else
		#define SKA_ALWAYS_INLINE __inline
	#endif

#else

	#define	SKA_INLINE inline
	/* See if we can use __forceinline or if we need to use __inline instead */
	#if (SKA_COMPILER == SKA_COMPILER_MSVC)
		#if (SKA_COMPILER_VERSION >= 1200)
			#define SKA_FORCE_INLINE __forceinline
		#else
			#error "Compilation error: Unsupported compiler. Version must be >= VS 2005"
		#endif
	#else
		#define SKA_FORCE_INLINE __inline
	#endif
#endif


//////////////////////////////////////////////////////////////////////////
// override is a non standard extension to the C++. It triggers warning
// 4481 when using warning level 4. In order not to get the warning we
// prevent it with a pragma.
#if (SKA_COMPILER == SKA_COMPILER_MSVC)
	#define SKA_OVERRIDE \
		override \
	__pragma(warning(disable: 4481))
#else
	#define SKA_OVERRIDE
#endif

// ---------- FLOATING POINT MIN / MAX ----------------

#include <float.h>

typedef float float32_t;
typedef double float64_t;

// -------- CALLING CONVENTIONS ------------------------

#if defined(_WIN32) && !defined(__MINGW32__) && !defined(__CYGWIN__)
	#define SKA_SDK_DECL  __stdcall
	#define SKA_SDK_CDECL  __cdecl
#else 
	#define SKA_SDK_DECL
	#define SKA_SDK_CDECL
#endif

//-------------- DLL Export DEFINITIONS ------------
#if (SKA_COMPILER == SKA_COMPILER_MSVC) && !defined(STATIC_LIB)
	#define SKA_DLL_EXPORT __declspec(dllexport)
	#define SKA_DLL_IMPORT __declspec(dllimport)
	#define SKA_DLL_LOCAL
	#define SKA_DLL_PROTECTED
#elif (SKA_COMPILER == SKA_COMPILER_GCC || SKA_COMPILER == SKA_COMPILER_ARMCC)
	#if (SKA_COMPILER_VERSION >= ((__GNUC__) * 100)) || (SKA_COMPILER_VERSION >= (500000))
		#define SKA_DLL_EXPORT 		__attribute__ ((visibility ("default")))
		#define SKA_DLL_IMPORT 		__attribute__ ((visibility ("default")))
		#define SKA_DLL_LOCAL 		__attribute__ ((visibility ("hidden")))
		#define SKA_DLL_PROTECTED 	__attribute__ ((visibility ("protected")))
	#else
		#define SKA_DLL_EXPORT
		#define SKA_DLL_IMPORT
		#define SKA_DLL_LOCAL
		#define SKA_DLL_PROTECTED
	#endif
#else
	#define SKA_DLL_EXPORT
	#define SKA_DLL_IMPORT
	#define SKA_DLL_LOCAL
	#define SKA_DLL_PROTECTED
#endif

#if defined(SKA_DLL_REGISTER)
	#define SKA_DLL_API SKA_DLL_EXPORT
#elif defined (SKA_HIDE_SYMBOLS)
	#define SKA_DLL_API
#else
	#define SKA_DLL_API SKA_DLL_IMPORT
#endif

#if SKA_PLATFORM == SKA_PLATFORM_WIN32

#ifdef CUSTOM_STD_INT
	#include CUSTOM_STD_INT
#else
	// provide default basic implementation of <stdint.h>
	typedef signed __int8		int8_t;
	typedef signed __int16		int16_t;
	typedef signed __int32		int32_t;
	typedef signed __int64		int64_t;

	typedef unsigned __int8		uint8_t;
	typedef unsigned __int8		uchar;
	typedef unsigned __int16	uint16_t;
	typedef unsigned __int16	ushort;
	typedef unsigned __int32	uint32_t;
	typedef unsigned __int32	uint;
	typedef unsigned __int64	uint64_t;

	#define	INT8_MIN		int8_t(-128)
	#define	INT8_MAX		int8_t(127)

	#define	UINT8_MIN		uint8_t(0)
	#define	UINT8_MAX		uint8_t(255)

	#define	INT16_MIN		int16_t(-32768)
	#define	INT16_MAX		int16_t(32767)

	#define	UINT16_MIN		uint16_t(0)
	#define	UINT16_MAX		uint16_t(65535)

	#define	INT32_MIN		int32_t(0x80000000)
	#define	INT32_MAX		int32_t(0x7FFFFFFF)

	#define	UINT32_MIN		uint32_t(0)
	#define	UINT32_MAX		uint32_t(0xFFFFFFFF)

	#define	INT64_MIN		int64_t(0x8000000000000000)
	#define	INT64_MAX		int64_t(0x7FFFFFFFFFFFFFFF)

	#define	UINT64_MIN		uint64_t(0)
	#define	UINT64_MAX		uint64_t(0xFFFFFFFFFFFFFFFF)
#endif // CUSTOM_STD_INT

#elif defined(SKA_PLATFORM_LINUX)
	#include <stdint.h>
	#include <limits.h>
	#define INT32_MAX      (2147483647)
	#define UINT32_MAX     (4294967295U)
    typedef unsigned char   uchar;
    typedef unsigned short  ushort;
    typedef unsigned int    uint;
#else

#endif // SKA_PLATFORM == SKA_PLATFORM_WIN32


#ifdef _WIN32
#pragma warning (pop)
#endif


#endif // RETARGETING_PLATFORM_H