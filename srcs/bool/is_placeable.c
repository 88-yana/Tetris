#include "../../includes/board.h"

bool	is_placeable(t_vars *vars, t_tetromino temp)
{
	for (int i = 0; i < temp.width; i++)
	{
		for (int j = 0; j < temp.width; j++)
		{
			const bool	is_out_of_bounds = temp.col + j < 0 || WIDTH <= temp.col + j || HEIGHT <= temp.row + i;
			if (is_out_of_bounds && temp.shape[i][j])
				return (false);
			const bool	is_placed_on_board = vars->board[temp.row + i][temp.col + j];
			if (is_placed_on_board && temp.shape[i][j])
				return (false);
		}
	}
	return (true);
}
