#ifndef LVOX_SHAREDFORTEST_H
#define LVOX_SHAREDFORTEST_H

#include <QtCore/qglobal.h>

#if defined(LVOXSHAREDFORTEST_LIBRARY)
#  define LVOXSHAREDFORTEST_EXPORT Q_DECL_EXPORT
#else
#  define LVOXSHAREDFORTEST_EXPORT Q_DECL_IMPORT
#endif

#endif // LVOX_SHAREDFORTEST_H
