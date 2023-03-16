/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** hover_colorization
*/

#include "my_paint.h"

void file_button(linked_dropdown *file_dropdown, sfVector2f pos_mouse)
{
    if ((pos_mouse.x > file_dropdown->origin.x && pos_mouse.x <
    (file_dropdown->origin.x + file_dropdown->size.x)) && (pos_mouse.y >
    file_dropdown->origin.y && pos_mouse.y <
    (file_dropdown->origin.y + file_dropdown->size.y))) {
        file_dropdown->button_state = HOVER;
        sfRectangleShape_setFillColor(file_dropdown->sprite,
            (sfColor) {107, 0, 40, 255});
    } else {
        file_dropdown->button_state = NONE;
        sfRectangleShape_setFillColor(file_dropdown->sprite,
            (sfColor) {107, 107, 107, 255});
    }
}

void edit_button(linked_dropdown *edit_dropdown, sfVector2f pos_mouse)
{
    if ((pos_mouse.x > edit_dropdown->origin.x && pos_mouse.x <
    (edit_dropdown->origin.x + edit_dropdown->size.x)) && (pos_mouse.y >
    edit_dropdown->origin.y && pos_mouse.y <
    (edit_dropdown->origin.y + edit_dropdown->size.y))) {
        edit_dropdown->button_state = HOVER;
        sfRectangleShape_setFillColor(edit_dropdown->sprite,
            (sfColor) {107, 0, 40, 255});
    } else {
        edit_dropdown->button_state = NONE;
        sfRectangleShape_setFillColor(edit_dropdown->sprite,
            (sfColor) {107, 107, 107, 255});
    }
}

void help_button(linked_dropdown *help_dropdown, sfVector2f pos_mouse)
{
    if ((pos_mouse.x > help_dropdown->origin.x && pos_mouse.x <
        (help_dropdown->origin.x + help_dropdown->size.x)) && (pos_mouse.y >
        help_dropdown->origin.y && pos_mouse.y <
        (help_dropdown->origin.y + help_dropdown->size.y))) {
            help_dropdown->button_state = HOVER;
            sfRectangleShape_setFillColor(help_dropdown->sprite,
                (sfColor) {107, 0, 40, 255});
    } else {
        help_dropdown->button_state = NONE;
        sfRectangleShape_setFillColor(help_dropdown->sprite,
            (sfColor) {107, 107, 107, 255});
    }
}

void pen_selection(linked_popup *pen, sfVector2f pos_mouse)
{
    if ((pos_mouse.x > pen->origin.x && pos_mouse.x <
        (pen->origin.x + pen->size.x)) && (pos_mouse.y >
        pen->origin.y && pos_mouse.y <
        (pen->origin.y + pen->size.y))) {
            pen->button_state = HOVER;
            sfRectangleShape_setFillColor(pen->sprite,
                (sfColor) {107, 0, 40, 255});
    } else {
        pen->button_state = NONE;
        sfRectangleShape_setFillColor(pen->sprite,
            (sfColor) {107, 107, 107, 255});
    }
}

void do_hover(sfVector2f pos_mouse, main_elements_t *main_elms)
{
    linked_dropdown *tmp = main_elms->dropdowns.file_dropdown;
    linked_popup *tmp_p = main_elms->popups.pen_size;
    while (tmp != NULL) {
        file_button(tmp, pos_mouse);
        tmp = tmp->next;
    }
    tmp = main_elms->dropdowns.edit_dropdown;
    while (tmp != NULL) {
        edit_button(tmp, pos_mouse);
        tmp = tmp->next;
    }
    tmp = main_elms->dropdowns.help_dropdown;
    while (tmp != NULL) {
        help_button(tmp, pos_mouse);
        tmp = tmp->next;
    }
    while (tmp_p != NULL) {
        pen_selection(main_elms->popups.pen_size, pos_mouse);
        tmp_p = tmp_p->next;
    }
}
