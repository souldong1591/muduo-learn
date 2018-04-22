#include "muduo/base/Singleton.h"
#include <iostream>
#include <string>
#include <thread>

using muduo::base::Singleton;
using muduo::base::noncopyable;
class Singleton_test : noncopyable {
 public:
	Singleton_test(): name_("") {

	}
	~Singleton_test() {}
	
	void setName(const std::string& name) {
		name_ = name;
	}
	const std::string& getName() {
		return name_;
	}

 private:
 	std::string name_;
};


void threadFunc() {
	Singleton<Singleton_test>::instance().setName("changed, only once");
}

int main(int argc, char const *argv[]) {
	Singleton<Singleton_test>::instance().setName("only once");
	std::cout << "Singleton_test name: " 
			  << Singleton<Singleton_test>::instance().getName()
			  << std::endl;
	std::thread t1(&threadFunc);
	t1.join();
	std::cout << "Singleton_test name: " 
			  << Singleton<Singleton_test>::instance().getName()
			  << std::endl;


	return 0;
}