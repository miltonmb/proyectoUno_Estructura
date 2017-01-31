lista:	ADTList.o LinkedList.o nodo.o object.o employee.o main.o
	g++ ADTList.o LinkedList.o nodo.o object.o employee.o main.o -o lista

main.o:	ADTList.h LinkedList.h object.h nodo.hma main.cpp employee.h
	g++ -c main.cpp

LinkedList.o:	ADTList.h LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

ADTList.o:	ADTList.h ADTList.cpp object.h
	g++ -c ADTList.cpp

nodo.o:	nodo.h nodo.cpp
	g++ -c nodo.cpp

employee.o:	employee.h employee.cpp object.h
	g++ -c employee.cpp

Object.o:	object.h object.cpp
	g++ -c object.cpp

clean:
	rm -f *.o lista