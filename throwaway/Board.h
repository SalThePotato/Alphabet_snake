#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


class Board
{

public:

	Board();
	
	void display_board() const;

	/// <summary>
	/// Puts the letter on the board in the posistion you specified
	/// </summary>
	/// <param name="letter"></param>
	/// <param name="Posistion: ">The place that it will appear at. PUT FROM 1-100!! </param>
	void set_position_on_board(char letter, int posistion);

	/// <summary>
	/// Converts a 1-100 number position to 2 numbers that can be plugged into a 2-dimesomnal array.
	/// </summary>
	/// <param name="position">The 1-100 number position</param>
	/// <param name="first_arr_pos">The first number to be put in the 2-dimeosnal array</param>
	/// <param name="second_arr_pos">The second number to be put in the 2-dimeosnal array</param>
	void convert_position_to_arr(int position, int& first_arr_pos, int& second_arr_pos);

	bool check_if_on_same_row(int pos_1, int pos_2);

	bool check_if_spot_occuiped(int pos_to_be_checked);

private:

	char board_array[10][10] {}; 

};

