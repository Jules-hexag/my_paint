/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** my_paint
*/

#ifndef MY_PAINT_H_
    #define MY_PAINT_H_
    #define STANDARD_BUTTON_SIZE {50, 20}
    #include <SFML/Graphics.h>

enum {
    SUCCESS_RETURN = 0,
    ERROR_RETURN = 84,
};

typedef struct {
    int file_menu;
    int help_menu;
} menu_states;

enum button_state_s {
    NONE = 0,
    HOVER,
    PRESSED,
    RELEASED,
};
typedef struct linked_dropdown_s {
    sfVector2f size;
    sfVector2f origin;
    char *name;
    enum button_state_s button_state;
    struct linked_dropdown_s *next;
} linked_dropdown;

typedef struct {
    linked_dropdown *file_dropdown;
    linked_dropdown *help_dropdown;
} all_dropdowns;

/*  SOURCE  */
int my_paint(char **env);
sfRenderWindow *create_window(char **env);
void event_management(sfRenderWindow *window);
void frame_loop(sfRenderWindow *window, all_dropdowns *dropdowns);

/*    MENU BAR    */
int create_menu_bar(sfRenderWindow *window, menu_states *menu);
void create_bar_rectangle(sfRenderWindow *window);
void create_dropdowns(sfRenderWindow *window, menu_states *menu);

#endif /* !MY_PAINT_H_ */
