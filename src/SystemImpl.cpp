#include "SystemImpl.hpp"

const string SystemBody::getName() const { return name; }

double SystemBody::getValue() const { return value; }

void SystemBody::setName(const string& name) { this->name = name; }

void SystemBody::setValue(double value) { this->value = value; }