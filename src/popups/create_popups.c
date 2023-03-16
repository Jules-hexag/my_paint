/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** create_popups
*/

#include "my.h"
#include "my_paint.h"
#include <SFML/System/Vector2.h>

void create_popups(sfRenderWindow *window, all_popups *popups)
{
    new_right_popup(window, &popups->pen_size, "1 px",
        (sfVector2f) {145, 20});
    new_right_popup(window, &popups->pen_size, "4 px",
        (sfVector2f) {145, 40});
    new_right_popup(window, &popups->pen_size, "8 px",
        (sfVector2f) {145, 60});
    new_right_popup(window, &popups->pen_size, "10 px",
        (sfVector2f) {145, 80});
    new_right_popup(window, &popups->pen_size, "12 px",
        (sfVector2f) {145, 100});
    new_right_popup(window, &popups->pen_size, "20 px",
        (sfVector2f) {145, 120});

    new_right_popup(window, &popups->eraser_shape, "round",
        (sfVector2f) {145, 40});
    new_right_popup(window, &popups->eraser_shape, "square",
        (sfVector2f) {145, 60});
}
