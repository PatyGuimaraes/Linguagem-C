//Para entender como funciona o tentativa++, ou i++.

#include<stdio.h>

void joga(int x){// aqui são variáveis diferentes da main, por isso usar o mesmo nome pode confundir
	printf("Joga %d\n", x);
	tentativas++;
	printf("Joga %d\n", x);
}

int main(){
	
	int tentativas = 0;
	
	printf("main %d\n", tentativas);
	
	tentativas++;
	printf("main %d\n", tentativas);
	
	tentativas++;
	printf("main %d\n", tentativas);
	
	joga(tentativas);
	
	printf("main %d\n", tentativas);
		
}
