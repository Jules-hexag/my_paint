/*
** EPITECH PROJECT, 2022
** my_lib header
** File description:
** all prototypes
*/

#ifndef MY_LIB_
    #define MY_LIB_
    #include "my_paint.h"

int my_strncmp(char const *s1, char const *s2, int n);
int count_elem(linked_dropdown *head);
int new_left(sfRenderWindow *window, linked_dropdown **head, char *name,
    sfVector2f origin);
int new_right(sfRenderWindow *window, linked_dropdown **head, char *name,
    sfVector2f origin);
int new_right_popup(sfRenderWindow *window, linked_popup **head, char *name,
    sfVector2f origin);
int count_elem_popup(linked_popup *head);

#endif /* MY_LIB_ */
