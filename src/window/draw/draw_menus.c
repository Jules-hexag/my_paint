/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** draw_menus
*/

#include "my_paint.h"
#include <SFML/Graphics/Types.h>

void draw_permanent_dropdowns_elem(sfRenderWindow *window,
    sfRectangleShape *menu_bar, all_dropdowns *dropdowns)
{
    sfRenderWindow_drawRectangleShape(window, menu_bar, NULL);
    sfRenderWindow_drawRectangleShape(window, dropdowns->file_dropdown->sprite,
        NULL);
    sfRenderWindow_drawRectangleShape(window, dropdowns->edit_dropdown->sprite,
        NULL);
    sfRenderWindow_drawRectangleShape(window, dropdowns->help_dropdown->sprite,
        NULL);
}

void draw_hidden_dropdowns_buttons(menu_states *menu, sfRenderWindow *window,
    all_dropdowns *dropdowns)
{
    if (menu->file_menu) {
        linked_dropdown *tmp = dropdowns->file_dropdown->next;
        while (tmp != NULL) {
            sfRenderWindow_drawRectangleShape(window, tmp->sprite, NULL);
            tmp = tmp->next;
        }
    }
    if (menu->edit_menu) {
        linked_dropdown *tmp = dropdowns->edit_dropdown->next;
        while (tmp != NULL) {
            sfRenderWindow_drawRectangleShape(window, tmp->sprite, NULL);
            tmp = tmp->next;
        }
    }
    if (menu->help_menu) {
        linked_dropdown *tmp = dropdowns->help_dropdown->next;
        while (tmp != NULL) {
            sfRenderWindow_drawRectangleShape(window, tmp->sprite, NULL);
            tmp = tmp->next;
        }}
}