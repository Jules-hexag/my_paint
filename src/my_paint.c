/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** my_paint
*/

#include "my_paint.h"

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

static menu_states init_menus(void)
{
    menu_states menu = (menu_states) {
        .file_menu = false,
        .edit_menu = false,
        .help_menu = false,
        .pen_menu = false,
        .eraser_menu = false,
    };
    return menu;
}

static all_popups init_popups(void)
{
    linked_popup *pen_size = NULL;
    linked_popup *eraser_shape = NULL;
    all_popups popups = (all_popups) {
        .pen_size = pen_size,
        .eraser_shape = eraser_shape,
    };
    return popups;
}

static main_elements_t init_important_elements(int const argc,
    char *const *const argv, char const *const *env)
{
    main_elements_t main_elements = (main_elements_t) {
        .window = init_window(env),
        .menu = init_menus(),
        .canva = create_canva_default(),
        .dropdowns = init_dropdowns(),
        .popups = init_popups(),
        .eraser_state = ROUND,
        .tool = {true, false, false},
        .filename = (argc > 1) ? argv[1] : "beautiful.jpg",
        .pen_size = 8,
    };
    return main_elements;
}

int my_paint(int const argc, char const *const *env, char *const *const argv)
{
    (void) argv;
    main_elements_t main_elms = init_important_elements(argc, argv, env);
    if (!main_elms.window) return ERROR_RETURN;
    main_elms.dropdowns.menu_bar = create_menu_bar(main_elms.window,
        &main_elms.dropdowns);
    create_popups(main_elms.window, &main_elms.popups);
    while (sfRenderWindow_isOpen(main_elms.window)) {
        frame_loop(&main_elms);
    }
    destroy(&main_elms);
    sfRenderWindow_destroy(main_elms.window);
    return SUCCESS_RETURN;
}
