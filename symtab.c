#include<stdio.h>
#include <stdlib.h>
//define node
struct node{
    int address;
    char label[20];
    struct symtab *link;
}*seq[10];
//function to insert label into the symbol table
void insertIntoTable(){
    int dest,moddest;
    struct node *new = malloc(sizeof(struct node));
    printf("Enter Address: ");
    scanf("%d",&dest);// accept address of the label from the user
    moddest=dest%10;//apply hashing technique
    //create a node with datas from the user and insert to appropriate index in the sequence
    printf("Enter Label: ");//accept label name from the user
    new->address=dest;
    scanf("%s",new->label);
    new->link=NULL;
    if(seq[moddest]==NULL)
        seq[moddest]=new;
    else
    {
        while(seq[moddest]->link!=NULL){
            seq[moddest]=seq[moddest]->link;
        }
        seq[moddest]->link=new;
    }
}
//function to serach for a label in the symbol table
void searchTable(){
    int flag=0,i,j=0;
    char name[50];
    printf("Enter Label Field To be Searched:");
    scanf("%s",name);//accept label name to be serached from the user
    //search for the label in the whole sequence
    for(i = 0; i < 10; i++)
    {
        //search for the label in all nodes in each sequence
        struct node *ptr = seq[i];
        while(ptr!=NULL)
        {
            if(strcmp(ptr->label,name)==0){
                flag=1;
                break;
            }
           ptr=ptr->link;
           j=j+1;
        }
        //success message
        if(flag==1){
            printf("%s Present at %dth position of %dth index in the Symbol Table",name,j,i);
            break;
        }
        j=0;
    }
    //search unsuccessful
    if(flag==0)
        printf("%s Not Present",name);
}
//function to display the symbol table
void displayTable(){
    int i;
    for(i = 0; i < 10; i++)
    {
        //display all nodes in each sequence
        struct node *ptr = seq[i];
        printf("%d-->\t",i);
        while(ptr!=NULL)
        {
            printf("%d -->",ptr->address);
            printf("%s -->",ptr->label);
            ptr = ptr->link;
        }
        printf("NULL\n");
    }
}
void main(){
    int ch,addr;
    //display menu
    printf("Menu: \n\t1.To Insert Label to Symbol Table \n\t2.To Search for a Label in The Table \n\tTo Display The Symbol Table\n\t4.To Terminate");
    do{
        //accept user's choice
        printf("\n\nEnter your choice:");
        scanf("%d",&ch);
        if(ch==1)
            insertIntoTable();
        else if(ch==2)
            searchTable();
        else if(ch==3)
            displayTable(); 
        else if(ch==4)
            printf("Terminated");
        else
            printf("Invalid Choice");            
    }while(ch!=4);// continue until choice is to terminate
}