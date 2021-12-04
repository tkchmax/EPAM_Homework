#include <iostream>
#include <string>
#include <boost/asio.hpp>


using namespace boost::asio;
using ip::tcp;


std::string cache_board;

void ShowBoard(const char* board)
{
	std::cout << "   1 2 3\n";
	std::cout << "  ______\n";
	std::cout << "c| " << board[6] << " " << board[7] << " " << board[8] << std::endl;
	std::cout << "b| " << board[3] << " " << board[4] << " " << board[5] << std::endl;
	std::cout << "a| " << board[0] << " " << board[1] << " " << board[2] << std::endl;
	std::cout << std::endl << std::endl;
}

std::string ChooseSide()
{
	std::string side;
	std::cout << "choose side(x/o): ";
	std::cin >> side;

	if (side != "x" && side != "o")
	{
		std::cout << "invalid side!\n";
		return ChooseSide();
	}
	return side;
}

void ReadGameBoard(tcp::socket& socket)
{
	boost::asio::streambuf board_buffer;
	boost::asio::read_until(socket, board_buffer, "\n");
	auto board = boost::asio::buffer_cast<const char*>(board_buffer.data());

	cache_board = board;

	ShowBoard(board);
}

int getMove()
{
	std::cout << "your move: ";
	std::string input;
	std::cin >> input;

	int y = (int)input[0] - 97; // a, b, c -> 0, 1, 2
	int x = (int)input[1] - 48 - 1; // char number code to int 

	if (y > 2 || x > 2 || y < 0 || x < 0 || cache_board[3 * y + x] != '-')
	{
		std::cout << "invalid move!\n";
		return getMove();
	}

	int move = 1 << (3 * y + x);

	return move;
}

void SendMove(tcp::socket& socket)
{
	int move = getMove();

	std::vector<boost::asio::const_buffer> buff;
	buff.push_back(boost::asio::buffer(&move, sizeof(move)));
	buff.push_back(boost::asio::buffer("\n"));
	boost::asio::write(socket, buff);

}

int main()
{
	boost::asio::io_service io;
	tcp::socket socket(io);
	socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));

	std::string side = ChooseSide();
	boost::asio::write(socket, boost::asio::buffer(side + "\n"));

	try
	{
		while (true)
		{
			ReadGameBoard(socket);
			SendMove(socket);
		}
	}
	catch (...) {}


}

