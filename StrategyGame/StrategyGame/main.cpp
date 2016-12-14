#include "Player.h"
#include <iostream>
#include <conio.h>
#include <math.h>
#include "ConsoleFunctions.h"
using namespace KSUN;

void DrawBoard();
char* shuffle(char* toShuffle, unsigned int stringSize);
void Update(Player& player1, Player& player2);
//bool WarriorEnemyAdjacentCheck(Warrior& p1, Player& p2);
bool WinCheck(Player& p1, Player& p2);

int main(int argc, char** argv)
{
	bool replay = true;
	while (replay)
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		Player player1("PLAYER 1", PLAYER_1);
		Player player2("PLAYER 2", PLAYER_2);
		char pieces[6] = { 'W', 'w', 'A', 'a', 'S', 's' };
		while (true)
		{
			// Randomize Turn Order
			shuffle(pieces, 6);
			// Draw Board
			DrawBoard();
			Console::ResetColor();
			Update(player1, player2);
			Console::ResetColor();
			// Display Insutructions
			Console::SetCursorPosition(25, 0);
			std::cout << "Move/Attack with Arrow Keys.";
			Console::SetCursorPosition(25, 1);
			std::cout << "Press 'p' to Skip Phase.";
			// Display Turn Order
			Console::SetCursorPosition(8, 0);
			std::cout << "Turn Order";
			for (unsigned int i = 0; i < 6; i++)
			{
				Console::SetCursorPosition(8, 1 + i);
				std::cout << pieces[i];
			}

			for (unsigned int i = 0; i < 6; i++)
			{
				switch (pieces[i])
				{
				case 'W':
				{
					Console::SetCursorPosition(8, 1 + i);
					Console::ForegroundColor(Green);
					std::cout << pieces[i];
					Console::ResetColor();
					if (!(player1.GetWarriorIsDead()))
					{
						player1.MoveWarrior(player1, player2);
						Update(player1, player2);
						player1.WarriorAttack(player2);
						Update(player1, player2);
					}
				}
					break;
				case 'w':
				{
					Console::SetCursorPosition(8, 1 + i);
					Console::ForegroundColor(Green);
					std::cout << pieces[i];
					Console::ResetColor();
					if (!(player2.GetWarriorIsDead()))
					{
						player2.MoveWarrior(player2, player1);
						Update(player1, player2);
						player2.WarriorAttack(player1);
						Update(player1, player2);
					}
				}
					break;
				case 'A':
				{
					Console::SetCursorPosition(8, 1 + i);
					Console::ForegroundColor(Green);
					std::cout << pieces[i];
					Console::ResetColor();
					if (!(player1.GetArcherIsDead()))
					{
						player1.MoveArcher(player1, player2);
						Update(player1, player2);
						player1.ArcherAttack(player2);
						Update(player1, player2);
					}
				}
					break;
				case 'a':
				{
					Console::SetCursorPosition(8, 1 + i);
					Console::ForegroundColor(Green);
					std::cout << pieces[i];
					Console::ResetColor();
					if (!(player2.GetArcherIsDead()))
					{
						player2.MoveArcher(player2, player1);
						Update(player1, player2);
						player2.ArcherAttack(player1);
						Update(player1, player2);
					}
				}
					break;
				case 'S':
				{
					Console::SetCursorPosition(8, 1 + i);
					Console::ForegroundColor(Green);
					std::cout << pieces[i];
					Console::ResetColor();
					if (!(player1.GetSorcererIsDead()))
					{
						player1.MoveSorcerer(player1, player2);
						Update(player1, player2);
						player1.SorcererAttack(player2);
						Update(player1, player2);
					}
				}
					break;
				case 's':
				{
					Console::SetCursorPosition(8, 1 + i);
					Console::ForegroundColor(Green);
					std::cout << pieces[i];
					Console::ResetColor();
					if (!(player2.GetSorcererIsDead()))
					{
						player2.MoveSorcerer(player2, player1);
						Update(player1, player2);
						player2.SorcererAttack(player1);
						Update(player1, player2);
					}
				}
					break;
				default:
					break;
				}
			}
			if (WinCheck(player1, player2))
			{
				Console::SetCursorPosition(0, Console::WindowHeight() - 1);
				std::cout << "Would You Like To Play Again? Y/N";
				bool input = false;
				while (!input)
				{
					if (_kbhit())
					{
						char ch = _getch();
						switch (ch)
						{
						case 'y':
						{
							replay = true;
							input = true;
						}
							break;
						case 'n':
						{
							replay = false;
							input = true;
						}
						default:
							break;
						}
					}
				}
				return 0;
			}
		}
	}
	return 0;
}

