#pragma once
#include "object.h"
#include <string>
using namespace std;
class employee: public object{
	string name;
	int age;
	double salary;

	public:
		employee();
		employee(string,int,double);
		virtual string toString()const;
		virtual bool equals(object*)const;
		double getSalary()const;
		void setSalary(double);
};



