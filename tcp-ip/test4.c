#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/un.h>
int main()
{
	int server_fd;
	struct sockaddr_un myaddr;
	myaddr.sun_family=AF_UNIX;
	strcpy(myaddr.sun_path,"wsmsockfile");
	char buf[100];
//1.socket
	server_fd=socket(AF_UNIX,SOCK_STREAM,0);
	if(server_fd==-1)
	{
		perror("fail socket");
		exit(-1);
	}
//2.connect
	if((connect(server_fd,(struct sockaddr *)&myaddr,sizeof(myaddr)))==-1)
	{
		perror("fail connect");
		exit(-1);
	}
	read(server_fd,buf,100);
	printf("%s\n",buf);
//3.close
	close(server_fd);
}
