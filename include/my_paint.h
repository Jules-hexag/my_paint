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

enum button_state_e {
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
    enum button_state_e button_state;
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

typedef struct {
    bool pen;
    bool eraser;
    bool doing;
} selected_tool;

typedef struct {
    sfRenderWindow *window;
    menu_states menu;
    canva_t *canva;
    all_dropdowns dropdowns;
    selected_tool tool;
    char *filename;
} main_elements_t;

/*  SOURCE  */
int my_paint(int const argc, char const *const *env, char *const *const argv);
sfRenderWindow *init_window(char const *const *env);
void event_management(main_elements_t *important_elements);
void frame_loop(main_elements_t *important_elements);

/*  DRAW ELEMENTS ON WINDOW  */
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

/*      CANVA & DRAWING      */
canva_t *create_canva_default(void);
void draw(sfRenderWindow *window, canva_t *canva, selected_tool tool);
void fill_pixels(canva_t *canva, sfVector2f *pos_mouse);

/*      DROPDOWNS FUNCTIONS     */
int check_if_in_file_dropdown(sfVector2f pos_mouse,
    main_elements_t *main_elements);
void new(sfImage *image, char *filename);

int check_if_in_edit_dropdown(sfVector2f pos_mouse, all_dropdowns *dropdowns,
    menu_states menu);

int check_if_in_help_dropdown(sfVector2f pos_mouse, all_dropdowns *dropdowns,
    menu_states menu);

/*      MOUSE EVENT     */
void mouse_moved_menu_events(sfRenderWindow *window, menu_states *menu,
    all_dropdowns *dropdowns);
void mouse_clicked_menu_events(main_elements_t *main_elements);
void check_dropdowns_click_coords(sfVector2f pos_mouse, menu_states *menu,
    all_dropdowns *dropdowns);

#endif /* !MY_PAINT_H_ */
