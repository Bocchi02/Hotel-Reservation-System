#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Details // structure declaration
{
    int roomNum;
    char cusName[20];
    char address[25];
    char contactNo[15];
    char nationality[15];
    int period;
    char arrival[10]; /* data */
};
//------------------------------------FUNCTIONS----------------------------------------------//
int booking(struct Details custDets[], int size);
void roomFeatures();
int cusBalance(struct Details cusDets[], int size);
int cusList(struct Details custDets[]);
int delCusRec(struct Details custDets[], int size);
void cusSearch(struct Details custDets[], int size);
void sort_struct(struct Details custDets[], int size);
void restaurantMainMenu();
void restaurantBreakfast();
void restaurantMainDish();
void restaurantDessert();
void restaurantDrinks();
void clear(int i);
//------------------------------------FUNCTIONS----------------------------------------------//

int main()
{

    struct Details custDets[255];
    FILE *a = fopen("data.txt", "r"), *b;
    int i = 0, size = 0;
    char customerName, try[1];
    int choice;
    int add, remove;

    if (a == NULL)
    {
        b = fopen("data.txt", "w");
        printf("The file data.txt does not exist and has been created!");
        printf("\nPlease run the program again.");
        fclose(b);
    }

    while (!feof(a))
    {
        fscanf(a, "\n%d", &custDets[size].roomNum);
        fscanf(a, " %[^\n]s", custDets[size].cusName);
        fscanf(a, " %[^\n]s", custDets[size].address);
        fscanf(a, "%s", custDets[size].contactNo);
        fscanf(a, "%s", custDets[size].nationality);
        fscanf(a, "%d", &custDets[size].period);
        fscanf(a, "%s\n", custDets[size].arrival);
        size++;
    }

    // printf("%d", size);
    // system("cls"); // FOR CLEARING SCREEN
    // printf("%d", size);
    clear(50);
    printf("\t\t  *************************************************\n");
    printf("\t\t  *                                               *\n");
    printf("\t\t  *       -----------------------------           *\n");
    printf("\t\t  *         WELCOME TO HOTEL TRIVAGO              *\n");
    printf("\t\t  *       -----------------------------           *\n");
    printf("\t\t  *                                               *\n");
    printf("\t\t  *************************************************\n\n\n");
    // printf(" \n Press any key to continue:");

    // getch();
    //  system("cls");
    while (1) // INFINITE LOOP
    {
        // system("cls");
        //  printf("%d", size);
        for (i = 0; i < 80; i++)
            printf("-");
        printf("\n");
        printf("   ******************************  |TRANSACTION MENU|  ***************************** \n");
        for (i = 0; i < 80; i++)
            printf("-");
        printf("\n");
        printf("\t\t *Please enter your desired transaction*:");
        printf("\n\n");
        printf(" \n Enter 1 -> Book a room");
        printf("\n------------------------");
        printf(" \n Enter 2 -> Room Features");
        printf("\n--------------------------");
        printf(" \n Enter 3 -> Show Receipt");
        printf("\n--------------------------");
        printf(" \n Enter 4 -> View Customer Record");
        printf("\n----------------------------------");
        printf(" \n Enter 5 -> Delete Customer Record");
        printf("\n-----------------------------------");
        printf(" \n Enter 6 -> Search Customer Record");
        printf("\n-----------------------------------");
        printf(" \n Enter 7 -> Restaurant Menu");
        printf("\n----------------------------");
        printf(" \n Enter 8 -> Exit");
        printf("\n-----------------");
        printf("\n> ");
        scanf("%d", &choice);
        // choice = getche();
        //  choice = toupper(choice);
        switch (choice) // SWITCH
        {
        case 1:
            clear(50);
            add = booking(custDets, size);
            size = add;
            break;
        case 2:
            clear(50);
            roomFeatures();
            break;
        case 3:
            clear(50);
            cusBalance(custDets, size);
            break;
        case 4:
            clear(50);
            size = cusList(custDets);
            break;
        case 5:
            clear(50);
            remove = delCusRec(custDets, size);
            size = remove;
            break;
        case 6:
            clear(50);
            cusSearch(custDets, size);
            break;
        case 7:
            clear(50);
            restaurantMainMenu();
            break;
        case 8:
            printf("\n\n\t *****THANK YOU FOR TRUSTING OUR SERVICE*****");
            //	Sleep(2000);
            exit(0);
            break;
        default:
        reset:
            printf("\nWrong Input");
            printf("\n Try again? Y/N");
            printf("\n> ");
            scanf("%s", try);

            if (strcmp(try, "Y") == 0 || strcmp(try, "y") == 0)
            {
                strcpy(try, "0");
            }
            else if (strcmp(try, "N") == 0 || strcmp(try, "n") == 0)
            {
                printf(" \n\n\nP r o g r a m \t\tE x i t e d !");
                exit(0);
            }
            else
            {
                goto reset;
            }
        }
    }
}

