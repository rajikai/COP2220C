#include <stdio.h>

//Ease to Modify Promotional Discounts.
#define FirstTime 500.00
#define Veteran 0.01
#define Student 700.00
#define MonthLastDay 0.05 

char Menu(char choice) {
	char Pointlessloop = 0;
	while (Pointlessloop == Pointlessloop) {
		printf("1: SEE CURRENT DATA ON SOLD CARS.\n");
		printf("2: ENTER A NEW SALE.\n");
		printf("3: EXIT PROGRAM.\n");
		printf("Please choose what to do: ");
		scanf_s("%i", &choice);
		if (choice == 1 || choice == 2 || choice == 3) {
			system("cls");
			return choice;
			break;
		}
		else {
			system("cls");
			printf("Invalid entry, try again! \n");
			continue;
		}
	}
}

// Show Average Data
void aShow(float rev, int sold) {
	float temp = rev / sold;

	if (sold == 0) {
		temp = 0;
	}
	system("cls");
	printf("Total Cars Sold:\t");
	printf("  %i Cars\n", sold);

	printf("Average Sell Price:\t");
	printf("  $%.2f\n", temp);

	printf("Total Revenue:\t\t");
	printf("  $%.2f\n", rev);
}

float ProcessPayment(float temp, char month, char buyer, char veteran, char student) {

	switch (month) {
	case 'y': // Show Current Data on Cars Sold
		temp = temp - (MonthLastDay * temp);
		break;
	case 'Y': // Enter data for new sell
		temp = temp - (MonthLastDay * temp);
		break;
	default:
		break;
	}
	switch (student) {
	case 'y': // Show Current Data on Cars Sold
		temp = temp - Student;
		break;
	case 'Y': // Enter data for new sell
		temp = temp - Student;
		break;
	default:
		break;
	}
	switch (buyer) {
	case 'y': // Show Current Data on Cars Sold
		temp = temp - FirstTime;
		break;
	case 'Y': // Enter data for new sell
		temp = temp - FirstTime;
		break;
	default:
		break;
	}
	switch (veteran) {
	case 'y': // Show Current Data on Cars Sold
		temp = temp - (temp * Veteran);
			break;
	case 'Y': // Enter data for new sell
		temp = temp - (temp * Veteran);
			break;
	default:
		break;
	}

	return temp;

}

char BoolCheck(char check) {
	char Truth = 0;
	while (Truth == 0) {
		switch (check) {
		case 'y':
			Truth = 1;
			continue;
		case 'Y':
			Truth = 1;
			continue;
		case 'n':
			Truth = 1;
			continue;
		case 'N':
			Truth = 1;
			continue;
		default:
			printf("Invalid entry, try again!\n");
			getchar();
			scanf_s("%c", &check);
			printf("%c", check);
		}
	}
		return check;
	
}

int main() {
	// Perm Values
	float Database[50000] = { 0 }, Revenue = 0, tempPrice;
	int NumOfCarsSold = 0;

	// Temp Values
	char running = 1, usrchoice, month, buyer, veteran, student;

	// Programming is Running Loop
	while (running == 1) {

		//Open Menu Function
		usrchoice = Menu(running);

		//Options on Menu
		switch (usrchoice) {
		case 1: // Show Current Data on Cars Sold
			aShow(Revenue, NumOfCarsSold);
			printf("\n\n");
			break;
		case 2: // Enter data for new sell
			aShow(Revenue, NumOfCarsSold);
			printf("\n\n");
			printf("What is the tag price?\n");
			scanf_s("%f", &tempPrice);

			aShow(Revenue, NumOfCarsSold);
			printf("\n\n");
			printf("Is it the last day of the Month? (y/n)\n");
			getchar();
			scanf_s("%c", &month);
			printf("%c", month);
			BoolCheck(month);

			aShow(Revenue, NumOfCarsSold);
			printf("\n\n");
			printf("Is the customer a first time buyer? (y/n)\n");
			getchar();
			scanf_s("%c", &buyer);
			BoolCheck(buyer);

			aShow(Revenue, NumOfCarsSold);
			printf("\n\n");
			printf("Is the customer a veteran? (y/n)\n");
			getchar();
			scanf_s("%c", &veteran);
			BoolCheck(veteran);

			aShow(Revenue, NumOfCarsSold);
			printf("\n\n");
			printf("Is the customer a student? (y/n)\n");
			getchar();
			scanf_s("%c", &student);
			Database[NumOfCarsSold] = ProcessPayment(tempPrice, month, buyer, veteran, student);
			Revenue += Database[NumOfCarsSold];
			NumOfCarsSold++;
			aShow(Revenue, NumOfCarsSold);
			printf("\nThe total is: %.2f\n\n", Database[NumOfCarsSold - 1]);
			break;
		case 3: //Exit Program
			running = 0;
			continue;
		default:
			printf("Invalid entry, try again!\n");
		}
	}
}