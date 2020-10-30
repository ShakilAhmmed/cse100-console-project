#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#define MAX_LIMIT 100
#define BUS_FILE "C:\\Users\\shaki\\OneDrive\\Desktop\\BusTicketReservationProject\\bus.txt"
void welcomeScreen()
{
    printf("\t\t\t\t\t\t\aWelcome\n");
    printf("\t\t\t\t\tBus Ticket Reservation System\n");
}

void menuScreen()
{
    printf("\t 1.Press 1 For Add New Bus\n");
    printf("\t 2.Press 2 For Add New Customer\n");
    printf("\t 3.Press 3 For See Available Bus\n");
    printf("\t 4.Press 4 For Booking Seat\n");
    printf("\t 5.Press 5 For Quit :) \n");
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
    //char cwd[PATH_MAX];
    /*if (getcwd(cwd, sizeof(cwd)) != NULL) {
        strcat(cwd, "\bus.txt");
        fptr = fopen(cwd,"w");
        if(fptr == NULL) {
          printf("Error!");
          exit(1);
       }
       fprintf(fptr,"%s",bus_name);
       fprintf(fptr,"%d",seat);
       fclose(fptr);
   }*/

    fptr = fopen(BUS_FILE,"a");
    if(fptr == NULL) {
      printf("Error!");
      exit(1);
    }
    fprintf(fptr,"Bus Name = %s Total Seat Is = %d\n",bus_name,seat);
    fclose(fptr);

}

void addNewCustomer()
{
    printf("\tAdd New Customer");
}

void seeAvailableBus()
{
    printf("\tSee Available Bus");
}

void bookSeat()
{
    printf("\t book Seat");
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
            addBus();
        }else if(choice == 2) {
            addNewCustomer();
        }else if(choice == 3) {
            seeAvailableBus();
        }else if(choice == 4){
            bookSeat();
        }else if(choice == 5){
            printf("\t \a Thank You For Choosing Us.Have a Great Day :)\n");
            exit(0);
        }else {
            printf("\t Sorry Your Choice Is Wrong.\n");
        }
    }
    getch();
    return 0;
}
