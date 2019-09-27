#include "DatabaseHandler.hpp"
#include <iostream>
#include <string.h>

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

vector<Vertice> DatabaseHandler::GetVertices() {
    const string QUERY_VERTICES = "SELECT * FROM cities;";
    int length_in_bytes = QUERY_VERTICES.size();
    vector<Vertice> vertices;
    sqlite3_stmt *stmt;
    int status = sqlite3_prepare_v2(
        db, QUERY_VERTICES.c_str(), length_in_bytes, &stmt, NULL);
    if (status != SQLITE_OK) {
        cerr << "Error reading from database: "
            << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
     }
     status = sqlite3_step(stmt);
     while (status == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        long long population = sqlite3_column_int64(stmt, 3);
        double lat = sqlite3_column_double(stmt, 4);
        double lon = sqlite3_column_double(stmt, 5);
        Vertice v(id, lat, lon, population);
        vertices.push_back(v);
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
     return vertices;
}
