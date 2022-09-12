#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>

#define MAX_PLAYERS 10

using namespace std;

/*
	Class representing an N-sided die
*/
class Dice
{
private:
	int numSides;

public:
	// Perform a single roll of the die
	int roll()
	{
		return (rand() % numSides + 1);
	}
	void SetNumSides(int numsides)
	{
		numSides = numsides;
	}
};
/*
	Class representing a Game Player
*/
class Player
{
private:
	string name;
	int score;

public:
	// Getter : Player Name
	string getName()
	{
		return name;
	}
	// Getter : Score
	int getScore()
	{
		return score;
	}
	// Increases the player's score by a specified value
	void addToScore(int val)
	{
		score = score + val;
	}
	Player(string username, int userscore)
	{
		name = username;
		score = userscore;
	}
};
/*
	Abstract class DiceGame
*/
class DiceGame
{
protected:
	Player *players[MAX_PLAYERS];
	Dice *dice;
	int numPlayers, numDice;

public:
	//	Pure virtual function
	// virtual void play() = 0;
	void initPlayers()
	{
		cout << "Enter the number of players: ";
		cin >> numPlayers;

		int i = 0;
		while (i < numPlayers)
		{
			cout << "Enter the name of player " << i + 1 << ": ";
			string username;
			cin >> username;
			cout << "Enter a score: ";
			int userscore;
			cin >> userscore;
			players[i] = new Player(username, userscore);
			i++;
		}
	}
	void displayScores()
	{
		cout << "Scores:" << endl;
		int i = 0;
		for (i = 0; i < numPlayers; i++)
		{
			cout << players[i]->getName() << ": " << players[i]->getScore() << endl;
		}
	}

	int getNumPlayers()
	{
		return this->numPlayers;
	}

	int testVal()
	{
		return 9999;
	}
	void writeScoresToFile()
	{
		std::ofstream outfile;
		outfile.open("scores.txt", std::ios_base::app);
		for (int i = 0; i < numPlayers; i++)
		{
			outfile << players[i]->getName() << ": " << players[i]->getScore() << endl;
			
		}
		outfile.close();
	}
	string getHighestScore()
	{

	}
};

class KnockOut : public DiceGame
{
	//knockout
	// roll N die and sum up total
	// total = knockout score
	// loop players taking turns rolling die and total each turn
	// do while total != knockout score
	// if total = knockout score then player is knocked out
	// play until one player is left
protected:
	//DiceGame *Knockout = new DiceGame;

public:
	void play(int numDice, int numsides)
	{
		initPlayers();
		int NP = getNumPlayers();

		Dice *die = new Dice;
		die->SetNumSides(numsides);

		int KnockOutScore = 0;
		for (int i = 0; i < numDice; i++)
		{
			int num = die->roll();
			KnockOutScore += num;
		}
		cout << "The Knock Out score is: " << KnockOutScore << endl;

		while (NP > 1)
		{

			for (unsigned int i = 0; i < NP; i++)
			{
				cout << players[i]->getName() << "'s turn: " << endl;
				int playerScore = 0;
				for (int i = 0; i < numDice; i++)
				{
					int num = die->roll();
					playerScore += num;
				}
				cout << players[i]->getName() << " scored a total of " << playerScore << "!" << endl;
				if (playerScore == KnockOutScore)
				{
					cout << players[i]->getName() << " is KNOCKED OUT!" << endl
						 << endl;

					for (int index = i; index < NP; index++)
					{
						players[index] = players[index + 1];
					}

					//if players[i] is NULL then i= +1
					NP -= 1;
				}
				else
				{
					cout << players[i]->getName() << " is safe!" << endl
						 << endl;
				}
			}
		}

		cout << players[0]->getName() << " is the winner!" << endl;
		players[0]->addToScore(69);
		writeScoresToFile();
	}
};

class Boston : public DiceGame
{
private:
public:
	void play(int numDice, int numsides)
	{
		initPlayers();

		int NP = getNumPlayers();

		Dice *die = new Dice;
		die->SetNumSides(numsides);
		for (int i = 0; i < NP; i++)
		{
			players[i]->addToScore(diceroll(die, numDice, players[i]->getScore()));
			displayScores();
		}
		
		writeScoresToFile();

		// roll dice numdice times and add highest val to player score
		//roll n-1 dice and addd highest val to score
		//RECURSION!!!
		//iterate one time using for loop
	}
	int diceroll(Dice *dice, int numDice, int totalScore)
	{
		int highVal = 0;
		int currVal;

		while (numDice > 0)
		{

			for (int i = 0; i < numDice; i++)
			{
				currVal = dice->roll();

				if (currVal > highVal)
				{
					highVal = currVal;
					cout << highVal << endl;	
				}
			}
			totalScore += highVal;
			cout << "ND to reroll: " << numDice-1 << endl;
			cout << "TS: " << totalScore << endl;
			
			numDice = numDice - 1;
			cout << "ND: " << numDice << endl;
			if (numDice == 0)
			{
				cout << "ND is 0" << endl;
				return totalScore;
				break;
			}
			diceroll(dice, numDice, totalScore);
		}

		return totalScore;
	}
};
int main()
{
	srand((unsigned)time(0));
	// Base class pointer
	//DiceGame *game = new DiceGame;
	//cout << "Would you like to play Boston (1) or KnockOut (2)? ";
	//int gameType;
	//cin >> gameType;
	// task 5
	//DiceGame *game = new Boston;
	//Boston objBoston;
	//if (gameType == 1)
	//{
	//	objBoston.play();
	//}
	//task 4
	//DiceGame *game = new KnockOut;
	//KnockOut knockout;
	//if (gameType == 2)
	//{
	//knockout.play();
	//}
	// task 3 output
	//game -> initPlayers();
	//game -> displayScores();

	//task 2 output
	//Player p("test", 17);
	//cout << p.getName()<<endl;
	//cout << p.getScore()<<endl;
	//p.addToScore(10);

	//task 1 output
	//Dice run (100);
	//run.roll();
	int numDice;
	int gameNum = 1;

	cout << "Enter the number of die: ";
	cin >> numDice;
	cout << "Enter the number of dice sides: ";
	int numsides;
	cin >> numsides;

	DiceGame *game;
	game = new(nothrow) KnockOut;
	KnockOut objKO;
	objKO.play(numDice, numsides);
	cout << "Would you like to play KO(1) or Boston DiceGame(2)? ";
	int gameType;
	cin >> gameType;
	if (gameType == 1)
	{
		cout << "Enter the number of die: ";
		cin >> numDice;
		cout << "Enter the number of dice sides: ";
		cin >> numsides;
		objKO.play(numDice, numsides);
	}
	else
	{
		game = new(nothrow) Boston;
		Boston objB;
		cout << "Enter the number of die: ";
		cin >> numDice;
		cout << "Enter the number of dice sides: ";
		cin >> numsides;
		objB.play(numDice, numsides);
	}
	//game->getHighestScore();

	return 0;
}
