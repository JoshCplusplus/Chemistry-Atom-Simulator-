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

using namespace std;

const int x_size = 31;
const int y_size = 15;
string board[y_size*x_size];

void print_board(){
	for(int i = 0; i < x_size*y_size; i++){
		if(i % 31 == 0 && i > 0) cout << endl;
		cout << board[i];
	}
	cout << endl;
	usleep(300000);
}
void sim_board(string obj1, string obj2){
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
	board[pos1] = "H2";
	print_board();
	cout << endl;

}

int main(){
	for(int i = 0; i < y_size*x_size; i++){
			board[i] = "*";
	}
//	print_board();
	sim_board("H", "H");
	/*	for(int i = 0; i <y_size; i++){
		for(int j =0; j < x_size; j++){
		cout << board[i][j];
		}
		cout << endl;
		}*/
}
