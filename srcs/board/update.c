#include "../../includes/board.h"

static void	calc_score(t_vars *vars, int deleted_rows)
{
	vars->score += 100 * deleted_rows;
}

static void	calc_time(t_vars *vars, int deleted_rows)
{
	static time_t	decrease_time = 10000000;

	for (int i = 0; i < deleted_rows; i++)
		vars->fall_time -= decrease_time;
	decrease_time += 5000000 * deleted_rows;
}

static void	move_down_rows(t_vars *vars, int del_row)
{
	for (int row = del_row; row >= 1; row--) //下から上へ
		for (int col = 0; col < WIDTH; col++)
			vars->board[row][col] = vars->board[row - 1][col]; //ひとつ上の行を下の行に
	for (int col = 0; col < WIDTH; col++)
		vars->board[0][col] = 0; //一番上は0初期化
}

static int	delete_rows(t_vars *vars)
{
	int	deleted_rows = 0;
	for (int row = 0; row < HEIGHT; row++)
	{
		int	sum_col = 0;
		for (int col = 0; col < WIDTH; col++)
			if (vars->board[row][col])
				sum_col++;
		if (sum_col == WIDTH)
		{
			move_down_rows(vars, row);
			deleted_rows++;
		}
	}
	return (deleted_rows);
}

void	update_board(t_vars *vars)
{
	copy_cell_to_board(vars->cell, vars->board);

	int	deleted_rows = delete_rows(vars);
	calc_score(vars, deleted_rows);
	calc_time(vars, deleted_rows);

	vars->cell = make_new_cell();
	if (!is_placeable(vars, vars->cell))
		vars->game_on = false;
}
