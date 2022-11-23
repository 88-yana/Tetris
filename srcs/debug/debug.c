#include "../../includes/tetris.h"

void	print_shape(t_tetromino cell)
{
	for (int i = 0; i < cell.width; i++)
	{
		for (int j = 0; j < cell.width; j++)
			printw("%c ", (cell.shape[i][j]) ? '#' : '.');
		printw("\n");
	}
}

void	print_cell(t_vars *vars)
{
	print_shape(vars->cell);
	printw("%d\n", vars->cell.width);
	printw("%d\n", vars->cell.col);
	printw("%d\n", vars->cell.row);
}

void	printw_afew(t_vars *vars)
{
	for (int i = 0; i < 3; i++)
	{
		initscr(); 
		vars->cell = make_new_cell();
		endwin();
		print_current_board(vars);
		sleep(2);
	}
}
