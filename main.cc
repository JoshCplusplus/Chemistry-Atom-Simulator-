#include <iostream>
#include <unistd.h>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <ncurses.h>
#include <utility>
#include <limits>
#include <vector>
#include <queue>
#include <set>
#include "atom.h"
using namespace std;

const int x_size = 31;
const int y_size = 15;
string board[y_size*x_size];

void die(){
	system("clear");
	exit(0);
}

void print_board(){
	for(int i = 0; i < x_size*y_size; i++){
		if(i % 31 == 0 && i > 0) cout << endl;
		cout << board[i];
	}
	cout << endl;
	usleep(300000);
}
void sim_board(atom obj1, atom obj2){
	string mol = obj1.get_name() + obj2.get_name();
	system("clear");
	int pos1 = 217;
	int pos2 = 247;
	board[pos1] = obj1.get_name();
	board[pos2] = obj2.get_name();
	print_board();
	while(pos1 != pos2){
		board[pos1] = "*";
		board[pos2] = "*";
		board[++pos1] = obj1.get_name();
		board[--pos2] = obj2.get_name();
		if(pos1 == pos2) break;
		system("clear");
		print_board();
		cout << endl;
	}
	system("clear");
	board[pos1] = obj1.get_name() + "2";
	print_board();
	board[pos1] = "*";
	cout << endl;

}

int main(){
	system("clear");
	for(int i = 0; i < y_size*x_size; i++){
			board[i] = "*";
	}
//	print_board();
	cout << "Welcome to Chemistry Simulation, Enter your choice: " << endl;
	int choice;
	while(true){
		cout << "1)Simulate atoms" << endl;
		cout << "2)Check list of available atoms/molecules" << endl;
		cout << "3)Quit" << endl;
		cin >> choice;
		if(choice == 1){
		string name1, name2;
		cout << "Enter Atom 1: ";
		cin >> name1;
		if(name1 == "q") die();
		atom atom1(name1);
		cout << "Enter Atom2: ";
		cin >> name2;
		if(name2 == "q") die();
		atom atom2(name2);
		sim_board(atom1, atom2);
		}
		else if(choice ==2){
			//print list of available atoms/moleculues	
		}
		else if(choice == 3){
			die();
		}
	}
	/*	for(int i = 0; i <y_size; i++){
		for(int j =0; j < x_size; j++){
		cout << board[i][j];
		}
		cout << endl;
		}*/
}
