#ifndef PASSWORD_GEN_H
#define PASSWORD_GEN_H

typedef struct password_structure
{
    int alpha_min;
    int alpha_maj;
    int decimal;
    int special;
} password_structure;

extern const password_structure WEAK;
extern const password_structure MEDIUM;
extern const password_structure STRONG;
extern const password_structure ROBUST;
extern const password_structure SECURE;

void init_password_gen();

char* generatePassword(const password_structure p0);

#endif