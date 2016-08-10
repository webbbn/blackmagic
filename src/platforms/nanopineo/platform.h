/*
 * This file is part of the Black Magic Debug project.
 *
 * Copyright (C) 2011  Black Sphere Technologies Ltd.
 * Written by Gareth McMullin <gareth@blacksphere.co.nz>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __PLATFORM_H
#define __PLATFORM_H

#include <stdint.h>

#include "timing.h"
#include "gpio.h"
#include "gpio_lib.h"

#define DEBUG(...)
//#define PLATFORM_HAS_DEBUG

#define SET_RUN_STATE(state)
#define SET_IDLE_STATE(state)
#define SET_ERROR_STATE(state)

#define PLATFORM_FATAL_ERROR(error)	abort()
#define PLATFORM_SET_FATAL_ERROR_RECOVERY()

#define SWCLK_PORT SUNXI_GPIO_A
#define SWCLK_PIN 6
#define SWDIO_PORT SUNXI_GPIO_G
#define SWDIO_PIN 8

#define SWDIO_MODE_FLOAT() \
    gpio_direction(SWDIO_PORT, SWDIO_PIN, false);
#define SWDIO_MODE_DRIVE() \
    gpio_direction(SWDIO_PORT, SWDIO_PIN, true);

void platform_init(int argc, char **argv);
const char *platform_target_voltage(void);
void platform_delay(uint32_t delay);

void platform_buffer_flush(void);
int platform_buffer_write(const uint8_t *data, int size);
int platform_buffer_read(uint8_t *data, int size);

static inline int platform_hwversion(void)
{
	        return 0;
}

#endif
