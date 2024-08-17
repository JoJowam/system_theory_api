#include "system.hpp"

System::System() 
    : name(""), value(0.0) {}

System::System(const string& name) 
    : name(name), value(0.0) {}

System::System(const string& name, double value) 
    : name(name), value(value) {}

System::System(const System& other) 
    : name(other.name), value(other.value) {}

System& System::operator=(const System& other) {
    if (this != &other) {
        name = other.name;
        value = other.value;
    }
    return *this;
}

System::~System() {}

const string System::getName() const {
    return name;
}

double System::getValue() const {
    return value;
}

void System::setValue(double value) {
    this->value = value;
}