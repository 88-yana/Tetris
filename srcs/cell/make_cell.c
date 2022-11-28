#include "../../includes/cell.h"

t_tetromino	make_new_cell(void)
{
	t_tetromino	new_cell;

	srand(time(NULL)); //現在時刻を元に，擬似乱数を生成. rand()初期値が変わる
	new_cell = pieces[rand() % TYPES];
	new_cell.col = rand() % (WIDTH - new_cell.width + 1);
	new_cell.row = 0;
	return (new_cell);
}

t_tetromino	make_rotated_cell(t_tetromino cell)
{
	t_tetromino	new_cell;

	new_cell = cell;
	for (int i = 0; i < cell.width; i++)
		for (int j = 0, k = cell.width - 1; j < cell.width; j++, k--)
			new_cell.shape[i][j] = cell.shape[k][i];
	return (new_cell);
}
