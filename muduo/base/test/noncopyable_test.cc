#include "muduo/base/noncopyable.h"
#include <iostream>

using muduo::base::noncopyable;


class Noncopyable_test : noncopyable {
public:
    Noncopyable_test() {
        std::cout << "construt Noncopyable_test success" << std::endl;
    }
    ~Noncopyable_test() {}
    Noncopyable_test(int32_t i) {
        std::cout << "construt Noncopyable_test: " 
                  << i << " success" << std::endl;
    }
    
};

int main(int argc, char const *argv[]) {
    Noncopyable_test n1;
    Noncopyable_test n2(1);


   // Noncopyable_test n3(n1); // compile error
   // Noncopyable_test n4 = n2; // compile error
    
    return 0;
}