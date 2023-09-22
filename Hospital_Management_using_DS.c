#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
void input();
void details();
void edit();
void bill();
void deletep();
void loginpage();
struct node
{
	char name[50],address[50],email[50],gender[10],blood_group[10],disease[100];
	int age,id,o2,pulse;
	float height,weight;
	char e_name[50],e_address[50],e_email[50],e_relation[50],e_phone_no[20],e_aadhar[20];
	int consult,report;
	float operation,medical,room_rent,other,total;
	struct node *next;
}*head=NULL,*last=NULL;
void login(int l)
{
	int m=3,i;
	char user[10]="system";
    char pass[10]="manager";
    char a[10],b[10];
	printf("\n\n\t\t\t\t\t\t\t\t\tENTER USERNAME:= ");
	scanf("%s",a);
	printf("\t\t\t\t\t\t\t\t\tENTER PASSWORD:= ");
	scanf("%s",b);
	printf("\n");
	if(strcmp(a,"system")==0 && strcmp(b,"manager")==0)
	{
	printf("                                                      WELCOME TO HOSPITAL MANAGEMENT SYSTEM !!!! LOGIN IS SUCCESSFUL\n\n");
    printf("                                                      LOADING PLEASE WAIT... \n\n");	
    printf(" ");	
    for(i=0; i<5; i++)
    {
        printf("..................................");
        Sleep(500);
    }
	printf("                                                      PRESS ANY KEY TO CONTINUE...\n");
	loginpage();
	getch();
	}
	else
	{
		l++;
		printf("                                                  SORRY !!!!  LOGIN IS UNSUCESSFUL\n");
		printf("                                                  TOTAL TRY IS %d AND YOU LEFT WITH %d\n",m,m-l);
		while(l!=3)
		{
			login(l);
		}
		if(l==3)
		{
			printf("YOUR PASSWORD IS WRONG 3 TIMES\n");
		}
		exit(0);	
	}
}
void loginpage()
{
	int i=0;
	printf("\n\n\n");
    int choice;
    do
	{
	printf("                                                       |EMPLOYEES RECORD MANAGEMENT|\n");
	printf("                                                       1> INPUT\n");
	printf("                                                       2> EDIT\n");
	printf("                                                       3> BILL\n");
	printf("                                                       4> DETAILS\n");
	printf("                                                       5> DELETE\n");
    printf("                                                       6> EXIT SYSTEM\n");
    printf("ENTER CHOICE\n");
    fflush(stdin);
    scanf("%d",&choice);
    switch(choice)
    {
    	case 1:
    		input();
    		break;
    	case 2:
    		edit();
    		break;
    	case 3:
    		bill();
    		break;
    	case 4:
    		details();
    		break;
    	case 5:
    		deletep();
    		break;
    	case 6:
    		printf("EXIT\n");
      		exit(0);
      	default:
			printf("ENTER VALID NUMBER\n");
	}
    }while(choice!=6);
}
void input()
{
  int id=1;
  printf("\n");
  struct node *ptr;
  ptr=(struct node *)malloc(sizeof(struct node));
  fflush(stdin);
  ptr->id=id;
  printf("PATIENT NUMBER:=%d\n",ptr->id);
  printf("\n");
  printf("ENTER PATIENT NAME\n");
  gets(ptr->name);
  printf("\n");
  printf("ENTER PATIENT ADDRESS\n");
  fflush(stdin);
  gets(ptr->address);
  printf("\n");
  printf("ENTER PATIENT EMAIL\n");
  gets(ptr->email);
  printf("\n");
  printf("ENTER PATIENT GENDER\n");
  gets(ptr->gender);
  printf("\n");
  printf("ENTER PATIENT BLOOD GROUP\n");
  gets(ptr->blood_group);
  printf("\n");
  printf("ENTER PATIENT DISEASE\n");
  gets(ptr->disease);
  printf("\n");
  printf("ENTER PATIENT AGE\n");
  scanf("%d",&ptr->age);
  printf("\n");
  printf("ENTER PATIENT OXYGEN LEVEL\n");
  scanf("%d",&ptr->o2);
  printf("\n");
  printf("ENTER PATIENT PULSE RATE\n");
  scanf("%d",&ptr->pulse);
  printf("\n");
  printf("ENTER PATIENT HEIGHT\n");
  scanf("%f",&ptr->height);
  printf("\n");
  printf("ENTER PATIENT WEIGHT\n");
  scanf("%f",&ptr->weight);
  printf("\n");
  fflush(stdin);
  printf("ENTER EMERGENCY PERSON NAME\n");
  gets(ptr->e_name);
  printf("\n");
  printf("ENTER EMERGENCY PERSON ADDRESS\n");
  fflush(stdin);
  gets(ptr->e_address);
  printf("\n");
  printf("ENTER EMERGENCY PERSON EMAIL\n");
  gets(ptr->e_email);
  printf("\n");
  printf("ENTER EMERGENCY PERSON RELATION\n");
  gets(ptr->e_relation);
  printf("\n");
  printf("ENTER EMERGENCY PERSON PHONE NUMBER\n");
  gets(ptr->e_phone_no);
  printf("\n");
  printf("ENTER EMERGENCY PERSON AADHAR NUMBER\n");
  gets(ptr->e_aadhar);
  printf("\n");
  printf("ENTER CONSULT\n");
  scanf("%d",&ptr->consult);
  printf("\n");
  printf("ENTER REPORT\n");
  scanf("%d",&ptr->report);
  printf("\n");
  id++;
  if(head==NULL)
  {
  	head=ptr;
  	return;
  }
  ptr->next=head;
  head=ptr;
}
void bill()
{
  int n1,flag9=0;
  printf("ENTER PATIENT NUMBER\n");
  scanf("%d",&n1);
  struct node *ptr;
  ptr=head;
  while(ptr!=NULL){
  		if(ptr->id==n1)
		{
		flag9=1;
		break;
	    }
		ptr=ptr->next;
	}
  if(flag9==1)
  {
  printf("ENTER OPERATION FEES\n");
  scanf("%f",&ptr->operation);
  printf("\n");
  printf("ENTER MEDICAL FEES\n");
  scanf("%f",&ptr->medical);
  printf("\n");
  printf("ENTER ROOM RENT\n");
  scanf("%f",&ptr->room_rent);
  printf("\n");
  printf("ENTER OTHER FEES\n");
  scanf("%f",&ptr->other);
  printf("\n");
  ptr->total=ptr->operation+ptr->medical+ptr->room_rent+ptr->other;
  printf("TOTAL AMOUNT:=%.0f",ptr->total);
  }
  else
  {
    printf("PATIENT IS NOT FOUND IN L.J HOSPITAL\n");
  }
}
void details()
{
	int n2,flag=0;
	printf("ENTER PATIENT NUMBER\n");
	scanf("%d",&n2);
	struct node *p1;
	p1=head;
	while(p1!=NULL){
		if(p1->id==n2)
		{
		flag=1;
		break;
	    }
		p1=p1->next;
	}
	if(flag==1)
	{	
	fflush(stdin);
	printf("PATIENT NUMBER::%d\n",p1->id);
	    printf("\n");
	printf("PATIENT NAME::%s\n",p1->name);
		printf("\n");
  	printf("PATIENT ADDRESS::%s\n",p1->address);
  		printf("\n");
    printf("PATIENT EMAIL::%s\n",p1->email);
    	printf("\n");
    printf("PATIENT GENDER::%s\n",p1->gender);
    	printf("\n");
    printf("PATIENT BLOOD GROUP::%s\n",p1->blood_group);
    	printf("\n");
    printf("PATIENT DISEASE::%s\n",p1->disease);
    	printf("\n");
    printf("PATIENT AGE::%d\n",p1->age);
    	printf("\n");
    printf("PATIENT OXYGEN LEVEL::%d\n",p1->o2);
    	printf("\n");
    printf("PATIENT PULSE RATE::%d\n",p1->pulse);
    	printf("\n");
    printf("PATIENT HEIGHT::%f\n",p1->height);
    	printf("\n");
    printf("PATIENT WEIGHT::%f\n",p1->weight);
    	printf("\n");
    printf("EMERGENCY PERSON NAME::%s\n",p1->e_name);
    	printf("\n");
  	printf("EMERGENCY PERSON ADDRESS::%s\n",p1->e_address);
  		printf("\n");
    printf("EMERGENCY PERSON EMAIL::%s\n",p1->e_email);
    	printf("\n");
    printf("EMERGENCY PERSON RELATION::%s\n",p1->e_relation);
    	printf("\n");
    fflush(stdin);
    printf("EMERGENCY PERSON PHONE NUMBER::%s\n",p1->e_phone_no);
    	printf("\n");
    printf("EMERGENCY PERSON AADHAR NUMBER::%s\n",p1->e_aadhar);
    	printf("\n");
    }
    else
    printf("PATIENT IS NOT FOUND IN L.J HOSPITAL\n");
}
void edit()
{
  int n3,flag2=0;
  printf("ENTER PATIENT NUMBER\n");
  scanf("%d",&n3);
  struct node *ptr3;
  ptr3=head;
  while(ptr3!=NULL){
  		if(ptr3->id==n3)
		{
		flag2=1;
		break;
	    }
		ptr3=ptr3->next;
	}
   if(flag2==1)
   {
  fflush(stdin);
  printf("PATIENT NUMBER:=%d\n",ptr3->id);
  printf("\n");
  printf("ENTER PATIENT NAME\n");
  gets(ptr3->name);
  printf("\n");
  printf("ENTER PATIENT ADDRESS\n");
  fflush(stdin);
  gets(ptr3->address);
  printf("\n");
  printf("ENTER PATIENT EMAIL\n");
  gets(ptr3->email);
  printf("\n");
  printf("ENTER PATIENT GENDER\n");
  gets(ptr3->gender);
  printf("\n");
  printf("ENTER PATIENT BLOOD GROUP\n");
  gets(ptr3->blood_group);
  printf("\n");
  printf("ENTER PATIENT DISEASE\n");
  gets(ptr3->disease);
  printf("\n");
  printf("ENTER PATIENT AGE\n");
  scanf("%d",&ptr3->age);
  printf("\n");
  printf("ENTER PATIENT OXYGEN LEVEL\n");
  scanf("%d",&ptr3->o2);
  printf("\n");
  printf("ENTER PATIENT PULSE RATE\n");
  scanf("%d",&ptr3->pulse);
  printf("\n");
  printf("ENTER PATIENT HEIGHT\n");
  scanf("%f",&ptr3->height);
  printf("\n");
  printf("ENTER PATIENT WEIGHT\n");
  scanf("%f",&ptr3->weight);
  printf("\n");
  fflush(stdin);
  printf("ENTER EMERGENCY PERSON NAME\n");
  gets(ptr3->e_name);
  printf("\n");
  printf("ENTER EMERGENCY PERSON ADDRESS\n");
  gets(ptr3->e_address);
  printf("\n");
  printf("ENTER EMERGENCY PERSON EMAIL\n");
  gets(ptr3->e_email);
  printf("\n");
  printf("ENTER EMERGENCY PERSON RELATION\n");
  gets(ptr3->e_relation);
  printf("\n");
  printf("ENTER EMERGENCY PERSON PHONE NUMBER\n");
  gets(ptr3->e_phone_no);
  printf("\n");
  printf("ENTER EMERGENCY PERSON AADHAR NUMBER\n");
  gets(ptr3->e_aadhar);
  printf("\n");
  printf("ENTER CONSULT\n");
  scanf("%d",&ptr3->consult);
  printf("\n");
  printf("ENTER REPORT\n");
  scanf("%d",&ptr3->report);
  printf("\n");
   }
  else
  {
    printf("PATIENT IS NOT FOUND IN L.J HOSPITAL\n");
  }
}
void deletep()
{
	struct node *p;
	int data;
	printf("ENTER PATIENT NUMBER\n");
	scanf("%d",&data);
	if(head==NULL)
	{
    printf("PATIENT IS NOT FOUND IN L.J HOSPITAL\n");
		return;
	}
	if(data==head->id)
	{
		p=head;
		head=head->next;
		free(p);
		printf("PROCESS IS DONE\n");
		return;
	}
	struct node *last;
	last=head;
	while(data!=last->next->id && last->next->next!=NULL)
	{
		last=last->next;
	}
	if(data==last->next->id && last->next->next!=NULL)
	{
		p=last->next;
		last->next=NULL;
		free(p);
		printf("PROCESS IS DONE\n");
		return;
	}
		if(data==last->next->id && last->next!=NULL)
	{
		p=last->next;
		last->next=last->next->next;
		free(p);
		printf("PROCESS IS DONE\n");
		return;
	}
    printf("PATIENT IS NOT FOUND IN L.J HOSPITAL\n");
}
void main()
{
	int l=0;
	login(0);
}
