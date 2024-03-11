cmake_minimum_required(VERSION 3.14)
project(audiosnoopy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)
#if(DEBUG)
#    add_compile_options("-g")
#else()
#    add_compile_options("-O3")
#endif()

find_package(Python COMPONENTS Interpreter Development.Module REQUIRED)
include_directories(${Python_INCLUDE_DIRS})

add_subdirectory(src/pybind11)
pybind11_add_module(audiosnoopy._audiosnoopy src/_audiosnoopy.cpp src/AudioSnoopy.cpp)

add_subdirectory(JUCE)
target_link_libraries(audiosnoopy._audiosnoopy PRIVATE juce::juce_audio_processors)

set_target_properties(audiosnoopy._audiosnoopy PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/audiosnoopy")