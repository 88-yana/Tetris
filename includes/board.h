#ifndef BOARD_H
# define BOARD_H

# include <stdio.h>
# include	<ncurses.h>
# include "define.h"

void	print_current_board(t_vars *vars);
bool	is_placeable(t_vars *vars);

#endif