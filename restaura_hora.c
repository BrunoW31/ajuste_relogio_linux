#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <locale.h>
#include <unistd.h>
#define ARQ_DATE "date.sh"

int main(){
	setlocale(LC_ALL, "pt_BR.UTF-8");

	char barra;
	char doispontos;
	int d1 = 0;
	int d2 = 0;
	int d3 = 0;	
	int h1 = 0;
	int h2 = 0;
	int h3 = 0;

	FILE *file = fopen(ARQ_DATE, "w");
	if(file == NULL){
		perror("erro ao manipular arquivo!\n");
		return (1);
	}
	printf("*****************************\n");
	printf("*                           *\n");
	printf("*    AJUSTAR DATA E HORA    *\n");
	printf("*                           *\n");
	printf("*****************************\n");
	printf("Exemplo: \nDATA: 01/01/2025 \nHORA: 20:30:00\n");

	//printf("OBSERVAÇÃO \nNecessário executar como root!\n");
	printf("Digite a data com 6 digitos: ");
	scanf(" %d %c %d %c %d", &d1, &barra, &d2, &barra, &d3);
	printf("Digite a hora com 6 digitos: ");
	scanf(" %d %c %d  %c %d", &h1, &doispontos, &h2, &doispontos, &h3);
	
	if(getuid() != 0){
	printf("Necessário  estar como usuário root\n");
	return (1);	
	}

	fprintf(file, "#Data\n");
	fprintf(file, "date -s %d/%d/%d\n", d3, d2, d1);
	fprintf(file, "#Hora\n");
	fprintf(file, "date -s %d:%d:%d\n", h1, h2, h3);
		
	fclose(file);
	
	system("./date.sh");

	return 0;
}
