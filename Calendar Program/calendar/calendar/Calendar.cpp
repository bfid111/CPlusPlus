#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;
string timeStamp(void);
ofstream fout("calendar.txt");
int calcDaysSoFar( int year, int month );
bool isLeapYear( int year);
void printCalendar(int month, int year, int firstDay);


 const int firstYear = 1800; 
 const int daypass = 3; 
 const int firstLeapYear = 1804; 
 
 string monthnames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}; 
 string  months1[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
 int monthdays[] = { 31,28,31,30,31,30,31,31,30,31,30,31} ; //standard year
 int daysPassed[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}; //per month per year

int main ()

{ 
	
    int year, month = 0;
    int days;
    cout << "Enter year : " << endl;
    cin >> year;
	if ( year > 9999 || year < 1800)
	{
		cout << "Year has to be greater than 1800 or less than 9999" << endl;
		system("pause");
		return EXIT_SUCCESS;
	}
	cout << "Enter month :" << endl;
	cin >> month;
	if (month>12||month<1)
	{
		cout << "Month has to be greater than 0 and less than 12 " << endl;
		system("pause");
		return EXIT_SUCCESS;
	}
	fout << "This Calendar was Created at :";
	fout << timeStamp() << endl;
    for(int a=0;a<1;a++)
	{
// calculate how many days passed
    days = calcDaysSoFar(year, month);
    
    
    int firstDayOfWeek = days % 7;

    printCalendar(month, year, firstDayOfWeek);
    month++;
    }
	while(month < 1);

	fout.close();
    system("pause");

}



int calcDaysSoFar( int year, int month)
{
    int days;

    //calculates basic number of days passed 
    days = (year - firstYear) * 365;
    days += daypass;
    days += daysPassed[month-1];
    
    //adds days for leap years
    for (int count = firstLeapYear; count < year ; count +=4)
    {
        if (isLeapYear(count) )
        {
            days++;
        }
    }

    //leapday for february  
    if( month > 2 && isLeapYear(year) )
    {
        days++;
    }

    return days;

}


// leapyear check
bool isLeapYear( int year)
{
    return (!(year%4)&&(year%100))||!(year%400);
}



void printCalendar(int month, int year, int firstDay)
{
    cout << setw(17) << months1[month-1] << endl;
	cout << setw(14) << "Year: " << year << endl;
    cout << "Sun " << "Mon " << "Tue " << "Wed " << "Thu " << "Fri " << "Sat "<< '\n';

	fout << setw(17) << months1[month-1] << endl;
	fout << setw(14) << "Year: " << year << endl;
    fout << "Sun " << "Mon " << "Tue " << "Wed " << "Thu " << "Fri " << "Sat "<< '\n';

    int count,offset;

    offset= 1 - firstDay;
    
    count = monthdays[month-1]; //get the number of days in this month


    if(isLeapYear(year) && (month==2) )
    {
        count++;
    }

	// leap year
    for (int x = offset; x <= count; x +=7)
    {

        for(int column= x; (column < x+7) && (column <= count); column++)
        {
            if (column <=0)
            {
                cout << setw(4) << left << setprecision(3) << " "; 
				fout << setw(4) << left << setprecision(3) << " "; 
            }
            else
            {
                cout << setw(4) << left << setprecision(3) << setfill(' ') << column;
				fout << setw(4) << left << setprecision(3) << setfill(' ') << column;
            }

        }

        cout << endl;
		fout << endl;
    }

    cout << endl;
	fout << endl;

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