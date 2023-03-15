/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** fill_pixels
*/

#include "my_paint.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <math.h>
#include <stdio.h>


static void draw_circle(sfVector2f *pos_mouse, int r, canva_t *canva,
    sfColor color)
{
    const double PI = 3.1415926535;
    double i = 0;
    double angle = 0;
    int x1 = 0;
    int y1 = 0;
    sfVector2f tl = sfSprite_getPosition(canva->sprite);
    int half_r = r / 2;
    int x = pos_mouse->x - tl.x - half_r;
    int y = pos_mouse->y - tl.y - half_r;

    while (r > 1) {
        for (i = 0; i < 360; i += 0.1) {
            angle = i;
            x1 = r * cos(angle * PI / 180);
            y1 = r * sin(angle * PI / 180);
            sfImage_setPixel(canva->image, x + x1, y + y1, color);
        }
        r--;
    }
    sfImage_setPixel(canva->image, x - r + 1, y - r + 1, color);
}

static int check_if_in_canva(canva_t *canva, sfVector2f *pos_mouse,
    selected_tool tool)
{
    sfVector2u canva_len = sfTexture_getSize(canva->texture);
    sfVector2f tl = sfSprite_getPosition(canva->sprite);
    sfVector2f tr = {tl.x + canva_len.x, tl.y};
    sfVector2f bl = {tl.x, tl.y + canva_len.y};
    if ((pos_mouse->x - tl.x) > 0 && (pos_mouse->x - tr.x) < 0
        && (pos_mouse->y - tl.y) > 0 && (pos_mouse->y - bl.y) < 0) {
            tool.pen ? draw_circle(pos_mouse, 4, canva, sfBlack) : 0;
            tool.eraser ? draw_circle(pos_mouse, 4, canva, sfWhite) : 0;
            sfTexture_updateFromImage(canva->texture, canva->image, 0, 0);
            sfSprite_setTexture(canva->sprite, canva->texture, sfTrue);
            return SUCCESS_RETURN;
    }
    return ERROR_RETURN;
}

void fill_pixels(canva_t *canva, sfVector2f *pos_mouse, selected_tool tool)
{
    check_if_in_canva(canva, pos_mouse, tool);
    return;
}
