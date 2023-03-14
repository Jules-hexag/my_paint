/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** check_dropdowns_click_coords
*/

#include "my_paint.h"
#include "my.h"
#include <SFML/System/Vector2.h>

static int check_coords_help(sfVector2f pos_mouse, menu_states *menu,
    linked_dropdown *help_dropdown)
{
    if ((pos_mouse.x > help_dropdown->origin.x && pos_mouse.x <
    (help_dropdown->origin.x + help_dropdown->size.x)) &&
    (pos_mouse.y > help_dropdown->origin.y && pos_mouse.y <
    (help_dropdown->origin.y + help_dropdown->size.y))) {
        sfRectangleShape_setFillColor(help_dropdown->sprite,
            (sfColor) {66, 1, 9, 255});
        (!menu->help_menu && !my_strncmp(help_dropdown->name, "help", 4)) ?
            (menu->help_menu = true) : (menu->help_menu = false);
        menu->file_menu = false;
        menu->edit_menu = false;
        return 1;
    }
    return 0;
}

static int check_coords_edit(sfVector2f pos_mouse, menu_states *menu,
    linked_dropdown *edit_dropdown)
{
    if ((pos_mouse.x > edit_dropdown->origin.x && pos_mouse.x <
    (edit_dropdown->origin.x + edit_dropdown->size.x)) &&
    (pos_mouse.y > edit_dropdown->origin.y && pos_mouse.y <
    (edit_dropdown->origin.y + edit_dropdown->size.y))) {
        sfRectangleShape_setFillColor(edit_dropdown->sprite,
            (sfColor) {66, 1, 9, 255});
        (!menu->edit_menu && !my_strncmp(edit_dropdown->name, "edit", 4)) ?
            (menu->edit_menu = true) : (menu->edit_menu = false);
        menu->file_menu = false;
        menu->help_menu = false;
        return 1;
    }
    return 0;
}

static int check_coords_file(sfVector2f pos_mouse, menu_states *menu,
    linked_dropdown *file_dropdown)
{
    if ((pos_mouse.x > file_dropdown->origin.x && pos_mouse.x <
    (file_dropdown->origin.x + file_dropdown->size.x)) &&
    (pos_mouse.y > file_dropdown->origin.y && pos_mouse.y <
    (file_dropdown->origin.y + file_dropdown->size.y))) {
        sfRectangleShape_setFillColor(file_dropdown->sprite,
            (sfColor) {66, 1, 9, 255});
        (!menu->file_menu && !my_strncmp(file_dropdown->name, "file", 4)) ?
            (menu->file_menu = true) : (menu->file_menu = false);
        menu->edit_menu = false;
        menu->help_menu = false;
        return 1;
    }
    return 0;
}

void check_dropdowns_click_coords(sfVector2f pos_mouse, menu_states *menu,
    all_dropdowns *dropdowns)
{
    int track_return = 0;
    linked_dropdown *tmp_file = dropdowns->file_dropdown;
    linked_dropdown *tmp_edit = dropdowns->edit_dropdown;
    linked_dropdown *tmp_help = dropdowns->help_dropdown;
    while (tmp_file != NULL) {
        track_return += check_coords_file(pos_mouse, menu, tmp_file);
        tmp_file = tmp_file->next;
    }
    while (tmp_edit != NULL) {
        track_return += check_coords_edit(pos_mouse, menu, tmp_edit);
        tmp_edit = tmp_edit->next;
    }
    while (tmp_help != NULL) {
        track_return += check_coords_help(pos_mouse, menu, tmp_help);
        tmp_help = tmp_help->next;
    }
    if (track_return == 0) { menu->file_menu = false;
        menu->edit_menu = false;
        menu->help_menu = false;
    }
}
