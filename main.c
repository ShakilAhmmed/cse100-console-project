#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#define MAX_LIMIT 100
#define BUS_FILE "C:\\Users\\mahad\\OneDrive\\Desktop\\BusTicketReservationProject\\bus.txt"
#define CUS_FILE "C:\\Users\\mahad\\OneDrive\\Desktop\\BusTicketReservationProject\\customer.txt"
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
    printf("\t\t\t\t\t 1.Press 1 For Add New Bus\n");
    printf("\t\t\t\t\t 2.Press 2 For View Bus Details\n");
    printf("\t\t\t\t\t 3.Press 3 For Add New Customer\n");
    printf("\t\t\t\t\t 4.Press 4 For View Customer Details\n");
    printf("\t\t\t\t\t 5.Press 5 For See Available Bus\n");
    printf("\t\t\t\t\t 6.Press 6 For Booking Seat\n");
    printf("\t\t\t\t\t 7.Press 7 For See Bus Book Seat Details\n");
    printf("\t\t\t\t\t 8.Press 8 For Quit :) \n");
    printf("\n\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
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
void adminlogin()
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
    printf("\n UserID : ");
    scanf("%s", &usserid);
    printf("\n Password : ");
    scanf("%s", &password);
    while (fread(&r, sizeof(r), 1, fptr));
    {
        if (strcmp(usserid, r.user_id) == 0 && strcmp(password, r.password)==0)
        {

            printf("\nYou are successfully logged in !!\n");


        }
        else
        {
            printf("\nYour UserID or password is incorrect !!\n");
            printf("Press any key to continue ...\n");
            adminlogin();
        }


    }
    fclose(fptr);

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

void addNewCustomer()
{
    printf("\t Add New Customer\n");
    char cus_name[MAX_LIMIT], cus_phone[MAX_LIMIT], password[MAX_LIMIT];

    printf("\t Enter Customer Name:");
    fgets(cus_name, MAX_LIMIT, stdin);
    scanf("%[^\n]%*c", cus_name);
    printf("\n");

    printf("\t Enter Customer Phone:");
    fgets(cus_phone, MAX_LIMIT, stdin);
    scanf("%[^\n]%*c", cus_phone);
    printf("\n");

    printf("\t Enter Customer Password:");
    fgets(password, MAX_LIMIT, stdin);
    scanf("%[^\n]%*c", password);

    FILE *fptr;
    fptr = fopen("customer.txt","a");
    if(fptr == NULL) {
      printf("Error!");
      exit(1);
    }
    fprintf(fptr,"Customer Name = %s Customer Phone = %s Password = %s\n", cus_name,cus_phone,password);
    fclose(fptr);
}

void viewCus()
{
    char ch;
    FILE *fptr;
    fptr = fopen("customer.txt","r");
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

int main()
{
    welcomeScreen();
    menuScreen();
    for(;;) {
        int choice;
        printf("\tEnter Your Choice:");
        scanf("%d",&choice);
        if(choice == 1) {
            adminRegister();
        }else if(choice == 2) {
            adminlogin();
        }else if(choice == 3) {
            addNewCustomer();
        }else if(choice == 4) {
            viewCus();
        }else if(choice == 5) {
            seeAvailableBus();
        }else if(choice == 6) {
            bookSeat();
        }else if(choice == 7) {
            seatBookDetails();
        }else if(choice == 8) {
            printf("\t \a Thank You For Choosing Us.Have a Great Day :)\n");
            exit(0);
        }else {
            printf("\t Sorry Your Choice Is Wrong.\n");
        }
    }
    getch();
    return 0;
}
