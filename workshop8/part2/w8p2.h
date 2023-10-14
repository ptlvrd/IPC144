/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : patel vrundaben vijaykumar
Student ID#: 158605220
Email      : vvpatel20@myseneca.ca
Section    : NBB part2

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


// ----------------------------------------------------------------------------
// defines/macros
#define MAXPRODUCT 3
#define GRAMS 64
#define LBSTOKG 2.20462
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
    int id;
    double price;
    int calories;
    double weight;
};

struct ReportData {
    int id;
    double price;
    int calories;
    double weightlbs;
    double weightkg;
    int weightg;
    double totalServing;
    double costServing;
    double caloriesServing;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int*);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double*);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(int);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int, double*, int, double*);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* pounds, double* cResultToKg);

// 9. convert lbs: g
int convertLbsG(const double* pounds, int* cResultToG);

// 10. convert lbs: kg / g
void convertLbs(const double* pounds, double* cResultToKg, int* cResultToG);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeG, const int totalg, double* numServing);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* totalServing, double* result);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalCal, double* result);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo cat);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rd, const int cheapestProd);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cat);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);