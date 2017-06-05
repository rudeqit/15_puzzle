#include <ncurses.h>
#include <stdio.h>
#include "graphics.h"
#include "logic.h"

int main()
{  
	initscr();
	noecho();
	curs_set(FALSE);

//	create_colsrow_window(stdscr);
	control_window(stdscr);

	WINDOW *board_window = board(stdscr);
	wrefresh(stdscr);
	wrefresh(board_window);

	int* arr = filling_array();
	randomize_board(arr);

	int* mask = create_array(4);

	while (1) {
		draw_board(board_window, arr);
		int zero_pos = mask_build(arr, mask);

		switch (wgetch(board_window)) {
		case 'q':
			endwin();
			return 0;
			break;
		case 'd':
			if (!mask[0]) {
				break;
			}
			swapvalues(arr, zero_pos, zero_pos - 1);
			break;
		case 'w':
			if (!mask[1]) {
				break;
			}
			swapvalues(arr, zero_pos, zero_pos + 4);
			break;
		case 's':
			if (!mask[2]) {
				break;
			}
			swapvalues(arr, zero_pos, zero_pos - 4);
			break;
		case 'a':
			if (!mask[3]) {
				break;
			}
			swapvalues(arr, zero_pos, zero_pos + 1);
			break;
		}

		if (check_board(arr)) {
			draw_board(board_window, arr);
			victory_window(board_window);
			getch();
			endwin();
			return 0;
		}

	}

}