int booking(struct Details custDets[], int size)
{
    int i;
    char key[1];

v:
    // system("cls");
    printf("\nEnter Customer Details: ");
    printf("\n**************************");
    printf("\nEnter Room Number: ");
    scanf("%d", &custDets[size].roomNum);
    fflush(stdin);
    printf("Enter Full Name: ");
    scanf(" %[^\n]s", custDets[size].cusName);
    printf("Enter Address: ");
    scanf(" %[^\n]s", custDets[size].address);
    printf("Enter Contact Number: ");
    scanf("%s", custDets[size].contactNo);
    printf("Enter Nationality: ");
    scanf("%s", custDets[size].nationality);
    printf("Enter Period('x'days): ");
    scanf("%d", &custDets[size].period);
    printf("Enter Arrival Date(mm/dd/yyyy): ");
    scanf("%s", &custDets[size].arrival);
    size++;

    FILE *add = fopen("data.txt", "w");

    sort_struct(custDets, size);

    for (i = 0; i < size; i++)
    {
        fprintf(add, "\n%d\n", custDets[i].roomNum);
        fprintf(add, "%s\n", custDets[i].cusName);
        fprintf(add, "%s\n", custDets[i].address);
        fprintf(add, "%s\n", custDets[i].contactNo);
        fprintf(add, "%s\n", custDets[i].nationality);
        fprintf(add, "%d\n", custDets[i].period);
        fprintf(add, "%s\n", custDets[i].arrival);
    }

    fclose(add);

    fflush(stdin);
    printf("\n\nSuccesfully booked!");
    printf("\nEnter N to add another detail, Enter E to go back to Main Menu.");
    printf("\n>");
    scanf("%s", key);

    if (strcmp(key, "N") == 0 || strcmp(key, "n") == 0)
    {
        clear(50);
        goto v;
    }
    else if (strcmp(key, "E") == 0 || strcmp(key, "E") == 0)
    {
        clear(50);
        main();
    }
}
void roomFeatures()
{
    char try[1];

    printf("\n\n                                        Room number            >>>        101 - 103");
    printf("\n\n");
    printf("\n                                              FEATURES OF THIS ROOM                       ");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n\n                                  Room Type            >>> Manila Bay Suite");
    printf("\n\n                                  Price per Night      >>> P116,300");
    printf("\n\n                                  No. of Beds          >>> 3 (2 double beds & 1 queen bed)");
    printf("\n\n                                  Capacity             >>> 6");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n                                               ADDITIONAL FEATURES                        ");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n\n                                                 >>> 3 Bathrooms");
    printf("\n\n                                                 >>> Shower and Bathtub");
    printf("\n\n                                                 >>> 2 Bedrooms");
    printf("\n\n                                                 >>> Free breakfast for 6");
    printf("\n\n                                                 >>> Free Wi-Fi");
    printf("\n\n                                                 >>> Outdoor View");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n\n                                        Room number            >>>        104 - 107");
    printf("\n\n");
    printf("\n                                              FEATURES OF THIS ROOM                       ");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n\n                                  Room Type            >>>  Executive Suite");
    printf("\n\n                                  Price per Night      >>> P26,865");
    printf("\n\n                                  No. of Beds          >>> 2 double beds");
    printf("\n\n                                  Capacity             >>> 5 (4 adult(s), 1 kid under");
    printf("\n\n                                                           12 years stays FREE");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n                                               ADDITIONAL FEATURES                        ");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n\n                                  Room Size            >>> 200 sq. m / 2153 sq. ft");
    printf("\n\n                                                       >>> Non-Smoking");
    printf("\n\n                                                       >>> Separate Shower/Bathtub");
    printf("\n\n                                                       >>> Free Wi-Fi");
    printf("\n\n                                                       >>> Outdoor View");
    printf("\n\n                                                       >>> Interconnecting room(s) available");
    printf("\n\n                                                       >>> Parking, Coffee & Tea, Express Check-In,");
    printf("\n\n                                                           Fitness Center, Welcome Drink");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n\n                                        Room number            >>>        108 - 110");
    printf("\n\n");
    printf("\n                                              FEATURES OF THIS ROOM                       ");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n\n                                  Room Type            >>> Premium Suite");
    printf("\n\n                                  Price per Night      >>> P18,408");
    printf("\n\n                                  No. of Beds          >>> 2 double beds");
    printf("\n\n                                  Capacity             >>> 4 (3 adult(s), 1 kid under 12 years");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n                                               ADDITIONAL FEATURES                        ");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n\n                                  Room Size            >>> 120 sq. m / 1292 sq. ft");
    printf("\n\n                                                       >>> Non-Smoking");
    printf("\n\n                                                       >>> Separate Shower/Bathtub");
    printf("\n\n                                                       >>> Free Wi-Fi");
    printf("\n\n                                                       >>> Outdoor View");
    printf("\n\n                                                       >>> Interconnecting room(s) available");
    printf("\n\n                                                       >>> Parking, Coffee & Tea, Express Check-In,");
    printf("\n\n                                                           Fitness Center");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n\n                                        Room number            >>>        111 - 115");
    printf("\n\n");
    printf("\n                                              FEATURES OF THIS ROOM                       ");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n\n                                  Room Type            >>> Grand Deluxe Room");
    printf("\n\n                                  Price per Night      >>> P13,482");
    printf("\n\n                                  No. of Beds          >>> 1 king bed");
    printf("\n\n                                  Capacity             >>> 2");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n                                               ADDITIONAL FEATURES                        ");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n\n                                  Room Size            >>> 75 sq. m / 807 sq. ft");
    printf("\n\n                                                       >>> Non-Smoking");
    printf("\n\n                                                       >>> Separate Shower/Bathtub");
    printf("\n\n                                                       >>> Free Wi-Fi");
    printf("\n\n                                                       >>> Outdoor View");
    printf("\n\n                                                       >>> Parking, Coffee & Tea, Express Check-In");
    printf("\n\n                                                           Fitness Center");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n\n                                        Room number            >>>        116 - 125");
    printf("\n\n");
    printf("\n                                              FEATURES OF THIS ROOM                       ");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n\n                                  Room Type            >>> Deluxe Room");
    printf("\n\n                                  Price per Night      >>> P10,448");
    printf("\n\n                                  No. of Beds          >>> 1 king bed");
    printf("\n\n                                  Capacity             >>> 2");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n                                               ADDITIONAL FEATURES                        ");
    printf("\n                        ------------------------------------------------------------------");
    printf("\n\n                                  Room Size            >>> 60 sq. m / 646 sq. ft");
    printf("\n\n                                                       >>> Non-Smoking");
    printf("\n\n                                                       >>> Separate Shower/Bathtub");
    printf("\n\n                                                       >>> Free Wi-Fi");
    printf("\n\n                                                       >>> Free Breakfast");
    printf("\n\n                                                       >>> Outdoor View");
    printf("\n\n                                                       >>> Parking, Coffee & Tea, Express Check-In");
    printf("\n\n                                                           Fitness Center");
    printf("\n                        ------------------------------------------------------------------");
