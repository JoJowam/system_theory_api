#include "model.hpp"
#include "system.hpp"
#include "flow.hpp"

Model::Model() {}

Model::Model(const Model& other) 
    : systems(other.systems), flows(other.flows) {}

Model& Model::operator=(const Model& other) {
    if (this != &other) {
        systems = other.systems;
        flows = other.flows;
    }
    return *this;
}

Model::~Model() {}

void Model::add(System* system) {
    systems.push_back(system);
}

void Model::add(Flow* flow) {
    flows.push_back(flow);
}

void Model::execute(int startTime, int endTime, int timeStep) {
    for (int currentTime = startTime + timeStep; currentTime <= endTime; currentTime += timeStep) {
        vector<double> systemValueChanges(systems.size(), 0.0);

        for (Flow* currentFlow : flows) {
            if (currentFlow->getSource() && currentFlow->getDestination()) {
                double flowValue = currentFlow->equation();

                SystemIterator sourceSystemIterator = find(systems.begin(), systems.end(), currentFlow->getSource());
                SystemIterator destinationSystemIterator = find(systems.begin(), systems.end(), currentFlow->getDestination());

                int sourceSystemIndex = distance(systems.begin(), sourceSystemIterator);
                int destinationSystemIndex = distance(systems.begin(), destinationSystemIterator);

                systemValueChanges[sourceSystemIndex] -= flowValue;
                systemValueChanges[destinationSystemIndex] += flowValue;
            }
        }
        
        SystemIterator systemIt = systems.begin();
        auto valueChangeIt = systemValueChanges.begin();

        while (systemIt != systems.end() && valueChangeIt != systemValueChanges.end()) {
            (*systemIt)->setValue((*systemIt)->getValue() + *valueChangeIt);
            ++systemIt;
            ++valueChangeIt;
        }
    }
}
