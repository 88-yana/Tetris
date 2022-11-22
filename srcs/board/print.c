#include "../../includes/board.h"

void	copy_cell_to_board(t_tetromino cell, int board[][WIDTH]) {
	for (int i = 0; i < cell.width; i++)
		for (int j = 0; j < cell.width; j++)
			if (cell.shape[i][j])
				board[cell.row + i][cell.col + j] = cell.shape[i][j];
}

#define location(y,x)	printf("\033[%d;%dH" ,y,x)

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
		fflush(stdout);
		location(i + 1, 0);
	}
	printf("\nScore: %d\n", vars->score);
	fflush(stdout);
	location(HEIGHT + 2, 0);
	// clear_screen;
}

void	print_current_board(t_vars *vars)
{
	int	sub_board[HEIGHT][WIDTH] = {0};

	copy_cell_to_board(vars->cell, sub_board);
	clear_screen;
	location(0, 0);
	write_board(vars, sub_board);
}
