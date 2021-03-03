SRC_FILES = $(wildcard test/libs/Unity/src/*.c)
SRC_FILES += $(wildcard test/*.c)
INC_DIRS = test/libs/Unity/src

PROJ = libs
LINKMODE ?= shared
LIBS = mystr myutils masking
OBJ_DIR = build
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))
TST_OUT = $(OBJ_DIR)/$(PROJ)-$(LINKMODE)-test.out

CFLAGS += -g -Wall
CFLAGS += $(addprefix -I,$(INC_DIRS))

LIB_DIR := $(abspath $(OBJ_DIR))
CFLAGS += $(addsuffix /inc,$(addprefix -I,$(LIBS)))
LDFLAGS += -L$(LIB_DIR)
LDFLAGS += $(addprefix -l,$(LIBS))
LDFLAGS += -lm
ifeq ($(LINKMODE),static)
    LDFLAGS += -$(LINKMODE)
endif

.PHONY: all libs test clean cleanall

all: libs $(TST_OUT)

libs:
	@for i in $(LIBS); do \
		$(MAKE) -C $$i install LINKMODE=$(LINKMODE) BUILD_DIR=$(LIB_DIR)/$$i INSTALL_DIR=$(LIB_DIR); \
	done

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	gcc -c $(CFLAGS) $< -o $@

$(TST_OUT): $(OBJ_FILES)
	gcc $^ $(LDFLAGS) -o $@

test: libs $(TST_OUT)
	LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:$(LIB_DIR) ./$(TST_OUT)

clean:
	rm -rf $(OBJ_FILES) $(TST_OUT)

cleanall:
	rm -rf $(OBJ_DIR)
