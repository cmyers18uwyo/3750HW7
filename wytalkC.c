#include"socketfun.h"
#include <unistd.h>

int main(int argc, char* argv[]) {
	int port = 51100;
	char msg[4092];
	msg = "Hello World";
	if(argc < 2) {
		printf("Please enter hostname.");
		return 0;
	}
	int sockd = request_connection(argv[1], port);
	send(sockd, msg, 4092,0);

}