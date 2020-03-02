#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Board
{
public:
	vector <string> State;

	Board();

	static bool isWinning(vector <string> board, string player);

	static vector<string> availableSquares(vector<string> board, string computer, string player);
};

