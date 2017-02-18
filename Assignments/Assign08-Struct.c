/*
Jonathan Rodrigues
C Programming COP-2220C
Taught by: Professor Dennis Hunchuck
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pause system("pause")
#define cls system("cls")

//Structs
typedef struct {
	int month;
	int day;
	int year;
} DATE;

typedef struct {
	const char * name; //strcpy does not work since there is no address to point to.
	DATE birth;
	char gender[7];
	float annIncome;
} PERSON;

//Prototype
populate(PERSON *, PERSON *, PERSON *);
output(PERSON, PERSON, PERSON);


// The Main
int main() {
	PERSON allan, john, mary; //Would've preferred to use an array, so I can use loops, but specs says to use 3 variables.

	populate(&allan, &john, &mary);
	output(allan, john, mary);

	pause;
}

populate (PERSON *person1, PERSON *person2, PERSON *person3) {
	
	//var allan
	person1->name = "Allan";
	person1->birth.month = 8;
	person1->birth.day = 23;
	person1->birth.year = 1990;
	strcpy(person1->gender, "Male");
	person1->annIncome = 50000;

	//var john
	person2->name = "Jonathan";
	person2->birth.month = 9;
	person2->birth.day = 30;
	person2->birth.year = 1991;
	strcpy(person2->gender, "Male");
	person2->annIncome = 30000;

	//var mary
	person3->name = "Marianne";
	person3->birth.month = 8;
	person3->birth.day = 3;
	person3->birth.year = 1994;
	strcpy(person3->gender, "Female");
	person3->annIncome = 40000;


}

output(PERSON person1, PERSON person2, PERSON person3){
	//Outputs Allan
	printf("Name: %s", person1.name);
	printf("\nBirthday: %02i%/%02i%/%i", person1.birth.month, person1.birth.day, person1.birth.year);
	printf("\nGender: %s", person1.gender);
	printf("\nAnnual Income: $%.2f\n\n", person1.annIncome);

	//Outputs John
	printf("Name: %s", person2.name);
	printf("\nBirthday: %02i%/%02i%/%i", person2.birth.month, person2.birth.day, person2.birth.year);
	printf("\nGender: %s", person2.gender);
	printf("\nAnnual Income: $%.2f\n\n", person2.annIncome);

	//Outputs Mary
	printf("Name: %s", person3.name);
	printf("\nBirthday: %02i%/%02i%/%i", person3.birth.month, person3.birth.day, person3.birth.year);
	printf("\nGender: %s", person3.gender);
	printf("\nAnnual Income: $%.2f\n\n", person3.annIncome);
}