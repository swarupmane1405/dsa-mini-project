// Railway reservation using linked lists and Queues.

// If the reservation is full, prompt reservation full!! Put them in waiting list (queue) and give a waiting list number.
// If a passenger wishes to cancel his ticket, he may cancel. Then the passenger in waiting list is booked automatically.
// Display all the contents of reserved passengers.


#include<stdio.h>
#include<stdlib.h>
#define size 3    //size of passangers


typedef struct NODE   //node defined
{
	int reg_no;
	int age;
	char name[20];
	struct NODE *next;
} node;           //object node created

node* deq();     
int create();
int reserve(node*);
int cancel(int);
void enq(node*);
void display();



node *start;
node *front;
node *rear;
int count=0;
int num=0;
//go to main fun

int create( )       //copy from reserve
{
	node *new;
	new=(node *)malloc(sizeof(node));
	new->reg_no=1;
	printf("Name: ");
	scanf("%s", new->name);
	printf("Age : ");
	scanf("%d", &new->age);
    if(new->age>=90 || new->age<=10) {
        free(new);
        return -1;
    }
	start=new;
	new->next=NULL;
	num++;
    return 1;
	
}
//go to enq

int reserve(node *start)     //reserve seat function
{
	int temp;
	if(start==NULL)          //when linked list empty
	{   
   		temp = create(start);
		 return temp;
	}
	else            
	{
	
	node *temp, *new_node;         
	temp=start;
	while(temp->next!=NULL)        //finding last node
	{ 
	  temp=temp->next;
	}
	
	new_node=(node *)malloc(sizeof(node));  //creating new node using malloc
	
	printf("Name: ");                 //taking inputs 
	scanf("%s", new_node->name);
	printf("Age : ");
	scanf("%d", &new_node->age);
    if(new_node->age >=90 || new_node->age<=10) {
        return -1;
    }
	new_node->next=NULL;
	if(num<=size)           //checking size
	{
		num++;
		new_node->reg_no=num;
		temp->next=new_node;
		
		return 1;
	}
	else                   //waiting list queue
	{
		enq(new_node);
		return 0;
	}
}
}

//go to create
//go to enq (at end)


int cancel(int reg)
{
	node *ptr, *preptr, *new;   //taking ptr, and preptr
	ptr=start;      
	preptr=NULL;
	if(start==NULL)     //altrady empty that position
	return -1;
	if(ptr->next==NULL && ptr->reg_no==reg)  //deleting single node
		{
		start=NULL;
		num--;
		free(ptr);
		return 1;
		
		}
		
	else{	
	while(ptr->reg_no!=reg && ptr->next!=NULL) //deleting middle random
		{
			preptr=ptr;
			ptr=ptr->next;   //simply incremanting until node
		}
		if(ptr==NULL && ptr->reg_no!=reg)
			return -1;                     //node not found
		else
			preptr->next=ptr->next;
		free(ptr);
		new=deq(); 
		new->reg_no=reg;  
		while(preptr->next!=NULL)   //going to last node and adding
			preptr=preptr->next;
		preptr->next=new;
		num--;               //adding last node
		return 1;
	
	}
}
//go to display
void enq(node *new_node)
{
	if(rear==NULL)    //inserting inqueue
	{
		rear=new_node;
		rear->next=NULL;
		front=rear;
	}
	else       //creating node and inserting
	{
		node *temp;
		temp=new_node;
		rear->next=temp;
		temp->next=NULL;
		rear=temp;
	}
	count++;
}

node* deq()
{
	node *front1;
	front1=front;
	if(front==NULL)    //empty queue
		return NULL;
	else
	{
	    count-- ;
		if(front->next!=NULL)  //deleting first element from queue
		{
			front=front->next;
			front1->next=NULL;
			return front1;
		}
		else      //single node delete
		{
			front=NULL;
			rear=NULL;
			
			return front1;
		}
	}	
}


void display()
{
	node *temp;
	temp=start;
	while(temp!=NULL)       //simplay print the info untill none
	{
		printf("\nRegistration Number: %d\n", temp->reg_no);
		printf("Name : %s\n\n", temp->name);
		temp=temp->next;
    }
    
}

int main()
{
	int choice, status=0,canc=0, reg=0;
	start=NULL;
	rear=NULL;
	front=NULL;
	
	  printf("\t\t\t\t Rajarambappu Institute  Of Technology, Rajaramnagar \n\n");
    printf("\t\t\t\t\t Data Structure Laboratory \n\n");
    //code

    printf(" \t\tMini Project\n\n\t\t Title : Railway Reservation \n\n\t\t Group Members : \n 1. Akshata Savadikar \t\tPRN2010037\n 2. Swaroop Mane \t\tPRN2010015\n 3. Aman Shikalgar \t\tPRN2010003\n 4. Chinmay Pawar \t\tPRN2010005\n 5. Vishwajit Mangrule \t\tPRN2010005");
	
	printf("\n\n\t\t\t**RAILWAY RESERVATION **\t\t\t\t\n");
	
	int ch =0;
	while(ch!=4)
	{
	printf("\n\nDo you want to - \n 1. Book a ticket \n 2. Cancel Booking \n 3. Display passenger details \n 4. exit\n\n");
	scanf("%d", &choice); 
	switch(choice)
	{	
		case 1 :  status=reserve(start);
	              if(status==0)
	                printf("\nBooking Full!! \nYou are added to waiting list. Waiting list number %d", count);
	              else if(status == -1) {
                      printf("\n age not eligible");
                  }
                  else
	                printf(" \nBooking Successful!!! Enjoy your journey! Your Reg No is %d\n\n", num);
	                
	              break;
	        
	    case 2:   printf(" \n Give the Registration number to be cancelled\n");
	              scanf(" %d", &reg);
	              if(reg>num)
	              printf("Invalid!!");
	              else
	              {
	              canc=cancel(reg);
	              if(canc==-1)
	              	printf("\nRegistration number invalid!!\n");
	              else
	              	printf("\nRegistration cancelled successfully\n");
	              	}
	              break;
	              
	    case 3: display();
	    break;
	    case 4: exit(0);   
	    break;
	    default: printf("\nWrong choice!\n");       
	              
	                 
		          
	
	}
	
}

}