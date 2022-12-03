#include "../../includes/board.h"

void	copy_cell_to_board(const t_tetromino cell, int board[][WIDTH])
{
	for (int i = 0; i < cell.width; i++)
		for (int j = 0; j < cell.width; j++)
			if (cell.shape[i][j])
				board[cell.row + i][cell.col + j] = cell.shape[i][j];
}

static void	write_block(const int type)
{
	attron(COLOR_PAIR(type));
	printw("%c ", ' ');
	attrset(0);
}

static void	write_board(const t_vars *vars, const int sub_board[][WIDTH])
{
	for (int i = 0; i < WIDTH - 1; i++)
		printw(" ");
	printw("Tetris\n");
	for (int i = 0; i < HEIGHT; i++)
	{
		write_block(COLOR_GRAY);
		for (int j = 0; j < WIDTH; j++)
			write_block(vars->board[i][j] + sub_board[i][j]);
		write_block(COLOR_GRAY);
		printw("\n");
	}
	for (int j = 0; j < WIDTH + 2; j++)
		write_block(COLOR_GRAY);
	printw("\nScore: %d\n", vars->score);
}

void	print_current_board(t_vars *vars)
{
	int	sub_board[HEIGHT][WIDTH] = {0};

	copy_cell_to_board(vars->cell, sub_board);
	clear();
	write_board(vars, sub_board);
}

void	print_result(const t_vars *vars)
{
	printf("Game over.\n");
	printf("Score: %d\n", vars->score);
}