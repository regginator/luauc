#!/bin/sh

cd luau

mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --target Luau.VM --config Release

cd ../..
g++ -std=c++17 -O3 -Wall -Wextra -o luauc luauc.cpp -Lluau/build -lLuau.VM
strip -s luauc
