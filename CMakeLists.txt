cmake_minimum_required(VERSION 3.0.0)

project(muduo_learn)
MESSAGE(STATUS "CURRENT DIR IS ${muduo_learn_SOURCE_DIR}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(Include_Dir
    ${CMAKE_HOME_DIRECTORY}
)
include_directories(${Include_Dir})

set(Link_Dir
)
link_directories(${Link_Dir})

set(Base_Src
	muduo/base/FileUtil.cc
  	muduo/base/LogFile.cc
  	muduo/base/Logging.cc
  	muduo/base/LogStream.cc
  	muduo/base/ProcessInfo.cc
  	muduo/base/Timestamp.cc


)

set(Net_Src
)

set(Libs
    pthread
)

set(Common_Src
    ${Base_Src}
    ${Net_Src}
)
include(CMakeLists.demo.cmake)
include(CMakeLists.test.base.cmake)