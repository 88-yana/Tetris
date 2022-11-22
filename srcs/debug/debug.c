#include "../../includes/tetris.h"

void	print_shape(t_tetromino cell)
{
	for (int i = 0; i < cell.width; i++)
	{
		for (int j = 0; j < cell.width; j++)
			printf("%c ", (cell.shape[i][j]) ? '#' : '.');
		printf("\n");
	}
}

void	print_cell(t_vars *vars)
{
	print_shape(vars->cell);
	printf("%d\n", vars->cell.width);
	printf("%d\n", vars->cell.col);
	printf("%d\n", vars->cell.row);
}

void	printf_afew(t_vars *vars)
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
