/*!
 \file Bridge.hpp
 \brief The classes Handle and Body implements "bridge" design pattern (also known as
	"handle/body idiom").The class Body was implemented based on the class teCounted
	writed by Ricardo Cartaxo and Gilberto Camara and founded in the geographic library TerraLib.
 \author Prof. Tiago Garcia de Senna Carneiro - UFOP, MG, Brazil
*/

#if !defined(HANDLE_BODY)
#define HANDLE_BODY

#ifndef DEBUGING
#define DEBUGING

inline int numHandleCreated = 0;
inline int numHandleDeleted = 0;
inline int numBodyCreated = 0;
inline int numBodyDeleted = 0;

#endif

/**
 * \brief
 *
 * The classes Handle and Body implements the "bridge" design pattern (also known as
 * "handle/body idiom").
 *
 */
template <class T>
class Handle{

	public:
		/// constructor
		Handle<T>(){
			pImpl_ = new T;
			pImpl_->attach();
			
			#ifdef DEBUGING
			numHandleCreated++;
			#endif
		}

		/// Destructor
		virtual ~Handle<T>() { 
			pImpl_->detach(); 
		
			#ifdef DEBUGING
			numHandleDeleted++;
			#endif	
		}

		/// copy constructor
		Handle<T>(const Handle &hd) : pImpl_(hd.pImpl_) { 
			pImpl_->attach(); 			
			
			#ifdef DEBUGING
			numHandleCreated++;
			#endif	
		}

		/// assignment operator
		Handle<T> &operator=(const Handle &hd){
			if (this != &hd){
				hd.pImpl_->attach();
				pImpl_->detach();
				pImpl_ = hd.pImpl_;
			}
			return *this;
		}

	protected:
		/// referencia para a implementacão
		T *pImpl_;
};

/**
 * \brief
 *
 * The class Implementation was implemented based on the class teCounted writed by Ricardo Cartaxo
 * and Gilberto Câmara and founded in the geographic library TerraLib.
 */

class Body{

	public:
		/// Constructor: zero references when the object is being built
		Body() : refCount_(0) {}

		/// Increases the number of references to this object
		void attach() { 
			refCount_++; 

			#ifdef DEBUGING
			numBodyCreated++;
			#endif	
		}

		/// Decreases the number of references to this object.
		/// Destroy it if there are no more references to it
		void detach(){
			if (--refCount_ == 0){
				delete this;
				
				#ifdef DEBUGING
				numBodyDeleted++;
				#endif	
			}
		}

		/// Returns the number of references to this object
		int refCount() { return refCount_; }

		/// Destructor
		virtual ~Body() {}

	private:
		/// No copy allowed
		Body(const Body &);

		/// Implementation
		Body &operator=(const Body &) { return *this; }

		int refCount_; /// the number of references to this class
};

#endif
