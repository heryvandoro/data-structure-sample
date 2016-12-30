#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

struct antrian{
	int value;
	struct antrian *next, *prev;
}*head, *tail, *current;

void print(){
	if(head!=NULL){
		current=head;
		while(current!=NULL){
			printf("%d -> ", current->value);
			current=current->next;
		}
	}else{
		printf("No Data");
	}
	printf("\n\n");
};

void pushHead(int value){
	current = (struct antrian *)malloc(sizeof antrian);
	current->value=value;
	current->next = current->prev = NULL;

	if(head==NULL){
		head=tail=current;
	}else{
		head->prev=current;
		current->next=head;
		head=current;
	}
}

void popTail(){
	if(tail==NULL){
		printf("No Data");
	}else if(tail==head){
		current=tail;
		head=tail=NULL;
		free(current);
	}else{
		current=tail;
		tail=tail->prev;
		tail->next=NULL;
		free(current);
	}
}

void main(){
	int menu;
	int antrianke=1;
	print();
	do{
		do{
			system("cls");
			print();
			printf("1. Queue\n");
			printf("2. DeQueue\n");
			printf("3. Exit\n");
			printf("Choose : "); scanf("%d", &menu); fflush(stdin);
		}while(menu<1 || menu>3);
		switch(menu){
			case 1 : 
				pushHead(antrianke);
				antrianke++;
				break;
			case 2 : 
				popTail();
				break;
		}
	}while(menu!=3);
}