#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<string.h>
int main()
{
	int server_fd,client_fd;
	struct sockaddr_un myaddr;
	struct sockaddr_un clientaddr;
	myaddr.sun_family=AF_UNIX;
	//local  file will be built
	strcpy(myaddr.sun_path,"smksocketfile");
	int clientaddr_len=sizeof(clientaddr);
	//1.socket
	server_fd=socket(AF_UNIX,SOCK_STREAM,0);
	if(server_fd==-1){
		perror("socket error");
		exit(1);
	}
	//2.bind
	if(bind(server_fd,(struct sockaddr *)&myaddr,sizeof(myaddr))==-1)
	{
		perror("bind error");
		exit(1);
	}

	//2.bind
	//3.listen
	if(listen(server_fd,20)==-1)
	{
		perror("listen error");
	}
	printf("listening....\n");
	//4.accept
	client_fd=accept(server_fd,(struct sockaddr *)&clientaddr,&clientaddr_len);
	if(client_fd==-1)
	{
		perror("accept error");
		exit(1);
	}
	//5.op
	write(client_fd,"hello songmengke",16);
	printf("write to client\n");
	//6.close
	close(client_fd);
	close(server_fd);
}
