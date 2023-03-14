/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** create_canva
*/

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Types.h>
#include "my_paint.h"

sfRectangleShape *create_canva_default(sfRenderWindow *window)
{
    sfRectangleShape *canva = sfRectangleShape_create();
    sfRectangleShape_setPosition(canva,
        sfRenderWindow_mapPixelToCoords(window,
        (sfVector2i) {410, 60}, NULL));
    sfRectangleShape_setSize(canva, (sfVector2f) {780, 780});
    sfRectangleShape_setFillColor(canva, sfWhite);
    return canva;
}
