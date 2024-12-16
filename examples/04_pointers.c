#include <stdio.h>

void basic_manipulation(void) {
    int a = 42;
    int *a_ptr = NULL;
    a_ptr = &a;
    printf("Value of `*a_ptr`: %d\n", *a_ptr);
    a = 43;
    printf("Value of `*a_ptr` after changing `a`: %d\n", *a_ptr);
    *a_ptr = 44;
    printf("Value of `a` after changing `*a_ptr`: %d\n", a);
}

void add_to(int *a, int b) {
    *a += b;
}

void manipulation_via_pointer(void) {
    int a = 10;
    add_to(&a, 5);
    printf("10 + 5 = %d\n", a);
}

int *get_a(void) {
    int a = 42;
    return &a;
}

void dangling_pointer(void) {
    int *a_ptr = get_a();
    printf("Value of `*a_ptr`: %d\n", *a_ptr);
}

int main(void) {
    basic_manipulation();
    manipulation_via_pointer();
    dangling_pointer();
    return 0;
}
