/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** event_management
*/

#include <stdlib.h>
#include "my_paint.h"

void event_management(sfRenderWindow *window)
{
    sfEvent event;
    menu_states *menu = malloc(sizeof(menu_states));
    menu->file_menu = 0;
    menu->help_menu = 0;
    create_menu_bar(window, menu);
    while (sfRenderWindow_pollEvent(window, &event)) {
        event.type == sfEvtClosed ? sfRenderWindow_close(window) : 0;
    }
    free(menu);
}
