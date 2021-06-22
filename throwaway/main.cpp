#include <iostream>
#include <string>
#include "Board.h"
#include "Alphabet_Placer.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;




int main()
{
	cout << "Hello World!" << endl;

	Board board;
	
	board.display_board();
	

	Alphabet_Placer placer;
	
	placer.place_alphatbet(board);
	
	cout << endl << "This is the result. " << endl;
	board.display_board();
	
	system("pause");
	return 0;
}


