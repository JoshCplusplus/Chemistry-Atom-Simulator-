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
		cout << message << endl;
	}
	pair<string,string> get_pair(){
		return madeof;
	}
	molecule(string name1, string atom1, string atom2, double energy1,string newmessage){
		name = name1;
		madeof = make_pair(atom1,atom2);
		energy = energy1;
		message = newmessage;
	}
}h2("H2","H","H",20,"Hydrogen Bond Formed"),h2o("H2O","H2","O",286,"Water Created"); 


