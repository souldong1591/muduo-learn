#include "muduo/base/Logging.h"

using namespace muduo::base;


int main(int argc, char const *argv[]) { 
    LOG_TRACE << "trace";
    LOG_DEBUG << "debug";
    LOG_INFO << "Hello";
    LOG_WARN << "World";
    LOG_ERROR << "Error";
    LOG_INFO << sizeof(muduo::base::Logger);
    LOG_INFO << sizeof(muduo::LogStream);
    LOG_INFO << sizeof(muduo::Fmt);
    LOG_INFO << sizeof(muduo::LogStream::Buffer);

}
