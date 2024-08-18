#include "UnitFlow.hpp"
#include "UnitModel.hpp"
#include "UnitSystem.hpp"

int main() {
    UnitFlow unitFlow;
    UnitModel unitModel;
    UnitSystem unitSystem;

    unitFlow.runTests();

    unitModel.runTests();

    unitSystem.runTests();

    return 0;
}
