#ifndef MODEL_IMPL_HPP
#define MODEL_IMPL_HPP

#include "Model.hpp"
#include "System.hpp"
#include "Bridge.hpp"
#include "Flow.hpp"

using std::vector;
using std::string;

using namespace std;

/**
 * @class ModelBody
 * @brief Implementation class for managing the internal state of the model.
 * @details ModelBody encapsulates the core functionality and data of the model. It manages systems and flows,
 *          tracks the simulation time, and performs the simulation execution. This class is intended to be 
 *          used internally by the ModelHandle and is not exposed directly to the user.
 * 
 * @see ModelHandle
 * @see System
 * @see Flow
 * @see Body
 * @warning Ensure that the ModelBody is properly managed by its associated Handle to avoid inconsistencies
 *          and ensure proper lifecycle management.
 */
class ModelBody : public Body {
    friend class UnitModel;

    private:
        string name;                 /**< Name of the model.*/
        vector<System*> systems;     /**< Vector storing pointers to the systems within the model.*/
        vector<Flow*> flows;         /**< Vector storing pointers to the flows within the model.*/
        int currentTime;             /**< Current time in the simulation.*/

    public:
        
        virtual ~ModelBody(){};
        void add(System* system);
        void add(Flow* flow);

        void setName(const string& modelName);
        string getName() const;

        int getCurrentTime() const;
        void setCurrentTime(int time);

        void execute(int startTime, int endTime, int timeStep);

        System* createSystem(const string& name, double value);;   
        bool deleteSystem(System* system);
        bool deleteFlow(Flow* flow);  
};

/**
 * @class ModelHandle
 * @brief Handle class for managing access to the ModelBody instance.
 * @details ModelHandle acts as a wrapper for the ModelBody, implementing the Handle pattern. It provides
 *          the interface through which users interact with the model, delegating all operations to the
 *          underlying ModelBody instance. This class ensures that the ModelBody is properly managed and
 *          adheres to the singleton pattern.
 * 
 * @see ModelBody
 * @see Handle
 */
class ModelHandle : public Model, public Handle<ModelBody> {

    public:

        static Model* _instance; /**< Static pointer to the singleton instance of ModelHandle. */
        
        /**
         * @brief Constructor for ModelHandle.
         * @param name Optional name to initialize the model.
         * 
         * @note This constructor creates a ModelHandle instance and sets the name of the underlying ModelBody.
         */
        ModelHandle(const string& name = "") : Handle<ModelBody>() {
            pImpl_->setName(name);
        }

        /**
         * @brief Destructor for the ModelHandle class.
         * @details Ensures that resources allocated by the ModelHandle instance are properly cleaned up.
         * 
         * @note The destructor must ensure that any dynamic memory or resources are released to avoid memory leaks.
         */
        virtual ~ModelHandle() {
            if (_instance == this) {
                _instance = nullptr;
            }
        }
        
        void add(System* system) { pImpl_->add(system); }

        void add(Flow* flow) { pImpl_->add(flow); }

        System* createSystem(const string& name, double value) {
            return pImpl_->createSystem(name, value);
        }

        bool deleteSystem(System* system) { return pImpl_->deleteSystem(system); }

        bool deleteFlow(Flow* flow) { return pImpl_->deleteFlow(flow); }

        void setName(const string& name) { pImpl_->setName(name); }

        string getName() const { return pImpl_->getName(); }

        int getCurrentTime() const { return pImpl_->getCurrentTime(); }

        void setCurrentTime(int time) { pImpl_->setCurrentTime(time); }

        void execute(int startTime, int endTime, int timeStep) {
            pImpl_->execute(startTime, endTime, timeStep);
        }
};

#endif