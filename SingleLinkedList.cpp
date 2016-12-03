#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct human{
	int age;
	char name[30];
	human *next;
}*head, *tail, *current;

void pushTail(int age, char name[]){
	current = (human*)malloc(sizeof(struct human));
	current->age = age;
	strcpy(current->name, name);

	if(head == NULL){
		head = tail = current;
	}
	else{
		tail->next = current;
		tail = current;
	}
	tail->next = NULL;
}

void pushHead(int age, char name[]){
	current = (human*)malloc(sizeof(struct human));
	current->age = age;
	strcpy(current->name, name);

	if(head == NULL){
		head = tail = current;
	}
	else{
		current->next = head;
		head = current;
	}	
}

void pushMid(int age, char name[]){
	current = (human*)malloc(sizeof(struct human));
	current->age = age;
	strcpy(current->name, name);

	if(head == NULL){
		head = tail = current;
	}
	else if(current->age < head->age){
		pushHead(age, name);
	}
	else if(current->age > tail->age){
		pushTail(age, name);
	}
	else{
		human *temp = head;
		while(temp->next->age < current->age){
			temp = temp->next;
		}
		current->next = temp->next;
		temp->next = current;
	}
}

void popHead(){
	current=head;
	if(head==NULL){
		printf("No data");
	}else if(head==tail){
		head=tail=NULL;
		free(current);
	}else{
		head=head->next;
		free(current);
	}
}

void popTail(){
	if(head==NULL){
		printf("No data");
	}else if(head==tail){
		head=tail=NULL;
		free(current);
	}else{
		human *temp=head;
		while(temp->next!=tail){
			temp=temp->next;
		}
		current=tail;
		tail=temp;
		free(current);
		tail->next=NULL;
	}
}

void popMid(int age){
	current=head;
	if(head==NULL){
		printf("No data");
	}else if(head->age==age){
		popHead();
	}else if(tail->age==age){
		popTail();
	}else{
		human *temp=head;
		while(temp->next->age!=age && temp!=tail){
			temp=temp->next;
		}
		current=temp->next;
		temp->next=temp->next->next;
		free(current);
	}
}

void print(){
	current = head;
	while(current != NULL){
		printf("%s - %d\n",current->name,current->age);
		current = current->next;
	}
}

int main(){
	pushMid(18, "hery");
	pushMid(17, "mahirkoding");
	pushTail(22, "andi");
	pushHead(15, "tono");
	pushMid(11, "vandoro");
	pushMid(23, "budi");
	popHead();
	popTail();
	popMid(15);
	print();
	getchar();
	return 0;
}
