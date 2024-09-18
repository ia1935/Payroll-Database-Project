//Header file Payroll Class
#ifndef H_Payroll
#define H_Payroll

#include <iostream>
#include <string>
using namespace std;

class Payroll
{
private:
	int employeeNumber,deptNumber,hoursWorked;
	string firstName, lastName;
	double payRate, payAmount;
public:
	Payroll()
	{
		employeeNumber = 0;
		firstName = "";
		lastName = "";
		deptNumber = 0;
		payRate = 0;
		hoursWorked = 0;
		payAmount = 0;
	}
	Payroll(int empNum, string fName, string lName, int deptNum, double pRate, int hrsWork)
	{
		employeeNumber = empNum;
		firstName = fName;
		lastName = lName;
		deptNumber = deptNum;
		payRate = pRate;
		hoursWorked = hrsWork;

	}
	void setEmployeeNumber(int empnum)
	{
		employeeNumber = empnum;
	}
	void setFirstName(string fname)
	{
		firstName = fname;	
	}
	void setLastName(string lname)
	{
		lastName = lname;
	}
	void setDepartmentNumber(int deptnum)
	{
		deptNumber = deptnum;
	}
	void setPayRate(double payrate)
	{
		payRate = payrate;
	}
	void setHoursWorked(int hrswork)
	{
		hoursWorked = hrswork;
	}
	int getEmployeeNumber()
	{
		return employeeNumber;
	}
	string getFirstName()
	{
		return firstName;
	}
	string getLastName()
	{
		return lastName;
	}
	int getDepartmentNumber()
	{
		return deptNumber;
	}
	double getPayRate()
	{
		return payRate;
	}
	int getHoursWorked()
	{
		return hoursWorked;
	}
	void printPayroll()const
	{
		cout << "Employee Number: " << employeeNumber << endl << "Name: " << firstName << " " << lastName << endl << "Department Number: " << deptNumber << endl << "Pay Rate: " << payRate << endl << "Hours: " << hoursWorked
			<< endl << "Pay Amount: " << payAmount << endl;
	}
	double calculatePay()
	{
		payAmount = payRate * hoursWorked;
		return payAmount;
	}
	void readPayroll(int empNum, string fName, string lName, int deptNum, double pRate, int hrsWork)
	{
		employeeNumber = empNum;
		firstName = fName;
		lastName = lName;
		deptNumber = deptNum;
		payRate = pRate;
		hoursWorked = hrsWork;
		payAmount = pRate*hrsWork;
	}
	bool operator>(const Payroll& obj) const
	{
		return ( obj.employeeNumber>employeeNumber);
	}
	bool operator<(const Payroll& obj) const
	{
		return (obj.employeeNumber < employeeNumber);
	}
	friend ostream& operator<<(ostream& os, const Payroll& obj)
	{
		os << "Employee Number: " << obj.employeeNumber << endl << "Name: " << obj.firstName << " " << obj.lastName << endl << "Department Number: " << obj.deptNumber << endl << "Hours Worked: " << obj.hoursWorked <<
			endl << "Pay: " << obj.payAmount << endl;
		return os;
	}
	bool operator==(const Payroll& obj)const
	{
		return (obj.employeeNumber == employeeNumber);
	}

};
















#endif