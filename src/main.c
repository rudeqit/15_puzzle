#include <ncurses.h>
#include "graphics.h"
#include "logic.h"

int main()
{  
	initscr();
	noecho();
//	curs_set(FALSE);

	create_colsrow_window(stdscr);
	getch();

	WINDOW *board_window = board(stdscr);
	wrefresh(stdscr);
	wrefresh(board_window);
	getch();

//	draw_board(board_window);
//	getch();

   	endwin();
}
