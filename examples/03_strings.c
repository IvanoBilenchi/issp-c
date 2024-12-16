#include <stdio.h>
#include <string.h>

void basic_manipulation(void) {
    char string[] = "string";
    string[3] = 'o';
    printf("String: %s\n", string);
    printf("String length: %zu\n", strlen(string));
    printf("String size: %zu\n", sizeof(string));
}

void oob_read(void) {
    char string[4];
    string[0] = 'a';
    string[1] = 'b';
    string[2] = 'c';
    string[3] = 'd';
    printf("String without NULL terminator: %s\n", string);
    string[3] = '\0';
    printf("String with NULL terminator: %s\n", string);
}

int main(void) {
    basic_manipulation();
    oob_read();
    return 0;
}
