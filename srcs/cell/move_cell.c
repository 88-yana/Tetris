#include "../../includes/cell.h"

static void	move_cell_to(int direction, t_vars *vars) {

	vars->cell.col += direction;
	if (is_placeable(vars, vars->cell) == false)
		vars->cell.col -= direction;
}

static void	move_down_cell(t_vars *vars) {

	vars->cell.row++;
	if (is_placeable(vars, vars->cell) == false)
	{
		vars->cell.row--;
		// update_board(vars);
	}
}

static void	rotate_cell(t_vars *vars) {
	t_tetromino	temp;

	temp = vars->cell;
	make_rotated_cell(&temp);
	if (is_placeable(vars, temp))
		make_rotated_cell(&(vars->cell));
}

void	move_cell(int input, t_vars *vars)
{
	switch (input)
	{
		case KEY_DOWN: // 後でマクロし直す
			move_down_cell(vars);
			break ;
		case KEY_RIGHT:
			move_cell_to(RIGHT, vars);
			break ;
		case KEY_LEFT:
			move_cell_to(LEFT, vars);
			break ;
		case KEY_UP:
			rotate_cell(vars);
	}
	print_current_board(vars);
}
