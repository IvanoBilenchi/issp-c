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
    for (size_t i = 0; i < buf->size; ++i) {
        printf("0x%02x ", buf->data[i]);
    }
    printf("\n");
}

// Encryption and decryption can be done using the same function, as XOR is its own inverse.
void xor_crypt(struct Buffer *buf, struct Buffer const *key) {
    // Iterate over the buffer and XOR each byte with the corresponding byte in the key.
    // i % key->size will cycle the key if it is shorter than the buffer.
    for (size_t i = 0; i < buf->size; ++i) {
        buf->data[i] ^= key->data[i % key->size];
    }
}

int main(void) {
    char data[] = "This is a very secret message";
    char const key[] = "s3cr3t_p4ssw0rd";

    // Initialize the buffer structs.
    // We use (sizeof(data) - 1) as the size to exclude the null terminator.
    // The string arrays are cast to uint8_t pointers to match the Buffer struct.
    // Generally speaking, casts between pointers to different types are illegal in C.
    // However, casting to a pointer to unsigned char is always allowed.
    struct Buffer buf = { sizeof(data) - 1, (uint8_t *)data };
    struct Buffer key_buf = { sizeof(key) - 1, (uint8_t *)key };

    // 1. Encrypt `data` in-place using the key, and print the result.
    xor_crypt(&buf, &key_buf);
    print_binary_buffer(&buf);

    // 2. Decrypt the result using the key, and print the original message.
    xor_crypt(&buf, &key_buf);
    print_string_buffer(&buf);

    return 0;
}
