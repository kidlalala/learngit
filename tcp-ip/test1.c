#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/un.h>
#include<string.h>
int main()
{
	int server_f,client_f;
	struct sockaddr_in myaddr;
	struct sockaddr_in client_addr;
	myaddr.sin_family=AF_INET;
	myaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	myaddr.sin_port=htons(9000);
	int t=sizeof(client_addr);
//1.socket
	server_f=socket(AF_INET,SOCK_STREAM,0);
	if(server_f==-1)
	{
		perror("fail socket");
		exit(-1);
	}
//2.bind
	if(bind(server_f,(struct sockaddr *)&myaddr,sizeof(myaddr))==-1)
	{
		perror("fail bind");
		exit(-1);
	}
//3.listen
	if(listen(server_f,5)==-1)
	{
		perror("fail listen");
		exit(-1);
	}
	printf("listening...\n");
//4.accept
	client_f=accept(server_f,(struct sockaddr *)&client_addr,&t);
	if(client_f==-1)
	{
		perror("fail accept");
		exit(-1);
	}
//5.op
	char htm[100]="<a href=\"http://www.baidu.com\">baidu</a>";
	send(client_f,htm,strlen(htm),0);
        printf("write to client\n");
	close(server_f);
	close(client_f);
}
//浏览器作为客户端

