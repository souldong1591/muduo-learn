#ifndef MUDUO_BASE_NONCOPYABLE_H
#define MUDUO_BASE_NONCOPYABLE_H

namespace muduo {
namespace base {

class noncopyable {
 protected:
    noncopyable() = default;
    ~noncopyable() = default;
 private:
    noncopyable(const noncopyable&) = delete;
    const noncopyable& operator=(const noncopyable&) = delete;
    
};

} // base

} // muduo

#endif // MUDUO_BASE_NONCOPYABLE_H
