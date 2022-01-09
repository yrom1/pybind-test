# pybind-test
toy c++ pybind with cppimport


# Setup

```
sudo apt-get install python3-dev
sudo apt-get install libpython3.10-dev
```

# Example

It works!

```py
$ py
Python 3.10.0 (default, Oct 11 2021, 05:33:59) [GCC 11.2.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import cppimport.import_hook
>>> import somecode
>>> somecode.square(9)
81
>>>
```
