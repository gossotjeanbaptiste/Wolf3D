/*
** EPITECH PROJECT, 2024
** my header files
** File description:
** declaration of all functions
*/

#ifndef MY_H
    #define MY_H
    #include <stddef.h>
    #include <unistd.h>
    #include <inttypes.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <ctype.h>
    #define INT_MAX 2147483647
    #define M_PI 3.14159265358979323846
int randint(int min, int max);
void free_word_array(char **array);
int my_atoi(const char *str);
int is_empty(char const *str);
int my_compute_power_it(int nb, int p);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
void my_isneg(int n);
int my_is_prime(int nb);
int my_isprint(int c);
void *my_memset(void *ptr, int value, size_t size);
int my_putchar(char c);
int my_put_float(double nb, int precision);
int my_put_hex(unsigned int nb, int is_upper, int precision);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_put_size_t(size_t nb);
int my_put_long(long nb);
int my_put_long_double(long double nb);
int my_put_long_long(long long nb);
int my_put_short_int(short int nb);
int my_put_ssize_t(ssize_t nb);
int my_put_size_t(size_t nb);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_sort_int_array(int *tab, int size);
char *my_strchr(const char *str, int c);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(const char *s1, const char *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(const char *s1, const char *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
void my_swap_char(char *a, char *b);
void my_reverse_str(char *str, int len);
int my_convert_num_to_str(unsigned int num, char *str);
double my_fabs(double num);
char *my_fgets(char *buffer, int n, FILE *stream);
int mini_printf(const char *format, ...);
void mini_printf_verification_switch(const char *format, va_list args, int i);
void mini_vprintf(const char *format, va_list args);
void swap_index(char *result, int index, int i);
int my_show_word_array(char *const *tab);
char **my_str_to_word_array(char *str);
char *my_strtok(char *str, const char *delim);
#endif /* !MY_H */
