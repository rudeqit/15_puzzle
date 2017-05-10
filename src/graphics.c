#include <ncurses.h>
#include <string.h>
#include "graphics.h"

void create_colsrow_window(WINDOW* stdscr)
{
	int parent_cols, parent_row;
	getmaxyx(stdscr, parent_row, parent_cols);

	WINDOW *colsrow_screen = newwin(3, 43, parent_row - 3, 0);
	box(colsrow_screen, 0, 0);
	mvwprintw(colsrow_screen, 1, 1, "The number of rows - %d and columns - %d", parent_cols, parent_row);

//	touchwin(stdscr); //how it work?
	wrefresh(stdscr);
	wrefresh(colsrow_screen);
//	wgetch(colsrow_screen);
}

WINDOW *board(WINDOW* stdscr)
{
	int parent_cols, parent_row;
	getmaxyx(stdscr, parent_row, parent_cols);

	WINDOW *board_window = newwin(10, 15, (parent_row / 2) - 7, (parent_cols / 2) - 7);
	box(board_window, 0, 0);

	return board_window;
}

/*
void draw_board(WINDOW* board_window)
{

}
*/
