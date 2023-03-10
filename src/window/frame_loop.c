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

void frame_loop(sfRenderWindow *window, sfRectangleShape *menu_bar, menu_states *menu, all_dropdowns *dropdowns)
{
    sfRenderWindow_clear(window, sfBlack);
    event_management(window, menu, dropdowns);
    sfRenderWindow_drawRectangleShape(window, menu_bar, NULL);
    sfRenderWindow_drawRectangleShape(window, dropdowns->file_dropdown->sprite, NULL);
    sfRenderWindow_drawRectangleShape(window, dropdowns->help_dropdown->sprite, NULL);

    if (menu->file_menu) {
        sfRenderWindow_drawRectangleShape(window, dropdowns->file_dropdown->next->sprite, NULL);
        sfRenderWindow_drawRectangleShape(window, dropdowns->file_dropdown->next->next->sprite, NULL);
    }

    if (menu->help_menu)
        sfRenderWindow_drawRectangleShape(window, dropdowns->help_dropdown->next->sprite, NULL);

    sfRenderWindow_display(window);
}
