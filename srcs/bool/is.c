#include "../../includes/bool.h"

bool	is_fall(t_vars *vars)
{
	struct timespec	now;

	clock_gettime(CLOCK_MONOTONIC, &now);
	time_t	now_nsec = now.tv_sec * 1000000000 + now.tv_nsec;
	time_t	start_nsec = vars->start_time.tv_sec * 1000000000 + vars->start_time.tv_nsec;
	if (now_nsec - start_nsec > vars->fall_time)
	{
		clock_gettime(CLOCK_MONOTONIC, &(vars->start_time));
		return (true);
	}
	return (false);
}

bool	is_placeable(const t_vars *vars, const t_tetromino temp)
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
