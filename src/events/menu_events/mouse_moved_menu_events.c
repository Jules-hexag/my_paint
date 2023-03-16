/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** mouse_events
*/

#include "my_paint.h"

void mouse_moved_menu_events(main_elements_t *main_elms)
{
    sfVector2i pos_mouse_pix =
        sfMouse_getPositionRenderWindow(main_elms->window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(main_elms->window,
        pos_mouse_pix, sfRenderWindow_getView(main_elms->window));
    do_hover(pos_mouse, main_elms);
}
