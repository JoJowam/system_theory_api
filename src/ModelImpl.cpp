#include "ModelImpl.hpp"
#include "SystemImpl.hpp"
#include "FlowImpl.hpp"

#include <algorithm>
#include <iostream>

ModelImpl* ModelImpl::_instance = nullptr;

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

ModelImpl::~ModelImpl() {
    for (System* system : systems) {
        delete system;
    }
    for (Flow* flow : flows) {
        delete flow;
    }
}

ModelImpl* ModelImpl::getInstance(const string& name) {
    if (_instance == nullptr) {
        _instance = new ModelImpl(name);
    }
    return _instance;
}

bool ModelImpl::deleteInstance() {
    if (_instance) {
        delete _instance;
        _instance = nullptr;
        return true; 
    }
    return false;
}

Model* Model::createModel(const string& name) {
    return ModelImpl::getInstance(name);
}

bool Model::deleteModel() {
    return ModelImpl::deleteInstance();
}

System* ModelImpl::createSystem(const string& name, double value) {
    System* system = new SystemImpl(name, value);
    add(system);
    return system;
}

bool ModelImpl::deleteSystem(System* system) {
    SystemIterator iterator = std::find(systems.begin(), systems.end(), system);
    if (iterator != systems.end()) {
        systems.erase(iterator);
        delete system;
        return true;
    }
    return false;
}

bool ModelImpl::deleteFlow(Flow* flow) {
    FlowIterator iterator = std::find(flows.begin(), flows.end(), flow);
    if (iterator != flows.end()) {
        flows.erase(iterator);
        delete flow;
        return true;
    }
    return false;
}

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

int ModelImpl::getCurrentTime() const {
    return currentTime;
}

void ModelImpl::setCurrentTime(int time) {
    currentTime = time;
}

void ModelImpl::execute(int startTime, int endTime, int timeStep){
    setCurrentTime(startTime);
    for (int currentTime = startTime + timeStep; currentTime <= endTime; currentTime += timeStep){
        vector<double> systemValueChanges(systems.size(), 0.0);

        for (Flow *currentFlow : flows){
            if (currentFlow->getSource() && currentFlow->getDestination()){
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

        while (systemIt != systems.end() && valueChangeIt != systemValueChanges.end()){
            (*systemIt)->setValue((*systemIt)->getValue() + *valueChangeIt);
            ++systemIt;
            ++valueChangeIt;
        }

        setCurrentTime(currentTime);
    }
}
