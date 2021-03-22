#include "TicTacToe.hpp"
#include <limits>
#include <fstream>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void menu();
void start(TicTacToe &);
void options(TicTacToe &);
void insertrec(std::string ,std::string , double , double);
void printrec();

int main() {

	menu();

	return 0;
}

void menu(){
	TicTacToe obj;
	int n ;
	while (true) {
		cout << "\t\tTic Tac Toe\n\n";
		cout << "1) Play\n2) Options\n3) Print Game History\n4) Exit\n";
		do {
			cout << "--> : ";
			cin >> n;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (n <= 0 && n > 4);

		switch (n) {
			case 1:	start(obj); break;
			case 2: options(obj); break;
			case 3:	printrec(); break;
			case 4: return; break;
		}
	}
}

void insertrec(std::string str1 , std::string str2, double n1 , double n2) {
	std::ofstream fout("MyText.txt" ,std::ios::app);

	if (!fout.is_open()) {
		std::cerr << "File Error: Please Try Again!" << endl;
	}
	fout << str1 <<n1 << "] : [" << n2 <<str2 <<"$";

	fout.close();
}

void printrec() {
	std::ifstream file("MyText.txt", std::ios::in);

	if (!file.is_open()) {
		std::cerr << "File Error: Please Try Again!" << endl;
	}

	cout << "\t\t\t____Game History_____" << endl << endl;
	char x;
	while (!file.eof()) {
		file >> x;
		if (x == '$')
			cout << endl;
		else cout << x;
	}
	cout << endl;

	file.close();
	cout << "Enter any key to go back to menu --> : ";
	cin >> x;
}

void options(TicTacToe &obj) {
	cout << "\t\t\t____Game Options_____" << endl << endl;
	int c;
	cout << endl << "1) Size - 3x3\n2) Size - 4x4\n3) Size - 5x5\n";
	do {
		cout << "--> ";
		cin >> c;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (c <= 0 && c > 3);
	
	switch (c) {
		case 1:	c = 3; break;
		case 2: c = 4; break;
		case 3: c = 5; break;
	}

	obj.setsize(c);
}

void start(TicTacToe& obj) {
	obj.setnames();
	obj.makeMatrix();
	obj.setpt1(0);
	obj.setpt2(0);

	bool stat = true;

	while (stat) {
		obj.newboard();
		do {
			obj.board();
			obj.play();

			if (obj.checkwin() == 1) {
				std::string str;
				if (obj.getturn() == -1) {
					double temp = obj.getpt2();
					obj.setpt2(++temp);
					str = obj.getname2();
				}
				else {
					double temp = obj.getpt1();
					obj.setpt1(++temp);
					str = obj.getname1();
				}
				obj.board();
				cout << "Congratulations " << str << " ,You Win !!! " << endl;
				break;
			}
			else if (obj.checkwin() == 0) {
				double temp = obj.getpt1();
				temp += 0.5;
				obj.setpt1(temp);
				temp = obj.getpt2();
				temp += 0.5;
				obj.setpt2(temp);
				obj.board();
				cout << "Draw ! " << endl;
				break;
			}
		} while (obj.checkwin() == -1);
		char st;
		cout << "Do you want to play again : ( y / n ) --> : ";
		cin >> st;
		cout <<"\n\n\n";
		if (st == 'n') {
			if (obj.getpt1() > obj.getpt2()){
				cout << "\t\t\tCongrutalitons " << obj.getname1() << " Wins " << obj.getname2();
		       		cout << endl << "\t\t\t\tPoints -> " << obj.getpt1() << " : " << obj.getpt2() << endl;
			}
			else if (obj.getpt1() < obj.getpt2()){
				cout << "\t\t\tCongrutalitons " << obj.getname2() << " Wins " << obj.getname1() << endl;
		       		cout << "\t\t\t\tPoints -> " << obj.getpt2() << " : " << obj.getpt1() << endl;
			}
			else{
				cout << "\t\t\t The Game Ended Draw !" << endl;
		       		cout <<"\t\t\tPoints - > "<< obj.getname1()<<"  "<< obj.getpt1()<<" : "<<obj.getpt2()<<"  "<< obj.getname2()<<endl;
			}
			stat = false;
			std::string str1 = obj.getname1() + " [";
			std::string str2 = "] " + obj.getname2();
			insertrec(str1, str2 , obj.getpt1(), obj.getpt2());
			cout <<"\n\nEnter any key to go back to menu --> : ";
			cin >> st;
		}
	}
}
