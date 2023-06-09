/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** create_rect_bar_object
*/

#include "my_paint.h"

sfRectangleShape *create_menu_button_popup(sfRenderWindow *window,
    linked_popup *button)
{
    sfRectangleShape *menu_button = sfRectangleShape_create();
    sfRectangleShape_setPosition(menu_button,
        sfRenderWindow_mapPixelToCoords(window,
        (sfVector2i) {button->origin.x, button->origin.y}, NULL));
    sfRectangleShape_setSize(menu_button, button->size);
    sfRectangleShape_setOutlineThickness(menu_button, (float) 2);
    sfRectangleShape_setOutlineColor(menu_button, sfBlack);
    sfRectangleShape_setFillColor(menu_button, (sfColor) {107, 107, 107, 255});
    return menu_button;
}

sfRectangleShape *create_menu_button(sfRenderWindow *window,
    linked_dropdown *button)
{
    sfRectangleShape *menu_button = sfRectangleShape_create();
    sfRectangleShape_setPosition(menu_button,
        sfRenderWindow_mapPixelToCoords(window,
        (sfVector2i) {button->origin.x, button->origin.y}, NULL));
    sfRectangleShape_setSize(menu_button, button->size);
    sfRectangleShape_setOutlineThickness(menu_button, (float) 2);
    sfRectangleShape_setOutlineColor(menu_button, sfBlack);
    sfRectangleShape_setFillColor(menu_button, (sfColor) {107, 107, 107, 255});
    return menu_button;
}

sfRectangleShape *create_bar_rectangle(sfRenderWindow *window)
{
    sfRectangleShape *menu_bar = sfRectangleShape_create();
    sfVector2u win_size = sfRenderWindow_getSize(window);
    float win_width = (float) win_size.x;
    sfVector2f menu_bar_size = {win_width, 20};
    sfColor bar_color = {79, 79, 79, 255};
    sfRectangleShape_setSize(menu_bar, menu_bar_size);
    sfRectangleShape_setPosition(menu_bar,
        sfRenderWindow_mapPixelToCoords(window,
        (sfVector2i) {0, 0}, NULL));
    sfRectangleShape_setFillColor(menu_bar, bar_color);
    return menu_bar;
}
