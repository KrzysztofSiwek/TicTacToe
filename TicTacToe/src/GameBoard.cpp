#include "GameBoard.hpp"
GameBoard::GameBoard(const int x):
    m_size(x)
{
    m_board.resize(x*x);
}

const int GameBoard::getPiece(int x) const
{
  return m_board[x];
}

void GameBoard::setPiece(int newPiece, int x)
{
  m_board[x]= newPiece;
}

bool GameBoard::isFull()
{
    for(int x: m_board)
        if(x==0)
            return false;
    return true;
}
