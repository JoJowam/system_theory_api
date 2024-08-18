#ifndef UNIT_MODEL_HPP
#define UNIT_MODEL_HPP

#include "../../src/ModelImpl.hpp"
#include "../../src/SystemImpl.hpp"
#include "../../src/FlowImpl.hpp"

#include <cassert>
#include <iostream>
#include <vector>

using std::vector;
using std::string;

/**
 * @class UnitModel
 * @brief Unit tests for the Model class.
 * @details Implements unit tests for the Model class where individual methods 
 * are tested. This class includes tests for methods like setName, addSystem, addFlow, execute, getSystems, and getFlows.
 * @see ModelImpl
 * 
 * @section Tests
 * This class contains various tests to validate the functionality of the Model 
 * class. Each test checks a specific method of the Model class for correctness.
 * 
 * @note Ensure that the ModelImpl objects are properly instantiated before 
 * running these tests.
 * @warning These tests assume that the ModelImpl class is correctly implemented 
 * and follows the expected behavior of the Model interface.
 * 
 * @version 0.0.1
*/
class UnitModel {
    public:
        /**
         * @brief Runs all unit tests for the Model class.
         * @details Calls all test methods in the class and outputs the results.
         * @pre ModelImpl objects must be properly instantiated before running these tests.
         * @post All test results are outputted to the console. Any failed assertions will terminate the program.
         * @assert All assertions in the test methods should pass for the tests to be considered successful.
         * @test Executes all individual test methods to ensure comprehensive testing of the Model class.
        */
        void runTests();
    private:
        /**
         * @brief Tests the setName method.
         * @details Creates a ModelImpl object and tests if the setName and getName methods correctly set and return the model name.
         * @pre A ModelImpl object must be instantiated.
         * @post The name returned by getName should match the name set by setName.
         * @assert The returned name should be "TestModel".
         * @test Validates the setName and getName methods of the ModelImpl class.
        */
        void testSetName();

        /**
         * @brief Tests the getName method.
         * @details Creates a ModelImpl object and tests if the getName method correctly returns the model name.
         * @pre A ModelImpl object must be instantiated.
         * @post The name returned by getName should be an empty string.
         * @assert The returned name should be an empty string.
         * @test Validates the getName method of the ModelImpl class.
        */
        void testGetName();
        /**
         * @brief Tests the addSystem method.
         * @details Creates a ModelImpl object and adds a SystemImpl object to it, then tests if the system is correctly added.
         * @pre A ModelImpl object must be instantiated.
         * @post The systems vector in the ModelImpl object should contain the added SystemImpl object.
         * @assert The size of the systems vector should be 1 and the contained object should match the added system.
         * @test Validates the addSystem method of the ModelImpl class.
        */
        void testAddSystem();

        /**
         * @brief Tests the addFlow method.
         * @details Creates a ModelImpl object and adds a FlowImpl object to it, then tests if the flow is correctly added.
         * @pre A ModelImpl object must be instantiated.
         * @post The flows vector in the ModelImpl object should contain the added FlowImpl object.
         * @assert The size of the flows vector should be 1 and the contained object should match the added flow.
         * @test Validates the addFlow method of the ModelImpl class.
        */
        void testAddFlow();

        /**
         * @brief Tests the execute method.
         * @details Creates a ModelImpl object, adds SystemImpl and FlowImpl objects to it, and tests if the execute method correctly updates system values.
         * @pre A ModelImpl object must be instantiated with valid SystemImpl and FlowImpl objects added.
         * @post The values of the systems should be updated according to the flow equations after execution.
         * @assert The value of the source system should decrease and the value of the destination system should increase.
         * @test Validates the execute method of the ModelImpl class.
        */
        void testExecute();

        /**
         * @brief Tests the getSystems method.
         * @details Creates a ModelImpl object and adds multiple SystemImpl objects to it, then tests if the getSystems method returns all systems correctly.
         * @pre A ModelImpl object must be instantiated with multiple SystemImpl objects added.
         * @post The systems vector returned by getSystems should contain all added SystemImpl objects.
         * @assert The size of the returned systems vector should match the number of added systems.
         * @test Validates the getSystems method of the ModelImpl class.
        */
        void testGetSystems();

        /**
         * @brief Tests the getFlows method.
         * @details Creates a ModelImpl object and adds multiple FlowImpl objects to it, then tests if the getFlows method returns all flows correctly.
         * @pre A ModelImpl object must be instantiated with multiple FlowImpl objects added.
         * @post The flows vector returned by getFlows should contain all added FlowImpl objects.
         * @assert The size of the returned flows vector should match the number of added flows.
         * @test Validates the getFlows method of the ModelImpl class.
        */
        void testGetFlows();

        /**
         * @brief Tests the getCurrentTime method.
         * @details Creates a ModelImpl object and tests if the getCurrentTime method returns the correct current time.
         * @pre A ModelImpl object must be instantiated.
         * @post The current time returned by getCurrentTime should be 0.
         * @assert The returned current time should be 0.
         * @test Validates the getCurrentTime method of the ModelImpl class.
        */
        void testGetCurrentTime();

        /**
         * @brief Tests the setCurrentTime method.
         * @details Creates a ModelImpl object and sets a new current time, then tests if the setCurrentTime method correctly updates the current time.
         * @pre A ModelImpl object must be instantiated.
         * @post The current time returned by getCurrentTime should match the new time set by setCurrentTime.
         * @assert The returned current time should be 10.
         * @test Validates the setCurrentTime method of the ModelImpl class.
        */
        void testSetCurrentTime();
};

#endif
