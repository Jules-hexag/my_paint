/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** my_paint
*/

#ifndef MY_PAINT_H_
    #define MY_PAINT_H_

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
    sfRectangleShape *menu_bar;
} all_dropdowns;

typedef struct {
    sfImage *image;
    sfTexture *texture;
    sfSprite *sprite;
} canva_t;

/*  SOURCE  */
int my_paint(char **env, char const *const *argv);
sfRenderWindow *create_window(char **env);
void event_management(sfRenderWindow *window, menu_states *menu,
    all_dropdowns *dropdowns);
void menus_loop(sfRenderWindow *window, menu_states *menu,
    all_dropdowns *dropdowns);
void canva_loop(sfRenderWindow *window, canva_t *canva);

/*  DRAW ELEMENTS   */
void draw_dropdowns_elem(sfRenderWindow *window, all_dropdowns *dropdowns,
    menu_states *menu);

/*    MENU BAR    */
sfRectangleShape *create_menu_bar(sfRenderWindow *window, menu_states *menu,
    all_dropdowns *dropdowns);
sfRectangleShape *create_bar_rectangle(sfRenderWindow *window);
sfRectangleShape *create_menu_button(sfRenderWindow *window,
    linked_dropdown *button);
void create_dropdowns(sfRenderWindow *window, menu_states *menu,
    all_dropdowns *dropdowns);

/*      CANVA       */
canva_t *create_canva_default(void);

/*      MOUSE EVENT     */
void mouse_moved_menu_events(sfRenderWindow *window, menu_states *menu,
    all_dropdowns *dropdowns);
void mouse_clicked_menu_events(sfRenderWindow *window, menu_states *menu,
    all_dropdowns *dropdowns);
void check_dropdowns_click_coords(sfVector2f pos_mouse, menu_states *menu,
    all_dropdowns *dropdowns);

#endif /* !MY_PAINT_H_ */
