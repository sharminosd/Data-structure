#include<stdio.h>
#include<stdlib.h>
#define N 4
int stack_arr[N];
int top= -1;

void push(int data){
	if(top == N-1){
		printf("stack overflow\n");
		return;
  }
   top=top+1;
   stack_arr[top]=data;

}
int pop(){
	if(top == -1){
		printf("stack underflow");
		exit(1);
	}
	int value=stack_arr[top];
   top=top-1;
   return value;
}

void print() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents:\n");
    for (i = top; i >= 0; i--) {
        printf("| %d |\n", stack_arr[i]);
    }
}


int main(){
	push(10);
	push(20);
	push(30);
	int del=pop();
	printf("value %d deleted\n",del);
	push(40);
	print();
	int del2=pop();
	printf("value %d deleted\n",del2);
	print();
return 0;
}
