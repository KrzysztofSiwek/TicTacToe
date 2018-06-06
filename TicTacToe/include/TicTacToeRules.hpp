#ifndef TIC_TAC_TOE_RULES
#define TIC_TAC_TOE_RULES

#include "GameBoard.hpp"
#include <SFML/Graphics.hpp>

const int XPLAYER=1;
const int OPLAYER=2;
const int EMPTY=0;

class TicTacToeRules
{
public:
    // checks whether player has won the game
    bool checkForWin(const GameBoard& TicTacToeBoard, const int player);
};

#endif
