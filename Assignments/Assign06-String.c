/*
Jonathan Rodrigues
C Programming COP-2220C
Taught by: Professor Dennis Hunchuck
*/

#include <stdio.h>
#include <stdlib.h>
#define FLUSH while (getchar() != '\n')
#define PAUSE system("pause");
#define CLS system("cls")
#define STRING 101 // Actual string value is -1 of what is displayed

//Prototype
char Navigation();
void enterString(char[]);
void revString(char[]);
void lenOfString(char[]);
void vertString(char[]);
void triString(char[]);
void RtriString(char[]);
void TheEXIT();


// The Main
int main() {
	char input = 0, usrInput[STRING] = "";

	input = Navigation();

	while (input != 2) {
		enterString(usrInput);
		revString(usrInput);
		lenOfString(usrInput);
		vertString(usrInput);
		triString(usrInput);
		RtriString(usrInput);
		printf("\n\n\t");
		PAUSE;
		input = Navigation();
	}
	void TheEXIT();
}


//The menu
char Navigation() {
	int input;

	CLS;

	printf("\n\tMenu options:\n");
	printf("\t\tPlease choose an option:\n");
	printf("\t\t1. Input a String.\n");
	printf("\t\t2. Exit.\n\n");

	printf("Input: ");

	scanf_s("%d", &input);
	FLUSH;

	while (input != 1 && input != 2) {
		printf("Invalid input, try again: ");
		scanf_s("%d", &input);
		FLUSH;
	}

	CLS; 

	return input;

}

//Allow user input
void enterString(char usrInput[]) {

	printf("Please enter a string (%i characters max): ", STRING - 1);
	scanf("%100[^\n]", usrInput);
	FLUSH;

	while (usrInput[0] == '\0') {
		printf("\nInvalid entry, try again: ");
		scanf("%100[^\n]", usrInput);
		FLUSH;
}
	printf("\n\nYour string is: %s", usrInput);
}

//Reverses the String
void revString(char usrInput[]) {
	int end, i;

	end = strlen(usrInput);

	printf("\n\nYour string backwards is: ");

	for (i = end; i >= 0; --i)
		printf("%c", usrInput[i]);

}

//Prints out the Length of the string
void lenOfString(char usrInput[]) {
	int end;

	end = strlen(usrInput);

	printf("\n\nYour string's length is: %i", end);

}

//Displays the String Vertically
void vertString(char usrInput[]) {
	int end, i;

	end = strlen(usrInput);

	printf("\n\nYour string vertically is: ");

	for (i = 0; i < end; i++)
		printf("\n\t%c", usrInput[i]);
}

//Shows the string as a triangle
void triString(char usrInput[]) {
	int end, i, j = 1, k = 1, middle;

	end = strlen(usrInput);
	middle = (end / 2);
	printf("\n\nYour string as a triangle: ");

	if (end == 1) {
		end += 2;
		middle = 2;
		printf("\nOnly 1 character was placed in, so we are repeating it.\n");
		while (middle >= 0) {
			printf("\n\t");
			for (i = 0; i < middle; i++)			 //centering
				printf(" ");
			for (i = 0; i < j; i++)					//Printing
				printf("%c", usrInput[0]);
			j += 2;
			middle--;
		}
		end++;
	}
	else {

		switch (end % 2) {
		case 0://If Even
			middle = (end / 2) - 1;
			end /= 2;
			while (j != end + 1) {
				printf("\n\t");
				for (i = 0; i <= middle; i++)			//Spacing
					printf(" ");
				for (i = 0; k <= 1; i++) {				 //Top (Middle divider)
					printf("*");
					middle--;
					k++;
				}
				if (k == 2) {
					k++;
					continue;
				}
				for (i = 1; i < j + 1; i++)
					printf("%c", usrInput[middle + i]); //Left side
				printf(" ");							//Space to make triangle
				for (i = 0; i < j; i++)
					printf("%c", usrInput[end + i]);	//Right side
				j++;
				middle--;
			}

			break;
		case 1://If Odd
			end++;
			middle = (end / 2) - 1;
			end /= 2;
			end++;
			while (k != end) {
				printf("\n\t");
				for (i = 0; i < middle; i++)			 //centering
					printf(" ");
				for (i = 0; i < j; i++)					//Printing
					printf("%c", usrInput[middle + i]);
				j += 2;
				k++;
				middle--;
			}
			end++;
			break;
		}
	}
}

//Shows the string as a right triangle
void RtriString(char usrInput[]) {
	int end, i, j = 1;

	end = strlen(usrInput) + 1;

	printf("\n\nYour string as a right triangle: ");

	if (end == 2) {
		end += 2;
		printf("\nOnly 1 character was placed in, so we are repeating it.\n");
		while (j != end) {
			printf("\n\t");
			for (i = 0; i < j; i++)
				printf("%c", usrInput[0]);
			j++;
		}
	}
	else {
		while (j != end) {
			printf("\n\t");
			for (i = 0; i < j; i++)
				printf("%c", usrInput[i]);
			j++;
		}
	}
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