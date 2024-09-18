//Imran Ahmed
//Project 2

#include <iostream>
#include<string>
#include "Payroll.h"
#include "binarySearchTree.h"
using namespace std;

void printByDepartment(const bSearchTreeType<Payroll>& obj, int department);
void runPayroll(const bSearchTreeType<Payroll>&obj, int department);
int main()
{
	int choice = 1, menuSelect = 0,employeeNumber=0,deptnum=0,hrs=0;
	string fname = "", lname = "",choice5="";
	double wage = 0;
	Payroll obj;
	bSearchTreeType<Payroll> treeobj;
	

	while (choice == 1)
	{
		cout << "Please select one of the following options: " << endl << "1. Insert Payroll Data" << endl << "2. Delete Payroll object from tree" << endl << "3. Search for employee data" << endl
			<< "4. Update Payroll information" << "5. Run Payroll" << endl << "6. Print all Payroll items" << endl << "7. Print a department Payroll list" << endl << "8. Exit" << endl;
		cin >> menuSelect;
		if (menuSelect == 1)
		{
			cout << "Please enter the following information:" << endl;
			cout << "Enter the employee's number: ";
			cin >> employeeNumber;
			cout << "Enter the employee's first name, followed by their last name: ";
			cin >> fname >> lname;
			cout << "Please enter the department number of the employee: ";
			cin >> deptnum;
			cout << "Please enter the hourly wage of the employee: ";
			cin >> hrs;
			cout << "Please enter total hours worked for the employee: ";
			cin >> wage;
			obj.readPayroll(employeeNumber, fname, lname, deptnum, wage,hrs);
			treeobj.insert(obj);
		}
		else if (menuSelect == 2)
		{
			cout << "Please enter the employee number you wish to delete: ";
			cin >> employeeNumber;
			obj.setEmployeeNumber(employeeNumber);
			if (treeobj.search(obj) == true)
			{
				treeobj.deleteNode(obj);
			}
		}
		else if (menuSelect == 3)
		{
			cout << "Please enter the employee number: ";
			cin >> employeeNumber;
			obj.setEmployeeNumber(employeeNumber);
			if (treeobj.search(obj)==true)
			{
				treeobj.inorderTraversal();
			}

			else
			{
				cout << "Information not found" << endl;
			}
		}
		else if (menuSelect == 4)
		{
			cout << "enter the employee number that you wish to update: " << endl;
			treeobj.search(obj);
			treeobj.deleteNode(obj);
		}
		else if (menuSelect == 5)
		{
			cout << "Do you wish to see employee information for a specific department? Indicate using Y or N: ";
			cin >> choice5;
			if (choice5 == "Y")
			{
				cout << "Please enter the department number: ";
				cin >> deptnum;
				printByDepartment(treeobj,deptnum);
			}
			else
			{
				cout << "Returning to Menu:" << endl << endl;
			}
		}
		else if (menuSelect == 6)
		{
			treeobj.treeNodeCount();
			cout << endl;
			treeobj.inorderTraversal();
			cout << endl;
		}

		else if (menuSelect == 7)
		{
			cout << "Please enter the department number you wish to see: ";
			cin >> deptnum;
			runPayroll(treeobj, deptnum);
		}
		else
		{
			choice = 2;
		}

	}


	return 0; 
}

void printByDepartment(const bSearchTreeType<Payroll>& obj, int department)
{
	obj.preorderTraversal(department);
}
void runPayroll(const bSearchTreeType<Payroll>& obj, int department)
{
	obj.preorderTraversalPayroll(department);
}