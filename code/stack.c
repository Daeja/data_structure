#include <stdio.h>
#include <stdlib.h>

#define BUF 5

#define BOOL int
#define TRUE 1
#define FALSE 0

int menu;
int number;
int top;
int stack[BUF];

void init() {
	int cnt;

	menu=0;
	number=0;
	top=0;

	for(cnt=0; cnt<BUF; cnt++) stack[cnt] = 0;
}

void display() {
	printf("1. push\n");
	printf("2. pop\n");
	printf("3. view\n");
	printf("4. size\n");
	printf("5. isEmpty\n");
	printf("6. exit\n");

	printf("Select your number : ");
}

void push(int number) {
	if(top >= BUF) printf("Overflow\n");
	else { stack[top] = number; top++; }
}

void pop() {
	if(top == 0) printf("Underflow\n");
	else { printf("Popping data : %d\n", stack[top-1]); top--; }
}

void view() {
	if(top == 0) printf("Stack is empty\n");
	else printf("Data that located in top : %d\n", stack[top-1]);
}

void size() {
	printf("Stack size is %d\n", top);
}

void isEmpty() {
	if(top == 0) printf("Stack is empty\n");
	else printf("Stack isn't empty\n");
}

int main() {
	BOOL bool = TRUE;
	int ret;

	init();

	while(bool) {
		display();
		scanf("%d", &menu);
		ret = system("clear");

		switch(menu) {
			case 1 :
				printf("Input number : ");
				scanf("%d", &number);
				push(number);
				break;

			case 2 :
				pop();
				break;

			case 3 :
				view();
				break;

			case 4 :
				size();
				break;

			case 5 :
				isEmpty();
				break;

			case 6 :
				printf("Exit\n");
				bool = FALSE;
				break;
		}
	}

	return 0;
}
