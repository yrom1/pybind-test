// cppimport
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>


#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

#include "math.h"
#include <iostream>

using namespace std; // NOLINT
namespace py = pybind11;

int add(int i, int j) { return i + j; }

py::array_t<double> add_arrays(py::array_t<double> input1,
                               py::array_t<double> input2) {
  auto buf1 = input1.request(), buf2 = input2.request();

  if (buf1.ndim != 1 || buf2.ndim != 1)
    throw std::runtime_error("Number of dimensions must be one");

  if (buf1.size != buf2.size)
    throw std::runtime_error("Input shapes must match");

  /* No pointer is passed, so NumPy will allocate the buffer */
  py::array_t<double> result = py::array_t<double>(buf1.size);
  py::buffer_info buf3 = result.request();

  double *ptr1 = reinterpret_cast<double *>(buf1.ptr),
         *ptr2 = reinterpret_cast<double *>(buf2.ptr),
         *ptr3 = reinterpret_cast<double *>(buf3.ptr);

  for (size_t idx = 0; idx < buf1.shape[0]; idx++)
    ptr3[idx] = ptr1[idx] + ptr2[idx];

  return result;
}

double sum(py::array_t<double> arr) {
  auto buffer = arr.request();
  std::cout << "Array has size: " << buffer.size << '\n';
  double *ptr = reinterpret_cast<double *>(buffer.ptr);
  double ans = 0.0;
  for (size_t idx = 0; idx < buffer.shape[0]; idx++) {
    ans += ptr[idx];
  }
  return ans;
}

double __ptr_sum(vector<double> &arr, int unsigned start, int unsigned end) {
  double ans = 0;
  for (size_t i = start; i <= end; i++)
    ans += arr[i];
  return ans;
}

int main(int argc, char *argv[]) {
  int unsigned ThreadsSize = 8;
  vector<std::future<double>> futures;
  vector<double> arr(10000000, 1);
  int unsigned kin, kend;
  int unsigned dk = floor(arr.size() / ThreadsSize);

  cout << "VectorSize = " << arr.size() << ", ThreadsSize = " << ThreadsSize
       << ", dk = " << dk << endl;

  auto t_start = std::chrono::high_resolution_clock::now();
  double Sum = 0;
  for (int unsigned k = 0; k <= ThreadsSize - 1; k = k + 1) {
    kin = k * dk;
    kend = (k + 1) * dk - 1;
    if (k == ThreadsSize - 1) {
      kend = arr.size() - 1;
    }
    cout << k << " in: " << kin << ", end: " << kend << endl;

    futures.push_back(std::async(std::launch::async, [&arr, kin, kend]() {
      return __ptr_sum(arr, kin, kend);
    }));
  }

  // Threads joining
  for (int unsigned k = 0; k <= ThreadsSize - 1; k = k + 1)
    Sum += futures[k].get();

  // Elapsed time calculation
  auto t_end = std::chrono::high_resolution_clock::now();
  double elapsed_time_ms =
      std::chrono::duration<double, std::milli>(t_end - t_start).count();

  // Output 2
  cout << "Sum = " << Sum << endl;
  cout << "Time = " << elapsed_time_ms << endl;

  return 0;
}

PYBIND11_MODULE(example, m) {
  m.doc() = "pybind11 example plugin";  // optional module docstring
  m.def("__add", &add, "A function which adds two numbers");
  m.def("__add_vec", &add_arrays, "Add two NumPy arrays");
  m.def("__sum", &sum, "Return the sum of a NumPy array");
}
/*
<%
setup_pybind11(cfg)
%>
*/
