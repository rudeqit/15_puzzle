#include "ncurses.h"

int main()
{
	initscr();
	printw("MOM, I'M A PROGRAMER!\n");
	refresh();
	getch();
	endwin();
	return 0;
}
