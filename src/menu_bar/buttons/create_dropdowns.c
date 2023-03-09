/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** create_buttons
*/

#include <SFML/System/Vector2.h>
#include "my_paint.h"
#include "my.h"

void create_dropdowns(sfRenderWindow *window, menu_states *menu, all_dropdowns *dropdowns)
{
    (void) menu;
    new_left(window, &dropdowns->file_dropdown, "file", (sfVector2f) {35, 0});
    new_left(window, &dropdowns->help_dropdown, "help", (sfVector2f) {87, 0});
}
