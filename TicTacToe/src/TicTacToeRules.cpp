#include "TicTacToeRules.hpp"
#include <vector>
#include "GameBoard.hpp"
#include <iostream>

bool TicTacToeRules::checkForWin(const GameBoard& TicTacToeBoard, const int player)
{
     unsigned int size = TicTacToeBoard.getSize();
     std::vector<bool> isAWin(size*2+2,true);

     //check for diagonal win
    for(unsigned int i=0;i<size;++i)
    {
       if(TicTacToeBoard[i+i*size]!=player)        isAWin[size*2]=false;
       if(TicTacToeBoard[size-i+i*size-1]!=player) isAWin[size*2+1]=false;
    }
    //check for column/row win
    for(unsigned int i=0;i<size;++i)
        for(unsigned int j=0;j<size;++j)
        {
            if(TicTacToeBoard[j+i*size]!=player) isAWin[i]=false;
            if(TicTacToeBoard[i+size*j]!=player) isAWin[size+i]=false;
        }

    for(unsigned int i=0;i<size*2+2;++i)
        if(isAWin[i])
            return true;
    return false;
}
