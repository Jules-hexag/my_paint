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
#include <stdio.h>

static int check_if_in_canva(canva_t *canva, sfVector2f *pos_mouse,
    selected_tool tool)
{

    sfVector2u canva_len = sfTexture_getSize(canva->texture);
    sfVector2f tl = sfSprite_getPosition(canva->sprite);
    sfVector2f tr = {tl.x + canva_len.x, tl.y};
    sfVector2f bl = {tl.x, tl.y + canva_len.y};
    if ((pos_mouse->x - tl.x) > 0 && (pos_mouse->x - tr.x) < 0
        && (pos_mouse->y - tl.y) > 0 && (pos_mouse->y - bl.y) < 0) {
            tool.pen ? sfImage_setPixel(canva->image, pos_mouse->x - tl.x,
                pos_mouse->y - tl.y, sfBlack) : 0;
            tool.eraser ? sfImage_setPixel(canva->image, pos_mouse->x - tl.x,
                pos_mouse->y - tl.y, sfWhite) : 0;
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
