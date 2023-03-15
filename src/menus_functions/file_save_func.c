/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** file.new_func
*/

#include "my_paint.h"
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Types.h>
#include <stdio.h>

void save(main_elements_t *main_elements)
{
    sfImage_saveToFile(main_elements->canva->image, main_elements->filename);
}
