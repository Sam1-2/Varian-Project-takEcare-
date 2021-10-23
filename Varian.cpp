#include "Varian.h"
#include<Windows.h> // Used in sleep in loading screen


//will be using getline(cin, str) most of the timese because in normal cases input as "a a asd" doesnt work properly

//Due to cin.ignore problem while taking input in getline() function

//check_getline used  ==>> In Details_Check() function
//                                 ==>> In Get_Date() function
//                                 ==>> In Delete_Record() function
//                                 ==>> In Menu_Option_Select() function
//                                 ==>> In Get_Flight_Info() function
//                                 ==>> In Get_Payment() function

int check_getline = 0, wrong_pnr = 0, wrong_user = 0;




void Menu_Head()
{
	cout << endl << endl;
	cout << "\n\n\t\t\t\t********************" << endl;
	cout << "\t\t\t\t\tMenu" << endl;
	cout << "\t\t\t\t********************" << endl;
}


void Loading_Screen(string& msg)
{
	system("color 0e");
	char a = 177, b = 219;
	cout << endl << msg << endl;
	cout << "\r";
	cout << "\t\t\t\t";
	for (int i = 0; i <= 25; i++)
	{
		cout << a;
		Sleep(50);
	}
	cout << "\r";
	cout << "\t\t\t\t";
	for (int i = 0; i <= 25; i++)
	{
		cout << b;
		Sleep(50);
	}


}





void Menu()
{
	//when menu is called from the Details_check()
	wrong_pnr = 0;
	check_getline = 0;
	wrong_user = 0;

	cout << "\t\t\t****************************************" << endl;
	cout << "\t\t\t\t*******takE-care*******" << endl;
	cout << "\t\t\t****************************************" << endl;
	cout << endl << "\t\t\t\tTogether we can fight cancer" << endl;

	string msg = "\t\t\t\t--A product by Variance......";
	Loading_Screen(msg);
	

	cout << endl << endl;
	cout << "\n\n\t\t\t\t********************" << endl;
	cout << "\t\t\t\t\tMenu" << endl;
	cout << "\t\t\t\t********************" << endl;

	cout << "\t\t\t\t1) Follow-Up Log In" << endl;
	cout << "\t\t\t\t2) Health-Care Team Log In" << endl;
	cout << "\t\t\t\t3) News Feed" << endl;
	cout << "\t\t\t\t4) Learn About Cancer" << endl;
	cout << "\t\t\t\t5) Quit" << endl;

	cout << endl << endl;


	int opt;
	cout << "\t\t\t\t>> Select : ";
	cin >> opt;

	//If  any character is input for opt
	if (cin.fail())
	{
		cin.clear();
		system("CLS");
		string junk = "";
		getline(cin, junk);
		cout << endl << "\t\t\tWrong Menu option selected. Please try again" << endl << endl;
		return Menu();

	}
	/*getchar();*/
	Menu_Option_Select(opt);
}


void Menu_Option_Select(int selection)
{
	check_getline = 0; // to ignore the first geetline error

	switch (selection)
	{


	case 1:
	{
	
		string answer;
		system("CLS");
		check_getline = 0;


		



		do
		{
			if (check_getline == 0) cin.ignore();
			cout << endl << "\t\t\t\tDo you have an USER account?" << endl;
			cout << "\t\t\t\t1) Yes I have an account" << endl;
			cout << "\t\t\t\t2) No, I would Like to Create an USER account" << endl << endl;
			cout << "\t\t\t\tSelect : ";
			check_getline++;
			getline(cin, answer);
		} while (answer < "1" || answer > "2" || answer.length() > 1);


		if (answer == "1")
		{
			Verify_Patient();
		}

		else if (answer == "2")
		{
			Patient_Detail user1;
			user1.Get_Detail();
			
			//user1.Make_File();


			//ADMIN admin;
			//admin.Make_File_Patient();
		}

	}

	case 2:
	{
		string answer;
		system("CLS");
		check_getline = 0;

		do
		{
			if (check_getline == 0) cin.ignore();
			cout << endl << "\t\t\t\tDo you have an Doctors account?" << endl;
			cout << "\t\t\t\t1) Yes I have an account" << endl;
			cout << "\t\t\t\t2) No, I would Like to Create an Doctors account" << endl << endl;
			cout << "\t\t\t\tSelect : ";
			check_getline++;
			getline(cin, answer);
		} while (answer < "1" || answer > "2" || answer.length() > 1);


		if (answer == "1")
		{
			Verify_Admin();
		}

		else if (answer == "2")
		{
			ADMIN admin;
			admin.Make_File_Admin();
		}
	}


	case 3:
	{
		cout << "\t\t\t\tNews Feed" << endl;

		cout << "\t\t\t\tPress Enter to Continue....";
		_getch();

		system("CLS");
		cout << endl << endl;
		return Menu();
		break;
	}

	case 4:
	{

		cout << "\t\t\t\tLearn About Cancer!!" << endl;

		cout << "\t\t\t\tPress Enter to Continue....";
		_getch();

		system("CLS");
		cout << endl << endl;
		return Menu();
		break;

	}






	case 5:
	{
		cout << endl << "\t\t\t\tThank you for being with US" << endl;
		cout << "\t\t\t\t========We wish you a Healthy Day======" << endl;
		exit(0);
		cout << endl << endl;
	}


	default:
	{
		system("CLS");
		cin.ignore(10, '\n');
		cout << endl << "\t\t\tWrong Menu option selected. Please try again" << endl << endl;
		return Menu();
	}

	}

}












