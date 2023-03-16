/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** my_paint
*/

#ifndef MY_PAINT_H_
    #define MY_PAINT_H_

    #include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
    #include <stdbool.h>

enum {
    SUCCESS_RETURN = 0,
    ERROR_RETURN = 84,
};


typedef struct {
    bool file_menu;
    bool edit_menu;
    bool help_menu;
    bool pen_menu;
    bool eraser_menu;
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

typedef struct linked_popup_s {
    sfRectangleShape *sprite;
    sfText *text;
    sfVector2f size;
    sfVector2f origin;
    char *name;
    enum button_state_e button_state;
    struct linked_popup_s *next;
} linked_popup;

typedef struct all_popups_s {
    linked_popup *pen_size;
    linked_popup *eraser_shape;
} all_popups;

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
    all_popups popups;
    selected_tool tool;
    char *filename;
    int pen_size;
} main_elements_t;

/*  SOURCE  */
int my_paint(int const argc, char const *const *env, char *const *const argv);
sfRenderWindow *init_window(char const *const *env);
void event_management(main_elements_t *important_elements);
void frame_loop(main_elements_t *important_elements);
void destroy(main_elements_t *main_elms);

/*  DRAW ELEMENTS ON WINDOW  */
void draw_dropdowns_elem(main_elements_t *main_elements);
void do_hover(sfVector2f pos_mouse, main_elements_t *main_elms);
void pen_selection(linked_popup *pen, sfVector2f pos_mouse);
void help_button(linked_dropdown *help_dropdown, sfVector2f pos_mouse);
void edit_button(linked_dropdown *edit_dropdown, sfVector2f pos_mouse);
void file_button(linked_dropdown *file_dropdown, sfVector2f pos_mouse);

/*    MENU BAR    */
sfRectangleShape *create_menu_bar(sfRenderWindow *window,
    all_dropdowns *dropdowns);
sfRectangleShape *create_bar_rectangle(sfRenderWindow *window);
sfRectangleShape *create_menu_button(sfRenderWindow *window,
    linked_dropdown *button);
sfRectangleShape *create_menu_button_popup(sfRenderWindow *window,
    linked_popup *button);
void create_dropdowns(sfRenderWindow *window, all_dropdowns *dropdowns);
void create_popups(sfRenderWindow *window, all_popups *popups);

/*      CANVA & DRAWING      */
canva_t *create_canva_default(void);
void draw(sfRenderWindow *window, canva_t *canva, selected_tool tool);
void fill_pixels(canva_t *canva, sfVector2f *pos_mouse, selected_tool tool);

/*      DROPDOWNS FUNCTIONS     */
void check_if_in_file_dropdown(sfVector2f pos_mouse,
    main_elements_t *main_elms);
void check_if_in_edit_dropdown(sfVector2f pos_mouse,
    main_elements_t *main_elms);
void check_if_in_help_dropdown(sfVector2f pos_mouse,
    main_elements_t *main_elms);

void new(main_elements_t *main_elements);
void save(main_elements_t *main_elements);
void pen(main_elements_t *main_elements);
void eraser(main_elements_t *main_elements);
void flip(main_elements_t *main_elements);
void invert(main_elements_t *main_elements);
void help(main_elements_t *main_elements);
void about(main_elements_t *main_elements);

/*      MOUSE EVENT     */
void mouse_moved_menu_events(main_elements_t *main_elements);
void mouse_clicked_menu_events(main_elements_t *main_elements);
void check_dropdowns_click_coords(sfVector2f pos_mouse, menu_states *menu,
    all_dropdowns *dropdowns, main_elements_t *main_elms);

#endif /* !MY_PAINT_H_ */
