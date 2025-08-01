/*
** EPITECH PROJECT, 2025
** Wolf3D
** File description:
** is_walkable_cell
*/

#include "../../include/csfml_include.h"
#include "../../include/my.h"
#include "../../include/struct_fb.h"

int is_walkable_cell(char cell)
{
    return (cell == '0' || (cell >= 'A' && cell <= 'Z'));
}
