#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
main(int argc,char *argv[3])
{
	int fd,i;
	char buf[2];
	fd=open(argv[1],O_RDONLY,0777);
	if(fd==-argc)
{
		printf("File open error\n");

}
	else
	{
		while((i=read(fd,buf,1))>0)
		{	
		printf("%c",buf[0]);
	}
	close(fd);
	}
}
