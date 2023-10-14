/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  :patel vrundaben vijaykumar
Student ID#:158605220
Email      :vvpatel20@myseneca.ca
Section    :milestone3 NBB

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

// Function to sort the values using bubble sort
void sort(struct Appointment appoints[], int max) {
    int i, j;
    struct Appointment apt;

    //storing every minute of the date and time for comparison
    for (i = 0; i < max; i++) {
        appoints[i].time.min = (appoints[i].date.year * 12 * 30 * 24 * 60) + (appoints[i].date.month * 30 * 24 * 60) + (appoints[i].date.day * 24 * 60) + (appoints[i].time.hour * 60) + appoints[i].time.min;
    }
    for (i = max - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (appoints[j].time.min > appoints[j + 1].time.min)
            {
                apt = appoints[j];
                appoints[j] = appoints[j + 1];
                appoints[j + 1] = apt;
            }
        }
    }
    for (i = 0; i < max; i++) {
        appoints[i].time.min = appoints[i].time.min - (appoints[i].date.year * 12 * 30 * 24 * 60) - (appoints[i].date.month * 30 * 24 * 60) - (appoints[i].date.day * 24 * 60) - (appoints[i].time.hour * 60);
    }
}

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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
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
    }
    if (!patientRecord) {
        printf("*** No records found ***\n\n");
    }
    printf("\n");
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max) {
    int number, pIndex, locate, i = 0;
    do {
        locate = 0;
        if (patient[i].patientNumber == 0){
            locate = 1;
            pIndex = i;
        }
        i++;
    } while (i < max && locate == 0);
    if (locate == 0){
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else{
        number = nextPatientNumber(patient, max);
        patient[pIndex].patientNumber = number;
        inputPatient(&patient[pIndex]);
        printf("*** New patient record added ***\n\n");
    }
}


// Edit a patient record from the patient array
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max) {
    int phnNumber, pIndex;
    char searchOpt, character;
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
        int flag = 1;

        do {
            scanf(" %c%c", &searchOpt, &character);

            if (searchOpt == 'n' || searchOpt == 'N') {
                printf("Operation aborted.\n\n");
                flag = 0;
                clearInputBuffer();
            }
            else if ((searchOpt == 'y' || searchOpt == 'Y') && (character == '\n')) {
                patient[pIndex].patientNumber = 0;
                printf("Patient record has been removed!\n\n");
                flag = 0;
            }

            else {

                clearInputBuffer();
                printf("ERROR: Character must be one of [yn]: ");
            }
        } while (flag);
    }
    
    else {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
    }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data) {
    int i, j;
    sort(data->appointments, data->maxAppointments);

    displayScheduleTableHeader(NULL, 1);
    for (i = 0; i < data->maxAppointments; i++) {
        for (j = 0; j < data->maxPatient; j++) {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber) {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }printf("\n");
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data) {
    int numDays = 31;
    int i, j;
    struct Date date;
    printf("Year        : ");
    date.year = inputIntPositive();

    
    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);

    printf("Day (1-");
    if (date.month == 4 || date.month == 9 || date.month == 11) {
        numDays = 30;
    }
    if (date.month == 2) {
        numDays = 28;
    }
    if (date.year % 4 == 0 && date.month == 2) {
        numDays = 29;
    }

    printf("%d)  : ", numDays);
    date.day = inputIntRange(1, numDays);
    printf("\n");

    sort(data->appointments, data->maxAppointments);
    displayScheduleTableHeader(&date, 0);
    for (i = 0; i < data->maxAppointments; i++) {
        for (j = 0; j < data->maxPatient; j++) {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber) {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) {
                    if (data->appointments[i].date.year == date.year && data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day) {
                        displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                    }
                }
            }
        }
    }
     printf("\n");
}


// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* app, int maxAppointments, struct Patient* pt, int maxPatients) {
    struct Date date;
    struct Time time;
    int numDays = 31;
    int patientNumber, pIndex, slotNotAvailable = 1;

    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    pIndex = findPatientIndexByPatientNum(patientNumber, pt, maxPatients);

    if (pIndex >= 0) {
        while (slotNotAvailable) {
            printf("Year        : ");
            date.year = inputIntPositive();

            printf("Month (1-12): ");
            date.month = inputIntRange(1, 12);

            printf("Day (1-");
            if (date.month == 4 || date.month == 9 || date.month == 11) {
                numDays = 30;

            } 
            if (date.month == 2) {
                numDays = 28;

            }
            if (date.year%4 == 0 && date.month == 2) {
                numDays = 29;
            }
            printf("%d)  : ", numDays);
            date.day = inputIntRange(1, numDays);

            printf("Hour (0-23)  : ");
            time.hour = inputIntRange(0, 23);

            printf("Minute (0-59): ");
            time.min = inputIntRange(0, 59);

            if(timeSlotAvailable(date, time, app, maxAppointments)) {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
            }
            else {
                while ((time.hour < HOUR_START || time.hour > END_HOUR) || (time.hour == END_HOUR && time.min > 0) || (time.min % MINUTEINTERVAL != 0)) {
                    printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", HOUR_START, END_HOUR, MINUTEINTERVAL);
                    printf("Hour (0-23)  : ");
                    time.hour = inputIntRange(0, 23);
                    printf("Minute (0-59): ");
                    time.min = inputIntRange(0, 59);
                }
                slotNotAvailable = 0;
            }
        }
        pIndex = nextSlotAvailable(app, maxAppointments);
        app[pIndex].date = date;
        app[pIndex].time = time;
        app[pIndex].patientNumber = patientNumber;
        printf("\n*** Appointment scheduled! ***\n\n");
    }
    else 
    {
        printf("\nERROR: Patient record not found!\n\n");
    }
    return;

}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* app, int maxAppointments, struct Patient* pt, int maxPatients) {
    struct Date date;
    int pIndex, patientNumber, numDays = 0, patientIndex;

    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    pIndex = findPatientIndexByPatientNum(patientNumber, pt, maxPatients);

    if (pIndex >= 0) {
        printf("Year        : ");
        date.year = inputIntPositive();

        printf("Month (1-12): ");
        date.month = inputIntRange(1, 12);

        printf("Day (1-");
        if (date.month == 4 || date.month == 9 || date.month == 11) {
            numDays = 30;
        }
        if (date.month == 2) {
            numDays = 28;
        }
        if (date.year % 4 == 0 && date.month == 2) {
            numDays = 29;
        }

        printf("%d)  : ", numDays);
        date.day = inputIntRange(1, numDays);
        patientIndex = validAppointment(patientNumber, date, app, maxAppointments);
        if (patientIndex >= 0) {
            printf("\n");

            displayPatientData(&pt[pIndex], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");

            if (inputCharOption("yn") == 'y') {
                app[patientIndex].patientNumber = 0;
                printf("\nAppointment record has been removed!\n\n");
            }
            else {
                printf("ERROR: No appointment for this date!\n\n");
            }
        }
    }
    else {
        printf("ERROR: Patient record not found!\n\n");
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
    }
    printf("\n");
    if (match == 0) {
        printf("*** No records found ***\n\n");

    }
}


// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max) {
    int i, nextPatient, largestNum = patient[0].patientNumber;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber > largestNum) {
            largestNum = patient[i].patientNumber;
        }
    }nextPatient = largestNum + 1;
    return nextPatient;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == patientNumber) {
            return i;
        }
    }return -1;
}
int timeSlotAvailable(struct Date date, struct Time time, struct Appointment* app, int maxAppointments) {
    int i,  availapt= 0;
    for (i = 0; i < maxAppointments; i++) {
        if (date.year == app[i].date.year && date.month == app[i].date.month && date.day == app[i].date.day && time.hour == app[i].time.hour && time.min == app[i].time.min) {
            availapt = 1;
        }
    }
    return availapt;
}
int nextSlotAvailable(struct Appointment* app, int maxAppointments) {
    int i = 0, available = 0;
    while (available == 0 && i < maxAppointments) {
        if (app[i].patientNumber < 1) {
            available = 1;
        }
        i++;
    }
    return i;
}

int validAppointment(int patientNumber, struct Date date, struct Appointment* app, int maxAppointments) {
    int i = 0, valid = 0;

    while (valid == 0 && i < maxAppointments)
    {
        if ((app[i].patientNumber == patientNumber) && (app[i].date.day == date.day) && (app[i].date.month == date.month) && (app[i].date.year == date.year)) {
            valid = 1;
        } i++;
    }
    return i - 1;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient) {

    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);
}


// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone) {
    int searchOpt;
    char inputPhnNum[PHONE_LEN + 1];
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    searchOpt = inputIntRange(1, 4);
    printf("\n");

    switch (searchOpt) {
    case 1:
        strncpy(phone->description, "CELL", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCStringNumbers(inputPhnNum, 10, 10);
        strcpy(phone->number, inputPhnNum);
        printf("\n");
        break;

    case 2:
        strncpy(phone->description, "HOME", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);

        printf("Number : ");
        inputCStringNumbers(inputPhnNum, 10, 10);
        strcpy(phone->number, inputPhnNum);
        printf("\n");
        break;

    case 3:
        strncpy(phone->description, "WORK", PHONE_DESC_LEN);
        printf("Contact: %s\n", phone->description);

        printf("Number : ");
        inputCStringNumbers(inputPhnNum, 10, 10);
        strcpy(phone->number, inputPhnNum);
        printf("\n");
        break;
    case 4:
        strncpy(phone->description, "TBD", PHONE_DESC_LEN);
        *phone->number = '\0';
        break;

    }

}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max) {
    int i = 0;

    FILE* fp;
    fp = fopen(datafile, "r");

    if (fp != NULL) {
        i = 0;
        while (fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber,
            patients[i].name,
            patients[i].phone.description,
            patients[i].phone.number) != EOF) {
            i++;
            if (i >= max)
                break;
        }fclose(fp);
    }
    else {
        printf("ERROR: File could not be read\n");
    }return i;
}


// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max) {
    // Declaring variables
    int i, count = 0;
    FILE* fp;
    fp = fopen(datafile, "r");
    if (fp != NULL) {
        for (i = 0; i < max && !feof(fp); i++) {
            fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min);
            if (!feof(fp)) {
                count++;
            }
        }fclose(fp);

    }
    else {
        printf("ERROR: File could not be read\n");
    }
    return count;
}