#pragma once

#include <iostream>
#include <string>
#include "Board.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


class Alphabet_Placer
{

public:

	Alphabet_Placer();
	int generate_random_number() const; 
	void place_alphatbet(Board& board);
	void place_char_on_board(int pos_to_be_placed, Board& board);
	bool check_each_side(Board &board);
	
private:

	int last_position_placed;
	string alphabet_key; 
	int char_currently_on;
};

