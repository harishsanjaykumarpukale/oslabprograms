#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define SIZE 10

sem_t full,empty,mutex;

int buffer[SIZE],top=-1;

void initialise(){
	sem_init(&mutex,1,1);
	sem_init(&empty,1,SIZE);
	sem_init(&full,1,0);
}

void* producer(void* arg){
	int item;
	item=rand()%115;

	sleep(1);
	sem_wait(&mutex);
	sem_wait(&empty);

	buffer[++top]=item;
	printf("\nProducer produced %d.\n",buffer[top]);

	sem_post(&full);
	sem_post(&mutex);
	pthread_exit(0);
}


void* consumer(void* arg){
        int item;

	sleep(1);
        sem_wait(&mutex);
        sem_wait(&full);

        item=buffer[top--];
        printf("\nConsumer consumed %d \n",item);

        sem_post(&empty);
        sem_post(&mutex);
	pthread_exit(0);
}

void main(){
	pthread_t tidp[10],tidc[10];

	int i,p,c;

	initialise();

	printf("\nEnter the number of Producers and Consumers:");
	scanf("%d%d",&p,&c);

	for(i=0;i<p;i++){
		pthread_create(&tidp[i],NULL,producer,NULL);
		pthread_join(tidp[i],NULL);
	}

	for(i=0;i<p;i++){
                pthread_create(&tidc[i],NULL,consumer,NULL);
                pthread_join(tidc[i],NULL);
        }
}

