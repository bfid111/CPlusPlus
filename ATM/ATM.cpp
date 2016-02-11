#include <iomanip>
#include <iostream>
#include <cmath>
#include <ctime>

double deposit ( double );
double withdraw (double );
double balance ( double );
int pincode;
double a1balance = 1000;
double a2balance = 10000;
double a3balance = 100000;
int account;
int function;
int depositmoney;
double money;
double dep1;
double dep2;
double dep3;
double with1;
double with2;
double with3;
double bcheck;
int answer;
int answer1;
int success;
double withdrawmoney;
double ac1deposit;
using namespace std;

int main ()
{	
	int choice;
	int go = 1;
	while ( go == 1 )
	{
	cout << " _____________________________ " << endl;
	cout << " |Welcome to ATM bank Service|" << endl;
	cout << " |       By Youngmin Son     |" << endl;
	cout << " |   Please Enter a Pincode  | " << endl;
	cout << " |      Pincode is '9999'    |" << endl;
	cout << " |     Type 'EXIT' to exit   |" << endl;
	cout << " |___________________________| " << endl;
	cin >> choice;
	switch ( choice)
	{
	case 9999:
		cout << " Pin Success " << endl;
		break;
	default :
		cout << " Wrong PIN " << endl;
		system ("pause");
		return EXIT_SUCCESS;
	}
	cout << " |  Please Select an Account | " << endl;
	cout << " |     Type 1 for Account 1  | " << endl;
	cout << " |     Type 2 for Account 2  | " << endl;  
	cout << " |     Type 3 for Account 3  | " << endl;  
	cout << " |______-EXIT to exit_______ | " << endl;  
	cin >> account;
	switch ( account )
	{
	case 1 :
		cout << " Login Success " << endl;
		success = 2;
		break;
	case 2 : 
		cout << " Login Success " << endl;
		success = 2;
		break;
	case 3 :
		cout << " Login Success " << endl;
		success = 2;
		break;
	 default:
		cout << " Thank you for using our ATM service " << endl;
		system("pause");
		return EXIT_SUCCESS;
		break;
	}
	cout << " _____________________________ " << endl;
	cout << " |         ATM Function      | " << endl;
	cout << " |     Type 1 for Deposit    | " << endl;
	cout << " |     Type 2 for Withdrawal | " << endl;  
	cout << " |  Type 3 for CheckBalance  | " << endl;  
	cin >> function;
	if ( function == 1 )
	{
		cout << " How much money do you want to deposit ? : ";
		cin >> money;
	
		if ( account == 1 )
		{
	dep1 = deposit(1);
	cout << "Your Balance after deposit is : " << dep1 << endl;
		}
if ( account == 2 )
{
	dep2 = deposit(2);
	cout << "Your Balance after deposit is : " << dep2 << endl;
}
if ( account == 3 )
{
	dep3 = deposit(3);
	cout << "Your Balance after deposit is : " << dep3 << endl;
}
		double finala1balance = dep1;
		a1balance = finala1balance;
		double finala2balance = dep2;
		a2balance = finala1balance;
		double finala3balance = dep3;
		a3balance = finala1balance;
cout << " Would You to EXIT? Type 1 to Try again and Type 0 to EXIT " << endl;
	cin >> answer;
	switch ( answer )
	{
	case 1 :
		break;
	case 0 :
		cout << " Thank you for using our ATM service " << endl;
		system("pause");
		return EXIT_SUCCESS;
		break;
	 default:
		cout << " Thank you for using our ATM service " << endl;
		system("pause");
		return EXIT_SUCCESS;
		break;
	}
}
	if ( function == 2 )
	{
		cout << " How much money do you want to withdraw ?: ";
		cin >> withdrawmoney;
		if ( account == 1 )
		{
			with1 = withdraw(1);
				cout << " Your Balance after withdrawal is : " << with1 << endl;
				
			}
		if ( account == 2 )
		{
			with2 = withdraw(2);
				cout << " Your Balance after withdrawal is : " << with2 << endl;
			}
		if ( account == 3 )
		{
			with3 = withdraw(3);
				cout << " Your Balance after withdrawal is : " << with3 << endl;
			}
		double finala1balance = with1;
		a1balance = finala1balance;
		double finala2balance = with2;
		a2balance = finala2balance;
		double finala3balance = with3;
		a3balance = finala3balance;
		cout << " Would You to EXIT? Type 1 to Try again and Type 0 to EXIT " << endl;
	cin >> answer;
	switch ( answer )
	{
	case 1 :
		break;
	case 0 :
		cout << " Thank you for using our ATM service " << endl;
		system("pause");
		return EXIT_SUCCESS;
		break;
	 default:
		cout << " Thank you for using our ATM service " << endl;
		system("pause");
		return EXIT_SUCCESS;
		break;
	}
	}
	if ( function == 3 )
	{
		if (account == 1 )
		{
		
			cout << " Your Balance is : " <<  a1balance << endl;

		}
		if (account == 2 )
		{
			
			cout << " Your Balance is : " <<  a2balance  << endl;

		}
		if (account == 3 )
		{

			cout << " Your Balance is : " <<  a3balance  << endl;

		}
		cout << " Would You to EXIT? Type 1 to Try again and Type 0 to EXIT " << endl;
	cin >> answer;
	switch ( answer )
	{
	case 1 :
		break;
	case 0 :
		cout << " Thank you for using our ATM service " << endl;
		system("pause");
		return EXIT_SUCCESS;
		break;
	 default:
		cout << " Thank you for using our ATM service " << endl;
		system("pause");
		return EXIT_SUCCESS;
		break;
			   }
			}
		}	
	}

double deposit ( double bal1 )
{
	double a1;
	if ( bal1 == 1 )
	{
		bal1 = money + a1balance;
		a1 = bal1;
		return a1;
	}
	if ( bal1 == 2 )
		{
		bal1 = money + a2balance;
		double a2 = bal1;
		return a2;
	}
	if ( bal1 == 3 )
		{
		bal1 = money + a3balance;
		double a3 = bal1;
		return a3;
	}
}
double withdraw ( double with2 )
{
	double w1;
	if ( with2 == 1 )
	{
		with2 = a1balance - withdrawmoney;
		w1 = with2;
		if ( withdrawmoney > a1balance )
		{
			cout << " Your Balance is too Low " << endl;
			system("pause");
			return EXIT_SUCCESS;
		}
		return w1;
	}
	if ( with2 == 2 )
		{
		with2 = a2balance - withdrawmoney;
		double w2 = with2;
		if ( withdrawmoney > a2balance )
		{
			cout << " Your Balance is too Low " << endl;
			system("pause");
			return EXIT_SUCCESS;
		}
		return w2;
	}
	if ( with2 == 3 )
		{
		with2 = a3balance - withdrawmoney;
		double w3 = with2;
		
		if ( withdrawmoney > a3balance )
		{
				cout << " Your Balance is too Low " << endl;
				system("pause");
			return EXIT_SUCCESS;
		}
		return w3;
	}
}
double balance ( double balance1)
{
	if ( balance1 == 1 )
	{
		double b1 = a1balance;
		return b1;
	}
	if ( balance1 == 2 )
	{
		double b2 = a2balance;
		return b2;
	}
	if ( balance1 == 3 )
	{
		double b3 = a3balance;
		return b3;
	}
}



