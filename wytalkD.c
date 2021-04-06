#include"socketfun.h"
#include <unistd.h>

int main(int argc, char* argv[]) {
	char hn[256];
	char msg[4092];
	gethostname(hn,256);
	int port = 51100;
	int sockd = serve_socket(hn,port);
	if(sockd == -1) {
		printf("Failed to create Socket");
		return -1;
	}
	int sockd2 = accept_connection(sockd);
	if(sockd2 == -1) {
		printf("Failed to connect to client");
		return -1;
	}
	
	while(1) {
		if(recv(sockd2, msg, 4092, 0) <= 0) {
			printf("Failed to receive message or socket closed");
			printf("\n");
			return -1;
		}
		printf("%s", msg);
		fgets(msg,4092,stdin);
		if(send(sockd2, msg, 4092, 0) <= 0) {
			printf("Failed to send message or socket closed");
			printf("\n");
			return -1;
		}
	}
}
