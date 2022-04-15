#!/usr/bin/env bash
set -eou pipefail
if [[ $# -eq 0 || $1 == -h || $1 == --help ]]; then
cat << _EOT_
Usage: bash compile-pybind11-macos [file.cpp]
_EOT_
exit 1
fi
c++ -O3 -Wall -shared -std=c++11 -undefined dynamic_lookup $(python3-config --includes) -Iextern/pybind11/include $1 -o example$(python3-config --extension-suffix)
