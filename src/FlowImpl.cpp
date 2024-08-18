#include "FlowImpl.hpp"

FlowImpl::FlowImpl() 
    : name(""), source(nullptr), destination(nullptr) {}

FlowImpl::FlowImpl(const string& name, System* source, System* destination) 
    : name(name), source(source), destination(destination) {}

FlowImpl::FlowImpl(const FlowImpl& other) 
    : name(other.name), source(other.source), destination(other.destination) {}

FlowImpl& FlowImpl::operator=(const FlowImpl& other) {
    if (this != &other) {
        name = other.name;
        source = other.source;
        destination = other.destination;
    }
    return *this;
}

FlowImpl::~FlowImpl() {}

const string& FlowImpl::getName() const {
    return name;
}

void FlowImpl::setSource(System* source) {
    this->source = source;
}

void FlowImpl::setDestination(System* destination) {
    this->destination = destination;
}

System* FlowImpl::getSource() const {
    return source;
}

System* FlowImpl::getDestination() const {
    return destination;
}
