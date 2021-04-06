#include"socketfun.h"
#include <unistd.h>

int main(int argc, char* argv[]) {
	char hn[256];
	char msg[4092];
	gethostname(hn,256);
	printf("%s", hn);
	int port = 51100;
	int sockd = serve_socket(hn,port);
	accept_connection(sockd);
	recv(sockd, msg, 4092, 0);
	printf("%s", msg);
}