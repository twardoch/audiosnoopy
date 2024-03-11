// audiosnoopy/AudioSnoopyPy.cpp

#include <pybind11/pybind11.h>
#include "AudioSnoopy.h"

namespace py = pybind11;

PYBIND11_MODULE(libaudiosnoopy, m)
{
    py::class_<AudioSnoopy>(m, "AudioSnoopy")
        .def(py::init<const std::string &>())
        .def("get_plugin_info", &AudioSnoopy::getPluginInfo);
}