//#######   Passenger_Detail class functions   #######//








void Patient_Detail::Get_Detail()
{

		cout << endl;
		cout << "\t\t\t\t>>Please Enter Your First Name : ";
		cin.ignore();
		getline(cin, p.F_Name);
		cout << endl;

		cout << "\t\t\t\t>>Please Enter Your Last Name : ";
		getline(cin, p.L_Name);
		cout << endl;

		Get_Gender();
		Get_Age();
	
	Get_Contact();


}









//Getting Gender
void Patient_Detail::Get_Gender()
{
	int choice, x = -1;
	cout << "\t\t\t\t>>Please Enter Your Gender : " << endl << endl;
	cout << "\t\t\t\t   1) Male" << endl << "\t\t\t\t   2) Female" << endl << "\t\t\t\t   3) Other" << endl << endl << endl;
	cout << "\t\t\t\t>>Select : ";
	cin >> choice;
	cout << endl;


	try {
		if (choice < 1 || choice > 3 || cin.fail()) throw x; // condition for 1 2 or 3 and error if character or array is input

		else
		{
			if (choice == 1) p.Gender = "Male";
			else if (choice == 2) p.Gender = "Female";
			else if (choice == 3) p.Gender = "Other";
		}
	}

	catch (int x)
	{
		cout << endl << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << endl;
		cout << "\t\t\t\tYou have entered a wrong Gender Type. Please Try Again!!" << endl << endl;
		return Get_Gender();
	}

}








void Patient_Detail::Get_Age()
{
	int x = -1;
	cout << "\t\t\t\t>>Please Enter Your Age : ";
	cin >> p.Age;

	try
	{
		if (p.Age < 18 || cin.fail()) throw x; // In case passenger is alone . Will write again for group booking
	}

	catch (int x)
	{
		cout << endl << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << endl << "\t\t\t\tSorry. You need to be atleast 18 to fly. If you have made a mistake, please enter again" << endl << endl;
		Get_Age();
	}

}



void Patient_Detail::Get_Contact()
{

	cout << endl;
	cout << "\t\t\t\tContact Informations => ";

	cout << endl << endl;
	cout << "\t\t\t\t>>Please Enter a valid Email Address : ";



	while (getline(cin, Email))
	{
		if (Email.empty())
		{
			continue;
		}
		else
			break;
	}
	cout << endl;

	//removing blank spaces
	Email.erase(remove(Email.begin(), Email.end(), ' '), Email.end());

	// converting string to back to lower case
	for_each(Email.begin(), Email.end(), [](char& c)
		{
			c = ::tolower(c);
		});



	size_t found = Email.find(".com");
	size_t found2 = Email.find("@");

	if (found == string::npos || found2 == string::npos)
	{
		cout << endl;
		cout << "\t\t\t\tYou have entered a wrong email address. E.g. xyz@yahoo.com" << endl << endl;
		return Get_Contact();
	}



	cout << "\t\t\t\t>>Please Enter your Phone Number : ";
	cin >> Phone_Number;


	//ADMIN admin;
	//admin.Make_File_Patient();
	Make_File_Patient();

}







