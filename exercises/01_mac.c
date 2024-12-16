// Implement a simple 64 bit message authentication code (MAC) by encrypting a digest using the
// xor_crypt function from the previous exercise.
//
// Hint: you can choose any hash function you like, even a non-cryptographic one.
//       One simple hash function is the djb2 hash function: http://www.cse.yorku.ca/~oz/hash.html

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

struct Buffer {
    size_t size;
    uint8_t *data;
};

uint64_t hash(struct Buffer const *buf) {
    // Implement.
    return 0xFFFFFFFF;
}

void xor_crypt(struct Buffer *buf, struct Buffer const *key) {
    // You can take this from the previous exercise.
}

uint64_t compute_mac(struct Buffer const *data, struct Buffer const *key) {
    // Implement.
    return 0xFFFFFFFF;
}

bool verify_mac(struct Buffer const *data, struct Buffer const *key, uint64_t mac) {
    // Implement.
    return false;
}

int main(void) {
    char message[] = "This message should be authenticated";
    char const key[] = "s3cr3t_p4ssw0rd";

    // 1. Compute the MAC of the message.
    uint64_t mac = 0;
    printf("MAC: 0x%016llx\n", mac);

    // 2. Verify the MAC of the message.

    // 3. Modify the message and verify the MAC again.

    return 0;
}