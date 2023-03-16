/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** check_dropdowns_click_coords
*/

#include "my_paint.h"
#include "my.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>

static int check_coords_help(sfVector2f pos_mouse, menu_states *menu,
    linked_dropdown *help_dropdown)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(help_dropdown->sprite);
    if (sfFloatRect_contains(&rect, pos_mouse.x, pos_mouse.y)) {
        sfRectangleShape_setFillColor(help_dropdown->sprite,
            (sfColor) {66, 1, 9, 255});
        (!menu->help_menu) ?
            (menu->help_menu = true) : (menu->help_menu = false);
        menu->file_menu = false;
        menu->edit_menu = false;
        return 1;
    }
    return 0;
}

static int check_coords_edit(sfVector2f pos_mouse, main_elements_t *main_elms)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(
            main_elms->dropdowns.edit_dropdown->sprite);
    if (sfFloatRect_contains(&rect, pos_mouse.x, pos_mouse.y)) {
        sfRectangleShape_setFillColor(
            main_elms->dropdowns.edit_dropdown->sprite,
            (sfColor) {66, 1, 9, 255});
        (!main_elms->menu.edit_menu) ?
            (main_elms->menu.edit_menu = true) :
            (main_elms->menu.edit_menu = false);
        main_elms->menu.file_menu = false;
        main_elms->menu.help_menu = false;
        return 1;
    }
    return 0;
}

static int check_coords_file(sfVector2f pos_mouse, menu_states *menu,
    linked_dropdown *file_dropdown)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(file_dropdown->sprite);
    if (sfFloatRect_contains(&rect, pos_mouse.x, pos_mouse.y)) {
        sfRectangleShape_setFillColor(file_dropdown->sprite,
            (sfColor) {66, 1, 9, 255});
        (!menu->file_menu) ?
            (menu->file_menu = true) : (menu->file_menu = false);
        menu->edit_menu = false;
        menu->help_menu = false;
        return 1;
    }
    return 0;
}

void check_dropdowns_click_coords(sfVector2f pos_mouse, menu_states *menu,
    all_dropdowns *dropdowns, main_elements_t *main_elms)
{
    int track_return = 0;
    linked_dropdown *tmp_file = dropdowns->file_dropdown;
    linked_dropdown *tmp_help = dropdowns->help_dropdown;

    track_return += check_coords_file(pos_mouse, menu, tmp_file);
    track_return += check_coords_edit(pos_mouse, main_elms);
    track_return += check_coords_help(pos_mouse, menu, tmp_help);

    if (track_return == 0) {
        menu->file_menu = false;
        menu->edit_menu = false;
        menu->help_menu = false;
        menu->pen_menu = false;
        menu->eraser_menu = false;
    }
}
