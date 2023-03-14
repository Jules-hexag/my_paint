/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** create_window
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <stdio.h>
#include "my.h"
#include "my_paint.h"

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

sfRenderWindow *init_window(char **env)
{
    if (display_mode(env)) return NULL;
    const char title[] = "Shotophop";
    sfVideoMode mode = {1600, 900, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, title, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);

    sfView *view = sfView_create();
    sfView_setSize(view, (sfVector2f) {1600, 900});
    sfView_setCenter(view, (sfVector2f) {800, 450});
    sfRenderWindow_setView(window, view);
    return window;
}
