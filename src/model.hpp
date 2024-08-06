
#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::vector;

class System;
class Flow;

class Model{
    private:
        vector<System*> systems;
        vector<Flow*> flows;

    public:
        Model();
        Model(const Model& other);
        Model& operator=(const Model& other);
        virtual ~Model();

        void add(System* system);
        void add(Flow* flow);
        void execute(int startTime, int endTime, int timeStep);
};

#endif