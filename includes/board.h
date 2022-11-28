#ifndef BOARD_H
# define BOARD_H

# include <stdio.h>
# include <ncurses.h>
# include "define.h"
# include "cell.h"

void	copy_cell_to_board(t_tetromino cell, int board[][WIDTH]);
void	print_current_board(t_vars *vars);
bool	is_placeable(t_vars *vars, t_tetromino temp);
void	update_board(t_vars *vars);

#endif