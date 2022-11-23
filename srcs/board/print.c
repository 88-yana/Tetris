#include "../../includes/board.h"

void	copy_cell_to_board(t_tetromino cell, int board[][WIDTH]) {
	for (int i = 0; i < cell.width; i++)
		for (int j = 0; j < cell.width; j++)
			if (cell.shape[i][j])
				board[cell.row + i][cell.col + j] = cell.shape[i][j];
}

static void	write_board(t_vars *vars, int sub_board[][WIDTH]) {
	for (int i = 0; i < WIDTH - 4; i++)
		printf(" ");
	printf("Tetris\n");
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++)
		{
			if (vars->board[i][j] + sub_board[i][j] == 1)
				printf("%c ", '?');
			else if (vars->board[i][j] + sub_board[i][j] == 2)
				printf("%c ", '$');
			else if (vars->board[i][j] + sub_board[i][j] == 3)
				printf("%c ", '#');
			else if (vars->board[i][j] + sub_board[i][j] == 4)
				printf("%c ", '!');
			else if (vars->board[i][j] + sub_board[i][j] == 5)
				printf("%c ", '@');
			else if (vars->board[i][j] + sub_board[i][j] == 6)
				printf("%c ", '^');
			else if (vars->board[i][j] + sub_board[i][j] == 7)
				printf("%c ", '*');
			else
				printf("%c ", '.');
		}
		printf("\n");
	}
	printf("\nScore: %d\n", vars->score);
}

void	print_current_board(t_vars *vars)
{
	int	sub_board[HEIGHT][WIDTH] = {0};

	copy_cell_to_board(vars->cell, sub_board);
	clear();
	write_board(vars, sub_board);
}
