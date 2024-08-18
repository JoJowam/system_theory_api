#ifndef FLOW_IMPL_HPP
#define FLOW_IMPL_HPP

#include "Flow.hpp"
#include "system.hpp"

/**
 * @class FlowImpl
 * @brief Concrete implementation of the Flow interface.
 * @see Flow
 * @see System
 */
class FlowImpl : public Flow {
    friend class UnitFlow;
    protected:
        string name;            /**< Name of the flow. */
        System* source;         /**< A pointer to the Source system of the flow. */
        System* destination;    /**< A pointer to the Destination system of the flow. */

    public:

        /**
         * @brief Default constructor for the Flow class.
         * @details Initializes a Flow object with an empty name and null pointers for the source and destination systems.
        */
        FlowImpl();

        
        /**
         * @brief Constructs a Flow with a specified name, source, and destination systems.
         * @details If the source or destination is not provided, they are initialized to null.
         * @param name The name identifier for the flow.
         * @param source Pointer to the source system (optional, default is nullptr).
         * @param destination Pointer to the destination system (optional, default is nullptr).
        */
        FlowImpl(const string& name, System* source = nullptr, System* destination = nullptr);

        /**
         * @brief Copy constructor for the Flow class.
         * @details Initializes a Flow object as a copy of another Flow object.
         * @param other Flow object to copy.
        */
        FlowImpl(const FlowImpl& other);

        /**
         * @brief Assignment operator for the Flow class.
         * @details Assigns one Flow object to another.
         * @param other Another instance of Flow to be assigned.
         * @return A reference to this Flow instance.
        */
        FlowImpl& operator=(const FlowImpl& other);


        virtual ~FlowImpl();

        const string& getName() const override;
        void setSource(System* source) override;
        void setDestination(System* destination) override;
        System* getSource() const override;
        System* getDestination() const override;

        virtual double equation() const = 0;
};

#endif
