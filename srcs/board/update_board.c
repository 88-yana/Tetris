#include "../../includes/board.h"

void	calc_score_and_time(t_vars *vars, int cnt_rows)
{
	static time_t	decrease_time = 100000000;

	vars->score += 100 * cnt_rows;
	for (int i = 0; i < cnt_rows; i++)
		vars->fall_time -= decrease_time;
	decrease_time += 50000000 * cnt_rows;
}

int	delete_rows(t_vars *vars)
{
	int	cnt_rows;
	int	sum_col;

	cnt_rows = 0;
	for (int n = 0; n < HEIGHT; n++)
	{
		sum_col = 0;
		for (int m = 0; m < WIDTH; m++)
			if (vars->board[n][m])
				sum_col++;
		if (sum_col == WIDTH)
		{
			// move_down_rows(n);
			cnt_rows++;
		}
	}
	return (cnt_rows);
}

void	update_board(t_vars *vars)
{
	int	deleted_rows;

	copy_cell_to_board();
	calc_score(vars, delete_rows(vars));
	vars->cell = make_new_cell();
}
