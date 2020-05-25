//Portscan 
//IGOR PINHEIRO 22-05-2020

#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]){

	int my_socket;
	int my_connection;
	
	int port;
	int port_start = 0;
	int port_finish = 65535;
	char *destiny;
	destiny = argv[1];

	struct sockaddr_in alvo;

	for(port=port_start;port<port_finish;port++){

	my_socket = socket(AF_INET,SOCK_STREAM,0);
	alvo.sin_family = AF_INET;
	alvo.sin_port = htons(port);
	alvo.sin_addr.s_addr = inet_addr(destiny);
	
	my_connection = connect(my_socket, (struct sockaddr *)&alvo, sizeof alvo);

	if(my_connection == 0){
		printf("Port %d - status [--> Open Port <--] *_* \n",port);
		close(my_socket);
		close(my_connection);
	} else {
		close(my_socket);
		close(my_connection);
	}
	}
}
