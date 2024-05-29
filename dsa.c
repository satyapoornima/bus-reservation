#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
struct Seat
{
	int seat_number;
  	int age;
  	char gender[20];
  	char name[50];
  	long long phone_no;
  	char board[50];
  	char dest[50];
  	char tim[50];
  	int cost;
  	int is_booked;
  	struct Seat *next;
};
struct Seat *head = NULL;

void add_seat (int seat_number)
{
	struct Seat *new_seat = (struct Seat *) malloc (sizeof (struct Seat));
  	new_seat->seat_number = seat_number;
  	new_seat->is_booked = 0;
  	new_seat->next=NULL;
  	if(head==NULL)
  	{
  		head=new_seat;
    }
  	else
  	{
  		struct Seat *temp=head;
  		while(temp->next!=NULL)
  			temp=temp->next;
  		temp->next=new_seat;
	}
}

int payment(int rate);
int capch();
void book_seat (int seat_number)
{
	struct Seat *current = head;
	while (current != NULL)
    {
    	if (current->seat_number == seat_number && current->is_booked == 0)
		{ 
			int ch;
	  		struct Seat *new_seat = current;
	  		current->is_booked = 1;
	  		printf ("enter the name :");
	  		scanf ("%s", new_seat->name);
	  		printf ("enter age :");
	  		scanf ("%d", &new_seat->age);
	  		printf ("enter gender :");
	  		scanf ("%s", new_seat->gender);
	  		printf ("enter phone :");
	  		scanf ("%lld", &new_seat->phone_no);
	      	printf("\n[1] banglore to tumukur\n[2] banglore to hiriyur\n[3] banglore to chitradurga\n[4] banglore to ballary\n");
	      	printf("enter your choice:");
	      	scanf("%d",&ch);
	      	switch(ch)
	      	{
	        	case 1:strcpy(new_seat->board,"banglore");
	                 strcpy(new_seat->dest,"tumkur");
	                 new_seat->cost=200;
	                 strcpy(new_seat->tim,"10am to 12 pm");
	                 break;
	        	case 2:strcpy(new_seat->board,"banglore");
	                 strcpy(new_seat->dest,"hiriyur");
	                 new_seat->cost=300;
	                 strcpy(new_seat->tim,"10am to 1 pm");
	                 break;
	        	case 3:strcpy(new_seat->board,"banglore");
	                 strcpy(new_seat->dest,"chitradurga");
	                 new_seat->cost=400;
	                 strcpy(new_seat->tim,"10am to 2 pm");
	                 break;
	        	case 4:strcpy(new_seat->board,"banglore");
	                 strcpy(new_seat->dest,"ballary");
	                new_seat->cost=600;
	                 strcpy(new_seat->tim,"10am to 4 pm");
	                 break;
	        	default:printf("service not available!!");
	        			return;
	    	}
	    	if(payment(new_seat->cost))
	    		printf ("Seat no %d has been successfully booked!\n", seat_number);
			else
			{
				printf("seat no  %d has not been booked\n",seat_number);
				new_seat->is_booked=0;
			}
			return;
		}
    	current = current->next;
    }
	printf ("\nSorry, Seat %d is not available for booking.\n", seat_number);
}

int payment(int Rate)
{
	int choice,MM,YY,CVV;
    char ch,bank_name[20];
    long  int UPI,link_no,user_ID,password,card_no;
    printf("\nENTER\n[1]:UPI\n[2]:Credit/ATM/Debit card\n[3]:Net banking\n[4]: exit\n");  
    scanf("%d",&choice);
    switch(choice)
    {
       case 1:printf("ENTER:\n[A]:Phonepay\n[B]:Gpay\n[C]:Paytm\n");
              getchar();
              scanf("%c",&ch);
              switch(ch)
              {
            	  case 'A':
                  case 'a':printf("ENTER UPI PIN :");
                           scanf("%ld",&UPI);
                           break;       
                  case 'B':
                  case 'b':printf("ENTER UPI PIN :");
                           scanf("%ld",&UPI);
                           break;
                  case 'C':
                  case 'c':printf("ENTER UPI PIN :");
                           scanf("%ld",&UPI);
                           break;
              } 
              if(capch())
              {
            	printf("\npayment successful\n");
              	return(1);
			  }
			  else
			  {
			    printf("\npayment not successful\n");
				return(0);
			  }
              printf("\n");
              break;
       case 2:printf("Enter Card number :");
              scanf("%ld",&card_no);
              printf("enter\n");
              printf("MM :");
              scanf("%d",&MM);
              printf("YY :");
              scanf("%d",&YY);
              printf("CVV :");
              scanf("%d",&CVV);
              if(capch())
              {
              	printf("\npayment successful\n");
              	return(1);
			  }
			  else
			  {
			  	printf("\npayment not successful\n");
			  	return(0);
			  }
              printf("\n");
              break;
               
       case 3:printf("Enter your Bank name :");
              scanf("%s",bank_name);
              printf("Enter your Bank User ID :");
              scanf("%ld",&user_ID);
              printf("Enter password :");
              scanf("%ld",&password);
              if(capch())
              {
              	printf("\npayment successful\n");
              	return(1);
			  }
			  else
			  {
			  	printf("\npayment not successful\n");
              	return(0);
          	  }
			  printf("\n");
              break;
       case 4:printf("\nthis mode of payment is not available\n ");
       			break;
   }
   return(0);
}

