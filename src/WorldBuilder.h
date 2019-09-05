#include "GraphFiller.h"
#include "Solution.h"
#ifndef METROLOGIST_H
    #include "Metrologist.h"
#endif
#include "Reader.h"


class WorldBuilder {
    private:
        Reader* reader;

    public:
        WorldBuilder(Reader* reader);

        Solution BuildFirstSolution() const;

};
