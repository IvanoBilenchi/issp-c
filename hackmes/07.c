// 1. Explain what's wrong with this code, what kind(s) of vulnerability it has,
//    and how it can be fixed.
// 2. Exploit the vulnerability by crafting a malicious input that allows you
//    to leak the password.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

#define PASSWORD "you will never find this"

int main(int argc, char *argv[]) {
    dlog_init(argc, argv);
    dlog_fun(main);

    char *password = malloc(sizeof(PASSWORD));
    strcpy(password, PASSWORD);
    dlog_var(password);

    char buf[32];
    user_input("Password", buf, sizeof(buf) - 1);

    if (strcmp(buf, password) == 0) {
        puts("Welcome, admin!");
    } else {
        printf(buf);
        puts(" is not the correct password!");
    }

    free(password);
    return 0;
}
