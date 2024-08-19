#ifndef UNIT_SYSTEM_HPP
#define UNIT_SYSTEM_HPP

#include "../../src/SystemImpl.hpp"

/**
 * @class UnitSystem
 * @brief Unit tests for the System class.
 * @details Implements unit tests for the System class where individual methods 
 * are tested. This class includes tests for methods like getName, getValue, and setValue.
 * @see SystemImpl
 * 
 * @section Tests
 * This class contains various tests to validate the functionality of the System 
 * class. Each test checks a specific method of the System class for correctness.
 * 
 * @note Ensure that the SystemImpl objects are properly instantiated before 
 * running these tests.
 * @warning These tests assume that the SystemImpl class is correctly implemented 
 * and follows the expected behavior of the System interface.
 * 
 * @author Josué Vila Real de Almeida
 * @date 2024-08-18
 * @version 0.0.1
*/
class UnitSystem {
    public:
        /**
         * @brief Runs all unit tests for the System class.
         * @details Calls all test methods in the class and outputs the results.
         * @pre SystemImpl objects must be properly instantiated before running these tests.
         * @post All test results are outputted to the console. Any failed assertions will terminate the program.
         * @assert All assertions in the test methods should pass for the tests to be considered successful.
         * @test Executes all individual test methods to ensure comprehensive testing of the System class.
        */
        void runUnitTests();

    private:
        /**
         * @brief Tests the getName method.
         * @details Creates a SystemImpl object with a specified name and tests if the getName method returns the correct name.
         * @pre A SystemImpl object must be instantiated with a valid name.
         * @post The name returned by getName should match the name used for object creation.
         * @assert The returned name should be "System1".
         * @test Validates the getName method of the SystemImpl class.
        */
        bool unit_testGetName();

        /**
         * @brief Tests the getValue method.
         * @details Creates a SystemImpl object with a specified name and value, then tests if the getValue method returns the correct value.
         * @pre A SystemImpl object must be instantiated with a valid name and value.
         * @post The value returned by getValue should match the value used for object creation.
         * @assert The returned value should be 100.0.
         * @test Validates the getValue method of the SystemImpl class.
        */
        bool unit_testGetValue();

        /**
         * @brief Tests the setValue method.
         * @details Creates a SystemImpl object with an initial value, sets a new value using setValue, and then verifies if the new value is correctly updated.
         * @pre A SystemImpl object must be instantiated with a valid name and an initial value.
         * @post The value set by setValue should be retrievable using getValue.
         * @assert The value retrieved using getValue should match the new value set by setValue.
         * @test Validates the setValue method of the SystemImpl class.
        */
        bool unit_testSetValue();
};

#endif
