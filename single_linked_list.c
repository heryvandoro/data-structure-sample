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
	pushMid(22, "andi");
	pushHead(22, "tono");
	pushMid(11, "vandoro");
	pushMid(22, "budi");
	print();
	getchar();
	return 0;
}
