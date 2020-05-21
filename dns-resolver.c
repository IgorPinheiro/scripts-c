//Programa ensinado no curso da DESEC
//IGOR PINHEIRO : 21/05/20

#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
	
	if(argc <= 1){
		printf("Modo de uso: ./dns-resolver sinte.alvo.com.br\n");
		return 0;
	}else {
	
		struct hostent *alvo = gethostbyname(argv[1]);
		

		if (alvo == NULL){
			printf("Ocorreu um erro :'(\n");
		} else {
		
			printf("IP: %s\n",inet_ntoa(*((struct in_addr *)alvo->h_addr)));
		}
}
}
