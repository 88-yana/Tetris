#ifndef CELL_H
# define CELL_H

# include <stdlib.h>
# include <ncurses.h>
# include "define.h"
# include "board.h"

t_tetromino	make_new_cell(void);
t_tetromino	make_rotated_cell(t_tetromino cell);
void		move_cell(int input, t_vars *vars);

#endif