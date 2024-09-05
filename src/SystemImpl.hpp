#ifndef SYSTEM_IMPL_HPP
#define SYSTEM_IMPL_HPP

#include "System.hpp"
#include "Bridge.hpp"

using std::string;

/**
 * @class SystemBody
 * @brief Implementation class for managing the internal state of a system.
 * @details SystemBody encapsulates the core attributes and functionality of a system, including its name and value.
 *          It provides methods to access and modify these attributes. This class is intended for internal use by
 *          SystemHandle and is not exposed directly to the user.
 * 
 * @see SystemHandle
 * @see Body
 * @warning Ensure that SystemBody is properly managed by its associated Handle to maintain consistency and
 *          proper lifecycle management.
 */
class SystemBody : public Body{
    friend class UnitSystem;

    private:
        string name;
        double value;
    
    public:
        const string getName() const;
        void setName(const string& name);
        
        double getValue() const;
        void setValue(double value);
};

/**
 * @class SystemHandle
 * @brief Handle class for managing access to the SystemBody instance.
 * @details SystemHandle acts as a wrapper for the SystemBody, implementing the Handle pattern. It provides
 *          the interface through which users interact with the system, delegating all operations to the
 *          underlying SystemBody instance. This class ensures that the SystemBody is properly managed and
 *          adheres to the intended design pattern.
 * 
 * @see SystemBody
 * @see Handle
 */
class SystemHandle : public System, public Handle<SystemBody>{
    public: 
        SystemHandle(string name = "", double value = 0.0){
            pImpl_->setName(name);
            pImpl_->setValue(value);
        };
        virtual ~SystemHandle(){};

        const string getName(void) const{ return pImpl_->getName(); };
        double getValue(void) const { return pImpl_->getValue(); };

        void setName(const string& name){ pImpl_->setName(name); };
        void setValue(double value) { pImpl_->setValue(value); };
};

#endif