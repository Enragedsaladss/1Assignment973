CC = gcc

all: a1p2 a1p3

a1p2: a1p2.c
	$(CC) a1p2.c -o a1p2

a1p3: a1p3.c
	$(CC) a1p3.c -o a1p3 

clean:
	rm -f a1p2 a1p3 *.tar *.tar.gz

run-w: a1p2
	./a1p2 w

run-s: a1p2
	./a1p2 s

tar:
	tar -cvf genereux-a1.tar *

tar.gz:
	tar -czvf genereux-a1.tar.gz *

.PHONY: 
	all clean tar tar.gz
