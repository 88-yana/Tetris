#ifndef DEFINE_H
# define DEFINE_H

# include	<stdbool.h>
# include	<time.h>

# define HEIGHT 20
# define WIDTH 15
# define RIGHT 1
# define LEFT -1
# define TYPES sizeof(pieces) / sizeof(t_tetromino)

typedef struct s_tetromino {
	int	shape[4][4];
	int	width;
	int	col;
	int	row;
}	t_tetromino;

typedef struct s_vars {
	int				board[HEIGHT][WIDTH];
	int				score;
	bool			game_on;
	t_tetromino		cell;
	time_t			fall_time;
	struct timespec	start_time;
}	t_vars;

static const	t_tetromino pieces[] = {
	// . # #
	// # # .
	// . . .
	{{	{0, 1, 1, 0},
		{1, 1, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	},
	3},
	// # # .
	// . # #
	// . . .
	{{	{2, 2, 0, 0},
		{0, 2, 2, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	},
	3},
	// . # .
	// # # #
	// . . .
	{{	{0, 3, 0, 0},
		{3, 3, 3, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	},
	3},
	// . . #
	// # # #
	// . . .
	{{	{0, 0, 4, 0},
		{4, 4, 4, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	},
	3},
	// # . .
	// # # #
	// . . .
	{{	{5, 0, 0, 0},
		{5, 5, 5, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	},
	3},
	// # #
	// # #
	{{	{6, 6, 0, 0},
		{6, 6, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	},
	2},
	// . . . .
	// # # # #
	// . . . .
	// . . . .
	{{	{0, 0, 0, 0},
		{7, 7, 7, 7},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	},
	4}
};

#endif