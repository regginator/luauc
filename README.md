# luauc

Simple Native Luau Bytecode File Runner

# Installation

<sup><i>This primarily assumes you're using G++ (GCC) on GNU/Linux, however, you can compile this however else you'd like yourself. (i'm too lazy to make a CMakeLists.txt for this.. contribute if you'd like lol)</i></sup>

* Clone the Repository (Recursively)

```sh
git clone https://github.com/regginator/luauc.git --recursive
cd luauc
```

(If on GNU/Linux, with `cmake` and `g++`)

```sh
./build.sh
```

Or, manually..

```sh
cd luau

mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --target Luau.VM --config Release

cd ../..
g++ -std=c++17 -O2 -Wall -Wextra -o luauc luauc.cpp -Lluau/build -lLuau.VM
strip -s luauc
```

## Usage

```txt
$ luauc
Usage: luauc <INPUT_FILE>
```
