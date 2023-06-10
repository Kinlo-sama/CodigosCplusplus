#include<stdio.h>
int main(){
	printf("Digite que figura desea dibujar\n");
	printf("1_Un pino\n");
	printf("2_Un rombo\n");
	int opc;
	scanf("%d", &opc);
	switch(opc){
		case 1:
			printf("00100\n");
			printf("01110\n");
			printf("11111\n");
			printf("00100\n");
			break;	
		case 2:
			printf("00100\n");
			printf("01110\n");
			printf("11111\n");		
			printf("01110\n");		
			printf("00100\n");		
			
	}
}