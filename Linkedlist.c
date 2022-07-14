#include<stdio.h>
#include<stdlib.h>

    int nodes;
    int node1val;
    int pushedval;
    int switchx;
    int mid;
    int midvalue;
    int i;
    int a;

struct node{
    int data;
    struct node *next;
}*node1,*nodex,*temp,*pushed,*midnode;

void del(){
    printf("\nENTER 1 TO DELETE HEAD \n2 TO DELETE ELSE \n");
    scanf("%d",&switchx);
if (switchx==1){
    node1=node1->next;
}

if (switchx==2){

             printf("\nENTER AT WHICH NODE IT IS TO BE DELTED :\n");
             scanf("%d",&mid);
             temp=node1;
             if(mid>nodes){
                //doint this so that segmentation fault wont occur
                printf("PLEASE GIVE A NUMBER WITHIN THE RANGE OF LINKED LIST");
             }
             else{
             for(int i=2;i<mid;i++) 
             {

             temp=temp->next;

             }
             
            {
                   temp->next=temp->next->next;       
            } 

}
}
}

void trav();

void s1(){
            {

           int i=0;
           printf("\nTHE LINKED LIST BEFORE ADDING IS : \n");

           trav();

           printf("\n");

             printf("ENTER AT WHICH NODE IT IS TO BE ADDED :");
             scanf("%d",&mid);
             temp=node1;
             if(mid>nodes){
                //doint this so that segmentation fault wont occur
                printf("PLEASE GIVE A NUMBER WITHIN THE RANGE OF LINKED LIST");
                s1();
             }
             else{
             for(i=2;i<mid;i++) 
             {

             temp=temp->next;

             }
             

             midnode=(struct node*)malloc(sizeof(struct node));
             printf("ENTER THE NODE VALUE :");
             scanf("%d",&midvalue);
             midnode->data=midvalue;  

               if(mid==1){  

                 midnode->next=node1;
                 node1=midnode;

                         }

               else{
                 midnode->next=temp->next;   
                 temp->next=midnode;            
                   } 

            trav();     
             }
        }
}

void peek(){
    int i=0;
    temp=node1;
    while(temp!=NULL){
        temp=temp->next;
        if(temp->next==NULL){
          printf(" THE PEEKED VALUE IS %d",temp->data);
        }

   }

}

int pop(){
    int i=0;
    temp=node1;
    while(temp!=NULL){
        temp=temp->next;
        i++;
        if(temp->next->next==NULL){
            a=temp->next->data;

            temp->next=NULL; // the assignment temp=null doesnt work and idk y??
            printf("POPPED ELEMENT IS %d \n",a);
            trav();
            return a;
        }
    }
    if(i==0){
        printf("STACK UNDERFLOW");
        trav();
    }
return 1;
}

void push(){

    int i=0;
    temp=node1;
     while(temp!=NULL){
        
        temp=temp->next;
        i++;
        if(i>=nodes){
            printf("STACK OVERFLOW \n");
            break;
            
        }
        
        if(temp->next==NULL){
                pushed=(struct node*)malloc(sizeof(struct node));
                printf("ENTER THE VALUE OF PUSHING NODE:");
                scanf("%d",&pushedval);
                pushed->data=pushedval;
                temp->next=pushed;
                pushed->next=NULL;
                break;
              
            }
        
     }
trav();
}

void trav(){
             int i=0;
          temp=node1;
          
          while(temp!=NULL)
                 { 
           printf("THE VALUE OF NODE %d IS ",++i);
           printf("%d \n",temp->data);
           temp=temp->next;

                 } 
}

int main(){

    node1=(struct node*)malloc(sizeof(struct node));
    printf("ENTER THE NUMBER OF NODES NEEDED :");
    scanf("%d",&nodes);

    printf("ENTER THE VALUE OF NODE 1 :");
    scanf("%d",&node1val);
    node1->data=node1val;
    node1->next=NULL;

    temp=node1;

    for(int i=2;i<=nodes;i++)
    {

            int nodexval;
            nodex=(struct node*)malloc(sizeof(struct node));

            printf("ENTER THE VALUE OF NODE %d :",i);
            scanf("%d",&nodexval);
            nodex->data=nodexval;
            nodex->next=NULL;

            temp->next=nodex;
  
            temp=nodex;
    }
    printf("\nENTER 1 TO ADD ELELEMENT  \nENTER 2 TO  TRAVERSE \nENTER 3 TO DELETE AN ELEMENT \n");
    scanf("%d",&switchx);


if (switchx==1)
 s1();

if (switchx==2)
 trav(); 

if (switchx==3)
 del();

printf("\nENTER 1 TO PUSH AN ELEMENT  \nENTER 2 TO POP AND ELEMENT \nENTER ANYTHING ELSE TO EXIT \n");
scanf("%d",&switchx);

if (switchx==2)
   pop();

if (switchx==1)
   push();
printf("\n");
trav();
}

