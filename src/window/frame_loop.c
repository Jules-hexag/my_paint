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

void frame_loop(sfRenderWindow *window, sfRectangleShape *menu_bar,
    menu_states *menu, all_dropdowns *dropdowns)
{
    sfRenderWindow_clear(window, sfBlack);
    draw_permanent_dropdowns_elem(window, menu_bar, dropdowns);
    event_management(window, menu, dropdowns);
    draw_hidden_dropdowns_buttons(menu, window, dropdowns);
    sfRenderWindow_display(window);
}
