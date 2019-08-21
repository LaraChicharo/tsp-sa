main: DatabaseHandler.o main.cpp
	g++ main.cpp DatabaseHandler.o -l sqlite3 -o main

interface_db.o: DatabaseHandler.h DatabaseHandler.cpp
	g++ -c DatabaseHandler.cpp

clean:
	rm -f main *.o *.ghc
