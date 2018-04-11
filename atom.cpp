#include "atom.h"

atom::atom(){
newname="   ";
newAN= ' ';

}

atom::atom(string name, int AN){
newname = name;
newAN = AN;
}

atom::datom(){

}
string atom::getname(){
return newname;
}

int atom::getAN(){
return newAN;
}
void atom::setname(string name){
newname = name;
}
void atom:: setAN(int AN){
newAN = AN;
}
