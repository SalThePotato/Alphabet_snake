#include "Board.h"

using std::to_string;
using std::stoi;

Board::Board()
{
	
}


void Board::display_board() const
{
	cout << endl; 

	/* We use a nested while loop because it not only has the same funciontally as a 
	for loop, but it looks more clean and easier to read */

	int i = 0;

	while (i < 10)
	{
		int b = 0;

		while (b < 10)
		{
			cout << "[" << board_array[i][b] << " ] "; 
			b++;
		}

		cout << endl;
		i++; 
	}
}


void Board::set_position_on_board(char letter, int position)
{
	// Checks whether position is not between 1 and 100 so that it gives us an error to come back and see why it failed
	if (position < 1 || position > 100)
	{
		cout << "ERROR: PUT NUMBER OUTSIDE OF RANGE. Calling from Class Board, Function: set_position_on_board " << endl;
		return;
	}


	int first_arr_pos = 0, second_arr_pos = 0; 

	convert_position_to_arr(position, first_arr_pos, second_arr_pos);

	board_array[first_arr_pos][second_arr_pos] = letter;
}


void Board::convert_position_to_arr(int position, int& first_arr_pos, int& second_arr_pos)
{
	/* We turn the position to a string so we can access indivual numbers. We subtract it by 1 because 
	   arrays start at 0 while the position starts at 1. */ 
	string string_num = to_string(position - 1);

	if (string_num.length() == 1)
	{
		second_arr_pos = position - 1; 
		first_arr_pos = 0;
	}
	else
	{
		first_arr_pos = string_num.at(0) - '0';
		second_arr_pos = string_num.at(1) - '0';
	}
}


bool Board::check_if_on_same_row(int pos_1, int pos_2)
{
	int first_pos_1_arr = 0, second_pos_1_arr = 0;

	convert_position_to_arr(pos_1, first_pos_1_arr, second_pos_1_arr);

	int first_pos_2_arr = 0, second_pos_2_arr = 0;

	convert_position_to_arr(pos_2, first_pos_2_arr, second_pos_2_arr);


	if (first_pos_1_arr == first_pos_2_arr)
	{
		return true;
	}
	else
		return false;
}


bool Board::check_if_spot_occuiped(int pos_to_be_checked)
{
	int first_arr_pos = 0, second_arr_pos = 0;

	convert_position_to_arr(pos_to_be_checked, first_arr_pos, second_arr_pos);

	if (board_array[first_arr_pos][second_arr_pos] == NULL)
	{
		return false;
	}
	else
		return true;
}
