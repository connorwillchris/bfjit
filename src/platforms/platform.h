#ifndef PLATFORM_H
#define PLATFORM_H

// simplistic header cross compilation
#if defined(_WIN32) || defined(_WIN64)

    #include <Windows.h>

#elif defined(__linux__)

    #include <stdlib.h>
    #include <sys/mman.h>

#endif

// include BF.H and STDIO.H by default.
#include "bf.h"
#include <stdio.h>

/// @brief Execute a given string `s` using the JIT compilation method.
/// @param b BF state.
/// @param s String to execute.
/// @return Error code, if any.
int bf_dostring_jit(Bf *b, char *s);

#endif
