#include <ncurses.h>
#include <string.h>
#include "graphics.h"

void create_colrow_window(WINDOW* stdscr)
{
	int parent_x, parent_y;
	getmaxyx(stdscr, parent_y, parent_x);
	WINDOW *colrow_screen = newwin(3, 43, parent_y - 3, 0);

	box(colrow_screen, 0, 0);
	mvwprintw(colrow_screen, 1, 1, "The number of rows - %d and columns - %d", parent_x, parent_y);

	touchwin(stdscr);
	wrefresh(stdscr);
	wrefresh(colrow_screen);
}
