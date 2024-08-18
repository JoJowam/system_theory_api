#include "UnitSystem.hpp"
#include <cassert>
#include <iostream>

void UnitSystem::runTests() {
    testGetName();
    testGetValue();
    testSetValue();
}

void UnitSystem::testGetName() {
    SystemImpl system("TestSystem", 100.0);
    assert(system.getName() == "TestSystem");

    std::cout << "System::getName() passed.\n";
}

void UnitSystem::testGetValue() {
    SystemImpl system("TestSystem", 100.0);
    assert(system.getValue() == 100.0);

    std::cout << "System::getValue() passed.\n";
}

void UnitSystem::testSetValue() {
    SystemImpl system("TestSystem", 100.0);
    system.setValue(200.0);
    assert(system.getValue() == 200.0);

    std::cout << "System::setValue() passed.\n";
}
