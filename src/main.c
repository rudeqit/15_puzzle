#include <ncurses.h>
#include "graphics.h"

int main()
{  
	initscr();
	noecho();
//	curs_set(FALSE);
	create_colrow_window(stdscr);
	getch();   
   	endwin();
}
