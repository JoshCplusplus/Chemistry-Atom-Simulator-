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
#include <unordered_map>
#include <unordered_set>
#include <boost/functional/hash.hpp>
using namespace std;

const int x_size = 31;
const int y_size = 15;
string board[y_size*x_size];

unordered_set <string> atomlist = {"H","C","O","Cl","F","N"};
unordered_map<pair<string,string>,molecule,boost::hash<pair<string,string>>> allmol({{h2o.get_pair(),h2o},{h2.get_pair(),h2}});
priority_queue <molecule> avmol;


bool operator<(molecule a, molecule b){
	if(a.get_energy() < b.get_energy()) return true;
	else return false;
}

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


/*bool check_atom(string atom){
	bool check = false;
	for(int i = 0; i < avmol.size(); i++){
		if(atom == *(&avmol.top()+i)) check = true;
	}
	if(allmol.find(atom) != allmol.end()) check = true;
	if(check) return true;
	else return false;

}*/

void sim_board(string obj1, string obj2){
	string mol = obj1 + obj2;
	system("clear");
	int pos1 = 217;
	int pos2 = 247;
	board[pos1] = obj1;
	board[pos2] = obj2;
	print_board();
	while(pos1 != pos2){
		board[pos1] = "*";
		board[pos2] = "*";
		board[++pos1] = obj1;
		board[--pos2] = obj2;
		if(pos1 == pos2) break;
		system("clear");
		print_board();
		cout << endl;
	}
	system("clear");
	board[pos1] = mol;
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
		cout << "Enter Atom2: ";
		cin >> name2;
		sim_board(name1, name2);
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
