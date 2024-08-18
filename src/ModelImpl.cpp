#include "ModelImpl.hpp"

ModelImpl::ModelImpl() {}

ModelImpl::ModelImpl(const ModelImpl& other) 
    : systems(other.systems), flows(other.flows) {}

ModelImpl& ModelImpl::operator=(const ModelImpl& other) {
    if (this != &other) {
        systems = other.systems;
        flows = other.flows;
    }
    return *this;
}

ModelImpl::~ModelImpl() {}

void ModelImpl::add(System* system) {
    systems.push_back(system);
}

void ModelImpl::add(Flow* flow) {
    flows.push_back(flow);
}

void ModelImpl::execute(int startTime, int endTime, int timeStep) {
    for (int currentTime = startTime + timeStep; currentTime <= endTime; currentTime += timeStep) {
        vector<double> systemValueChanges(systems.size(), 0.0);

        for (Flow* currentFlow : flows) {
            if (currentFlow->getSource() && currentFlow->getDestination()) {
                double flowValue = currentFlow->equation();

                auto sourceSystemIterator = std::find(systems.begin(), systems.end(), currentFlow->getSource());
                auto destinationSystemIterator = std::find(systems.begin(), systems.end(), currentFlow->getDestination());

                int sourceSystemIndex = std::distance(systems.begin(), sourceSystemIterator);
                int destinationSystemIndex = std::distance(systems.begin(), destinationSystemIterator);

                systemValueChanges[sourceSystemIndex] -= flowValue;
                systemValueChanges[destinationSystemIndex] += flowValue;
            }
        }

        for (size_t i = 0; i < systems.size(); ++i) {
            systems[i]->setValue(systems[i]->getValue() + systemValueChanges[i]);
        }
    }
}
