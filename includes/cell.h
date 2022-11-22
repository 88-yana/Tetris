#ifndef CELL_H
# define CELL_H

# include <stdlib.h>
# include <ncurses.h>
# include "define.h"
# include	"board.h"

t_tetromino	copy_cell(t_tetromino cell);
t_tetromino	make_new_cell(void);
void		move_cell(int input, t_vars *vars);
#endif