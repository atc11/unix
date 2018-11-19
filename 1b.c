#include<stdio.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("Usage:%s <srcfile><destfile>\n",argv[0]);
		return 0;
	}
	if(link(argv[1],argv[2])==-1)
	{
		printf("\nLink error\n");
		return 1;
	}
	printf("File linked\n");
	printf("The inode number of the file is\n");
	char str[100];
	sprintf(str,"ls -i %s %s\n",argv[1],argv[2]);
	system(str);
	return 0;
}
