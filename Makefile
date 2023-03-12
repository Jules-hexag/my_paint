##
## EPITECH PROJECT, 2022
## makefile
## File description:
## il fait le projet
##

SRC 	=	src/main.c \
			src/my_paint.c \
			src/window/frame_loop.c \
			src/window/create_window.c \
			src/events/event_management.c \
			src/menu_bar/create_menu_bar.c \
			src/menu_bar/create_rect_objects.c \
			src/events/mouse_moved_menu_events.c \
			src/events/mouse_clicked_menu_events.c \
			src/menu_bar/buttons/create_dropdowns.c \
			src/events/check_dropdowns_click_coords.c

TESTS_SRC	=	bonus/tests.c \

OBJ		= 	$(SRC:.c=.o)

T_OBJ	=	$(TESTS_SRC:.c=.o)

NAME 	=	my_paint

TESTS	=	unit_tests

LIB 	=	lib/libmy.a

LDFLAGS = 	-L./lib

LDLIBS	=	-lmy -lcriterion -lcsfml-graphics -lcsfml-window -lcsfml-system

CFLAGS	=	-I./include -O2 -Wall -Wextra

CFLAGS_DEBUG	=	-I./include -ggdb3 -fsanitize=address

CFLAGS_TESTS	=	-I./include/ -ggdb3 -O0 --coverage

all : $(NAME)

$(NAME) : $(LIB) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	@cp ./include/my_paint.h ./lib/my/

$(TESTS): CFLAGS=$(CFLAGS_TESTS)
$(TESTS): re $(T_OBJ)
	gcc -o $@ $(T_OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

$(LIB):
	make -C lib/my/

debug: CFLAGS=$(CFLAGS_DEBUG)
debug: re

clean:
	@$(RM) -vf $(OBJ)
	@$(RM) -vf $(T_OBJ)
	@$(RM) -vf $(TESTS)
	@$(RM) -vf generated_file

tests_run: $(TESTS)
	./$(TESTS) --always-succeed
	gcovr --exclude bonus/tests.c
	gcovr --branches --exclude bonus/tests.c

fclean: clean
	@$(RM) -vf $(NAME)
	make fclean -C lib/my/

re: fclean all

.PHONY: all clean fclean re tests_run unit_tests
