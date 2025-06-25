import os

from setuptools import Extension, find_packages, setup
from setuptools.command.build_ext import build_ext


class CMakeBuild(build_ext):
    def run(self):
        os.system("cmake . && make")
        super().run()

cmake_args = [f'-Dpybind11_DIR={pybind11.get_cmake_dir()}']

setup(
    # packages is typically read from pyproject.toml [tool.setuptools]
    package_dir={"audiosnoopy": "src"}, # The 'audiosnoopy' package is in the 'src' directory
    cmake_install_dir="audiosnoopy",    # Files from CMAKE_INSTALL_PREFIX/audiosnoopy (like _audiosnoopy.so)
                                      # will be placed into the 'audiosnoopy' package directory (which is 'src')
    cmake_args=cmake_args,
)
