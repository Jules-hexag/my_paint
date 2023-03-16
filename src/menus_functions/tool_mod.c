/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** edit_pen_size
*/

#include "my_paint.h"

void pen_size(main_elements_t *main_elements, int button_index)
{
    if (button_index == 1) main_elements->pen_size = 1;
    if (button_index == 2) main_elements->pen_size = 4;
    if (button_index == 3) main_elements->pen_size = 8;
    if (button_index == 4) main_elements->pen_size = 10;
    if (button_index == 5) main_elements->pen_size = 12;
    if (button_index == 6) main_elements->pen_size = 20;
}

void eraser_shape(main_elements_t *main_elements, int button_index)
{
    if (button_index == 2)
        main_elements->eraser_state = ROUND;
    if (button_index == 3) main_elements->eraser_state = SQUARE;
}
