cmake_minimum_required(VERSION 3.14)
project(_audiosnoopy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)
#if(DEBUG)
#    add_compile_options("-g")
#else()
#    add_compile_options("-O3")
#endif()

find_package(Python COMPONENTS Interpreter Development.Module REQUIRED)
include_directories(${Python_INCLUDE_DIRS})

add_subdirectory(JUCE)
add_subdirectory(pybind11)

pybind11_add_module(_audiosnoopy src/_audiosnoopy.cpp src/AudioSnoopy.cpp)

target_link_libraries(_audiosnoopy PRIVATE juce::juce_audio_processors)

set_target_properties(_audiosnoopy PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/audiosnoopy")
