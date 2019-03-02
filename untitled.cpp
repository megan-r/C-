#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;


struct Player
{
	char name[100];
	int number;
	int score;
};

const int teamsize = 6;

void getPlayerInfo(Player &p)
{
	cout << "Player name: ";
	cin.getline(p.name, 100);
	cout << "Player's number: ";
	while ((cin >> p.number) && (p.number < 0))
	{
		cout << "enter valid number: " << endl;
	}
	cout << "Points scored: ";
	while ((cin >> p.score) && (p.score < 0))
	{
		cout << "enter valid number: " << endl;
	}
}
// prints the inputs in table format
void setPlayerInfo(Player print)
{
	cout << setw(10) << print.name << setw(10) << print.number << setw(10) << print.score << endl;
}
// Creates int total and adds all array values to total
int getTotalPoints(Player points[], int size)
{
	int total = 0;
	for (int index = 0; index < size; index++)
		total = total + points[index].score;
	return total;
}
//Uses array, compares 2 numbers at a time, moves bigger number to highscore
void setHighestScore(Player points[], int size)
{
	int highest = 0;
	int placeholder = points[0].score;

	for (int index = 1; index < size; index++)
	{
		if (points[index].score > placeholder)
		{
			highest = index;
			placeholder = points[index].score;
		}
	}
	cout << "Most points scored by: ";
	cout << points[highest].name << endl;
	cout << "Their score was: ";
	cout << points[highest].score << endl;
}


int main()
{
	Player roster[teamsize];
	int index;

	for (index = 0; index < teamsize; index++)
	{
		cout << "\nPlayer #" << (index + 1) << "\n";
		getPlayerInfo(roster[index]);
		cin.get();
	}


	cout.setf(ios::left);
	cout << setw(10) << "\nName" << setw(10) << "Number" << setw(10);
	cout << "Points scored\n";
	for (index = 0; index < teamsize; index++)
		setPlayerInfo(roster[index]);
	cout << "Total Points: " << getTotalPoints(roster, teamsize) << endl;
	setHighestScore(roster, teamsize);
	system("PAUSE");
}