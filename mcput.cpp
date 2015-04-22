/* echoclient.c - An echo client
 */
/* $begin echoclientmain */
extern "C" {
#include "csapp.h"
};

/*struct dataStruct{
	public:
		dataStruct(string n, string v)
		{
			name = n;
			value = v;	
		}
		string get_name()
		{
			return name;
		}
		string get_value() {
			return value;
		}
		void set_value(string v){
			value = v;
		}
	private:
		string name;
		string value;
		
};*/

int main(int argc, char **argv) 
{
	int clientfd, port, key;
	char *host, buf[MAXLINE];
	rio_t rio;

	if (argc != 4) {
	fprintf(stderr, "usage: mcput <host> <port> <key>\n");
	exit(0);
	}
	host = argv[1];
	port = atoi(argv[2]);
	key = atoi(argv[3]);
	

	clientfd = Open_clientfd(host, port);
	Rio_readinitb(&rio, clientfd);

	while (Fgets(buf, MAXLINE, stdin) != NULL) {
	Rio_writen(clientfd, buf, strlen(buf));
	Rio_readnb(&rio, buf, MAXLINE);
	Fputs(buf, stdout);
	}
	Close(clientfd); //line:netp:echoclient:close
	exit(0);
}
/* $end echoclientmain */
