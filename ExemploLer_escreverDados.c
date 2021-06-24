#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE* f;
		char c;

	f = fopen("palavras.txt", "r");
	while(!feof(f)) {
    	c = fgetc(f);    
    	printf("Char %c\n", c);
	}
	
}



