#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *head;
void createnode(int n);
void display();
void insert_beg();
void insert_middle();
void insert_end();
void delete_first();
void delete_middle();
void delete_last();
void searching(int data);
int main()
{
    int n;
    printf("\n Enter total number of node: ");
    scanf("%d",&n);
    createnode(n);
    display();
    printf("\n Inserting new node at beginning...\n");
    insert_beg();
     display();
     printf("\n Inserting new node at middle...\n");
    insert_middle(n);
     display();
     printf("\n Inserting new node at the end...\n");
    insert_end();
     display();
     printf("\n AFTER DELETING THE FIRST & LAST NODE....");
    delete_first();
    delete_last();
    display();
    delete_middle();
    display();
    int data;
    printf("\nEnter data for search:\n");
    scanf("%d",&data);
    searching(data);
    return 0;

}

void createnode(int n)
{
    node *newnode, *temp;
    int i;
    head= (node*)malloc(sizeof(node));
    head->next=NULL;
    printf("\n Enter data for Node 1: ");
    scanf("%d", &head->data);
    temp=head;
    for(i=2;i<=n;i++)
    {
      newnode=  (node*)malloc(sizeof(node));
      printf("\n Enter data for Node %d: ",i);
      scanf("%d", &newnode->data);
      newnode->next=NULL;
      temp->next=newnode;
      temp=temp->next;
    }
}

void insert_beg()
{
    node *newnode;

    newnode=  (node*)malloc(sizeof(node));
    printf("\n Enter data for beginning node: ");
    scanf("%d", &newnode->data);
    newnode->next=head;
    head=newnode;
}
void insert_middle(int pos){
node *newnode,*temp,*current,*prev;
 newnode=  (node*)malloc(sizeof(node));
 printf("\n Enter the position for inserting data:");
 scanf("%d",&pos);
    printf("\n Enter data for middle node: ");
    scanf("%d", &newnode->data);
    temp=head;
for(int i=1;i<pos;i++){
    prev=temp;
    current=temp->next;
    temp=current;
}
prev->next=newnode;
newnode->next=current;

}
void insert_end()
{
    node *temp,*newnode;
    newnode=  (node*)malloc(sizeof(node));
    printf("\n Enter data for last node: ");
    scanf("%d",&newnode->data);
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
     newnode->next=NULL;
}
void delete_first()
{
    node *temp;
    temp=head;
    head=temp->next;
    free(temp);
}

void delete_middle()
{
    int pos,i;
    node *current, *temp, *prev;
    printf("\n Enter the position of the node you want to delete..\n");
    scanf("%d",&pos);
    temp=head;
    for(i=1;i<pos;i++)
    {
        prev=temp;
        current=temp->next;
        temp=temp->next;
    }
    prev->next=current->next;
    free(current);
}
void delete_last()
{
node *temp, *prev;
temp=head;
while(temp->next!=NULL)
{
    prev=temp;
    temp=temp->next;
}
prev->next=NULL;
free(temp);
}
void searching(int data)
{
 node *temp;
 temp = head;
 int pos = 1;

 while (temp != NULL)
 {
 if (temp->data == data)
 {
 printf("Data found at node %d\n", pos);
 return;
 }
 temp = temp->next;
 pos++;
 }

 printf("Data not found in the list.\n");
}
void display()
{
    node *temp;
    int count =0;
    temp=head;
    printf("\n You have Successfully created the following linkedlist: \n");
    while(temp!=NULL)
    {
        count++;
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("\nThe number of nodes are: %d\n", count);
}


