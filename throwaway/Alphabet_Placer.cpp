#include "Alphabet_Placer.h"
#include <cstdlib>


Alphabet_Placer::Alphabet_Placer() : last_position_placed{ 0 }, alphabet_key{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" }, char_currently_on{ 0 }
{
}


int Alphabet_Placer::generate_random_number() const
{
	srand(time(NULL));
	return rand() % 100 + 1;
}


void Alphabet_Placer::place_alphatbet(Board& board)
{
	if (char_currently_on == 0)
	{
		int pos_to_be_placed = generate_random_number(); 
		
		place_char_on_board(pos_to_be_placed, board);
	}


	while (char_currently_on < 26)
	{
		if (check_each_side(board) == false)
		{
			cout << "End reached, could not go further. " << endl;
			return; 
		}
	}

}


bool Alphabet_Placer::check_each_side(Board& board)
{
	int checked_pos = 0;

	// To check above a position, we can MINUS 10 from it. We then check if it is greater then 0
	checked_pos = (last_position_placed - 10);

	if (checked_pos > 0 && board.check_if_spot_occuiped(checked_pos) == false)
	{	
		place_char_on_board(checked_pos, board);
		return true;
	}

	// To check below a position, we can add 10 to it. - We then check if it is less then 101 
	checked_pos = last_position_placed + 10;

	if (checked_pos < 101 && board.check_if_spot_occuiped(checked_pos) == false)
	{
		place_char_on_board(checked_pos, board);
		return true;
	}

	// To check left of a position, we can MINUS 1 from it. - We then check if the 2 numbers are on the same row
	checked_pos = last_position_placed - 1;

	if (board.check_if_on_same_row(last_position_placed, checked_pos) == true && board.check_if_spot_occuiped(checked_pos) == false)
	{
		place_char_on_board(checked_pos, board);
		return true;
	}

	// To check right of a position, we can ADD 1 to it. - We then check if the 2 numbers are on the same row
	checked_pos = last_position_placed + 1;

	if (board.check_if_on_same_row(last_position_placed, checked_pos) == true && board.check_if_spot_occuiped(checked_pos) == false)
	{
		place_char_on_board(checked_pos, board);
		return true;
	}
	else
		return false;
}


void Alphabet_Placer::place_char_on_board(int pos_to_be_placed, Board& board)
{
	if (pos_to_be_placed < 1 || pos_to_be_placed > 100)
	{
		cout << endl << "ERROR: Position out of range 1-100. Called from Alphabet_Placer Class from Function place_char_on_board. " << endl; 
		return;
	}

	char letter_to_be_placed = alphabet_key.at(char_currently_on);
	board.set_position_on_board(letter_to_be_placed, pos_to_be_placed);

	char_currently_on++;
	last_position_placed = pos_to_be_placed;
}


