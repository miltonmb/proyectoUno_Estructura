#include "employee.h"
#include "ADTList.h"
#include "LinkedList.h"
#include "object.h"
#include <iostream>
#include <exception>
#include <stdlib.h>
using namespace std;
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
 
#define CLEAR "\033[2J"  // clear screen escape code 

int main(){
	ADTList* list = new LinkedList();
	char answer ='y';
	int option;
	//ciclo con respuesta de usuario
	while(answer == 'Y' || answer == 'y'){
		try{
			cout<<RED<<"--WELCOME--"<<RESET<<endl;
			cout<<GREEN<<"What do you want to do?"<<endl;
			cout<<"1-Add employee"<<endl;
			cout<<"2-List employees"<<endl;
			cout<<"3-Average salary"<<endl;
			cout<<"4-Highest salary"<<endl;
			cout<<"5-Lowest salary"<<endl;
			cout<<"6-Inflation adjustment"<<endl;
			cout << RESET<<endl;
			cout<<"your Input: ";
			cin >> option;
		}catch(exception& e){
			cout << e.what()<<endl;
		}
		//inicio switch
		switch(option){

			//inicio case 1
			case 1:{
				try{
					string name;
					int age;
					double salary;
					int pos;
					cout <<RED<< "--ADD EMPLOYEE--"<<RESET<<endl;
					cout <<GREEN<<endl;
					cout << "Input employee's name: ";
					cin >> name;
					cout << "Input employee's age: ";
					cin >> age;
					cout << "Input employee's salary: ";
					cin >> salary;
					cout <<RESET;
					cout << "Input position: ";
					cin >> pos;
					employee* emp = new employee(name,age,salary);
					if(list->insert(emp,pos)){
						cout << "Complete!"<<endl;
					}else{
						cout << "An error has ocurred"<<endl;
					}
				}catch(exception& e){
					cout << e.what()<<endl;
				}
				cout << CLEAR; 
				break;
			}
			//fin case 1

			//inicio case 2
			case 2:{
				try{
					cout << CLEAR;
					cout <<RED<< "--LIST EMPLOYEES--"<<RESET<<endl;
					for (int i = 0; i < list->Size();++i){
						cout <<GREEN<<i<< " -- " << list->get(i)->toString()<<endl;
					}
					cout << RESET;
				}catch(exception& e){
					cout << e.what()<<endl;
				}
				break;
			}
			//fin case 2

			//inicio case 3
			case 3:{
				try{
					cout << CLEAR;
					employee* temp;
					double salary=0;
					int cont=0;
					double AverageSalary=0;
					cout <<RED<< "--AVERAGE SALARY--"<<RESET<<endl;
					for (int i = 0; i < list->Size(); ++i){
						if(dynamic_cast<employee*>(list->get(i))){
							temp = dynamic_cast<employee*>(list->get(i));
							salary += temp->getSalary();
							cont++;
						}
					}
					AverageSalary = salary/cont;
					cout <<GREEN<< "The Average salary is: "<<RESET<<BLUE<<AverageSalary<<RESET<<endl;
				}catch(exception& e){
					cout << e.what()<<endl;
				}
				break;
			}
			//fin case 3

			//inicio case 4
			case 4:{
				try{
					cout << CLEAR;
					employee* h_salary;
					double highest_salary=0;
					double temp_salary=0;
					cout <<RED<< "--HIGHEST SALARY--"<<RESET<<endl;
					for (int i = 0; i < list->Size(); ++i){
						if(dynamic_cast<employee*>(list->get(i))){
							h_salary = dynamic_cast<employee*>(list->get(i));
							temp_salary = h_salary->getSalary();
							if(temp_salary > highest_salary){
								highest_salary = temp_salary;
							}
						}
					}
					cout <<GREEN<< "The highest salary is: "<<RESET<<BLUE<<highest_salary<<RESET<<endl;

				}catch(exception& e){
					cout << e.what()<<endl;
				}
				break;
			}
			//fin case 4

			//inicio case 5
			case 5:{
				try{
					cout << CLEAR;
					employee* l_salary;
					double lowest_salary=dynamic_cast<employee*>(list->get(0))->getSalary();
					double temp2_salary=0;
					cout <<RED<< "--LOWEST SALARY--"<<RESET<<endl;
					for (int i = 1; i < list->Size(); ++i){
						if(dynamic_cast<employee*>(list->get(i))){
							l_salary = dynamic_cast<employee*>(list->get(i));
							temp2_salary = l_salary->getSalary();
							if(temp2_salary < lowest_salary){
								lowest_salary = temp2_salary;
							}
						}
					}
					cout <<GREEN<< "The lowest salary is: "<<RESET<<BLUE<<lowest_salary<<RESET<<endl;

				}catch(exception& e){
					cout << e.what()<<endl;
				}
				break;
			}
			//fin case 5

			//inicio case 6
			case 6:{
				try{
					cout << CLEAR;
					double inflation_percentage, inflation_salary;
					employee* temp_inflation;
					cout <<RED<< "--INFLATION ADJUSTMENT--"<<RESET<<endl;
					cout << "Input inflation percentage: ";
					cin >> inflation_percentage;
					if(inflation_percentage>0){
						inflation_percentage = inflation_percentage/100;
						for (int i = 0; i < list->Size(); ++i){
							if(dynamic_cast<employee*>(list->get(i))){
								temp_inflation = dynamic_cast<employee*>(list->get(i));
								inflation_salary = temp_inflation->getSalary()*inflation_percentage;
								dynamic_cast<employee*>(list->get(i))->setSalary(inflation_salary+temp_inflation->getSalary());
							}
						}
						cout <<GREEN<<"Complete!"<<RESET<<endl;
					}
				}catch(exception& e){
					cout << e.what()<<endl;
				}
				break;
			}
			//fin case 6
		}
		//fin switch
		cout << "CONTINUE[Y/N]?: ";
		cin >> answer;
	}
	//fin while

	//liberar memoria
	for (int i = 0; i < list->Size(); ++i){
	 	list->remove(i);
	 }
	 delete list;
	 cout <<RED<< "BAI BAI!"<<RESET<<endl; 
	return 0;
}
