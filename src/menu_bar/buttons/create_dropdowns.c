/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** create_buttons
*/

#include <SFML/System/Vector2.h>
#include "my_paint.h"
#include "my.h"

void create_dropdowns(sfRenderWindow *window, all_dropdowns *dropdowns)
{
    new_right(window, &dropdowns->file_dropdown, "file", (sfVector2f) {35, 0});
    new_right(window, &dropdowns->file_dropdown, "new", (sfVector2f) {35, 20});
    new_right(window, &dropdowns->file_dropdown, "open", (sfVector2f) {35, 40});
    new_right(window, &dropdowns->file_dropdown, "save", (sfVector2f) {35, 60});

    new_right(window, &dropdowns->edit_dropdown, "edit", (sfVector2f) {90, 0});
    new_right(window, &dropdowns->edit_dropdown, "pen", (sfVector2f) {90, 20});
    new_right(window, &dropdowns->edit_dropdown, "eraser",
        (sfVector2f) {90, 40});
    new_right(window, &dropdowns->edit_dropdown, "flip",
        (sfVector2f) {90, 60});
    new_right(window, &dropdowns->edit_dropdown, "invert",
        (sfVector2f) {90, 80});

    new_right(window, &dropdowns->help_dropdown, "help", (sfVector2f) {145, 0});
    new_right(window, &dropdowns->help_dropdown, "about",
        (sfVector2f) {145, 20});
    new_right(window, &dropdowns->help_dropdown, "help",
        (sfVector2f) {145, 40});
}
