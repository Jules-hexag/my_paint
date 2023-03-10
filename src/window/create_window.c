/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** create_window
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "my.h"

static int display_mode(char **env)
{
    int env_vars = 0;
    while (env[env_vars] != NULL) {
        if (!my_strncmp(env[env_vars], "DISPLAY=", 8))
            return 0;
        env_vars++;
    }
    return 1;
}

sfRenderWindow *create_window(char **env)
{
    if (display_mode(env)) return NULL;
    const char title[] = "Fenêtre";
    sfVideoMode mode = {1600, 900, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, title, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}
