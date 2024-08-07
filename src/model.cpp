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

                auto sourceSystemIterator = find(systems.begin(), systems.end(), currentFlow->getSource());
                auto destinationSystemIterator = find(systems.begin(), systems.end(), currentFlow->getDestination());

                int sourceSystemIndex = distance(systems.begin(), sourceSystemIterator);
                int destinationSystemIndex = distance(systems.begin(), destinationSystemIterator);

                systemValueChanges[sourceSystemIndex] -= flowValue;
                systemValueChanges[destinationSystemIndex] += flowValue;
            }
        }

        for (size_t i = 0; i < systems.size(); ++i) {
            systems[i]->setValue(systems[i]->getValue() + systemValueChanges[i]);
        }

        std::cout << "System States at time " << currentTime << ":" << std::endl;
        for (size_t i = 0; i < systems.size(); ++i) {
            std::cout << "System: " << systems[i]->getName() 
                      << ", Value: " << systems[i]->getValue() << std::endl;
        }
        std::cout << std::endl;
    }
}
