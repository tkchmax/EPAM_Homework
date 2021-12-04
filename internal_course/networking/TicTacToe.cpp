#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
	board_[CROSSES] = 0;
	board_[NOUGHTS] = 0;
}

static int nextMove(int& move_board)
{
	if (move_board == 0)
		return 0;

	int move = 1 << BitScanForward(move_board);
	move_board &= move_board - 1;
	return move;
}

int TicTacToe::negamax(int depth, int side)
{
	int score = evaluate(side);

	if (abs(score) == 10)
		return score;
	if (!isMovesLeft())
		return 0;

	int best = -1000;
	int movesBoard = getMoveBoard();
	int move = nextMove(movesBoard);
	int bestMove = move;
	while (move)
	{
		makeMove(move, side);
		int tmp = -negamax(depth + 1, (side == CROSSES) ? NOUGHTS : CROSSES) - depth;
		undoMove(move, side);
		if (tmp > best)
		{
			best = tmp;
			bestMove = move;
		}
		move = nextMove(movesBoard);
	}

	if (depth == 0)
		makeMove(bestMove, side);

	return best;
}

void TicTacToe::makeBestMove(int side)
{
	if (gameOver())
		return;

	negamax(0, side);
}

void TicTacToe::showBoard()
{
	auto game_board = getBoard();
	std::cout << "   1 2 3\n";
	std::cout << "  ______\n";
	std::cout << "c| " << game_board[6] << " " << game_board[7] << " " << game_board[8] << std::endl;
	std::cout << "b| " << game_board[3] << " " << game_board[4] << " " << game_board[5] << std::endl;
	std::cout << "a| " << game_board[0] << " " << game_board[1] << " " << game_board[2] << std::endl;
	std::cout << std::endl << std::endl;
}

int TicTacToe::evaluate(int side)
{
	int oppositeSide = (side == CROSSES) ? NOUGHTS : CROSSES;
	for (int i = 0; i < 3; ++i)
	{
		int vertical_line = VERTICAL_LINE << i;
		int horizontal_line = HORIZONTAL_LINE << (3 * i);
		if ((board_[side] & vertical_line) == vertical_line || (board_[side] & horizontal_line) == horizontal_line)
			return 10;
		if ((board_[oppositeSide] & vertical_line) == vertical_line || (board_[oppositeSide] & horizontal_line) == horizontal_line)
			return -10;
	}

	if ((board_[side] & DIAG_LINE_1) == DIAG_LINE_1 || (board_[side] & DIAG_LINE_2) == DIAG_LINE_2)
		return 10;
	if ((board_[oppositeSide] & DIAG_LINE_1) == DIAG_LINE_1 || (board_[oppositeSide] & DIAG_LINE_2) == DIAG_LINE_2)
		return -10;

	return 0;
}

std::array<char, 9> TicTacToe::getBoard()
{
	int crosses = board_[CROSSES];
	int noughts = board_[NOUGHTS];

	std::array<char, 9> game_board = { '-','-','-', '-','-','-' , '-','-','-' };
	while (crosses)
	{
		game_board[BitScanForward(crosses)] = 'x';
		crosses &= crosses - 1;
	}
	while (noughts)
	{
		game_board[BitScanForward(noughts)] = 'o';
		noughts &= noughts - 1;
	}
	return game_board;
}

int BitScanForward(int mask)
{
	unsigned char isNonzero;
	unsigned long index;
	isNonzero = _BitScanForward(&index, mask);
	if (isNonzero)
		return index;
}
