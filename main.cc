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
unordered_map<pair<string,string>,molecule,boost::hash<pair<string,string>>> allmol({{h2o.get_pair(),h2o},{h2.get_pair(),h2},{o2.get_pair(),o2},{co2.get_pair(),co2},{no.get_pair(),no},{cl2.get_pair(),cl2},{n2.get_pair(),n2},{no2.get_pair(),no2},{hf.get_pair(),hf}});
priority_queue <molecule> avmol;


bool operator<(molecule a, molecule b){
	if(a.get_energy() < b.get_energy()) return true;
	else return false;
}

void die(){
	system("clear");
	exit(0);
}
void fillvector(vector<atom>&);
void printvector(const vector<atom>&);
	
vector<atom> atoms;

void print_board(){
	for(int i = 0; i < x_size*y_size; i++){
		if(i % 31 == 0 && i > 0) cout << endl;
		cout << board[i];
	}
	cout << endl;
	usleep(300000);
}
string find_mol(string x, string y){
	auto i = allmol.find(make_pair(x,y));
	auto j = allmol.find(make_pair(y,x));
	if(i != allmol.end()) return i->second.get_name();
	else if(j != allmol.end()) return i->second.get_name();
	else return "0";
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

void sim_board(string obj1, string obj2, string molec){
	string mol = molec;
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
	fillvector(atoms);
	printvector(atoms);
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
			string mol_check;
			while(cin){
				while(cin){
					cout << "Enter Atom 1: ";
					cin >> name1;
					if(name1 == "q") die();
					if(name1.size() == 1) check = check_atom(name1);
					else check = check_mol(name1);
					if(check) break;
					else cout << "Invalid Atom/Molecule" << endl;
				}
				while(cin){
					cout << "Enter Atom2: ";
					cin >> name2;
					if(name2 == "q") die();
					if(name2.size() == 1) check = check_atom(name2);
					else check = check_mol(name2);
					if(check) break;
					else cout << "Invalid Atom/Moleculue" << endl;
				}
				mol_check = find_mol(name1,name2);
				if(mol_check == "0"){
					cout << "Bad pair of atoms/molecules" << endl;
				}
				else break;
			}
			sim_board(name1, name2,mol_check);

		}
		else if(choice ==2){
			printvector(atoms);
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

void fillvector(vector<atom>& newatoms){
string name;
int AN;
cout <<"How many atoms are in the table?"<<endl;
int tablesize;
cin>> tablesize;
for(int i = 0; i< tablesize;i++){
cout<<" enter atom name: "<<endl;
cin>> name;
cout<< "enter atom's atomic number: "<<endl;
cin>> AN;

atom newatom(name,AN);
newatoms.push_back(newatom);
}
cout<<endl;
}
void printvector(const vector<atom>& newatoms){
	unsigned int size= newatoms.size;
	for(int i=0;i<size,i++){
		cout<<" atom: "<< newatoms[i].getname()<<endl;
		cout <<" atomic number: "<<newatoms[i].getAN()<<endl;
		cout<< endl;
		
}
