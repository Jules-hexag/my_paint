/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** create_bar
*/

#include "my_paint.h"
#include <SFML/Graphics/Types.h>

sfRectangleShape *create_menu_bar(sfRenderWindow *window,
    all_dropdowns *dropdowns)
{
    create_dropdowns(window, dropdowns);
    return create_bar_rectangle(window);
}
