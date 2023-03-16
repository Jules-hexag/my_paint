/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** check_if_in_tool_drpd
*/

#include "my_paint.h"
#include "my.h"

void check_if_in_pen_dropdown(sfVector2f pos_mouse,
    main_elements_t *main_elms)
{
    if (main_elms->menu.pen_menu && (pos_mouse.x >
    main_elms->popups.pen_size->origin.x &&
    pos_mouse.x < (main_elms->popups.pen_size->origin.x +
    main_elms->popups.pen_size->size.x)) && (pos_mouse.y >
    main_elms->popups.pen_size->origin.y && (pos_mouse.y <
    (main_elms->popups.pen_size->origin.y +
    (main_elms->popups.pen_size->size.y *
    count_elem_popup(main_elms->popups.pen_size)))))) {
        int button_index = pos_mouse.y / 20;
        pen_size(main_elms, button_index);
    }
}

void check_if_in_erase_dropdown(sfVector2f pos_mouse,
    main_elements_t *main_elms)
{
    if (main_elms->menu.eraser_menu && (pos_mouse.x >
    main_elms->popups.eraser_shape->origin.x &&
    pos_mouse.x < (main_elms->popups.eraser_shape->origin.x +
    main_elms->popups.eraser_shape->size.x)) && (pos_mouse.y >
    main_elms->popups.eraser_shape->origin.y && (pos_mouse.y <
    (main_elms->popups.eraser_shape->origin.y +
    (main_elms->popups.eraser_shape->size.y *
    count_elem_popup(main_elms->popups.eraser_shape)))))) {
        int button_index = pos_mouse.y / 20;
        eraser_shape(main_elms, button_index);
    }
}
