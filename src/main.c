#include <ncurses.h>
#include "graphics.h"

int main()
{
	initscr();
	draw_something();
	getch();
	endwin();
	return 0;
}
