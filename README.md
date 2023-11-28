# luauc

Simple Native Luau Bytecode File Runner

## Build

*(If on GNU/Linux, with `cmake` and `g++`)*

* Clone the Repository (Recursively)

```sh
git clone --recursive https://github.com/regginator/luauc.git
cd luauc
```

```sh
./build.sh
```

Or, manually..

```sh
mkdir -p luau/build
cmake -S luau -B luau/build -DCMAKE_BUILD_TYPE=Release
cmake --build luau/build --config Release --target Luau.VM

g++ -std=c++17 -O2 -Wall -Wextra -o luauc luauc.cpp -Lluau/build -lLuau.VM
strip -s luauc
```

## Usage

```
$ luauc
Usage: luauc <INPUT_FILE>
```
