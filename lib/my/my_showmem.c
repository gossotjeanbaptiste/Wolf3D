/*
** EPITECH PROJECT, 2024
** my_showmem
** File description:
** show memory
*/
#include "my.h"

static void my_puthex2(unsigned char n)
{
    char hex_digits[] = "0123456789abcdef";
    char hex[2] = {hex_digits[(n >> 4) & 0xF], hex_digits[n & 0xF]};

    my_putstr(hex);
}

static void my_puthex8(int n)
{
    char hex_digits[] = "0123456789abcdef";
    char hex[8];

    for (int i = 7; i >= 0; i--) {
        hex[i] = hex_digits[n & 0xF];
        n >>= 4;
    }
    my_putstr(hex);
}

static void annexe_to_my_showmem3(int i, char const *str, int size)
{
    for (int j = 0; j < 16; j++) {
        if (i + j < size) {
            my_puthex2((unsigned char)str[i + j]);
            my_putstr(" ");
        } else {
            my_putstr("   ");
        }
    }
}

static void annexe_to_my_showmem2(char c)
{
    if (isprint((unsigned char)c)) {
        my_putchar(c);
    } else {
        my_putstr(".");
    }
}

static void annexe_to_my_showmem(int i, char const *str, int size)
{
    char c = str[i];

    for (int j = 0; j < 16; j++) {
        if (i + j < size) {
            c = str[i + j];
            annexe_to_my_showmem2(c);
        } else {
            my_putstr(" ");
        }
    }
}

int my_showmem(char const *str, int size)
{
    for (int i = 0; i < size; i += 16) {
        my_puthex8(i);
        my_putstr(": ");
        annexe_to_my_showmem3(i, str, size);
        my_putstr(" ");
        annexe_to_my_showmem(i, str, size);
        my_putstr("\n");
    }
    return 0;
}
