#include "../../includes/cell.h"



// t_tetromino	copy_cell(t_tetromino cell)
// {

// }

t_tetromino	make_new_cell(void)
{
	t_tetromino	new_cell;

	srand(time(NULL)); //現在時刻を元に，擬似乱数を生成. rand()初期値が変わる
	new_cell = pieces[rand() % TYPES];
	new_cell.col = rand() % (WIDTH - new_cell.width + 1);
	new_cell.row = 0;
	return (new_cell);
}

// make_rotated_cell

