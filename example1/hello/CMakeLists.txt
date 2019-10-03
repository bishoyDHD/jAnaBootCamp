# Add lib called hello from source hello.cc
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
find_package(ROOT REQUIRED COMPONENTS)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
                    ${ROOT_INCLUDE_DIR})

file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cxx)
file(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

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

ROOT_GENERATE_DICTIONARY(dictDir ${CMAKE_CURRENT_SOURCE_DIR}/include/hello.h LINKDEF ${CMAKE_CURRENT_SOURCE_DIR}/include/LinkDef.hh)

#---Create a shared library with geneated dictionary
add_library(dictDirect SHARED "${sources}" dictDir.cxx ${ROOT_LIBRARIES})

target_link_libraries(dictDirect "-L${ROOT_LIBRARY_DIR}" ${ROOT_LIBRARIES})

#add_library(Hello hello.cc)
