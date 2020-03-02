#include <iostream>
#include <string>
#include <vector>

#include "Board.h"
#include "Move.h"

using namespace std;

vector <string> State;

Board::Board() {
    State = { "1","2","3","4","5","6","7","8","9"};
}

static vector<string> Board::availableSquares(vector<string> board, string computer, string player) {
    vector <string> availSqrs;
    for (size_t i = 0; i < board.size(); i++) {
        if ((board[i] != computer) && (board[i] != player)) {
            availSqrs.push_back(board[i]);
        }
    }

    return availSqrs;
};

bool Board::isWinning(vector <string> board, string player) {
    if (
        (board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)
        )
    {
        return true;
    }
    else {
        return false;
    }

}
