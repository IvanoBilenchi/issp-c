// Implement the one-time pad (OTP) encryption algorithm.
// If the key is shorter than the message, it should be repeated cyclically.

#include <stdint.h>
#include <stdio.h>

// The buffer struct deals with uint8_t (unsigned char) instead of char
// to allow bitwise operations on the data, which are only well-defined
// for unsigned integer types.
struct Buffer {
    size_t size;   // Size of the buffer.
    uint8_t *data; // Pointer to the buffer data.
};

// Use this to print a buffer containing an ASCII string.
void print_string_buffer(struct Buffer const *buf) {
    printf("%s\n", buf->data);
}

// Use this to print a buffer containing binary data.
void print_binary_buffer(struct Buffer const *buf) {
    printf("LSB ");
    for (size_t i = 0; i < buf->size; ++i) {
        printf("%02x ", buf->data[i]);
    }
    printf("MSB\n");
}

// Encryption and decryption can be done using the same function, as XOR is its own inverse.
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
