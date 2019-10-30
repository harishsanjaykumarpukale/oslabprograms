#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left,*right;
};
typedef struct node* NODE;

int SIZE;

NODE getnodE(){
    NODE temp;
    temp=(NODE) malloc(sizeof(struct node));
    if(temp!=NULL)
        return temp;
    else{
        printf("\nAllocation unsuccessful.\n");
        exit(0);
        }
}



int allocate(NODE root,int size){

	if(size<root->data){
        root->left=


void main(){

	int ch,size;

	NODE root=NULL;

	printf("\nEnter the size of total memory :");
	scanf("%d",&SIZE);

	root->data=SIZE;
	root->left=NULL;

	for(;;){

		printf("Press\n 1 for Allocate memory\n 2 for Deallocating memory\n 3 for Display\n 4 for Exit.\n");

	        printf("\nEnter your choice:");

		scanf("%d",&ch);

		switch(ch){
			case 1: printf("\nEnter the size of proccess to be allocated:");

				scanf("%d",&size);

				if(allocate(&root,size))
					printf("\nAllocation Successful\n");
				else
					printf("\nAllocation Unsuccessful\n");
				break;


			
