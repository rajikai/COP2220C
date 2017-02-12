/*
Jonathan Rodrigues
C Programming COP-2220C
Taught by: Professor Dennis Hunchuck
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define pause system("pause")
#define cls system("cls")
#define WORDS 50
#define WORDLENGTH 15

//Prototypes 
void GrabWords(char [][WORDLENGTH]);
int CheckResume(char [][WORDLENGTH]);
void TheEXIT();


// The Main
int main() {
	int results;
	char keywords[WORDS][WORDLENGTH] = { "" };

	printf("\t\t\tInstructions:\n\tPlease make sure the \"keywords.txt\" and \"resume.txt\" \n\t\tfiles are in the correct location.\n\n\t\t");
	pause; // To allow user time to change/placce resume file in correct location.

	GrabWords(keywords); // Make the Keyword.txt into a string to check against.
	results = CheckResume(keywords); //Checks the Resume.txt against the keywords string.

	printf("\n\t\t\tThe results are::");
	printf("\n\n\t\t\t\t%i points\n\n", results);
	pause;

	TheEXIT();
}

//Grab Keywords
void GrabWords(char keywords[][WORDLENGTH]) {
	int i = 0;

	cls;
	FILE * fd;

	fd = fopen("keywords.txt", "r");

	//Checks for error in file opening
	if (fd == NULL) {
		perror("Error");
		printf("\nClosing program now...\n\n");
		pause;
		exit(1);
	}

	//Transfer from txt to the array
	while (fscanf(fd, "%14[^, ], ", keywords[i], WORDLENGTH) != EOF) {
		i++;
	}

	fclose(fd);
}

//Check Resume with Keywords
int CheckResume(char keywords[][WORDLENGTH]) {
	int i = 0, counter = 0;
	char tempCompare[WORDLENGTH];

	cls;
	FILE * fd;

	fd = fopen("resume.txt", "r");

	//Checks for error in file opening
	if (fd == NULL) {
		perror("Error");
		printf("\nClosing program now...\n\n");
		pause;
		exit(2);
	}

	//Compare txt words with keywords
	while (fscanf(fd, "%14s", tempCompare, WORDLENGTH) != EOF) {
	
		//lowercase everything
		i = 0;
		while (tempCompare[i])
		{
			tempCompare[i] = tolower(tempCompare[i]);
			i++;
		}
		i = 0;

		//Make sure loop does not exceed array
		while (i != WORDS) {
			//Make Sure loop Ends even if word not matched.
			if (strcmp(tempCompare, keywords[i]) == 0)
			{
				counter++;
				i = 0;
				break;
			}
			else {
				i++;
			}
		}
	}

	fclose(fd);
	return counter;  //Return to main so it can be printed
}

//Exits the Program
void TheEXIT() {

	CLS;

	printf("Created by: Rory Corn, Robert Gay, TJ Parrish, Jonathan Rodrigues \n");
	printf("Class: C Programming COP-2220C (Spring 2017)\n");
	printf("Taught by: Professor Dennis Hunchuck\n\n");
	printf("\t\tGoodbye!\n\n");

	PAUSE;
}