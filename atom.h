#include <vector>
#include <iostream>

using namespace std;


class atom{
	string newname;
int newAN;
	public:
	atom();
	atom(string,int);
	datom();
	string getname();
	int getAN();
	void setname(string);
	void setAN(int);
		

class molecule{
	string name;
	atom first;
	atom second;
	double energy;
	public:
	double get_energy(){
		return energy;
	}
	string get_name(){
		return name;
	}
	string get_first_name(){
		return first.get_name();
	}
	string get_second_name(){
		return second.get_name();
	}


	molecule(string name1, atom atom1, atom atom2, double energy1){
		name = name1;
		first = atom1;
		second = atom2;
		energy = energy1;
	}
};


