#include <stdio.h>

void underscore_to_space(char *str) {
    for (size_t i = 0; str[i]; ++i) {
        if (str[i] == '_') {
            str[i] = ' ';
        }
    }
}

int main(void) {
    int a = 10;
    int *a_ptr = &a;
    printf("Value of `a`: %d\n", a_ptr[1]);
    char str[] = "this_was_a_snake_case_string";
    underscore_to_space(&str[5]);
    printf("%s\n", str);
    return 0;
}
