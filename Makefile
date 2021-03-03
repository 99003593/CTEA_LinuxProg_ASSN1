SRC_FILES = $(wildcard test/libs/Unity/src/*.c)
SRC_FILES += $(wildcard test/*.c)
INC_DIRS = test/libs/Unity/src

PROJ = libs
LIBS = mystr myutils masking
OBJ_DIR = build
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))
TST_OUT = $(OBJ_DIR)/$(PROJ)-test.out

CFLAGS += -g -Wall
CFLAGS += $(addprefix -I,$(INC_DIRS))

LIB_DIR := $(abspath $(OBJ_DIR))
CFLAGS += $(addsuffix /inc,$(addprefix -I,$(LIBS)))
LDFLAGS += $(addprefix -L$(LIB_DIR)/,$(LIBS))
LDFLAGS += $(addprefix -l,$(LIBS))
LDFLAGS += -lm

.PHONY: all libs test clean

all: libs $(TST_OUT)

libs:
	@for i in $(LIBS); do \
		$(MAKE) -C $$i lib BUILD_DIR=$(LIB_DIR)/$$i; \
	done

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	gcc -c $(CFLAGS) $< -o $@

$(TST_OUT): $(OBJ_FILES)
	gcc $^ $(LDFLAGS) -o $@

test: libs $(TST_OUT)
	./$(TST_OUT)

clean:
	rm -rf $(OBJ_DIR)
