/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-jules.fradin
** File description:
** linked_ope
*/

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include "my_paint.h"

int count_elem(linked_dropdown *head)
{
    int i = 1;
    if (head == NULL) return 0;
    if (head->next == NULL) return 1;
    while (head->next != NULL) {
        i++;
        head = head->next;
    }
    return i;
}

int new_right_popup(sfRenderWindow *window, linked_popup **head, char *name,
    sfVector2f origin)
{
    linked_popup *new_node = malloc(sizeof(linked_popup));
    if (!new_node) return ERROR_RETURN;
    *new_node = (linked_popup) {
        .size = (sfVector2f) {50, 20},
        .origin = origin,
        .name = name,
        .button_state = NONE,
        .next = *head,
    };
    new_node->sprite = create_menu_button(window, new_node),
    new_node->text = create_text((sfVector2f) {origin.x + 2, origin.y + 4},
        name);
    new_node->next = NULL;
    linked_popup *tmp = *head;
    while (*head != NULL)
        head = &(*head)->next;
    *head = new_node;
    head = &tmp;
    return 0;
}

static sfText *create_text(sfVector2f pos_text, char *text_str)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/ELNATH.ttf");
    sfText_setString(text, text_str);
    sfText_setCharacterSize(text, 11);
    sfText_setColor(text, sfWhite);
    sfText_setFont(text, font);
    sfText_setPosition(text, pos_text);
    return text;
}

/*
                                    --> --> --> --> -->
    linked list : head--prev-------------------------------------next--NULL
*/
int new_right(sfRenderWindow *window, linked_dropdown **head, char *name,
    sfVector2f origin)
{
    linked_dropdown *new_node = malloc(sizeof(linked_dropdown));
    if (!new_node) return ERROR_RETURN;
    *new_node = (linked_dropdown) {
        .size = (sfVector2f) {50, 20},
        .origin = origin,
        .name = name,
        .button_state = NONE,
        .next = *head,
    };
    new_node->sprite = create_menu_button(window, new_node),
    new_node->text = create_text((sfVector2f) {origin.x + 2, origin.y + 4},
        name);
    new_node->next = NULL;
    linked_dropdown *tmp = *head;
    while (*head != NULL)
        head = &(*head)->next;
    *head = new_node;
    head = &tmp;
    return 0;
}

void pop_first_elem(linked_dropdown **list)
{
    linked_dropdown *pop = *list;
    (*list) = (*list)->next;
    free(pop);
}
