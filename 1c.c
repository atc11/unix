#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#define BUFF_SIZE 1024

int main(int argc,char *argv[])
{
int srcFD,destFD,nbread,nbwrite;
char *buff[BUFF_SIZE];

if(argc!=3)
{
printf("\n Usage:cp cmd source_file destination_file\n");
exit(EXIT_FAILURE);
}

srcFD=open(argv[1],O_RDONLY,0777);

if(srcFD==-1)
{
printf("\n Error opening file %s error=%d\n",argv[2],errno);
exit(EXIT_FAILURE);
}
destFD=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR|S_IROTH|S_IWOTH,0777);

if(destFD==-1)
{
printf("error eopening file %errno= %d\n",argv[2],errno);
exit(EXIT_FAILURE);
}
while((nbread=read(srcFD,buff,BUFF_SIZE))>0)
{
if(write(destFD,buff,nbread)!=nbread)
{
printf("\n error in writing data is %s\n",argv[2]);

}
if(nbread==-1)
{
printf("\n error in reading data from %s\n",argv[1]);
}
if(close(srcFD)==-1)
{
printf("\n error in closing file %s\n",argv[1]);
}
if(close(destFD)==-1)
{
printf("\n error in closing file %s\n",argv[2]);
}
exit(EXIT_SUCCESS);
	}		
}
