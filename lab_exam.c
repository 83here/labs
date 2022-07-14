#include<stdio.h>
#include<stdlib.h>

int queue1[10];
int queue2[10];
int flag=0;

void vip(int *queue ,int value ,int *front, int *rear);
void printstack(int *queue, int *front, int*rear,int size);
void add(int *queue,int *front, int *rear,int value);
int done(int *queue ,int *front, int *rear);
void transfer(int *queue1,int *front1,int *rear1,int *queue2,int *rear2,int *front2);
int pop(int *queue,int *front , int *rear);

int pop(int *queue,int *front , int *rear)
{
int x=queue[*rear];

 if (*rear==8)
 {
   *rear=0;
   return x;
 }
 else
 {
    *rear=*rear-1;
    return x;
 }

}

void transfer(int *queue1,int *front1,int *rear1,int *queue2,int *front2,int *rear2)
{
if(*front1>*rear1)
{
    for (int i=*front1;i<9;i++ )
    { 
        add(queue1,front1,rear1,pop(queue2,front2,rear2));
    }

    for (int i=0;i<=*rear1;i++ )
    { 
        add(queue2,front2,rear2,pop(queue1,front1,rear1));
    }

}

else
{
int len=(*rear1)-(*front1)+1;
    for(int i=0;i<(len/2);i++)
    {
        add(queue2,front2,rear2,pop(queue1,front1,rear1));
    } 
}
}

void printstack(int *queue, int *front, int*rear,int size){
    if(*rear<*front)
    {
     printf("\nQUEUE IS :\n");

        for(int i=*front;i<size;i++)
        {
         if(i!=-1)
         printf("%d ",queue[i]);
        }
        for(int i=0;i<=*rear;i++)
        {
         printf("%d",queue[i]);
        }

    }
    else
    {

     printf("\nQUEUE IS : \n");

        for(int i=*front;i<=*rear;i++)
        {
         if(i!=-1)
          printf("%d ",queue[i]);
        }
        printf("\n");
}
}



void add(int *queue,int *front, int *rear,int value)
{
    flag++;
    if (*front==-1 && *rear==-1)
    {
     *front=0;
     add(queue,front,rear,value);
     return;
    }

    if (*rear==9 && *front!=0)
    {
     *rear=0;
     queue[*rear]=value;
    }

    if(*rear==9 && *front==0)
     printf("QUEUE FULL \n");

    else
    {
     *rear=*rear+1;
     queue[*rear]=value;
    }
     
}

int done(int *queue ,int *front, int *rear)
{

    int x=queue[*front];

    if(*front==*rear)
    {
        *front=-1;
        *rear=*front;

    }

    else if(*front>*rear && *front==8)
    {
        *front=0;
    }


    else if(*front<*rear)
     {
        *front=*front+1;
     }

    return x;
}


void vip(int *queue ,int value ,int *front, int *rear)
{

if (*front==0)
{
    *front=8;
    *rear=*rear-1;
    queue[*front]=value;
}
else 
{
    if(*front-1==*rear)
     {
        --*front;
        --*rear;
        queue[*front]=value;
     }
    else
    {
     queue[--*front]=value;
    }
}

}

int main()
{

int *front1=malloc(sizeof(int));
int *front2=malloc(sizeof(int));
int *rear1=malloc(sizeof(int));
int *rear2=malloc(sizeof(int));

*front1=-1;
*front2=-1;
*rear1=-1;
*rear2=-1;



  int choice=7;
  int re=0;
  while(choice!=5)
  {
  re++;
  printf("\nENTER 1 TO ADD IN QUEUE\n2 T0 SEND OFF CUSTOMERS\n3 TO OLD PATIENT ENTRY\n4 TO TRAVERSE THE QUEUE\n5 TO EXIT\n\nCHOICE HERE:");
  scanf("%d",&choice);
  if(*front1==-1 && *front2!=-1 && re>4)
  {
    printf("TRANSFERING FROM QUEUE 2 TO 1\n");
    transfer(queue2,front2,rear2,queue1,front1,rear1);
    re=0;
  }

  if(*front2==-1 && *front1!=-1 && re>4)
  {
    printf("TRANSFERING FROM QUEUE 1 TO 2\n");
    transfer(queue1,front1,rear1,queue2,front2,rear2);
    re=0;
  }
  if(choice == 1)
  {
    int adder;
    printf("\nENTER PATIENT ID TO ADD :");
    scanf("%d",&adder);
    if(flag%2==0)
    {
     printf("\nPATIENT WITH ID ""%d"" ADDED TO Q1\n\n",adder);
     add(queue1,front1,rear1,adder);
    }
    else
    {
     printf("\nPATIENT WITH ID ""%d"" ADDED TO Q2\n\n",adder);
       add(queue2,front2,rear2,adder);
    }
}

if(choice == 2)
{
  int q;
  printf("ENTER 1 TO QUEUE 1\nENTER 2 TO QUEUE 2 :");
  scanf("%d",&q);
  if(q==1)
   printf("%d'S BILLING WAS DONE  \n",done(queue1,front1,rear1));
  if(q==2)
  {
   printf("%d'S BILLING WAS DONE \n",done(queue2,front2,rear2));
  }

}

if(choice == 3)
{
    int value;
    printf("ENTER THE VIP NAME\n");
    scanf("%d",&value);

    if(flag%2==0)
      vip(queue1,value,front1,rear1);
    if(flag%2!=0)
      vip(queue2,value,front2,rear2);

}

if(choice==4)
{
    
    int q;
    printf("\nENTER 1 FOR 1ST\nENTER 2 FOR SETTING 2\nENTER CHOICE :");
    scanf("%d",&q);
    if (q==1)
     printstack(queue1,front1,rear1, 9);
    else 
     printstack(queue2, front2, rear2, 9);

}
}
}
