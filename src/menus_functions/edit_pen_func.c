/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** edit_pen_func
*/

#include "my_paint.h"

void pen(main_elements_t *main_elements)
{
    if (main_elements->menu.pen_menu) {
        main_elements->menu.pen_menu = false;
    } else {
        main_elements->menu.pen_menu = true;
    }
    main_elements->menu.eraser_menu = false;
    main_elements->tool.eraser = false;
    main_elements->tool.pen = true;
}
