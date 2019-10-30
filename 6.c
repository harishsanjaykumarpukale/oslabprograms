#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
void main(int argc,char *argv[]){
    char *file=argv[1];
    int fd;
    struct flock lock;
    if(argc==2){
printf("\nI am opening file %s\n",file);
    fd=open(file,O_WRONLY);


    printf("\nI am locking file!\n");
    memset(&lock,0,sizeof(lock));
    lock.l_type=F_WRLCK;
    fcntl(fd,F_SETLKW,&lock);
    printf("\n I have locked the file.\n Press any key to unlock.\n");
    getchar();
    printf("\nRemoving lock.\n");
    lock.l_type=F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    close(fd);
    
}
}
