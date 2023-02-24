/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** my_paint
*/

#include "my_paint.h"
#include <SFML/Graphics/RenderWindow.h>

int my_paint(char **env)
{
    sfRenderWindow *window = create_window(env);
    if (!window) return ERROR_RETURN;
    while (sfRenderWindow_isOpen(window)) {
        frame_loop(window);
    }
    sfRenderWindow_destroy(window);
    return SUCCESS_RETURN;
}
