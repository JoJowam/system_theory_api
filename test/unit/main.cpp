#include "UnitFlow.hpp"
#include "UnitModel.hpp"
#include "UnitSystem.hpp"

int main() {
    UnitFlow unitFlow;
    UnitModel unitModel;
    UnitSystem unitSystem;

    unitFlow.runUnitTests();
    unitModel.runUnitTests();
    unitSystem.runUnitTests();

    return 0;
}
