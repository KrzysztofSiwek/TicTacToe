#include "TileMap.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "TicTacToeRules.hpp"
#include "AlphaBeta.hpp"

int main()
{
    TicTacToeRules referee;
    int size,turn=0;
    bool enableAI;
    AI ai;

    std::cout << "wpisz rozmiar planszy" << std::endl;
    std::cin >> size;
    std::cout << "wpisz 1 aby grać z AI, wpisz 0 aby grac z kims" << std::endl;
    std::cin >> enableAI;

    sf::RenderWindow window(sf::VideoMode(size*50,size*50), "Tilemap");

    TileMap Map(size,"texture/T.png", sf::Vector2u(50, 50), size, size);
    Map.load();

    while (window.isOpen())
    {
        if(Map.getLevel().isFull())
        {
            window.close();
            std::cout << "remis" << std::endl;
        }
        else if(turn%2+1==OPLAYER && enableAI)
        {
            sf::Vector2i pos = ai.doMagic(Map.getLevel());
            Map.getLevel()[pos.x+pos.y*size]=OPLAYER;
            Map.update();
            if(referee.checkForWin(Map.getLevel(),OPLAYER))
            {
                window.close();
                std::cout << "Wygrywa AI" << std::endl;
            }
            ++turn;
        }
        else
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
              if(event.type == sf::Event::Closed)
                  window.close();

              if( sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                 sf::Vector2i pos = sf::Mouse::getPosition(window);
                 if(pos.x>0 && pos.x < size*50 && pos.y > 0 && pos.y < size*50)
                 {
                     pos/=50;

                     if(Map.getLevel()[pos.x+pos.y*size]==0 && (turn%2+1==XPLAYER || !enableAI))
                     {
                        Map.getLevel()[pos.x+pos.y*size]=turn%2+1;
                        Map.update();
                        if(referee.checkForWin(Map.getLevel(),turn%2+1))
                        {
                            window.close();
                            std::cout << (turn%2+1==XPLAYER?"wygrywa X":"wygrywa O") << std::endl;
                        }
                        ++turn;
                     }
                 }
                }

            }
        }
        window.clear(sf::Color::White);
        window.draw(Map);
        window.display();
    }

    return 0;
}
