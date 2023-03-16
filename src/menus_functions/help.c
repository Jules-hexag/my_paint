/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-jules.fradin
** File description:
** help
*/

#include <unistd.h>
#include "my_paint.h"

void help(main_elements_t *main_elements)
{
    (void) main_elements;
    write(1, "USAGE:\n\t./my_paint [OPTIONAL]\n\t[OPTIONAL]: optional \
path --> name and format to save your drawing\n\nFEATURES:\n\t\
file->new: create a new canva, try to draw, the previous one will be cleared.\
\n\tfile->save: save your drawing (.jpg by default), you can precise or not\
the file name and format to be used for saving the drawing.\n\t\
edit->pen: select the pen tool.\n\t\
edit->eraser: select the eraser tool.\n\t\
edit->flip & edit->invert: flip vertically or horizontally your drawing.\n\t\
help->about: who coded the program.\n\thelp->help: print help.\n\n\
NOTES:\n\t- Pen is selected by default at the launch of the program.\n\t\
- For now, only black is managed for the pen tool.\n\t\
- For now, only one size is managed, it can be changed in the source code \
(4 pixels radius by default).\n\tCanvas are standardized to 780^2px.", 790);
}

void about(main_elements_t *main_elements)
{
    (void) main_elements;
    write(1, "matteo.le-pluart@epitech.eu\njules.fradin@epitech.eu\n", 53);
}
