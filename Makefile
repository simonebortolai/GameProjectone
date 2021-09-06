
main: main.o printer.o misc.o element.o entity.o livingentity.o miscList.o bullet.o space2d.o room.o simpleMap.o map.o keymanager.o 
	g++ -o main main.o printer.o misc.o element.o entity.o livingentity.o miscList.o bullet.o space2d.o room.o simpleMap.o map.o keymanager.o -lcurses	

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

miscList.o: ./classes/miscList.cpp
	g++ -c -Wall ./classes/miscList.cpp

bullet.o: ./classes/entities/bullet.cpp
	g++ -c -Wall ./classes/entities/bullet.cpp

map.o: ./classes/map.cpp
	g++ -c -Wall ./classes/map.cpp

room.o: ./classes/room.cpp
	g++ -c -Wall ./classes/room.cpp

space2d.o: ./classes/space2d.cpp
	g++ -c -Wall ./classes/space2d.cpp

keymanager.o: ./classes/keymanager.cpp
	g++ -c -Wall ./classes/keymanager.cpp

simpleMap.o: ./classes/simpleMap.cpp
	g++ -c -Wall ./classes/simpleMap.cpp

element.o: ./classes/entities/element.cpp
	g++ -c -Wall ./classes/entities/element.cpp

clean:
	rm *.o