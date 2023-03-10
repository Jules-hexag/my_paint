/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** mouse_clicked_events
*/

#include <SFML/Graphics/Types.h>
#include "my_paint.h"

void mouse_clicked_events(sfRenderWindow *window, menu_states *menu, all_dropdowns *dropdowns)
{
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(window,
        pos_mouse_pix, NULL);

    if ((pos_mouse.x > dropdowns->file_dropdown->origin.x && pos_mouse.x < (dropdowns->file_dropdown->origin.x + dropdowns->file_dropdown->size.x)) && (pos_mouse.y > dropdowns->file_dropdown->origin.y && pos_mouse.y < (dropdowns->file_dropdown->origin.y + dropdowns->file_dropdown->size.y))) {
        !menu->file_menu ? (menu->file_menu = true) : (menu->file_menu = false);
    }
    if ((pos_mouse.x > dropdowns->help_dropdown->origin.x && pos_mouse.x < (dropdowns->help_dropdown->origin.x + dropdowns->help_dropdown->size.x)) && (pos_mouse.y > dropdowns->help_dropdown->origin.y && pos_mouse.y < (dropdowns->help_dropdown->origin.y + dropdowns->help_dropdown->size.y))) {
        !menu->help_menu ? (menu->help_menu = true) : (menu->help_menu = false);
    }
}