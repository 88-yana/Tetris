#ifndef DEFINE_H
# define DEFINE_H

# include	<stdbool.h>
# include	<time.h>

# define HEIGHT 20
# define WIDTH 15
# define RIGHT 1
# define LEFT -1
# define TYPES sizeof(pieces) / sizeof(t_tetromino)
// typedef struct s_tetromino {
// 	int	**shape;
// 	int	width;
// 	int	col;
// 	int	row;
// }	t_tetromino;

typedef struct s_tetromino {
	int	shape[4][4];
	int	width;
	int	col;
	int	row;
}	t_tetromino;

typedef struct s_vars {
	int				board[HEIGHT][WIDTH];
	int				score;
	int				reduce_time;
	int				fall_time;
	bool			game_on;
	t_tetromino		cell;
	struct timespec	start_time;
}	t_vars;

// static const	t_tetromino pieces[] = {
// 	// . # #
// 	// # # .
// 	// . . .
// 	{(int *[]){(int[]){0, 1, 1},
// 				(int[]){1, 1, 0},
// 				(int[]){0, 0, 0}},
// 	3},
// 	// # # .
// 	// . # #
// 	// . . .
// 	{(int *[]){(int[]){2, 2, 0},
// 				(int[]){0, 2, 2},
// 				(int[]){0, 0, 0}},
// 	3},
// 	// . # .
// 	// # # #
// 	// . . .
// 	{(int *[]){(int[]){0, 3, 0},
// 				(int[]){3, 3, 3},
// 				(int[]){0, 0, 0}},
// 	3},
// 	// . . #
// 	// # # #
// 	// . . .
// 	{(int *[]){(int[]){0, 0, 4},
// 				(int[]){4, 4, 4},
// 				(int[]){0, 0, 0}},
// 	3},
// 	// # . .
// 	// # # #
// 	// . . .
// 	{(int *[]){(int[]){5, 0, 0},
// 				(int[]){5, 5, 5},
// 				(int[]){0, 0, 0}},
// 	3},
// 	// # #
// 	// # #
// 	{(int *[]){(int[]){6, 6},
// 				(int[]){6, 6}},
// 	2},
// 	// . . . .
// 	// # # # #
// 	// . . . .
// 	// . . . .
// 	{(int *[]){(int[]){0, 0, 0, 0},
// 				(int[]){7, 7, 7, 7},
// 				(int[]){0, 0, 0, 0},
// 				(int[]){0, 0, 0, 0}},
// 	4}
// };

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

	// {{{0, 1, 1, 0},
	// {0, 1, 1, 0},
	// {0, 1, 1, 0},
	// {0, 1, 1, 0},
	// },
	// 			// (int[]){1, 1, 0},
	// 			// (int[]){0, 0, 0}},
	// 3},
#endif