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

static all_dropdowns init_dropdowns(void)
{
    linked_dropdown *file_dropdown = NULL;
    linked_dropdown *help_dropdown = NULL;
    linked_dropdown *edit_dropdown = NULL;
    all_dropdowns dropdowns = (all_dropdowns) {
        .file_dropdown = file_dropdown,
        .edit_dropdown = edit_dropdown,
        .help_dropdown = help_dropdown,
    };
    return dropdowns;
}

int my_paint(char **env, char const *const *argv)
{
    (void) argv;
    sfRenderWindow *window = create_window(env);
    all_dropdowns dropdowns = init_dropdowns();
    menu_states menu = (menu_states) {
        .file_menu = false,
        .edit_menu = false,
        .help_menu = false,
    };
    if (!window) return ERROR_RETURN;
    canva_t *canva = create_canva_default();
    dropdowns.menu_bar = create_menu_bar(window, &menu, &dropdowns);
    while (sfRenderWindow_isOpen(window)) {
        frame_loop(window, &menu, canva, &dropdowns);
    }
    sfRenderWindow_destroy(window);
    return SUCCESS_RETURN;
}