//Operator overloading
ostream& operator<<(ostream& os, Patient_Detail& passenger)
{

	//Just for Fun
	string msg = "\t\t\t\tPlease wait while the server saves your details......";
	Loading_Screen(msg);
	string msg1 = "\t\t\t\tPrinting Entered Data....";
	Loading_Screen(msg1);

	cout << endl << endl;
	cout << "\t\t\t\t>>Entered Details : " << endl << endl;



	cout << endl << endl << "\t\t\t\t>>Contact Info : " << endl << "\t\t\t\t" << endl;

	os << "\t\t\t\tEmail Address : " << passenger.Email << endl;
	os << "\t\t\t\tPhone Number : " << passenger.Phone_Number << endl << endl;
	return os;
}





//Operator << overloading to print out string
ostream& operator<<(ostream& os, const string& string)
{
	for (int i = 0; i < string.length(); i++)
	{
		os << string[i];
	}
	return os;
}






//Printing details from passengers class
void Patients::print_detail()
{
	cout << "\t\t\t\tFull Name : " << F_Name << " " << L_Name << endl;
	cout << "\t\t\t\tAge : " << Age << endl;
	cout << "\t\t\t\tGender : " << Gender << endl;
}



//#######   Flight class functions   #######//








//#######   File Handling functions   #######//


//Saving data in a txt file which is readable easily
void Patient_Detail::Make_File()
{
	ofstream my_file;

	my_file.open("domestic flight.txt", ios::binary | ios::app);

	if (my_file.is_open())
	{
		my_file << "Patient Details ~";
	

			
			my_file << "Full Name : " << p.F_Name << " " << p.L_Name << "." << "Gender : " << p.Gender << "." << "Age : " << p.Age << ".";

		

		my_file << ">Contact Informations =>";
		my_file << "Email Address : " << Email << "." << "Phone Number : " << Phone_Number << ".";
		my_file << ">Health Details =>";
		my_file << "Body : " << body_problem << "." << "Pain : " << pain << "." << "Fever : " << y_n << "."<< endl << endl;

	}
	else cout << "File opening Failed!" << endl;

	my_file.close();
}





//Deleting a record based on the given pnr code
void Delete_Record()
{
	int c = 0, x = -1;
	string rpnr = "";




	try
	{
		if (wrong_pnr > 4)
		{
			cout << endl << endl << "\t\t\t\tYou have tried many times" << endl;
			cout << endl << "\t\t\t\tIt is possible that you have lost the pnr code. Contact our customer service center." << endl;
			cout << endl << "\t\t\t\tWe will take you back to the Main Menu now" << endl;
			cout << endl << endl << "\t\t\t\tPress any key to continue.........";
			_getch();

			system("CLS");
			cout << endl << endl;
			Menu();
		}
		cout << "\t\t\t\t>> Please Enter a valid pnr code of your fight : ";
		if (check_getline == 0) cin.ignore();
		getline(cin, rpnr);
		cout << endl;
		check_getline++;
		Delete_Record_Function(rpnr);
	}

	catch (int x)
	{
		Delete_Record();
	}

	check_getline = 0; //essential to set this to zero before exiting the function
	wrong_pnr = 0;
}




