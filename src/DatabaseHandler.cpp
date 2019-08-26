#include "DatabaseHandler.h"
#include <iostream>

using namespace std;


DatabaseHandler::DatabaseHandler(): DATABASE_FILENAME("db/tsp.db") {}

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

vector<pair<pair<int, int>, double>> DatabaseHandler::GetEdges() {
    const string QUERY_EDGES = "SELECT * FROM connections;";
    int length_in_bytes = QUERY_EDGES.size();
    vector<pair<pair<int, int>, double>> edges;
    sqlite3_stmt *stmt;
    int status = sqlite3_prepare_v2(
        db, QUERY_EDGES.c_str(), length_in_bytes, &stmt, NULL);
    if (status != SQLITE_OK) {
        cerr << "Error reading from database: "
            << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
     }
     status = sqlite3_step(stmt);
     while (status == SQLITE_ROW) {
        int citya = sqlite3_column_int(stmt, 0);
        int cityb = sqlite3_column_int(stmt, 1);
        double distance = sqlite3_column_double(stmt, 2);
        edges.push_back({{citya, cityb}, distance});
        status = sqlite3_step(stmt);
     }
     if (status != SQLITE_ROW && status != SQLITE_DONE) {
        cerr << "Error reading from database: "
            << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
     }
     if (status == SQLITE_DONE) {
        sqlite3_finalize(stmt);
     }
     return edges;
}

pair<double, double> DatabaseHandler::GetCoordinates(int v) {
    string query_vertice =
        "SELECT latitude, longitude FROM cities WHERE id = ";
    query_vertice += (to_string(v) + ";");
    int length_in_bytes = query_vertice.size();
    pair<double, double> coordinates;
    sqlite3_stmt *stmt;
    int status = sqlite3_prepare_v2(
        db, query_vertice.c_str(), length_in_bytes, &stmt, NULL
    );
    if (status != SQLITE_OK) {
        cerr << "Error1 reading from database: "
            << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
    }
    status = sqlite3_step(stmt);
    double lat = sqlite3_column_double(stmt, 0);
    double lon = sqlite3_column_double(stmt, 1);
    coordinates = {lat, lon};
    status = sqlite3_step(stmt);
    
    if (status != SQLITE_ROW && status != SQLITE_DONE) {
        cerr << "Error reading from database: "
            << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
    }
    if (status == SQLITE_DONE) {
        sqlite3_finalize(stmt);
    }

    return coordinates;        
}

