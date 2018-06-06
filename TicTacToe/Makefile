
CC = g++
Links = -lsfml-graphics -lsfml-window -lsfml-system
Flags = -pedantic -Wall -std=c++14 -Iinclude -g


TicTacToe: main.o TileMap.o GameBoard.o TicTacToeRules.o AlphaBeta.o
	$(CC) $(Flags)  main.o TileMap.o GameBoard.o TicTacToeRules.o AlphaBeta.o  $(Links)

main.o: src/main.cpp include/GameBoard.hpp include/TileMap.hpp
	$(CC) $(Flags) src/main.cpp -c -o main.o

TileMap.o: src/TileMap.cpp include/TileMap.hpp include/GameBoard.hpp
	$(CC) $(Flags) src/TileMap.cpp -c -TileMap.o

GameBoard.o: src/GameBoard.cpp include/GameBoard.hpp
	$(CC) $(Flags) src/GameBoard.cpp -c -o GameBoard.o

TicTacToeRules.o: src/TicTacToeRules.cpp include/TicTacToeRules.hpp include/GameBoard.hpp
	$(CC) $(Flags) src/TicTacToeRules.cpp -c -o TicTacToeRules.o

AlphaBeta.o: src/AlphaBeta.cpp include/AlphaBeta.hpp include/GameBoard.hpp include/TicTacToeRules.hpp
	$(CC) $(Flags) src/AlphaBeta.cpp -c -o AlphaBeta.o

