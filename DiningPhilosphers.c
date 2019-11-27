#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#define N 5

#define EATING 0
#define HUNGRY 1
#define THINKING 2

#define LEFT ((phnum + 4 ) % N)
#define RIGHT ((phnum + 1 ) % N)

sem_t mutex,S[N];
int state[N],phil[N]={0,1,2,3,4};
void test(int phnum){
	if(state[phnum]==HUNGRY && state[LEFT]!=EATING && state[RIGHT]!=EATING){
		state[phnum]=EATING;
		printf("\n\nPhilospher %d takes fork %d and %d .\n",phnum+1,LEFT+1,phnum+1);
		printf("\nPhilospher %d is EATING.\n",phnum+1);
		sleep(2);
		sem_post(&S[phnum]);
	}
}

void take_fork(int phnum){
	sem_wait(&mutex);
	state[phnum]=HUNGRY;
	printf("\nPhilospher %d is HUNGRY",phnum+1);
	test(phnum);
	sem_post(&mutex);
	sem_wait(&S[phnum]);
	sleep(1);
}

void put_fork(int phnum){
	sem_wait(&mutex);
	state[phnum]=THINKING;
	printf("\n\nPhilospher %d puts down fork %d and %d .\n",phnum+1,LEFT+1,phnum+1);
	printf("\nPhilospher %d is THINKING.\n",phnum+1);
	test(LEFT);
	test(RIGHT);
	sem_post(&mutex);
}



void* philospher(void* arg){
	int* n=(int*)arg;

	while(1){
		sleep(1);
		take_fork(*n);
		sleep(0);
		put_fork(*n);
		sleep(1);
	}
	pthread_exit(0);
}

void main(){
	pthread_t thread_id[N];
	int i;
	sem_init(&mutex,1,1);
	for(i=0;i<N;i++)
		sem_init(&S[i],1,0);

	for(i=0;i<N;i++){
		pthread_create(&thread_id[i],NULL,philospher,&phil[i]);
		printf("\nPhilospher %d is THINKING.",i+1);
	}

	for(i=0;i<N;i++)
		pthread_join(thread_id[i],NULL);

}

