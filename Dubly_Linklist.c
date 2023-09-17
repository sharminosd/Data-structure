#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
}*head;
int main()
{
    int n;
    printf("Input the number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("\nData entered in the doubly linked list:\n");
    printData();
    display();

    int newData;

    printf("Enter data to insert at the beginning: ");
    scanf("%d", &newData);
    insertAtBeginning(newData);
    printf("\nData after inserting at the beginning:\n");
    printData();
    display();

    printf("Enter data to insert at the end: ");
    scanf("%d", &newData);
    insertAtEnd(newData);
    printf("\nData after inserting at the end:\n");
    printData();
    display();

    int position;
    printf("Enter position to insert at the middle: ");
    scanf("%d", &position);
    printf("Enter data to insert at position %d: ", position);
    scanf("%d", &newData);
    insertAtMiddle(position, newData);
    printf("\nData after inserting at the middle:\n");
    printData();
    display();

    deleteAtBeginning();
    printf("\nData after deleting at the beginning:\n");
    printData();
    display();

    deleteAtEnd();
    printf("\nData after deleting at the end:\n");
    printData();
    display();

    printf("Enter position to delete at the middle: ");
    scanf("%d", &position);
    deleteAtMiddle(position);
    printf("\nData after deleting at the middle:\n");
    printData();
    display();

    int data;
    printf("Enter data you want find: ");
    scanf("%d", &data);
    searching(data);
    display();

    return 0;
}

void createList(int n)
{
    struct node* newnode, * temp;

    head = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data for the first node: ");
    scanf("%d", &head->data);
    head->next = NULL;
    temp = head;

    for (int i = 2; i <= n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Input data for node %d: ", i);
        scanf("%d", &newnode->data);
        newnode->prev = temp;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}

void printData()
{
    if (head == NULL)
    {
        printf("Doubly linked list is empty\n");
    }
    else
    {
        struct node* temp = head;
        while (temp != NULL)
        {
            printf("CURRENT ADDRESS: %p \n DATA: %d \n Previous address: %p \n Next address: %p \n",
                   temp, temp->data, temp->prev, temp->next);
            temp = temp->next;
        }
    }
}

void insertAtBeginning(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    // newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

void insertAtEnd(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    struct node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtMiddle(int position, int data)
{
    struct node* newNode,*prev,*current;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    struct node* temp = head;
    for (int i = 1; i < position; i++)
    {
        prev=temp;
        current=temp->next;
        temp=current;
    }
    prev->next=newNode;
    newNode->next=current;

}

void deleteAtBeginning()
{
    struct node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd()
{
    struct node* temp,*prev;
    temp = head;

    while (temp->next != NULL)
    {
        prev=temp;
        temp = temp->next;
    }

    prev->next=NULL;

    free(temp);
}

void deleteAtMiddle(int position)
{
    struct node* temp,*prev,*current;
    temp = head;

    for (int i = 1; i < position ; i++)
    {
        prev=temp;
        current= temp->next;
        temp = temp->next;
    }
    prev->next=current->next;

    free(temp);
}

void searching(int data)
{
    struct node *temp;
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
    struct node *temp;
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



