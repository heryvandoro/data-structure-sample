#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

struct book{
	char studentname[30];
	struct book *next, *prev;
}*head, *tail, *current;

void print(){
	if(head!=NULL){
		current=head;
		while(current!=NULL){
			printf("%s -> ", current->studentname);
			current=current->next;
		}
	}else{
		printf("No Data");
	}
	printf("\n\n");
};

void pushHead(char name[]){
	current = (struct book *)malloc(sizeof book);
	strcpy(current->studentname, name);
	current->next = current->prev = NULL;

	if(head==NULL){
		head=tail=current;
	}else{
		head->prev=current;
		current->next=head;
		head=current;
	}
}

void popHead(){
	if(head==NULL){
		printf("No Data");
	}else if(head==tail){
		current=head;
		head=tail=NULL;
		free(current);
	}else{
		current=head;
		head=head->next;
		head->prev=NULL;
		free(current);
	}
}

void main(){
	int menu;
	char studentname[30];
	print();
	do{
		do{
			system("cls");
			print();
			printf("1. Stack\n");
			printf("2. UnStack\n");
			printf("3. Exit\n");
			printf("Choose : "); scanf("%d", &menu); fflush(stdin);
		}while(menu<1 || menu>3);
		switch(menu){
			case 1 : 
				printf("Input Student Name : "); scanf("%s", studentname); fflush(stdin);
				pushHead(studentname);
				break;
			case 2 : 
				popHead();
				break;
		}
	}while(menu!=3);
}
