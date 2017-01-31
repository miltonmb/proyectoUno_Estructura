#include "object.h"
#include "employee.h"
#include <sstream>
using namespace std;
employee::employee(){

}

employee::employee(string name, int age,double salary){
	this->name = name;
	this->age = age;
	this->salary = salary;
}

string employee::toString()const{
	stringstream ss;
	ss << "Name: "<< name;
	ss << endl; 
	ss << "Age: "<< age;
	ss << endl;
	ss << "Salary: "<<salary;
	return ss.str();
}

bool employee::equals(object* other)const{
	if(!dynamic_cast<employee*>(other)){
		return false;
	}
	employee* p = dynamic_cast<employee*>(other);
	return p-> name == name;
}

double employee::getSalary()const{
	return this->salary;
}
void employee::setSalary(double salary){
	this->salary = salary;
}