#ifndef SIMPLEQTLOGGER_GLOBAL_H
#define SIMPLEQTLOGGER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SIMPLEQTLOGGER_LIBRARY)
#  define SIMPLEQTLOGGERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SIMPLEQTLOGGERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SIMPLEQTLOGGER_GLOBAL_H
