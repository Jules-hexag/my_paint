/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** create_buttons
*/

#include <SFML/System/Vector2.h>
#include "my_paint.h"
#include "my.h"

void create_dropdowns(menu_states *menu, all_dropdowns *dropdowns)
{
    new_left(&dropdowns->file_dropdown, "file", (sfVector2f) {-30, 0});
    new_left(&dropdowns->help_dropdown, "help", (sfVector2f) {-82, 0});
}
