/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** destroy
*/

#include <stdlib.h>
#include "my_paint.h"

static void destroy_menus(all_dropdowns dropdowns)
{
    linked_dropdown *tmp_f = dropdowns.file_dropdown->next;
    linked_dropdown *tmp_e = dropdowns.edit_dropdown->next;
    linked_dropdown *tmp_h = dropdowns.help_dropdown->next;

    while (tmp_f != NULL) {
        sfText_destroy(tmp_f->text);
        sfRectangleShape_destroy(tmp_f->sprite);
        tmp_f = tmp_f->next;
    } free(dropdowns.file_dropdown);
    while (tmp_e != NULL) {
        sfText_destroy(tmp_e->text);
        sfRectangleShape_destroy(tmp_e->sprite);
        tmp_e = tmp_e->next;
    } free(dropdowns.edit_dropdown);
    while (tmp_h != NULL) {
        sfText_destroy(tmp_h->text);
        sfRectangleShape_destroy(tmp_h->sprite);
        tmp_h = tmp_h->next;
    } free(dropdowns.help_dropdown);
}

void destroy(main_elements_t *main_elms)
{
    sfSprite_destroy(main_elms->canva->sprite);
    sfTexture_destroy(main_elms->canva->texture);
    sfImage_destroy(main_elms->canva->image);

    destroy_menus(main_elms->dropdowns);

    sfRectangleShape_destroy(main_elms->dropdowns.menu_bar);
}
