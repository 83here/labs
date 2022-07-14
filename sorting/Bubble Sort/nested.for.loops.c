#include<stdio.h>
#include<stdlib.h>
int comp=0;
int size;

void bubblesort(int *array,int low,int high);
void swap(int*a,int*b);
void printArray(int *array,int size);

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void printArray(int *array,int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main()

{
    printf("ENTER THE SIZE OF ARRAY YOU WANT :\n");
    scanf("%d",&size);                              
    int *array=(int *)malloc(sizeof(int)*size);

    for(int i=0;i<size;i++){
        printf("ENTER THE ELEMENT %d :",i+1);
        scanf("%d",array+i);
    }

    printf("THE ARRAY GIVEN IS :\n");
    printArray(array,size);

    bubblesort(array,0,size);
    printf("THE ARRAY SORTED IS :\n");

    printArray(array,size);
    printf("THE TOTAL NUMBER OF ITERATIONS IS : %d",comp);

}

void bubblesort(int *array,int low,int high)
{
  for(int step=0;step<high;step++)
  {comp++;
    for(int i=low;i<high-1-step;i++) // a bug when "i<high" since see below the comparision already goes till high index as i+1 goes high, so high-1 is correct
    {comp++;
        if(array[i]>array[i+1])
        {
            
            printArray(array,size);

            swap(array+i,array+i+1);


        }
    }
  }
}
