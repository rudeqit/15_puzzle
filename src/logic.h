#ifndef LOGIC_H
#define LOGIC_H

#include <string.h>
#include <stdlib.h>
#include <time.h>

int* create_array(int size);

int* filling_array();

void randomize_board(int* arr);

int find_zero_pos(int* arr);

void swapvalues(int* arr, int x, int y);

int mask_build(int* arr, int* mask);

int check_board(int* arr);

int count_couple(int* arr);

int check_victory(int* arr);

#endif
