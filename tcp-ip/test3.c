#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
int main()
{
	unlink("wsmsockfile");
	int server_fd,client_fd;
	struct sockaddr_un myaddr;
	struct sockaddr_un client_addr;
	myaddr.sun_family=AF_UNIX;
	int t=sizeof(client_addr);
//creat local file
	strcpy(myaddr.sun_path,"wsmsockfile");
//1.socket
	server_fd=socket(AF_UNIX,SOCK_STREAM,0);
	if(server_fd==-1)
	{
		perror("fail socket");
		exit(-1);
	}
//2.bind
	if((bind(server_fd,(struct sockaddr *)&myaddr,sizeof(myaddr))==-1))
        {
                perror("fail bind");
		exit(-1);
	}
//3.listen
	listen(server_fd,20);
	printf("listening...\n");
//4.accept
	client_fd=accept(server_fd,(struct sockaddr *)&client_addr,&t);
	if(client_fd==-1)
	{
	        perror("fail accept");
		exit(-1);
	}
//5.op
	write(client_fd,"hi i'm wsm",11);
	printf("write to client\n");
	close(server_fd);
	close(client_fd);
}
