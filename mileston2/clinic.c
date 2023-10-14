/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  :patel vrundaben vijaykumar
Student ID#:158605220
Email      :vvpatel20@myseneca.ca
Section    :milestone2 NBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"
#include <string.h>

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    int i, patientRecord = 0;
    if (fmt == FMT_TABLE) {
        displayPatientTableHeader();
    }
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            displayPatientData(&patient[i], fmt);
            patientRecord = 1;
        }
    }if (!patientRecord) {
        printf("*** No records found ***\n\n");
    }
    printf("\n");
}



// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max) {
    int searchOpt;
    do {
        printf("Search Options"
        "\n==========================");
        printf("\n1) By patient number"
        "\n2) By phone number"
        "\n.........................."
        "\n0) Previous menu"
        "\n.........................."
        "\nSelection: ");
        scanf("%d", &searchOpt);
        printf("\n");

        if (searchOpt == 1) {
            searchPatientByPatientNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
        else if (searchOpt == 2) {
            searchPatientByPhoneNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
    } while (searchOpt != 0);

}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max) {
    int i, arrayIndex = 0;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            arrayIndex++;
        }
    }if (max > arrayIndex) {
        patient[arrayIndex].patientNumber = nextPatientNumber(patient, max);
        inputPatient(patient + arrayIndex);
        printf("*** New patient record added ***\n\n");
        clearInputBuffer();

    }
    else {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}


// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max) {
    int phnNumber, pIndex;
    printf("Enter the patient number: ");
    scanf("%d", &phnNumber);
    printf("\n");

    if (findPatientIndexByPatientNum(phnNumber, patient, max) != -1) {
        pIndex = findPatientIndexByPatientNum(phnNumber, patient, max);
        menuPatientEdit(patient + pIndex);
    }
    else {
        printf("ERROR: Patient record not found!\n");
    }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max) {
    int phnNumber, pIndex;
    char searchOpt;
    printf("Enter the patient number: ");
    scanf("%d", &phnNumber);
    printf("\n");

    if (findPatientIndexByPatientNum(phnNumber, patient, max) != -1) {
        pIndex = findPatientIndexByPatientNum(phnNumber, patient, max);
        printf("Name  : %s\n", patient[pIndex].name);
        printf("Number: %05d\n", patient[pIndex].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[pIndex].phone.number);
        printf(" (%s)", patient[pIndex].phone.description);
        printf("\n\nAre you sure you want to remove this patient record? (y/n): ");
        scanf(" %c", &searchOpt);

        if (searchOpt == 'n' || searchOpt == 'N') {
            printf("Operation aborted.\n\n");
            clearInputBuffer();
        }
        else {
            patient[pIndex].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
            clearInputBuffer();
        }
    }
    else {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    int phnNumber, pIndex;
    printf("Search by patient number: ");
    scanf("%d", &phnNumber);
    printf("\n");

    if (findPatientIndexByPatientNum(phnNumber, patient, max) != -1) {
        pIndex = findPatientIndexByPatientNum(phnNumber, patient, max);
        printf("Name  : %s\n", patient[pIndex].name);
        printf("Number: %05d\n", patient[pIndex].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[pIndex].phone.number);
        printf(" (%s)", patient[pIndex].phone.description);
        printf("\n\n");
    }
    else {
        printf("*** No records found ***\n\n");
    }
}


// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    int i, match = 0;
    char phnnumber[PHONE_LEN + 1];
    clearInputBuffer();
    printf("Search by phone number: ");
    fgets(phnnumber, sizeof(phnnumber), stdin);
    printf("\n");
    displayPatientTableHeader();

    for (i = 0; i < max + 1; i++) {
        if (strcmp(patient[i].phone.number, phnnumber) == 0) {
            printf("%05d %-15s ", patient[i].patientNumber, patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);
            match++;
        }
    }printf("\n");
    if (match == 0) {
        printf("*** No records found ***\n\n");

    }
}


// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max) {
    int i,nextPatient, largestNum=patient[0].patientNumber;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber > largestNum) {
            largestNum = patient[i].patientNumber;
        }
    }nextPatient = largestNum + 1;
    return nextPatient;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == patientNumber) {
            return i;
        }
    }return -1;
}



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient) {
    int i;
    char name[NAME_LEN];

    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    fgets(name, sizeof(name), stdin);

    for (i = 0; i < strlen(name) - 1; i++) {
        patient->name[i] = name[i];

    }
    printf("\n");
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone) {
    int searchOpt, i;
    char inputPhnNum[PHONE_LEN + 1];
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    scanf("%d", &searchOpt);
    printf("\n");

    switch (searchOpt) {
    case 1:
        strncpy(phone->description, "CELL", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        clearInputBuffer();
        printf("Number : ");
        fgets(inputPhnNum, sizeof(inputPhnNum), stdin);
        for (i = 0; i < PHONE_LEN + 1; i++) {
            phone->number[i] = inputPhnNum[i];
        }printf("\n");
        break;

    case 2:
        strncpy(phone->description, "HOME", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        clearInputBuffer();
        printf("Number : ");
        fgets(inputPhnNum, sizeof(inputPhnNum), stdin);
        for (i = 0; i < PHONE_LEN + 1; i++) {
            phone->number[i] = inputPhnNum[i];
        }printf("\n");
        break;

    case 3:
        strncpy(phone->description, "WORK", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        clearInputBuffer();
        printf("Number : ");
        fgets(inputPhnNum, sizeof(inputPhnNum), stdin);
        for (i = 0; i < PHONE_LEN + 1; i++) {
            phone->number[i] = inputPhnNum[i];
        }printf("\n");
        break;
    case 4:
        strncpy(phone->description, "TBD", PHONE_DESC_LEN);
        *phone->number = 0;
        break;

    default:
        printf("Error:\n");
        break;
    }

}