#ifndef BOARD_H
# define BOARD_H

# include <ncurses.h>
# include "define.h"
# include "cell.h"
# include "bool.h"

void	copy_cell_to_board(const t_tetromino cell, int board[][WIDTH]);
void	print_current_board(t_vars *vars);
void	print_result(const t_vars *vars);
void	update_board(t_vars *vars);

#endif