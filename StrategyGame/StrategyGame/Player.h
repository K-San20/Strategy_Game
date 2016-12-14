#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <iostream>
#include <ctime>
#include <conio.h>
//using namespace std;
//#include "Warrior.h"
//#include "Archer.h"
//#include "Sorcerer.h"
#include "ConsoleFunctions.h"
using namespace KSUN;

enum PLAYER_ID{ PLAYER_1, PLAYER_2 };
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Player
{
public:
#pragma region Warrior Struct
	struct Warrior
	{
		char symbol;
		int health;
		unsigned int atkRange;
		unsigned int minAtkDamage;
		unsigned int maxAtkDamage;
		bool isDead;
		int posX;
		int posY;
		//public:
		Warrior(char sym)
		{
			symbol = sym;
			health = 20;
			atkRange = 1;
			minAtkDamage = 7;
			maxAtkDamage = 14;
			isDead = false;
		}
		// Accessors
		char GetSymbol(){ return symbol; }
		int GetHealth(){ return health; }
		unsigned int GetAtkRange(){ return atkRange; }
		unsigned int GetMinAtkDamage(){ return minAtkDamage; }
		unsigned int GetMaxAtkDamage(){ return maxAtkDamage; }
		bool GetIsDead(){ return isDead; }
		// Mutators
		void SetSymbol(char sym){ symbol = sym; }
		void SetHealth(int hp){ health = hp; }
		void SetAttkRange(unsigned int atkR){ atkRange = atkR; }
		void SetMinAtkDamage(unsigned int minAtkD){ minAtkDamage = minAtkD; }
		void SetMaxAtkDamage(unsigned int maxAtkD){ minAtkDamage = maxAtkD; }
		void SetIsDead(bool dead){ isDead = dead; }
		// Turn Options
		void Move(Player& p1, Player& p2)
		{
			Console::SetCursorPosition(15, 3);
			Console::ForegroundColor(Yellow);
			std::cout << " Move Phase ";
			Console::ResetColor();
			bool input = false;
			while (!input)
			{
				if (_kbhit())
				{
					int c = _getch();
					switch (c)
					{
					case KEY_UP:
					{
						Console::SetCursorPosition(posX, posY);
						if ((posY % 2) == 0)
						{
							if ((posX % 2) == 0)
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
							if ((posX % 2) == 0)
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
						Console::SetCursorPosition(posX, posY);
						std::cout << '*';
						posY--;
						if (posY < 0
							|| posY > 6
							|| (posX == p2.GetWarriorX() && posY == p2.GetWarriorY())
							|| (posX == p2.GetArcherX() && posY == p2.GetArcherY())
							|| (posX == p2.GetSorcererX() && posY == p2.GetSorcererY())
							|| (posX == p1.GetArcherX() && posY == p1.GetArcherX())
							|| (posX == p1.GetSorcererX() && posY == p1.GetSorcererY()))
						{
							posY++;
						}
						input = true;
					}
						break;
					case KEY_DOWN:
					{
						Console::SetCursorPosition(posX, posY);
						if ((posY % 2) == 0)
						{
							if ((posX % 2) == 0)
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
						Console::SetCursorPosition(posX, posY);
						std::cout << '*';
						posY++;
						if (posY < 0
							|| posY > 6
							|| (posX == p2.GetWarriorX() && posY == p2.GetWarriorY())
							|| (posX == p2.GetArcherX() && posY == p2.GetArcherY())
							|| (posX == p2.GetSorcererX() && posY == p2.GetSorcererY())
							|| (posX == p1.GetArcherX() && posY == p1.GetArcherX())
							|| (posX == p1.GetSorcererX() && posY == p1.GetSorcererY()))
						{
							posY--;
						}
						input = true;
					}
						break;
					case KEY_LEFT:
					{
						Console::SetCursorPosition(posX, posY);
						if ((posY % 2) == 0)
						{
							if ((posX % 2) == 0)
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
						Console::SetCursorPosition(posX, posY);
						std::cout << '*';
						posX--;
						if (posX < 0
							|| posX > 6
							|| (posX == p2.GetWarriorX() && posY == p2.GetWarriorY())
							|| (posX == p2.GetArcherX() && posY == p2.GetArcherY())
							|| (posX == p2.GetSorcererX() && posY == p2.GetSorcererY())
							|| (posX == p1.GetArcherX() && posY == p1.GetArcherX())
							|| (posX == p1.GetSorcererX() && posY == p1.GetSorcererY()))
						{
							posX++;
						}
						input = true;
					}
						break;
					case KEY_RIGHT:
					{
						Console::SetCursorPosition(posX, posY);
						if ((posY % 2) == 0)
						{
							if ((posX % 2) == 0)
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
						Console::SetCursorPosition(posX, posY);
						std::cout << '*';
						posX++;
						if (posX < 0
							|| posX > 6
							|| (posX == p2.GetWarriorX() && posY == p2.GetWarriorY())
							|| (posX == p2.GetArcherX() && posY == p2.GetArcherY())
							|| (posX == p2.GetSorcererX() && posY == p2.GetSorcererY())
							|| (posX == p1.GetArcherX() && posY == p1.GetArcherX())
							|| (posX == p1.GetSorcererX() && posY == p1.GetSorcererY()))
						{
							posX--;
						}
						input = true;
					}
						break;
					case (int)'p':
					{
						input = true;
					}
						break;
					}
				}
			}
		}
		void Attack(Player& player)
		{
			Console::SetCursorPosition(15, 3);
			Console::ForegroundColor(Yellow);
			std::cout << "Attack Phase";
			Console::ResetColor();
			bool input = false;
			while (!input)
			{
				if (_kbhit())
				{
					int c = _getch();
					switch (c)
					{
					case KEY_UP:
					{
						posY--;
						if ((posX == player.GetWarriorX() && posY == player.GetWarriorY()) && (posX == player.GetWarriorX()))
						{

							if (!player.GetWarriorIsDead())
							{
								int damage = (rand() % 14 - 7 + 1) + 7;
								player.SetWarriorHealth(player.GetWarriorHealth() - damage);
								if (player.GetWarriorHealth() <= 0)
								{
									player.SetWarriorIsDead(true);
									player.SetWarriorSymbol('D');
								}
							}
						}
						else if ((posX == player.GetArcherX() && posY == player.GetArcherY()) && (posX == player.GetArcherX()))
						{

							if (!player.GetArcherIsDead())
							{
								int damage = (rand() % 14 - 7 + 1) + 7;
								player.SetArcherHealth(player.GetArcherHealth() - damage);
								if (player.GetArcherHealth() <= 0)
								{
									player.SetArcherIsDead(true);
									player.SetArcherSymbol('D');
								}
							}
						}
						else if ((posX == player.GetSorcererX() && posY == player.GetSorcererY()) && (posX == player.GetSorcererX()))
						{

							if (!player.GetSorcererIsDead())
							{
								int damage = (rand() % 14 - 7 + 1) + 7;
								player.SetSorcererHealth(player.GetSorcererHealth() - damage);
								if (player.GetSorcererHealth() <= 0)
								{
									player.SetSorcererIsDead(true);
									player.SetSorcererSymbol('D');
								}
							}
						}
						posY++;
						input = true;
					}
						break;
					case KEY_DOWN:
					{
						posY++;
						if ((posX == player.GetWarriorX() && posY == player.GetWarriorY()) && (posX == player.GetWarriorX()))
						{

							if (!player.GetWarriorIsDead())
							{
								int damage = (rand() % 14 - 7 + 1) + 7;
								player.SetWarriorHealth(player.GetWarriorHealth() - damage);
								if (player.GetWarriorHealth() <= 0)
								{
									player.SetWarriorHealth(0);
									player.SetWarriorIsDead(true);
									player.SetWarriorSymbol('D');
								}
							}
						}
						else if ((posX == player.GetArcherX() && posY == player.GetArcherY()) && (posX == player.GetArcherX()))
						{

							if (!player.GetArcherIsDead())
							{
								int damage = (rand() % 14 - 7 + 1) + 7;
								player.SetArcherHealth(player.GetArcherHealth() - damage);
								if (player.GetArcherHealth() <= 0)
								{
									player.SetArcherHealth(0);
									player.SetArcherIsDead(true);
									player.SetArcherSymbol('D');
								}
							}
						}
						else if ((posX == player.GetSorcererX() && posY == player.GetSorcererY()) && (posX == player.GetSorcererX()))
						{

							if (!player.GetSorcererIsDead())
							{
								int damage = (rand() % 14 - 7 + 1) + 7;
								player.SetSorcererHealth(player.GetSorcererHealth() - damage);
								if (player.GetSorcererHealth() <= 0)
								{
									player.SetSorcererHealth(0);
									player.SetSorcererIsDead(true);
									player.SetSorcererSymbol('D');
								}
							}
						}
						posY--;
						input = true;
					}
						break;
					case KEY_LEFT:
					{
						posX--;
						if ((posX == player.GetWarriorX() && posY == player.GetWarriorY()) && (posY == player.GetWarriorY()))
						{

							if (!player.GetWarriorIsDead())
							{
								int damage = (rand() % 14 - 7 + 1) + 7;
								player.SetWarriorHealth(player.GetWarriorHealth() - damage);
								if (player.GetWarriorHealth() <= 0)
								{
									player.SetWarriorIsDead(true);
									player.SetWarriorSymbol('D');
								}
							}
						}
						else if ((posX == player.GetArcherX() && posY == player.GetArcherY()) && (posY == player.GetArcherY()))
						{

							if (!player.GetArcherIsDead())
							{
								int damage = (rand() % 14 - 7 + 1) + 7;
								player.SetArcherHealth(player.GetArcherHealth() - damage);
								if (player.GetArcherHealth() <= 0)
								{
									player.SetArcherIsDead(true);
									player.SetArcherSymbol('D');
								}
							}
						}
						else if ((posX == player.GetSorcererX() && posY == player.GetSorcererY()) && (posY == player.GetSorcererY()))
						{

							if (!player.GetSorcererIsDead())
							{
								int damage = (rand() % 14 - 7 + 1) + 7;
								player.SetSorcererHealth(player.GetSorcererHealth() - damage);
								if (player.GetSorcererHealth() <= 0)
								{
									player.SetSorcererIsDead(true);
									player.SetSorcererSymbol('D');
								}
							}
						}
						posX++;
						input = true;
					}
						break;
					case KEY_RIGHT:
					{
						posX++;
						if ((posX == player.GetWarriorX() && posY == player.GetWarriorY()) && (posY == player.GetWarriorY()))
						{

							if (!player.GetWarriorIsDead())
							{
								int damage = (rand() % 14 - 7 + 1) + 7;
								player.SetWarriorHealth(player.GetWarriorHealth() - damage);
								if (player.GetWarriorHealth() <= 0)
								{
									player.SetWarriorIsDead(true);
									player.SetWarriorSymbol('D');
								}
							}
						}
						else if ((posX == player.GetArcherX() && posY == player.GetArcherY()) && (posY == player.GetArcherY()))
						{

							if (!player.GetArcherIsDead())
							{
								int damage = (rand() % 14 - 7 + 1) + 7;
								player.SetArcherHealth(player.GetArcherHealth() - damage);
								if (player.GetArcherHealth() <= 0)
								{
									player.SetArcherIsDead(true);
									player.SetArcherSymbol('D');
								}
							}
						}
						else if ((posX == player.GetSorcererX() && posY == player.GetSorcererY()) && (posY == player.GetSorcererY()))
						{

							if (!player.GetSorcererIsDead())
							{
								int damage = (rand() % 14 - 7 + 1) + 7;
								player.SetSorcererHealth(player.GetSorcererHealth() - damage);
								if (player.GetSorcererHealth() <= 0)
								{
									player.SetSorcererIsDead(true);
									player.SetSorcererSymbol('D');
								}
							}
						}
						posX--;
						input = true;
					}
						break;
					case (int)'p':
					{
						input = true;
					}
						break;
					}
				}
			}
		}
	};
#pragma endregion
#pragma region Archer Struct
	struct Archer
	{
		char symbol;
		int health;
		unsigned int atkRange;
		unsigned int minAtkDamage;
		unsigned int maxAtkDamage;
		bool isDead;
		int posX;
		int posY;
	public:
		Archer(char sym)
		{
			symbol = sym;
			health = 20;
			atkRange = 4;
			minAtkDamage = 2;
			maxAtkDamage = 7;
			isDead = false;
		}
		// Accessors
		char GetSymbol(){ return symbol; }
		int GetHealth(){ return health; }
		unsigned int GetAtkRange(){ return atkRange; }
		unsigned int GetMinAtkDamage(){ return minAtkDamage; }
		unsigned int GetMaxAtkDamage(){ return maxAtkDamage; }
		bool GetIsDead(){ return isDead; }
		// Mutators
		void SetSymbol(char sym){ symbol = sym; }
		void SetHealth(int hp){ health = hp; }
		void SetAttkRange(unsigned int atkR){ atkRange = atkR; }
		void SetMinAtkDamage(unsigned int minAtkD){ minAtkDamage = minAtkD; }
		void SetMaxAtkDamage(unsigned int maxAtkD){ minAtkDamage = maxAtkD; }
		void SetIsDead(bool dead){ isDead = dead; }
		// Turn Options
		void Move(Player p1, Player p2)
		{
			Console::SetCursorPosition(15, 3);
			Console::ForegroundColor(Yellow);
			std::cout << " Move Phase ";
			Console::ResetColor();
			bool input = false;
			while (!input)
			{
				if (_kbhit())
				{
					int c = _getch();
					switch (c)
					{
					case KEY_UP:
					{
						Console::SetCursorPosition(posX, posY);
						if ((posY % 2) == 0)
						{
							if ((posX % 2) == 0)
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
						Console::SetCursorPosition(posX, posY);
						std::cout << '*';
						posY--;
						if (posY < 0
							|| posY > 6
							|| (posX == p2.GetWarriorX() && posY == p2.GetWarriorY())
							|| (posX == p2.GetArcherX() && posY == p2.GetArcherY())
							|| (posX == p2.GetSorcererX() && posY == p2.GetSorcererY())
							|| (posX == p1.GetWarriorX() && posY == p1.GetWarriorY())
							|| (posX == p1.GetSorcererX() && posY == p1.GetSorcererY()))
						{
							posY++;
						}
						input = true;
					}
						break;
					case KEY_DOWN:
					{
						Console::SetCursorPosition(posX, posY);
						if ((posY % 2) == 0)
						{
							if ((posX % 2) == 0)
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
						Console::SetCursorPosition(posX, posY);
						std::cout << '*';
						posY++;
						if (posY < 0
							|| posY > 6
							|| (posX == p2.GetWarriorX() && posY == p2.GetWarriorY())
							|| (posX == p2.GetArcherX() && posY == p2.GetArcherY())
							|| (posX == p2.GetSorcererX() && posY == p2.GetSorcererY())
							|| (posX == p1.GetWarriorX() && posY == p1.GetWarriorY())
							|| (posX == p1.GetSorcererX() && posY == p1.GetSorcererY()))
						{
							posY--;
						}
						input = true;
					}
						break;
					case KEY_LEFT:
					{
						Console::SetCursorPosition(posX, posY);
						if ((posY % 2) == 0)
						{
							if ((posX % 2) == 0)
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
						Console::SetCursorPosition(posX, posY);
						std::cout << '*';
						posX--;
						if (posX < 0
							|| posX > 6
							|| (posX == p2.GetWarriorX() && posY == p2.GetWarriorY())
							|| (posX == p2.GetArcherX() && posY == p2.GetArcherY())
							|| (posX == p2.GetSorcererX() && posY == p2.GetSorcererY())
							|| (posX == p1.GetWarriorX() && posY == p1.GetWarriorY())
							|| (posX == p1.GetSorcererX() && posY == p1.GetSorcererY()))
						{
							posX++;
						}
						input = true;
					}
						break;
					case KEY_RIGHT:
					{
						Console::SetCursorPosition(posX, posY);
						if ((posY % 2) == 0)
						{
							if ((posX % 2) == 0)
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
							if ((posX % 2) == 0)
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
						Console::SetCursorPosition(posX, posY);
						std::cout << '*';
						posX++;
						if (posX < 0
							|| posX > 6
							|| (posX == p2.GetWarriorX() && posY == p2.GetWarriorY())
							|| (posX == p2.GetArcherX() && posY == p2.GetArcherY())
							|| (posX == p2.GetSorcererX() && posY == p2.GetSorcererY())
							|| (posX == p1.GetWarriorX() && posY == p1.GetWarriorY())
							|| (posX == p1.GetSorcererX() && posY == p1.GetSorcererY()))
						{
							posX--;
						}
						input = true;
					}
						break;
					case (int)'p':
					{
						input = true;
					}
						break;
					}
				}
			}
		}
		void Attack(Player& player)
		{
			Console::SetCursorPosition(15, 3);
			Console::ForegroundColor(Yellow);
			std::cout << "Attack Phase";
			Console::ResetColor();
			bool input = false;
			while (!input)
			{
				if (_kbhit())
				{
					int c = _getch();
					switch (c)
					{
					case KEY_UP:
					{
						//posY--;
						if ((abs((int)player.GetWarriorX() - (int)posX) + abs((int)player.GetWarriorY() - (int)posY)) <= 4 && (posX == player.GetWarriorX()))//(posX == player.GetWarriorX() && posY == player.GetWarriorY())
						{
							if (!player.GetWarriorIsDead())
							{
								int damage = (rand() % 7 - 2 + 1) + 2;
								player.SetWarriorHealth(player.GetWarriorHealth() - damage);
								if (player.GetWarriorHealth() <= 0)
								{
									player.SetWarriorHealth(0);
									player.SetWarriorIsDead(true);
									player.SetWarriorSymbol('D');
								}
							}
						}
						else if ((abs((int)player.GetArcherX() - (int)posX) + abs((int)player.GetArcherY() - (int)posY)) <= 4 && (posX == player.GetArcherX()))
						{

							if (!player.GetArcherIsDead())
							{
								int damage = (rand() % 7 - 2 + 1) + 2;
								player.SetArcherHealth(player.GetArcherHealth() - damage);
								if (player.GetArcherHealth() <= 0)
								{
									player.SetArcherHealth(0);
									player.SetArcherIsDead(true);
									player.SetArcherSymbol('D');
								}
							}
						}
						else if ((abs((int)player.GetSorcererX() - (int)posX) + abs((int)player.GetSorcererY() - (int)posY)) <= 4 && (posX == player.GetSorcererX()))
						{

							if (!player.GetSorcererIsDead())
							{
								int damage = (rand() % 7 - 2 + 1) + 2;
								player.SetSorcererHealth(player.GetSorcererHealth() - damage);
								if (player.GetSorcererHealth() <= 0)
								{
									player.SetSorcererHealth(0);
									player.SetSorcererIsDead(true);
									player.SetSorcererSymbol('D');
								}
							}
						}
						//posY++;
						input = true;
					}
						break;
					case KEY_DOWN:
					{
						//posY++;
						if ((abs((int)player.GetWarriorX() - (int)posX) + abs((int)player.GetWarriorY() - (int)posY)) <= 4 && (posX == player.GetWarriorX()))
						{

							if (!player.GetWarriorIsDead())
							{
								int damage = (rand() % 7 - 2 + 1) + 2;
								player.SetWarriorHealth(player.GetWarriorHealth() - damage);
								if (player.GetWarriorHealth() <= 0)
								{
									player.SetWarriorHealth(0);
									player.SetWarriorIsDead(true);
									player.SetWarriorSymbol('D');
								}
							}
						}
						else if ((abs((int)player.GetArcherX() - (int)posX) + abs((int)player.GetArcherY() - (int)posY)) <= 4 && (posX == player.GetArcherX()))
						{

							if (!player.GetArcherIsDead())
							{
								int damage = (rand() % 7 - 2 + 1) + 2;
								player.SetArcherHealth(player.GetArcherHealth() - damage);
								if (player.GetArcherHealth() <= 0)
								{
									player.SetArcherHealth(0);
									player.SetArcherIsDead(true);
									player.SetArcherSymbol('D');
								}
							}
						}
						else if ((abs((int)player.GetSorcererX() - (int)posX) + abs((int)player.GetSorcererY() - (int)posY)) <= 4 && (posX == player.GetSorcererX()))
						{

							if (!player.GetSorcererIsDead())
							{
								int damage = (rand() % 7 - 2 + 1) + 2;
								player.SetSorcererHealth(player.GetSorcererHealth() - damage);
								if (player.GetSorcererHealth() <= 0)
								{
									player.SetSorcererHealth(0);
									player.SetSorcererIsDead(true);
									player.SetSorcererSymbol('D');
								}
							}
						}
						//posY--;
						input = true;
					}
						break;
					case KEY_LEFT:
					{
						//posX--;
						if ((abs((int)player.GetWarriorX() - (int)posX) + abs((int)player.GetWarriorY() - (int)posY)) <= 4 && (posY == player.GetWarriorY()))
						{

							if (!player.GetWarriorIsDead())
							{
								int damage = (rand() % 7 - 2 + 1) + 2;
								player.SetWarriorHealth(player.GetWarriorHealth() - damage);
								if (player.GetWarriorHealth() <= 0)
								{
									player.SetWarriorHealth(0);
									player.SetWarriorIsDead(true);
									player.SetWarriorSymbol('D');
								}
							}
						}
						else if ((abs((int)player.GetArcherX() - (int)posX) + abs((int)player.GetArcherY() - (int)posY)) <= 4 && (posY == player.GetArcherY()))
						{
							int damage = (rand() % 7 - 2 + 1) + 2;
							player.SetArcherHealth(player.GetArcherHealth() - damage);
							if (player.GetArcherHealth() <= 0)
							{
								player.SetArcherHealth(0);
								player.SetArcherIsDead(true);
								player.SetArcherSymbol('D');
							}
						}
						else if ((abs((int)player.GetSorcererX() - (int)posX) + abs((int)player.GetSorcererY() - (int)posY)) <= 4 && (posY == player.GetSorcererY()))
						{
							if (!player.GetSorcererIsDead())
							{
								int damage = (rand() % 7 - 2 + 1) + 2;
								player.SetSorcererHealth(player.GetSorcererHealth() - damage);
								if (player.GetSorcererHealth() <= 0)
								{
									player.SetSorcererHealth(0);
									player.SetSorcererIsDead(true);
									player.SetSorcererSymbol('D');
								}

							}
						}
						//posX++;
						input = true;
					}
						break;
					case KEY_RIGHT:
					{
						//posX++;
						if ((abs((int)player.GetWarriorX() - (int)posX) + abs((int)player.GetWarriorY() - (int)posY)) <= 4 && (posY == player.GetWarriorY()))
						{

							if (!player.GetWarriorIsDead())
							{
								int damage = (rand() % 7 - 2 + 1) + 2;
								player.SetWarriorHealth(player.GetWarriorHealth() - damage);
								if (player.GetWarriorHealth() <= 0)
								{
									player.SetWarriorHealth(0);
									player.SetWarriorIsDead(true);
									player.SetWarriorSymbol('D');
								}
							}
						}
						else if ((abs((int)player.GetArcherX() - (int)posX) + abs((int)player.GetArcherY() - (int)posY)) <= 4 && (posY == player.GetArcherY()))
						{

							if (!player.GetArcherIsDead())
							{
								int damage = (rand() % 7 - 2 + 1) + 2;
								player.SetArcherHealth(player.GetArcherHealth() - damage);
								if (player.GetArcherHealth() <= 0)
								{
									player.SetArcherHealth(0);
									player.SetArcherIsDead(true);
									player.SetArcherSymbol('D');
								}
							}
						}
						else if ((abs((int)player.GetSorcererX() - (int)posX) + abs((int)player.GetSorcererY() - (int)posY)) <= 4 && (posY == player.GetSorcererY()))
						{

							if (!player.GetSorcererIsDead())
							{
								int damage = (rand() % 7 - 2 + 1) + 2;
								player.SetSorcererHealth(player.GetSorcererHealth() - damage);
								if (player.GetSorcererHealth() <= 0)
								{
									player.SetSorcererHealth(0);
									player.SetSorcererIsDead(true);
									player.SetSorcererSymbol('D');
								}
							}
						}
						//posX--;
						input = true;
					}
						break;
					case (int)'p':
					{
						input = true;
					}
						break;
					}
				}
			}
		}
	};
#pragma endregion
#pragma region Sorcerer Struct
	struct Sorcerer
	{
		char symbol;
		int health;
		unsigned int atkRange;
		unsigned int minAtkDamage;
		unsigned int maxAtkDamage;
		bool isDead;
		int posX;
		int posY;
	public:
		Sorcerer(char sym)
		{
			symbol = sym;
			health = 20;
			atkRange = 2;
			minAtkDamage = 1;
			maxAtkDamage = 10;
			isDead = false;
		}
		// Accessors
		char GetSymbol(){ return symbol; }
		int GetHealth(){ return health; }
		unsigned int GetAtkRange(){ return atkRange; }
		unsigned int GetMinAtkDamage(){ return minAtkDamage; }
		unsigned int GetMaxAtkDamage(){ return maxAtkDamage; }
		bool GetIsDead(){ return isDead; }
		// Mutators
		void SetSymbol(char sym){ symbol = sym; }
		void SetHealth(int hp){ health = hp; }
		void SetAttkRange(unsigned int atkR){ atkRange = atkR; }
		void SetMinAtkDamage(unsigned int minAtkD){ minAtkDamage = minAtkD; }
		void SetMaxAtkDamage(unsigned int maxAtkD){ minAtkDamage = maxAtkD; }
		void SetIsDead(bool dead){ isDead = dead; }
		// Turn Options
		void Move(Player& p1, Player& p2)
		{
			Console::SetCursorPosition(15, 3);
			Console::ForegroundColor(Yellow);
			std::cout << " Move Phase ";
			Console::ResetColor();
			bool input = false;
			while (!input)
			{
				if (_kbhit())
				{
					int c = _getch();
					switch (c)
					{
					case KEY_UP:
					{
						Console::SetCursorPosition(posX, posY);
						if ((posY % 2) == 0)
						{
							if ((posX % 2) == 0)
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
							if ((posX % 2) == 0)
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
						Console::SetCursorPosition(posX, posY);
						std::cout << '*';
						posY--;
						if (posY < 0
							|| posY > 6
							|| (posX == p2.GetWarriorX() && posY == p2.GetWarriorY())
							|| (posX == p2.GetArcherX() && posY == p2.GetArcherY())
							|| (posX == p2.GetSorcererX() && posY == p2.GetSorcererY())
							|| (posX == p1.GetArcherX() && posY == p1.GetArcherX())
							|| (posX == p1.GetWarriorX() && posY == p1.GetWarriorY()))
						{
							posY++;
						}
						input = true;
					}
						break;
					case KEY_DOWN:
					{
						Console::SetCursorPosition(posX, posY);
						if ((posY % 2) == 0)
						{
							if ((posX % 2) == 0)
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
						Console::SetCursorPosition(posX, posY);
						std::cout << '*';
						posY++;
						if (posY < 0
							|| posY > 6
							|| (posX == p2.GetWarriorX() && posY == p2.GetWarriorY())
							|| (posX == p2.GetArcherX() && posY == p2.GetArcherY())
							|| (posX == p2.GetSorcererX() && posY == p2.GetSorcererY())
							|| (posX == p1.GetArcherX() && posY == p1.GetArcherX())
							|| (posX == p1.GetWarriorX() && posY == p1.GetWarriorY()))
						{
							posY--;
						}
						input = true;
					}
						break;
					case KEY_LEFT:
					{
						Console::SetCursorPosition(posX, posY);
						if ((posY % 2) == 0)
						{
							if ((posX % 2) == 0)
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
						Console::SetCursorPosition(posX, posY);
						std::cout << '*';
						posX--;
						if (posX < 0
							|| posX > 6
							|| (posX == p2.GetWarriorX() && posY == p2.GetWarriorY())
							|| (posX == p2.GetArcherX() && posY == p2.GetArcherY())
							|| (posX == p2.GetSorcererX() && posY == p2.GetSorcererY())
							|| (posX == p1.GetArcherX() && posY == p1.GetArcherX())
							|| (posX == p1.GetWarriorX() && posY == p1.GetWarriorY()))
						{
							posX++;
						}
						input = true;
					}
						break;
					case KEY_RIGHT:
					{
						Console::SetCursorPosition(posX, posY);
						if ((posY % 2) == 0)
						{
							if ((posX % 2) == 0)
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
						Console::SetCursorPosition(posX, posY);
						std::cout << '*';
						posX++;
						if (posX < 0
							|| posX > 6
							|| (posX == p2.GetWarriorX() && posY == p2.GetWarriorY())
							|| (posX == p2.GetArcherX() && posY == p2.GetArcherY())
							|| (posX == p2.GetSorcererX() && posY == p2.GetSorcererY())
							|| (posX == p1.GetArcherX() && posY == p1.GetArcherX())
							|| (posX == p1.GetWarriorX() && posY == p1.GetWarriorY()))
						{
							posX--;
						}
						input = true;
					}
						break;
					case (int)'p':
					{
						input = true;
					}
						break;
					}
				}
			}
		}
		void Attack(Player& player)
		{
			Console::SetCursorPosition(15, 3);
			Console::ForegroundColor(Yellow);
			std::cout << "Attack Phase";
			Console::ResetColor();
			bool input = false;
			while (!input)
			{
				if (_kbhit())
				{
					int c = _getch();
					switch (c)
					{
					case KEY_UP:
					{
						//posY--;
						if (((abs((int)player.GetWarriorX() - (int)posX) + abs((int)player.GetWarriorY() - (int)posY)) <= 2) && posX == player.GetWarriorX())
						{

							if (!player.GetWarriorIsDead())
							{
								int damage = rand() % 10 + 1;
								player.SetWarriorHealth(player.GetWarriorHealth() - damage);
								if (player.GetWarriorHealth() <= 0)
								{
									player.SetWarriorIsDead(true);
									player.SetWarriorSymbol('D');
								}
							}
						}
						else if ((abs((int)player.GetArcherX() - (int)posX) + abs((int)player.GetArcherY() - (int)posY)) <= 2 && (posX == player.GetArcherX()))
						{

							if (!player.GetArcherIsDead())
							{
								int damage = rand() % 10 + 1;
								player.SetArcherHealth(player.GetArcherHealth() - damage);
								if (player.GetArcherHealth() <= 0)
								{
									player.SetArcherIsDead(true);
									player.SetArcherSymbol('D');
								}
							}
						}
						else if ((abs((int)player.GetSorcererX() - (int)posX) + abs((int)player.GetSorcererY() - (int)posY)) <= 2 && (posX == player.GetSorcererX()))
						{

							if (!player.GetSorcererIsDead())
							{
								int damage = rand() % 10 + 1;
								player.SetSorcererHealth(player.GetSorcererHealth() - damage);
								if (player.GetSorcererHealth() <= 0)
								{
									player.SetSorcererIsDead(true);
									player.SetSorcererSymbol('D');
								}
							}
						}
						//posY++;
						input = true;
					}
						break;
					case KEY_DOWN:
					{
						//posY++;
						if ((abs((int)player.GetWarriorX() - (int)posX) + abs((int)player.GetWarriorY() - (int)posY)) <= 2 && (posX == player.GetWarriorX()))
						{

							if (!player.GetWarriorIsDead())
							{
								int damage = rand() % 10 + 1;
								player.SetWarriorHealth(player.GetWarriorHealth() - damage);
								if (player.GetWarriorHealth() <= 0)
								{
									player.SetWarriorIsDead(true);
									player.SetWarriorSymbol('D');
								}
							}
						}
						else if ((abs((int)player.GetArcherX() - (int)posX) + abs((int)player.GetArcherY() - (int)posY)) <= 2 && (posX == player.GetArcherX()))
						{

							if (!player.GetArcherIsDead())
							{
								int damage = rand() % 10 + 1;
								player.SetArcherHealth(player.GetArcherHealth() - damage);
								if (player.GetArcherHealth() <= 0)
								{
									player.SetArcherIsDead(true);
									player.SetArcherSymbol('D');
								}
							}
						}
						else if ((abs((int)player.GetSorcererX() - (int)posX) + abs((int)player.GetSorcererY() - (int)posY)) <= 2 && (posX == player.GetSorcererX()))
						{

							if (!player.GetSorcererIsDead())
							{
								int damage = rand() % 10 + 1;
								player.SetSorcererHealth(player.GetSorcererHealth() - damage);
								if (player.GetSorcererHealth() <= 0)
								{
									player.SetSorcererIsDead(true);
									player.SetSorcererSymbol('D');
								}
							}
						}
						//posY--;
						input = true;
					}
						break;
					case KEY_LEFT:
					{
						//posX--;
						if ((abs((int)player.GetWarriorX() - (int)posX) + abs((int)player.GetWarriorY() - (int)posY)) <= 2 && (posY == player.GetWarriorY()))
						{

							if (!player.GetWarriorIsDead())
							{
								int damage = rand() % 10 + 1;
								player.SetWarriorHealth(player.GetWarriorHealth() - damage);
								if (player.GetWarriorHealth() <= 0)
								{
									player.SetWarriorIsDead(true);
									player.SetWarriorSymbol('D');
								}
							}
						}
						else if ((abs((int)player.GetArcherX() - (int)posX) + abs((int)player.GetArcherY() - (int)posY)) <= 2 && (posY == player.GetArcherY()))
						{

							if (!player.GetArcherIsDead())
							{
								int damage = rand() % 10 + 1;
								player.SetArcherHealth(player.GetArcherHealth() - damage);
								if (player.GetArcherHealth() <= 0)
								{
									player.SetArcherIsDead(true);
									player.SetArcherSymbol('D');
								}
							}
						}
						else if ((abs((int)player.GetSorcererX() - (int)posX) + abs((int)player.GetSorcererY() - (int)posY)) <= 2 && (posY == player.GetSorcererY()))
						{

							if (!player.GetSorcererIsDead())
							{
								int damage = rand() % 10 + 1;
								player.SetSorcererHealth(player.GetSorcererHealth() - damage);
								if (player.GetSorcererHealth() <= 0)
								{
									player.SetSorcererIsDead(true);
									player.SetSorcererSymbol('D');
								}
							}
						}
						//posX++;
						input = true;
					}
						break;
					case KEY_RIGHT:
					{
						//posX++;
						if ((abs((int)player.GetWarriorX() - (int)posX) + abs((int)player.GetWarriorY() - (int)posY)) <= 2 && (posY == player.GetWarriorY()))
						{

							if (!player.GetWarriorIsDead())
							{
								int damage = rand() % 10 + 1;
								player.SetWarriorHealth(player.GetWarriorHealth() - damage);
								if (player.GetWarriorHealth() <= 0)
								{
									player.SetWarriorIsDead(true);
									player.SetWarriorSymbol('D');
								}
							}
						}
						else if ((abs((int)player.GetArcherX() - (int)posX) + abs((int)player.GetArcherY() - (int)posY)) <= 2 && (posY == player.GetArcherY()))
						{

							if (!player.GetArcherIsDead())
							{
								int damage = rand() % 10 + 1;
								player.SetArcherHealth(player.GetArcherHealth() - damage);
								if (player.GetArcherHealth() <= 0)
								{
									player.SetArcherIsDead(true);
									player.SetArcherSymbol('D');
								}
							}
						}
						else if ((abs((int)player.GetSorcererX() - (int)posX) + abs((int)player.GetSorcererY() - (int)posY)) <= 2 && (posY == player.GetSorcererY()))
						{

							if (!player.GetSorcererIsDead())
							{
								int damage = rand() % 10 + 1;
								player.SetSorcererHealth(player.GetSorcererHealth() - damage);
								if (player.GetSorcererHealth() <= 0)
								{
									player.SetSorcererIsDead(true);
									player.SetSorcererSymbol('D');
								}
							}
						}
						//posX--;
						input = true;
					}
						break;
					case (int)'p':
					{
						input = true;
					}
						break;
					}
				}
			}
		}
	};
#pragma endregion
private:
	std::string name;
	Warrior* warrior;
	Archer* archer;
	Sorcerer* sorcerer;
	PLAYER_ID id;
public:
	Player(std::string _name, PLAYER_ID _id)
	{
		name = _name;
		id = _id;
		if (id == PLAYER_1)
		{
			warrior = new Warrior('W');
			archer = new Archer('A');
			sorcerer = new Sorcerer('S');
			warrior->posX = 1;
			warrior->posY = 0;
			archer->posX = 0;
			archer->posY = 0;
			sorcerer->posX = 2;
			sorcerer->posY = 0;
		}
		else if (id == PLAYER_2)
		{
			warrior = new Warrior('w');
			archer = new Archer('a');
			sorcerer = new Sorcerer('s');
			warrior->posX = 5;
			warrior->posY = 4;
			archer->posX = 5;
			archer->posY = 5;
			sorcerer->posX = 4;
			sorcerer->posY = 5;
		}
	}
	~Player()
	{
		//delete warrior;
		//delete archer;
		//delete sorcerer;
	}

	// Accessors
	std::string GetName(){ return name.c_str(); }
	// Health Access
	int GetWarriorHealth(){ return warrior->health; }
	int GetArcherHealth(){ return archer->health; }
	int GetSorcererHealth(){ return sorcerer->health; }
	bool GetWarriorIsDead(){ return warrior->isDead; }
	bool GetArcherIsDead(){ return archer->isDead; }
	bool GetSorcererIsDead(){ return sorcerer->isDead; }
	// Position Access
	unsigned int GetWarriorX(){ return warrior->posX; }
	unsigned int GetWarriorY(){ return warrior->posY; }
	unsigned int GetArcherX(){ return archer->posX; }
	unsigned int GetArcherY(){ return archer->posY; }
	unsigned int GetSorcererX(){ return sorcerer->posX; }
	unsigned int GetSorcererY(){ return sorcerer->posY; }
	// Mutators
	// Health Modifiers
	void SetWarriorHealth(int newHp){ warrior->health = newHp; }
	void SetArcherHealth(int newHp){ archer->health = newHp; }
	void SetSorcererHealth(int newHp){ sorcerer->health = newHp; }
	void SetWarriorIsDead(bool dead){ warrior->SetIsDead(dead); }
	void SetArcherIsDead(bool dead){ archer->SetIsDead(dead); }
	void SetSorcererIsDead(bool dead){ sorcerer->SetIsDead(dead); }
	void SetWarriorSymbol(char sym){ warrior->SetSymbol(sym); }
	void SetArcherSymbol(char sym){ archer->SetSymbol(sym); }
	void SetSorcererSymbol(char sym){ sorcerer->SetSymbol(sym); }
	// Position Modifiers
	void SetWarriorX(unsigned int newX){ warrior->posX = newX; }
	void SetWarriorY(unsigned int newY){ warrior->posY = newY; }
	void SetArcherX(unsigned int newX){ archer->posX = newX; }
	void SetArcherY(unsigned int newY){ archer->posY = newY; }
	void SetSorcererX(unsigned int newX){ sorcerer->posX = newX; }
	void SetSorcererY(unsigned int newY){ sorcerer->posY = newY; }

	void DisplayWarrior(unsigned int x, unsigned int y)
	{
		Console::ForegroundColor(Red);
		Console::SetCursorPosition(x, y);
		std::cout << warrior->symbol;
	}
	void DisplayArcher(unsigned int x, unsigned int y)
	{
		Console::ForegroundColor(Red);
		Console::SetCursorPosition(x, y);
		std::cout << archer->symbol;
	}
	void DisplaySorcerer(unsigned int x, unsigned int y)
	{
		Console::ForegroundColor(Red);
		Console::SetCursorPosition(x, y);
		std::cout << sorcerer->symbol;
	}

	void MoveWarrior(Player& p1, Player& p2)
	{
		warrior->Move(p1, p2);
	}
	void MoveArcher(Player& p1, Player& p2)
	{
		archer->Move(p1, p2);
	}
	void MoveSorcerer(Player& p1, Player& p2)
	{
		sorcerer->Move(p1, p2);
	}

	void WarriorAttack(Player& player)
	{
		warrior->Attack(player);
	}
	void ArcherAttack(Player& player)
	{
		archer->Attack(player);
	}
	void SorcererAttack(Player& player)
	{
		sorcerer->Attack(player);
	}
};
#endif