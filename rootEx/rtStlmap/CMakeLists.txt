cmake_minimum_required(VERSION 3.5)

project(testmap)

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT REQUIRED)

#make sure compiler can find include files from our hello lib
include_directories(${CMAKE_SOURCE_DIR}/src/include
	            ${ROOT_INCLUDE_DIR})

file(GLOB sources ${CMAKE_SOURCE_DIR}/src/*.cxx)
file(GLOB headers ${CMAKE_SOURCE_DIR}/src/include/*.h)
##### FOR THE ROOT COMPILER #########################
EXECUTE_PROCESS(COMMAND root-config --cflags OUTPUT_VARIABLE ROOT_CXX_FLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
### Need to set CMAKE_FLAGS for root otherwise program will not compile
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ROOT_CXX_FLAGS}")


##### FOR THE ROOT LINKER #########################
EXECUTE_PROCESS(COMMAND root-config --glibs OUTPUT_VARIABLE ROOT_LD_FLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)

set(CMAKE_EXE_LINKER_FLAGS ${ROOT_LD_FLAGS})
set(ROOT_LIBRARIES ${ROOT_LIBRARIES})
#####################################################

#---Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
include(${ROOT_USE_FILE})

ROOT_GENERATE_DICTIONARY(dictDir ${CMAKE_CURRENT_SOURCE_DIR}/src/include/*.h LINKDEF ${CMAKE_CURRENT_SOURCE_DIR}/src/include/LinkDef.hh)

#add binary called "hello_world" built from test.cc
add_executable(testmap testmap.cxx dictDir ${sources} ${headers} ${ROOT_LIBRARIES})

#link executable to the hello lib
target_link_libraries(testmap "-L${ROOT_LIBRARY_DIR}" ${ROOT_LIBRARIES})
