/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** mouse_events
*/

#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_paint.h"

static void file_button(all_dropdowns *dropdowns, sfVector2f pos_mouse)
{
    if ((pos_mouse.x > dropdowns->file_dropdown->origin.x && pos_mouse.x < (dropdowns->file_dropdown->origin.x + dropdowns->file_dropdown->size.x)) && (pos_mouse.y > dropdowns->file_dropdown->origin.y && pos_mouse.y < (dropdowns->file_dropdown->origin.y + dropdowns->file_dropdown->size.y))) {
        dropdowns->file_dropdown->button_state = HOVER;
        sfRectangleShape_setFillColor(dropdowns->file_dropdown->sprite, (sfColor) {250, 20, 102, 100});
    } else {
        dropdowns->file_dropdown->button_state = NONE;
        sfRectangleShape_setFillColor(dropdowns->file_dropdown->sprite, (sfColor) {200, 200, 200, 100});
    }
}

static void help_button(all_dropdowns *dropdowns, sfVector2f pos_mouse)
{
    if ((pos_mouse.x > dropdowns->help_dropdown->origin.x && pos_mouse.x < (dropdowns->help_dropdown->origin.x + dropdowns->help_dropdown->size.x)) && (pos_mouse.y > dropdowns->help_dropdown->origin.y && pos_mouse.y < (dropdowns->help_dropdown->origin.y + dropdowns->help_dropdown->size.y))) {
        dropdowns->help_dropdown->button_state = HOVER;
        sfRectangleShape_setFillColor(dropdowns->help_dropdown->sprite, (sfColor) {250, 20, 102, 100});
    } else {
        dropdowns->file_dropdown->button_state = NONE;
        sfRectangleShape_setFillColor(dropdowns->help_dropdown->sprite, (sfColor) {200, 200, 200, 100});
    }
}

void mouse_moved_events(sfRenderWindow *window, menu_states *menu, all_dropdowns *dropdowns)
{
    (void) menu;
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(window, pos_mouse_pix, NULL);
    file_button(dropdowns, pos_mouse);
    help_button(dropdowns, pos_mouse);
}