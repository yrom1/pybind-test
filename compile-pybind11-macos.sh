c++ -O3 -Wall -shared -std=c++11 -undefined dynamic_lookup $(python3-config --includes) -Iextern/pybind11/include example.cpp -o example$(python3-config --extension-suffix)
