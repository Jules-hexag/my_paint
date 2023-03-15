/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** check_if_in_dropdown
*/

#include "my_paint.h"

void (*menus_func[7])(main_elements_t *main_elements) = {
    &new,
    NULL,
    &save,
    &pen,
    &eraser,
    NULL,
    NULL,
};

void check_if_in_help_dropdown(sfVector2f pos_mouse,
    main_elements_t *main_elms)
{
    if (main_elms->menu.help_menu && (pos_mouse.x >
    main_elms->dropdowns.help_dropdown->origin.x &&
    pos_mouse.x < (main_elms->dropdowns.help_dropdown->origin.x +
    main_elms->dropdowns.help_dropdown->size.x)) && (pos_mouse.y >
    main_elms->dropdowns.help_dropdown->origin.y && (pos_mouse.y <
    (main_elms->dropdowns.help_dropdown->origin.y +
    (main_elms->dropdowns.help_dropdown->size.y * 3))))) {
        // int button_index = pos_mouse.y / 20;
    }
}

void check_if_in_edit_dropdown(sfVector2f pos_mouse,
    main_elements_t *main_elms)
{
    if (main_elms->menu.edit_menu && (pos_mouse.x >
    main_elms->dropdowns.edit_dropdown->origin.x &&
    pos_mouse.x < (main_elms->dropdowns.edit_dropdown->origin.x +
    main_elms->dropdowns.edit_dropdown->size.x)) && (pos_mouse.y >
    main_elms->dropdowns.edit_dropdown->origin.y && (pos_mouse.y <
    (main_elms->dropdowns.edit_dropdown->origin.y +
    (main_elms->dropdowns.edit_dropdown->size.y * 3))))) {
        int button_index = pos_mouse.y / 20;
        if (button_index == 1) menus_func[3](main_elms);
        if (button_index == 2) menus_func[4](main_elms);
    }
}

void check_if_in_file_dropdown(sfVector2f pos_mouse,
    main_elements_t *main_elms)
{
    if (main_elms->menu.file_menu && (pos_mouse.x >
    main_elms->dropdowns.file_dropdown->origin.x &&
    pos_mouse.x < (main_elms->dropdowns.file_dropdown->origin.x +
    main_elms->dropdowns.file_dropdown->size.x)) && (pos_mouse.y >
    main_elms->dropdowns.file_dropdown->origin.y && (pos_mouse.y <
    (main_elms->dropdowns.file_dropdown->origin.y +
    (main_elms->dropdowns.file_dropdown->size.y * 4))))) {
        int button_index = pos_mouse.y / 20;
        if (button_index == 1) menus_func[0](main_elms);
        if (button_index == 3) menus_func[2](main_elms);
    }
}
