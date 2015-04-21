#pragma once

#if defined(WIN32)
# if defined(IISU_TOOLBOX_LIB)
#  define IISU_TOOLBOX_EXPORT __declspec(dllexport)
# else
#  define IISU_TOOLBOX_EXPORT __declspec(dllimport)
# endif // defined(IISU_TOOLBOX_LIB)
# define IISU_TOOLBOX_DECL __cdecl
#else
# define IISU_TOOLBOX_EXPORT
# define IISU_TOOLBOX_DECL
#endif // defined(WIN32)
