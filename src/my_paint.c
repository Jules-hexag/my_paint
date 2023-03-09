/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** my_paint
*/

#include "my_paint.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <stdlib.h>

int my_paint(char **env)
{
    sfRenderWindow *window = create_window(env);
    linked_dropdown *file_dropdown = malloc(sizeof(linked_dropdown));
    linked_dropdown *help_dropdown = malloc(sizeof(linked_dropdown));
    all_dropdowns dropdowns = (all_dropdowns) {
        .file_dropdown = file_dropdown,
        .help_dropdown = help_dropdown,
    };
    menu_states menu = (menu_states) {
        .file_menu = false,
        .help_menu = false,
    };
    if (!window) return ERROR_RETURN;
    sfRectangleShape *menu_bar = create_menu_bar(window, &menu, &dropdowns);
    while (sfRenderWindow_isOpen(window)) {
        frame_loop(window, menu_bar, &menu, &dropdowns);
    }
    sfRenderWindow_destroy(window);
    return SUCCESS_RETURN;
}
