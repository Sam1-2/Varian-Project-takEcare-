#include<iostream>
#include<stdio.h>
#include<string> // for string functions
#include<string.h> // for string functions
#include <algorithm> // for lower case and whitespace removal
#include <fstream> // for file handling
#include <conio.h> // for getch to ask to enter to continue
#include <ctime> // for generating random value more often



using namespace std;




class Patients
{

	string L_Name, F_Name, Gender;
	int Age;


	//friends:
	friend class Patient_Detail;
	friend ostream& operator<<(ostream& os, Patient_Detail& passenger);

public:

	void print_detail();
};








//Class for domestic flight option
class Flight
{


	string  Date, Time;
	int  total_cost, int_flight_type, time_choice;



public:

	//friends:
	friend class Passenger_Detail;



	


	
	void Get_Date();
	void Get_Time();

	

	//constructors and destructors
	Flight();
	~Flight();


};






class Patient_Detail : public Flight,  public Patients
{
	Patients p;
	string Email;
	string body_problem, pain,y_n;
	string username, password;

	unsigned long long int Phone_Number;
	
	
	friend void Verify_Patient();
	//friends:
	friend void Details_Check();
	friend ostream& operator<<(ostream& os, Patient_Detail& passenger);

public:

	void cost(int f_type);
	void Get_Detail();
	void Get_Age();
	void Get_Contact();
	void Get_Gender();
	void print(int i) { p.print_detail(); }
	
	void Get_Payment();

	//storing datas
	void Make_File();
	void Patient_Page();
	void Make_File_Patient();
	bool Verify_Pass_Patient();

	//constructors and destructors
	Patient_Detail();
	~Patient_Detail();


};





class ADMIN
{
	string username, password;

	//friends:
	friend void Verify_Admin();
	//friend void Verify_Patient();
	

public:

	//saving credentials into file
	void Make_File_Admin();
	//void Make_File_Patient();

	//verifying password
	bool Verify_Pass_Admin();


	//constructors and destructors
	ADMIN();
	~ADMIN();

};



//Menu options
void Menu();

//Menu further options
void Menu_Option_Select(int selection);

//Loading screen
void Loading_Screen(string& msg);


//Randomly generating pnr code
string char_pnr_rand();



//Checking for details according to pnr code
void Details_Check();



//Verifying admin details while printing all pnr codes
void Verify_Admin();
void Verify_Patient();


//Operator << overloading
ostream& operator<<(ostream& os, Patient_Detail& passenger);
ostream& operator<<(ostream& os, const string& string);


//deleting records
void Delete_Record();
//Due to exception handling
void Delete_Record_Function(string& rpnr);



//Operator Overloading + to add string and int
string operator+(string& a, int& b);

//listing all pnr codes in database [only for admins]
void List();


//password instructions
void pass_ins();


//special character viability
bool isSpecialCharater(char& a);

//Verifying the input date
bool Verify_Date(int year, int month, int day); 




void Patient_Page();
void Doctor_Page();
