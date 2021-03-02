SRC_FILES = $(wildcard src/*.c)
SRC_FILES += $(wildcard libs/Unity/src/*.c)
INC_DIRS = inc libs/Unity/src

PROJ = test
OBJ_DIR = build
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))
OUT_FILE = $(OBJ_DIR)/$(PROJ).out

CFLAGS += -g -Wall
CFLAGS += $(addprefix -I,$(INC_DIRS))
LDFLAGS += -lm

.PHONY: all run clean

all: $(OUT_FILE)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	gcc -c $(CFLAGS) $< -o $@

$(OUT_FILE): $(OBJ_FILES)
	gcc $(OBJ_FILES) $(LDFLAGS) -o $@

run: $(OUT_FILE)
	./$(OUT_FILE)

clean:
	rm -rf $(OBJ_DIR)
