#include "DatabaseHandler.h"
#include <iostream>

using namespace std;


DatabaseHandler::DatabaseHandler(): DATABASE_FILENAME("tsp.sqlt") {}

void DatabaseHandler::OpenDatabase() {
    int status = sqlite3_open(DATABASE_FILENAME.c_str(), &db);
    if (status || db == NULL) {
        cerr << "Error opening db: "
            << sqlite3_errmsg(db) << endl;
    }
}

void DatabaseHandler::CloseDatabase() {
    int status = sqlite3_close(db);
    if (status != SQLITE_OK) {
        cerr << "Error closing database: " <<
            sqlite3_errmsg(db) << endl;
    }
}

void DatabaseHandler::Query(
    void* data,
    string query,
    int (*callback)(void*,int,char**,char**)) {
    
    char* errmsg;
    int status = sqlite3_exec(
        db,
        query.c_str(),
        callback,
        data,
        &errmsg
    );
    if (status != SQLITE_OK) {
        cerr << "Error reading from database: " <<
            errmsg << endl;
    }
}

int DatabaseHandler::CallbackPrintEdges(
    void* data, int argc, char** argv, char** colname) {
    
    for (int i=0; i<argc; i++) {
        cout << argv[i] << endl;
    }
    return 0;
}

void DatabaseHandler::PrintEdges() {
    const string QUERY_EDGES = "SELECT * FROM connections;";
    Query((void*)NULL, QUERY_EDGES, CallbackPrintEdges);
}

