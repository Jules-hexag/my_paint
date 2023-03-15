/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** edit_flip_func
*/

#include "my_paint.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>

void flip(main_elements_t *main_elements)
{
    sfImage_flipVertically(main_elements->canva->image);
    sfTexture_updateFromImage(main_elements->canva->texture,
        main_elements->canva->image, 0, 0);
    sfSprite_setTexture(main_elements->canva->sprite,
        main_elements->canva->texture, sfTrue);
}
