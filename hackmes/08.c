// 1. Explain what's wrong with this code, what kind(s) of vulnerability it has,
//    and how it can be fixed.
// 2. Exploit the vulnerability by crafting a malicious input that allows you
//    to authenticate as the admin, without knowing the password.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "util.h"

int random_canary(void) {
    srand(time(NULL));
    return rand();
}

int main(int argc, char *argv[]) {
    dlog_init(argc, argv);
    dlog_fun(main);

    int const canary_value = random_canary();

    struct {
        char pass[16];
        int canary;
        int authenticated;
    } data;

    data.canary = canary_value;
    data.authenticated = 0;

    dlog_var(data);
    user_input("Password", data.pass, sizeof(data));

    if (strcmp(data.pass, "p4ssw0rd") == 0) {
        data.authenticated = 1;
    }

    dlog_var(data);

    if (data.canary != canary_value) {
        puts("Smashing detected!");
        return 1;
    }

    if (data.authenticated) {
        puts("Welcome, admin!");
    } else {
        puts("Who are you?");
    }

    return 0;
}
