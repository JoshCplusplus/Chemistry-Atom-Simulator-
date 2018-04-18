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
  }
	void setname(string);
	void setAN(int);
  
		

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
}h2("H2","H","H",432,"Hydrogen Bond Formed"),h2o("H2O","H2","O",934,"Water Created"),o2("O2","O","O",204,"Oxygen Bond Formed"),co2("CO2","C","O2",716,"Carbon Dyoxide Formed"),no("NO","N","O",201,"Nitrogen Oxide Formed"),cl2("CL2","CL","Cl",242,"Chlorine Gas Formed"),n2("N2","N","N",163,"Nitrogen Gas Formed"),no2("NO2","N","O2",402,"Nitrogen Oxide Formed"),hf("HF","H","F",567,"Hydrogen Fluoride Formed");


