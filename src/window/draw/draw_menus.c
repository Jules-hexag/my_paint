/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** draw_menus
*/

#include "my_paint.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>

static void draw_elems(sfRenderWindow *window, linked_dropdown *tmp)
{
    sfRenderWindow_drawRectangleShape(window, tmp->sprite, NULL);
    sfRenderWindow_drawText(window, tmp->text, NULL);
}

static void draw_hidden_dropdowns_buttons(menu_states *menu,
    sfRenderWindow *window, all_dropdowns *dropdowns)
{
    if (menu->file_menu) {
        linked_dropdown *tmp = dropdowns->file_dropdown->next;
        while (tmp != NULL) { draw_elems(window, tmp);
            tmp = tmp->next;
        }
    }
    if (menu->edit_menu) {
        linked_dropdown *tmp = dropdowns->edit_dropdown->next;
        while (tmp != NULL) { draw_elems(window, tmp);
            tmp = tmp->next;
        }
    }
    if (menu->help_menu) {
        linked_dropdown *tmp = dropdowns->help_dropdown->next;
        while (tmp != NULL) { draw_elems(window, tmp);
            tmp = tmp->next;
        }
    }
}

void draw_dropdowns_elem(sfRenderWindow *window, all_dropdowns *dropdowns,
    menu_states *menu)
{
    sfRenderWindow_drawRectangleShape(window, dropdowns->menu_bar, NULL);

    sfRenderWindow_drawRectangleShape(window, dropdowns->file_dropdown->sprite,
        NULL);
    sfRenderWindow_drawText(window, dropdowns->file_dropdown->text, NULL);

    sfRenderWindow_drawRectangleShape(window, dropdowns->edit_dropdown->sprite,
        NULL);
    sfRenderWindow_drawText(window, dropdowns->edit_dropdown->text, NULL);

    sfRenderWindow_drawRectangleShape(window, dropdowns->help_dropdown->sprite,
        NULL);
    sfRenderWindow_drawText(window, dropdowns->help_dropdown->text, NULL);
    draw_hidden_dropdowns_buttons(menu, window, dropdowns);
}
