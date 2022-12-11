#ifndef DEFINE_H
# define DEFINE_H

# include	<stdbool.h>
# include	<time.h>

# define HEIGHT 20
# define WIDTH 15
# define RIGHT 1
# define LEFT -1
# define CELL_SIZE 4
# define NUM_OF_NEXT 3
# define COLOR_GRAY 8
# define FALL_TIME 500000000 //ns
# define DECREASE_TIME 10000000 //ns
# define TYPES sizeof(pieces) / sizeof(t_tetromino)

typedef struct s_tetromino {
	int	shape[CELL_SIZE][CELL_SIZE];
	int	width;
	int	col;
	int	row;
}	t_tetromino;

typedef struct s_vars {
	int				board[HEIGHT][WIDTH];
	int				score;
	int				order_of_next;
	bool			game_on;
	t_tetromino		cell;
	t_tetromino		next[NUM_OF_NEXT];
	time_t			fall_time;
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
	3, 0, 0},
	// # # .
	// . # #
	// . . .
	{{	{2, 2, 0, 0},
		{0, 2, 2, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	},
	3, 0, 0},
	// . # .
	// # # #
	// . . .
	{{	{0, 3, 0, 0},
		{3, 3, 3, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	},
	3, 0, 0},
	// . . #
	// # # #
	// . . .
	{{	{0, 0, 4, 0},
		{4, 4, 4, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	},
	3, 0, 0},
	// # . .
	// # # #
	// . . .
	{{	{5, 0, 0, 0},
		{5, 5, 5, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	},
	3, 0, 0},
	// # #
	// # #
	{{	{6, 6, 0, 0},
		{6, 6, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	},
	2, 0, 0},
	// . . . .
	// # # # #
	// . . . .
	// . . . .
	{{	{0, 0, 0, 0},
		{7, 7, 7, 7},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	},
	4, 0, 0}
};

#endif