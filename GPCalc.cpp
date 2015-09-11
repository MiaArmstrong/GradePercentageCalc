#include <iostream>
using namespace std;

int  getScore();
void pause();
int  getNum();
char getReply();


int main()
{
		

	cout << "Welcome to CS162 Grade Percentage Caluculator! \n\n" << endl;

	while(true)
	{
		int num = 0;
		int  score = 0;
		int  scoreTotal = 0;
		int  avgScore = 0;
		int  midterm = 0;
		int  final = 0;
		int  grade = 0;
		char answer;
		char answer2;
		char reply;
		int  i = 1;
		num = getNum();

		do
		{
			cout << "Please enter your score for program " << i ;
			score = getScore();
			cout << "Score: " << score << "%" << endl;
			scoreTotal = scoreTotal + score;
			i++;
		}while (i <= num);
		avgScore = scoreTotal/num;
		cout << "Average score for programs is: " << avgScore << "% " << endl;
		cout << "Do you have a midterm score to enter? (y/n) ";
		answer = getReply();
		
		switch(answer)
		{
		case'n':
			
				grade = (avgScore * 35)/35;
				cout << "Your current grade is " << grade << "%."<< endl;
				break;

		case'y':
			
				cout << "Please enter your score";
				midterm = getScore();
				cout << "Score: " << midterm << "%" << endl;
				cout << "Do you have a final exam score to enter? (y/n) ";
				answer2 = getReply();
				
				switch(answer2)
				{
					case'n':
					
						grade = ((avgScore * 35) + (midterm * 25))/60;
						cout << "Your current grade is " << grade << "%."<< endl;
						break;

				case'y':
						cout << "Please enter your score";
						final = getScore();
						cout << "Score: " << final << "%" << endl;
						grade = ((avgScore * 35) + (midterm * 25) + (final * 40))/100;
						cout << "Your current grade is " << grade << "%."<< endl;
						break;
				}
				break;
			
		}
		cout << "Would you like to recalculate your grade? (y/n) ";
		reply = getReply();
		
		switch(reply)
		{
		case'y':
			break;

		case'n':
			
				pause();
				return 0;
		}		
		
	}
}
int getNum()
{
	int num;
	cout << "How many programs do you have grades for? ";
	cin >> num;

	cin.ignore(100, '\n');
	while (true)
	{
		if(!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "It has to be a legal integer! Please try again: ";
			cin >> num;
		}
		else if(num < 1 || num > 5)
		{
			cout << "Number must be between 1 and 5! Try again: ";
			cin >> num;	
		}
		else
		return num;
	}
}
int getScore()
{
	int score;
	cout << ": ";
	cin >> score;
	cin.ignore(100, '\n');
	while (true)
	{
		if(!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "It has to be a legal integer! Please try again: ";
			cin >> score;
		}
		else if(score < 0 || score > 100)
		{
			cout << "Score must be between 0 and 100! Try again: ";
			cin >> score;	
		}
		else
		return score;
	}
}
char getReply()
{
	char reply;
	cin >> reply;
	if (isupper(reply)) reply=tolower(reply);
	cin.ignore(100, '\n');
	while(true)
	{
		if(reply == 'y' || reply == 'n')
		{
			return reply;
		}
		else
			cout << "Please enter y for yes or n for no. (y/n) ";
			cin >> reply;

	}
}


void pause()
{
	char ch;
	cout << "Please press any key to continue ..." << endl;
	cin >> ch;
}