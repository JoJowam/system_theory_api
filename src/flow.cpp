#include "flow.hpp"

Flow::Flow() 
    : name(""), source(nullptr), destination(nullptr) {}

Flow::Flow(const string& name, System* source, System* destination) 
    : name(name), source(source), destination(destination) {}

Flow::Flow(const string& name) 
    : name(name), source(nullptr), destination(nullptr) {}

Flow::Flow(const Flow& other) 
    : name(other.name), source(other.source), destination(other.destination) {}

Flow& Flow::operator=(const Flow& other) {
    if (this != &other) {
        name = other.name;
        source = other.source;
        destination = other.destination;
    }
    return *this;
}

Flow::~Flow() {}

const string& Flow::getName() const {
    return name;
}

void Flow::setSource(System* source) {
    this->source = source;
}

void Flow::setDestination(System* destination) {
    this->destination = destination;
}

System* Flow::getSource() const {
    return source;
}

System* Flow::getDestination() const {
    return destination;
}