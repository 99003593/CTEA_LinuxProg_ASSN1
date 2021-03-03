PROJ = $(notdir $(abspath .))

SRCS = $(wildcard src/*.c)
INC = inc

INSTALL_DIR ?= $(BUILD_DIR)

ifneq ($(BUILD_DIR),)
    BUILD_DIR := $(BUILD_DIR)/$(PROJ)
else
    BUILD_DIR ?= build
endif

include ../simplelib.mk
