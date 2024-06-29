#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "rail.h"
#include <conio.h>

int main()
{
    int choice,ticket_no,result;
    char *pmob_no,*ptrain_no;
    int *pticket_no;
    Passenger *ptr;
    add_trains();
    while(1)
    {
        choice = enterchoice();
        if(choice==9)
        {
            return 0;
        }
        switch(choice)
        {
            case 1:
            {
                view_trains();
                getch();
                clrscr();
                break;
            }
            case 2:
            {
                ptr=get_passenger_details();
                if(ptr!=NULL)
                {
                    ticket_no=book_ticket(*ptr);
                    if(ticket_no==-1)
                    {
                        textcolor(LIGHTRED);
                        printf("Booking Failed!");
                    }
                    else
                    {
                        textcolor(LIGHTGREEN);
                        printf("\nTicket successfully booked\nYour ticket no is %d",ticket_no);
                    }
                    textcolor(WHITE);
                    printf("\nPress any key to go back to the main screen:");
                    getch();
                    clrscr();
                }
                break;
            }
            case 3:
            {
                clrscr();
                ticket_no=accept_ticket_no();
                if(ticket_no!=0)
                {
                    view_ticket(ticket_no);
                }
                textcolor(WHITE);
                if(ticket_no!=0)
                {

                    printf("\nPress any key to go back to Main Screen:");
                    getch();
                }
                clrscr();
                break;
            }
            case 4:
            {
                clrscr();
                pmob_no=accept_mob_no();
                if(pmob_no!=NULL)
                {
                    pticket_no=get_ticket_no(pmob_no);
                    view_all_tickets(pmob_no,pticket_no);
                }
                break;
            }
            case 5:
            {
                view_all_bookings();
                break;
            }
            case 6:
            {
                clrscr();
                ptrain_no=accept_train_no();
                if(ptrain_no!=NULL)
                {
                    view_booking(ptrain_no);
                }
                break;
            }
            case 7:
            {
                clrscr();
                ticket_no=accept_ticket_no();
                if(ticket_no!=0)
                {
                    result=cancel_ticket(ticket_no);
                    if(result==0)
                    {
                        textcolor(LIGHTRED);
                        printf("Sorry! No ticket booked against ticket no %d",ticket_no);
                    }
                    else if(result==1)
                    {
                        textcolor(LIGHTGREEN);
                        printf("Ticket no %d successfully cancelled!",ticket_no);
                    }
                    else if(result==2)
                    {
                        textcolor(LIGHTRED);
                        printf("Sorry! Error in cancellation. Try again!");
                    }
                    textcolor(WHITE);
                    printf("\n\nPress any key to go back to Main Screen:");
                    getch();
                    clrscr();
                }
                break;
            }
            case 8:
            {
                clrscr();
                ptrain_no=accept_train_no();
                if(ptrain_no!=NULL)
                {
                    result=cancel_train(ptrain_no);
                    if(result==0)
                    {
                        textcolor(LIGHTRED);
                        printf("Sorry! No tickets booked in train no %s",ptrain_no);
                    }
                    else if(result==1)
                    {
                        textcolor(LIGHTGREEN);
                        printf("Train no %s successfully cancelled!",ptrain_no);
                    }
                    else if(result==2)
                    {
                        textcolor(LIGHTRED);
                        printf("Sorry! Error in cancellation. Try again!");
                    }
                    textcolor(WHITE);
                    printf("\n\nPress any key to go back to Main Screen:");
                    getch();
                    clrscr();
                }
                break;
            }
            default:
            {
                textcolor(LIGHTRED);
                printf("Wrong Choice! Press enter to try again:");
                getch();
                clrscr();
            }
        }
    }
    return 0;
}
