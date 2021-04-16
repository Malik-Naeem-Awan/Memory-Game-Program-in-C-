// Final Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "stdlib.h"
#include "iostream"
#include "iomanip"
#include "ctime"
#include "windows.h"
#include "conio.h"
#include <fstream>
#include <string>

using namespace std;

void saveFile(string Malik, int score);
//Class for 4 x 4 Matrix

class Game0
{
private:
	int cards[4][4] = { {1, 2, 3, 4},
						{5, 6, 7, 8},
						{1, 2, 3, 4},
						{5, 6, 7, 8} };

	int deck[16] = { 2, 3, 4, 5, 6, 7, 8, 9 }, rem[4][4];
	int r1, r2, c1, c2, a1, a2, b1, b2, marks = 0, random1 = 0, random2 = 0, temp = 0, matchs = 8, mis = 0;
public:
	Game()
	{
		r1 = 0; r2 = 0; c1 = 0; c2 = 0;
	}

	void space()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << endl;
		}
	}


	void begin()
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		srand((unsigned)time(NULL));
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				random1 = rand() % 4;
				random2 = rand() % 4;
				temp = cards[i][j];
				cards[i][j] = cards[random1][random2];
				cards[random1][random2] = temp;
				//cout << cards[random1][random2] << " ";
				rem[i][j] = 0;
			}
			cout << endl;
		}
		
		 for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				cout << cards[i][j] << " ";
			}
			cout << endl;
		}

		space();

		for (int i = 0; i < 4; i++)
		{
			cout << "\t\t\t\t" << "+-----+-----+-----+-----+" << endl << "\t\t\t\t" << "| ";
			for (int j = 0; j < 4; j++)
			{
				cout << " * ";
				cout << " | ";
			}
			cout << endl;
		}
		cout << "\t\t\t\t" << "+-----+-----+-----+-----+" << endl << endl;
		
		input();
	}

	void input()
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 7);
		srand(time(0));
		cout << "\t\t\t\t" << "Row, Col = ";
		cin >> a1 >> b1;
		cout << "\t\t\t\t" << "Row, Col = ";
		cin >> a2 >> b2;
		system("CLS");

		r1=a1-1; r2=a2-1; c1=b1-1; c2=b2-1;
		
		cout << endl;

		space();

		cout << endl << endl << endl;

		for (int x = 0; x < 4; x++)
		{
			cout << "\t\t\t\t" << "+-----+-----+-----+-----+" << endl << "\t\t\t\t" << "| ";
			for (int y = 0; y < 4; y++)
			{
				if ((x == r1) && (y == c1))
				{
					cout << " ";
					SetConsoleTextAttribute(h, 6);
					cout << cards[x][y];
					SetConsoleTextAttribute(h, 7);
					cout << " " << " | ";
				}
				else if((x == r2) && (y == c2))
				{
					cout << " ";
					SetConsoleTextAttribute(h, 6);
					cout << cards[x][y];
					SetConsoleTextAttribute(h, 7);
					cout << " " << " | ";
				}
				else
				{
					SetConsoleTextAttribute(h, 7);
					cout << " * ";
					cout << " | ";
				}	
			}
			cout << endl;
		}
		cout << "\t\t\t\t" << "+-----+-----+-----+-----+" << endl << endl;

		match();
		
		
	}
	public: 
	
	void saveFile(string Malik, int score) {
		ofstream file;
		file.open("Easy.txt", std::ios_base::app);
		file << "Name: " << Malik  << "\n";
		file << "Score: " << score << "\n\n";
		file.close();
	}
	
	void  showHighestScore() {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 7);
		int previousHighest = 0;
		string line;
		ifstream myfile ("Easy.txt");
		if (myfile.is_open()) {
    		while ( getline (myfile,line) ) {
    			std::string str2 = line.substr(0,5);
    			if (str2.compare(0,5,"Score") == 0) {
    				std::string score = line.substr(7, line.length());
    				int value = atoi(score.c_str());
    				if (value >  previousHighest)
    					previousHighest = value;
    			}
    		}
    		myfile.close();
  		} else {
  			cout << "Unable to open file";
		}

  		cout << " Your Previous Highest Score is :  " << previousHighest;
	}
	
	
	void match()
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		if (cards[r1][c1] == cards[r2][c2])
		{
			if(matchs == 0)
			{
				cout << "\t\t\t\t" << "You Won!" << endl;
				saveFile("Malik", marks);
				showHighestScore();
			}
			else
			{
				rem[r1][c1] = cards[r1][c1];
				rem[r2][c2] = cards[r2][c2];
				SetConsoleTextAttribute(h, 10);
				cout << "\t\t\t\t" << "Valid Match!" << endl;
				if(cards[r1][c1] == cards[r1][c1])
				marks += 2;
				matchs -= 1;
				SetConsoleTextAttribute(h, 11);
				cout << "\t\t\t\t\t" << "Points: " << marks << endl;
				input();
			}
		}
		
		else if((rem[r1][c1] == cards[r1][c1]) && (rem[r2][c2] == cards[r2][c2]))
		{
			cout<<"These are matched already!";
		}
		else
		{
			mis += 1;
			if(mis == 3)
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\t\t\t\t" << "You Lose!" << endl;
				saveFile("Malik", marks);
				showHighestScore();
			}
			else
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\t\t\t\t" << "Invalid Match!" << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "\t\t\t\t" << "Points: " << marks << endl;
				input();
			}
		}
		
		
	}

};

