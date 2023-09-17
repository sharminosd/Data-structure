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
void printData();
int searching(int data);
int main()
{
    int n;
    printf("\n Enter total number of node: ");
    scanf("%d",&n);
    createnode(n);
    printData();
    display();
    printf("\n Inserting new node at beginning...\n");
    insert_beg();
    printData();
    display();
    printf("\n Inserting new node at middle...\n");
    insert_middle(n);
    printData();
    display();
    printf("\n Inserting new node at the end...\n");
    insert_end();
    printData();
    display();
    printf("\n AFTER DELETING THE FIRST & LAST NODE....");
    delete_first();
    delete_last();
    printData();
    display();
    delete_middle();
    printData();
    display();
    int key;
    printf("\nEnter the value to search for: ");
    scanf("%d", &key);

    int position = searching(key);
    if (position != -1)
    {
        printf("Node with value %d found at position %d.\n", key, position);
    }
    else
    {
        printf("Node with value %d not found.\n", key);
    }
    return 0;

    // ... (rest of your main function)
}

void createnode(int n)
{
    node *newnode, *temp;
    int i;
    head= (node*)malloc(sizeof(node));
    head->next=head;
    printf("\n Enter data for Node 1: ");
    scanf("%d", &head->data);
    temp=head;
    for(i=2; i<=n; i++)
    {
        newnode=  (node*)malloc(sizeof(node));
        printf("\n Enter data for Node %d: ",i);
        scanf("%d", &newnode->data);
        newnode->next=head;
        temp->next=newnode;
        temp=temp->next;
    }
}

void insert_beg()
{
    node *newnode,*temp;

    newnode=  (node*)malloc(sizeof(node));
    printf("\n Enter data for beginning node: ");
    scanf("%d", &newnode->data);
    temp=head;
    newnode->next=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    head=newnode;
    temp->next=head;
}
void insert_middle(int pos)
{
    node *newnode,*temp,*current,*prev;
    newnode=  (node*)malloc(sizeof(node));
    printf("\n Enter the position for inserting data:");
    scanf("%d",&pos);
    printf("\n Enter data for middle node: ");
    scanf("%d", &newnode->data);
    temp=head;
    for(int i=1; i<pos; i++)
    {
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
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
}
void delete_first()
{

    node *temp = head;
    node *last = head;

    while (last->next != head)
    {
        last = last->next;
    }

    head = temp->next;
    last->next = head;

    free(temp);
}


void delete_middle()
{
    int pos,i;
    node *current, *temp, *prev;
    printf("\n Enter the position of the node you want to delete..\n");
    scanf("%d",&pos);
    temp=head;
    for(i=1; i<pos; i++)
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
    while(temp->next!=head)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=head;
    free(temp);
}
void printData()
{
    if (head == NULL)
    {
        printf("Doubly linked circular list is empty\n");
    }
    else
    {
        node* ptr = head;
        do
        {
            printf("CURRENT ADDRESS: %p \n DATA: %d  \n Next address: %p \n",
                   ptr, ptr->data, ptr->next);
            ptr = ptr->next;
        }
        while (ptr != head);
    }
}
int searching(int key)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return -1; // List is empty, so return -1 to indicate not found.
    }

    node *temp = head;
    int pos = 1;

    do
    {
        if (temp->data == key)
        {
            return pos; // Found the key at position 'pos'.
        }
        temp = temp->next;
        pos++;
    }
    while (temp != head);

    // printf("Node with value %d not found.\n", key);
    return -1; // Key not found in the list.
}
void display()
{
    node *temp;
    temp=head;
    int count=1;
    printf("\n You have Successfully created the following linkedlist: \n");
    while(temp->next!=head)
    {
        count ++;
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("%d-> ",temp->data);
    printf("\nThe number of nodes are: %d\n", count);
}

