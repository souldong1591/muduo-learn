add_executable(test_base
    ${Common_Src}
    #muduo/base/test/noncopyable_test.cc
    #muduo/base/test/singleton_test.cc
    muduo/base/test/logging_test.cc
)
target_link_libraries(test_base
    ${Libs}
)