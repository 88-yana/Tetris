#ifndef BOARD_H
# define BOARD_H

# include <stdio.h>
# include "define.h"

# define clear_screen printf("\033[2J")

void	print_current_board(t_vars *vars);
#endif