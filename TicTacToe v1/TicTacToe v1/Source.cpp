#include <iostream>
#include <cstdlib>

using namespace std;

void PrintBoard(char Board[10])
{
	system("cls");

	cout << "Tic Tac Toe!" << endl;

	cout << Board[1] << "|" << Board[2] << "|" << Board[3] << endl;
	cout << "-----" << endl;
	cout << Board[4] << "|" << Board[5] << "|" << Board[6] << endl;
	cout << "-----" << endl;
	cout << Board[7] << "|" << Board[8] << "|" << Board[9] << endl;
}

enum class eGameState
{
	eGameState_StillPlaying = 1,
	eGameState_Xwon = 2,
	eGameState_OWon = 3,
	eGameState_Draw = 4
};

bool isMovesLeft(char Board[10])
{
	for (int i = 1; i < 10; i++)
	{
		if (Board[i] != 'X')
		{
			if (Board[10] != 'O')
			{
				//return 0;
				cout << "no";
			}
		}
	}
	//return 1;
	cout << "yes";
	return 0;
}

char AskPlayerPlayAgain()
{
	char Choice = ' ';
	cout << "Do you want to play again? (y/n)" << endl;

	while (true)
	{
		cin >> Choice;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');

		}
		if (Choice == 'n' || Choice == 'y')
		{
			if (Choice == 'y')
			{
				cout << "Starting new Game!";
			}
			else if (Choice == 'n')
			{
				cout << "Bye!" << endl;
			}
			break;
		}
	}
	return Choice;
}

enum eGameState checkGameState(char Board[10])
{
	enum eGameState GameState = eGameState::eGameState_StillPlaying;

	if (Board[1] == Board[2] && Board[2] == Board[3])
	{
		char Mark = Board[1];
		if (Mark == 'X')
		{
			GameState = eGameState::eGameState_Xwon;
		}
		else
		{
			GameState = eGameState::eGameState_OWon;
		}

	}
	else if (Board[4] == Board[5] && Board[5] == Board[6])
	{
		char Mark = Board[4];
		if (Mark == 'X')
		{
			GameState = eGameState::eGameState_Xwon;
		}
		else
		{
			GameState = eGameState::eGameState_OWon;
		}

	}
	else if (Board[7] == Board[8] && Board[8] == Board[9])
	{
		char Mark = Board[7];
		if (Mark == 'X')
		{
			GameState = eGameState::eGameState_Xwon;
		}
		else
		{
			GameState = eGameState::eGameState_OWon;
		}

	}
	else if (Board[1] == Board[4] && Board[4] == Board[7])
	{
		char Mark = Board[1];
		if (Mark == 'X')
		{
			GameState = eGameState::eGameState_Xwon;
		}
		else
		{
			GameState = eGameState::eGameState_OWon;
		}

	}
	else if (Board[2] == Board[5] && Board[5] == Board[8])
	{
		char Mark = Board[2];
		if (Mark == 'X')
		{
			GameState = eGameState::eGameState_Xwon;
		}
		else
		{
			GameState = eGameState::eGameState_OWon;
		}

	}
	else if (Board[3] == Board[6] && Board[6] == Board[9])
	{
		char Mark = Board[1];
		if (Mark == 'X')
		{
			GameState = eGameState::eGameState_Xwon;
		}
		else
		{
			GameState = eGameState::eGameState_OWon;
		}
	}
	else if (Board[1] == Board[5] && Board[5] == Board[9])
	{
		char Mark = Board[1];
		if (Mark == 'X')
		{
			GameState = eGameState::eGameState_Xwon;
		}
		else
		{
			GameState = eGameState::eGameState_OWon;
		}
	}
	else if (Board[3] == Board[5] && Board[5] == Board[7])
	{
		char Mark = Board[3];
		if (Mark == 'X')
		{
			GameState = eGameState::eGameState_Xwon;
		}
		else
		{
			GameState = eGameState::eGameState_OWon;
		}
	}
	else if (Board[1] != '1' && Board[2] != '2' && Board[3] != '3'
		&& Board[4] != '4' && Board[5] != '5' && Board[6] != '6'
		&& Board[7] != '7' && Board[8] != '8' && Board[9] != '9')
	{
		GameState = eGameState::eGameState_Draw;
	}
	return GameState;
};

int main()
{
	char PlayerChoice = 'y';

	while (PlayerChoice == 'y')
	{
		int ScoreX = 0;
		int ScoreO = 0;
		char Player = 'X';
		char Board[10] = { '0','1','2','3','4','5','6','7','8','9' };
		

		enum eGameState GameState = eGameState::eGameState_StillPlaying;

		while (GameState == eGameState::eGameState_StillPlaying)
		{
			system("cls");

			PrintBoard(Board);

			//Input
			cout << "Player " << Player << " choose your field: ";
			int Position;
			cin >> Position;
		

			//Validating input
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}

			//Position on board
			if (Position >= 1 && Position <= 9 && Board[Position] != 'X' && Board[Position] != 'O')
			{
				Board[Position] = Player;
			}
			else continue;

			//Game over
			GameState = checkGameState(Board);

			if (GameState == eGameState::eGameState_Xwon)
			{
				PrintBoard(Board);

				ScoreX = ScoreX + 1;

				cout << "Player X won!" << endl;
				cout << "Player X:" << ScoreX << " - " << "Player O:" << ScoreO << endl << endl;

				PlayerChoice = AskPlayerPlayAgain();
			}
			else if (GameState == eGameState::eGameState_OWon)
			{
				PrintBoard(Board);

				ScoreO = ScoreO + 1;

				cout << "Player O won!" << endl;
				cout << "Player X:" << ScoreX << " - " << "Player O:" << ScoreO << endl << endl;

				PlayerChoice = AskPlayerPlayAgain();

				
			}
			else if (GameState == eGameState::eGameState_Draw)
			{
				PrintBoard(Board);

				cout << "Draw!" << endl;

				PlayerChoice = AskPlayerPlayAgain();
			}
			else
			{
				//Switch player
				Player = (Player == 'X') ? 'O' : 'X';
			}

		}
	}
}