#ifndef GAME_BOARD_HPP
#define GAME_BOARD_HPP

#include <vector>


class GameBoard
{
public:
    // constructor,x is a size of the board's side, board has x^2 fields.
  GameBoard(const int x);

  const int& operator[](int x)const{ return m_board[x];};
        int& operator[](int x)     { return m_board[x];};
  const int getPiece(int x) const;
  void setPiece(int newPiece, int x);
  // returns size of the board's side
  const unsigned int getSize()const{return m_size;};
  bool isFull();
private:
  std::vector<int> m_board;
  const unsigned  int m_size;
};

#endif
