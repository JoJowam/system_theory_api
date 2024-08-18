#include "SystemImpl.hpp"

SystemImpl::SystemImpl() 
    : name(""), value(0.0) {}

SystemImpl::SystemImpl(const string& name) 
    : name(name), value(0.0) {}

SystemImpl::SystemImpl(const string& name, double value) 
    : name(name), value(value) {}

SystemImpl::SystemImpl(const SystemImpl& other) 
    : name(other.name), value(other.value) {}

SystemImpl& SystemImpl::operator=(const SystemImpl& other) {
    if (this != &other) {
        name = other.name;
        value = other.value;
    }
    return *this;
}

SystemImpl::~SystemImpl() {}

const string SystemImpl::getName() const {
    return name;
}

double SystemImpl::getValue() const {
    return value;
}

void SystemImpl::setValue(double value) {
    this->value = value;
}
