SRC_FILES = $(wildcard src/*.c)
INC_DIRS = inc

TST_SRC_FILES = $(wildcard test/libs/Unity/src/*.c)
TST_SRC_FILES += $(wildcard test/*.c)
TST_INC_DIRS = test/libs/Unity/src

PROJ = test
OBJ_DIR = build
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))
TST_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(TST_SRC_FILES:.c=.o))
TST_OUT = $(OBJ_DIR)/$(PROJ)-test.out

CFLAGS += -g -Wall
CFLAGS += $(addprefix -I,$(INC_DIRS))
TST_CFLAGS = $(addprefix -I,$(TST_INC_DIRS))
LDFLAGS += -lm

.PHONY: all test clean

all: $(TST_OUT)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	gcc -c $(TST_CFLAGS) $(CFLAGS) $< -o $@

$(TST_OUT): $(OBJ_FILES) $(TST_OBJ_FILES)
	gcc $^ $(LDFLAGS) -o $@

test: $(TST_OUT)
	./$(TST_OUT)

clean:
	rm -rf $(OBJ_DIR)
