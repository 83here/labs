//not fully working


#include<stdio.h>
#include<stdlib.h>

int size;
int req;

void binary(int *array,int low, int high,int req){
    int mid=(low+high)/2;

    while(mid!=high || mid!=low){
    
    if(array[mid]==req)
    {
        printf("ELEMENT IS FOUND AT INDEX :%d",mid);
        break;
    }
    else if(array[mid]>req){
                   mid--;
                   printf("minus");
    } 
    else
    {
     mid++;
    }    
    }
    
    if((mid==high || mid==low)&&array[mid]!=req)
    {
     printf("ELEMENT NOT FOUND");
    }
}

int main()
{

    printf("ENTER THE SIZE OF ARRAY YOU WANT :\n");
    scanf("%d",&size);                              //GLOBAL VARIABLE
    int *array=(int *)malloc(sizeof(int)*size);

    for(int i=0;i<size;i++){
        printf("ENTER THE ELEMENT %d :",i+1);
        scanf("%d",array+i);
    }

    for (int i = 0; i < size; ++i) 
    {
    printf("%d  ", array[i]);
    }

    printf("\nENTER THE NUMBER TO SEARCH :");
    scanf("%d",&req);
    binary(array,0,size-1,req);

}