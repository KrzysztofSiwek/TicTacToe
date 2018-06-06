#include "AlphaBeta.hpp"
//#include <bits/stdc++.h>
#include "TicTacToeRules.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
const int MAX = 10000;
const int MIN = -10000;


sf::Vector2i AI::doMagic(GameBoard& board)
{
    std::pair<int,sf::Vector2i> tmp  = minMax(0,board,OPLAYER,MIN,MAX);
    return tmp.second;
}

std::pair<int,sf::Vector2i> AI::minMax(int depth, GameBoard& board ,int player, int alpha,int beta)
{
    TicTacToeRules check;
    int score;

    if(check.checkForWin(board,XPLAYER))
        return std::make_pair(-10,sf::Vector2i(0,0));
    else if(check.checkForWin(board,OPLAYER))
        return std::make_pair(10,sf::Vector2i(0,0));
    else if (board.isFull())
        return std::make_pair(0,sf::Vector2i(0,0));
    else if (depth==5)
        return std::make_pair(0,sf::Vector2i(0,0));

    std::vector<std::pair<int,sf::Vector2i> > moves;
    int bestMove = 0;

    for(unsigned int y = 0; y < board.getSize(); y++)
        for(unsigned int x = 0; x < board.getSize(); x++)
        {
         if(board[x+y*board.getSize()]==EMPTY)
         {
            sf::Vector2i move(x,y);
            board[x+y*board.getSize()]=player;
            // maximizing player
            if(player==OPLAYER) 
            {
                score=minMax(depth+1,board,XPLAYER,alpha,beta).first;
                int bestScore = -100000;
                for(unsigned int i = 0; i < moves.size(); ++i)
                    if(moves[i].first > bestScore)
                    {
                        bestMove = i;
                        bestScore=moves[i].first;
                    }
                alpha = std::max(bestScore,alpha);
                if(alpha>=beta)
                {
                    board[x+y*board.getSize()]=EMPTY;
                    return moves[bestMove];
                }
           }
            // mainimizing player
            else
            {
                score=minMax(depth+1,board,OPLAYER,alpha,beta).first;
                int bestScore = 100000;
                for(unsigned int i = 0; i < moves.size(); ++i)
                if(moves[i].first < bestScore)
                {
                    bestMove = i;
                    bestScore=moves[i].first;
                }
                beta = std::min(bestScore,beta);
                if(alpha>=beta)
                {
                    board[x+y*board.getSize()]=EMPTY;
                    return moves[bestMove];
                }
            }
            moves.push_back(std::make_pair(score,move));
            board[x+y*board.getSize()]=EMPTY;
         }
        }

   return moves[bestMove];
}

