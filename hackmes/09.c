// 1. Explain what's wrong with this code, what kind(s) of vulnerability it has,
//    and how it can be fixed.
// 2. Exploit the vulnerability by crafting a malicious input that allows you
//    to call the shellcode function.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "util.h"

void shellcode(void) {
    puts("You got shell!");
}

void greet(char const *name) {
    printf("Hello, %s!\n", name);
}

int random_canary(void) {
    srand(time(NULL));
    return rand();
}

int main(int argc, char *argv[]) {
    dlog_init(argc, argv);
    dlog_fun(shellcode);

    int const canary_value = random_canary();

    struct {
        char name[64];
        char pass[16];
        int canary;
        int authenticated;
        void (*fun)(char const *);
    } data = { .canary = canary_value, .fun = greet };

    user_input("User name", data.name, sizeof(data.name) - 1);
    printf(data.name);
    user_input(" password", data.pass, sizeof(data));

    if (strcmp(data.name, "admin") == 0 && strcmp(data.pass, "p4ssw0rd") == 0) {
        data.authenticated = 1;
    }

    if (data.canary != canary_value) {
        puts("Smashing detected!");
        return 1;
    }

    if (data.authenticated) {
        data.fun(data.name);
    } else {
        puts("Who are you?");
    }

    return 0;
}
