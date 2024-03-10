import os

from setuptools import Extension, setup
from setuptools.command.build_ext import build_ext


class CMakeBuild(build_ext):

    def run(self):
        os.system("cmake . && make")
        super().run()


setup(
    name="audiosnoopy",
    version="0.1.0",
    packages=["audiosnoopy"],
    ext_modules=[Extension("audiosnoopy", [])],
    cmdclass={"build_ext": CMakeBuild},
    install_requires=["fire"],
)
