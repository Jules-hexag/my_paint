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
int new_left(linked_dropdown **head, char *name, sfVector2f origin);
int new_right(linked_dropdown **head, char *name, sfVector2f origin);
void pop_first_elem(linked_dropdown **list);

#endif /* MY_LIB_ */
