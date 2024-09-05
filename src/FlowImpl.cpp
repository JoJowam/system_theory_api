#include "FlowImpl.hpp"

const string& FlowBody::getName() const {
    return name;
}

void FlowBody::setName(const string& name) {
    this->name = name;
}

void FlowBody::setSource(System* source) {
    this->source = source;
}

void FlowBody::setDestination(System* destination) {
    this->destination = destination;
}

System* FlowBody::getSource() const {
    return source;
}

System* FlowBody::getDestination() const {
    return destination;
}
