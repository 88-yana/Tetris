#ifndef DEFINE_H
# define DEFINE_H

# include	<stdbool.h>
# include	<time.h>
# include	<sys/time.h>

# define HEIGHT 20
# define WIDTH 15
# define RIGHT 1
# define LEFT -1
# define TYPES sizeof(pieces) / sizeof (t_tetromino)

typedef struct s_tetromino {
	int	**shape;
	int	width;
	int	col;
	int	row;
}	t_tetromino;

typedef struct s_vars {
	int			board[HEIGHT][WIDTH];
	int			decrease_time;
	int			score;
	bool		game_on;
	suseconds_t	timer;
	t_tetromino	current;
}	t_vars;

const t_tetromino pieces[] = {
	// . # #
	// # # .
	// . . .
	{(int *[]){(int[]){0, 1, 1},
				(int[]){1, 1, 0},
				(int[]){0, 0, 0}},
	3},
	// # # .
	// . # #
	// . . .
	{(int *[]){(int[]){2, 2, 0},
				(int[]){0, 2, 2},
				(int[]){0, 0, 0}},
	3},
	// . # .
	// # # #
	// . . .
	{(int *[]){(int[]){0, 3, 0},
				(int[]){3, 3, 3},
				(int[]){0, 0, 0}},
	3},
	// . . #
	// # # #
	// . . .
	{(int *[]){(int[]){0, 0, 4},
				(int[]){4, 4, 4},
				(int[]){0, 0, 0}},
	3},
	// # . .
	// # # #
	// . . .
	{(int *[]){(int[]){5, 0, 0},
				(int[]){5, 5, 5},
				(int[]){0, 0, 0}},
	3},
	// # #
	// # #
	{(int *[]){(int[]){6, 6},
				(int[]){6, 6}},
	2},
	// . . . .
	// # # # #
	// . . . .
	// . . . .
	{(int *[]){(int[]){0, 0, 0, 0},
				(int[]){7, 7, 7, 7},
				(int[]){0, 0, 0, 0},
				(int[]){0, 0, 0, 0}},
	4}
};

#endif