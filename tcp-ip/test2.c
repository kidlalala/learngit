#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<arpa/inet.h>
int main()
{
	int server_f;
	struct sockaddr_in myaddr;
	myaddr.sin_family=AF_INET;
	myaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	myaddr.sin_port=htons(9000);
	char buf[55];
//1.socket
	server_f=socket(AF_INET,SOCK_STREAM,0);
	if(server_f==-1)
	{
		perror("fail socket");
		exit(-1);
	}
//2.connect
        if(connect(server_f,(struct sockaddr *)&myaddr,sizeof(myaddr))==-1)
	{	
		perror("fail connect");
		exit(-1);
	}
	recv(server_f,buf,12,0);
	printf("%s\n",buf);
//3.close
	close(server_f);
}
