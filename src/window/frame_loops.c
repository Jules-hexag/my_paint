/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** draw_elements
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <stdbool.h>
#include "my_paint.h"
#include "my.h"

void canva_loop(sfRenderWindow *window, sfRectangleShape *canva)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawRectangleShape(window, canva, NULL);
    return;
}

void menus_loop(sfRenderWindow *window, menu_states *menu,
    all_dropdowns *dropdowns)
{
    event_management(window, menu, dropdowns);
    draw_dropdowns_elem(window, dropdowns, menu);
    sfRenderWindow_display(window);
}
