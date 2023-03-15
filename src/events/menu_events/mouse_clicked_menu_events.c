/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** mouse_clicked_events
*/

#include "my_paint.h"

void (*drpd_bound[3])(sfVector2f pos_mouse, main_elements_t *main_elements) = {
    &check_if_in_file_dropdown,
    &check_if_in_edit_dropdown,
    &check_if_in_help_dropdown,
};

void mouse_clicked_menu_events(main_elements_t *main_elms)
{
    sfVector2i pos_mouse_pix = sfMouse_getPositionRenderWindow(
        main_elms->window);
    sfVector2f pos_mouse = sfRenderWindow_mapPixelToCoords(
        main_elms->window, pos_mouse_pix, NULL);

    main_elms->menu.file_menu ? drpd_bound[0](pos_mouse, main_elms) : 0;
    main_elms->menu.edit_menu ? drpd_bound[1](pos_mouse, main_elms) : 0;
    main_elms->menu.help_menu ? drpd_bound[2](pos_mouse, main_elms) : 0;

    check_dropdowns_click_coords(pos_mouse, &main_elms->menu,
        &main_elms->dropdowns);
}
