#include "Board.cpp"
#include "Checker.cpp"
#include "Piece.cpp"
#include "Game.cpp"
#include "User.cpp"
#include "KingChecker.cpp"

// allows for colour usability
//#include <windows.h>

#include <sstream>
#include <typeinfo>

#include "Board.h"
#include "Checker.h"
#include "Piece.h"
#include "Game.h"
#include <iomanip>

// file that contaings control flow for main  logic

int main(){

	//allows for colour printout in the terminal
	//system(("chcp " + std::to_string(CP_UTF8)).c_str());

    // welcome the use and display game instructions
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
	std::cout << "|  " <<  std::setw(65) << std::left <<  "coordinates, a space " ", then the second set of coordinates. " <<" |" << std::endl;
	std::cout << "|  " <<  std::setw(61) << std::left <<  "\teg. b3>d5 "
													   ""
				"d5>b7" <<" |" << std::endl;
	std::cout << "|********************************************************************|" << std::endl;
	std::cout << "\t\tHave fun!" << std::endl << std::endl;

    // create game object
	Game game;
    
    // variables to store user's name
    std::string name1,name2, gameStyle;
    
    // take user input
    std::cout << "What king of game would you like to play? (PvP or PvAI) " << std::endl;
    
    
    User user1;
    User user2;
    
    while (gameStyle != "PvP" || gameStyle != "AI")
    {
        std::getline(std::cin, gameStyle);
        
        if (gameStyle == "PvP")
        {
            // take user input
            std::cout << "Provide the name of first player: " << std::endl;
            std::getline(std::cin, name1);
            std::cout << "Provide the name of second player: " << std::endl;
            std::getline(std::cin, name2);
            
            // provide user input to user objects
            user1.setName(name1);
            user2.setName(name2);
            
            //continue playing the game until end game status is reached
            while(!game.endGame()) {
                game.pvpPlay();
            }
        }

        else if(gameStyle == "PvAI")
        {
            // take user input
            std::cout << "Provide the name of human player: " << std::endl;
            std::getline(std::cin, name1);
            
            name2 = "AI";
            
            // provide user input to user objects
            user1.setName(name1);
            user2.setName(name2);
            
            //continue playing the game until end game status is reached
            while(!game.endGame()) {
                game.aiPlay();
            }
        }
        
        else
        {
            std::cout << "Please provide a valid input: \"PvP\" or \"PvAI\"" <<std::endl;
        }
    }
    
    // provide information and statistics at the end of the game
    std::cout << game.currentColor() << " lost! " << std::endl;
	std::cout << "The game lasted " << game.getTurn() << " moves." << std::endl;
	std::cout << std::endl << "Thanks for playing" << std::endl;
    
    // recording the info from this game into a file
    // the first user parameter in the function call is a winner
    if (game.currentColor() == "Black")
        game.updateStats(user1, user2);
    else
        game.updateStats(user2, user1);
    
    return 0;
}
