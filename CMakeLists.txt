cmake_minimum_required(VERSION 3.14)
project(audiosnoopy)

set(CMAKE_CXX_STANDARD 17)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_subdirectory(audiosnoopy/pybind11)
pybind11_add_module(audiosnoopy audiosnoopy/AudioSnoopyPy.cpp audiosnoopy/AudioSnoopy.cpp)

add_subdirectory(JUCE)
target_link_libraries(audiosnoopy PRIVATE juce::juce_audio_processors)