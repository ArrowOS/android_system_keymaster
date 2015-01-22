/*
 * Copyright 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "soft_keymaster_logger.h"

#include <stdarg.h>
#include <syslog.h>

#define LOG_TAG "SoftKeymaster"
#include <cutils/log.h>

namespace keymaster {

int SoftKeymasterLogger::debug(const char* fmt, ...) const {
    va_list args;
    va_start(args, fmt);
    int retval = LOG_PRI_VA(LOG_DEBUG, LOG_TAG, fmt, args);
    va_end(args);
    return retval;
}

int SoftKeymasterLogger::info(const char* fmt, ...) const {
    va_list args;
    va_start(args, fmt);
    int retval = LOG_PRI_VA(LOG_INFO, LOG_TAG, fmt, args);
    va_end(args);
    return retval;
}

int SoftKeymasterLogger::error(const char* fmt, ...) const {
    va_list args;
    va_start(args, fmt);
    int retval = LOG_PRI_VA(LOG_ERR, LOG_TAG, fmt, args);
    va_end(args);
    return retval;
}

int SoftKeymasterLogger::severe(const char* fmt, ...) const {
    va_list args;
    va_start(args, fmt);
    int retval = LOG_PRI_VA(LOG_CRIT, LOG_TAG, fmt, args);
    va_end(args);
    return retval;
}

}  // namespace keymaster
