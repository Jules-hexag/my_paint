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

void mouse_clicked_menu_events(sfRenderWindow *window, menu_states *menu,
    all_dropdowns *dropdowns)
{
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(window,
        pos_mouse_pix, NULL);
    check_dropdowns_click_coords(pos_mouse, menu, dropdowns);
}
