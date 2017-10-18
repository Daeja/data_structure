#include <stdio.h>
#include <stdlib.h>

#define BUF 5

#define BOOL int
#define TRUE 1
#define FALSE 0

int menu;
int number;
int front;
int rear;
int queue[BUF];

void init() {
	int cnt;

	menu=0;
	number=0;
	front=-1;
	rear=-1;

	for(cnt=0; cnt<BUF; cnt++) queue[cnt] = 0;
}

void display() {
	printf("1. input\n");
	printf("2. output\n");
	printf("3. view\n");
	printf("4. size\n");
	printf("5. isEmpty\n");
	printf("6. exit\n");

	printf("Select your number : ");
}

void input(int number) {
	if(rear == (BUF - 1)) printf("Queue is full\n");
	else { rear++; queue[rear] = number; }
}

void output() {
	int cnt;

	if(front == rear) printf("Queue is empty\n");
	else {
		front++;
		printf("Output data is %d\n", queue[front]);

		for(cnt=front; cnt<rear; cnt++) queue[cnt] = queue[cnt + 1];

		front--;
		rear--;
	}
}

void view() {
	if(front == rear) printf("Queue is empty\n");
	else {
		int cnt;

		for(cnt=(front + 1); cnt<(rear + 1); cnt++) printf("%d\t", queue[cnt]);

		printf("\n");
	}
}

void size() {
	printf("Queue size is %d\n", rear-front);
}

void isEmpty() {
	if(front == rear) printf("Queue is empty\n");
	else printf("Queue isn't empty\n");
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
				input(number);
				break;

			case 2 :
				output();
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
