#!/bin/sh

cd luau

mkdir -p cmake
cd cmake
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --target Luau.VM --config Release

cd ../..
g++ -std=c++17 -O2 -Wall -Wextra -o luauc luauc.cpp -Lluau/cmake -lLuau.VM
