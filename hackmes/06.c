// 1. Explain what's wrong with this code, what kind(s) of vulnerability it has,
//    and how it can be fixed.
// 2. Exploit the vulnerability by crafting a malicious input that allows you
//    to leak the PIN.

#include <stdio.h>
#include <stdlib.h>

#include "util.h"

unsigned long string_to_pin(char const *str) {
    return strtoul(str, NULL, 10);
}

int main(int argc, char *argv[]) {
    dlog_init(argc, argv);
    dlog_fun(main);

    struct {
        unsigned long pin;
        char buf[32];
    } data = { .pin = 61930412 };

    user_input("8-digit PIN", data.buf, sizeof(data.buf) - 1);

    if (data.pin == string_to_pin(data.buf)) {
        puts("Welcome, admin!");
    } else {
        printf(data.buf);
        puts(" is not the correct PIN!");
    }

    return 0;
}
