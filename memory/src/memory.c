#include "memory.h"

#include "utils/assertion.h"
#include "utils/message_handler.h"
#include <stdio.h>

int write(
    const Byte (*buffer)[], 
    const size_t element_size, 
    const Address address, 
    Memory *mem
    )
{
    size_t memory_length = sizeof(*mem);
    
    m_assert(element_size <= memory_length, 
        "You are trying to write an element of a size greater then the memory itself:\nrequested: %llu bytes\navailable: %llu bytes\n", element_size, memory_length);
    m_assert((address + element_size) <= memory_length, 
        "You are trying to write outside of the memory:\ndata address: %u\ndata length: %llu bytes\nmemory length: %llu bytes\n", address, element_size, memory_length);
    
    if (element_size > memory_length) return 1;
    if ((address + element_size) > memory_length) return 1;
    
    for (unsigned int i = 0; i < element_size; ++i)
    {
        (*mem)[address + i] = (*buffer)[i];
    }
    
    return 0;
}

int read(
    Byte (*buffer)[], 
    const size_t element_size, 
    const Address address, 
    const Memory *mem
    )
{
    size_t memory_length = sizeof(*mem);

    m_assert(element_size <= memory_length, 
        "You are trying to read an element of a size greater then the memory itself:\nrequested: %llu bytes\navailable: %llu bytes\n", element_size, memory_length);
    m_assert((address + element_size) <= memory_length, 
        "You are trying to read outside of the memory:\ndata address: %u\ndata length: %llu bytes\nmemory length: %llu bytes\n", address, element_size, memory_length);
    
    if (element_size > memory_length) return 1;
    if ((address + element_size) > memory_length) return 1;


    for (unsigned int i = 0; i < element_size; ++i)
    {
        (*buffer)[i] = (*mem)[address + i];
    }
        
    return 0;
}