//Due to exception handling
void Delete_Record_Function(string& rpnr)
{
	if (rpnr.length() < 5 || rpnr.length() > 6) throw - 1;

	else
	{
		rpnr = " " + rpnr + "."; // adding white space in front and fullstop at end to identify specifically
		int f = 0, p = 0;
		string line, line2;
		ifstream my_file, fout;
		ofstream tmpfile;


		//Printing the matched pnr code
		fout.open("domestic flight.txt", ios::binary);//opening file............., ios::in | ios::out | ios::binary


		while (getline(fout, line2))
		{
			if (line2.find(rpnr) != string::npos)//checking pnr
			{

				string msg = "\t\t\t\tPlease wait while the server searches for your details......";
				Loading_Screen(msg);
				string msg1 = "\t\t\t\tPrinting Matched Data....";
				Loading_Screen(msg1);
				cout << endl << endl;

				cout << "\t\t\t\t";
				for (int i = 0; i < line2.length(); i++)
				{

					cout << line2[i];    //display details

					if ((line2[i] == '.' && line2[i + 1] != 'c') || (line2[i] == '.' && line2[i + 1] == '>') || line2[i] == '~' || line2[i] == '>')
					{
						if (line2[i] == '~') cout << endl;
						else if (line2[i] == '.' && line2[i + 1] == '>') cout << endl;
						//else if (line[i] == '>') cout << endl;

						cout << endl;
						cout << "\t\t\t\t";
					}
				}

				cout << "\n\t\t\t\tYour Reservation" << endl;
				p++;//incrementing f if onr found
				break;
			}

		}


		fout.close();//closing file


		if (p > 0)
		{
			cout << "\t\t\t\tAre you sure you want to cancel your reservation?" << endl;
			cout << endl << "\t\t\t\tPlease check and press and key to continue with the cancellation.......";
			_getch();

			cout << endl;
			string msg = "\t\t\t\tRefunding Money to bank account......";
			Loading_Screen(msg);


			// Actual Delete Function
			my_file.open("domestic flight.txt", ios::binary);  //opening file............., ios::in | ios::out | ios::binary
			tmpfile.open("tmp.txt", ios::binary);

			//copying line till we find pnr line
			while (getline(my_file, line))
			{
				if (line.find(rpnr) == string::npos) //checking pnr
				{
					tmpfile << line << endl;
				}
				else f++;  //incrementing if pnr is found

				//break;
			}
			tmpfile.close();
			my_file.close();

			remove("domestic flight.txt");
			rename("tmp.txt", "domestic flight.txt");



		}




		switch (f)
		{
		case 0: //if f==0, pnr not found
		{
			wrong_pnr++;
			cout << "\t\t\t\tPNR code not found. Please try Again" << endl << endl;
			Delete_Record();
			break;
		}
		default:
		{
			cout << endl;
			string msg = "\t\t\t\tYour Reservation is being erased from our Database......";
			Loading_Screen(msg);
			break;
		}

		}
	}

}





//Finding details based on the given pnr code from user
void Details_Check()
{
	string rpnr = "";


	do
	{
		if (wrong_pnr > 4)
		{
			cout << endl << endl << "\t\t\t\tYou have tried many times" << endl;
			cout << endl << "\t\t\t\tIt is possible that you have lost the pnr code. Contact our customer service center." << endl;
			cout << endl << "\t\t\t\tWe will take you back to the Main Menu now" << endl;
			cout << endl << endl << "\t\t\t\tPress any key to continue.........";
			_getch();

			system("CLS");
			cout << endl << endl;
			Menu();
		}

		cout << "\t\t\t\t>> Please Enter a valid pnr code of your flight : ";
		if (check_getline == 0) cin.ignore(); // under condition so that can not take the first word of rpnr after wrong rpnr input
		getline(cin, rpnr);
		cout << endl;
		check_getline++;
	} while (rpnr.length() < 5 || rpnr.length() > 6);

	rpnr = " " + rpnr + "."; // adding white space in front and fullstop at end to identify specifically


	string line;
	int f = 0;
	ifstream fout;

	fout.open("domestic flight.txt", ios::binary);//opening file............., ios::in | ios::out | ios::binary


	while (getline(fout, line))
	{
		if (line.find(rpnr) != string::npos)//checking pnr
		{

			string msg = "\t\t\t\tPlease wait while the server searches for your details......";
			Loading_Screen(msg);
			string msg1 = "\t\t\t\tPrinting Matched Data....";
			Loading_Screen(msg1);
			cout << endl << endl;


			cout << "\t\t\t\t";
			for (int i = 0; i < line.length(); i++)
			{

				cout << line[i];    //display details

				if ((line[i] == '.' && line[i + 1] != 'c') || (line[i] == '.' && line[i + 1] == '>') || line[i] == '~' || line[i] == '>')
				{
					if (line[i] == '~') cout << endl;
					else if (line[i] == '.' && line[i + 1] == '>') cout << endl;
					//else if (line[i] == '>') cout << endl;

					cout << endl;
					cout << "\t\t\t\t";
				}
			}

			cout << "\n\t\t\t\tYour Reservation" << endl;
			f++;//incrementing if pnr found
			break;
		}

	}
	fout.close();//closing file

	if (f == 0) //if f==0, pnr not found
	{
		cout << "\t\t\t\tNo reservation found under this code." << endl;
		wrong_pnr++;
		Details_Check();
	}
	check_getline = 0; //essential to set this to zero before exiting the function
	wrong_pnr = 0;
}