reset:
    printf("\n\nEnter E to go back to Main Menu.");
    printf("\n>");
    scanf("%s", try);

    if (strcmp(try, "E") == 0 || strcmp(try, "e") == 0)
    {
        clear(50);
        main();
    }
    else
    {
        printf(" \n\nWrong Input");
        goto reset;
    }

    // getch();
}

int cusBalance(struct Details custDets[], int size)
{

    int roomNum, i, period, payment, indicator = 0;
    float price, change;
    char try[1];
resibo:
    printf("Enter Room Number to show receipt: ");
    scanf("%d", &roomNum);

    for (i = 0; i < size; i++)
    {

        if (roomNum == custDets[i].roomNum)
        {
            indicator = 1;
            break;
        }
    }

    if (indicator == 1)
    {
        if (roomNum >= 101 && roomNum <= 103)
        {
            period = custDets[i].period;
            printf("\n\tRECORD FOUND!\n");
            printf("\nRoom Number:\t%d", custDets[i].roomNum);
            printf("\nCustomer Name:\t%s", custDets[i].cusName);
            printf("\nPeriod:\t%d days", custDets[i].period);
            printf("\nPrice per Night: Php 116 300");
            price = 116300 * period;
            printf("\n---------------------------");
            printf("\nTOTAL:\tPhp %.2f\n", price);
            printf("\n---------------------------");
        pay:
            printf("\n\nEnter Payment:\tPhp ");
            scanf("%d", &payment);
            printf("\n---------------------------");
            change = payment - price;
            if (change >= 0)
            {
                printf("\nChange:\tPhp %.2f\n", change);
            }
            else if (change < 0)
            {
                printf("\nInsufficient Amount. Please try again.");
                goto pay;
            }
        }
        else if (roomNum >= 104 && roomNum <= 107)
        {
            period = custDets[i].period;
            printf("\n\tRECORD FOUND!\n");
            printf("\nRoom Number:\t%d", custDets[i].roomNum);
            printf("\nCustomer Name:\t%s", custDets[i].cusName);
            printf("\nPeriod:\t%d", custDets[i].period);
            printf("\nPrice per Night: Php 26 865");
            price = 26865 * period;
            printf("\n---------------------------");
            printf("\nTOTAL:\tPhp %.2f", price);
            printf("\n---------------------------");
        payy:
            printf("\n\nEnter Payment:\tPhp ");
            scanf("%d", &payment);
            printf("\n---------------------------");
            change = payment - price;
            if (change >= 0)
            {
                printf("\nChange:\tPhp%.2f\n", change);
            }
            else if (change < 0)
            {
                printf("\nInsufficient Amount. Please try again.");
                goto payy;
            }
        }
        else if (roomNum >= 108 && roomNum <= 110)
        {
            period = custDets[i].period;
            printf("\n\tRECORD FOUND!\n");
            printf("\nRoom Number:\t%d", custDets[i].roomNum);
            printf("\nCustomer Name:\t%s", custDets[i].cusName);
            printf("\nPeriod:\t%d", custDets[i].period);
            printf("\nPrice per Night: Php 18 408");
            price = 18408 * period;
            printf("\n---------------------------");
            printf("\nTOTAL:\tPhp %.2f", price);
            printf("\n---------------------------");
        payyy:
            printf("\n\nEnter Payment:\tPhp ");
            scanf("%d", &payment);
            printf("\n---------------------------");
            change = payment - price;
            if (change >= 0)
            {
                printf("\nChange:\tPhp %.2f\n", change);
            }
            else if (change < 0)
            {
                printf("\nInsufficient Amount. Please try again.");
                goto payyy;
            }
        }
        else if (roomNum >= 111 && roomNum <= 115)
        {
            period = custDets[i].period;
            printf("\n\tRECORD FOUND!\n");
            printf("\nRoom Number:\t%d", custDets[i].roomNum);
            printf("\nCustomer Name:\t%s", custDets[i].cusName);
            printf("\nPeriod:\t%d", custDets[i].period);
            printf("\nPrice per Night: Php 13 482");
            price = 13482 * period;
            printf("\n---------------------------");
            printf("\nTOTAL:\tPhp %.2f", price);
            printf("\n---------------------------");
        payyyy:
            printf("\n\nEnter Payment:\tPhp ");
            scanf("%d", &payment);
            printf("\n---------------------------");
            change = payment - price;
            if (change >= 0)
            {
                printf("\nChange:\tPhp %.2f\n", change);
            }
            else if (change < 0)
            {
                printf("\nInsufficient Amount. Please try again.");
                goto payyyy;
            }
        }
        else if (roomNum >= 116 && roomNum <= 125)
        {
            period = custDets[i].period;
            printf("\n\tRECORD FOUND!\n");
            printf("\nRoom Number:\t%d", custDets[i].roomNum);
            printf("\nCustomer Name:\t%s", custDets[i].cusName);
            printf("\nPeriod:\t%d", custDets[i].period);
            printf("\nPrice per Night: Php 10 448");
            price = 10448 * period;
            printf("\n---------------------------");
            printf("\nTOTAL:\tPhp %.2f", price);
            printf("\n---------------------------");
        payyyyy:
            printf("\n\nEnter Payment:\tPhp ");
            scanf("%d", &payment);
            printf("\n---------------------------");
            change = payment - price;
            if (change >= 0)
            {
                printf("\nChange:\tPhp %.2f\n", change);
            }
            else if (change < 0)
            {
                printf("\nInsufficient Amount. Please try again.");
                goto payyyyy;
            }
        }
        printf("\n");
    }
    else
    {
        printf("\n\tRoom number %d does not exist! Try again.\n\n", roomNum);
        goto resibo;
    }
reset:
    printf("\nDo you want to check on other receipts? Y/N");
    printf("\n>");
    scanf("%s", try);

    if (strcmp(try, "Y") == 0 || strcmp(try, "y") == 0)
    {
        strcpy(try, "0");
        clear(50);
        goto resibo;
    }
    else if (strcmp(try, "N") == 0 || strcmp(try, "n") == 0)
    {
        main();
    }
    else
    {
        printf("Wrong Input");
        goto reset;
    }
}

