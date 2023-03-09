/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** mouse_events
*/

#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_paint.h"

int mouse_events(sfRenderWindow *window, menu_states *menu, all_dropdowns *dropdowns)
{
    (void) menu;
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(window, pos_mouse_pix, NULL);
    if ((pos_mouse.x > dropdowns->file_dropdown->origin.x && pos_mouse.x < (dropdowns->file_dropdown->origin.x + dropdowns->file_dropdown->size.x)) && (pos_mouse.y > dropdowns->file_dropdown->origin.y && pos_mouse.y < (dropdowns->file_dropdown->origin.y + dropdowns->file_dropdown->size.y))) {
        printf("C'est dedans\n");
    }
    return 0;
}