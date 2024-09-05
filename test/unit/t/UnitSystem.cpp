#include "UnitSystem.hpp"
#include "../../src/SystemImpl.hpp"

#include <cassert>
#include <iostream>

void UnitSystem::runUnitTests() {
    assert(unit_testGetName());
    assert(unit_testGetValue());
    assert(unit_testSetValue());
}

bool UnitSystem::unit_testGetName() {
    System* system = new SystemHandle("TestGetName_System");
    assert(system->getName() == "TestGetName_System");

    delete system;

    std::cout << "System::getName() passed.\n";

    return true;
}

bool UnitSystem::unit_testGetValue() {
    System* system = new SystemHandle("TestGetValue_System", 100.0);
    assert(system->getValue() == 100.0);

    delete system;

    std::cout << "System::getValue() passed.\n";

    return true;
}

bool UnitSystem::unit_testSetValue() {
    System* system = new SystemHandle("TestSetValue_System");
    system->setValue(200.0);
    assert(system->getValue() == 200.0);

    delete system;

    std::cout << "System::setValue() passed.\n";

    return true;
}
