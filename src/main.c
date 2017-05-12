#include <ncurses.h>
#include <stdio.h>
#include "graphics.h"
#include "logic.h"

int main()
{  
	initscr();
	noecho();
//	curs_set(FALSE);

	create_colsrow_window(stdscr);
//	getch(); delete

	WINDOW *board_window = board(stdscr);
	wrefresh(stdscr);
	wrefresh(board_window);
//	getch(); delete

	int* arr = filling_array();
	randomize_board(arr);
	draw_board(board_window, arr);
	getch();

   	endwin();
}
