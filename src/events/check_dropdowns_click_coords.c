/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** check_dropdowns_click_coords
*/

#include "my_paint.h"
#include <SFML/System/Vector2.h>

static int check_coords_help(sfVector2f pos_mouse, menu_states *menu,
    all_dropdowns *dropdowns)
{
    if ((pos_mouse.x > dropdowns->help_dropdown->origin.x && pos_mouse.x <
    (dropdowns->help_dropdown->origin.x + dropdowns->help_dropdown->size.x)) &&
    (pos_mouse.y > dropdowns->help_dropdown->origin.y && pos_mouse.y <
    (dropdowns->help_dropdown->origin.y + dropdowns->help_dropdown->size.y))) {
        !menu->help_menu ? (menu->help_menu = true) : (menu->help_menu = false);
        menu->file_menu = false;
        menu->edit_menu = false;
        return 1;
    }
    return 0;
}

static int check_coords_edit(sfVector2f pos_mouse, menu_states *menu,
    all_dropdowns *dropdowns)
{
    if ((pos_mouse.x > dropdowns->edit_dropdown->origin.x && pos_mouse.x <
    (dropdowns->edit_dropdown->origin.x + dropdowns->edit_dropdown->size.x)) &&
    (pos_mouse.y > dropdowns->edit_dropdown->origin.y && pos_mouse.y <
    (dropdowns->edit_dropdown->origin.y + dropdowns->edit_dropdown->size.y))) {
        !menu->edit_menu ? (menu->edit_menu = true) : (menu->edit_menu = false);
        menu->file_menu = false;
        menu->help_menu = false;
        return 1;
    }
    return 0;
}

static int check_coords_file(sfVector2f pos_mouse, menu_states *menu,
    all_dropdowns *dropdowns)
{
    if ((pos_mouse.x > dropdowns->file_dropdown->origin.x && pos_mouse.x <
    (dropdowns->file_dropdown->origin.x + dropdowns->file_dropdown->size.x)) &&
    (pos_mouse.y > dropdowns->file_dropdown->origin.y && pos_mouse.y <
    (dropdowns->file_dropdown->origin.y + dropdowns->file_dropdown->size.y))) {
        !menu->file_menu ? (menu->file_menu = true) : (menu->file_menu = false);
        menu->edit_menu = false;
        menu->help_menu = false;
        return 1;
    }
    return 0;
}

void check_dropdowns_click_coords(sfVector2f pos_mouse, menu_states *menu,
    all_dropdowns *dropdowns)
{
    if (!check_coords_file(pos_mouse, menu, dropdowns) &&
        !check_coords_edit(pos_mouse, menu, dropdowns) &&
        !check_coords_help(pos_mouse, menu, dropdowns)) {
        menu->file_menu = false;
        menu->edit_menu = false;
        menu->help_menu = false;
    }
}
