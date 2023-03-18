#include "bool.h"

bool	is_fall(t_vars *vars)
{
	static struct timespec	start_time;
	struct timespec			now;

	clock_gettime(CLOCK_MONOTONIC, &now);
	time_t	now_nsec = now.tv_sec * 1000000000 + now.tv_nsec;
	time_t	start_nsec = start_time.tv_sec * 1000000000 + start_time.tv_nsec;
	if (now_nsec - start_nsec > vars->fall_time)
	{
		clock_gettime(CLOCK_MONOTONIC, &(start_time));
		return (true);
	}
	return (false);
}
//vars->board vars->cell
bool	is_placeable(const t_vars *vars, const t_tetromino cell)
{
	for (int i = 0; i < cell.width; i++)
	{
		for (int j = 0; j < cell.width; j++)
		{
			const bool	is_out_of_bounds = cell.col + j < 0 || WIDTH <= cell.col + j || HEIGHT <= cell.row + i;
			if (is_out_of_bounds && cell.shape[i][j])
				return (false);
			const bool	is_placed_on_board = vars->board[cell.row + i][cell.col + j];
			if (is_placed_on_board && cell.shape[i][j])
				return (false);
		}
	}
	return (true);
}
