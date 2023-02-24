/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** create_rect_bar_object
*/

#include "my_paint.h"

sfRectangleShape *create_bar_rectangle(sfRenderWindow *window)
{
    sfRectangleShape *menu_bar = sfRectangleShape_create();
    sfVector2u win_size = sfRenderWindow_getSize(window);
    float win_width = (float) win_size.x;
    sfVector2f menu_bar_size = {win_width, 20};
    sfRectangleShape_setSize(menu_bar, menu_bar_size);
    sfRectangleShape_setOrigin(menu_bar, (sfVector2f) {0, 0});
    sfRectangleShape_setFillColor(menu_bar, sfWhite);
    sfRenderWindow_drawRectangleShape(window, menu_bar, NULL);
    return menu_bar;
}
