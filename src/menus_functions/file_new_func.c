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

void new(sfImage *image, char *filename)
{
    sfImage_saveToFile(image, filename);
}
