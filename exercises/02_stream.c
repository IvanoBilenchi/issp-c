// Implement a program that reads a file, encrypts it using a stream cipher, and writes the result
// to a new file. File paths and the key should be passed as command line arguments.
// The stream cipher should work by XORing the plaintext with a pseudorandom keystream.
// The keystream should be initialized with a hash of the key.
//
// Hint: you can use any random number generator to generate the keystream, such as an LCG or
//       a LFSR. The xorshift LFSR is simple and efficient: https://en.wikipedia.org/wiki/xorshift

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Buffer {
    size_t size;
    uint8_t *data;
};

// Returns the size of the file at the specified path in bytes.
// If the file does not exist or cannot be opened, the function returns 0.
size_t get_file_size(char const *path) {
    FILE *file = fopen(path, "rb");
    if (file == NULL) return 0;

    size_t size = 0;
    if (fseek(file, 0, SEEK_END) == 0) {
        size = ftell(file);
    }
    fclose(file);
    return size;
}

// Reads the contents of the file at the specified path into the buffer.
// Returns true if the file was read successfully, false otherwise.
bool read_file(char const *path, struct Buffer *buf) {
    FILE *file = fopen(path, "rb");
    if (file == NULL) return false;

    size_t read = fread(buf->data, 1, buf->size, file);
    fclose(file);
    return read == buf->size;
}

// Writes the contents of the buffer to a new file at the specified path.
// Returns true if the file was written successfully, false otherwise.
bool write_file(char const *path, struct Buffer const *buf) {
    FILE *file = fopen(path, "wb");
    if (file == NULL) return false;

    size_t written = fwrite(buf->data, 1, buf->size, file);
    fclose(file);
    return written == buf->size;
}

// The keystream generator function is essentially a pseudorandom number generator (PRNG).
// It takes a state variable as input and returns a new state variable after generating a number.
// The state is passed by pointer to allow the function to update it, which is necessary for
// generating a sequence of different numbers.
uint64_t prng(uint64_t *state) {
    return *state;
}

uint64_t hash(struct Buffer const *buf) {
    // You can take this from the previous exercise.
    return 0xFFFFFFFF;
}

// Encrypts or decrypts the buffer using the stream cipher.
// You should compute a hash of the key and use it to initialize the PRNG state.
// Then, iterate over the buffer and XOR each byte with a new byte from the PRNG.
// Hint: since the PRNG generates 64-bit numbers, you can use the lower 8 bits of each
//       generated number as the keystream byte.
void crypt(struct Buffer *buf, struct Buffer const *key) {
    // Implement.
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    char const *input_path = argv[1];
    char const *output_path = argv[2];
    char const *key = argv[3];

    // Hint: you can use strlen to get the length of the key string.
    //       sizeof(key) will return the size of the pointer, not the length of the string.

    // 1. Read the input file into a suitably sized, dynamically allocated buffer.

    // 2. Encrypt/decrypt the buffer containing the file data.

    // 3. Remember to release any allocated memory.

    return 0;
}