//Class for 8 x 8 Matrix

class Game1
{
private:
	int cards[8][8] = { {1, 2, 3, 4, 5, 6, 7, 8},
						{1, 2, 3, 4, 5, 6, 7, 8},
						{1, 2, 3, 4, 5, 6, 7, 8},
						{1, 2, 3, 4, 5, 6, 7, 8},
						{1, 2, 3, 4, 5, 6, 7, 8},
						{1, 2, 3, 4, 5, 6, 7, 8},
						{1, 2, 3, 4, 5, 6, 7, 8},
						{1, 2, 3, 4, 5, 6, 7, 8} };

	int deck[16] = { 1, 2, 3, 4, 5, 6, 7, 8 }, rem[8][8];
	int r1, r2, c1, c2, a1, a2, b1, b2, marks = 0, random1 = 0, random2 = 0, temp = 0, matchs = 32, mis = 0;
public:
	Game()
	{
		r1 = 0; r2 = 0; c1 = 0; c2 = 0;
	}

	void space()
	{
		for (int i = 0; i < 2; i++)
		{
			cout << endl;
		}
	}


	void begin()
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		srand((unsigned)time(NULL));
		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				random1 = rand() % 8;
				random2 = rand() % 8;
				temp = cards[i][j];
				cards[i][j] = cards[random1][random2];
				cards[random1][random2] = temp;
				//cout << cards[random1][random2] << " ";
				rem[i][j] = 0;
			}
			cout << endl;
		}
		
		/*for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				cout << cards[i][j] << " ";
			}
			cout << endl;
		}*/

		space();
		cout << endl << endl << endl;

		for (int i = 0; i < 8; i++)
		{
			cout << "\t\t\t" << "+-----+-----+-----+-----+-----+-----+-----+-----+" << endl << "\t\t\t" << "| ";
			for (int j = 0; j < 8; j++)
			{
				cout << " * ";
				cout << " | ";
			}
			cout << endl;
		}
		cout << "\t\t\t" << "+-----+-----+-----+-----+-----+-----+-----+-----+" << endl << endl;
		
		input();
	}

	void input()
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 7);
		srand(time(0));
		cout << "\t\t\t" << "Row, Col = ";
		cin >> a1 >> b1;
		cout << "\t\t\t" << "Row, Col = ";
		cin >> a2 >> b2;
		system("CLS");

		r1=a1-1; r2=a2-1; c1=b1-1; c2=b2-1;
		
		cout << endl;

		space();

		for (int x = 0; x < 8; x++)
		{
			cout << "\t\t\t" << "+-----+-----+-----+-----+-----+-----+-----+-----+" << endl << "\t\t\t" << "| ";
			for (int y = 0; y < 8; y++)
			{
				if ((x == r1) && (y == c1))
				{
					cout << " ";
					SetConsoleTextAttribute(h, 6);
					cout << cards[x][y];
					SetConsoleTextAttribute(h, 7);
					cout << " " << " | ";
				}
				else if((x == r2) && (y == c2))
				{
					cout << " ";
					SetConsoleTextAttribute(h, 6);
					cout << cards[x][y];
					SetConsoleTextAttribute(h, 7);
					cout << " " << " | ";
				}
				else
				{
					SetConsoleTextAttribute(h, 7);
					cout << " * ";
					cout << " | ";
				}	
			}
			cout << endl;
		}
		cout << "\t\t\t" << "+-----+-----+-----+-----+-----+-----+-----+-----+" << endl << endl;

		match();
		
		
	}
		public: 
	
	void saveFile(string Malik, int score) {
		ofstream file;
		file.open("Medium.txt", std::ios_base::app);
		file << "Name: " << Malik  << "\n";
		file << "Score: " << score << "\n\n";
		file.close();
	}
	
	void  showHighestScore() {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 7);
		int previousHighest = 0;
		string line;
		ifstream myfile ("Medium.txt");
		if (myfile.is_open()) {
    		while ( getline (myfile,line) ) {
    			std::string str2 = line.substr(0,5);
    			if (str2.compare(0,5,"Score") == 0) {
    				std::string score = line.substr(7, line.length());
    				int value = atoi(score.c_str());
    				if (value >  previousHighest)
    					previousHighest = value;
    			}
    		}
    		myfile.close();
  		} else {
  			cout << "Unable to open file";
		}

  		cout << " Your Previous Highest Score is :  " << previousHighest;
	}
	void match()
	{

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		if (cards[r1][c1] == cards[r2][c2])
		{
			if(matchs == 0)
			{
				cout << "\t\t\t" << "You Won!" << endl;
				saveFile("Malik", marks);
				showHighestScore();
			}
			else
			{
				rem[r1][c1] = cards[r1][c1];
				rem[r2][c2] = cards[r2][c2];
				SetConsoleTextAttribute(h, 10);
				cout << "\t\t\t" << "Valid Match!" << endl;
				if(cards[r1][c1] == cards[r1][c1])
				marks += 2;
				matchs -= 1;
				SetConsoleTextAttribute(h, 11);
				cout << "\t\t\t" << "Points: " << marks << endl;
				input();
			}
		}
		
		else if((rem[r1][c1] == cards[r1][c1]) && (rem[r2][c2] == cards[r2][c2]))
		{
			cout<<"These are matched already!";
		}
		else
		{
			mis += 1;
			if(mis == 3)
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\t\t\t" << "You Lose!" << endl;
				saveFile("Malik", marks);
				showHighestScore();
			}
			else
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\t\t\t" << "Invalid Match!" << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "\t\t\t" << "Points: " << marks << endl;
				
				input();
			}
		}
		
		
	}

};

