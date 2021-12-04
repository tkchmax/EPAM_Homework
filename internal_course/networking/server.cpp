#include "TicTacToe.h"
#include <functional>
#include <vector>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;


char ReadSide(tcp::socket& socket) {
	boost::asio::streambuf buf;
	boost::asio::read_until(socket, buf, "\n");
	const char* side = boost::asio::buffer_cast<const char*>(buf.data());
	return *side;
}

void SendGameBoard(tcp::socket& socket, std::array<char, 9> board)
{
	std::vector<boost::asio::const_buffer> buffers;
	const char* s = "asd";
	for (int i = 0; i < board.size(); ++i)
		buffers.push_back(boost::asio::buffer(&board[i], sizeof(board[i])));
	buffers.push_back(boost::asio::buffer("\n"));
	boost::asio::write(socket, buffers);
}

int ReadMove(tcp::socket& socket)
{
	boost::asio::streambuf buf;
	boost::asio::read_until(socket, buf, "\n");
	auto move = boost::asio::buffer_cast<const int*>(buf.data());
	return *move;
}

int main()
{
	boost::asio::io_context io;

	tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 1234)); 
	tcp::socket socket(io);
	acceptor.accept(socket); 

	TicTacToe game;

	char side = ReadSide(socket);

	auto play_crosses = [&]
	{
		SendGameBoard(socket, game.getBoard());
		game.makeMove(ReadMove(socket), CROSSES);
		game.makeBestMove(NOUGHTS);
	};
	auto play_noughts = [&]
	{
		game.makeBestMove(CROSSES);
		SendGameBoard(socket, game.getBoard());
		game.makeMove(ReadMove(socket), NOUGHTS);
	};

	std::function<void()> play;
	if (side == 'x')
		play = play_crosses;
	else if (side == 'o')
		play = play_noughts;


	while (!game.gameOver())
	{
		play();
	}

	if(side == 'x')
	SendGameBoard(socket, game.getBoard());
}

