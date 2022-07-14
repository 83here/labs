/*
DOCUMENTATION
IF YOU WANT TO KNOW HOW CODE WORKS REMOVE THE COMMENTS AND RUN
*/


#include<stdio.h>
#include<stdlib.h>

int size;
int partition(int *array,int low,int high);
void swap(int *a,int *b);
void quicksort(int *array,int start, int end);
void printArray(int *array,int size) ;


void printArray(int *array,int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

void swap(int *a,int *b)

{
    int t=*a;
    *a=*b;
    *b=t;
    
}

int partition(int *array,int low,int high)
{

 int pointer=low;//SETTING A COMPARISION POINTER WITH 1ST ELEMENT OF ARRAY
 int pivot=low;//SETTING THE 1ST ELEMENT OF THE ARRAY AS PIVOT

 for(int i=low;i<=high;i++)//STARTS FROM LOWEST INDEX AND PASSED AND GOES TILL THE END OF THE SUB ARRAY
 {

  //printArray(array,size);
  //SWAPS ALL THE LOWER ELEMENTS WITH THE POINTER AND SMALL ELEMENT DETECTED 
  //THE IDEA IS THAT THE POINTER WILL MOVE ALONG i IF SMALLER ELEMENT IS DETECTED AND WONT IF LARGER IS DETECTED WHEN THE NEXT SMALLER ELEMENT IS DETECTED THE POINTER IS INCREMENTED BY 1 AND SWAPPED AS THE POINTER IS LEFT BEHIND ONLY IN THE CASE OF WHEN LARGER ELEMENT WAS DETECTED AND THE NEXT ELEMENT WILL BE LARGER ELEMENT
  if(array[i]<array[pivot])
  {
     pointer++;
     //printf("SWAPPED %d AND %d \n",array[pointer],array[i]);
     swap(array+pointer,array+i);

  }
 }
 //WHEN ALL SWAPPING IS DONE THERE IS MASTER SWAP WITH PIVOT AND POINTER
 //THE SUB ARRAY BEFORE THE PIVOT INDEX INCLUDED ITSELF WILL HAVE LOWER VALUES AND THE OTHER SUB ARRAY WILL HAVE HIGHER ONES
 printf("MASTER SWAPPED %d AND %d \n",array[pointer],array[pivot]);
 swap(array+pointer,array+pivot);
 return(pointer);// THE INDEX BELOW WHICH (INCL. ITSELF) HAS LOWER VALUES

}

void quicksort(int *array,int low,int high)

{

    if(low<high) //SERVES AS AND END TO THE BELOW RECURSION FOR THAT IT DOESNT LET LOW=HIGH AND KEEP ON SWAPPING 
    {
    printArray(array,size);
    int pi=partition(array,low,high);//DIVIDES THE ARRAY INTO TWO SEGMENTS WITH LESSER ELEMENTS IN LEFT AND GREATER IN RIGHT AND RETURNS INDEX OF THE POSITION TILL LESSER ELEMENTS ARE THERE
    quicksort(array,low,pi);// THE pi RETURNS A INDEX INCL BELOW WHICH SMALLER ELEMENTS THAT PIVOT ARE THERE
    quicksort(array,pi+1,high);// THE HIGHER VALUES ARE AGAIN ARRANGED AS ELEMENTS ABOVE INDEX pi (ie.pi+1) HAS LARGER ELEMENTS THAN PIVOT ARE THERE
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

    printf("THE ARRAY GIVEN IS :\n");
    printArray(array,size);//PRINT ARRAY NEEDS SIZE FOR PASSIG SIZE 

    quicksort(array,0,size-1);//QUICKSORT NEEDS INDEX FOR PASSING SIZE-1
    printf("THE ARRAY SORTED IS :\n");
    printArray(array,size);

}
