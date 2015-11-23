/*#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
	using namespace std;
string timeStamp(void);
int main()
{


	string filename = "Barcode.txt";
	string input = "";
	string all = "";
	vector <string> zipcode;
	cout << " Zipcode Encoder " << endl;
	while( input.compare( "quit" ) != 0 )
	{
		cout << "Enter Zipcode: ";
		while ( input != "quit" )
		{
		zipcode.push_back(input);
		}
	}



	ofstream fout( "C:\\Users\\15yson\\Desktop\\"  + filename );
	
	fout << timeStamp();
	fout.close();


	system ("pause");
	
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
*/
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

string timeStamp(void);

int main() 
{ 	
	string filename = "whatever.txt";
	string input = "";
	string all;

	while( input.compare( "quit" ) != 0 )
	{
		cout << "Enter some text: ";
		if(input!="quit")
		{
		cin >> input;
		all += input;
		cout << endl;
		}
	}

	ofstream fout( "C:\\Users\\15yson\\Desktop\\"  + filename);

	if( !fout )
	{
		cout << filename << " was unable to be opened" << endl;
		return -1;
	}

	fout << timeStamp();

	fout << all << endl;

	fout.close();


	cout << endl;
	system("pause");	
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
