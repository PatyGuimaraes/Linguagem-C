#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void abertura();
void chuta();
void desenhaforca();
void escolhepalavra();
int acertou();
int chuteserrados();
int enforcou();
int jachutou(char letra);
void adicionapalavra();

char palavrasecreta[MAX];
char chutes[26];
int chutesdados = 0;

void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

void chuta() {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

void desenhaforca(){
	int i;
	int achou;
	int erros = chuteserrados();
	
	printf("   _________            \n");
	printf("  |/         |          \n");
	
	printf("  |         %c%c%c      \n", (erros >= 1 ? '(' : ' '), 
		(erros >=1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));//if ternarios - usamos quando temos uma condição se for verdadeiro ou se for falso.
	printf("  |         %c%c%c       \n", (erros >=2 ? '\\' : ' '),
		(erros >= 2 ? '|' : ' '), (erros >= 2 ? '/' : '  '));
	printf("  |          %c         \n", (erros >=3 ? '|': ' '));
	printf("  |         %c %c       \n", (erros >=4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
	printf("  |                     \n");
	printf("__|____                 \n");
	printf("\n\n");
	
	for(i = 0; i < strlen(palavrasecreta); i++){
		achou = jachutou(palavrasecreta[i]);
		if(achou){
			printf("%c ", palavrasecreta[i]);
		}else{
			printf("_ ");
		}
	}
	printf("\n");
}


void adicionapalavra(){
	char quer, novapalavra[MAX];
	int qtd;
	
	printf("Voce deseja adicionar uma nova palavra no jogo?");
	scanf(" %c", &quer);
	if(quer == 'S'){
		printf("Com letras maiusculas, informe a nova palavra: ");
		scanf("%s", novapalavra);// sem o & porque é uma string
	FILE *f;		
		
	f = fopen("palavras.txt", "r+");// "r+"  ->vamos ler e escreve no final do arquivo
	if(f==0){
		printf("Desculpe, banco de dados nao disponivel\n\n");
		exit(1);// exit 1 representa falso, que o arquivo deu problema para abrir
	}		
	fscanf(f, "%d", &qtd);//lemos a quantidade do arquivo
	qtd++;//incrementamos por conta de adicionar palavra, tem que modificar a quantidade de palavras, mas precisa voltar 
	//fseek recebe 3 parâmetros: o arquivo, quantos bytes ela deve andar, e de onde ela deve começar a andar:	
	fseek(f, 0, SEEK_SET);//para posicionar a seta no inicio novamente, vai pro 0 (primeira posicao do arquivo) e aponta pro começo
	fprintf(f, "%d", qtd);//subscreve a quantidade de palavras 
	//agora pra posicionar no fim do arquivo
	fseek(f, 0, SEEK_END);//subscreve o final do arquivo
	fprintf(f, "\n%s", novapalavra);//escreve a nova palavra no final
			
	fclose(f);
	}
}

void escolhepalavra(){
	FILE *f;
	int qtddepalavras;
	int randomico;
	int i;
	
	f = fopen("palavras.txt", "r");
	if(f==0){
		printf("Desculpe, banco de dados nao disponivel\n\n");
		exit(1); //exit 1 representa falso, que o arquivo deu problema para abrir
	}
	fscanf(f, "%d", &qtddepalavras);//vai salvar o numero de palavras que tá na primeira linha do arquivo
	
	srand(time(0));// esse numero vai de 0 até 2 que são as tres palavras que estão armazenadas no arquivo.
	randomico = rand() % qtddepalavras;//calculo de quantas palavras vai rodar nas palavras que tem no arquivo
	
	for(i=0; i<= randomico; i++){//vai andar 
		fscanf(f, "%s", palavrasecreta);//e guardar na palavra secreta até o for parar
	}
	fclose(f);	
}

int acertou(){
	int i;
	for(i=0; i<strlen(palavrasecreta); i++){
		if(!jachutou(palavrasecreta[i])){
			return 0;//se não chutou a palavra secreta return falso 
		}
	}
	return 1;//se chutou a palavra secreta return verdadeiro - ganhou
}

int chuteserrados(){
	int i, j;
	int existe = 0;
	int erros = 0;
	
	for (i = 0; i < chutesdados; i++){
		existe = 0;
		for(j = 0; j < strlen(palavrasecreta); j++){
			if(chutes[i] == palavrasecreta[j]){
				existe = 1;
				break;
			}
		}
		if(!existe) erros++;
	}
	return erros;//ERROS NÃO PODE SER >=5
}

int enforcou(){
	return chuteserrados() >= 5;
}

int jachutou(char letra) {
    int achou = 0, j;
    for(j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

int main() {

    escolhepalavra();
    abertura();

    do {

        desenhaforca();
        chuta();

    } while (!acertou() && !enforcou());
    //copiei de ASC ART
   if(acertou()){
		printf("\nParabens, voce ganhou!\n\n");
		printf("       ___________       \n");
		printf("      '._==_==_=_.'      \n");
		printf("      .-\\:     /-.      \n");
		printf("      | (|:.   |) |      \n");
		printf("       '-|:.   |-'       \n");
		printf("         \\::.  /        \n");
		printf("          '::. .'        \n");
		printf("            ) (          \n");
		printf("          _.' '._        \n");
		printf("         '_______'       \n\n");
    }else{
		printf("\nPuxa, voce foi enforcado!\n");
		printf("A palavra secreta era **%s** \n\n", palavrasecreta);
		printf("   __________________         \n");
		printf("  /                  \\       \n");
		printf("//                    \\/\\   \n");
		printf("\\|   XXXX    XXXX     | /    \n");
		printf(" |   XXXX    XXXX     |/      \n");
		printf(" |   XXX      XXX     |       \n");
		printf(" |                    |       \n");
		printf(" \\___    XXX       ___/      \n");
		printf("   |\\__  XXX      / |        \n");
		printf("   | |           |  |         \n");
		printf("   |  I I I I I I   |         \n");
		printf("   |   I I I I I    |         \n");
		printf("   \\_             _/         \n");
		printf("     \\___________/           \n");		
    }
    
	//adicionapalavra();

}
