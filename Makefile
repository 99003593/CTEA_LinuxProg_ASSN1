.PHONY: all run clean

all: test.out

unity.o:
	gcc -c libs/Unity/src/*.c -Ilibs/Unity/src/

test.out: unity.o
	gcc -c src/*.c -Iinc -Ilibs/Unity/src/
	gcc *.o -lm -o test.out

run: test.out
	./test.out

clean:
	rm -rf *.o test.out