int cusList(struct Details custDets[])
{

    FILE *list;
    int i, size = 0;
    char try[1];
    list = fopen("data.txt", "r");

    while (!feof(list))
    {
    reset:
        fscanf(list, "\n%d", &custDets[size].roomNum);
        fscanf(list, " %[^\n]s", custDets[size].cusName);
        fscanf(list, " %[^\n]s", custDets[size].address);
        fscanf(list, "%s", custDets[size].contactNo);
        fscanf(list, "%s", custDets[size].nationality);
        fscanf(list, "%d", &custDets[size].period);
        fscanf(list, "%s\n", custDets[size].arrival);

        if (custDets[size].roomNum == 0)
        {
            custDets[size].roomNum = 1;
            strcpy(custDets[size].cusName, "INITIAL DATA");
            strcpy(custDets[size].address, "EARTH");
            strcpy(custDets[size].contactNo, "0948208279");
            strcpy(custDets[size].nationality, "JAPANESE");
            custDets[size].period = 2;
            strcpy(custDets[size].arrival, "08/22/2022");
            goto reset;
        }
        else
        {
            size++;
        }
    }
    fclose(list);
    // system("cls");
    clear(50);
    printf("  ----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("  |    ROOM     |  |            NAME            |  |            ADDRESS           |  |    CONTACT   |  | NATIONALITY |  | PERIOD |  |  ARRIVAL DATE  |\n");
    printf("  ----------------------------------------------------------------------------------------------------------------------------------------------------\n");

    sort_struct(custDets, size);
    for (i = 0; i < size; i++)
    {
        printf("  |%13d| ", custDets[i].roomNum);
        printf(" |%28s| ", custDets[i].cusName);
        printf(" |%30s| ", custDets[i].address);
        printf(" |%14s| ", custDets[i].contactNo);
        printf(" |%13s| ", custDets[i].nationality);
        printf(" |%8d| ", custDets[i].period);
        printf(" |%16s| \n", custDets[i].arrival);
        printf("  ----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    FILE *b = fopen("data.txt", "w");

    for (i = 0; i < size; i++)
    {
        fprintf(b, "\n%d\n", custDets[i].roomNum);
        fprintf(b, "%s\n", custDets[i].cusName);
        fprintf(b, "%s\n", custDets[i].address);
        fprintf(b, "%s\n", custDets[i].contactNo);
        fprintf(b, "%s\n", custDets[i].nationality);
        fprintf(b, "%d\n", custDets[i].period);
        fprintf(b, "%s\n", custDets[i].arrival);
    }
    fclose(b);
resett:
    printf("\nEnter Y to exit.");
    printf("\n>");
    scanf("%s", try);
    if (strcmp(try, "Y") == 0 || strcmp(try, "y") == 0)
    {
        main();
    }
    else
    {
        printf("Wrong Input");
        goto resett;
    }
    return size;
}

int delCusRec(struct Details custDets[], int size)
{

    // FILE *data;
    int i = 1, j, k, copy;
    int roomNum;
    char try[1];
    // data = fopen("data.txt", "r");
    // system("cls");
    printf("Enter the Customer's Room Number to erase customer's data from the database: ");
    scanf("%d", &roomNum);

    for (j = 0; j < size; j++)
    {

        if (roomNum == custDets[j].roomNum)
        {
            i = 0;
            copy = j;
        }
    }

    // fclose(data);
    //  printf("INDEX: %d", copy);

    for (k = copy; k < size; k++)
    {
        custDets[k].roomNum = custDets[k + 1].roomNum;
        strcpy(custDets[k].cusName, custDets[k + 1].cusName);
        strcpy(custDets[k].address, custDets[k + 1].address);
        strcpy(custDets[k].contactNo, custDets[k + 1].contactNo);
        strcpy(custDets[k].nationality, custDets[k + 1].nationality);
        custDets[k].period = custDets[k + 1].period;
        strcpy(custDets[k].arrival, custDets[k + 1].arrival);
    }
    size--;

    FILE *b = fopen("data.txt", "w");
    // SORT FUNCTION FOR STRUCT
    sort_struct(custDets, size);
    for (j = 0; j < size; j++)
    {
        fprintf(b, "\n%d\n", custDets[j].roomNum);
        fprintf(b, "%s\n", custDets[j].cusName);
        fprintf(b, "%s\n", custDets[j].address);
        fprintf(b, "%s\n", custDets[j].contactNo);
        fprintf(b, "%s\n", custDets[j].nationality);
        fprintf(b, "%d\n", custDets[j].period);
        fprintf(b, "%s\n", custDets[j].arrival);
    }
    fclose(b);

    if (i == 1)
    {
        printf("\n\nRoom number %d does not exist!", roomNum);
        // getch();
        main();
    }
    else
    {
        printf("\n\nThe customer information of Room Number %d is succesfully removed.", roomNum);
    resett:
        printf("\nEnter Y to exit.");
        printf("\n>");
        scanf("%s", try);
        if (strcmp(try, "Y") == 0 || strcmp(try, "y") == 0)
        {
            main();
        }
        else
        {
            printf("Wrong Input");
            goto resett;
        }
        return size;
    }
}

void cusSearch(struct Details custDets[], int size)
{
    int roomNum, i, indicator = 0;
    char try[1];
start:
    printf("Enter Room Number to search: ");
    scanf("%d", &roomNum);

    for (i = 0; i < size; i++)
    {

        if (roomNum == custDets[i].roomNum)
        {
            indicator = 1;
            break;
        }
    }

    if (indicator == 1)
    {

        printf("\n\tRECORD FOUND!\n");
        printf("\nRoom Number:\t%d", custDets[i].roomNum);
        printf("\nCustomer Name:\t%s", custDets[i].cusName);
        printf("\nAddress:\t%s", custDets[i].address);
        printf("\nContact Number:\t%s", custDets[i].contactNo);
        printf("\nNationality:\t%s", custDets[i].nationality);
        printf("\nPeriod:\t%d", custDets[i].period);
        printf("\nArrival Date:\t%s", custDets[i].arrival);
    }
    else
    {
        printf("\n\tRoom number %d does not exist! Try again.\n\n", roomNum);
        goto start;
    }

reset:
    printf("\n\nDo you want to search other customer? Y/N");
    printf("\n>");
    scanf("%s", try);

    if (strcmp(try, "Y") == 0 || strcmp(try, "y") == 0)
    {
        strcpy(try, "0");
        clear(50);
        goto start;
    }
    else if (strcmp(try, "N") == 0 || strcmp(try, "n") == 0)
    {
        main();
    }
    else
    {
        printf("Wrong Input");
        goto reset;
    }
}

void sort_struct(struct Details custDets[], int size)
{
    int i, j;
    struct Details temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < (size - 1 - i); j++)
        {
            if (custDets[j].roomNum > custDets[j + 1].roomNum)
            {
                temp = custDets[j];
                custDets[j] = custDets[j + 1];
                custDets[j + 1] = temp;
            }
        }
    }
}

float total;

//--------------------------------------------------Restaurant--------------------------------------------------//

void restaurantMainMenu()
{
    int i = 0;
    char customerName;
    int choice;
    char try[1];

    // system("cls"); // FOR CLEARING SCREEN
    clear(50);
    printf("\t\t*************************************************\n");
    printf("\t\t*                                               *\n");
    printf("\t\t*       -----------------------------           *\n");
    printf("\t\t*         HOTEL TRIVAGO RESTAURANT              *\n");
    printf("\t\t*       -----------------------------           *\n");
    printf("\t\t*                                               *\n");
    printf("\t\t*************************************************\n\n\n");
    // printf(" \n Press any key to continue:");

    // getch();
    // system("cls");
    while (1) // INFINITE LOOP
    {
        // system("cls");
        for (i = 0; i < 80; i++)
            printf("-");
        printf("\n");
        printf("   ******************************  |TRANSACTION MENU|  ***************************** \n");
        for (i = 0; i < 80; i++)
            printf("-");
        printf("\n");
        printf("\t\t *Please enter your desired transaction*:");
        printf("\n\n");
        printf(" \n Enter 1 -> Breakfast Dishes");
        printf("\n-----------------------------");
        printf(" \n Enter 2 -> Main Dishes");
        printf("\n------------------------");
        printf(" \n Enter 3 -> Desserts");
        printf("\n---------------------");
        printf(" \n Enter 4 -> Drinks");
        printf("\n-------------------");
        printf(" \n Enter 5 -> Back to Main Menu");
        printf("\n------------------------------");
        printf("\n> ");
        scanf("%d", &choice);
        // choice = getche();
        //  choice = toupper(choice);
        switch (choice) // SWITCH
        {
        case 1:
            clear(50);
            restaurantBreakfast();
            break;
        case 2:
            clear(50);
            restaurantMainDish();
            break;
        case 3:
            clear(50);
            restaurantDessert();
            break;
        case 4:
            clear(50);
            restaurantDrinks();
            break;
        case 5:
            printf("\n\n\t *****THANK YOU FOR TRUSTING OUR SERVICE*****");
            //	Sleep(2000);
            main();
            break;
        default:
        reset:
            printf("Wrong Input");
            printf("\n Try again? Y/N");
            printf("\n> ");
            scanf("%s", try);

            if (strcmp(try, "Y") == 0 || strcmp(try, "y") == 0)
            {
                strcpy(try, "0");
            }
            else if (strcmp(try, "N") == 0 || strcmp(try, "n") == 0)
            {
                clear(50);
                main();
            }
            else
            {
                goto reset;
            }
        }
    }
}

void restaurantBreakfast()
{
    int choice = 0;
    int qty = 0;
    int again = 0;
    // system("cls");
    printf("\n                                                    BREAKFAST MENU                       ");
    printf("\n                        ------------------------------------------------------------------\n");
    printf("\t\t\t   [1] Bihon Guisado                          - Php 75\n");
    printf("\t\t\t   [2] Canton Special                         - Php 75\n");
    printf("\t\t\t   [3] Sotanghon Guisado                      - Php 75\n");
    printf("\t\t\t   [4] Spaghetti with Meat Sauce              - Php 100\n");
    printf("\t\t\t   [5] Spicy Oriental Noodles                 - Php 90\n");
    printf("\t\t\t   [6] Lomi Soup                              - Php 150\n");
    printf("\t\t\t   [7] Sotanghon Soup                         - Php 200\n");
    printf("\t\t\t   [8] Back To Main-Menu         ");

    printf("\n\n \t   Enter your choice here : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("\n[1] Bihon Guisado\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 75 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    order:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantBreakfast();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto order;
        }
    }
    else if (choice == 2)
    {
        printf("\n[2] Canton Special\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 75 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    orderr:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantBreakfast();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto orderr;
        }
    }
    else if (choice == 3)
    {
        printf("\n[3] Sotanghon Guisado\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 75 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    orderrr:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantBreakfast();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto orderrr;
        }
    }
    else if (choice == 4)
    {
        printf("\n[4] Spaghetti with Meat Sauce\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 100 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    orderrrr:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantBreakfast();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto orderrrr;
        }
    }
    else if (choice == 5)
    {
        printf("\n[5] Spicy Oriental Noodles\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 90 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    orderrrrr:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantBreakfast();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto orderrrrr;
        }
    }
    else if (choice == 6)
    {
        printf("\n[6] Lomi Soup\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 150 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    orderrrrrr:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantBreakfast();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto orderrrrrr;
        }
    }
    else if (choice == 7)
    {
        printf("\n[7] Sotanghon Soup\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 200 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    orderrrrrrr:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantBreakfast();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto orderrrrrrr;
        }
    }
    else if (choice == 8)
    {
        restaurantMainMenu();
    }
    else if (choice != 1, 2, 3, 4, 5, 6, 7, 8)
    {
        printf("\n\n\t\t   Invalid Choice Entered\n\n");
        restaurantBreakfast();
    }
}

