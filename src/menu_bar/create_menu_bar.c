/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** create_bar
*/

#include "my_paint.h"

int create_menu_bar(sfRenderWindow *window, menu_states *menu)
{
    create_bar_rectangle(window);
    create_dropdowns(window, menu);
    return SUCCESS_RETURN;
}