//Listing all the pnr codes
void List()
{
	string line;
	int j = 0;
	ifstream my_file;

	my_file.open("domestic flight.txt", ios::binary);//opening file............., ios::in | ios::out | ios::binary

	cout << endl;

	while (getline(my_file, line))
	{
		cout << "\t\t\t\t";

		string word = "PNR code : ";
		size_t found = line.find(word);


		//To only print counter when there is a pnr in txt file
		if (found > 0 && found < line.length())
		{
			cout << j + 1 << ") ";
			j++;
		}

		//Print the pnr codes
		for (int i = found + 11; i < line.length(); i++)
		{
			cout << line[i];
		}
		cout << endl;

	}


	my_file.close();//closing file

}







// making file for ADMIN class
void ADMIN::Make_File_Admin()
{
	ADMIN user;

	ofstream my_file;


	int matched = 0;
	int count = 0;
	ifstream my_file2;



	do
	{

		matched = 0;

		if (count > 0) cout << endl << endl << "\t\t\t\tUsername Already Taken. Please Try Again" << endl;

		cout << endl << endl << "\t\t\t\t>>Enter a username : ";
		getline(cin, username);


		my_file2.open("ADMIN.dat", ios::in | ios::out | ios::binary | ios::app);//opening file............., ios::in | ios::out | ios::binary

		while (!my_file2.eof())
		{
			my_file2.read((char*)&user, sizeof(user));  //reading another record from the same file

			//cout << user.username << "  " << username << "  " << matched << endl;

			if (user.username == username)
			{
				matched++;
			}

		}

		my_file2.close();

		count++;

	} while (matched > 0);


	string msg = "\t\t\t\tCreating Username for ADMIN Account......";
	Loading_Screen(msg);


	cout << endl << endl << "\t\t\t\t|||||| Username Created Successfully ||||||" << endl;


	do
	{
		pass_ins();
		cout << endl << endl << "\t\t\t\t>>Enter a Password : ";
		getline(cin, password);
	} while (!Verify_Pass_Admin());

	cout << endl << endl << "\t\t\t\t|||||| Password Set Successfully ||||||" << endl;


	string msg2 = "\t\t\t\tSaving ADMIN Account Credentials......";
	Loading_Screen(msg2);


	cout << endl << endl << "\t\t\t\t>>Please note down the following Credentials for future use: " << endl;
	cout << endl << "\t\t\t\tUsername : " << username << endl;
	cout << endl << "\t\t\t\tPassword : " << password << endl;




	//Saving credentials

	ADMIN user1;

	my_file.open("ADMIN.dat", ios::in | ios::out | ios::app | ios::binary);



	while (!my_file.eof())
	{
		//user.ID = ID;
		user1.username = username;
		user1.password = password;
		break;
	}
	//else cout << "File opening Failed!" << endl;
	my_file.write((char*)&user1, sizeof(user1));

	my_file.close();

	cout << endl << "\t\t\t\tCheck the details above. Press Enter to Continue....";
	_getch();
	check_getline = 0;

	system("CLS");
	cout << endl << endl;
	return Menu();

}










