/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-jules.fradin
** File description:
** linked_ope
*/

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

int new_left(sfRenderWindow *window, linked_dropdown **head, char *name, sfVector2f origin)
{
    linked_dropdown *new_node = malloc(sizeof(linked_dropdown));
    if (!new_node) return ERROR_RETURN;
    *new_node = (linked_dropdown) {
        .size = (sfVector2f) STANDARD_BUTTON_SIZE,
        .origin = origin,
        .name = name,
        .button_state = NONE,
        .next = *head,
    };
    new_node->sprite = create_menu_button(window, new_node),
    *head = new_node;
    return 0;
}

/*
                                    --> --> --> --> -->
    linked list : head--prev-------------------------------------next--NULL
*/
int new_right(sfRenderWindow *window, linked_dropdown **head, char *name, sfVector2f origin)
{
    linked_dropdown *new_node = malloc(sizeof(linked_dropdown));
    if (!new_node) return ERROR_RETURN;
    *new_node = (linked_dropdown) {
        .size = (sfVector2f) STANDARD_BUTTON_SIZE,
        .origin = origin,
        .name = name,
        .button_state = NONE,
        .next = *head,
    };
    new_node->sprite = create_menu_button(window, new_node),
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
