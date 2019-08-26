SRC_DIR = src


main: DatabaseHandler.o Graph.o Metrologist.o $(SRC_DIR)/main.cpp
	g++ $(SRC_DIR)/main.cpp DatabaseHandler.o Graph.o Metrologist.o -l sqlite3 -o main

DatabaseHandler.o: $(SRC_DIR)/DatabaseHandler.h $(SRC_DIR)/DatabaseHandler.cpp
	g++ -c $(SRC_DIR)/DatabaseHandler.cpp

Graph.o: $(SRC_DIR)/Graph.h $(SRC_DIR)/Graph.cpp
	g++ -c $(SRC_DIR)/Graph.cpp

Metrologist.o: $(SRC_DIR)/Constants.h $(SRC_DIR)/Metrologist.h $(SRC_DIR)/Metrologist.cpp
	g++ -c $(SRC_DIR)/Metrologist.cpp

clean:
	rm -f main *.o *.ghc

