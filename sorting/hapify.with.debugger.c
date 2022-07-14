#include<stdio.h>
#include<stdlib.h>

int * start(int size);
void traverser(int *list, int size);
void swap(int *a,int *b);
void heapify(int *list, int index, int size);
void printstack(int *list ,int size);

int main()
{
    int size;
    printf("ENTER THE SIZE OF STACK NEEDED");
    scanf("%d",&size);
    int *list=start(size);
    for(int i=0;i<size;i++)
    {
    printf("THE ELEMENT %d OF LIST : ",i+1);
    scanf("%d",list+i);
    }
    printstack(list,size);
    //for (i=0;i<)
    heapify(list,(size/2)-1,size);
    heapify(list,(size/2)-1,size);    
    heapify(list,(size/2)-1,size);    
    printstack(list,size);

}

int * start(int size)
{
    return (int*)malloc(sizeof(int));
}

//void traverser(int *list,int size)
/*{
    for(int i=(size/2)-1;i>-1;i--)
    {
        printf("\n-------------from traverser at %d\n",i);
        heapify(list,i,size);
        heapify(list,i,size);

    }
}*/

void heapify(int *list, int index, int size)
{
    printf("largest element is at index %d\n",index);

    int largest =index;
    int r=2*index+2;
    int l=2*index+1;
    int swapelement=index;
    if(list[r]>list[largest] && r<size)
    {
        printf("swapper1\n");
        printf("r is %d assumed largest is %d------- %d>%d\n",list[r],list[largest],list[r],list[largest]);
        swapelement=r;
    }
    if(list[l]>list[swapelement] && l<size)
    {
     printf("swapper2\n");
     printf("l is %d assumed largest is %dd------- %d>%d\n",list[l],list[largest],list[l],list[largest]);
     swapelement=l;

    }

    printf("swapper element is at index %d\n",swapelement);
    swap(list+swapelement,list+largest);


    if (largest != 0)
    {
      heapify(list, largest-1, size);
    }
}

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void printstack(int *list,int size)
{
printf("\nTREE IS :");
for(int i=0;i<size;i++)
{
   printf("%d,",list[i]);
}
}