#ifndef FLOW_IMPL_HPP
#define FLOW_IMPL_HPP

#include "Flow.hpp"
#include "system.hpp"

/**
 * @class FlowImpl
 * @brief Concrete implementation of the Flow interface.
 * @details FlowImpl provides a basic implementation of the Flow interface, allowing for 
 * the creation of specific flow types by extending this class. It manages the name of the flow, 
 * as well as the source and destination systems between which the flow occurs.
 * 
 * @note This class can be extended to create specific types of flows by overriding the `equation` method.
 * 
 * @see Flow
 * @see System
 * @author Josué Vila Real de Almeida
 * @date 2024-08-18
 * @version 0.1.3
 */
class FlowImpl : public Flow {
    friend class UnitFlow;

    protected:
        string name;            /**< Name of the flow. */
        System* source;         /**< A pointer to the source system of the flow. */
        System* destination;    /**< A pointer to the destination system of the flow. */

    public:

        /**
         * @brief Default constructor for the FlowImpl class.
         * @details Initializes a FlowImpl object with an empty name and null pointers for the source and destination systems.
         * 
         * @note This constructor allows the creation of a FlowImpl instance without immediately specifying the source and destination systems.
         * 
         * @code
         * FlowImpl flow;
         * flow.setName("Example Flow");
         * @endcode
         */
        FlowImpl();

        /**
         * @brief Constructs a FlowImpl with a specified name, source, and destination systems.
         * @details If the source or destination is not provided, they are initialized to null.
         * @param name The name identifier for the flow.
         * @param source Pointer to the source system (optional, default is nullptr).
         * @param destination Pointer to the destination system (optional, default is nullptr).
         * 
         * @note This constructor is useful when the source and destination systems are known at the time of flow creation.
         * 
         * @code
         * System* sourceSystem = new System("Source");
         * System* destinationSystem = new System("Destination");
         * FlowImpl flow("My Flow", sourceSystem, destinationSystem);
         * @endcode
         * 
         * @see System
         */
        FlowImpl(const string& name, System* source = nullptr, System* destination = nullptr);

        /**
         * @brief Copy constructor for the FlowImpl class.
         * @details Initializes a FlowImpl object as a copy of another FlowImpl object, duplicating the name, source, and destination.
         * @param other FlowImpl object to copy.
         * 
         * @note The copy constructor ensures that a shallow copy of the FlowImpl object is made.
         * 
         * @code
         * FlowImpl originalFlow("Original Flow");
         * FlowImpl copiedFlow = originalFlow;
         * @endcode
         */
        FlowImpl(const FlowImpl& other);

        /**
         * @brief Assignment operator for the FlowImpl class.
         * @details Assigns one FlowImpl object to another, ensuring proper handling of dynamic memory and object state.
         * @param other Another instance of FlowImpl to be assigned.
         * @return A reference to this FlowImpl instance.
         * 
         * @note The assignment operator should handle self-assignment and ensure that all resources are properly managed.
         * 
         * @code
         * FlowImpl flow1("Flow 1");
         * FlowImpl flow2 = flow1;
         * @endcode
         */
        FlowImpl& operator=(const FlowImpl& other);

        /**
         * @brief Destructor for the FlowImpl class.
         * @details Ensures that resources allocated by the FlowImpl instance are properly cleaned up.
         * 
         * @note The destructor must ensure that any dynamic memory or resources are released to avoid memory leaks.
         */
        virtual ~FlowImpl();

        /**
         * @brief Retrieves the name of the flow.
         * @return The flow's name as a constant reference to a string.
         * 
         * @note The name is used for identifying different flows in the simulation.
         */
        const string& getName() const override;

        /**
         * @brief Sets the source system of the flow.
         * @param source A pointer to the source system.
         * @return None.
         * 
         * @note Changing the source system can significantly affect the outcome of the flow calculations.
         */
        void setSource(System* source) override;

        /**
         * @brief Sets the destination system of the flow.
         * @param destination A pointer to the destination system.
         * @return None.
         * 
         * @note Ensure that the destination system is appropriately set to accurately model the flow within the simulation.
         */
        void setDestination(System* destination) override;

        /**
         * @brief Gets the source system of the flow.
         * @return A pointer to the source system.
         * 
         * @note The source system is where the flow originates and is integral to the flow's behavior.
         */
        System* getSource() const override;

        /**
         * @brief Gets the destination system of the flow.
         * @return A pointer to the destination system.
         * 
         * @note The destination system is the target of the flow and must be set correctly for accurate simulation results.
         */
        System* getDestination() const override;

        /**
         * @brief Pure virtual method to calculate the flow.
         * @details Derived classes must implement this method to define the specific behavior of the flow.
         * @return The calculated value of the flow.
         * 
         * @note The `equation` method is the core of the flow's functionality, determining how resources or energy are transferred.
         */
        virtual double equation() const = 0;
};

#endif