#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <string>

class TicTacToe
{
public:
	TicTacToe();
	~TicTacToe();
	void board();
	void newboard();
	void makeMatrix();
	void play();
	int checkwin();
	void setsize(int sz);
	void setpt1(double pt);
	void setpt2(double pt);
	void setnames();
	double getpt1();
	double getpt2();
	int getturn();
	std::string getname1();
	std::string getname2();
private:
	int *square;
	int size;
	int turn;
	double pt1, pt2;
	std::string pl1, pl2;
};

#endif
