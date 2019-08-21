#include "DatabaseHandler.h"
#include <iostream>
#include <vector>

using namespace std;


int main() {
    DatabaseHandler* dbh = new DatabaseHandler();
    dbh->OpenDatabase();
    dbh->PrintEdges();
    dbh->CloseDatabase();
}
