#include<stdio.h>
#include<stdlib.h>
int i=0;

int polish(char *stack,char *array,int size, int *topp);
char *createstack (int size);
char pop(char *stack,int *topp);
void push(char *stack,int pusher, int *topp,int size);
int isfull(int *topp,int size);
int isempty(int *topp);
char peek(char *stack,int *topp);
int prec(char x);



int main()
{
	char array[] = "a+b*(c^d-e)^(f+g*h)-i"; 
    printf("THE INPUT EXPRESSION IS :%s\n",array);
    int size=sizeof(array)-1;
    printf("THE SIZE OF THE ARRAY IS :%d\n",size);

    char *stack=createstack(size);
    printf("\n");
    printf("THE POSTFIX EXPRESSION IS :");

    int top=-1;
    int *topp=&top;  

    polish(stack,array,size,topp);
}


int polish(char *stack,char *array,int size, int *topp)
{
    while(array[i]!='\0')
    {
    if (prec(peek(stack,topp))>=prec(*(array+i)))
        {
            if(array[i]=='(')
                {
                    push(stack,*(array+i),topp,size);
                    i++; 
                }
            else
            {
                while(prec(peek(stack,topp))>=prec(*(array+i)))
                {
                    if(peek(stack,topp)=='(')
                    {
                        pop(stack,topp);
                        i++; 
                        break;
                    }
                    printf("%c",peek(stack,topp));
                    pop(stack,topp);
                    break;    
                 }
            }       
        }
        else
        {
            if (prec(*(array+i))>=4)
            {
                printf("%c",*(array+i));
                i++; 
            }
            else
            {
                push(stack,*(array+i),topp,size);
                i++; 
            } 
         
        }
    }
    {
        while(isempty(topp)==0)
        {
            printf("%c",pop(stack,topp));
            i++;
        }
    }
printf("\n\nDONE \n");
return 0;
}

int prec(char x){
    if(x==')' || x=='(')
    {
        return 0;
    }
    
    else if(x=='1'){
        return -1;
    }

    else if(x=='+' || x=='-'){
        return 1;
    }

    else if(x=='/' || x=='*'){
        return 2;
    } 

    else if(x=='^'){
        return 3;
    }

    else
    {
        return 5;
    }

}

char *createstack (int size)
{

    char *stack=(char *)malloc(size*sizeof(char));
    return stack;
}

char pop(char *stack,int *topp)
{
    if (isempty(topp)==1)
    {
        return '1';
    }

    else
    {
       char r=stack[*topp];
       *topp=*topp-1;


       return r;

    }
}

void push(char *stack,int pusher,int *topp,int size)
{

    if (isfull(topp,size)==1)
    {
        printf("STACK OVERFLOW \n");
    }

    else
    {
    *topp+=1;
    stack[*topp]=pusher;
    }

}

char peek(char *stack,int *topp)
{
    if (isempty(topp)==1)
    {
        return '1';
    }

    else
    {
       return stack[*topp] ;
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
    if (*topp==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}