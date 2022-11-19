  #-*- Makefile -*-


memo: memo.o libmemo.o
	gcc -o memo memo.o libmemo.o
memo.o: memo.c
	gcc -c memo.c 
libmemo.o: libmemo.c memo.h
	gcc -c libmemo.c


clean:
	rm -f *.o 
	

