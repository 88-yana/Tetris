#ifndef CELL_H
# define CELL_H

# include <stdlib.h>
# include "define.h"
# include "board.h"

t_tetromino	make_new_cell(void);
t_tetromino	make_rotated_cell(const t_tetromino cell);
void	move_cell(const int input, t_vars *vars);

#endif