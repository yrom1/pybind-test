# pybind-test
toy pybind11 submodule install and compile for macos

# Setup

```
git submodule add -b stable ../../pybind/pybind11 extern/pybind11
git submodule update --init
```
```
mkdir build
cd build
cmake ..
make check -j 4
```
```
bash compile-pybind11-macos.sh
```
