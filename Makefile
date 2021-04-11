go: 
	g++ -Wall main.cpp ./classes/bullet.cpp ./classes/entity.cpp ./classes/interaction.cpp ./classes/keymanager.cpp ./classes/map.cpp ./classes/misc.cpp ./classes/people.cpp ./classes/printer.cpp ./classes/room.cpp

clean:
	rm *.o