// 1. Explain what's wrong with this code, what kind(s) of vulnerability it has,
//    and how it can be fixed.
// 2. Exploit the vulnerability by crafting a malicious input that allows you
//    to call the shellcode function.

#include <stdio.h>

#include "util.h"

void shellcode(void) {
    puts("You got shell!");
}

void greet(char const *name) {
    printf("Hello, %s!\n", name);
}

int user_input_int(void) {
    int n;
    if (scanf("%d", &n) != 1) n = 0;
    return n;
}

#define BUF_SIZE 16

int main(int argc, char *argv[]) {
    dlog_init(argc, argv);
    dlog_fun(main);
    dlog_fun(greet);
    dlog_fun(shellcode);

    struct {
        char buf[BUF_SIZE];
        void (*fun)(char const *);
    } data;

    data.fun = greet;

    printf("User name length: ");
    int len = user_input_int();

    if (len >= BUF_SIZE) {
        puts("User name too long!");
        return 1;
    }

    dlog_var(data);
    user_input("User name", data.buf, len);
    dlog_var(data);

    data.fun(data.buf);
    return 0;
}
