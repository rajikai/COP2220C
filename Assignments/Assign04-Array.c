/*
Jonathan Rodrigues
C Programming COP-2220C
Taught by: Professor Dennis Hunchuck
*/

#include <stdio.h>

//Call up Functions
void Scan(char *);
int menu(char, int, int, int, char);
char Check(char *, char *);
char CheckInt(char, char *);
void CheckIntisNum(int *, int *, int *, char);

void ChosenAction(char, char, char, char *, int *, int *, int *);


int main() {


}


//The Main Error Preventing Scanf_s Function
void Scan(char *entry) {
	char tempEntry[5000];

	scanf_s("%4999s", tempEntry, 5000);
	*entry = tempEntry[0];
}

//Universal Display of the Three Intergers
void theInts(int first, int second, int third) {
	system("cls");
	printf("First Interger: %i\n", first);
	printf("Second Interger: %i\n", second);
	printf("Third Interger: %i \n\n", third);
}

//Menu
int menu(char input, int first, int second, int third, char again) {
	theInts(first, second, third);
	printf("\tMAIN MENU\n\n");
	printf("\t\tA)  Get Three Integers\n");
	printf("\t\tB)  Display the Sum\n");
	printf("\t\tC)  Display the Product\n");
	printf("\t\tD)  Display the Average\n");
	printf("\t\tE)  Display the Lowest\n");
	printf("\t\tF)  Quit\n\n");

	// Did not put in three intergers
	if (again == 1) {
		printf("Please select \"Get three intergers\" first!\n\n  ");
	}

	printf("Option:  ");

	Scan(&input);
	return input;
}

//Check Input
char Check(char *Icheck, char *EXIT) {
	char valid = 0, i = 0;

	while (valid == 0) {
		switch (*Icheck) {
		case 'a':
			*Icheck = 1;
			*EXIT = *EXIT + 1;
			return 3;
		case 'A':
			*Icheck = 1;
			*EXIT = *EXIT + 1;
			return 3;
		case 'b':
			*Icheck = 2;
			*EXIT = *EXIT + *EXIT;
			return 0;
		case 'B':
			*Icheck = 2;
			*EXIT = *EXIT + *EXIT;
			return 0;
		case 'c':
			*Icheck = 3;
			return 0;
		case 'C':
			*Icheck = 3;
			return 0;
		case 'd':
			*Icheck = 4;
			return 0;
		case 'D':
			*Icheck = 4;
			return 0;
		case 'e':
			*Icheck = 5;
			return 0;
		case 'E':
			*Icheck = 5;
			return 0;
		case 'f':
			*EXIT = 1;
			return 0;
		case 'F':
			*EXIT = 1;
			return 0;
		default:
			printf("Invalid Entry, try again:  ");
			Scan(&*Icheck);
			i++;
			continue;
		}
	}
}

//Check for Integers and Exit Program
char CheckInt(char Icheck, char *again) {
	if (Icheck == 0) {
		*again = 1;												//Tell Machine to loop since 3 interegers are not present.
	}
	else if (Icheck == 1) {
		system("cls");
		printf("Created by: Jonathan Rodrigues\n");
		printf("Class: C Programming COP-2220C \(Spring 2017\)\n");
		printf("Taught by: Professor Dennis Hunchuck\n\n");
		printf("\t\tGoodbye!\n\n");
		system("pause");
		return 1;
	}
	else {
		return 0;
	}
}

//Check if Intergers are Numbers and Assign
void CheckIntisNum(int *one, int *two, int *three, char i) {
	int temp;

	while (scanf_s("%d", &temp) != 1) {
		printf("Invalid Entry, try again:  ");
		getchar();
	}
	switch (i) {
	case 1:
		*one = temp;
		break;
	case 2:
		*two = temp;
		break;
	case 3:
		*three = temp;
		break;
	}

}

//Determines which choice has been choosen 
void ChosenAction(char status, char status2, char input, char *again, int *first, int *second, int *third) {

	if (status >= 2 && status2 == 0) {
		switch (input) {
		case 1:
			Get3(&*first, &*second, &*third);
			*again = 0;
			break;
		case 2:
			Sum(*first, *second, *third);
			break;
		case 3:
			Product(*first, *second, *third);
			break;
		case 4:
			Average(*first, *second, *third);
			break;
		case 5:
			Lowest(*first, *second, *third);
			break;
		default:
			break;
		}
	}
}

