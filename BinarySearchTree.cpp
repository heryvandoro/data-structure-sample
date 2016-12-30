#include <stdio.h>
#include <stdlib.h>

struct data{
	int number;
	data *left, *right;
}*root;

void push(data **current, int number){
	if((*current)==NULL){
		(*current) = (struct data *)malloc(sizeof data);
		(*current)->number=number;
		(*current)->left = (*current)->right = NULL;
	}else if(number < (*current)->number){
		push(&(*current)->left, number);
	}else if(number >= (*current)->number){
		push(&(*current)->right, number);
	}
}

void inOrder(data **current){
	if((*current)!=NULL){
		inOrder(&(*current)->left);
		printf("%d -> ", (*current)->number);
		inOrder(&(*current)->right);
	}
}

void preOrder(data **current){
	if((*current)!=NULL){
		printf("%d -> ", (*current)->number);
		preOrder(&(*current)->left);
		preOrder(&(*current)->right);
	}
}

void postOrder(data **current){
	if((*current)!=NULL){
		postOrder(&(*current)->left);
		postOrder(&(*current)->right);
		printf("%d -> ", (*current)->number);
	}
}

void search(data **current, int number){
	if((*current)!=NULL){
		if(number<(*current)->number){
			search(&(*current)->left,number);
		}else if(number>(*current)->number){
			search(&(*current)->right,number);
		}else{
			printf("Found : %d", (*current)->number);
		}
	}else{
		printf("Not Found.");
	}
}

void main(){
	push(&root, 11);
	push(&root, 22);
	push(&root, 13);
	push(&root, 15);
	push(&root, 9);
	inOrder(&root);
	printf("\n");
	preOrder(&root);
	printf("\n");
	postOrder(&root);
	printf("\n");
	search(&root,91);
	getchar();
}