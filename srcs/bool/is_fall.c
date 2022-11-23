#include "../../includes/bool.h"

bool	is_fall(t_vars *vars)
{
	struct timespec	now;
	time_t			now_nsec;
	time_t			start_nsec;

	clock_gettime(CLOCK_MONOTONIC, &now);
	now_nsec = now.tv_sec * 1000000000 + now.tv_nsec;
	start_nsec = vars->start_time.tv_sec * 1000000000 + vars->start_time.tv_nsec;
	if (now_nsec - start_nsec > vars->fall_time)
	{
		clock_gettime(CLOCK_MONOTONIC, &(vars->start_time));
		return (true);
	}
	return (false);
}