#include "graphics.h"

void control_window(WINDOW* stdscr)
{
	int parent_cols, parent_row;
	getmaxyx(stdscr, parent_row, parent_cols);

	WINDOW *control_screen = newwin(4, 38, parent_row - 5, parent_cols - parent_cols);
	box(control_screen, 0, 0);
	mvwprintw(control_screen, 1, 5, "Use \"w, a, s, d\" for control");
	mvwprintw(control_screen, 2, 11, "and \"q\" for exit" );

	wrefresh(stdscr);
	wrefresh(control_screen);
}

void victory_window(WINDOW* stdscr)
{
	int parent_cols, parent_row;
	getmaxyx(stdscr, parent_row, parent_cols);

	WINDOW *victory_screen = newwin(3, 15, (parent_row / 3) - 6, (parent_cols / 2) - 7);
	box(victory_screen, 0, 0);
	mvwprintw(victory_screen, 1, 4, "You win!");

	wrefresh(victory_screen);
}

WINDOW *board(WINDOW* stdscr)
{
	int parent_cols, parent_row;
	getmaxyx(stdscr, parent_row, parent_cols);

	WINDOW *board_window = newwin(9, 15, (parent_row / 2) - 7, (parent_cols / 2) - 7);
	box(board_window, 0, 0);

	return board_window;
}

void draw_board(WINDOW* board_window, int* arr)
{
	int i, x = 1, y = 1;

	for (i = 0; i <= 15; i++) {
		x++;

		if (x >= 13) {
			x = 2;
			y += 2;
		} 

		if (y < 9) { 
			if ((arr[i] <= 9) && (arr[i] != 0)) {
				mvwprintw(board_window, y, x, "%d ", arr[i]);
				x += 2;
			} else if ((arr[i] > 9) && (arr[i] != 0)) {
				mvwprintw(board_window, y, x, "%d", arr[i]);
				x += 2;
			} else {
				mvwprintw(board_window, y, x, "  ");
				x += 2;
			}
		}
	}

	wrefresh(board_window);
}
