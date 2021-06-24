#include<stdio.h>

int main() {
	int numeros[3];
	// declarando um ponteiro que aponta para
	// o mesmo lugar que o array/ponteiro numeros
//	int i;
	int* ponteiro = numeros;
	
	numeros[0] = 10;
	numeros[1] = 20;
	numeros[2] = 30;
	
	for(int i = 0; i < 3; i++) {

		printf("%d \n", numeros[0]);
		
		//repare na soma que fazemos com o ponteiro
		printf("%d \n\n", *(ponteiro + 1));
		
		printf("\n");
		
	}
}
