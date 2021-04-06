#include"socketfun.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]) {
	int port = 51100;
	char msg[4092];
	if(argc < 2) {
		printf("Please enter hostname.");
		return 0;
	}
	int sockd = request_connection(argv[1], port);
	if(sockd == -1) {
	printf("Failed to connect to the Daemon");	
	return -1;
	}
	
	while(1) {
		fgets(msg,4092,stdin);
		if(send(sockd, msg, 4092, 0) <= 0) {
			printf("Failed to send message or socket closed");
			printf("\n");
			return -1;
		}
		if(recv(sockd,msg,4092,0) <= 0) {
			printf("Failed to receive message or socket closed");
			printf("\n");
			return -1;
		}
		printf("%s", msg);
	}
}
