/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : patel vrundaben vijaykumar
Student ID#: 158605220
Email      : vvpatel20@myseneca.ca
Section    : part 2 NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"


// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intPointer) {
	int input;
	int flag = 1;
	do {
		scanf(" %d", &input);
		if (input <= 0) {
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
	printf("\n\nEnter the details for %d dry food bags of product data for analysis.", MAXPRODUCT);
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
void displayCatFoodData(int id, double* price, int calories, double* weight) {

	printf("%07d %10.2lf %10.1lf %8d\n", id, *price, *weight, calories);
}
// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* pounds, double* cResultToKg) {
	double poundsToKg = (*pounds) / LBSTOKG;
	if (cResultToKg != NULL) {
		*cResultToKg = poundsToKg;
	}return poundsToKg;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* pounds, int* cResultToG) {
	int poundsTog = ((*pounds) / LBSTOKG) * 1000;
	if (cResultToG != NULL) {
		*cResultToG = poundsTog;
	}return poundsTog;
}

// 10. convert lbs: kg and g
void convertLbs(const double* pounds, double* cResultToKg, int* cResultToG) {
	double poundsToKg = (*pounds) / LBSTOKG;
	int poundsTog = ((*pounds) / LBSTOKG) * 1000;
	if (cResultToKg != NULL && cResultToG != NULL) {
		*cResultToKg = poundsToKg;
		*cResultToG = poundsTog;
	}
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeG, const int totalg, double* numServing) {
	double servings = ((double)totalg) / servingSizeG;
	if (numServing != NULL) {
		*numServing = servings;
	}return servings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* totalServing, double* result) {
	double costS = (*productPrice) / (*totalServing);
	if (result != NULL) {
		*result = costS;
	}return costS;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalCal, double* result) {
	double costCal = (*productPrice) / (*totalCal);
	if (result != NULL) {
		*result = costCal;
	}return costCal;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo cat) {
	struct ReportData rd;
	//1st 4 members of report data
	rd.id = cat.id;
	rd.price = cat.price;
	rd.weightlbs = cat.weight;
	rd.calories = cat.calories;

	//calculated values
	rd.weightkg = convertLbsKg(&rd.weightlbs, &rd.weightkg);
	rd.weightg = convertLbsG(&rd.weightlbs, &rd.weightg);
	rd.totalServing = calculateServings(GRAMS, rd.weightg, &rd.totalServing);
	double totalCal = rd.calories * rd.totalServing;
	rd.costServing = calculateCostPerServing(&rd.price, &rd.totalServing, &rd.costServing);
	rd.caloriesServing = calculateCostPerCal(&rd.price, &totalCal, &rd.caloriesServing);
	
	return rd;
}


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n",GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rd, const int cheapestProd) {
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", rd.id, rd.price, rd.weightlbs, rd.weightkg, rd.weightg, rd.calories, rd.totalServing, rd.costServing, rd.caloriesServing);
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cat) {
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n", cat.id, cat.price);
	printf("\nHappy shopping!\n");
}


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct ReportData rd[MAXPRODUCT] = { {0} };
	struct CatFoodInfo cat[MAXPRODUCT] = { {0} };

	int i, index = 0;

	openingMessage(MAXPRODUCT);
	for (i = 0; i < MAXPRODUCT; i++) {
		cat[i] = getCatFoodInfo(i);
		rd[i] = calculateReportData(cat[i]);
	}
	displayCatFoodHeader();
	for (i = 0; i < MAXPRODUCT; i++) {
		displayCatFoodData(cat[i].id, &cat[i].price, cat[i].calories, &cat[i].weight);
	}
	double cheapestPrice = rd[0].costServing;
	for (i = 0; i < MAXPRODUCT; i++) {
		if (rd[i].costServing <= cheapestPrice) {
			cheapestPrice = rd[i].costServing;
			index = i;
		}
	}
	printf("\n");
	displayReportHeader();
	for (i = 0; i < MAXPRODUCT; i++) {
		displayReportData(rd[i], index);
		if (index == i) {
			printf(" ***\n");
		}
		else {
			printf("\n");
		}
	}printf("\n");

	for (i = 0; i < MAXPRODUCT; i++) {
		if (i == index) {
			displayFinalAnalysis(cat[i]);
		}
	}
}
