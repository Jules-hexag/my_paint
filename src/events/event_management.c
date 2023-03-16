/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** event_management
*/

#include "my_paint.h"

static void resize_event(sfEvent event, main_elements_t *main_elms)
{
    if (event.type == sfEvtResized) {
        sfView *view = sfView_create();
        sfVector2u new_size = sfRenderWindow_getSize(main_elms->window);
        sfView_setSize(view, (sfVector2f) {(float) new_size.x,
            (float) new_size.y});
        int n_x = new_size.x = new_size.x / 2;
        int n_y = new_size.y = new_size.y / 2;
        sfView_setCenter(view, (sfVector2f) {n_x, n_y});
        sfRenderWindow_setView(main_elms->window, view);
    }
}

static void mouse_button_event(sfEvent event, main_elements_t *main_elms)
{
    if (event.type == sfEvtMouseButtonReleased) main_elms->tool.doing = false;
    if (event.type == sfEvtMouseButtonPressed) {
        mouse_clicked_menu_events(main_elms);
        main_elms->tool.doing = true;
    }
}

static void mouse_moved_event(sfEvent event, main_elements_t *main_elms)
{
    if (event.type == sfEvtMouseMoved ||
        event.type == sfEvtMouseButtonReleased) {
        main_elms->tool.doing ? draw(main_elms) : 0;
        mouse_moved_menu_events(main_elms);
    }
}

void event_management(main_elements_t *main_elms)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(main_elms->window, &event)) {
        event.type == sfEvtClosed ? sfRenderWindow_close(main_elms->window) : 0;
        mouse_moved_event(event, main_elms);
        mouse_button_event(event, main_elms);
        resize_event(event, main_elms);
    }
}
