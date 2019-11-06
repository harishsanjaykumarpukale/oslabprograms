#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<string.h>
void main(){
	DIR *d;
	struct dirent *de;
	struct stat buf;
	int i,j;
	struct passwd *p;
	struct group *g;
	struct tm *t;
	char time[26];
	char P[]="rwxrwxrwx",AP[]="";


	char name[20],cmd[30]="cd /media/student/",path[20]="../../media/student/";
	printf("\n Enter the name of secondary memory device:");
	scanf("%s",name);

	strcat(cmd,name);

	if( ! WIFEXITED(system(cmd))  ){
		printf("\nERROR: in accessing device:)\n");
		exit(0);
	}

	strcat(path,name);
	d=opendir(path);

	while((de=readdir(d))!=NULL){
		if(de->d_type==DT_REG)
			printf("-");

		else if(de->d_type==DT_DIR)
                        printf("d");

		else if(de->d_type==DT_LNK)
                        printf("l");

		else if(de->d_type==DT_SOCK)
                        printf("s");

		else if(de->d_type==DT_CHR)
                        printf("C");

		else if(de->d_type==DT_BLK)
                        printf("b");

		else if(de->d_type==DT_FIFO)
                        printf("p");

		else //(de->d_type==DT_UNKNOWN)
                        printf("u");

		stat(de->d_name,&buf);

		printf( (buf.st_mode & S_IRUSR) ? " r" : " -");
	        printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
        	printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
        	printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
	        printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
        	printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
	        printf( (buf.st_mode & S_IROTH) ? "r" : "-");
        	printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
        	printf( (buf.st_mode & S_IXOTH) ? "x" : "-");




		printf(" %3ld",buf.st_nlink);



		p=getpwuid(buf.st_uid);
		printf(" %8s",p->pw_name);


		g=getgrgid(buf.st_gid);
		printf(" %8s",g->gr_name);

		printf(" %4ld",buf.st_size);


		t=localtime(&buf.st_mtime);
		strftime(time,sizeof(time),"%b %d %H:%M",t);
		printf(" %s",time);

		printf("  %s\n",de->d_name);


	}







}



