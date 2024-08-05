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

Model::~Model() {
    for (System* system : systems) {
        delete system;
    }
    for (Flow* flow : flows) {
        delete flow;
    }
}

void Model::add(System* system) {
    systems.push_back(system);
}

void Model::add(Flow* flow) {
    flows.push_back(flow);
}

void Model::execute(int startTime, int endTime, int timeStep) {
    for (int currentTime = startTime; currentTime <= endTime; currentTime += timeStep) {
        for (Flow* flow : flows) {
            if (flow->getSource() && flow->getDestination()){
                //TODO: iterate over all flows
                std::cout << "FlowName: " << flow->getName() << std::endl;

                flow->getDestination()->setValue(flow->getDestination()->getValue() + flow->equation());
                flow->getSource()->setValue(flow->getSource()->getValue() - flow->equation());
                
                std::cout << "DestinationValue: " << flow->getDestination()->getValue() << std::endl;
                std::cout << "SourceValue: " << flow->getSource()->getValue() << std::endl;
            }
        }
    }
}