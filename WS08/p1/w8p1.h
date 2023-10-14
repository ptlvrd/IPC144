/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : patel vrundaben vijaykumar
Student ID#: 158605220
Email      : vvpatel20@myseneca.ca
Section    : nbb part1

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define MAXPRODUCT 3
#define GRAMS 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
    int id;
    double price;
    int calories;
    double weight;
};


// ----------------------------------------------------------------------------
// function prototypes

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

// 7. Logic entry point
void start(void);
