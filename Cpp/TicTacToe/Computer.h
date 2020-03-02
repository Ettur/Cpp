#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Move.h"
#include "Board.h"

using namespace std;

class Computer
{
public:
	static string Ai;
	static string Player;


    static Move MinMax(vector <string> board, string player) {

        vector <string> freeSquares = Board::availableSquares(board, Ai, Player);

        if (Board::isWinning(board, Ai))
        {
            Move max;
            max.Value = 10;
            return max;
        }
        else if (Board::isWinning(board, Player))
        {
            Move min;
            min.Value = -10;
            return min;
        }
        else if (freeSquares.size() == 0)
        {
            Move draw;
            draw.Value = 0;
            return draw;
        }

}

};



