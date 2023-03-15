/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** check_if_in_dropdown
*/

#include "my_paint.h"

int check_if_in_help_dropdown(sfVector2f pos_mouse, all_dropdowns *dropdowns,
    menu_states menu)
{
    if (menu.help_menu && (pos_mouse.x > dropdowns->help_dropdown->origin.x &&
    pos_mouse.x < (dropdowns->help_dropdown->origin.x +
    dropdowns->help_dropdown->size.x)) && (pos_mouse.y >
    dropdowns->help_dropdown->origin.y && (pos_mouse.y <
    (dropdowns->help_dropdown->origin.y +
    (dropdowns->help_dropdown->size.y * 3))))) {
        int button_index = pos_mouse.y / 20;
    }
    return 0;
}

int check_if_in_edit_dropdown(sfVector2f pos_mouse, all_dropdowns *dropdowns,
    menu_states menu)
{
    if (menu.edit_menu && (pos_mouse.x > dropdowns->edit_dropdown->origin.x &&
    pos_mouse.x < (dropdowns->edit_dropdown->origin.x +
    dropdowns->edit_dropdown->size.x)) && (pos_mouse.y >
    dropdowns->edit_dropdown->origin.y && (pos_mouse.y <
    (dropdowns->edit_dropdown->origin.y +
    (dropdowns->edit_dropdown->size.y * 3))))) {
        int button_index = pos_mouse.y / 20;
    }
    return 0;
}

int check_if_in_file_dropdown(sfVector2f pos_mouse,
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
        button_index == 3 ? new(main_elms->canva->image, main_elms->filename)
            : button_index;
    }
    return 0;
}
