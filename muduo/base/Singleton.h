#ifndef MUDUO_BASE_SINGLETON_H
#define MUDUO_BASE_SINGLETON_H

#include "muduo/base/noncopyable.h"
#include <assert.h>
#include <pthread.h>
#include <stdlib.h>

namespace muduo {
namespace base {

template<typename T>
struct has_no_destory {
	template<typename C>
	static char test(decltype(&C::no_destory));

	template<typename C>
	static int32_t test(...);

	const static bool value = sizeof(test<T>(0)) == 1;
	
};


template<typename T>
class Singleton : noncopyable {
 public:
 	static T& instance() {
 		pthread_once(&ponce_, &Singleton::init);
 		assert(value_ != nullptr);
 		return *value_;
 	}

 private:
	Singleton();
	~Singleton();

	static void init() {
		value_ = new T();
		if (!has_no_destory<T>::value) {
			::atexit(destory);
		}
	}

	static void destory() {
		typedef char T_must_be_complete_type[sizeof(T) == 0 ? -1 : 1];
		T_must_be_complete_type dummy;
		(void) dummy;
		delete value_;
		value_ == nullptr;
	}

 private:
 	static pthread_once_t ponce_;
 	static T* value_;
	
};

template<typename T>
pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;

template<typename T>
T* Singleton<T>::value_ = nullptr;


} // base

} // muduo






#endif // MUDUO_BASE_SINGLETON_H
