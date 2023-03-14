/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** draw_elements
*/

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <stdbool.h>
#include "my_paint.h"
#include "my.h"

static void canva_loop(sfRenderWindow *window, canva_t *canva)
{
    sfRenderWindow_clear(window, (sfColor_fromInteger(0x1d1d1dff)));
    sfRenderWindow_drawSprite(window, canva->sprite, NULL);
    return;
}

void frame_loop(sfRenderWindow *window, menu_states *menu, canva_t *canva,
    all_dropdowns *dropdowns)
{
    event_management(window, menu, dropdowns);
    canva_loop(window, canva);
    draw_dropdowns_elem(window, dropdowns, menu);
    sfRenderWindow_display(window);
}