//Class for 16 x 16 Matrix

class Game2
{
private:
	int cards[16][16] = {	{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5},
							{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5},
							{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5},
							{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5},
							{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5},
							{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5},
							{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5},
							{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5}, 
							{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5},
							{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5},
							{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5},
							{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5},
							{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5},
							{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5},
							{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5},
							{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5} };

	int deck[16] = { 1, 2, 3, 4, 5, 6, 7, 8 }, rem[16][16];
	int r1, r2, c1, c2, a1, a2, b1, b2, marks = 0, random1 = 0, random2 = 0, temp = 0, matchs = 32, mis = 0;
public:
	Game()
	{
		r1 = 0; r2 = 0; c1 = 0; c2 = 0;
	}

	void space()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << endl;
		}
	}


	void begin()
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

		srand((unsigned)time(NULL));
		for(int i = 0; i < 16; i++)
		{
			for(int j = 0; j < 16; j++)
			{
				random1 = rand() % 16;
				random2 = rand() % 16;
				temp = cards[i][j];
				cards[i][j] = cards[random1][random2];
				cards[random1][random2] = temp;
				//cout << cards[random1][random2] << " ";
				rem[i][j] = 0;
			}
			cout << endl;
		}
		
		/*for(int i = 0; i < 16; i++)
		{
			for(int j = 0; j < 16; j++)
			{
				cout << cards[i][j] << " ";
			}
			cout << endl;
		}*/

		space();
		cout << endl << endl << endl;

		for (int i = 0; i < 16; i++)
		{
			cout << "\t\t\t\t\t" << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" <<
			 endl << "\t\t\t\t\t" << "| ";
			for (int j = 0; j < 16; j++)
			{
				cout << " * ";
				cout << " | ";
			}
			cout << endl;
		}
		cout << "\t\t\t\t\t" << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl << endl;
		
		input();
	}

	void input()
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 7);
		srand(time(0));
		cout << "\t\t\t\t\t" << "Row, Col = ";
		cin >> a1 >> b1;
		cout << "\t\t\t\t\t" << "Row, Col = ";
		cin >> a2 >> b2;
		system("CLS");

		r1=a1-1; r2=a2-1; c1=b1-1; c2=b2-1;
		
		cout << endl;

		space();

		for (int x = 0; x < 16; x++)
		{
			cout << "\t\t\t\t\t" << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" <<
			 endl << "\t\t\t\t\t" << "| ";
			for (int y = 0; y < 16; y++)
			{
				if ((x == r1) && (y == c1))
				{
					cout << " ";
					SetConsoleTextAttribute(h, 6);
					cout << cards[x][y];
					SetConsoleTextAttribute(h, 7);
					cout << " " << " | ";
				}
				else if((x == r2) && (y == c2))
				{
					cout << " ";
					SetConsoleTextAttribute(h, 6);
					cout << cards[x][y];
					SetConsoleTextAttribute(h, 7);
					cout << " " << " | ";
				}
				else
				{
					SetConsoleTextAttribute(h, 7);
					cout << " * ";
					cout << " | ";
				}	
			}
			cout << endl;
		}
		cout << "\t\t\t\t\t" << "+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl << endl;

		match();
		
		
	}
		public: 
	
	void saveFile(string Malik, int score) {
		ofstream file;
		file.open("Hard.txt", std::ios_base::app);
		file << "Name: " << Malik  << "\n";
		file << "Score: " << score << "\n\n";
		file.close();
	}
	
	void  showHighestScore() {
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 7);
		int previousHighest = 0;
		string line;
		ifstream myfile ("Hard.txt");
		if (myfile.is_open()) {
    		while ( getline (myfile,line) ) {
    			std::string str2 = line.substr(0,5);
    			if (str2.compare(0,5,"Score") == 0) {
    				std::string score = line.substr(7, line.length());
    				int value = atoi(score.c_str());
    				if (value >  previousHighest)
    					previousHighest = value;
    			}
    		}
    		myfile.close();
  		} else {
  			cout << "Unable to open file";
		}

  		cout << " Your Previous Highest Score is :  " << previousHighest;
	}
	
	void match()
	{

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		if (cards[r1][c1] == cards[r2][c2])
		{
			if(matchs == 0)
			{
				cout << "\t\t\t\t\t" << "You Won!" << endl;
			saveFile("Malik", marks);
				showHighestScore();
				}
			else
			{
				rem[r1][c1] = cards[r1][c1];
				rem[r2][c2] = cards[r2][c2];
				SetConsoleTextAttribute(h, 10);
				cout << "\t\t\t\t\t" << "Valid Match!" << endl;
				if(cards[r1][c1] == cards[r1][c1])
				marks += 2;
				matchs -= 1;
				SetConsoleTextAttribute(h, 11);
				cout << "\t\t\t\t\t" << "Points: " << marks << endl;
				input();
			}
		}
		
		else if((rem[r1][c1] == cards[r1][c1]) && (rem[r2][c2] == cards[r2][c2]))
		{
			cout<<"These are matched already!";
		}
		else
		{
			mis += 1;
			if(mis == 3)
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\t\t\t\t\t" << "You Lose!" << endl;
				saveFile("Malik", marks);
				showHighestScore();
			}
			else
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\t\t\t\t\t" << "Invalid Match!" << endl;
				SetConsoleTextAttribute(h, 11);
				cout << "\t\t\t\t\t" << "Points: " << marks << endl;
				input();
			}
		}
		
		
	}

};

