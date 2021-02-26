main: height.o balanced.o nodeFree.o add.o search.o delete.o LNR.o NLR.o LRN.o treeFree.o main.o
	gcc -o plate nodeFree.o height.o balanced.o add.o search.o delete.o LNR.o NLR.o LRN.o treeFree.o main.o
height.o: height.c main.h
	gcc -c height.c
balanced.o: balanced.c main.h
	gcc -c balanced.c
add.o: add.c main.h
	gcc -c add.c
search.o: search.c main.h
	gcc -c search.c
delete.o: delete.c main.h
	gcc -c delete.c
LNR.o: LNR.c main.h
	gcc -c LNR.c
NLR.o: NLR.c main.h
	gcc -c NLR.c
LRN.o: LRN.c main.h
	gcc -c LRN.c
treeFree.o: treeFree.c main.h
	gcc -c treeFree.c
nodeFree.o: nodeFree.c main.h
	gcc -c nodeFree.c
main.o: main.c main.h
	gcc -c main.c
clean:
	rm plate nodeFree.o height.o balanced.o add.o search.o delete.o LNR.o NLR.o LRN.o treeFree.o main.o
