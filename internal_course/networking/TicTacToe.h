#include <iostream>
#include <array>

#define NOUGHTS 0
#define CROSSES 1


#define FULL_BOARD      0x1FF
#define HORIZONTAL_LINE 0x7
#define VERTICAL_LINE   0x49
#define DIAG_LINE_1     0x111
#define DIAG_LINE_2     0x54


int BitScanForward(int mask);

class TicTacToe
{
public:
	TicTacToe();
	int  negamax(int depth, int side);
	void makeBestMove(int side);

	void showBoard();
	int  evaluate(int side);
	std::array<char, 9> getBoard();


	void makeMove(int move, int side) { board_[side] |= move;}
	void undoMove(int move, int side) { board_[side] &= ~move; }
	bool gameOver()                   { return (!isMovesLeft() || abs(evaluate(CROSSES)) == 10); }
	int  getMoveBoard()               { return ~(board_[NOUGHTS] | board_[CROSSES]) & FULL_BOARD; }
	bool isMovesLeft()                { return (board_[NOUGHTS] | board_[CROSSES]) != FULL_BOARD; }
private:
	std::array<int, 2> board_;
};

