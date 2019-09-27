SRC_DIR = src
BIN_DIR = build


main: DatabaseHandler.o Graph.o Metrologist.o GraphFiller.o Solution.o Reader.o WorldBuilder.o Temperature.o SimulatedAnnealing.o Journal.o $(SRC_DIR)/main.cpp
	g++ $(SRC_DIR)/main.cpp $(BIN_DIR)/DatabaseHandler.o $(BIN_DIR)/Graph.o $(BIN_DIR)/Metrologist.o $(BIN_DIR)/Solution.o $(BIN_DIR)/WorldBuilder.o $(BIN_DIR)/Reader.o $(BIN_DIR)/GraphFiller.o $(BIN_DIR)/Temperature.o $(BIN_DIR)/SimulatedAnnealing.o $(BIN_DIR)/Journal.o -l sqlite3 -o main

DatabaseHandler.o: $(SRC_DIR)/DatabaseHandler.hpp $(SRC_DIR)/DatabaseHandler.cpp  $(SRC_DIR)/Constants.hpp
	g++ -c $(SRC_DIR)/DatabaseHandler.cpp -o $(BIN_DIR)/DatabaseHandler.o

Graph.o: $(SRC_DIR)/Graph.hpp $(SRC_DIR)/Graph.cpp $(SRC_DIR)/Constants.hpp
	g++ -c $(SRC_DIR)/Graph.cpp -o $(BIN_DIR)/Graph.o

Metrologist.o: $(SRC_DIR)/Constants.hpp $(SRC_DIR)/Metrologist.hpp $(SRC_DIR)/Metrologist.cpp $(SRC_DIR)/earth.hpp
	g++ -c $(SRC_DIR)/Metrologist.cpp -o $(BIN_DIR)/Metrologist.o

GraphFiller.o: $(SRC_DIR)/GraphFiller.cpp $(SRC_DIR)/GraphFiller.hpp
	g++ -c $(SRC_DIR)/GraphFiller.cpp -o $(BIN_DIR)/GraphFiller.o

Solution.o: $(SRC_DIR)/Solution.cpp $(SRC_DIR)/Solution.hpp $(SRC_DIR)/Metrologist.hpp
	g++ -c $(SRC_DIR)/Solution.cpp -o $(BIN_DIR)/Solution.o

Reader.o: $(SRC_DIR)/Reader.cpp $(SRC_DIR)/Reader.hpp
	g++ -c $(SRC_DIR)/Reader.cpp -o $(BIN_DIR)/Reader.o

WorldBuilder.o: $(SRC_DIR)/WorldBuilder.cpp $(SRC_DIR)/WorldBuilder.hpp
	g++ -c $(SRC_DIR)/WorldBuilder.cpp -o $(BIN_DIR)/WorldBuilder.o

Temperature.o: $(SRC_DIR)/Temperature.cpp $(SRC_DIR)/Temperature.hpp
	g++ -c $(SRC_DIR)/Temperature.cpp -o $(BIN_DIR)/Temperature.o

SimulatedAnnealing.o: $(SRC_DIR)/SimulatedAnnealing.cpp $(SRC_DIR)/SimulatedAnnealing.hpp
	g++ -c $(SRC_DIR)/SimulatedAnnealing.cpp -o $(BIN_DIR)/SimulatedAnnealing.o

Journal.o: $(SRC_DIR)/Journal.cpp $(SRC_DIR)/Journal.hpp
	g++ -c $(SRC_DIR)/Journal.cpp -o $(BIN_DIR)/Journal.o

clean:
	rm -f main $(BIN_DIR)/*.o $(BIN_DIR)/*.ghc

