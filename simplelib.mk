SRCS ?=
INC ?=

PROJ ?= simple
BUILD_DIR ?= build

OBJS ?= $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))

CFLAGS += -c $(addprefix -I,$(INC))

LIB = $(BUILD_DIR)/lib$(PROJ).a

ifeq ($(BUILD_DIR),.)
	RM_STUFF = $(OBJS) $(LIB)
else
	RM_STUFF = $(BUILD_DIR)
endif

AR ?= ar
CC ?= gcc

.PHONY: lib clean

lib: $(LIB)

echo_lib_path:
	@echo $(abspath $(LIB))

clean:
	rm -rf $(RM_STUFF)

$(LIB): $(OBJS)
	$(AR) rc -o $@ $^

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@