void Patient_Detail::Make_File_Patient()
{


	Patient_Detail user;

	ofstream my_file;


	int matched = 0;
	int count = 0;
	ifstream my_file2;



	do
	{

		matched = 0;

		if (count > 0) cout << endl << endl << "\t\t\t\tUsername Already Taken. Please Try Again" << endl;

		cin.ignore();
		cout << endl << endl << "\t\t\t\t>>Enter a username : ";
		getline(cin, username);


		my_file2.open("PATIENT.dat", ios::in | ios::out | ios::binary | ios::app);//opening file............., ios::in | ios::out | ios::binary

		while (!my_file2.eof())
		{
			my_file2.read((char*)&user, sizeof(user));  //reading another record from the same file

			//cout << user.username << "  " << username << "  " << matched << endl;

			if (user.username == username)
			{
				matched++;
			}

		}

		my_file2.close();

		count++;

	} while (matched > 0);


	string msg = "\t\t\t\tCreating Username for PATIENT Account......";
	Loading_Screen(msg);


	cout << endl << endl << "\t\t\t\t|||||| Username Created Successfully ||||||" << endl;


	do
	{
		pass_ins();
		cout << endl << endl << "\t\t\t\t>>Enter a Password : ";
		getline(cin, password);
	} while (!Verify_Pass_Patient());

	cout << endl << endl << "\t\t\t\t|||||| Password Set Successfully ||||||" << endl;


	string msg2 = "\t\t\t\tSaving PATIENT Account Credentials......";
	Loading_Screen(msg2);


	cout << endl << endl << "\t\t\t\t>>Please note down the following Credentials for future use: " << endl;
	cout << endl << "\t\t\t\tUsername : " << username << endl;
	cout << endl << "\t\t\t\tPassword : " << password << endl;




	//Saving credentials

	Patient_Detail user1;

	my_file.open("PATIENT.dat", ios::in | ios::out | ios::app | ios::binary);



	while (!my_file.eof())
	{
		//user.ID = ID;
		user1.username = username;
		user1.password = password;
		break;
	}
	//else cout << "File opening Failed!" << endl;
	my_file.write((char*)&user1, sizeof(user1));

	my_file.close();


	Patient_Page();





	cout << endl << "\t\t\t\tCheck the details above. Press Enter to Continue....";
	_getch();
	check_getline = 0;

	system("CLS");
	cout << endl << endl;
	return Menu();


}

















//Function to verify is the password is Ideal
bool ADMIN::Verify_Pass_Admin()
{
	int len_cnt = 0, up_cnt = 0, low_cnt = 0, digit_cnt = 0, spchar_cnt = 0;

	if (password.length() >= 5) len_cnt++;

	for (int i = 0; i < password.length(); i++)
	{
		if (isdigit(password[i])) digit_cnt++;
		if (isupper(password[i])) up_cnt++;
		if (islower(password[i])) low_cnt++;
		if (isSpecialCharater(password[i])) spchar_cnt++; // UDF
	}

	if (len_cnt == 0 || up_cnt == 0 || low_cnt == 0 || digit_cnt == 0 || spchar_cnt == 0)
	{
		return false;
	}
	else return true;

}




bool Patient_Detail::Verify_Pass_Patient()
{
	int len_cnt = 0, up_cnt = 0, low_cnt = 0, digit_cnt = 0, spchar_cnt = 0;

	if (password.length() >= 5) len_cnt++;

	for (int i = 0; i < password.length(); i++)
	{
		if (isdigit(password[i])) digit_cnt++;
		if (isupper(password[i])) up_cnt++;
		if (islower(password[i])) low_cnt++;
		if (isSpecialCharater(password[i])) spchar_cnt++; // UDF
	}

	if (len_cnt == 0 || up_cnt == 0 || low_cnt == 0 || digit_cnt == 0 || spchar_cnt == 0)
	{
		return false;
	}
	else return true;

}







//Instructions for password
void pass_ins()
{
	cout << endl << endl << "\t\t\t\tInstruction for password ==>" << endl << endl;
	cout << "\t\t\t\ta) The password has to be atleast 5 characters long." << endl;
	cout << "\t\t\t\tb) The password should contain atleast one upper alphabet" << endl;
	cout << "\t\t\t\tc) The password should contain atleast one lower alphabet" << endl;
	cout << "\t\t\t\td) The password should contain atleast one special Character" << endl << endl;
}


//Function to check if character is special
bool isSpecialCharater(char& a)
{
	if (isalpha(a) || isdigit(a)) return false;
	else return true;
}







