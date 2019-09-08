SRC_DIR = src


main: DatabaseHandler.o Graph.o Metrologist.o GraphFiller.o Solution.o Reader.o WorldBuilder.o Temperature.o SimulatedAnnealing.o $(SRC_DIR)/main.cpp
	g++ $(SRC_DIR)/main.cpp DatabaseHandler.o Graph.o Metrologist.o Solution.o WorldBuilder.o Reader.o GraphFiller.o Temperature.o SimulatedAnnealing.o -l sqlite3 -o main

DatabaseHandler.o: $(SRC_DIR)/DatabaseHandler.h $(SRC_DIR)/DatabaseHandler.cpp  $(SRC_DIR)/Constants.h
	g++ -c $(SRC_DIR)/DatabaseHandler.cpp

Graph.o: $(SRC_DIR)/Graph.h $(SRC_DIR)/Graph.cpp $(SRC_DIR)/Constants.h
	g++ -c $(SRC_DIR)/Graph.cpp

Metrologist.o: $(SRC_DIR)/Constants.h $(SRC_DIR)/Metrologist.h $(SRC_DIR)/Metrologist.cpp $(SRC_DIR)/earth.h
	g++ -c $(SRC_DIR)/Metrologist.cpp

GraphFiller.o: $(SRC_DIR)/GraphFiller.cpp $(SRC_DIR)/GraphFiller.h
	g++ -c $(SRC_DIR)/GraphFiller.cpp

Solution.o: $(SRC_DIR)/Solution.cpp $(SRC_DIR)/Solution.h $(SRC_DIR)/Metrologist.h
	g++ -c $(SRC_DIR)/Solution.cpp

Reader.o: $(SRC_DIR)/Reader.cpp $(SRC_DIR)/Reader.h
	g++ -c $(SRC_DIR)/Reader.cpp

WorldBuilder.o: $(SRC_DIR)/WorldBuilder.cpp $(SRC_DIR)/WorldBuilder.h
	g++ -c $(SRC_DIR)/WorldBuilder.cpp

Temperature.o: $(SRC_DIR)/Temperature.cpp $(SRC_DIR)/Temperature.h
	g++ -c $(SRC_DIR)/Temperature.cpp

SimulatedAnnealing.o: $(SRC_DIR)/SimulatedAnnealing.cpp $(SRC_DIR)/SimulatedAnnealing.h
	g++ -c $(SRC_DIR)/SimulatedAnnealing.cpp


clean:
	rm -f main *.o *.ghc

