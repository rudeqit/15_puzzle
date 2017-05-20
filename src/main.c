#include <ncurses.h>
#include <stdio.h>
#include "graphics.h"
#include "logic.h"

int main()
{  
	initscr();
	noecho();
	curs_set(FALSE);

	create_colsrow_window(stdscr);

	WINDOW *board_window = board(stdscr);
	wrefresh(stdscr);
	wrefresh(board_window);

	int* arr = filling_array();
	randomize_board(arr);

	while (1) {
		draw_board(board_window, arr);
		int zero_pos = search_zero(arr);

		switch (wgetch(board_window)) {
		case 'q':
			endwin();
			return 0;
			break;
		case 'd':
			swapvalues(arr, zero_pos, zero_pos - 1);
			break;
		case 'w':
			swapvalues(arr, zero_pos, zero_pos + 4);
			break;
		case 's':
			swapvalues(arr, zero_pos, zero_pos - 4);
			break;
		case 'a':
			swapvalues(arr, zero_pos, zero_pos + 1);
			break;
		}

	}

}
