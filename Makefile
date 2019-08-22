SRC_DIR = src


main: DatabaseHandler.o $(SRC_DIR)/main.cpp
	g++ $(SRC_DIR)/main.cpp DatabaseHandler.o -l sqlite3 -o main

DatabaseHandler.o: $(SRC_DIR)/DatabaseHandler.h $(SRC_DIR)/DatabaseHandler.cpp
	g++ -c $(SRC_DIR)/DatabaseHandler.cpp

clean:
	rm -f main *.o *.ghc
