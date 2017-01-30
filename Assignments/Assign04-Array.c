/*
Jonathan Rodrigues
C Programming COP-2220C
Taught by: Professor Dennis Hunchuck
*/

#include <stdio.h>
#include <stdlib.h>
#define freeze system("pause");
#define clear system("cls")
#define TotalGames 1000
#define PlayersInTeams 2

//Call up Functions
void Scan(char *);
void menu(char *, char);
char Check(char *, char *);
char theExit(char, char *);

int XdataIn(long long int);
long long int EnterResults();
void header();

void PrintStats(int, int, int);
void WinResults(long long int *[TotalGames][PlayersInTeams], int, int);
void AllResults(long long int *[TotalGames][PlayersInTeams] , int);


// The Main
int main() {
	char ProgRun = 0, entry = 0, again = 0, EXIT = 0, amount = 1, result = 0;
	int GamEntered = 0, wins = 0, losses = 0, ties = 0, i, j;
	long long int GamStats[TotalGames][PlayersInTeams] = { 0 };

	while (ProgRun != 1) {

		//Part One of Main: Error Checking
		menu(&entry, again);																		//Opens Menu
		EXIT += Check(&entry, &EXIT);																//Checks for Valid input
		getchar();																					//Prevents some skipping
		ProgRun = theExit(EXIT, &again);															//Checks if data has been entered

		//Part Two of Main: The Actual Program
		//Allow Function to Determine User's Choice
		if (EXIT >= 2 && ProgRun == 0) {
			switch (entry) {
			case 1:
				amount = XdataIn(GamStats);
				for (i = 0; i < amount; i++) {
					clear;
					printf("\n\t***********************************************\n");
					printf("\t**                  MAIN   MENU              **\n");
					printf("\t***********************************************\n");
					printf("\t\nPlease enter the given information for game %d.", GamEntered + 1);

					printf("\n\n\tTeam Score: ");
					GamStats[GamEntered][0] = EnterResults();

					printf("\n\tOpposing Team Score: ");
					GamStats[GamEntered][1] = EnterResults();

					if (GamStats[GamEntered][0] > GamStats[GamEntered][1]) {
						wins++;
						GamEntered++;
					}
					else if (GamStats[GamEntered][0] < GamStats[GamEntered][1]) {
						losses++;
						GamEntered++;
					}
					else {
						ties++;
						GamEntered++;
					}
				}
				amount = 1;
				break;
			case 2:
				PrintStats(wins, losses, ties);
				break;
			case 3:
				WinResults(GamStats, GamEntered, wins);
				break;
			case 4:
				AllResults(GamStats, GamEntered);
				break;
			default:
				break;
			}
		}	
	}
}


//The Main Error Preventing Scanf_s Function
void Scan(char *entry) {
	char tempEntry[5000];

	scanf_s("%4999s", tempEntry, 5000);
	*entry = tempEntry[0];
}

//Menu
void menu(char *entry, char again) {
	clear;
	printf("\n\t***********************************************\n");
	printf("\t**                  MAIN   MENU              **\n");
	printf("\t***********************************************\n");
	printf("\tA) Enter game results\n");
	printf("\tB) Current Record(# of wins and # of losses)\n");
	printf("\tC) Display ALL results from all games WON\n");
	printf("\tD) Display ALL results\n");
	printf("\tE) Quit\n\n");

	// If user did not enter any data in
	if (again == 1) {
		printf("Please enter game result first!\n\n  ");
	}

	printf("Option:  ");

	Scan(&*entry);
}

//Check Input 
/* Note to self, Check This out */
char Check(char *entry, char *EXIT) {
	char valid = 0;

	while (valid == 0) {
		switch (*entry) {
		case 'a':
			*entry = 1;
			*EXIT = *EXIT + 1;
			return 3;
		case 'A':
			*entry = 1;
			*EXIT = *EXIT + 1;
			return 3;
		case 'b':
			*entry = 2;
			*EXIT = *EXIT + *EXIT;
			return 0;
		case 'B':
			*entry = 2;
			*EXIT = *EXIT + *EXIT;
			return 0;
		case 'c':
			*entry = 3;
			return 0;
		case 'C':
			*entry = 3;
			return 0;
		case 'd':
			*entry = 4;
			return 0;
		case 'D':
			*entry = 4;
			return 0;
		case 'e':
			*EXIT = 1;
			return 0;
		case 'E':
			*EXIT = 1;
			return 0;
		default:
			printf("Invalid Entry, try again:  ");
			Scan(&*entry);
			continue;
		}
	}
}

//Check for Data and Exit Program
char theExit(char exit, char *again) {
	if (exit == 0) {
		*again = 1;												//Tell Machine to loop since no data has been inserted.
	}
	else if (exit == 1) {
		system("cls");
		printf("Created by: Jonathan Rodrigues\n");
		printf("Class: C Programming COP-2220C (Spring 2017)\n");
		printf("Taught by: Professor Dennis Hunchuck\n\n");
		printf("\t\tGoodbye!\n\n");
		freeze
		return 1;
	}
	else {
		return 0;
	}
}

