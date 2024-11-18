//my compiler can't handle having the .cpp files included, only the .h. yours seems the opposite?
//include "Board.cpp"
//#include "Checker.cpp"
//#include "Piece.cpp"

#include "Board.h"
#include <iomanip>

int main(){

	std::cout << "\t\tWelcome to checkers!" << std::endl;
	std::cout << "|********************************************************************|" << std::endl;
	std::cout << "|  " <<  std::setw(65) << std::left <<  "Checkers is a two-player game, where each player moves pieces" <<" |" << std::endl;
	std::cout << "|  " <<  std::setw(65) << std::left <<  "diagonally. Pieces can move one square forward or capture an" <<" |" << std::endl;
	std::cout << "|  " <<  std::setw(65) << std::left <<  "opponent's piece by jumping over it to an empty square. Kings" <<" |" << std::endl;
	std::cout << "|  " <<  std::setw(65) << std::left <<  "(created when a piece reaches the opponent's back row) can move" <<" |" << std::endl;
	std::cout << "|  " <<  std::setw(65) << std::left <<  "both forward and backward. The goal is to capture all opponent" <<" |" << std::endl;
	std::cout << "|  " <<  std::setw(65) << std::left <<  "pieces or block them so they can't move." <<" |" << std::endl;
	std::cout << "|--------------------------------------------------------------------|" << std::endl;
	std::cout << "|  " <<  std::setw(65) << std::left <<  "Provide moves in the form row+col>row+col" <<" |" << std::endl;
	std::cout << "|  " <<  std::setw(61) << std::left <<  "\teg. b3>c4" << " |" << std::endl;
	std::cout << "|  " <<  std::setw(65) << std::left <<  "To perform multiple jump moves, enter the first set of" <<" |" << std::endl;
	std::cout << "|  " <<  std::setw(65) << std::left <<  "coordinates, a space " ", then the second set of coordinates." <<"|" << std::endl;
	std::cout << "|  " <<  std::setw(61) << std::left <<  "\teg. b3>d &d5>b7" <<" |" << std::endl;
	std::cout << "|********************************************************************|" << std::endl;
	std::cout << "\t\tHave fun!" << std::endl << std::endl;

	//consider having player enter moves individually (specifically for double jump/ triple jump moves) this
	//would make it so that board and piece class only have to consider cases of single moves, and just get multiple
	//of them in a row

	Board board;

    // start with red(red - odd, black - even)
    // red at bottom black at top
    int turn = 1; 
    
    board.display();

	bool cont = true;
	std::string color;
	std::string input;

	while(cont) {

		if(turn % 2 == 0) {
			color = "Black";
		}else {
			color = "Red";
		}

		std::cout << color << "'s turn." << std::endl;
		std::getline(std::cin, input);

		board.attemptMove(input, turn);
		board.display();
	}

    return 0;
}

/*zach's test case
*
b3>c4
c6>d5
c2>b3
g6>h5
f3>g4
h5>f3
b3>a4
f7>g6
d1>c2
d5>b3 b3>d1
a4>b5
*/
