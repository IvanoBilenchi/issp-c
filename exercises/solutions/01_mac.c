// Implement a simple 64 bit message authentication code (MAC) by encrypting a digest using the
// xor_crypt function from the previous exercise.
//
// Hint: you can choose any hash function you like, even a non-cryptographic one.
//       One simple and efficient hash function is djb2: http://www.cse.yorku.ca/~oz/hash.html

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

struct Buffer {
    size_t size;
    uint8_t *data;
};

// Compute a 64-bit hash of the buffer.
uint64_t hash(struct Buffer const *buf) {
    uint64_t hash = 5381;
    for (size_t i = 0; i < buf->size; i++) {
        hash = (hash << 5U) + hash + buf->data[i];
    }
    return hash;
}

void xor_crypt(struct Buffer *buf, struct Buffer const *key) {
    for (size_t i = 0; i < buf->size; ++i) {
        buf->data[i] ^= key->data[i % key->size];
    }
}

// Compute the MAC of the data using the key.
uint64_t compute_mac(struct Buffer const *data, struct Buffer const *key) {
    uint64_t mac = hash(data);
    // In C, everything is essentially a blob of data, so we can treat the `mac` variable
    // as a buffer and pass it to the xor_crypt function. The size of the buffer is the size
    // of the variable, and the data is a pointer containing the address of the variable.
    struct Buffer hash_buf = { sizeof(mac), (uint8_t *)&mac };
    xor_crypt(&hash_buf, key);
    return mac;
}

// Verify that the MAC of the data matches the given MAC.
// You can either decrypt the MAC and compare it to the hash of the data,
// or compute the MAC again and compare it to the given MAC.
bool verify_mac(struct Buffer const *data, struct Buffer const *key, uint64_t mac) {
    return compute_mac(data, key) == mac;
}

int main(void) {
    char message[] = "This message should be authenticated";
    char const key[] = "s3cr3t_p4ssw0rd";

    struct Buffer data = { sizeof(message) - 1, (uint8_t *)message };
    struct Buffer key_buf = { sizeof(key) - 1, (uint8_t *)key };

    // 1. Compute the MAC of the message.
    uint64_t mac = compute_mac(&data, &key_buf);
    printf("MAC: 0x%016llx\n", mac);

    // 2. Verify the MAC of the message.
    if (verify_mac(&data, &key_buf, mac)) {
        puts("Message is authentic");
    } else {
        puts("Message is not authentic");
    }

    // 3. Modify the message and verify the MAC again.
    message[0] = 't';
    if (verify_mac(&data, &key_buf, mac)) {
        puts("Message is authentic");
    } else {
        puts("Message is not authentic");
    }

    return 0;
}
