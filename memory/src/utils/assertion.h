#ifndef ASSERTION_DECLARATION
#define ASSERTION_DECLARATION

#include <stdlib.h>
#include <stdio.h>

void assertion_error(
    const char* expression,
    const char* file,
    unsigned int line,
    const char* format,
    ...
    );

#ifdef NDEBUG

    #define m_assert(expression, format, ...) ((void)0)

#else

    #define m_assert(expression, format, ...) \
    do { \
        if (!(expression)) { \
            assertion_error(#expression, __FILE__, (unsigned)(__LINE__), format, ##__VA_ARGS__); \
        } \
    } while (0)
    

#endif // NDEBUG

#endif // ASSERTION_DECLARATION
