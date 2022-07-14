#include<stdio.h>
#include<stdlib.h>

int x=-1;
int pusher;


int *createstack (int size);
void pop(int *stack,int *topp);
void push(int *stack,int *topp,int size);
int isfull(int *topp,int size);
int isempty(int *topp);
void peek(int *stack,int *topp);



int main()

{

    int size;
    printf("ENTER THE SIZE OF STACK YOU WANT: ");
    scanf("%d",&size);   
    printf("\n");

    int *stack=createstack(size);
    printf("\n");
    int top=size-1;
    int *topp=&top;  


    while(x!=6)
    {
    printf("ENTER \n1 TO CHECK IF FULL\n2 TO CHECK IF EMPTY\n3 TO POP\n4 TO PUSH\n5 TO PEEK\n6 TO EXIT"); 
    printf("\n");
    scanf("%d",&x); //IF THIS IS NOT THERE THEN YOU ARE GONE CASE ONLY, YOU WONT KNOW WHATS GOING ON SINCE NOTHING WILL HAPPEN 


        if(x==1)
        {
            if(isfull(topp,size)==1)
            {
                printf("STACK IS FULL \n");
            }
            else
            {
                printf("STACK IS NOT FULL \n");
            }
        }

        if(x==2)
        {
            if(isempty(topp)==1)
            {
                printf("STACK IS EMPTY \n");
            }
            else
            {
                printf("STACK IS NOT EMPTY \n");
            }
        }

        if(x==3)
        {
            pop(stack,topp);
        }

        if(x==4)
        {
            push(stack,topp,size);
        }

        if(x==5)
        {
            peek(stack,topp);
        }

        if(x==6){
            printf("EXITTING");
            break;
        }


    }
    

}

int *createstack (int size)
{

    int *stack=(int *)malloc(size*sizeof(int));


    for(int i=0;i<size;i++)
    {
        printf("ENTER THE ELEMENT %d :",i+1);
        scanf("%d",&stack[i]);
    }
        printf("\n");

    return stack;
}

void pop(int *stack,int *topp)
{
    if (isempty(topp)==1)
    {
        printf("STACK UNDERFLOW \n");
    }

    else
    {
    printf("ELEMENT %d WAS POPPED \n",stack[*topp]);
    *topp=*topp-1;
    }
}

void push(int *stack,int *topp,int size)
{

    if (isfull(topp,size)==1)
    {
        printf("STACK OVERFLOW \n");
    }

    else
    {
    printf("ENTER THE ELEMENT TO BE ADDED \n");
    scanf("%d",&pusher);
    *topp=*topp+1;
    stack[*topp]=pusher;
    printf("ELEMENT %d WAS PUSHED AT INDEX %d \n",pusher,*topp);
    }

}

void peek(int *stack,int *topp)
{
    if (isempty(topp)==1)
    {
        printf("STACK EMPTY \n");
    }

    else
    {
    printf("THE TOPMOST ELEMENT IS %d \n",stack[*topp]) ;
    }
}

int isfull(int *topp,int size)
{
    if (*topp==size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isempty(int *topp)
{
    if (*topp==-1){
        return 1;
    }
    else{
        return 0;
    }
}