void DrawBoard()
{
	for (unsigned int r = 0; r < 6; r++)
	{
		for (unsigned int c = 0; c < 6; c++)
		{
			if ((r % 2) == 0)
			{
				if ((c % 2) == 0)
				{
					Console::ForegroundColor(White);
					Console::BackgroundColor(Black);
				}
				else
				{
					Console::ForegroundColor(Black);
					Console::BackgroundColor(White);
				}
			}
			else
			{
				if ((c % 2) == 0)
				{
					Console::ForegroundColor(Black);
					Console::BackgroundColor(White);
				}
				else
				{
					Console::ForegroundColor(White);
					Console::BackgroundColor(Black);
				}
			}
			Console::SetCursorPosition(c, r);
			std::cout << '*';
		}
	}
}

char* shuffle(char* toShuffle, unsigned int arrSize)
{
	if (arrSize > 1)
	{
		for (unsigned int i = 0; i < arrSize - 1; i++)
		{
			unsigned int newSpot = i + rand() / (RAND_MAX / (arrSize - i) + i);
			char tmp = toShuffle[newSpot];
			toShuffle[newSpot] = toShuffle[i];
			toShuffle[i] = tmp;
		}
	}
	return toShuffle;
}

void Update(Player& player1, Player& player2)
{
	Console::ResetColor();
	// Draw Pieces to Board
	player1.DisplayWarrior(player1.GetWarriorX(), player1.GetWarriorY());
	player1.DisplayArcher(player1.GetArcherX(), player1.GetArcherY());
	player1.DisplaySorcerer(player1.GetSorcererX(), player1.GetSorcererY());
	player2.DisplayWarrior(player2.GetWarriorX(), player2.GetWarriorY());
	player2.DisplayArcher(player2.GetArcherX(), player2.GetArcherY());
	player2.DisplaySorcerer(player2.GetSorcererX(), player2.GetSorcererY());
	Console::ResetColor();
	std::cout << "\n\n\n\n";
	// Display Player Info
	Console::SetCursorPosition(0, 8);
	std::cout << player1.GetName() << ": " << "W: " << player1.GetWarriorHealth() << "/20" << ", "
		<< "A: " << player1.GetArcherHealth() << "/20" << ", "
		<< "S: " << player1.GetSorcererHealth() << "/20      ";
	std::cout << '\n';
	std::cout << player2.GetName() << ": " << "W: " << player2.GetWarriorHealth() << "/20" << ", "
		<< "A: " << player2.GetArcherHealth() << "/20" << ", "
		<< "S: " << player2.GetSorcererHealth() << "/20      ";
}

bool WinCheck(Player& p1, Player& p2)
{
	if (p1.GetWarriorIsDead() && p1.GetArcherIsDead() && p1.GetSorcererIsDead())
	{
		Console::SetCursorPosition(0, 20);
		std::cout << "Player 2 Wins!";
		return true;
	}

	else if (p2.GetWarriorIsDead() && p2.GetArcherIsDead() && p2.GetSorcererIsDead())
	{
		Console::SetCursorPosition(0, 20);
		std::cout << "Player 1 Wins!";
		return true;
	}
	return false;
}