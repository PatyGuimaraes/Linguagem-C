#include <stdio.h>
#include <math.h>
int main(){
	int numero, i;
	int multiplicacao;
	
	printf("Digite o numero que deseje a impressao de sua tabuada de multiplicacao: ");
	scanf("%d", &numero);
	
	for(i=1; i<=10; i++){
		multiplicacao = numero*i;
		printf("\t%d x %d = %d\n", numero, i, multiplicacao);
	}

}
