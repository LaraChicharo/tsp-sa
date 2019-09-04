#include <iostream>
#include <vector>


class Reader {
    private:
        std::vector<int> instance_vertices;


    public:
        Reader(int argc, char** argv);
        std::vector<int> GetInstanceVertices() const;

};
