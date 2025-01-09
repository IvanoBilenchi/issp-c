// 1. Explain what's wrong with this code, what kind(s) of vulnerability it has,
//    and how it can be fixed.
// 2. Exploit the vulnerability by crafting a malicious input that allows you
//    to call the shellcode function.

#include <stdio.h>
#include <string.h>

#include "util.h"

void shellcode(void) {
    puts("You got shell!");
}

void auth_failure(void) {
    puts("Who are you?");
}

int main(int argc, char *argv[]) {
    dlog_init(argc, argv);
    dlog_fun(main);
    dlog_fun(auth_failure);
    dlog_fun(shellcode);

    struct {
        char buf[16];
        int authenticated;
        void (*error)(void);
    } data;

    data.authenticated = 0;
    data.error = auth_failure;

    dlog_var(data);

    user_input("Password", data.buf, sizeof(data));

    if (strcmp(data.buf, "p4ssw0rd") == 0) {
        data.authenticated = 1;
    }

    dlog_var(data);

    if (data.authenticated) {
        puts("Welcome, admin!");
    } else {
        data.error();
    }

    return 0;
}
