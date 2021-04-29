# GameProject

Divisione compiti:
Entità varie -> Simo/Ceci
Creazione livelli/mostri vari -> Simo/Ceci
Mappa/Rooms -> 
Controller/main/gestione varia -> 
Iterazione ->
Generazione mostri ->

To do:

Entità varie
Giocatore
Sparo
Mostri

# come compilare
- Se avete creato nuovi file che non sono in `classes/CMakeLists.txt`: 
    1. installate cmake `sudo apt install cmake` se già non lo avete
    2. aggiungere al file `classes/CMakeLists.txt` i file `.hpp` e `.cpp` che avete modificato (se non ci sono)
    3. eseguire il comando `cmake -S ./ -B ./` per generare il makefile
- altrimenti basta fare `make` e `./main`