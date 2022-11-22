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
	print_shape(vars->current_cell);
	printf("%d\n", vars->current_cell.width);
	printf("%d\n", vars->current_cell.col);
	printf("%d\n", vars->current_cell.row);
}
