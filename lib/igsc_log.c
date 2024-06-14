/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2023 Intel Corporation
 */

#include "msvc/config.h"
#include "gcc/config.h"
#include "igsc_lib.h"

static enum igsc_log_level_type igsc_log_level =
#if defined(DEBUG) || defined(_DEBUG)
IGSC_LOG_LEVEL_DEBUG;
#else
IGSC_LOG_LEVEL_ERROR;
#endif

static igsc_log_func_t igsc_log_func = NULL;

void igsc_set_log_level(unsigned int log_level)
{
    if (log_level >= IGSC_LOG_LEVEL_MAX)
    {
        log_level = IGSC_LOG_LEVEL_MAX - 1;
    }
    igsc_log_level = log_level;
}

unsigned int igsc_get_log_level(void)
{
    return igsc_log_level;
}

void igsc_set_log_callback_func(igsc_log_func_t log_f)
{
    igsc_log_func = log_f;
}

igsc_log_func_t igsc_get_log_callback_func()
{
    return igsc_log_func;
}
