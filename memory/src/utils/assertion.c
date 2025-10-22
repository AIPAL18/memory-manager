#include "assertion.h"

#include <stdlib.h>
#include "color.h"
#include "message_handler.h"
#include <stdarg.h>

void assertion_error(
    const char* expression,
    const char* file,
    unsigned int line,
    const char* format,
    ...
    )
{
    // (void)expression;
    // (void)file;
    // (void)line;

    va_list args;

    va_start(args, format);
    forward_error("Assertion Error", file, line, expression, format, args);
    va_end(args);
}
