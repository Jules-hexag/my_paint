/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** draw
*/

#include "my_paint.h"

void draw(sfRenderWindow *window, canva_t *canva, selected_tool tool)
{
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(window,
        pos_mouse_pix, NULL);
    fill_pixels(canva, &pos_mouse, tool);
    return;
}
