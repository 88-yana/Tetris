#include "../../includes/cell.h"

static void	move_cell_to(int direction, t_vars *vars) {

	vars->cell.col += direction;
	if (is_placeable(vars) == false)
		vars->cell.col -= direction;
}

static void	move_down_cell(t_vars *vars) {

	vars->cell.row++;
	if (is_placeable(vars) == false)
	{
		vars->cell.row--;
		// update_board(vars);
	}
}

// static void	rotate_cell(t_vars *vars) {
// 	t_tetromino	temp;

// 	temp = copy_cell(vars->cell);
// 	make_rotated_cell(&temp);
// 	if (is_shape_placeable(temp))
// 		make_rotated_shape(&(vars->cell));
// }

void	move_cell(int input, t_vars *vars)
{
	switch (input)
	{
		case KEY_DOWN: // 後でマクロし直す
			move_down_cell(vars);
			printf("%d\n", 123);
			break ;
		case KEY_RIGHT:
			move_cell_to(RIGHT, vars);
			printf("%d\n", 123);
			break ;
		case KEY_LEFT:
			move_cell_to(LEFT, vars);
			printf("%d\n", 123);
			break ;
		// case KEY_UP:
		// 	rotate_cell(vars);
	}
	print_current_board(vars);
}