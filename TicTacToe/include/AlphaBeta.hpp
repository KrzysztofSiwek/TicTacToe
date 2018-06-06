#ifndef ALPHA_BETA_CPP
#define ALPHA_BETA_CPP

#include "GameBoard.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>

class AI
{
public:
    // minMax algorithm interface
    sf::Vector2i doMagic(GameBoard& board);
private:
    // minMax algorithm 
    std::pair<int,sf::Vector2i> minMax(int depth,GameBoard& board, int player,int alpha, int beta);

};
#endif
