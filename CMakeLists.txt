cmake_minimum_required(VERSION 3.15)
project(audiosnoopy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Attempt to force a headless build for JUCE
add_compile_definitions(JUCE_HEADLESS_PLUGIN_CLIENT=1)
# Try to disable specific X11 features if the above is not enough
# add_compile_definitions(JUCE_USE_XINERAMA=0)
# add_compile_definitions(JUCE_USE_XRANDR=0)
# add_compile_definitions(JUCE_USE_XCURSOR=0)
# add_compile_definitions(JUCE_DISABLE_WEB_BROWSER_COMPONENT=1) # For juce_gui_extra related webkit

# Pybind11
find_package(pybind11 CONFIG REQUIRED)
# Python
find_package(Python COMPONENTS Interpreter Development REQUIRED)

# JUCE
set(JUCE_MODULE_juce_gui_extra OFF CACHE BOOL "Disable juce_gui_extra if JUCE build system respects this")
add_subdirectory(JUCE)

# Python module
# Add AudioSnoopy.cpp directly to the pybind11 module sources
pybind11_add_module(_audiosnoopy src/_audiosnoopy.cpp src/AudioSnoopy.cpp)

# Link dependencies
target_link_libraries(_audiosnoopy PRIVATE
    juce::juce_audio_processors # For JUCE functionality
    # pybind11::module # pybind11_add_module should handle this
)

# Include directories
target_include_directories(_audiosnoopy PRIVATE
    src # For AudioSnoopy.h and json.hpp
    # pybind11_INCLUDE_DIRS # pybind11_add_module should handle this
    # JUCE include directories are propagated by juce::juce_audio_processors
)

# No separate AudioSnoopy library needed if only used by the extension.

# Install rules
include(GNUInstallDirs)

# Install the Python extension module
install(TARGETS _audiosnoopy
    LIBRARY DESTINATION audiosnoopy  # Installs to <prefix>/audiosnoopy/_audiosnoopy.so
    RUNTIME DESTINATION audiosnoopy
)

# Install AudioSnoopy.h and json.hpp if they are public headers for the C++ part
# (not strictly needed if only used for the pybind module, but good practice if C++ lib could be used)
install(FILES src/AudioSnoopy.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/audiosnoopy)
install(DIRECTORY src/json/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/audiosnoopy/json)

# Testing (requires CTest)
enable_testing()
# Add tests here if you have C++ tests
# Example:
# add_executable(run_cpp_tests tests/cpp_tests.cpp)
# target_link_libraries(run_cpp_tests PRIVATE AudioSnoopy)
# add_test(NAME CppTests COMMAND run_cpp_tests)