void restaurantMainDish()
{
    int choice = 0;
    int qty = 0;
    int again = 0;
    // system("cls");
    printf("\n                                                      MAIN DISHES                       ");
    printf("\n                        ------------------------------------------------------------------\n");
    printf("\t\t\t   [1] Buttered Fried Chicken                 - Php 400\n");
    printf("\t\t\t   [2] Chicken Lollipop                       - Php 250\n");
    printf("\t\t\t   [3] Chicken Teriyaki                       - Php 850\n");
    printf("\t\t\t   [4] Crispy Chicken Wings                   - Php 250\n");
    printf("\t\t\t   [5] Garlic Fried Chicken                   - Php 500\n");
    printf("\t\t\t   [6] Assorted Vegetables with Quail Eggs    - Php 650\n");
    printf("\t\t\t   [7] Chopsuey                               - Php 600\n");
    printf("\t\t\t   [8] Fresh Lumpiang Ubod                    - Php 300\n");
    printf("\t\t\t   [9] Fried Lumpiang Ubod                    - Php 300\n");
    printf("\t\t\t   [10] Chicharon Bulaklak                    - Php 350\n");
    printf("\t\t\t   [11] Crispy Pata                           - Php 480\n");
    printf("\t\t\t   [12] Fried Lumpiang Shanghai               - Php 150\n");
    printf("\t\t\t   [13] Lechon Kawali                         - Php 900\n");
    printf("\t\t\t   [14] Pork Barbeque                         - Php 200\n");
    printf("\t\t\t   [15] Pork Sisig                            - Php 275\n");
    printf("\t\t\t   [16] Kare-Kare with Bagoong                - Php 770\n");
    printf("\t\t\t   [17] Beef Morcon in Tomato Sauce           - Php 1000\n");
    printf("\t\t\t   [18] Calamares                             - Php 300\n");
    printf("\t\t\t   [19] Fish Fillet with Tartar Sauce         - Php 900\n");
    printf("\t\t\t   [20] Sweet and Sour Fish Fillet            - Php 900\n");
    printf("\t\t\t   [21] Back To Main-Menu         ");

    printf("\n\n \t   Enter your choice here : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("\n[1] Buttered Fried Chicken\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 400 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    a:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto a;
        }
    }
    else if (choice == 2)
    {
        printf("\n[2] Chicken Lollipop\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 250 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    b:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto b;
        }
    }
    else if (choice == 3)
    {
        printf("\n[3] Chicken Teriyaki\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 850 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php%.2f,\n", total);
        printf("====================================          \n");
    c:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto c;
        }
    }
    else if (choice == 4)
    {
        printf("\n[4] Crispy Chicken Wings\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 250 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    d:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto d;
        }
    }
    else if (choice == 5)
    {
        printf("\n[5] Garlic Fried Chicken\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 500 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    e:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto e;
        }
    }
    else if (choice == 6)
    {
        printf("\n[6] Assorted Vegetables with Quail Eggs\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 650 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    f:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto f;
        }
    }
    else if (choice == 7)
    {
        printf("\n[7] Chopsuey\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 600 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    g:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto g;
        }
    }
    else if (choice == 8)
    {
        printf("\n[8] Fresh Lumpiang Ubod\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 300 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    h:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto h;
        }
    }
    else if (choice == 9)
    {
        printf("\n[9] Fried Lumpiang Ubod\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 300 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    i:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto i;
        }
    }
    else if (choice == 10)
    {
        printf("\n[10] Chicharon Bulaklak\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 350 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    j:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto j;
        }
    }
    else if (choice == 11)
    {
        printf("\n[11] Crispy Pata\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 480 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    u:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto u;
        }
    }
    else if (choice == 12)
    {
        printf("\n[12] Fried Lumpiang Shanghai\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 150 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    k:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto k;
        }
    }
    else if (choice == 13)
    {
        printf("\n[13] Lechon Kawali\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 900 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    l:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto l;
        }
    }
    else if (choice == 14)
    {
        printf("\n[14] Pork Barbeque\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 200 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    m:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto m;
        }
    }
    else if (choice == 15)
    {
        printf("\n[15] Pork Sisig\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 275 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    n:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto n;
        }
    }

    else if (choice == 16)
    {
        printf("\n[16] Kare-kare with Bagoong\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 770 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    o:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto o;
        }
    }
    else if (choice == 17)
    {
        printf("\n[17] Beef Morcon in Tomato Sauce\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 1000 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    q:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto q;
        }
    }
    else if (choice == 18)
    {
        printf("\n[18] Calamares\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 300 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    r:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto r;
        }
    }
    else if (choice == 19)
    {
        printf("\n[19] Fish Fillet with Tartar Sauce\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 900 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    s:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto s;
        }
    }
    else if (choice == 20)
    {
        printf("\n[20] Sweet and Sour Fish Fillet\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 900 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    t:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantMainDish();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto t;
        }
    }

    else if (choice == 21)
    {
        restaurantMainMenu();
    }
    else if (choice != 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21)
    {
        // system("cls");
        printf("\n\n\t\t   Invalid Choice Entered\n\n");
        restaurantMainDish();
    }
}
void restaurantDessert()
{
    int choice = 0;
    int qty = 0;
    int again = 0;
    // system("cls");
    printf("\n                                                      DESSERTS                       ");
    printf("\n                        ------------------------------------------------------------------\n");
    printf("\t\t\t   [1] Pichi Pichi with Cheese                - Php 85\n");
    printf("\t\t\t   [2] Pichi Pichi with Honey Roasted Peanuts - Php 85\n");
    printf("\t\t\t   [3] Pichi Pichi with Fresh Coconut         - Php 85\n");
    printf("\t\t\t   [4] Puto Cheese                            - Php 200\n");
    printf("\t\t\t   [5] Leche Flan                             - Php 75\n");
    printf("\t\t\t   [6] Cheesecake                             - Php 150\n");
    printf("\t\t\t   [7] Luxury Ice Cream (Unli)                - Php 500\n");
    printf("\t\t\t   [8] Back To Main-Menu         ");

    printf("\n\n \t   Enter your choice here : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("\n[1] Pichi Pichi with Cheese\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 85 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    a:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantDessert();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto a;
        }
    }
    else if (choice == 2)
    {
        printf("\n[2] Pichi Pichi with Honey Roasted Peanuts\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 85 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    b:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantDessert();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto b;
        }
    }
    else if (choice == 3)
    {
        printf("\n[3] Pichi Pichi with Fresh Coconut\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 85 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    c:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantDessert();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto c;
        }
    }
    else if (choice == 4)
    {
        printf("\n[4] Puto Cheese\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 200 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    d:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantDessert();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto d;
        }
    }
    else if (choice == 5)
    {
        printf("\n[5] Leche Flan\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 75 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    e:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantDessert();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto e;
        }
    }
    else if (choice == 6)
    {
        printf("\n[6] Cheesecake\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 150 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    f:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantDessert();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto f;
        }
    }
    else if (choice == 7)
    {
        printf("\n[7] Luxury Ice Cream (Unli)\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 500 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    g:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantDessert();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto g;
        }
    }
    else if (choice == 8)
    {
        restaurantMainMenu();
    }
    else if (choice != 1, 2, 3, 4, 5, 6, 7, 8)
    {
        // system("cls");
        printf("\n\n\t\t   Invalid Choice Entered\n\n");
        restaurantDessert();
    }
}

