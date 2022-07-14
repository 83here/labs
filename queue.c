#include<stdio.h>
#include<stdlib.h>

int x;
int size;

void printstack(int *queue, int *front, int*rear);
int *createqueue(int size);
void enqueue(int *queue,int *front,int *rear);
void dequeue(int *queue,int *front,int *rear);


int main()
{

printf("ENTER THE SIZE OF STACK : ");
scanf("%d",&size);
int *queue=createqueue(size);
printf("\n");
int front=-1;
int rear=-1;
int *frontp=&front;  
int *rearp=&rear;  

while(x!=6)
    {
    printf("\nREAR NOW IS %d\n",*rearp);
    printf("FRONT NOW IS %d\n",*frontp);
    printstack(queue, frontp, rearp);

    printf("\nENTER \n1 TO ENQUEUE\n2 TO DEQUEUE\n3 TO EXIT\n"); 
    scanf("%d",&x);

    printf("\n");

    if (x==1)
    {
        enqueue(queue,frontp,rearp);
    }
    else if (x==2)
    {
        dequeue(queue,frontp,rearp);
    }
    else if (x==3)
    {
        free(queue);
        break;
    }
    }
}

int *createqueue(int size)
{
    int *x=(int*)malloc(size*sizeof(int));
    return x;
}

void enqueue(int *queue,int *frontp,int *rearp)
{
    if(*rearp==size-1)
    {
        printf("CANT ADD QUEUE FULL \n");
    }

    else
    {
        if(*frontp==-1)
         *frontp=*frontp+1;

        *rearp=*rearp+1;
        int element;
        printf("ENTER THE ELEMENT TO BE ADDED :");
        scanf("%d",&element);
        queue[*rearp]=element;
        printf("ELEMENT %d WAS ADDED AT REAR %d ", queue[*rearp],*rearp);

    }
}

void dequeue(int *queue,int *frontp,int *rearp)
{

    if(*rearp==*frontp)
    {
        *rearp=-1;
        *frontp=-1;
        printf("QUEUE RESET");
    }
    else
    {
    *frontp=*frontp+1;
    }

}

void printstack(int *queue, int *front, int*rear)
{
printf("\nQUEUE IS :");
for(int i=*front;i<=*rear;i++)
{
    if(i!=-1)
     printf("%d",queue[i]);
}
printf("\n");
}