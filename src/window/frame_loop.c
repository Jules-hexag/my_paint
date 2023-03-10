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

    while (menu->file_menu && dropdowns->file_dropdown->next != NULL) {
        dropdowns->file_dropdown = dropdowns->file_dropdown->next;
        sfRenderWindow_drawRectangleShape(window, dropdowns->file_dropdown->sprite, NULL);
    }

    while (menu->help_menu && dropdowns->help_dropdown->next != NULL) {
        dropdowns->help_dropdown = dropdowns->help_dropdown->next;
        sfRenderWindow_drawRectangleShape(window, dropdowns->help_dropdown->sprite, NULL);
    }

    sfRenderWindow_display(window);
}
