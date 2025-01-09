#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int issp_debug;

#define dlog(fmt, ...)                                                                             \
    do {                                                                                           \
        if (issp_debug) printf("[DEBUG] " fmt, __VA_ARGS__);                                       \
    } while (0)

#define dlog_fun(fun)                                                                              \
    do {                                                                                           \
        if (issp_debug) printf("[DEBUG] " #fun ": %p\n", fun);                                     \
    } while (0)

#define dlog_var(var)                                                                              \
    do {                                                                                           \
        if (issp_debug) p_dlog_data(#var, (unsigned char const *)&(var), sizeof(var));             \
    } while (0)

void dlog_init(int argc, char *argv[]);
void user_input(char const *prompt, char *buf, size_t size);

// Private

void p_dlog_data(char const *prompt, unsigned char const *data, size_t size);

#endif // UTIL_H
