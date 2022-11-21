#include "../../includes/tetris.h"

void	init_vars(t_vars *vars)
{
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
			vars->board[i][j] = 0;
	vars->score = 0;
	vars->reduce_time = 5000;
	vars->fall_time = 400000;
	vars->game_on = true;
	clock_gettime(CLOCK_MONOTONIC, &(vars->start_time));
	make_new_cell(vars->current_cell);
}

void	setup_tetris(void) {
	srand(time(NULL)); //現在時刻を元に，擬似乱数を生成
	initscr(); //curses を利用する場合，最初に呼び出さなければならない
	noecho(); // 矢印などの特殊キーをgetch関数で受け取れるようにする defined by curses.h
	cbreak(); // 矢印などの特殊キーをgetch関数で受け取れるようにする defined by curses.h
	keypad(stdscr, true); // 矢印などの特殊キーをgetch関数で受け取れるようにする defined by curses.h
	timeout(1); //入力を何ミリ秒待つか指定，負の値の場合，無限に待つ defined by curses.h
}

void	execute_tetris(t_vars *vars) {
	print_current_board(vars);
	while (vars->game_on)
	{
		int	key_input = getch();
		if (key_input != ERR)
			move_cell(key_input, vars);
		if (is_fall(vars))
			move_down(vars);
	}
}

void	terminate_tetris(t_vars *vars) {
	free_shape(vars->current_cell); //Check：これが必要かはまだ不明
	endwin(); //端末の制御を終了する defined by curses.h
	print_result(vars->score);
}

int	main(void) {
	t_vars	vars;

	init_vars(&vars);
	setup_tetris();
	execute_tetris(&vars);
	terminate_tetris(&vars);
	return (0);
}
