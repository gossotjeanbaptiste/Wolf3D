##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## compiles libmy
##

LIB = libmy.a libmy_graphical.a
PROJECT_NAME = wolf3d
MY_LIB = -lmy -lmy_graphical
CFLAGS = -Wall -Wextra -Wunused -Wimplicit -O3
SRC = $(wildcard *.c) $(wildcard src/*.c) $(wildcard src/init/*.c) \
$(wildcard src/input/*.c) $(wildcard src/menu/tools/*.c)\
$(wildcard src/menu/*.c) $(wildcard src/draw/*.c) \
$(wildcard src/weapon/*.c)

CSFML_LIB = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio \
-lcsfml-system -lcsfml-network -lm

SRC_SEGV = $(wildcard *.c) $(wildcard src/*.c) $(wildcard lib/my/*.c) \
$(wildcard src/init/*.c) $(wildcard src/menu/*.c) \
$(wildcard src/input/*.c) $(wildcard src/draw/*.c) \
$(wildcard src/weapon/*.c) $(wildcard lib/my_graphical/*.c) \
$(wildcard src/menu/tools/*.c)

OBJ = $(SRC:.c=.o)
INCL = -I include/
LIB_C = -L ./ $(MY_LIB) $(CSFML_LIB)

all: libmy.a $(PROJECT_NAME)

start :
		mv gitignore.txt .gitignore
		mv src/project.c src/$(PROJECT_NAME).c

libmy.a:
		cd lib/my && make
		mv lib/my/libmy.a ./
		rm -f include/my.h
		cp lib/my/my.h include/
		cd lib/my_graphical && make
		@echo "libmy.a and libmy_graphical.a has been compiled."

$(PROJECT_NAME): $(OBJ)
		gcc -o $(PROJECT_NAME) $(OBJ) $(INCL) $(LIB_C) $(CFLAGS) -lm

clean:
		cd lib/my && make clean
		rm -f $(OBJ)

fclean: clean
		rm -f a.out
		rm -f $(LIB)
		rm -f $(PROJECT_NAME)
		rm -f *~
		rm -f src/*~
		rm -f lib/my/libmy.a
		rm -f lib/my/*.o
		rm -f lib/my/*~
		rm -f coding-style-reports.log
		rm -f *.gcno
		rm -f *.gcda
		rm -f unit_tests
		rm -f *.out
		rm -f *#
		@echo "Everything has been cleaned, do make to have a \
new libmy and compilation"

re: fclean all

cs: fclean
		clear
		@echo "All none compliant file for coding style \
has been cleaned, do make to have a \
new libmy and compilation"
		coding-style . .
		cat coding-style-reports.log
		rm -f coding-style-reports.log

unit_tests: fclean
		make all
		gcc -o unit_tests tests/*.c -I include/ \
			-L ./ -lmy -lcriterion --coverage


tests_run: unit_tests
		./unit_tests
		gcovr --exclude tests/
		gcovr --exclude tests/ --branches
		make fclean

segfault:
		gcc -o $(PROJECT_NAME) -g $(SRC_SEGV) $(INCL) $(CFLAGS) $(CSFML_LIB)

printf:
		grep -Rn printf

.PHONY: cs all clean fclean re
