# Strategy_Game
Small 2 player, turn based strategy game project made for a data structures project.

Turn order show what unit on the field is currently acting. There is a move phase and attack phase for each unit's turn. Use the arrow keys to move a unit during the move phase (can only move to an empty space), and to select an attack direcion during the attack phase. Player 1 are the upper case letters, while player 2 is lower case.

A Warrior (W or w) has an attack range of 1.  Their attack randomly does 7 to 14.
A Sorcerer (S or s) has an attack range of 2.  Their attack randomly does 1 to 10.
An Archer (A or a) has an attack range of 4.  Their attack randomly does 2 to 7.

A character which has 0 hit points left is considered dead and should also be represented as a ‘D’ or ‘d’ on the battlefield (depending on which team they are on). The game ends when a team has no players left alive to continue fighting.


ConsoleFunctions.h/.cpp only code provided to me, rest was written solely by myself.
