#include <stdio.h>
#include <string.h>
#include "display.h"

void centerText(char *text, const size_t fieldWidth)
{
    size_t width = fieldWidth;
    if (strlen(text) > fieldWidth) width = strlen(text);

    int r_padlen, l_padlen;
    r_padlen = l_padlen = (width - strlen(text)) / 2;
    if ((strlen(text) + width) % 2 == 1) l_padlen += 1;
    printf("%*s%s%*s", l_padlen, "", text, r_padlen, "");
}

size_t padding(const size_t len, const size_t width)
{
    return ((width) - ((len) % (width))) % (width);
}

void print_generic(const Byte (*mem)[], const size_t mem_len, const char* name, const size_t element_per_line)
{
    // ┌ ┐ └ ┘ │ ─ ┼ ┴ ┬ ┤ ├
    // 10 + 1 + (element_per_line * 3)
    size_t inside_width = (element_per_line * 3) + 12;
    
    // Header
    printf("┌────────────────────────────────────────────────────────────┐\n│");
    char buffer[55];
    if (!snprintf(buffer, 55, "%s: %-16p - %04u bytes", name, (void*)mem, (unsigned int)mem_len)) return;
    centerText(buffer, inside_width);
    printf("│\n├──────────┬─────────────────────────────────────────────────┤\n│          │");
    for (Address address = 0; address < element_per_line; ++address)
    {
        printf(" %02X", address);
    }
    printf(" │\n├──────────┼─────────────────────────────────────────────────┤");

    // Body
    for (Address address = 0; address < mem_len; ++address)
    {
        if (address % element_per_line == 0) printf("\n│0x%08X│", address);
        printf(" %02x", (*mem)[address]);
        if (address % element_per_line == (element_per_line - 1) && (address + 1) < mem_len) printf(" │");
    }

    for (size_t i = 0; i < padding(mem_len, element_per_line); ++i)
    {
        printf(" ──");
    }

    // footer
    printf(" │\n└──────────┴─────────────────────────────────────────────────┘\n\n");
}

void print_memory(const Memory *mem)
{
    print_generic(mem, sizeof(*mem), "Memory", 0x10);
}

void print_bytes(const Byte (*buffer)[], const size_t buffer_length)
{
    print_generic(buffer, buffer_length, "Buffer", 0x10);
}
