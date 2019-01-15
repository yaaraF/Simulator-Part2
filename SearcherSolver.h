

#ifndef PART2_SEARCHERSOLVER_H
#define PART2_SEARCHERSOLVER_H

#include "Solver.h"
#include "Searcher.h"
#include "Searchable.h"

class SercherSolver:public Solver<Searchable<vector<int>>*,string>{
    Searcher<vector<int>>* searcher;

public:
    SercherSolver(Searcher<vector<int>> *searcher){
        this->searcher = searcher;
    }

    string solve(Searchable<vector<int>>* searchable) override {
      return this->searcher->search(searchable);
    }

    virtual ~SercherSolver() {

    }
};

#endif //PART2_SEARCHERSOLVER_H
