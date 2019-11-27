#include<stdio.h>
#include<stdlib.h>
int p,r,i,av[10],j,max[10][10],alloc[10][10],need[10][10],comp[10]={0},req[10];
void bankersalgo(){
	int c1=0,c2=0,k;
	while(c1!=p){
		c2=c1;
		for(i=0;i<p;i++){
			k=0;
			for(j=0;j<r;j++)
				if(av[j]>=need[i][j])
					k++;
			if(k==r && comp[i]==0){
				comp[i]=1;
				c1++;
				for(j=0;j<r;j++)
					av[j]+=alloc[i][j];
				printf("\nProcess %d",i);
			}
		}

		if(c1==c2){
			printf("\nDeadlock\n");
			return ;
		}
	}
}

void main(){
	int ch,pr_num,k;
	printf("\nEnter the total no of proccess:");
	scanf("%d",&p);

	printf("\nEnter the no of differnt types of resources:");
	scanf("%d",&r);


	printf("\nEnter the available instances of resource");
	for(i=0;i<r;i++){
		printf("\nof type %d:",i+1);
		scanf("%d",&av[i]);
		}


	printf("\nEnter the max no of resources required by  ");
	for(i=0;i<p;i++){
		printf("\nProccess %d in order:",i+1);
		for(j=0;j<r;j++)
			scanf("%d",&max[i][j]);
		}


	printf("\nEnter the allocated no of resources to ");
	for(i=0;i<p;i++){
		printf("\nProccess %d in order:",i+1);
		for(j=0;j<r;j++){
			scanf("%d",&alloc[i][j]);
			need[i][j]=max[i][j]-alloc[i][j];
			}
	       }


	printf("\nNeed Matrix is as follows:");
	for(i=0;i<p;i++){
		for(j=0;j<r;j++)
		       	printf("%d\t",need[i][j]);
		printf("\n");
		}

	bankersalgo();

	printf("\nRESOURCE REQUEST ALGORITHM\n");

	printf("\nEnter the process number:");
	scanf("%d",&pr_num);

	printf("\nEnter the resource request  vector:");
	for(i=0;i<r;i++)
	       scanf("%d",&req[i]);

	printf("\nEnter the available instances of resource");//Once again since available vetctor has changed after call to bankersalgo()
        for(i=0;i<r;i++){
        	printf("\nof type %d:",i+1);
                scanf("%d",&av[i]);
                }

	for(i=0;i<p;i++)
		comp[i]=0;

	k=0;
	for(i=0;i<r;i++)
		if(req[i]<=need[pr_num-1][i] && req[i]<=av[i])
			k++;
	if(k==r){
		for(i=0;i<r;i++){
			av[i]-=req[i];

			alloc[pr_num-1][i]+=req[i];

			need[pr_num-1][i]-=req[i];
		}


		bankersalgo();
	}

	else
		printf("\nERROR:REQUEST VECTOR IS GREATER THAN NEED \n OR \nERROR:REQUEST CANNOT BE GRANTED IMMIDIATELY\n");



}



