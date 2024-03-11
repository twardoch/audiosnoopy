import os

from setuptools import Extension, find_packages, setup
from setuptools.command.build_ext import build_ext


class CMakeBuild(build_ext):

    def run(self):
        os.system("cmake . && make")
        super().run()


setup(
    name="audiosnoopy",
    version="0.1.0",
    package_dir={"": "src"},
    packages=find_packages(where="src"),
    ext_modules=[Extension("audiosnoopy._audiosnoopy", [])],
    cmdclass={"build_ext": CMakeBuild},
    install_requires=["fire"],
)