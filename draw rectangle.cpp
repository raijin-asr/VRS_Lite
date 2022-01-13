//Creating quiz game in C++
#include <iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<mmsystem.h> //for sound


using namespace std;


//creating base class quizGame
class QuizGame
{
	private:
		//for question answer
		int i,op,points,ans1,attempt,correct,wrong; //i for loop, op for switch case and points for score,ans1 for ans
		char name[20], ch,answer,ans;	//player name, total attempt, correct and wrong ans count
		
		//Login part
		char pass[10];
		char un[10];
		char username[10]="admin";
		char password[10]="admin";
	
	public:
		QuizGame()
			{  //creating constructor for setting initial points as zero
				points=0;
				attempt=0;
				correct=0;
				wrong=0;
			}
	
		//system co-ordinates
		COORD coord={0,0}; 
		void gotoxy(int x, int y)
			{//creating func to go on particular place witht co-ordinate values
				coord.X=x; //x co-ordinate vaneko x bata pass vayeko value
				coord.Y=y; //y co-ordinate vankeo y bata pass vayera aaune value
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord); //for setting cursor position of x & y
			}

		//prototypes or function declarations
		void DrawRectangle();//for outer rectangle //we will write it's function outside class with scope resoluton operator
		void MainTitle();
		
};	//end of QuizGame class

//Main Title
void QuizGame::MainTitle()
{
	ifstream welfile("Welcome.txt");
	if(welfile.bad())
	{
		cout<<"Error in opening file....";
		getch();
		exit(1);
	}
	while(!welfile.eof())
	{
		welfile.get(ch);
		cout<<ch;
	}
	welfile.close();
}


//Animated Rectangle
void QuizGame::DrawRectangle()
{
	MainTitle();
	//top left point
	gotoxy(25,20);
	cout<<char(201) <<endl;
	//top line: Direction: Left->Right
	for (i = 26; i <= 142; i++)
	{
		gotoxy(i,20);
		cout<<char(205);
	}

	//top right point
	gotoxy(142,20);
	cout<<char(187) <<endl;
	//right side line: Direction: Up->Down
	for ( i = 21; i <=48; i++)
	{
		gotoxy(142,i);
		cout<<char(186);
	}

	//for bottom right point
	gotoxy(142,49);
	cout<<char(188) <<endl;
	//for bottom line: Direction: Right->Left
	for(i=141;i>=25;i--)
	{
		gotoxy(i,49);
		cout<<char(205);
	}

	//bottom left point
	gotoxy(25,49);
	cout<<char(200) <<endl;
	//Left side Line: Direction: Down-> Up
	for(i=48;i>=21;i--)
	{
		gotoxy(25,i);
		cout<<char(186);
	}

}

int main()
{
    system("color 3f");
	QuizGame obj;	
	system("PAUSE");
	obj.MainTitle();
//	obj.DrawRectangle();
	
	
	getch();
	return 0;
}