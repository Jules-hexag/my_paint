/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** my_paint
*/

#ifndef MY_PAINT_H_
    #define MY_PAINT_H_
    #define STANDARD_BUTTON_SIZE {50, 20}

    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics.h>
    #include <stdbool.h>

enum {
    SUCCESS_RETURN = 0,
    ERROR_RETURN = 84,
};

typedef struct {
    bool file_menu;
    bool edit_menu;
    bool help_menu;
} menu_states;

enum button_state_s {
    NONE = 0,
    HOVER,
    PRESSED,
    RELEASED,
};
typedef struct linked_dropdown_s {
    sfRectangleShape *sprite;
    sfText *text;
    sfVector2f size;
    sfVector2f origin;
    char *name;
    enum button_state_s button_state;
    struct linked_dropdown_s *next;
} linked_dropdown;

typedef struct {
    linked_dropdown *file_dropdown;
    linked_dropdown *edit_dropdown;
    linked_dropdown *help_dropdown;
} all_dropdowns;

/*  SOURCE  */
int my_paint(char **env);
sfRenderWindow *create_window(char **env);
void event_management(sfRenderWindow *window, menu_states *menu,
    all_dropdowns *dropdowns);
void frame_loop(sfRenderWindow *window, sfRectangleShape *menu_bar,
    menu_states *menu, all_dropdowns *dropdowns);

/*  DRAW ELEMENTS   */
void draw_hidden_dropdowns_buttons(menu_states *menu, sfRenderWindow *window,
    all_dropdowns *dropdowns);
void draw_permanent_dropdowns_elem(sfRenderWindow *window,
    sfRectangleShape *menu_bar, all_dropdowns *dropdowns);

/*    MENU BAR    */
sfRectangleShape *create_menu_bar(sfRenderWindow *window, menu_states *menu,
    all_dropdowns *dropdowns);
sfRectangleShape *create_bar_rectangle(sfRenderWindow *window);
sfRectangleShape *create_menu_button(sfRenderWindow *window,
    linked_dropdown *button);
void create_dropdowns(sfRenderWindow *window, menu_states *menu,
    all_dropdowns *dropdowns);

/*      MOUSE EVENT     */
void mouse_moved_menu_events(sfRenderWindow *window, menu_states *menu,
    all_dropdowns *dropdowns);
void mouse_clicked_menu_events(sfRenderWindow *window, menu_states *menu,
    all_dropdowns *dropdowns);
void check_dropdowns_click_coords(sfVector2f pos_mouse, menu_states *menu,
    all_dropdowns *dropdowns);

#endif /* !MY_PAINT_H_ */
