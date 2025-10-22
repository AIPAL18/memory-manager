#ifndef MEMORY_DECLARATION
#define MEMORY_DECLARATION

#include "types/types.h"

// #define MEMORY_LENGTH 0x1000 // 4Kio (4096 o)
#define MEMORY_LENGTH 0x100
typedef Byte Memory[MEMORY_LENGTH];

int write(
    const Byte (*buffer)[], 
    const size_t element_size, 
    const Address address, 
    Memory *mem
    );

int read(
    Byte (*buffer)[], 
    const size_t element_size, 
    const Address address, 
    const Memory *mem
    );

#endif // MEMORY_DECLARATION