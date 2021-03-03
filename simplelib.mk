SRCS ?=
INC ?=

PROJ ?= simple
LINKMODE ?= static
BUILD_DIR ?= build
INSTALL_DIR ?= .

OBJS ?= $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))

CFLAGS += -c $(addprefix -I,$(INC))
LDFLAGS = -$(LINKMODE) $(LDFLAG)

LIB_static = $(BUILD_DIR)/lib$(PROJ).a
LIB_shared = $(BUILD_DIR)/lib$(PROJ).so

ifeq ($(LINKMODE),shared)
	LIB = $(LIB_shared)
else
	LIB = $(LIB_static)
endif

ifeq ($(BUILD_DIR),.)
	RM_STUFF = $(OBJS) $(LIB)
else
	RM_STUFF = $(BUILD_DIR)
endif

AR ?= ar
CC ?= gcc

.PHONY: lib clean

lib: $(LIB)

install: lib
	cp $(LIB) $(INSTALL_DIR)

uninstall:
	rm -rf $(INSTALL_DIR)/$(LIBNAME)

echo_lib_path:
	@echo $(abspath $(INSTALL_DIR)/$(LIBNAME))

clean:
	rm -rf $(RM_STUFF)

$(LIB_static): $(OBJS)
	$(AR) rc -o $@ $^

# -lm should be last. Otherwise it doesn't get included in the ld table
$(LIB_shared): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@
