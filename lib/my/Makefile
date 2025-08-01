##
## EPITECH PROJECT, 2024
## B-CPE-101-NCY-1-1-myprintf-jean-baptiste.gossot
## File description:
## Makefile of lib/my
##

SRC 	= 	free_word_array.c 	\
		is_empty.c 	\
		mini_printf.c 	\
		mini_vprintf.c 	\
		my_atoi.c 	\
		my_compute_power_it.c 	\
		my_compute_power_rec.c 	\
		my_compute_square_root.c 	\
		my_convert_num_to_str.c 	\
		my_fabs.c 	\
		my_fgets.c 	\
		my_find_prime_sup.c 	\
		my_getnbr.c 	\
		my_isneg.c 	\
		my_is_prime.c 	\
		my_isprint.c 	\
		my_memset.c 	\
		my_putchar.c 	\
		my_put_float.c 	\
		my_put_hex.c 	\
		my_put_long.c 	\
		my_put_long_double.c 	\
		my_put_long_long.c 	\
		my_put_nbr.c 	\
		my_put_short_int.c 	\
		my_put_size_t.c 	\
		my_put_ssize_t.c 	\
		my_putstr.c 	\
		my_reverse_str.c 	\
		my_revstr.c 	\
		my_showmem.c 	\
		my_show_word_array.c 	\
		my_sort_int_array.c 	\
		my_strcapitalize.c 	\
		my_strcat.c 	\
		my_strchr.c 	\
		my_strcmp.c 	\
		my_strcpy.c 	\
		my_strdup.c 	\
		my_str_isalpha.c 	\
		my_str_islower.c 	\
		my_str_isnum.c 	\
		my_str_isprintable.c 	\
		my_str_isupper.c 	\
		my_strlen.c 	\
		my_strlowcase.c 	\
		my_strncat.c 	\
		my_strncmp.c 	\
		my_strncpy.c 	\
		my_strstr.c 	\
		my_strtok.c 	\
		my_str_to_word_array.c 	\
		my_strupcase.c 	\
		my_swap.c 	\
		randint.c 	\
		swap_index.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ./../../include/
clean:
	rm -f $(OBJ)
