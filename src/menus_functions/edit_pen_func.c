/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** edit_pen_func
*/

#include "my_paint.h"

void pen(main_elements_t *main_elements)
{
    main_elements->tool.eraser = false;
    main_elements->tool.pen = true;
    main_elements->menu.pen_menu = true;
}
