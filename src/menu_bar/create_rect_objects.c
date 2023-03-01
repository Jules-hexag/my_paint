/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** create_rect_bar_object
*/

#include "my_paint.h"

    // sfColor button_color = {107, 107, 107, 100};
void create_menu_button(sfRenderWindow *window, linked_dropdown *button)
{
    sfRectangleShape *menu_button = sfRectangleShape_create();
    sfVector2u win_size = sfRenderWindow_getSize(window);
    sfRectangleShape_setSize(menu_button, button->size);
    sfRectangleShape_setOrigin(menu_button, button->origin);
    sfRectangleShape_setFillColor(menu_button, sfWhite);
    sfRenderWindow_drawRectangleShape(window, menu_button, NULL);
}

void create_bar_rectangle(sfRenderWindow *window)
{
    sfRectangleShape *menu_bar = sfRectangleShape_create();
    sfVector2u win_size = sfRenderWindow_getSize(window);
    float win_width = (float) win_size.x;
    sfVector2f menu_bar_size = {win_width, 20};
    sfColor bar_color = {107, 107, 107, 100};
    sfRectangleShape_setSize(menu_bar, menu_bar_size);
    sfRectangleShape_setOrigin(menu_bar, (sfVector2f) {0, 0});
    sfRectangleShape_setFillColor(menu_bar, bar_color);
    sfRenderWindow_drawRectangleShape(window, menu_bar, NULL);
}
