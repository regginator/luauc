// the laziest luau C api usage ever <3

#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>

// luau
#include "luau/VM/include/lua.h"
#include "luau/VM/include/lualib.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        if (argc == 1) {
            fprintf(stderr, "Usage: %s <INPUT_FILE>\n", argv[0]);
        }

        return 1;
    }

    char *filePath = argv[1];

    // read bytecode
    FILE *file = fopen(filePath, "rb");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file `%s`\n", filePath);
        return 1;
    }

    // get size
    fseek(file, 0, SEEK_END);
    long bytecodeSize = ftell(file);
    rewind(file);

    // init buffer
    char *bytecode = (char *) malloc(bytecodeSize);
    if (bytecode == NULL) {
        fprintf(stderr, "Failed to allocate buffer for bytecode data\n");
        fclose(file);
        return 1;
    }

    // read data into buffer
    long int readResult = fread(bytecode, 1, bytecodeSize, file);
    if (readResult != bytecodeSize) {
        fprintf(stderr, "Failed to read file %s\n", filePath);
        fclose(file);
        free(bytecode);
        return 1;
    }

    fclose(file);

    // state
    lua_State *L = luaL_newstate();
    if (L == NULL) {
        fprintf(stderr, "Failed to initialize lua_State\n");
        free(bytecode);
        return 1;
    }

    lua_setsafeenv(L, LUA_ENVIRONINDEX, 1);
    luaopen_base(L); // I hate this

    int loadResult = luau_load(L, basename(filePath), bytecode, bytecodeSize, 0);
    free(bytecode);

    if (loadResult != 0) {
        fprintf(stderr, "Error loading bytecode\n");
        return 1;
    }

    lua_call(L, 0, LUA_MULTRET);

    return 0;
}
