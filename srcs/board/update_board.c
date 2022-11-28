#include "../../includes/board.h"

void	calc_score(t_vars *vars, int deleted_rows)
{
	vars->score += 100 * deleted_rows;
}

void	calc_time(t_vars *vars, int deleted_rows)
{
	static time_t	decrease_time = 10000000;

	for (int i = 0; i < deleted_rows; i++)
		vars->fall_time -= decrease_time;
	decrease_time += 5000000 * deleted_rows;
}

int	delete_rows(t_vars *vars)
{
	int	cnt_rows;
	int	sum_col;

	cnt_rows = 0;
	for (int i = 0; i < HEIGHT; i++)
	{
		sum_col = 0;
		for (int j = 0; j < WIDTH; j++)
			if (vars->board[i][j])
				sum_col++;
		if (sum_col == WIDTH)
		{
			// move_down_rows(i);
			cnt_rows++;
		}
	}
	return (cnt_rows);
}

void	update_board(t_vars *vars)
{
	int	deleted_rows;

	copy_cell_to_board(vars->cell, vars->board);
	deleted_rows = delete_rows(vars);
	calc_score(vars, deleted_rows);
	calc_time(vars, deleted_rows);
	vars->cell = make_new_cell();
}
