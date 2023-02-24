/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** draw_elements
*/

#include <SFML/Graphics/RenderWindow.h>
#include "my_paint.h"

void frame_loop(sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    event_management(window);
    sfRenderWindow_display(window);
}
