/*
** EPITECH PROJECT, 2024
** Epi-Template-C
** File description:
** mini_vprintf
*/
#include "my.h"
#include <stdarg.h>

static void mini_printf_handle_string(va_list args)
{
    char *str = va_arg(args, char *);

    my_putstr(str);
}

static void mini_printf_handle_integer(va_list args)
{
    int num = va_arg(args, int);

    my_put_nbr(num);
}

static void mini_printf_handle_char(va_list args)
{
    char c = va_arg(args, int);

    my_putchar(c);
}

static void mini_printf_handle_default(char c)
{
    my_putchar('%');
    my_putchar(c);
}

static void mini_printf_handle_long(va_list args)
{
    long i = va_arg(args, long);

    my_put_long(i);
}

static int mini_printf_handle_pointer_p(va_list args)
{
    void *ptr = va_arg(args, void *);
    unsigned long address = (unsigned long)ptr;
    int printed_chars = 0;

    if (ptr == NULL) {
        printed_chars += my_putstr("(nil)");
        return printed_chars;
    }
    printed_chars += my_putstr("0x");
    printed_chars += my_put_hex((unsigned int)address, 0, 0);
    return printed_chars;
}

void mini_printf_verification_switch(const char *format, va_list args, int i)
{
    switch (format[i]) {
    case 's':
        mini_printf_handle_string(args);
        break;
    case 'd':
        mini_printf_handle_integer(args);
        break;
    case 'c':
        mini_printf_handle_char(args);
        break;
    case 'p':
        mini_printf_handle_pointer_p(args);
        break;
    case 'l':
        mini_printf_handle_long(args);
        break;
    default:
        mini_printf_handle_default(format[i]);
        break;
    }
}

void mini_vprintf(const char *format, va_list args)
{
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '\0') {
            i++;
            mini_printf_verification_switch(format, args, i);
        } else {
            my_putchar(format[i]);
        }
    }
}
