#include<stdio.h>
#include<stdlib.h>

int size;
int req;

void binary(int *array,int low, int high,int req){
    int mid=(low+high)/2;

    
    if(array[mid]==req)
    {
        printf("ELEMENT IS FOUND AT INDEX :%d",mid);
    }
    else if(array[mid]>req){
        if (mid-1==low)
        printf("ELEMENTS DOESNT EXITS :");
        else
        binary(array,low,mid,req);
    } 
    else if(array[mid]<req)  
    {
        if (mid+1==high)
        printf("ELEMENTS DOESNT EXITS :");
        else
        binary(array,mid,high,req);
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