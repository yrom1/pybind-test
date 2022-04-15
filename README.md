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

---

```py
Ryans-MacBook-Air:pybind-test ryan$ ls
README.md			compile-pybind11-macos.sh	example.cpp			example.cpython-310-darwin.so	extern				run-test.sh
Ryans-MacBook-Air:pybind-test ryan$ py
Python 3.10.2 (main, Feb  2 2022, 05:51:25) [Clang 13.0.0 (clang-1300.0.29.3)] on darwin
Type "help", "copyright", "credits" or "license" for more information.
>>> import example
>>> example.add(1,2)
3
>>>
```
