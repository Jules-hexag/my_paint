/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** fill_pixels
*/

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <math.h>
#include <stdio.h>
#include "my_paint.h"

static void draw_square(sfVector2f pos_mouse, int r,
    main_elements_t *main_elms)
{
    sfVector2f tl = sfSprite_getPosition(main_elms->canva->sprite);
    sfVector2u img_size_u = sfImage_getSize(main_elms->canva->image);
    sfVector2i img_size = {(int) img_size_u.x, (int) img_size_u.y};
    int x = pos_mouse.x - tl.x;
    int y = pos_mouse.y - tl.y;
    int size = (r * 2);
    for (int y_pix = 0, x_pix = 0; y_pix * x_pix < size * size; (x_pix < size)
        ? ++x_pix :
        (x_pix = 0, y_pix++)) {
            int px = (x - r) + x_pix;
            int py = (y - r) + y_pix;
            if (px < 0 || px > img_size.x - 1 || py < 0 || py > img_size.y - 1)
                continue;
            sfImage_setPixel(main_elms->canva->image, (x - r) + x_pix,
                (y - r) + y_pix, sfWhite);
    }
}

static void draw_circle(sfVector2f pos_mouse, int r,
    main_elements_t *main_elms, sfColor color)
{
    if (main_elms->tool.eraser && main_elms->eraser_state == SQUARE) {
        draw_square(pos_mouse, r, main_elms);
        return;
    }
    const double PI = 3.1415926535;
    double angle = 0;
    int x1, y1 = 0;
    sfVector2f tl = sfSprite_getPosition(main_elms->canva->sprite);
    int x = pos_mouse.x - tl.x;
    int y = pos_mouse.y - tl.y;
    sfVector2u img_size_u = sfImage_getSize(main_elms->canva->image);
    sfVector2i img_size = {(int) img_size_u.x, (int) img_size_u.y};
    for (angle = 0; r > 0; (angle < 360) ? angle += 0.1 : (r--, angle = 0)) {
        x1 = r * cos(angle * PI / 180) + x;
        y1 = r * sin(angle * PI / 180) + y;
        if (x1 < 0 || x1 > img_size.x - 1 || y1 < 0 || y1 > img_size.y - 1)
            continue;
        sfImage_setPixel(main_elms->canva->image, x1, y1, color);
    }
}

static int check_if_in_canva(main_elements_t *main_elms, sfVector2f pos_mouse)
{
    sfVector2u canva_len = sfTexture_getSize(main_elms->canva->texture);
    sfVector2f tl = sfSprite_getPosition(main_elms->canva->sprite);
    sfVector2f tr = {tl.x + canva_len.x, tl.y};
    sfVector2f bl = {tl.x, tl.y + canva_len.y};
    if ((pos_mouse.x - tl.x) > 0 && (pos_mouse.x - tr.x) < 0
        && (pos_mouse.y - tl.y) > 0 && (pos_mouse.y - bl.y) < 0) {
            main_elms->tool.pen ? draw_circle(pos_mouse, main_elms->pen_size,
                main_elms, sfBlack) : 0;
            main_elms->tool.eraser ? draw_circle(pos_mouse, main_elms->pen_size,
                main_elms, sfWhite) : 0;
            sfTexture_updateFromImage(main_elms->canva->texture,
                main_elms->canva->image, 0, 0);
            sfSprite_setTexture(main_elms->canva->sprite,
                main_elms->canva->texture, sfTrue);
            return SUCCESS_RETURN;
    }
    return ERROR_RETURN;
}

void fill_pixels(main_elements_t *main_elements, sfVector2f pos_mouse)
{
    check_if_in_canva(main_elements, pos_mouse);
    return;
}