int capch()
{
	int i=0;
    int Id,Captcha;
    srand(time(NULL));
    Id=rand()%40001+1000;
	printf("CAPTCHA\n%d\n",Id);
    printf("Enter the Captcha\n");
    scanf("%d",&Captcha);
    while(i<2)
    {	  
        if(Id==Captcha)
        {
            return(1);
            break;
        }
        else
        {
            printf("Incorrect Captcha..please try Again\n");
            scanf("%d",&Captcha);
        }
        i++;
    }
    return(0);
}

void view_available_seats ()
{
	struct Seat *current = head;
	printf ("\nThe following seats are available: ");
	while (current != NULL)
    {
    	if (current->is_booked == 0)
		{
			printf ("%d ", current->seat_number);
		}
    	current = current->next;
    }
	printf ("\n");
}

void cancel_booking (int seat_number)
{
	struct Seat *current = head;
	while (current != NULL)
    {
    	if (current->seat_number == seat_number && current->is_booked == 1)
		{
			current->is_booked = 0;
			printf ("\nBooking for Seat %d has been successfully cancelled!\n", seat_number);
			printf("refund is not available \n");
			return;
		}
    	current = current->next;
    }
  	printf ("\nNo booking was found for Seat %d.\n", seat_number);
}

void display_seats (int n)
{
	struct Seat *current = head;
	int i,j,k,l=0;
	printf("\n------------------------------------------------------------\n");
	printf("\t**KSP TRAVELS*");
    printf("\n__\n");
	printf("Seat Number(Booking Status)\n");
    for (i =0; i<n;i= i+4)
	{
		for (j=0;j<4;j=j+2)
	    {
	    	for (k=0;k<2;k++)
			{
				if(current->seat_number>9)
		  			printf("  %d(%d)",current->seat_number,current->is_booked);
		  		else
		  			printf("  0%d(%d)",current->seat_number,current->is_booked);
		  		current=current->next;
			}
	    	printf("\t\t");
	    }
		printf("\n");
	}
	printf("\n------------------------------------------------------------\n");
}

void display_details (int seat_number)
{
	struct Seat *current = head;
	while (current != NULL)
    {
    	if (current->seat_number == seat_number && current->is_booked == 1)
		{
			printf("\n**");
			printf("\n~KSP TRAVELS");
			printf("\n--------------------------------------\n");
			printf("name:%s\n", current->name);
			printf("age:%d\n", current->age);
	  		printf("gender:%s\n", current->gender);
	  		printf("phone :%lld\n", current->phone_no);
	  		printf("seat number:%d\n",current->seat_number);
	  		printf("bording point:%s\n",current->board);
	  		printf("destination:%s\n",current->dest);
	  		printf("time:%s\n",current->tim);
	  		printf("cost:%d\n",current->cost);
	  		printf("payment :successful");
	  		printf("\n--------------------------------------");
	  		printf("\n**\n");
	  		return;
		}
      	current = current->next;
    }
  	printf ("\n seat not booked !!!!!!\n");
}


int main()
{
	int choice, seat_number, n;
	while (1)
    {
    	printf("\n\n~~");
    	printf ("\nBus Reservation System\n");
      	printf ("[1] Add Seat\n");
      	printf ("[2] Book Seat\n");
      	printf ("[3] View Available Seats\n");
      	printf ("[4] Cancel Booking\n");
      	printf ("[5] Display Seats\n");
      	printf ("[6] display details\n");
      	printf ("Enter your choice: ");
      	scanf ("%d", &choice);
      	switch (choice)
		{
			case 1:
	 				printf ("Enter number of seats : ");
	  				scanf ("%d", &n);
	  				for (seat_number = 1; seat_number <= n; seat_number++)
	    			add_seat (seat_number);
	  				break;
			case 2:
	  				printf ("enter the seat no to be booked :");
	  				scanf ("%d", &seat_number);
	 				book_seat (seat_number);
	  				break;
			case 3:
	  				view_available_seats ();
	  				break;
			case 4:
	  				printf ("enter the seat no to be cancelled :");
	  				scanf ("%d", &seat_number);
	  				cancel_booking (seat_number);
	  				break;
			case 5:
			        display_seats(n);
	  				break;
			case 6:
	  				printf ("enter the seat no :");
	 				scanf ("%d", &seat_number);
	  				display_details (seat_number);
	  				break;
			default: exit (0);
		}
    }
    return(0);
}