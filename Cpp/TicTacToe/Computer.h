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

        vector<Move> moves;

        for (size_t i = 0; i < freeSquares.size(); i++)
        {
            Move move;
            move.Index = stoi(freeSquares[i]);
            board[freeSquares[i]] = player;

            /* Tässä tapahtuu rekursio, jos on konen vuoro niin uusi MinMax kutsutaan pelaajan "vuorolla"
             ja toisinpäin myös */

            if (player == computer)
            {

                Move result = new Move();
                result = (Move)MinMax(board, human);
                move.score = result.score;
            }
            else
            {
                Move result = new Move();
                result = (Move)MinMax(board, computer);
                move.score = result.score;
            }

            // vapaudedaan käsitelyty ruutu ja lisätään siirto (move) moves listaan
            board[freeSquares[i]] = move.index;
            moves.Add(move);

        }

        /* kun kaikki mahdolliset siirrot yhdltä tasolta on kerätty, etsitään niistä paras mahdollinen
        sille pelaajalle kene vuoro on - kone maximalisoi pelaaja minimalisoi*/
        int bestMove = 0;

        if (player == computer)
        {
            int bestScore = -10000;
            for (int i = 0; i < moves.Count; i++)
            {
                if (moves[i].score > bestScore)
                {
                    bestScore = moves[i].score;
                    bestMove = i;
                }
            }
        }
        else
        {
            int bestScore = 10000;
            for (int i = 0; i < moves.Count; i++)
            {
                if (moves[i].score < bestScore)
                {
                    bestScore = moves[i].score;
                    bestMove = i;
                }
            }
        }

        //tason paras siirto löydetty, palautetaan se ylöspäin edelliselle pelaajalle
        return moves[bestMove];

    }



}

};



