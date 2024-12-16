// Implement the one-time pad (OTP) encryption algorithm.
// If the key is shorter than the message, it should be repeated cyclically.

#include <stdint.h>
#include <stdio.h>

struct Buffer {
    size_t size;
    uint8_t *data;
};

void print_string_buffer(struct Buffer const *buf) {
    printf("%s\n", buf->data);
}

void print_binary_buffer(struct Buffer const *buf) {
    printf("0x");
    for (size_t i = 0; i < buf->size; ++i) {
        printf("%02x", buf->data[i]);
    }
    printf("\n");
}

void xor_crypt(struct Buffer *buf, struct Buffer const *key) {
    // Implement.
}

int main(void) {
    char data[] = "This is a very secret message";
    char const key[] = "s3cr3t_p4ssw0rd";

    // 1. Encrypt `data` in-place using the key, and print the result.

    // 2. Decrypt the result using the key, and print the original message.

    return 0;
}
