/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** draw_elements
*/

#include <SFML/Graphics/RenderWindow.h>
#include "my_paint.h"

void frame_loop(sfRenderWindow *window, all_dropdowns *dropdowns)
{
    menu_states menu = (menu_states) {
        .file_menu = 0,
        .help_menu = 0,
    };
    sfRenderWindow_clear(window, sfBlack);
    create_menu_bar(window, &menu);
    event_management(window);
    sfRenderWindow_display(window);
}
