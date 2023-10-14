/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : patel vrundaben vijaykumar
Student ID#: 158605220
Email      : vvpatel20@myseneca.ca
Section    : NBB part1

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intPointer) {
	int input;
	int flag=1;
    do {
		scanf(" %d", &input);
		if(input<=0) { 
			printf("ERROR: Enter a positive value: ");
		}
		else {
			flag = 0;
		}
	} while (flag);
	if (intPointer != NULL) {
		*intPointer = input;
	}
	return input;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doublePointer) {
	double input;
	int flag = 1;

	do {
		scanf("%lf", &input);
		if (input <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
		else {
			flag = 0;
		}
	} while (flag);
	if (doublePointer != NULL) {
		*doublePointer = input;
	}
	return input;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProduct) {

	printf("Cat Food Cost Analysis"
		"\n======================");
	printf("\n\nEnter the details for %d dry food bags of product data for analysis.",MAXPRODUCT);
	printf("\nNOTE: A 'serving' is %dg\n\n", GRAMS);

}
// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int numProduct) {
	struct CatFoodInfo cat;
	int flag;
	printf("Cat Food Product #%d", numProduct + 1);
	printf("\n--------------------");
	flag = 1;

	//id
	printf("\nSKU           : ");
	flag = 1;
    do {
		scanf("%d", &cat.id);
		if (cat.id <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
		else {
			flag = 0;
		}
	} while (flag);

	//price
	printf("PRICE         : $");
	flag = 1;
	do {
		scanf("%lf", &cat.price);
		if (cat.price <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
		else {
			flag = 0;
		}
	} while (flag);

	//weight in lbs
	printf("WEIGHT (LBS)  : ");
	flag = 1;
	do {
		scanf("%lf", &cat.weight);
		if (cat.weight <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
		else {
			flag = 0;
		}
	} while (flag);

	//calories
	printf("CALORIES/SERV.: ");
	flag = 1;
	do {
		scanf("%d", &cat.calories);
		if (cat.calories <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
		else {
			flag = 0;
		}
	} while (flag);
	printf("\n");
	return cat;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int id, double* price, int calories, double* weight){
	
	printf("%07d %10.2lf %10.1lf %8d\n", id, *price, *weight, calories);
}

// 7. Logic entry point
void start(void) {
	struct CatFoodInfo cat[MAXPRODUCT] = { {0} };
	int i;
	openingMessage(MAXPRODUCT);
	for (i = 0; i < MAXPRODUCT; i++) {
		cat[i] = getCatFoodInfo(i);
	}
	displayCatFoodHeader();
	for (i = 0; i < MAXPRODUCT; i++) {
		displayCatFoodData(cat[i].id, &cat[i].price, cat[i].calories, &cat[i].weight);
	}

}