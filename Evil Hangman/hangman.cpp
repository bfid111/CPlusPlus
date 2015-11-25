#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
int isCorrectletter(char guess, string &guessword);
vector <string> lists;
int main()
{
	string input_line[10000];
	string fileData;
	string newline = "\n";
	int tries = 0;
	char guess[11116];
	int correctcount =0;
	
	string all;
	int wordlength;
	ifstream fin( "dictionary.txt" );
		if( !fin )
	{
		cout << "An error has occurred reading in file." << endl;
		cout << endl;
		system("pause");
		return -1;  //tells the OS of an error when returned from the main
	}
		  		
	for( int i = 1; !fin.eof(); i++ )
	{
	
		getline( fin, input_line[i] );		//reads in one line from file into input_line
			
	}
	fin.close();
	
	cout << "Dicitonary.txt Load Complete " << endl;
	cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<< endl;
	cout << "&&&&&&&&&&&&& Welcome to Hangman &&&&&&&&&&&& " << endl;
	cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<< endl;
	cout << "_____________________________________________"<< endl;
	// evil hangman sequence starts // 
	cout << "Input the Length of the Word : ";
	cin >> wordlength; // length input
	cout << endl;
	tries = wordlength;
	if ( wordlength > 6 || wordlength < 1 )
	{
		cout << "Length has to be Greater than 0 or Less than 7 " << endl;
		return -1;

	}

	for ( int a=0; a < 9704; a++) // 9705 = number of lines in the list txt
	{
		if ( input_line[a].size() == wordlength ) 
		{
		lists.push_back(input_line[a]); // inputs the list of words that has the length that the user input to a string vector
		}
		
	}
	for ( int b =tries; b > 0; b--)
	{
		cout << "Pleaes Guess a letter : ";
		cin >> guess[b]; 
		cout << endl;
		for ( int c =0; c < lists.size()-1; c++) // deletes all words in the list that contains a letter that the user guesses except one word 
		{
			if(lists[c].find_first_not_of(guess[c]) || lists[c].find_last_not_of(guess[c])||lists[c].find_first_of(guess[c])||lists[c].find_last_of(guess[c])) // see if the word has any character that the user guessed 
			{
				lists[c].erase(); // delete the words from the list except one 
				
			}
		 
		}

		cout << " Wrong Guess ! " << "Tries Left : " << b << endl;
		
		
	}
	
	tries = wordlength; // reset game to real hangman 
	
	cout << " Fooled Ya! The real Hangman Starts NOW! " << endl;
	for ( int d = tries ; d > 0; d--)
	{
		cout << "Pleaes Guess a letter : ";
		cin >> guess[d];
		cout << endl;
		
		if (guess[d] == d)
		{
			cout << "Correct Guess! " << "Tries Left : " << d << endl;
			correctcount++;
			
			if (correctcount == wordlength )
			{
				cout << "Congradulations You Won ! " << endl;
				system("pause");
				return EXIT_SUCCESS;
			}

		}
		
		else
		{
			cout << " Wrong Guess ! " << "Tries Left : " << d << endl;
			
			if ( d < 2 )
			{
				cout << " You lost !! " << endl;
				cout << " The Answer is in answer.txt " << endl;
				system("pause");
				return EXIT_SUCCESS;
			}
		}

	
	}
	
	
	
	system("pause");
	ofstream fout( "answer.txt" );
	for ( int n =0; n < 9705; n++)
	{
	fout << lists[n] << endl;
	
	}

	fout.close();
}

