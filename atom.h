#include <vector>
#include <iostream>

using namespace std;

class molecule{
	string name;
	pair <string,string> madeof;
	double energy;
	string message;
	public:
	double get_energy() const{
		return energy;
	}
	string get_name() const{
		return name;
	}
	string get_message(){
		return message;
	}
	pair<string,string> get_pair(){
		return madeof;
	}
	molecule(){
		name = "BAD";
	}
	molecule(string name1, string atom1, string atom2, double energy1,string newmessage){
		name = name1;
		madeof = make_pair(atom1,atom2);
		energy = energy1;
		message = newmessage;
	}
}h2("H2","H","H",432,"Hydrogen Bond Formed"),h2o("H2O","H2","O",459,"Water Created"),o2("O2","O","O",142,"Oxygen Bond Formed"); 