void restaurantDrinks()
{
    int choice = 0;
    int qty = 0;
    int again = 0;
    // system("cls");
    printf("\n                                                       DRINKS                       ");
    printf("\n                        ------------------------------------------------------------------\n");
    printf("\t\t\t   [1] Tea                                    - Php 85\n");
    printf("\t\t\t   [2] Espresso                               - Php 85\n");
    printf("\t\t\t   [3] Espresso Macchiato                     - Php 150\n");
    printf("\t\t\t   [4] Latte                                  - Php 200\n");
    printf("\t\t\t   [5] Nescafe Classic                        - Php 5\n");
    printf("\t\t\t   [6] Orange Juice                           - Php 50\n");
    printf("\t\t\t   [7] Regular Soda                           - Php 40\n");
    printf("\t\t\t   [8] Back To Main-Menu         ");

    printf("\n\n \t   Enter your choice here : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("\n[1] Tea\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 85 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    a:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantDrinks();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto a;
        }
    }
    else if (choice == 2)
    {
        printf("\n[2] Espresso\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 85 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    b:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantDrinks();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto b;
        }
    }
    else if (choice == 3)
    {
        printf("\n[3] Espresso Macchiato\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 150 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    c:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantDrinks();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto c;
        }
    }
    else if (choice == 4)
    {
        printf("\n[4] Latte\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 200 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    d:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantDrinks();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto d;
        }
    }
    else if (choice == 5)
    {
        printf("\n[5] Nescafe Classic\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 5 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    e:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantDrinks();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto e;
        }
    }
    else if (choice == 6)
    {
        printf("\n[6] Orange Juice\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 50 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    f:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantDrinks();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto f;
        }
    }
    else if (choice == 7)
    {
        printf("\n[7] Regular Soda\n\n");
        printf("Enter Quantity : ");
        scanf("%d", &qty);
        total = 40 * qty;
        printf("===================================          ");
        printf("\nYour total bill amount is Php %.2f,\n", total);
        printf("====================================          \n");
    g:
        printf("Would you like to order more?\nEnter [1] - Yes, Enter [2] - No : ");
        scanf("%d", &again);
        // system("cls");

        if (again == 1)
            restaurantDrinks();
        else if (again == 2)
            restaurantMainMenu();
        else if (again != 1, 2)
        {
            printf("\n\n\t\tSorry Invalid Decision Entered\n\n");
            goto g;
        }
    }
    else if (choice == 8)
    {
        restaurantMainMenu();
    }
    else if (choice != 1, 2, 3, 4, 5, 6, 7, 8)
    {
        // system("cls");
        printf("\n\n\t\t   Invalid Choice Entered\n\n");
        restaurantDrinks();
    }
}

void clear(int i)
{
    for (int j = 0; j < i; j++)
        printf(" \n");
}