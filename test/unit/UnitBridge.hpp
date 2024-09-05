#ifndef UNIT_BRIDGE_HPP
#define UNIT_BRIDGE_HPP

#include "../../src/SystemImpl.hpp"

class UnitBridge {
    public:
        /**
         * @brief Runs all unit tests for the Flow class.
         * @pre The Flow class and its methods should be implemented.
         * @post All test methods are executed and results are displayed.
         * @assert All test methods should pass without assertion errors.
         * @test Calls each test method to verify the functionality of FlowImpl methods.
        */
        void runUnitTests();
    private:
        /**
         * @brief Tests the getName method of FlowImpl.
         * @pre A FlowImpl object should be created with a valid name.
         * @post The name returned should be the same as the one set.
         * @assert Expects getName() method to return "TestGetNameFlow".
         * @test Creates a FlowImpl object and tests the getName() method.
        */
        bool unit_testBridge();
};

#endif
