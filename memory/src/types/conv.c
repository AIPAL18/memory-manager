#include "conv.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// You MUST free() the pointer !!!!!
Byte* byte_from_char(const char *str, size_t *out_len) {
    /*
    const char *text = "Coucou";
    size_t length;
    Byte *bytes = byte_from_char(text, &length);

    if (bytes) {
        printf("Bytes: ");
        for (size_t i = 0; i < length; ++i) {
            printf("%02x ", bytes[i]);
        }
        printf("\n");
        free(bytes);
    } else {
        printf("Conversion failed.\n");
    }
    */
    if (str == NULL || out_len == NULL) return NULL;

    size_t len = strlen(str);
    Byte *bytes = malloc(len * sizeof(Byte));
    if (!bytes) return NULL; // allocation failed

    for (size_t i = 0; i < len; ++i) {
        bytes[i] = (Byte)str[i];
    }

    *out_len = len;
    return bytes;
}

void char_to_byte(Byte *out_buf, const char *str, size_t str_size) {
    /*
    char* message = "Coucou";
    Byte buf[10] = {0};
    char_to_byte(buf, message, sizeof(message));
    
    printf("Bytes: ");
    for (size_t i = 0; i < sizeof(message); ++i) {
        printf("%02X ", buf[i]);
    }
    printf("\n");
    */
    if (!str || !out_buf) return;

    printf("%llu\n", sizeof(out_buf));

    for (size_t i = 0; i < str_size && str[i] != '\0'; ++i) {
        out_buf[i] = (Byte)str[i];
    }
}

void byte_to_char(char *out_buf, const Byte *bytes, size_t bytes_size) {
    if (!bytes || !out_buf) return;

    for (size_t i = 0; i < bytes_size; ++i) {
        out_buf[i] = (char)bytes[i];
    }
}
