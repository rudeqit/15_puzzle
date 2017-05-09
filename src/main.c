#include <ncurses.h>
#include "graphics.h"

int main()
{  
	initscr();
	noecho();
//	curs_set(FALSE);

	WINDOW *board_window = board(stdscr);
	wrefresh(stdscr);
	wrefresh(board_window);

//	draw_board(board_window);

	create_colsrow_window(stdscr);
	getch();
   	endwin();
}
