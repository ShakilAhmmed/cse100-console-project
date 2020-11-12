#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#define MAX_LIMIT 100
#define RVALUE 5
#define CVALUE 10
#define BUS_FILE "C:\\Users\\mahad\\OneDrive\\Desktop\\BusTicketReservationProject\\bus.txt"
#define CUS_FILE "C:\\Users\\mahad\\OneDrive\\Desktop\\BusTicketReservationProject\\customer.txt"
int Seats[RVALUE][CVALUE];
void welcomeScreen()
{

    printf("\n\n\n\n\n\n\n\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	printf("\n\t\t\t\t#\t\t WELCOME\t\t#");
	printf("\n\t\t\t\t#\t Bus Ticket Reservation System \t#");
	printf("\n\t\t\t\t#\t\t Team Members \t\t#");
	printf("\n\t\t\t\t#\t Nasima Akter Tania - 012 \t#");
	printf("\n\t\t\t\t#\t Shakil Ahmmed - 013 \t\t#");
	printf("\n\t\t\t\t#\t Mahedi Hasan - 011 \t\t#");
	printf("\n\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\t\t\t\t\t\n");
}

void menuScreen()
{
    printf("\n\n\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\t\t\t\t\t 1.Press 1 For Register Admin \n");
    printf("\t\t\t\t\t 2.Press 2 For Admin Login \n");
    printf("\t\t\t\t\t 3.Press 3 For Customer SingUp \n");
    printf("\t\t\t\t\t 4.Press 4 For Customer Login \n");
    printf("\t\t\t\t\t 5.Press 5 For Quit :) \n");
    printf("\n\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
}

void menuScreenAdmin()
{
    printf("\n\n\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\t\t\t 1.Press 1 For  Add Bus \n");
    printf("\t\t\t 2.Press 2 For See Bus Details \n");
    printf("\t\t\t 3.Press 3 For See Available Bus Seat \n");
    printf("\t\t\t 4.Press 4 For See Customer Details \n");
    printf("\t\t\t 5.Press 5 Return Main Menu \n");
    printf("\t\t\t 6.Press 6 For Quit :) \n");
    printf("\n\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
}
struct user
{
    char user_id[MAX_LIMIT];
    char user_name[MAX_LIMIT];
    char password[MAX_LIMIT];
    char email[MAX_LIMIT];
    char phone[MAX_LIMIT];
};

void adminRegister()
{
    FILE *fptr;
    struct user r;
    fptr = fopen("user.txt","a");
    printf("\t Add New Admin\n");
    printf("\t Enter User ID: ");
    scanf("%s", &r.user_id);
    printf("\t Enter User Name: ");
    scanf("%s", &r.user_name);
    printf("\t Enter User Password: ");
    scanf("%s",&r.password);
    printf("\t Enter User Email: ");
    scanf("%s",&r.email);
    printf("\t Enter User Phone: ");
    scanf("%s",&r.phone);



    if(fptr == NULL) {
      printf("Error!");
      exit(1);
    }
    fwrite(&r, sizeof(r), 1, fptr);
    fclose(fptr);
    printf("\t \t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\t \t \t You are successfully registered!! \n");
    printf("\t \t \t Your UserId is %s and your password is %s \n", r.user_id, r.password);
    printf("\t \t \t Now login with your userid and password!! Press By 2 \n");
    printf("\t \t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n");


}
void adminLogin()
{
    char usserid[MAX_LIMIT];
    char password[MAX_LIMIT];
    FILE *fptr;
    struct user r;
    fptr = fopen("user.txt", "r");
    if (fptr == NULL)
    {
        printf("FILE NOT FOUND!!!");
        exit(1);
    }
    printf("\t UserID : ");
    scanf("%s", &usserid);
    printf("\t Password : ");
    scanf("%s", &password);
    while (fread(&r, sizeof(r), 1, fptr));
    {
        if (strcmp(usserid, r.user_id) == 0 && strcmp(password, r.password)==0)
        {
            printf("\t \t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            printf("\t \t \t You are successfully logged in :)\n");
            printf("\t \t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            subMenuAdmin();
        }
        else
        {

            printf("\t \t **************************************************\n");
            printf("\t \t \t Your UserID or password is incorrect !!\n");
            printf("\t \t **************************************************\n");
            printf("\n");
            adminLogin();
        }


    }
    fclose(fptr);

}

void addNewCustomer()
{
    FILE *fptr;
    struct user cr;
    fptr = fopen("customer.txt","a");
    printf("\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\t \t Welcome Customer Register Panel\n");
    printf("\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n");
    printf("\t Enter User ID: ");
    scanf("%s", &cr.user_id);
    printf("\t Enter User Name: ");
    scanf("%s", &cr.user_name);
    printf("\t Enter User Password: ");
    scanf("%s",&cr.password);
    printf("\t Enter User Email: ");
    scanf("%s",&cr.email);
    printf("\t Enter User Phone: ");
    scanf("%s",&cr.phone);

    if(fptr == NULL) {
      printf("Error!");
      exit(1);
    }

    fwrite(&cr, sizeof(cr), 1, fptr);
    fclose(fptr);
    printf("\t \t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\t \t \t You are successfully registered!! \n");
    printf("\t \t \t Your UserId is %s and your password is %s \n", cr.user_id, cr.password);
    printf("\t \t \t Now login with your userid and password!! Press By 3 \n");
    printf("\t \t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n");

}

void customerLogin()
{
    char usserid[MAX_LIMIT];
    char password[MAX_LIMIT];
    int count_commit = 0;
    FILE *fptr;
    struct user cr;
    fptr = fopen("customer.txt", "r");
    if (fptr == NULL)
    {
        printf("FILE NOT FOUND!!!");
        exit(1);
    }
    printf("\t UserID : ");
    scanf("%s", &usserid);
    printf("\t Password : ");
    scanf("%s", &password);
    while (fread(&cr, sizeof(cr), 1, fptr));
    {
        if (strcmp(usserid, cr.user_id) == 0 && strcmp(password, cr.password)==0)
        {

            printf("\t \t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            printf("\t \t \t You are successfully logged in :)\n");
            printf("\t \t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");


        }
        else
        {

            printf("\t \t **************************************************\n");
            printf("\t \t \t Your UserID or password is incorrect !!\n");
            printf("\t \t **************************************************\n");
            printf("\n");
            customerLogin();

        }


    }
    fclose(fptr);
}

void viewCustomer()
{
    char ch;
    FILE *fptr;
    struct user cr;
    fptr = fopen("customer.txt","r");
    if(fptr == NULL) {
      printf("Error!");
      exit(1);
    }
    printf("\t---------------------------------------------------------------------------------------------\n");

    while(fread(&cr, sizeof(struct user), 1, fptr))

        printf ("\t \t Id = %s \t| Name = %s \t| Email = %s  \t| Phone = %s \n", cr.user_id,cr.user_name, cr.email, cr.phone);

    printf("\t---------------------------------------------------------------------------------------------\n");
    // close file
    fclose (fptr);
}

void addBus()
{
    printf("\t Add New Bus\n");
    char bus_name[MAX_LIMIT];
    int seat;
    printf("\t Enter Bus Name:");
    fgets(bus_name, MAX_LIMIT, stdin);
    scanf("%[^\n]%*c", bus_name);
    printf("\n");
    printf("\t Enter Total Seat:");
    scanf("%d",&seat);
    FILE *fptr;
    fptr = fopen("bus.txt","a");
    if(fptr == NULL) {
      printf("Error!");
      exit(1);
    }
    fprintf(fptr,"Bus Name = %s Total Seat Is = %d\n",bus_name,seat);
    fclose(fptr);

}

void viewBus()
{
    char ch;
    FILE *fptr;
    fptr = fopen("bus.txt","r");
    if(fptr == NULL) {
      printf("Error!");
      exit(1);
    }
    do{
        ch = fgetc(fptr);
        putchar(ch);
    } while(ch != EOF);
}

void seeAvailableBus()
{
    printf("\tSee Available Bus");
}

void bookSeat()
{
    printf("\t book Seat");
    char bus_name[MAX_LIMIT];
    char cus_name[MAX_LIMIT];
    char seat_num[MAX_LIMIT];
    char date[MAX_LIMIT];
    int amount, d, m, year;
    //Search_in_File("bus_seatbook.txt", )
    //time_t t = time(NULL);
    //struct tm tm = *localtime(&t);
    //printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("\t Enter Date (dd/mm/yy): ");
    fgets(date, MAX_LIMIT, stdin);
    scanf("%[^\n]%*c", date);
    printf("\t Enter Bus Name: ");
    scanf("%[^\n]%*c", bus_name);
    printf("\n");
    printf("\t Enter Customer Name: ");
    scanf("%[^\n]%*c", cus_name);
    printf("\n");
    printf("\t Enter Seat Number: ");
    scanf("%[^\n]%*c", seat_num);
    printf("\n");
    printf("\t Enter Amount Of Ticket:");
    scanf("%d",&amount);
    FILE *fptr;
    fptr = fopen("bus_seatbook.txt","a");
    if(fptr == NULL) {
      printf("Error!");
      exit(1);
    }
    fprintf(fptr,"Date = %s Bus Name = %s Customer Name = %s Seat Number = %s Amount Of Ticket = %d\n",date,bus_name,cus_name,seat_num,amount);

    fclose(fptr);
}

void seatBookDetails() {
    char ch;
    FILE *fp = fopen("bus_seatbook.txt","r");
    if(fp == NULL) {

      printf("Error!");
      exit(1);

    }
     do{
        ch = fgetc(fp);
        putchar(ch);
    } while(ch != EOF);


	return 0;
}

void ChooseSeat(void)
{

    int row, col,k;
    printf("Which row do you want to choose? : ");
    scanf("%d", &row);
    printf("Which seat do you want to select? : ");
    scanf("%d", &col);
    if (row > RVALUE || col > CVALUE)
    {
        printf("Wrong Entry !! Try again\n");
        ChooseSeat();
    }
    else if (Seats[row - 1][col - 1] != 0)
    {
        printf("Seat is already reserved try again !!\n");
        ChooseSeat();
    }
    else
    {
        Seats[row - 1][col - 1] = 1;
        printf("Congratulations!! Reservation Completed!!!\n");
        DisplaySeats();
        printf("\nPress any key to go to main menu!!");
    }


}
void DisplaySeats(void)
{
	printf("\t \t Seats\n");
    printf("\t 1 2 3 4 5 6 7 8 9 10\n");

    for (int i = 0; i < RVALUE; i++)
    {
        printf("Rows %d : ", i + 1);
        for (int j = 0; j < CVALUE; j++)
            printf("%d ", Seats[i][j]);
        printf("\n");
    }
    printf("\n");

}
void ReserveSeats(void)
{
    int NoOfSeats,i;
    printf("How many seats do you want to reserve?\n");
    scanf("%d", &NoOfSeats);
    DisplaySeats();
    for (i = 1; i <= NoOfSeats; i++)
    {
        ChooseSeat();
    }


}
void subMenuAdmin()
{
    menuScreenAdmin();
    for(;;) {
        int choice;
        printf("\tEnter Your Choice: ");
        scanf("%d",&choice);
        if(choice == 1) {
           ReserveSeats();
        }else if(choice == 2) {
            adminLogin();
        }else if(choice == 3) {
            addNewCustomer();
        }else if(choice ==4){
            viewCustomer();
        }else if(choice ==5){
            subMenuAdmin();
        }else if(choice == 6) {
            printf("\t \a Thank You For Choosing Us.Have a Great Day :)\n");
            exit(0);
        }else {
            printf("\t Sorry Your Choice Is Wrong.\n");
        }
    }
}
int main()
{
    welcomeScreen();
    menuScreen();
    for(;;) {
        int choice;
        printf("\tEnter Your Choice: ");
        scanf("%d",&choice);
        if(choice == 1) {
           adminRegister();
        }else if(choice == 2) {
            adminLogin();
        }else if(choice == 3) {
            addNewCustomer();
        }else if(choice ==4){
            customerLogin();
        }else if(choice == 4) {
            printf("\t \a Thank You For Choosing Us.Have a Great Day :)\n");
            exit(0);
        }else {
            printf("\t Sorry Your Choice Is Wrong.\n");
        }
    }
    getch();
    return 0;
}
