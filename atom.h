#include <vector>
#include <iostream>

using namespace std;

class molecule{
	string name;
	string first;
	string second;
	double energy;
	string message;
	public:
	double get_energy(){
		return energy;
	}
	string get_name(){
		return name;
	}
	string get_first(){
		return first;
	}
	string get_second(){
		return second;
	}
	string get_message(){
		cout << message << endl;
	}

	molecule(string name1, string atom1, string atom2, double energy1,string newmessage){
		name = name1;
		first = atom1;
		second = atom2;
		energy = energy1;
		message = newmessage;
	}
}h2("H2","H","H",20,"Hydrogen Bond Formed"),h2o("H2O","H2","O",286,"Water Created"); 

