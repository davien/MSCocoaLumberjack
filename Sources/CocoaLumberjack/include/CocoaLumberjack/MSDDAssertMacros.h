// Software License Agreement (BSD License)
//
// Copyright (c) 2010-2021, Deusty, LLC
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
 * NSAssert replacement that will output a log message even when assertions are disabled.
 **/
#define MSDDAssert(condition, frmt, ...)                                                \
        if (!(condition)) {                                                           \
            NSString *description = [NSString stringWithFormat:frmt, ## __VA_ARGS__]; \
            MSDDLogError(@"%@", description);                                           \
            NSAssert(NO, @"%@", description);                                         \
        }
#define MSDDAssertCondition(condition) MSDDAssert(condition, @"Condition not satisfied: %s", #condition)

/**
 * Analog to `DDAssertionFailure` from DDAssert.swift for use in Objective C
 */
#define MSDDAssertionFailure(frmt, ...) MSDDAssert(NO, frmt, ##__VA_ARGS__)

