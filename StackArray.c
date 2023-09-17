#include <stdio.h>
#define N 100 // Define the stack size as a constant

int top = -1; // Initialize the top of the stack
int stack[N]; // Define the stack with a fixed size
//int n; // Size of the stack

void push()
{
    int x;
    if (top == N - 1)   // Check for stack overflow
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter a value to push: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if (top == -1)   // Check for stack underflow
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Empty\n");
    }
    else
    {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--)
        {
            printf(" | %d |\n", stack[i]);
        }
    }
}

int main()
{
    int n;
    top = -1;
    printf("\n Enter the size of STACK [MAX=100]: ");
    scanf("%d", &n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");

    int choice = 0;
    while (choice != 4)
    {
        printf("\n Enter the Choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            push();
        }
        else if (choice == 2)
        {
            pop();
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            printf("\n\t EXIT POINT ");
        }
        else
        {
            printf("\n\t Please Enter a Valid Choice (1/2/3/4)");
        }
    }

    return 0;
}
