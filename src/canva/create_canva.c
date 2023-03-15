/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** create_canva
*/

#include <stdlib.h>
#include "my_paint.h"

canva_t *create_canva_default(void)
{
    canva_t *canva = malloc(sizeof(canva_t));
    canva->image = sfImage_createFromColor(780, 780, sfWhite);
    canva->texture = sfTexture_createFromImage(canva->image,
        &(sfIntRect) {0, 0, 780, 780});
    canva->sprite = sfSprite_create();
    sfSprite_setTexture(canva->sprite, canva->texture, sfTrue);
    sfSprite_setPosition(canva->sprite, (sfVector2f) {480, 80});
    return canva;
}
