// 1. Explain what's wrong with this code, what kind(s) of vulnerability it has,
//    and how it can be fixed.
// 2. Exploit the vulnerability by crafting a malicious input that allows you
//    to authenticate as the admin, without knowing the password.

#include <stdio.h>
#include <string.h>

#include "util.h"

int main(int argc, char *argv[]) {
    dlog_init(argc, argv);
    dlog_fun(main);

    struct {
        char buf[16];
        int authenticated;
    } data;

    data.authenticated = 0;

    dlog_var(data);

    user_input("Password", data.buf, sizeof(data));

    if (strcmp(data.buf, "p4ssw0rd") == 0) {
        data.authenticated = 1;
    }

    dlog_var(data);

    if (data.authenticated) {
        puts("Welcome, admin!");
    } else {
        puts("Who are you?");
    }

    return 0;
}
