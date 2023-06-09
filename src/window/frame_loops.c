/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** draw_elements
*/

#include "my_paint.h"
#include "my.h"

static void canva_loop(sfRenderWindow *window, canva_t *canva)
{
    sfRenderWindow_clear(window, (sfColor_fromInteger(0x1d1d1dff)));
    sfRenderWindow_drawSprite(window, canva->sprite, NULL);
    return;
}

void frame_loop(main_elements_t *main_elms)
{
    event_management(main_elms);
    canva_loop(main_elms->window, main_elms->canva);
    draw_dropdowns_elem(main_elms);
    sfRenderWindow_display(main_elms->window);
}
