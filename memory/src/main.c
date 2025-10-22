#include <stdio.h>
#include <Windows.h>
#include <string.h>

#include "display.h"
#include "types/types.h"
#include "types/conv.h"
#include "memory.h"
#include "utils/color.h"

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    
    Memory memory = {0};
    
    char* message = "Coucou";
    Byte file[20] = {0};
    char_to_byte(file, message, sizeof(message));
    
    print_bytes(&file, sizeof(file));

    printf(GREEN("Writing file into memory...\n"));

    if (write(&file, sizeof(file), 0x00, &memory))
        return 1;
    print_memory(&memory);

    printf(GREEN("Reading memory into buffer...\n"));

    Byte buf[20] = {0};
        
    if (read(&buf, sizeof(buf), 0x00, &memory))
        return 1;

    print_bytes(&buf, sizeof(buf));

    char out[20] = {0};
    byte_to_char(out, buf, sizeof(buf));

    printf("message: %s\n", out);

    return 0;
}