#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int * start(int size);
void traverser(int *list, int size);
void swap(int *a,int *b);
void heapify(int *list, int index, int size);
void printstack(int *list ,int size);

int main()
{
    int size;
    printf("ENTER THE SIZE OF HEAP NEEDED");
    scanf("%d",&size);
    int *list=start(size);
    for(int i=0;i<size;i++)
    {
    printf("THE ELEMENT %d OF HEAP : ",i+1);
    scanf("%d",list+i);
    }
    printstack(list,size);

    heapify(list,(size/2)-1,size);

printstack(list,size);

}

int * start(int size)
{
    return (int*)malloc(sizeof(int));
}

void heapify(int *list, int index, int size)
{
    int largest =index;
    int r=2*index+2;
    int l=2*index+1;
    int swapelement=index;
    if(list[r]>list[swapelement] && r<size)
    {
        swapelement=r;
    }
    if(list[l]>list[swapelement] && l<size)
    {
     swapelement=l;
    }
    
    if (swapelement != index)
    {
    swap(list+largest,list+swapelement);
    heapify(list,swapelement,size);
    }

    if (swapelement != 0)
    {
      heapify(list, swapelement-1, size);
    }
}

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void printstack(int *list,int size)
{
printf("\nMAX HEAP IS :");

for(int i=0;i<size;i++)
{
   printf("%d-",list[i]);
}
}
