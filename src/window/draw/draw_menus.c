/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** draw_menus
*/

#include "my_paint.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <unistd.h>

static void draw_elems(sfRenderWindow *window, linked_dropdown *tmp)
{
    sfRenderWindow_drawRectangleShape(window, tmp->sprite, NULL);
    sfRenderWindow_drawText(window, tmp->text, NULL);
}

static void draw_elems_popup(sfRenderWindow *window, linked_popup *tmp)
{
    sfRenderWindow_drawRectangleShape(window, tmp->sprite, NULL);
    sfRenderWindow_drawText(window, tmp->text, NULL);
}

static void draw_hidden_dropdowns_buttons_next(main_elements_t *main_elements)
{
    if (main_elements->menu.help_menu) {
        linked_dropdown *tmp = main_elements->dropdowns.help_dropdown->next;
        while (tmp != NULL) { draw_elems(main_elements->window, tmp);
            tmp = tmp->next;
        }
    }
    if (main_elements->menu.pen_menu) {
        linked_popup *tmp = main_elements->popups.pen_size;
        while (tmp != NULL) { draw_elems_popup(main_elements->window, tmp);
            tmp = tmp->next;
        }
    }
    if (main_elements->menu.eraser_menu) {
        linked_popup *tmp = main_elements->popups.eraser_shape;
        while (tmp != NULL) { draw_elems_popup(main_elements->window, tmp);
            tmp = tmp->next;
        }
    }
}

static void draw_hidden_dropdowns_buttons(main_elements_t *main_elements)
{
    if (main_elements->menu.file_menu) {
        linked_dropdown *tmp = main_elements->dropdowns.file_dropdown->next;
        while (tmp != NULL) { draw_elems(main_elements->window, tmp);
            tmp = tmp->next;
        }
    }
    if (main_elements->menu.edit_menu) {
        linked_dropdown *tmp = main_elements->dropdowns.edit_dropdown->next;
        while (tmp != NULL) { draw_elems(main_elements->window, tmp);
            tmp = tmp->next;
        }
    }
    draw_hidden_dropdowns_buttons_next(main_elements);
}

void draw_dropdowns_elem(main_elements_t *main_elements)
{
    sfRectangleShape_setSize(main_elements->dropdowns.menu_bar,
        (sfVector2f) {sfRenderWindow_getSize(main_elements->window).x, 20});
    sfRenderWindow_drawRectangleShape(main_elements->window,
        main_elements->dropdowns.menu_bar, NULL);

    sfRenderWindow_drawRectangleShape(main_elements->window,
        main_elements->dropdowns.file_dropdown->sprite, NULL);
    sfRenderWindow_drawText(main_elements->window,
        main_elements->dropdowns.file_dropdown->text, NULL);

    sfRenderWindow_drawRectangleShape(main_elements->window,
        main_elements->dropdowns.edit_dropdown->sprite, NULL);
    sfRenderWindow_drawText(main_elements->window,
        main_elements->dropdowns.edit_dropdown->text, NULL);

    sfRenderWindow_drawRectangleShape(main_elements->window,
        main_elements->dropdowns.help_dropdown->sprite, NULL);
    sfRenderWindow_drawText(main_elements->window,
        main_elements->dropdowns.help_dropdown->text, NULL);
    draw_hidden_dropdowns_buttons(main_elements);
}
