cmake_minimum_required(VERSION 3.5)
#Top level CmakeLists.txt

project(Example1)

add_subdirectory(hello)

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT REQUIRED COMPONENTS)

file(GLOB headers ${CMAKE_SOURCE_DIR}/hello/include/hello.h)
#make sure compiler can find include files from our hello lib
#include_directories(${hello_SOURCE_DIR}/hello)

##### FOR THE ROOT COMPILER #########################
EXECUTE_PROCESS(COMMAND root-config --cflags OUTPUT_VARIABLE ROOT_CXX_FLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
### Need to set CMAKE_FLAGS for root otherwise program will not compile
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ROOT_CXX_FLAGS}")


##### FOR THE ROOT LINKER #########################
EXECUTE_PROCESS(COMMAND root-config --glibs OUTPUT_VARIABLE ROOT_LD_FLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)

set(CMAKE_EXE_LINKER_FLAGS ${ROOT_LD_FLAGS})
set(ROOT_LIBRARIES ${ROOT_LIBRARIES})
#####################################################

set(include_dir ${CMAKE_SOURCE_DIR}/hello/include)

include_directories(${include_dir} ${ROOT_INCLUDE_DIR})

#add binary called "bootCamp1" built from example1.cc
add_executable(bootCamp1 example1.cxx ${headers} ${ROOT_LIBRARIES})

#link executable to the hello lib
target_link_libraries(bootCamp1 dictDirect "-L${ROOT_LIBRARY_DIR}" ${ROOT_LIBRARIES})