//log in page for existing ADMIN
void Verify_Admin()
{
	string input_username, input_password;


	//cin.ignore();
	cout << endl << "\t\t\t\t>>Enter An Existing Username : ";
	getline(cin, input_username);



	//Verifying the input data:
	string line;
	ADMIN user;
	int f = 0, p = 0;
	ifstream my_file;
	bool found = false;

	my_file.open("ADMIN.dat", ios::in | ios::out | ios::binary | ios::app);//opening file............., ios::in | ios::out | ios::binary

	int u = 0;

	while (!my_file.eof())
	{
		my_file.read((char*)&user, sizeof(user)); //reading another record from the same file



		if (user.username == input_username)
		{
			string msg2 = "\t\t\t\tLooking For Username through Database......";
			Loading_Screen(msg2);

			cout << endl << endl << "\t\t\t\t||||| Username Found! |||||" << endl;

			do
			{
				if (p > 0) cout << endl << endl << "\t\t\t\tWrong Password! Please Try again!!" << endl;

				if (p > 4)
				{
					cout << endl << endl << "\t\t\t\tYou have tried many times" << endl;
					cout << endl << "\t\t\t\tIt is possible that you have forgotten the password. Contact your superviser" << endl;
					cout << endl << "\t\t\t\tWe will take you back to the Main Menu now" << endl;
					cout << endl << endl << "\t\t\t\tPress any key to continue.........";
					_getch();


					system("CLS");
					cout << endl << endl;
					return Menu();
				}

				//cin.ignore();
				cout << endl << endl << "\t\t\t\t>>Enter Password : ";
				getline(cin, input_password);
				p++;
			} while (user.password != input_password);

			string msg3 = "\t\t\t\tChecking Credebility......";
			Loading_Screen(msg3);


			cout << endl << endl << "\t\t\t\t||||| Credentials Matched |||||" << endl;

			found = true;
			break;
		}

	}


	my_file.close();


	if (found == true)
	{

		Doctor_Page();

	}

	else if (found == false)
	{
		string msg2 = "\t\t\t\tLooking For Username through Database......";
		Loading_Screen(msg2);

		wrong_user++;

		if (wrong_user > 2)
		{
			system("CLS");
			cout << endl << endl << "\t\t\t\tUsername was not Found!" << endl;
			cout << endl << "\t\t\t\tIt seems Like you do not have an ADMIN Account" << endl;
			cout << endl << "\t\t\t\tTaking back to Main Menu. From there create an ADMIN account and try again!" << endl;

			cout << endl << "\t\t\t\tPress any key to continue.......";
			_getch();


			system("CLS");
			cout << endl << endl;
			return Menu();
		}

		else if (wrong_user <= 2)
		{
			cout << endl << endl << "\t\t\t\tUsername was not Found!" << endl;
			cout << endl << "\t\t\t\tPlease Try Again!!" << endl;


		}

		Verify_Admin();
	}


	wrong_user = 0;
}









//log in page for existing ADMIN
void Verify_Patient()
{
	string input_username, input_password;
	Patient_Detail user1;

	//cin.ignore();
	cout << endl << "\t\t\t\t>>Enter An Existing Username : ";
	getline(cin, input_username);



	//Verifying the input data:
	string line;
	Patient_Detail user;
	int f = 0, p = 0;
	ifstream my_file;
	bool found = false;

	my_file.open("PATIENT.dat", ios::in | ios::out | ios::binary | ios::app);//opening file............., ios::in | ios::out | ios::binary

	int u = 0;

	while (!my_file.eof())
	{
		my_file.read((char*)&user, sizeof(user)); //reading another record from the same file



		if (user.username == input_username)
		{
			string msg2 = "\t\t\t\tLooking For Username through Database......";
			Loading_Screen(msg2);

			cout << endl << endl << "\t\t\t\t||||| Username Found! |||||" << endl;

			do
			{
				if (p > 0) cout << endl << endl << "\t\t\t\tWrong Password! Please Try again!!" << endl;

				if (p > 4)
				{
					cout << endl << endl << "\t\t\t\tYou have tried many times" << endl;
					cout << endl << "\t\t\t\tIt is possible that you have forgotten the password. Contact the front desk" << endl;
					cout << endl << "\t\t\t\tWe will take you back to the Main Menu now" << endl;
					cout << endl << endl << "\t\t\t\tPress any key to continue.........";
					_getch();


					system("CLS");
					cout << endl << endl;
					return Menu();
				}

				//cin.ignore();
				cout << endl << endl << "\t\t\t\t>>Enter Password : ";
				getline(cin, input_password);
				p++;
			} while (user.password != input_password);

			string msg3 = "\t\t\t\tChecking Credebility......";
			Loading_Screen(msg3);


			cout << endl << endl << "\t\t\t\t||||| Credentials Matched |||||" << endl;

			found = true;
			break;
		}

	}


	my_file.close();


	if (found == true)
	{

		string msg = "\t\t\t\tApproving Authorization......";
		Loading_Screen(msg);
		cout << endl;

		user1.Patient_Page();
		cout << endl << "\t\t\t\tPress any key to continue.......";
		_getch();


		system("CLS");
		cout << endl << endl;
		return Menu();
	}

	else if (found == false)
	{
		string msg2 = "\t\t\t\tLooking For Username through Database......";
		Loading_Screen(msg2);

		wrong_user++;

		if (wrong_user > 2)
		{
			system("CLS");
			cout << endl << endl << "\t\t\t\tUsername was not Found!" << endl;
			cout << endl << "\t\t\t\tIt seems Like you do not have an ADMIN Account" << endl;
			cout << endl << "\t\t\t\tTaking back to Main Menu. From there create an ADMIN account and try again!" << endl;

			cout << endl << "\t\t\t\tPress any key to continue.......";
			_getch();


			system("CLS");
			cout << endl << endl;
			return Menu();
		}

		else if (wrong_user <= 2)
		{
			cout << endl << endl << "\t\t\t\tUsername was not Found!" << endl;
			cout << endl << "\t\t\t\tPlease Try Again!!" << endl;


		}

		Verify_Patient();
	}


	wrong_user = 0;
}






















