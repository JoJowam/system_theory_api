#include "ModelImpl.hpp"
#include <iostream>

ModelImpl::ModelImpl() : name(""), currentTime(0) {}

ModelImpl::ModelImpl(const string& name) : name(name), currentTime(0) {}

ModelImpl::ModelImpl(const ModelImpl& other) 
    : name(other.name), systems(other.systems), flows(other.flows), currentTime(other.currentTime) {}

ModelImpl& ModelImpl::operator=(const ModelImpl& other) {
    if (this != &other) {
        name = other.name;
        systems = other.systems;
        flows = other.flows;
        currentTime = other.currentTime;
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

void ModelImpl::setName(const string& name) {
    this->name = name;
}

string ModelImpl::getName() const {
    return name;
}

vector<System*> ModelImpl::getSystems() const {
    return systems;
}

vector<Flow*> ModelImpl::getFlows() const {
    return flows;
}

int ModelImpl::getCurrentTime() const {
    return currentTime;
}

void ModelImpl::setCurrentTime(int time) {
    currentTime = time;
}

void ModelImpl::execute(int startTime, int endTime, int timeStep) {
    setCurrentTime(startTime);
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

        setCurrentTime(currentTime);
    }
}
