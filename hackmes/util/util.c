#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int issp_debug = 0;

void dlog_init(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--debug") == 0) {
            issp_debug = 1;
            break;
        }
    }
}

static void p_dlog_data_small(char const *prompt, unsigned char const *data, size_t size) {
    printf("%s: ", prompt);
    unsigned long long buf = 0;
    for (size_t i = 0; i < size; ++i) {
        buf |= (unsigned long long)data[i] << (i * 8);
    }
    printf("0x%llx\n", buf);
}

void p_dlog_data(char const *prompt, unsigned char const *data, size_t size) {
    printf("[DEBUG] ");

    if (size <= sizeof(unsigned long long)) {
        p_dlog_data_small(prompt, data, size);
        return;
    }

    size_t indent = strlen(prompt) + 2;
    for (size_t i = 0; i < indent; ++i) {
        putchar(' ');
    }
    for (size_t i = 0; i < size; ++i) {
        printf("%2zu ", i);
    }
    printf("\n[DEBUG] %s: ", prompt);
    for (size_t i = 0; i < size; ++i) {
        printf("%02x ", data[i]);
    }
    printf("(%zu bytes)\n", size);
}

void user_input(char const *prompt, char *buf, size_t size) {
    fflush(stdin);
    if (prompt) printf("%s: ", prompt);

    size = size > 1024 ? 1024 : size;
    size_t temp_size = size * 3;
    char *temp = calloc(temp_size, sizeof(char));

    if (!fgets(temp, (int)temp_size, stdin)) {
        free(temp);
        return;
    }

    size_t j = 0;
    for (char *c = temp; *c && j < size; ++c, ++j) {
        if (*c == '\n') {
            buf[j] = '\0';
        } else if (*c == '\\') {
            int read;
            sscanf(c + 1, "%2hhx%n", &buf[j], &read);
            c += read;
        } else {
            buf[j] = *c;
        }
    }
    if (j < size) buf[j] = '\0';

    free(temp);
}