int main()
{
		
	
	
	Game0 memoryMatch;
	Game1 memoryMatch1;
	Game2 memoryMatch2;
	

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	
	cout << endl << endl << endl << endl;
	SetConsoleTextAttribute(h, 10);
	cout << "\t\t\t\t" << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	cout << "\t\t\t\t" << "       Memory Matching Game      " << endl;
	cout << "\t\t\t\t" << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	cout<<endl<<endl;
	cout << "\t" << "A. Easy " << "\t" << "(4x4)" << endl;
	cout << "\t" << "B. Medium " << "\t" << "(8x8)" << endl;
	cout << "\t" << "C. Hard " << "\t" << "(16x16)" << endl;
	cout << "\t" << "D. Instructions" << endl;
	cout << "\t" << "E. Exit" << endl << endl;
	cout << "\t" << "Chose you mode accordingly!" << endl << endl;
	char op = getch();
	
	
	
	switch(op)
	{
		case 'a':
			SetConsoleTextAttribute(h, 7);
			memoryMatch.begin();
			break;
		case 'b':
			SetConsoleTextAttribute(h, 7);
			memoryMatch1.begin();
			break;
		case 'c':
			SetConsoleTextAttribute(h, 7);
			memoryMatch2.begin();
			break;
		case 'd':
			cout << endl << endl << endl << endl;
			SetConsoleTextAttribute(h, 1);
			
			cout << "\t\t\t\t" << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
			cout << "\t\t\t\t" << "           Instructions          " << endl;
			cout << "\t\t\t\t" << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
			cout << endl << endl;
			cout << "The following are the instructions for this game: " << endl << endl;
			cout << "\t" << "1. Select the which you want to play." << endl;
			cout << "\t" << "2. Enter Row & Col number for the 1st number, you wanna select!" << endl;
			cout << "\t" << "3. Similarly, enter the Row & Col for the 2nd number." << endl;
			cout << "\t" << "4. If the flipped cards match, you'll get the points!" << endl;
			cout << "\t" << "5. If the the flipped cards didn't match, you won't get the points." << endl;
			cout << "\t" << "6. If you mismatched the cards 3 times, the game will over and you will lose!" << endl;
			cout << "\t" << "7. If you matched all the cards, then you will win. Maximum score that you can achieve is:" ;
			cout << "\t"  <<"    16  points in  4*4   game "<<endl;
			cout << "\t"  <<"    64  points in  8*8   game "<<endl;
			cout << "\t"  <<"    256 points in 16*16 game
			break;
		case 'e':
			exit(0);
			break;
		default:
			SetConsoleTextAttribute(h, 4);
			cout << "\t" << "Invalid Input!" << endl;
	}
	
	SetConsoleTextAttribute(h, 7);
	cout << endl << endl; 	
	system("pause");
}
