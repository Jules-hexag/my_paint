/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** file_new_func
*/

#include "my_paint.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>

void new(main_elements_t *main_elements)
{
    sfImage *new_image = sfImage_createFromColor(780, 780, sfWhite);
    sfImage_destroy(main_elements->canva->image);
    main_elements->canva->image = new_image;
}
