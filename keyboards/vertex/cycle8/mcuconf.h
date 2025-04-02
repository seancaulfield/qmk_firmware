// Copyright 2022 Eason
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

#undef STM32_SPI_USE_SPI2
#define STM32_SPI_USE_SPI2 TRUE

//#undef STM32_HSECLK
//#define STM32_HSECLK 8000000U

//#undef STM32_PLLXTPRE
//#define STM32_PLLXTPRE STM32_PLLXTPRE_DIV2

