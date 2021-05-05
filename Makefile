
main: main.o printer.o misc.o entity.o livingentity.o miscFunc.o bullet.o space2d.o room.o 
	g++ -o main main.o printer.o misc.o entity.o livingentity.o miscFunc.o bullet.o space2d.o room.o -lcurses
	rm *.o

main.o: main.cpp
	g++ -c -Wall main.cpp

printer.o: ./classes/printer.cpp
	g++ -c -Wall ./classes/printer.cpp

misc.o: ./classes/misc.cpp
	g++ -c -Wall ./classes/misc.cpp

entity.o: ./classes/entities/entity.cpp
	g++ -c -Wall ./classes/entities/entity.cpp

livingentity.o: ./classes/entities/livingentity.cpp
	g++ -c -Wall ./classes/entities/livingentity.cpp

miscFunc.o: ./classes/miscFunc.cpp
	g++ -c -Wall ./classes/miscFunc.cpp

bullet.o: ./classes/entities/bullet.cpp
	g++ -c -Wall ./classes/entities/bullet.cpp

map.o: ./classes/map.cpp
	g++ -c -Wall ./classes/map.cpp

room.o: ./classes/room.cpp
	g++ -c -Wall ./classes/room.cpp

space2d.o: ./classes/space2d.cpp
	g++ -c -Wall ./classes/space2d.cpp

clean:
	rm *.o