#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include <cctype>
#include <cstdlib> // general utilities 
#include <iomanip>

using namespace std;
void login();
void registr();
void forgot();
void viewMenu();

int main()
{
	int choice;
	cout << endl;
	cout << "************************UHD Cafe Login**********************" << endl;
	cout << "1.Login" << endl;
	cout << "2.Register" << endl;
	cout << "3.Forgot credentials" << endl;
	cout << "Enter your choice : ";
	cin >> choice;
	
	switch (choice)
	{
	case 1: 
		login();
		break;
	case 2:
		registr();
		break;
	case 3:
		forgot();
		break;
	case 4:
		cout << "Exit UHD Cafe Menu" << endl;
		break;
	default:
		cout << "Enter choice 1 - 3";
		main();

	}
}

void registr()
{
	string reguser, regpass;
	system("cls");
	cout << "Enter the username :";
	cin >> reguser;
	cout << "Enter the password :";
	cin >> regpass;
	
	ofstream reg("database.txt", ios::app);
	reg << reguser << ' ' << regpass << endl;
	system("cls");
	cout << "Registration is successfull" << endl;
	main();
}

void login()
{
	int exist = 0;
	string user, pass,u,p;
	system, ("cls");
	cout << "Enter the username : ";
	cin >> user;
	cout << "Enter the password : ";
	cin >> pass;

	ifstream input("database.txt");
	
	while (input >> u >> p)
	{
		if (u == user && p == pass)
		{
			exist = 1;
		}
	}
	input.close();
	if (exist == 1)
	{
		cout << "User name "<< user << " is now active" << endl;
		cin.get();
		cin.get();
		viewMenu();
		//main();
	}
	else
	{
		cout << "User does not exist";
		cin.get();
		cin.get();
		main();

	}
	
}

void forgot()
{
	int ch;
	system("cls");
	cout << "1. Search your account by username" << endl;
	cout << "2. Search your account by password" << endl;
	cout << "3.Main Menu" << endl;
	cin >> ch;

	switch (ch)
	{
		case 1:
		{
			int ex = 0;
			string searchuser, su, sp;
			cout << "Enter your username : ";
			cin >> searchuser;
			ifstream searchu("database.txt");
			while (searchu >> su >> sp)
			{
				if (su == searchuser)
				{
					ex = 1;
					break;
				}
			}
			searchu.close();
			if (ex == 1)
			{
				cout << "User account found" << endl;
				cout << sp;
				cin.get();
				cin.get();
				main();
			}
			else
			{
				cout << "User account not found" << endl;
				cin.get();
				cin.get();
				main();
			}
			break;
		}
		case 2:
		{
			int exi = 0;
			string searchpass, su2, sp2;
			cout << "Enter the User account :";
			cin >> searchpass;

			ifstream searchp("database.txt");
			while (searchp >> su2 >> sp2)
			{
				if (sp2 == searchpass)
				{
					exi = 1;
					break;
				}
				searchp.close();
				if (exi == 1)
				{
					cout << "User account found" << endl;
					cout << "User name is : " << su2;
					cout << "Password is : " << sp2;
					cin.get();
					cin.get();
					main();
				}
				break;
			}
		
		}
		case 3:
		{
			main();
			break;
		}
		default:
		{
			cout << "Enter 1-3" << endl;
			cin.get();
			cin.get();
			forgot();
		}
		
	}
}

void viewMenu()
{
	//char choice2 = 'Y';

	int order = 1;

	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
	int num_customers = 0;
	int sentinel = 0;
	const double SalePrice1 = 6.95, SalePrice2 = 3.75, SalePrice3 = 4.25, SalePrice4 = 1.89, SalePrice5 = 1.50;
	double AmountofSale1 = 0, AmountofSale2 = 0, AmountofSale3 = 0, AmountofSale4 = 0, AmountofSale5 = 0;


	cout << " Welcome to the UHD cafe\n";
	cout << " We are happy to serve you\n";

	cout << "___________________Menu_______________________\n\n"
		<< "(1) Buffalo_Wings		        $6.95_____\n"
		<< "(2) Cheese_Burger		        $3.75_____\n"
		<< "(3) Chicken_Sandwich	                $4.25_____\n"
		<< "(4) Pizza_Slice    	                $1.89_____\n"
		<< "(5) French_Fries		        $1.50_____\n";




	while (order != sentinel)
	{
		cout << "From our menu, what would you like to order:\n";
		cin >> order;
		switch (order)
		{

		case 0:
			break;

		case 1:

			cout << "How many Buffalo Wings would you like to order:\n";
			cin >> num1;

			AmountofSale1 = SalePrice1 * num1;
			break;




		case 2:
			cout << "How many Cheese Burgers would you like to order:\n";
			cin >> num2;

			AmountofSale2 = SalePrice2 * num2;
			break;


		case 3:
			cout << "How many Chicken Sandwiches would you like to order:\n";
			cin >> num3;

			AmountofSale3 = SalePrice3 * num3;
			break;



		case 4:
			cout << "How many Pizza Slices would you like to order:\n";
			cin >> num4;

			AmountofSale4 = SalePrice4 * num4;
			break;



		case 5:
			cout << "How many French Fries would you like to order:\n";
			cin >> num5;

			AmountofSale5 = SalePrice5 * num5;
			break;


		default: cout << "To continue please choose another valid item from our menu\n";
		}


		{

			cout << "Your order total is:\n\n";

			cout << left << setw(15) << "ITEM" << right << setw(10) << "QUANTITY" << right << setw(15) << "SALE PRICE" << right << setw(20) << "AMOUNT OF SALE\n";


			cout << "Buffalo Wings:" << setw(6) << left << num1 << setw(16) << right << SalePrice1 << setw(20) << right << AmountofSale1 << endl << endl;

			cout << "Cheese Burger:" << setw(6) << left << num2 << setw(16) << right << SalePrice2 << setw(20) << right << AmountofSale2 << endl << endl;

			cout << "Chicken Sandwich:" << setw(6) << left << num3 << setw(16) << right << SalePrice3 << setw(20) << right << AmountofSale3 << endl << endl;

			cout << "Pizza Slice:" << setw(6) << left << num4 << setw(16) << right << SalePrice4 << setw(20) << right << AmountofSale4 << endl << endl;

			cout << "French Fries:" << setw(6) << left << num5 << setw(16) << right << SalePrice5 << setw(20) << right << AmountofSale5 << endl << endl;
		}
	}

	system("PAUSE");
}