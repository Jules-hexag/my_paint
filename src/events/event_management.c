/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** event_management
*/

#include <SFML/Window/Event.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_paint.h"

void event_management(sfRenderWindow *window, menu_states *menu, all_dropdowns *dropdowns)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        event.type == sfEvtClosed ? sfRenderWindow_close(window) : 0;
        if (event.type == sfEvtMouseMoved) {
            mouse_events(window, menu, dropdowns);
        }
    }
}
