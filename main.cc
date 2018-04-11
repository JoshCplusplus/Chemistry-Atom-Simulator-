#include <iostream>
#include <algorithm>
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
int tot_energy = 0;

unordered_set <string> atomlist = {"H","C","O","Cl","F","N"};
unordered_map<pair<string,string>,molecule,boost::hash<pair<string,string>>> allmol({{h2o.get_pair(),h2o},{h2.get_pair(),h2},{o2.get_pair(),o2}});
priority_queue <molecule> avmol;


bool operator<(molecule a, molecule b){
	if(a.get_energy() < b.get_energy()) return true;
	else return false;
}

void die(){
	system("clear");
	exit(0);
}

void print_atoms(){
	cout << "\nAvailable Atoms:" << endl;
	for(string s: atomlist){
		cout << s << endl;
	}
	cout << "\nAvailable Molecules:" << endl;
	if(avmol.size() == 0) cout << "NONE" << endl;
	else{
		for(int i = 0; i < avmol.size(); i++){
			cout << (*(&avmol.top() + i)).get_name() << endl;
		}
	}
	cout << "\nAll Moleclues:" << endl;
	for(auto i : allmol){
		cout << i.second.get_name() << endl;
	}
	cout << endl;
}

void print_board(){
	for(int i = 0; i < x_size*y_size; i++){
		if(i % 31 == 0 && i > 0) cout << endl;
		cout << board[i];
	}
	cout << endl;
	usleep(300000);
}
molecule find_mol(string x, string y){
	molecule temp;
	auto i = allmol.find(make_pair(x,y));
	auto j = allmol.find(make_pair(y,x));
	if(i != allmol.end()) return i->second;
	else if(j != allmol.end()) return i->second;
	else return temp;
}
bool check_mol(string mol){
	for(int i = 0; i < avmol.size(); i++){
		if((*(&avmol.top() + i)).get_name() == mol) return true;
	}
	return false;
}
bool check_atom(string atom){
	if(atomlist.find(atom) != atomlist.end()) return true;
	else return false;

}

void sim_board(string obj1, string obj2, molecule molec){
	string mol = molec.get_name();
	avmol.push(molec);
	tot_energy += molec.get_energy();
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
	cout << molec.get_message() << endl;
	cout << "\nTotal Energy(Kj/mol): " << tot_energy << "  H.E.M: " << avmol.top().get_name() << endl;

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
			bool check;
			molecule mol_check;
			while(cin){
				while(cin){
					cout << "Enter Atom 1: ";
					cin >> name1;
					for(auto& c: name1) c = toupper(c);
					if(name1 == "Q") die();
					if(name1.size() == 1) check = check_atom(name1);
					else check = check_mol(name1);
					if(check) break;
					else cout << "Invalid Atom/Molecule" << endl;
				}
				while(cin){
					cout << "Enter Atom2: ";
					cin >> name2;
					for(auto & c: name2) c = toupper(c);
					if(name2 == "Q") die();
					if(name2.size() == 1) check = check_atom(name2);
					else check = check_mol(name2);
					if(check) break;
					else cout << "Invalid Atom/Moleculue" << endl;
				}
				mol_check = find_mol(name1,name2);
				if(mol_check.get_name() == "BAD"){
					cout << "Bad pair of atoms/molecules" << endl;
				}
				else break;
			}
			sim_board(name1, name2,mol_check);

		}
		else if(choice ==2){
			//print list of available atoms/moleculues	
			print_atoms();
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
