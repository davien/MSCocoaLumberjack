// Software License Agreement (BSD License)
//
// Copyright (c) 2010-2020, Deusty, LLC
// All rights reserved.
//
// Redistribution and use of this software in source and binary forms,
// with or without modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
// * Neither the name of Deusty nor the names of its contributors may be used
//   to endorse or promote products derived from this software without specific
//   prior written permission of Deusty, LLC.

/**
 * Legacy macros used for 1.9.x backwards compatibility.
 *
 * Imported by default when importing a DDLog.h directly and MSDD_LEGACY_MACROS is not defined and set to 0.
 **/
#if MSDD_LEGACY_MACROS

#warning CocoaLumberjack 1.9.x legacy macros enabled. \
Disable legacy macros by importing CocoaLumberjack.h or MSDDLogMacros.h instead of MSDDLog.h or add `#define MSDD_LEGACY_MACROS 0` before importing MSDDLog.h.

#ifndef MSLOG_LEVEL_DEF
    #define MSLOG_LEVEL_DEF ddLogLevel
#endif

#define MSLOG_FLAG_ERROR    MSDDLogFlagError
#define MSLOG_FLAG_WARN     MSDDLogFlagWarning
#define MSLOG_FLAG_INFO     MSDDLogFlagInfo
#define MSLOG_FLAG_DEBUG    MSDDLogFlagDebug
#define MSLOG_FLAG_VERBOSE  MSDDLogFlagVerbose

#define MSLOG_LEVEL_OFF     MSDDLogLevelOff
#define MSLOG_LEVEL_ERROR   MSDDLogLevelError
#define MSLOG_LEVEL_WARN    MSDDLogLevelWarning
#define MSLOG_LEVEL_INFO    MSDDLogLevelInfo
#define MSLOG_LEVEL_DEBUG   MSDDLogLevelDebug
#define MSLOG_LEVEL_VERBOSE MSDDLogLevelVerbose
#define MSLOG_LEVEL_ALL     MSDDLogLevelAll

#define MSLOG_ASYNC_ENABLED YES

#define MSLOG_ASYNC_ERROR    ( NO && MSLOG_ASYNC_ENABLED)
#define MSLOG_ASYNC_WARN     (YES && MSLOG_ASYNC_ENABLED)
#define MSLOG_ASYNC_INFO     (YES && MSLOG_ASYNC_ENABLED)
#define MSLOG_ASYNC_DEBUG    (YES && MSLOG_ASYNC_ENABLED)
#define MSLOG_ASYNC_VERBOSE  (YES && MSLOG_ASYNC_ENABLED)

#define MSLOG_MACRO(isAsynchronous, lvl, flg, ctx, atag, fnct, frmt, ...) \
        [MSDDLog log : isAsynchronous                                     \
             level : lvl                                                \
              flag : flg                                                \
           context : ctx                                                \
              file : __FILE__                                           \
          function : fnct                                               \
              line : __LINE__                                           \
               tag : atag                                               \
            format : (frmt), ## __VA_ARGS__]

#define MSLOG_MAYBE(async, lvl, flg, ctx, fnct, frmt, ...)                       \
        do { if((lvl & flg) != 0) MSLOG_MACRO(async, lvl, flg, ctx, nil, fnct, frmt, ##__VA_ARGS__); } while(0)

#define MSLOG_OBJC_MAYBE(async, lvl, flg, ctx, frmt, ...) \
        MSLOG_MAYBE(async, lvl, flg, ctx, __PRETTY_FUNCTION__, frmt, ## __VA_ARGS__)

#define MSDDLogError(frmt, ...)   MSLOG_OBJC_MAYBE(MSLOG_ASYNC_ERROR,   MSLOG_LEVEL_DEF, MSLOG_FLAG_ERROR,   0, frmt, ##__VA_ARGS__)
#define MSDDLogWarn(frmt, ...)    MSLOG_OBJC_MAYBE(MSLOG_ASYNC_WARN,    MSLOG_LEVEL_DEF, MSLOG_FLAG_WARN,    0, frmt, ##__VA_ARGS__)
#define MSDDLogInfo(frmt, ...)    MSLOG_OBJC_MAYBE(MSLOG_ASYNC_INFO,    MSLOG_LEVEL_DEF, MSLOG_FLAG_INFO,    0, frmt, ##__VA_ARGS__)
#define MSDDLogDebug(frmt, ...)   MSLOG_OBJC_MAYBE(MSLOG_ASYNC_DEBUG,   MSLOG_LEVEL_DEF, MSLOG_FLAG_DEBUG,   0, frmt, ##__VA_ARGS__)
#define MSDDLogVerbose(frmt, ...) MSLOG_OBJC_MAYBE(MSLOG_ASYNC_VERBOSE, MSLOG_LEVEL_DEF, MSLOG_FLAG_VERBOSE, 0, frmt, ##__VA_ARGS__)

#endif
