#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

extern const char* PASSWORDS_PATH;

void encrypt(const unsigned char *input, unsigned char *output, const unsigned char *key);

void decrypt(const unsigned char *input, unsigned char *output, const unsigned char *key);

#endif