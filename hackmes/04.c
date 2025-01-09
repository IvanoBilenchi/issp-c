// 1. Explain what's wrong with this code, what kind(s) of vulnerability it has,
//    and how it can be fixed.
// 2. Exploit the vulnerability by crafting a malicious input that allows you
//    to leak the secret string.

#include <stdio.h>

#include "util.h"

#define SECRET_STRING "What are you doing here?"

int main(int argc, char *argv[]) {
    dlog_init(argc, argv);
    dlog_fun(main);

    struct {
        char buf[16];
        char secret[sizeof(SECRET_STRING)];
    } data = { .secret = SECRET_STRING };

    dlog_var(data);
    user_input("Echo", data.buf, sizeof(data.buf));
    dlog_var(data);
    printf("%s\n", data.buf);
    return 0;
}
