#ifndef DISPLAY_DECLARATION
#define DISPLAY_DECLARATION

#include "types/types.h"
#include "memory.h"

void print_generic(const Byte (*mem)[], const size_t mem_len, const char* name, const size_t element_per_line);

void print_memory(const Memory *mem);

void print_bytes(const Byte (*buffer)[], const size_t buffer_length);

#endif // DISPLAY_DECLARATION
