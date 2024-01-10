#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/md5.h>

void calculateHash(const char *path, const char *algorithm) {
    FILE *file = fopen(path, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    unsigned char hash[SHA512_DIGEST_LENGTH]; // 가장 긴 해시 길이를 갖는 SHA-512에 맞춤
    int hashLength = 0;

    if (strcmp(algorithm, "SHA256") == 0) {
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        hashLength = SHA256_DIGEST_LENGTH;

        const int bufSize = 1024;
        unsigned char *buffer = malloc(bufSize);
        if (!buffer) {
            perror("Malloc failed");
            fclose(file);
            return;
        }

        int bytesRead;
        while ((bytesRead = fread(buffer, 1, bufSize, file))) {
            SHA256_Update(&sha256, buffer, bytesRead);
        }

        SHA256_Final(hash, &sha256);
        free(buffer);
    } else if (strcmp(algorithm, "SHA512") == 0) {
        SHA512_CTX sha512;
        SHA512_Init(&sha512);
        hashLength = SHA512_DIGEST_LENGTH;

        const int bufSize = 1024;
        unsigned char *buffer = malloc(bufSize);
        if (!buffer) {
            perror("Malloc failed");
            fclose(file);
            return;
        }

        int bytesRead;
        while ((bytesRead = fread(buffer, 1, bufSize, file))) {
            SHA512_Update(&sha512, buffer, bytesRead);
        }

        SHA512_Final(hash, &sha512);
        free(buffer);
    } else if (strcmp(algorithm, "MD5") == 0) {
        MD5_CTX md5;
        MD5_Init(&md5);
        hashLength = MD5_DIGEST_LENGTH;

        const int bufSize = 1024;
        unsigned char *buffer = malloc(bufSize);
        if (!buffer) {
            perror("Malloc failed");
            fclose(file);
            return;
        }

        int bytesRead;
        while ((bytesRead = fread(buffer, 1, bufSize, file))) {
            MD5_Update(&md5, buffer, bytesRead);
        }

        MD5_Final(hash, &md5);
        free(buffer);
    } else {
        printf("Unsupported algorithm: %s\n", algorithm);
        fclose(file);
        return;
    }

    fclose(file);

    for (int i = 0; i < hashLength; i++) {
        printf("%02X", hash[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Invalid arguments. Usage: %s [algorithm] [file path]...\n", argv[0]);
        printf("Supported algorithms: SHA256, SHA512, MD5\n");
        return 1;
    }

    const char *algorithm = argv[1];

    printf("-----------------------------------------------------------------------------\n");
    for (int i = 2; i < argc; i++) {
        printf("File path: %s\n", argv[i]);
        calculateHash(argv[i], algorithm);
        printf("-----------------------------------------------------------------------------\n");
    }

    return 0;
}