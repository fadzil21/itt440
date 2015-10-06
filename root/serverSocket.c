#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
	int sock, mysock;
	struct sockaddr_in server;
	char buff[1024];
	
	sock = socket (AF_INET, SOCK_STREAM, 0);
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(1026);


	bind(sock,(struct sockaddr *)&server, sizeof(server));
	
	listen(sock, 5);

	do
	{
		mysock = accept(sock, (struct sockaddr *)0, 0);
		
		memset(buff, 0, sizeof(buff));
		
		close(mysock);
	}while(1);
	
	
	return 0;
}
