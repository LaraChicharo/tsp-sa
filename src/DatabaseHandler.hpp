#pragma once

#include "Graph.hpp"
#include <sqlite3.h>
#include <string>
#include <vector>


/// @brief Handles connection with the database.
class DatabaseHandler {
    private:
        const std::string DATABASE_FILENAME;
        /// Database object
        sqlite3* db;
    public:
        DatabaseHandler();

        /// @brief Opens a connection with the database.
        void OpenDatabase();
        /// @brief Closes the current connection.
        void CloseDatabase();
        /// @brief Executes a query on the database.
        /// @param data     data to pass to callback
        /// @param query    the query in SQL language
        /// @param callback callback function to execute after
        /// the query is done
        void Query(
            void* data,
            std::string query,
            int(*callback)(void*,int,char**,char**)
        );
        /// @brief Function to be called after a query is executed
        /// that prints all of the edges in the database.
        static int CallbackPrintEdges(
            void* data, int argc, char** argv, char** colname
        );
        /// @brief Returns the edges contained in the database.
        std::vector<std::pair<std::pair<int, int>, double>> GetEdges();
        /// @brief Returns the vertices in the database.
        std::vector<Vertice> GetVertices();
};
