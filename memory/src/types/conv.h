#ifndef CONV_DECLARATION
#define CONV_DECLARATION

#include "types.h"

// You MUST free() the pointer !!!!!
Byte* byte_from_char(const char *str, size_t *out_len);

void char_to_byte(Byte *out_buf, const char *str, size_t str_size);

void byte_to_char(char *out_buf, const Byte *bytes, size_t bytes_size);

#endif // FILE_DECLARATION