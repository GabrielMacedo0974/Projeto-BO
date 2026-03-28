#include <stdio.h>
#include <locale.h>
#include <string.h>
int main(){
setlocale(LC_ALL,"PORTUGUESE");

	char Tipo[50];
	char Data[20];
	char Hora[20];
	char Local[50];
	int opcao;
	
	printf("Digite o Numero da Ocorrencia:\n");
		printf("1-Furto\n2-Roubo\n3-Homicidio\n4-Feminicidio\n5-Acidente\n6-Desaparecimento\n7-Nao criminal\n");
			scanf("%d", &opcao);
		
	switch(opcao) {
		
		case 1:
			strcpy(Tipo,"Furto\n");
		break;
		
		case 2:
			strcpy(Tipo,"Roubo\n");
		break;
			
		case 3:
			strcpy(Tipo,"Homicidio\n");
		break;
		
		case 4:
			strcpy(Tipo,"Feminicidio\n");
		break;
			
		case 5:
			strcpy(Tipo,"Acidente\n");
		break;
		
		case 6:
			strcpy(Tipo,"Desaparecimento\n");
		break;
			
		case 7:
			strcpy(Tipo,"Não criminal\n");
		break;
		
		default:
			printf("Invalido\n");
		
	}
	getchar();
	
	printf("Digite a Data do Ocorrido:\n");
		fgets(Data, 30, stdin);
		
		
	printf("Digite a Hora do Ocorrido:\n");
		fgets(Hora, 30, stdin);
	
	
	printf("Digite o Local do Ocorrido:\n");
		fgets(Local, 100, stdin);
		
	printf("\n---dados adicionados até agora---\n");
		printf("Tipo: %s\n", Tipo);
		printf("Data: %s\n", Data);
		printf("Hora: %s\n", Hora);
		printf("Local: %s\n", Local);
	
 return 0;
}
