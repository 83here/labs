#include<stdio.h>
#include<stdlib.h>
int x=-1;
int* create(int size);
void enqueue(int *queue,int *front,int *rear,int size);
void printstack(int *queue, int *front, int*rear,int size);
void dequeue(int *queue,int *front,int *rear,int size);


int main()
{
int size;

printf("ENTER THE SIZE OF STACK NEEDED \n");
scanf("%d",&size);
int * queue=create(size);
int front=-1;
int *frontp=&front;
int rear=-1;
int *rearp=&rear;

while(x!=6)
    {
    printstack(queue, frontp, rearp, size);

    printf("\nENTER \n1 TO ENQUEUE\n2 TO DEQUEUE\n3 TO EXIT\n"); 

    printf("\nREAR NOW IS %d\n",*rearp);
    printf("FRONT NOW IS %d\n",*frontp);

    scanf("%d",&x);
    printf("\n");

    if (x==1)
    {
        enqueue(queue,frontp,rearp,size);
    }
    else if (x==2)
    {
        dequeue(queue,frontp,rearp,size);
    }
    else if (x==3)
    {
        free(queue);
        break;
    }
    }


}


int * create(int size)
{
 return (int*)malloc(sizeof(int)*size);
}

void enqueue(int *queue,int *front,int *rear,int size)
{
    int element;
    if(*front==-1&&*rear==-1)
    {
            *front=*front+1;
    printf("\nREAR NOW IS %d\n",*rear);
    printf("FRONT NOW IS %d\n",*front);
    }

    if((*rear+1)%size==*front&& *rear!=-1)
    {
     printf("QUEUE FULL");
    }
  
    else
    {

    *rear=*rear+1;
    *rear=(size+*rear)%(size);
    printf("\nREAR NOW IS %d\n",*rear);
    printf("FRONT NOW IS %d\n",*front);
    printf("ENTER THE ELEMENT YOU WANT TO ADD :");
    scanf("%d",&element);
    queue[*rear]=element;
    }
}

void dequeue(int *queue,int *front,int *rear,int size)
{

    if(*front+1>*rear)
    {
     printf("QUEUE EMPTY\n");
     *rear=-1;
     *front=-1;
    }

    if(*rear!=*front)
    {

    *front=*front+1;
    *front=(size+*front)%(size);
    printf("FRONT NOW IS %d\n",*front);

    }
}
