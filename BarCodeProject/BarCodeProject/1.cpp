#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

string timeStamp(void);


string one = ": : : | | ";
string two = ": : | : | ";
string three = ": : | | : ";
string four = ": | : : | ";
string five = ": | : | : ";
string six = ": | | : : ";
string seven = "| : : : | ";
string eight = "| : : | : ";
string nine = "| : | : : ";
string zero = "| | : : : ";
string bar1; 
string bar2; 
string bar3;
string bar4; 
string bar5; 
string bar6;
int digit1;
int digit2;
int digit3;
int digit4;
int digit5;
int digit6;
void encode (int);
int main() 
{ 	
	string filename = "whatever.txt";
	string input = "";
	string all = "";
	
	
	int c;

	cout << "How many zipcode do you want to encode :";
	cin >> c;
	
	
	int zipcode[10000];
	cout << "Input Zip Code : " << endl;

	
	for ( int a =0; a < c; a++)
	{
		cin >> zipcode[a];
	}
	ofstream fout("zipcode.txt");
	fout << timeStamp() << endl;
	fout << " Encoded Zip Code : " << endl;

	for ( int b=0; b<c;b++)
	{
 digit5 = (zipcode[b] % 10);
 digit4 = ((zipcode[b] % 100) - (digit5));
 digit3 = ((zipcode[b] % 1000) - (digit5 + digit4)) / 100;
 digit2 = ((zipcode[b] % 10000) - (digit5 + digit4 + digit3)) / 1000;
 digit1 = ((zipcode[b] % 100000) - (digit5 + digit4 + digit3 + digit2)) / 10000;
 digit6 = 20-(digit1+digit2+digit3+digit4+digit5);
		if (digit1 == 1)
bar1 = one;
else
{
if (digit1 == 2)
bar1 = two;
else
{
if (digit1 == 3)
bar1 = three;
else
{
if (digit1 == 4)
bar1 = four;
else
{
if (digit1 == 5)
bar1 = five;
else
{
if (digit1 == 6)
bar1 = six;
else
{
if (digit1 == 7)
bar1 = seven;
else
{
if (digit1 == 8)
bar1 = eight;
else
{
if (digit1 == 9)
bar1 = nine;
else
{
bar1 = zero;
}
}
}
}
}
}
}
}
}
fout  << "| "<<bar1;
/*----------------------------------------------------*/
if (digit2 == 1)
bar2 = one;
else
{
if (digit2 == 2)
bar2 = two;
else
{
if (digit2 == 3)
bar2 = three;
else
{
if (digit2 == 4)
bar2 = four;
else
{
if (digit2 == 5)
bar2 = five;
else
{
if (digit2 == 6)
bar2 = six;
else
{
if (digit2 == 7)
bar2 = seven;
else
{
if (digit2 == 8)
bar2 = eight;
else
{
if (digit2 == 9)
bar2 = nine;
else
{
bar2= zero;
}
}
}
}
}
}
}
}
}
fout  << bar2;
/*----------------------------------------------------*/
if (digit3 == 1)
bar3 = one;
else
{
if (digit3 == 2)
bar3 = two;
else
{
if (digit3 == 3)
bar3 = three;
else
{
if (digit3 == 4)
bar3 = four;
else
{
if (digit3 == 5)
bar3 = five;
else
{
if (digit3 == 6)
bar3 = six;
else
{
if (digit3 == 7)
bar3 = seven;
else
{
if (digit3 == 8)
bar3 = eight;
else
{
if (digit3 == 9)
bar3 = nine;
else
{
bar3= zero;
}
}
}
}
}
}
}
}
}
fout  << bar3;
/*----------------------------------------------------*/
if (digit4 == 1)
bar4 = one;
else
{
if (digit4 == 2)
bar4= two;
else
{
if (digit4== 3)
bar4= three;
else
{
if (digit4 == 4)
bar4 = four;
else
{
if (digit4 == 5)
bar4 = five;
else
{
if (digit4 == 6)
bar4 = six;
else
{
if (digit4 == 7)
bar4 = seven;
else
{
if (digit4 == 8)
bar4 = eight;
else
{
if (digit4 == 9)
bar4 = nine;
else
{
bar4= zero;
}
}
}
}
}
}
}
}
}
fout  << bar4;
/*----------------------------------------------------*/
if (digit5 == 1)
bar5 = one;
else
{
if (digit5 == 2)
bar5= two;
else
{
if (digit5== 3)
bar5= three;
else
{
if (digit5 == 4)
bar5 = four;
else
{
if (digit5 == 5)
bar5 = five;
else
{
if (digit5 == 6)
bar5 = six;
else
{
if (digit5 == 7)
bar5 = seven;
else
{
if (digit5 == 8)
bar5 = eight;
else
{
if (digit5 == 9)
bar5 = nine;
else
{
bar5= zero;
}
}
}
}
}
}
}
}
}
fout  << bar5;
/*----------------------------------------------------*/
if (digit6 == 1)
bar6 = one;
else
{
if (digit6 == 2)
bar6= two;
else
{
if (digit6== 3)
bar6= three;
else
{
if (digit6 == 4)
bar6 = four;
else
{
if (digit6 == 5)
bar6 = five;
else
{
if (digit6 == 6)
bar6 = six;
else
{
if (digit6 == 7)
bar6 = seven;
else
{
if (digit6 == 8)
bar6 = eight;
else
{
if (digit6 == 9)
bar6 = nine;
else
{
bar6= zero;
}
}
}
}
}
}
}
}
}
fout  << bar6 << " |" << endl;
	}
		



	cout << endl;
	fout.close();
    return EXIT_SUCCESS; 
}

string timeStamp()//function def
{
	string str;
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	str =  asctime (timeinfo) ;	
	return str;
}
void encode (int zipcode)
{

int digit5 = (zipcode % 10);
int digit4 = ((zipcode % 100) - (digit5));
int digit3 = ((zipcode % 1000) - (digit5 + digit4)) / 100;
int digit2 = ((zipcode % 10000) - (digit5 + digit4 + digit3)) / 1000;
int digit1 = ((zipcode % 100000) - (digit5 + digit4 + digit3 + digit2)) / 10000;
int digit6 = 20-(digit1+digit2+digit3+digit4+digit5);



}
