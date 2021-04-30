main: main.o printer.o misc.o entity.o livingentity.o miscFunc.o
	g++ -o main main.o printer.o misc.o entity.o livingentity.o miscFunc.o -lcurses
	rm *.o

main.o: main.cpp
	g++ -c -Wall main.cpp

printer.o: ./classes/printer.cpp
	g++ -c -Wall ./classes/printer.cpp

misc.o: ./classes/misc.cpp
	g++ -c -Wall ./classes/misc.cpp

entity.o: ./classes/entity.cpp
	g++ -c -Wall ./classes/entity.cpp

livingentity.o: ./classes/livingentity.cpp
	g++ -c -Wall ./classes/livingentity.cpp

miscFunc.o: ./classes/miscFunc.cpp
	g++ -c -Wall ./classes/miscFunc.cpp

clean:
	rm *.o