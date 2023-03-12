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

static void file_button(linked_dropdown *file_dropdown, sfVector2f pos_mouse)
{
    if ((pos_mouse.x > file_dropdown->origin.x && pos_mouse.x <
    (file_dropdown->origin.x + file_dropdown->size.x)) && (pos_mouse.y >
    file_dropdown->origin.y && pos_mouse.y <
    (file_dropdown->origin.y + file_dropdown->size.y))) {
        file_dropdown->button_state = HOVER;
        sfRectangleShape_setFillColor(file_dropdown->sprite,
            (sfColor) {250, 20, 102, 100});
    } else {
        file_dropdown->button_state = NONE;
        sfRectangleShape_setFillColor(file_dropdown->sprite,
            (sfColor) {200, 200, 200, 100});
    }
}

static void edit_button(linked_dropdown *edit_dropdown, sfVector2f pos_mouse)
{
    if ((pos_mouse.x > edit_dropdown->origin.x && pos_mouse.x <
    (edit_dropdown->origin.x + edit_dropdown->size.x)) && (pos_mouse.y >
    edit_dropdown->origin.y && pos_mouse.y <
    (edit_dropdown->origin.y + edit_dropdown->size.y))) {
        edit_dropdown->button_state = HOVER;
        sfRectangleShape_setFillColor(edit_dropdown->sprite,
            (sfColor) {250, 20, 102, 100});
    } else {
        edit_dropdown->button_state = NONE;
        sfRectangleShape_setFillColor(edit_dropdown->sprite,
            (sfColor) {200, 200, 200, 100});
    }
}

static void help_button(linked_dropdown *help_dropdown, sfVector2f pos_mouse)
{
    if ((pos_mouse.x > help_dropdown->origin.x && pos_mouse.x <
        (help_dropdown->origin.x + help_dropdown->size.x)) && (pos_mouse.y >
        help_dropdown->origin.y && pos_mouse.y <
        (help_dropdown->origin.y + help_dropdown->size.y))) {
            help_dropdown->button_state = HOVER;
            sfRectangleShape_setFillColor(help_dropdown->sprite,
                (sfColor) {250, 20, 102, 100});
    } else {
        help_dropdown->button_state = NONE;
        sfRectangleShape_setFillColor(help_dropdown->sprite,
            (sfColor) {200, 200, 200, 100});
    }
}

void mouse_moved_menu_events(sfRenderWindow *window, menu_states *menu,
    all_dropdowns *dropdowns)
{
    (void) menu;
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(window,
        pos_mouse_pix, NULL);
    linked_dropdown *tmp_file = dropdowns->file_dropdown;
    linked_dropdown *tmp_edit = dropdowns->edit_dropdown;
    linked_dropdown *tmp_help = dropdowns->help_dropdown;
    while (tmp_file != NULL) {
        file_button(tmp_file, pos_mouse);
        tmp_file = tmp_file->next;
    }
    while (tmp_edit != NULL) {
        edit_button(tmp_edit, pos_mouse);
        tmp_edit = tmp_edit->next;
    }
    while (tmp_help != NULL) {
        help_button(tmp_help, pos_mouse);
        tmp_help = tmp_help->next;
    }
}
