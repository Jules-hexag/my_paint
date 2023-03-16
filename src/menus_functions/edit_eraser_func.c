/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** edit_eraser_func
*/

#include "my_paint.h"

void eraser(main_elements_t *main_elements)
{
    if (main_elements->menu.eraser_menu) {
        main_elements->menu.eraser_menu = false;
    } else {
        main_elements->menu.eraser_menu = true;
    }
    main_elements->tool.pen = false;
    main_elements->tool.eraser = true;
}
