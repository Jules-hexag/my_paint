/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** create_popups
*/

#include "my.h"
#include "my_paint.h"

void create_popups(sfRenderWindow *window, all_popups *popups)
{
    new_right_popup(window, &popups->pen_size, "1px", (sfVector2f) {145, 20});
    new_right_popup(window, &popups->pen_size, "5px", (sfVector2f) {145, 40});
}
