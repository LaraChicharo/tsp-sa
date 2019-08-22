#include <sqlite3.h>
#include <string>
#include <vector>


class DatabaseHandler {
    private:
        const std::string DATABASE_FILENAME;
        sqlite3* db;
    public:
        DatabaseHandler();

        void OpenDatabase();
        void CloseDatabase();
        void Query(
            void* data,
            std::string query,
            int(*callback)(void*,int,char**,char**)
        );
        static int CallbackPrintEdges(
            void* data, int argc, char** argv, char** colname
        );
        std::vector<std::pair<std::pair<int, int>, double>> GetEdges();
};