//Choose Action to take when entering data
int XdataIn(long long int GamStats) {
	int temp[3];
	char i, EXIT = 5, entry = 0, amount = 1;

	clear;
	printf("\n\t***********************************************\n");
	printf("\t**                  MAIN   MENU              **\n");
	printf("\t***********************************************\n");
	printf("\tA) Enter one game.\n");
	printf("\tB) Enter any number of games.\n\n");

	printf("Option:  ");

	//Ensure Valid Input loop
	while (EXIT < 9 || EXIT > 11) {
		Scan(&entry);
		getchar();
		EXIT += Check(&entry, &EXIT);
		if (EXIT == 5 || EXIT == 1) {
			printf("Invalid Entry, try again:  ");
			EXIT == 5;
		}
	}
	switch (entry) {
	case 1:
		return 1;
	case 2:
		printf("\nNumber of inputs: ");
		entry = EnterResults();
		return entry;

	}
}

//Check if Intergers are Numbers and Assign
long long int EnterResults() {
	long long int temp = 0;

	while (scanf_s("%i", &temp) != 1) {
		printf("Invalid Entry, try again:  ");
		getchar();
	}
	return temp;
}

//Print current stats
void PrintStats(int win, int loss, int tie) {

	clear;
	printf("\n\t******************************************");
	printf("\n\t**\t\tGame Stats\t\t**");
	printf("\n\t******************************************");
	printf("\n\t**\tTotal Wins\t**\t%d\t**", win);
	printf("\n\t******************************************");
	printf("\n\t**\tTotal Ties\t**\t%d\t**", tie);
	printf("\n\t******************************************");
	printf("\n\t**\tTotal Losses\t**\t%d\t**", loss);
	printf("\n\t******************************************\n\n");

	freeze
}

//Top header of the rsults
void header(){
	clear;
	printf("\n\t**************************************************");
	printf("\n\t**    Game #    **   Your Team  **   Opposing   **");
	printf("\n\t**************************************************");
}

//Print the results of Winning Games
void WinResults(long long int *GamStats[TotalGames][PlayersInTeams], int GamEntered, int wins) {
	int i = 0, entry = 0, count, forward = 0, forwardLimit = ((wins - 1) / 10) + 2;

	while (i < GamEntered) {

		header();
		for (count = 0; count < 10; i = i + 2) {
			if (GamStats[i][0] > GamStats[i + 1][0]) {
				printf("\n\t**\t%d\t**\t%d\t**\t%d\t**", (i / 2) + 1, GamStats[i][0], GamStats[i + 1][0]);
				count++;
				if (i < forwardLimit) {
					forwardLimit = i;
				}
			}
			if (i >= TotalGames) {
				count = 10;
			}
		}

		entry = 0;
		printf("\n\t**************************************************");
		printf("\n\t**\tTotal Games Won:\t**\t%d/%d\t** ", wins, GamEntered);
		printf("\n\t**************************************************\n\n");

		if (forward == 0 || wins == 10) {
			if (forwardLimit != 2) {
				printf("\n\nEnter 1 to page to forward. ");
				while (entry != 1) {
					entry = EnterResults();
					switch (entry) {
					case 1:
						forward++;
						break;
					default:
						printf("Invalid Entry, try again:  ");
					}
				}
			}
			else {
				printf("\n\n");
				freeze;
			}
		}
		else if (forward <= forwardLimit && wins > 10) {
			if (forward == forwardLimit) {
				printf("\n\nEnter 1 to page to exit, 2 to page back. ");
			}
			else {
				printf("\n\nEnter 1 to page to forward, 2 to page back. ");
			}
			while (entry == 0) {
				entry = EnterResults();
				switch (entry) {
				case 1:
					forward++;
					getchar();
					break;
				case 2:
					getchar();
					i = i - 20;
					forward--;
					break;
				default:
					printf("Invalid Entry, try again:  ");
				}
			}
		}
	}
}

//Print all the results of all Games
void AllResults(long long int *GamStats[TotalGames][PlayersInTeams], int GamEntered) {
	int i = 0, entry = 0, count, forward = 0, forwardLimit = ((GamEntered - 1) / 10) + 2;

	while (i < GamEntered) {

		header();
		for (count = 0; count < 10; count++) {
			printf("\n\t**\t%d\t**\t%d\t**\t%d\t**", (i /2) + 1, GamStats[i][0], GamStats[i+1][0]);
			i = i + 2;
		}
		entry = 0;
		printf("\n\t**************************************************");
		printf("\n\t**\tTotal Games Entered:\t**\t%d\t** ", GamEntered);
		printf("\n\t**************************************************\n\n");

		if (forward == 0 || GamEntered == 10) {
			if (forwardLimit != 2) {
				printf("\n\nEnter 1 to page to forward. ");
				while (entry != 1) {
					entry = EnterResults();
					switch (entry) {
					case 1:
						forward++;
						break;
					default:
						printf("Invalid Entry, try again:  ");
					}
				}
			}
			else {
				printf("\n\n");
				freeze;
			}
		}
		else if (forward <= forwardLimit && GamEntered > 10 ) {
			if (forward == forwardLimit) {
				printf("\n\nEnter 1 to page to exit, 2 to page back. ");
			}
			else {
				printf("\n\nEnter 1 to page to forward, 2 to page back. ");
			}
			while (entry == 0) {
				entry = EnterResults();
				switch (entry) {
				case 1:
					forward++;
					getchar();
					break;
				case 2:
					getchar();
					i = i - 20;
					forward--;
					break;
				default:
					printf("Invalid Entry, try again:  ");
				}
			}
		}
	}
}
