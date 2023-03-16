/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** draw
*/

#include "my_paint.h"

void draw(main_elements_t *main_elms)
{
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(
        main_elms->window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(main_elms->window,
        pos_mouse_pix, NULL);
    fill_pixels(main_elms, pos_mouse);
    return;
}
