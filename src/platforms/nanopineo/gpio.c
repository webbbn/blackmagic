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

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

#include "platform.h"
#include "gpio.h"
#include "gpio_lib.h"

int gpio_direction(uint8_t port, uint8_t pin, bool output) {
    uint32_t mcu_pin = GPIO_PIN(port, pin);
    if (output) {
	return sunxi_gpio_set_cfgpin(mcu_pin, SUNXI_GPIO_OUTPUT);
    } else {
	return sunxi_gpio_set_cfgpin(mcu_pin, SUNXI_GPIO_INPUT);
    }
}

int gpio_set_val(uint8_t port, uint8_t pin, bool value) {
    uint32_t mcu_pin = GPIO_PIN(port, pin);
    return sunxi_gpio_output(mcu_pin, value ? 1 : 0);
}

int gpio_set(uint8_t port, uint8_t pin) {
    return gpio_set_val(port, pin, true);
}

int gpio_clear(uint8_t port, uint8_t pin) {
    return gpio_set_val(port, pin, false);
}

bool gpio_get(uint8_t port, uint8_t pin) {
    uint32_t mcu_pin = GPIO_PIN(port, pin);
    return sunxi_gpio_input(mcu_pin);
}
