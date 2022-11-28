#include "../../includes/tetris.h"

static void	init_vars(t_vars *vars)
{
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
			vars->board[i][j] = 0;
	vars->score = 0;
	vars->game_on = true;
	vars->cell = make_new_cell();
	vars->fall_time = 600000000;
	clock_gettime(CLOCK_MONOTONIC, &(vars->start_time));
}

static void	setup_tetris(void)
{
	initscr(); //curses を利用する場合，最初に呼び出さなければならない
	noecho(); // 端末にキーを表示しない defined by curses.h
	cbreak(); // 矢印などの特殊キーをgetch関数で受け取れるようにする defined by curses.h
	keypad(stdscr, true); // 矢印などの特殊キーをgetch関数で受け取れるようにする defined by curses.h
	timeout(1); //入力を何ミリ秒待つか指定，負の値の場合，無限に待つ defined by curses.h
	start_color();
	init_pair(0, COLOR_RED, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLUE);
	init_pair(2, COLOR_RED, COLOR_CYAN);
	init_pair(3, COLOR_RED, COLOR_GREEN);
	init_pair(4, COLOR_RED, COLOR_MAGENTA);
	init_pair(5, COLOR_RED, COLOR_RED);
	init_pair(6, COLOR_RED, COLOR_WHITE);
	init_pair(7, COLOR_RED, COLOR_YELLOW);
	init_pair(8, COLOR_RED, COLOR_GRAY);
}

static void	execute_tetris(t_vars *vars)
{
	print_current_board(vars);
	while (vars->game_on)
	{
		int	key_input = getch();
		if (key_input != ERR)
			move_cell(key_input, vars);
		if (is_fall(vars))
			move_cell(KEY_DOWN, vars);
	}
}

static void	terminate_tetris(t_vars *vars)
{
	endwin(); //端末の制御を終了する defined by curses.h
	print_result(vars);
}

int	main(void)
{
	t_vars	vars;

	init_vars(&vars);
	setup_tetris();
	execute_tetris(&vars);
	terminate_tetris(&vars);
	return (0);
}
