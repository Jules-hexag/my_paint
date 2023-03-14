/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** event_management
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_paint.h"

void event_management(sfRenderWindow *window, menu_states *menu,
    all_dropdowns *dropdowns)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        event.type == sfEvtClosed ? sfRenderWindow_close(window) : 0;
        if (event.type == sfEvtMouseMoved ||
            event.type == sfEvtMouseButtonReleased) {
            mouse_moved_menu_events(window, menu, dropdowns);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            mouse_clicked_menu_events(window, menu, dropdowns);
        }
        if (event.type == sfEvtResized) {
            sfView *view = sfView_create();
            sfVector2u new_size = sfRenderWindow_getSize(window);
            sfView_setSize(view, (sfVector2f) {(float) new_size.x,
                (float) new_size.y});
            sfView_setCenter(view, (sfVector2f) {new_size.x / 2,
                new_size.y / 2});
            sfRenderWindow_setView(window, view);
        }
    }
}
