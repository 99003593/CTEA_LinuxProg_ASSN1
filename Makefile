SRC = libs/Unity/src/unity.c \
		src/bitmask.c \
		src/mystring.c \
		src/myutils.c \
		src/test.c

INC = -Ilibs/Unity/src/ -Iinc

.PHONY: all run clean

test.out: $(SRC)
	gcc -c $^ $(INC)
	gcc *.o -lm -o $@

all: test.out

run: test.out
	./$^

clean:
	rm -rf *.o test.out
