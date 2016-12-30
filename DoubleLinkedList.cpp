#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct human{
	int age;
	char name[30];
	human *next, *prev;
}*head, *tail, *current;

void pushTail(int age, char name[]){
	current = (struct human *)malloc(sizeof human);
	strcpy(current->name, name);
	current->age = age;
	current->prev = current->next = NULL;

	if(head==NULL){
		head=tail=current;
	}else{
		current->prev = tail;
		tail->next = current;
		tail = current;
	}
}

void pushHead(int age, char name[]){
	current = (struct human *)malloc(sizeof human);
	strcpy(current->name, name);
	current->age=age;
	current->next = current->prev=NULL;

	if(head==NULL){
		head=tail=current;
	}else{
		head->prev=current;
		current->next=head;
		head=current;
	}
}

void PushMid(int age, char name[]){
	if(head==NULL){
		pushHead(age,name);
	}else if(age < head->age){
		pushHead(age,name);
	}else if(age > tail->age){
		pushTail(age,name);
	}else{
		current = (struct human *)malloc(sizeof human);
		strcpy(current->name, name);
		current->age = age;
		current->next = current->prev = NULL;

		struct human *temp=head;
		while(temp!=NULL && temp->age < current->age){
			temp=temp->next;
		}
		current->prev=temp->prev;
		current->next=temp;

		temp->prev->next=current;
		temp->prev=current;
	}
}

void popHead(){
	if(head==NULL){
		printf("No Data\n");
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

void popTail(){
	if(head==NULL){
		printf("No Data\n");
	}else if(head==tail){
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

void popMid(int age){
	int temu=0;
	if(head==NULL){
		printf("No Data\n");
	}else{
		current=head;
		while(current!=NULL){
			if(current->age==age){
				temu=1;
				break;
			}
			current=current->next;
		}
		if(temu==1){
			if(current==head){
			popHead();
			}else if(current==tail){
				popTail();
			}else{
				current->prev->next=current->next;
				current->next->prev=current->prev;
				free(current);
			}
		}else{
			printf("Data Not Found\n");
		}
	}
}

void popAll(){
	while(head!=NULL){
		popHead();
	}
}

void print(){
	current=head;
	if(current!=NULL){
		while(current!=NULL){
			printf("Name : %s | Age : %d\n", current->name, current->age);
			current=current->next;
		}
	}else{
		printf("No Data\n");
	}
}

void main(){
	pushHead(23, "Hery");
	pushHead(20, "Budi");
	pushHead(13,"Tono");
	pushHead(11, "Andi");
	pushTail(15, "MahirKoding");
	PushMid(17, "Budi");
	popMid(11);
	//popMid(6);
	//popAll();
	print();
	getchar();
}
