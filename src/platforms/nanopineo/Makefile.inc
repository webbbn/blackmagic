CFLAGS += -DLIBFTDI -Wno-format
LDFLAGS += -lusb
SRC += \
  gpio_lib.c \
  gpio.c \
  timing.c
