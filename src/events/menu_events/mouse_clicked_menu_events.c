/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** mouse_clicked_events
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include "my_paint.h"

void mouse_clicked_menu_events(main_elements_t *main_elements)
{
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(
        main_elements->window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(
        main_elements->window, pos_mouse_pix, NULL);
    if (main_elements->menu.file_menu)
        check_if_in_file_dropdown(pos_mouse, main_elements);
    check_dropdowns_click_coords(pos_mouse, &main_elements->menu,
        &main_elements->dropdowns);
}