////////####### Constructors and Destructors########//////////

Patient_Detail::Patient_Detail()
{
	//delete p;
	Email = "";

	Phone_Number = NULL;
	
}

Patient_Detail::~Patient_Detail()
{
	//delete p;
	Email = "";
	Phone_Number = NULL;
	
}




ADMIN::ADMIN()
{

	username = "";
	password = "";
}

ADMIN::~ADMIN()
{

	username = "";
	password = "";
}





Flight::Flight()
{

	Date = "";
	Time = "";
	total_cost = NULL;
	int_flight_type = NULL;
	time_choice = NULL;
}


Flight::~Flight()
{

	Date = "";
	Time = "";
	total_cost = NULL;
	int_flight_type = NULL;
	time_choice = NULL;
}












void Patient_Detail::Patient_Page()
{
	//Passenger_Detail user1;
	
	string opt1;
	system("CLS");
	cout << endl << endl;

	check_getline = 0; // to ignore the first geetline error

	cout << "\t\t\t****************************************" << endl;
	cout << "\t\t\t\t*******HOMEPAGE*******" << endl;
	cout << "\t\t\t****************************************" << endl;

	do
	{
	cout << "\t\t\t\tHow can we help you today? : " << endl << endl;
	cout << "\t\t\t\t1) Report Any unusual or side effect" << endl;
	cout << "\t\t\t\t2) Book Appointment with Doctor" << endl;
	cout << "\t\t\t\t3) See or Update your profile." << endl;
	cout << "\t\t\t\t4) Emergency contact" << endl;
	cout << "\t\t\t\t5) More" << endl;
	cout << "\t\t\t\t>> Select : ";
	getline(cin, opt1);
	check_getline++;
	} while (opt1 < "1" || opt1 > "5" || opt1.length() > 1);


	if (opt1 == "1")
	{


		cout << "\t\t\t\t1) In what part of your Body did you feel problem? : ";
		getline(cin, body_problem);
		cout << "\t\t\t\t2) Rate your pain on the scale of 0 to 10 : ";
		getline(cin, pain);
		cout << "\t\t\t\t3) Did you have any Fever? (Yes or No) : ";
		getline(cin, y_n);



	}
	
	
	//user1.Make_File();
	Make_File();


	_getch();


}






void Doctor_Page()
{

	system("CLS");
	cout << endl << endl;


	cout << "\t\t\t****************************************" << endl;
	cout << "\t\t\t\t*******HOMEPAGE*******" << endl;
	cout << "\t\t\t****************************************" << endl;



	cout << "\t\t\t\t1) Choose Patient" << endl;
	cout << "\t\t\t\t2) Emergency Section" << endl;
	cout << "\t\t\t\t3) Oncology Updates" << endl;
	cout << "\t\t\t\t4) Schedule" << endl;
	cout << "\t\t\t\t5) More" << endl;

	_getch();

}