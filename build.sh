#!/bin/sh

mkdir -p luau/build
cmake -S luau -B luau/build -DCMAKE_BUILD_TYPE=Release
cmake --build luau/build --config Release --target Luau.VM

c++ -std=c++17 -O2 -Wall -Wextra -o luauc luauc.cpp -Lluau/build -lLuau.VM
strip -s luauc
