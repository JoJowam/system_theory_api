#ifndef FLOW_IMPL_HPP
#define FLOW_IMPL_HPP

#include "Flow.hpp"
#include "System.hpp"
#include "Bridge.hpp"

/**
 * @class FlowBody
 * @brief Implementation class for managing the internal state of a flow.
 * @details FlowBody encapsulates the core attributes and functionality of a flow, including its name,
 *          source system, and destination system. It provides methods to access and modify these attributes.
 *          This class is used internally by FlowHandle and is not directly exposed to the user.
 * 
 * @see FlowHandle
 * @see Body
 * @see System
 * @warning Ensure that FlowBody is properly managed by its associated Handle to maintain consistency and
 *          proper lifecycle management.
 */
class FlowBody : public Body {
    friend class UnitFlow;

    private:
        string name;
        System* source;
        System* destination;

    public:
        
        const string& getName() const;
        void setName(const string& name);

        void setSource(System* source);
        void setDestination(System* destination);

        System* getSource() const;
        System* getDestination() const;
};

/**
 * @class FlowHandle
 * @brief Handle class for managing access to the FlowBody instance.
 * @details FlowHandle acts as a wrapper for the FlowBody, implementing the Handle pattern. It provides
 *          the interface through which users interact with the flow, delegating all operations to the
 *          underlying FlowBody instance. This class ensures that the FlowBody is properly managed and
 *          adheres to the intended design pattern.
 * 
 * @see FlowBody
 * @see Handle
 */
class FlowHandle : public Flow, public Handle<FlowBody> {
    
    public:
        FlowHandle(const string& name = "", System* source = nullptr, System* destination = nullptr) {
            pImpl_->setName(name);
            pImpl_->setSource(source);
            pImpl_->setDestination(destination);
        }
        FlowHandle() = default;

        virtual ~FlowHandle() {}

        const string& getName() const { return pImpl_->getName(); }

        void setName(const string& name) { pImpl_->setName(name); }

        void setSource(System* source) { pImpl_->setSource(source); }

        void setDestination(System* destination) { pImpl_->setDestination(destination); }

        System* getSource() const { return pImpl_->getSource(); }

        System* getDestination() const { return pImpl_->getDestination(); }

        virtual double equation() const = 0;
};

#endif