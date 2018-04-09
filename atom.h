#include <vector>
#include <iostream>

using namespace std;


class atom{
	string name;
};

class molecule{
	string name;
	atom first;
	atom second;
	double energy;
	public:
	double get_energy(){
		return energy;
	}
	molecule(string name1, atom atom1, atom atom2, double energy1){
		name = name1;
		first = atom1;
		second = atom2;
		energy = energy1;
	}
};


