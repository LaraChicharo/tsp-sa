SRC_DIR = src


main: DatabaseHandler.o Graph.o Metrologist.o GraphFiller.o Solution.o Reader.o $(SRC_DIR)/main.cpp
	g++ $(SRC_DIR)/main.cpp DatabaseHandler.o Graph.o Metrologist.o Solution.o Reader.o GraphFiller.o -l sqlite3 -o main

DatabaseHandler.o: $(SRC_DIR)/DatabaseHandler.h $(SRC_DIR)/DatabaseHandler.cpp  $(SRC_DIR)/Constants.h
	g++ -c $(SRC_DIR)/DatabaseHandler.cpp

Graph.o: $(SRC_DIR)/Graph.h $(SRC_DIR)/Graph.cpp $(SRC_DIR)/Constants.h
	g++ -c $(SRC_DIR)/Graph.cpp

Metrologist.o: $(SRC_DIR)/Constants.h $(SRC_DIR)/Metrologist.h $(SRC_DIR)/Metrologist.cpp
	g++ -c $(SRC_DIR)/Metrologist.cpp

GraphFiller.o: $(SRC_DIR)/GraphFiller.cpp $(SRC_DIR)/GraphFiller.h
	g++ -c $(SRC_DIR)/GraphFiller.cpp

Solution.o: $(SRC_DIR)/Solution.cpp $(SRC_DIR)/Solution.h $(SRC_DIR)/Metrologist.h
	g++ -c $(SRC_DIR)/Solution.cpp

Reader.o: $(SRC_DIR)/Reader.cpp $(SRC_DIR)/Reader.h
	g++ -c $(SRC_DIR)/Reader.cpp

clean:
	rm -f main *.o *.ghc

