#include "TicTacToe.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using std::cout;
using std::cin;
using std::endl;

TicTacToe::TicTacToe()
{
	pt1 = pt2 = 0;
	turn = -1;
	size = 3;
}

void TicTacToe::board()
{
	cout << "\t\tTic Tac Toe\n\n";

	cout << "Player 1 (X)" << std::setw(25) << " Player 2 (O)" << endl << endl;
	cout << pl1 << std::setw(25) << pl2 << endl;
	cout << "Points : " << pt1 << std::setw(23) << "Points : " << pt2 << endl << endl;

	for (int i = 0; i < size; i++) {
		if (i == size - 1)
			cout << "      ";
		else cout << "     |";
	}
	cout << endl;

	cout << "  ";
	for (int i = 0; i < size*size; i++) {
		if (square[i] == -1) {
			if ((i + 1) % size == 0)
				cout << std::setw(1) << 'X';
			else
				cout << std::setw(1) << 'X' << "  |  ";
		}
		else if (square[i] == -2) {
			if ((i + 1) % size == 0)
				cout << std::setw(1) << 'O';
			else
				cout << std::setw(1) << 'O' << "  |  ";
		}
		else {
			if ((i + 1) % size == 0)
				cout << std::setw(1) << square[i];
			else if (i < 9) {
				cout << std::setw(1) << square[i] << "  |  ";
			}
			else {
				cout << square[i] << " |  ";
			}
		}
		if ((i + 1) % size == 0) {
			cout << endl;
			if (i != size * size - 1) {
				for (int i = 0; i < size; i++) {
					if (i != size - 1)
						cout << "_____|";
					else cout << "_____" << endl;
				}
				for (int i = 0; i < size; i++) {
					if (i != size - 1)
						cout << "     |";
					else cout << "	  " << endl;
				}
				cout << "  ";
			}
			else {
				for (int i = 0; i < size; i++) {
					if (i == size - 1)
						cout << "      ";
					else cout << "     |";
				}
				cout << endl << endl;
			}
		}
	}
}

void TicTacToe::newboard()
{
	for (int i = 1; i <= size*size; i++) {
		square[i - 1] = i;
	}
	turn = -1;
}

void TicTacToe::makeMatrix() {
	square = new int[size*size];
}

void TicTacToe::play()
{
	int temp;
	do {
		if (turn == -1)
			cout << "Your turn " << pl1 << " : ";
		else
			cout << "Your turn " << pl2 << " : ";

		if (cin >> temp) {
			if (square[temp - 1] != -1 && square[temp - 1] != -2) {
				square[temp - 1] = turn;
			}
			else {
				temp = 0;
			}
		}
		else {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (temp < 1 || temp > size*size);

	if (turn == -1)
		turn = -2;
	else {
		turn = -1;
	}
}

int TicTacToe::checkwin()
{
	bool win;
	for (int i = 0; i < size*size; i+=size) {
		win = true;
		for (int j = i; j < i + size; j++) {
			if (square[i] != square[j]) {
				win = false;
				break;
			}
		}
		if (win)
			return 1;
	}

	for (int i = 0; i < size; i++) {
		win = true;
		for (int j = i + size; j < size*size; j += size) {
			if (square[i] != square[j])
			{
				win = false;
				break;
			}
		}
		if (win)
			return 1;
	}

	int temp = 0;
	win = true;
	for (int i = 0; i < size*size; i += (size + 1)) {
		if(square[i] == square[temp])
			temp = i;
		else {
			win = false;
			break;
		}
	}
	if (win)
		return 1;

	temp = size-1;
	win = true;
	for (int i = size-1; i < size*size-1; i += (size - 1)) {
		if (square[i] == square[temp])
			temp = i;
		else {
			win = false;
			break;
		}
	}
	if (win)
		return 1;

	bool draw = true;
	for (int i = 0; i < size*size; i++) {
		if ((i + 1) == square[i]) {
			draw = false;
			break;
		}
	}

	if (draw)
		return 0;
	
	return -1;
}

void TicTacToe::setsize(int sz)
{
	size = sz;
}

void TicTacToe::setpt1(double pt)
{
	pt1 = pt;
}

void TicTacToe::setpt2(double pt)
{
	pt2 = pt;
}

void TicTacToe::setnames()
{
	cout << "Enter your name (Player 1) --> : ";
	cin >> pl1;
	cout << "Enter your name (Player 2) --> : ";
	cin >> pl2;
}

double TicTacToe::getpt1()
{
	return pt1;
}

double TicTacToe::getpt2()
{
	return pt2;
}

int TicTacToe::getturn()
{
	return turn;
}

std::string TicTacToe::getname1()
{
	return pl1;
}

std::string TicTacToe::getname2()
{
	return pl2;
}

TicTacToe::~TicTacToe() {
	delete[] square;
}
