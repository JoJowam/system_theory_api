#ifndef UNIT_FLOW_HPP
#define UNIT_FLOW_HPP

#include "../../src/FlowImpl.hpp"
#include "../../src/SystemImpl.hpp"

#include <cassert>
#include <iostream>

/**
 * @class UnitFlow
 * @brief Unit tests for the Flow class.
 * @details Implements unit tests for the Flow class where individual 
 * methods are tested. This class includes tests for methods like getName, 
 * getSource, getDestination, setSource, setDestination, and equation.
 * @see FlowImpl
 * 
 * @section Tests
 * This class contains various tests to validate the functionality of the Flow 
 * class. Each test checks a specific method of the Flow class for correctness.
 * 
 * @note Ensure that the FlowImpl and System objects are properly instantiated 
 * before running these tests.
 * @warning These tests assume that the FlowImpl class is correctly implemented 
 * and follows the expected behavior of the Flow interface.
 * 
 * @author Josué Vila Real de Almeida
 * @date 2024-08-18
 * @version 0.0.1
*/
class UnitFlow {
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
        bool unit_testGetName();

        /**
         * @brief Tests the getSource method of FlowImpl.
         * @pre A FlowImpl object should be created with a source system.
         * @post The source system returned should be the same as the one set.
         * @assert Expects getSource() method to return the source system pointer.
         * @test Creates a FlowImpl object with a source system and tests the getSource() method.
        */
        bool unit_testGetSource();

        /**
         * @brief Tests the getDestination method of FlowImpl.
         * @pre A FlowImpl object should be created with a destination system.
         * @post The destination system returned should be the same as the one set.
         * @assert Expects getDestination() method to return the destination system pointer.
         * @test Creates a FlowImpl object with a destination system and tests the getDestination() method.
        */
        bool unit_testGetDestination();

        /**
         * @brief Tests the setSource method of FlowImpl.
         * @pre A FlowImpl object should be created.
         * @post The source system should be set and returned correctly by getSource().
         * @assert Expects getSource() method to return the newly set source system.
         * @test Creates a FlowImpl object, sets a source system, and verifies it with getSource().
        */
        bool unit_testSetSource();

        /**
         * @brief Tests the setDestination method of FlowImpl.
         * @pre A FlowImpl object should be created.
         * @post The destination system should be set and returned correctly by getDestination().
         * @assert Expects getDestination() method to return the newly set destination system.
         * @test Creates a FlowImpl object, sets a destination system, and verifies it with getDestination().
        */
        bool unit_testSetDestination();

        /**
         * @brief Tests the equation method of FlowImpl.
         * @pre A FlowImpl object should be created with necessary setup.
         * @post The equation method should return the expected value based on the implementation.
         * @assert Expects equation() method to return the correct calculated value "1.0".
         * @test Creates a FlowImpl object and verifies the equation method.
        */
        bool unit_testEquation();
};

#endif
