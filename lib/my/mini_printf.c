/*
** EPITECH PROJECT, 2024
** B-CPE-101-NCY-1-1-miniprintf-jean-baptiste.gossot
** File description:
** mini_printf
*/
#include "my.h"

static int count_format_specifiers(const char *format)
{
    int count = 0;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && (format[i + 1] == 's' ||
        format[i + 1] == 'd' || format[i + 1] == '%' ||
        format[i + 1] == 'i' || format[i + 1] == 'c')) {
            count++;
            i++;
        }
    }
    return count;
}

static int count_arguments(const char *format)
{
    int count = 0;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && (format[i + 1] == 's' ||
        format[i + 1] == 'd' || format[i + 1] == '%' ||
        format[i + 1] == 'i' || format[i + 1] == 'c')) {
            count++;
            i++;
        }
    }
    return count;
}

static int error_handler(const char *format, ...)
{
    va_list args;
    int format_specifiers_count = 0;
    int arguments_count = 0;

    va_start(args, format);
    format_specifiers_count = count_format_specifiers(format);
    arguments_count = count_arguments(format);
    va_end(args);
    if (format_specifiers_count != arguments_count) {
        my_putstr("Error: wrong format\n");
        return 84;
    }
    return 0;
}

int mini_printf(const char *format, ...)
{
    int format_len = my_strlen(format);
    va_list list;

    va_start(list, format);
    if (error_handler(format, format_len) == 84) {
        va_end(list);
        return 84;
    }
    mini_vprintf(format, list);
    va_end(list);
    return 0;
}
