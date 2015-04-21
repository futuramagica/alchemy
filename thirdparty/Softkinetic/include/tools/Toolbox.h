#pragma once

#include "ToolboxConfig.h"
#ifdef __cplusplus
namespace SK
{
class IisuHandle;

namespace Toolbox
{
//
//
IISU_TOOLBOX_EXPORT int IISU_TOOLBOX_DECL run(int argc, char **argv);

//! \brief Run the Toolbox using an existing iisu handle.
IISU_TOOLBOX_EXPORT int IISU_TOOLBOX_DECL runFromHandle(SK::IisuHandle *handle);

#if defined(WIN32)
//! \brief Run the Toolbox using an existing iisu handle in its own thread.
IISU_TOOLBOX_EXPORT void IISU_TOOLBOX_DECL startFromHandle(SK::IisuHandle *handle);
#endif // defined(WIN32)

//! \brief Show the Toolbox if it is already running.
IISU_TOOLBOX_EXPORT void IISU_TOOLBOX_DECL show();

//! \brief Closes the Toolbox thread.
IISU_TOOLBOX_EXPORT void IISU_TOOLBOX_DECL close();
} // namespace Toolbox
} // namespace SK
#endif // __cplusplus

// C-API function.
#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
IISU_TOOLBOX_EXPORT int IISU_TOOLBOX_DECL SK_Toolbox_run(int argc, char *argv[]);

IISU_TOOLBOX_EXPORT int IISU_TOOLBOX_DECL SK_Toolbox_runFromHandle(void *handle);

#if defined(WIN32)
IISU_TOOLBOX_EXPORT void IISU_TOOLBOX_DECL SK_Toolbox_startFromHandle(void *handle);
#endif // defined(WIN32)

IISU_TOOLBOX_EXPORT void IISU_TOOLBOX_DECL SK_Toolbox_show(void);

IISU_TOOLBOX_EXPORT void IISU_TOOLBOX_DECL SK_Toolbox_close(void);
#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus
