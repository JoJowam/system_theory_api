#include "ModelImpl.hpp"
#include "SystemImpl.hpp"
#include "FlowImpl.hpp"

#include <algorithm>
#include <iostream>

Model* ModelHandle::_instance = nullptr;

Model* Model::getInstance() {
    if (ModelHandle::_instance == nullptr) {
        ModelHandle::_instance = new ModelHandle();
    }
    return ModelHandle::_instance;
}

Model* Model::createModel(const string& name) {
    return getInstance();
}

bool Model::deleteModel() {
    if (ModelHandle::_instance != nullptr) {
        delete ModelHandle::_instance;
        ModelHandle::_instance = nullptr;
        return true;
    }
    return false;
}

void ModelBody::add(System* system) {
    systems.push_back(system);
}

void ModelBody::add(Flow* flow) {
    flows.push_back(flow);
}

System* ModelBody::createSystem(const string& name, double value) {
    System* system = new SystemHandle(name, value);
    add(system);
    return system;
}

bool ModelBody::deleteSystem(System* system) {
    auto it = std::find(systems.begin(), systems.end(), system);
    if (it != systems.end()) {
        systems.erase(it);
        delete system;
        return true;
    }
    return false;
}

bool ModelBody::deleteFlow(Flow* flow) {
    auto it = std::find(flows.begin(), flows.end(), flow);
    if (it != flows.end()) {
        flows.erase(it);
        delete flow;
        return true;
    }
    return false;
}

// Métodos de acesso
void ModelBody::setName(const string& modelName) {
    name = modelName;
}

string ModelBody::getName() const {
    return name;
}

int ModelBody::getCurrentTime() const {
    return currentTime;
}

void ModelBody::setCurrentTime(int time) {
    currentTime = time;
}

void ModelBody::execute(int startTime, int endTime, int timeStep) {
    setCurrentTime(startTime);
    for (int currentTime = startTime + timeStep; currentTime <= endTime; currentTime += timeStep) {
        vector<double> systemValueChanges(systems.size(), 0.0);

        for (Flow* currentFlow : flows) {
            if (currentFlow->getSource() && currentFlow->getDestination()) {
                double flowValue = currentFlow->equation();

                auto sourceIt = std::find(systems.begin(), systems.end(), currentFlow->getSource());
                auto destinationIt = std::find(systems.begin(), systems.end(), currentFlow->getDestination());

                int sourceIndex = std::distance(systems.begin(), sourceIt);
                int destinationIndex = std::distance(systems.begin(), destinationIt);

                systemValueChanges[sourceIndex] -= flowValue;
                systemValueChanges[destinationIndex] += flowValue;
            }
        }

        auto systemIt = systems.begin();
        auto valueChangeIt = systemValueChanges.begin();

        while (systemIt != systems.end() && valueChangeIt != systemValueChanges.end()) {
            (*systemIt)->setValue((*systemIt)->getValue() + *valueChangeIt);
            ++systemIt;
            ++valueChangeIt;
        }

        setCurrentTime(currentTime);
    }
}
