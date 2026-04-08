#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct{
char Tipo[50];
char Data[20];
char Hora[20];
char Local[50];
}Ocorrencia;

void cadastrarOcorrencia(Ocorrencia *O){
int opcao;
printf("Digite o Numero da Ocorrencia:\n");
printf("1-Furto\n2-Roubo\n3-Homicidio\n4-Feminicidio\n5-Acidente\n6-Desaparecimento\n7-Nao criminal\n");
scanf("%d", &opcao);
getchar();

switch(opcao) {

	case 1:
		strcpy(O->Tipo,"Furto\n");
	break;
	
	case 2:
		strcpy(O->Tipo,"Roubo\n");
	break;
		
	case 3:
		strcpy(O->Tipo,"Homicidio\n");
	break;
	
	case 4:
		strcpy(O->Tipo,"Feminicidio\n");
	break;
		
	case 5:
		strcpy(O->Tipo,"Acidente\n");
	break;
	
	case 6:
		strcpy(O->Tipo,"Desaparecimento\n");
	break;
		
	case 7:
		strcpy(O->Tipo,"Não criminal\n");
	break;
	
	default:
		printf(O->Tipo,"Invalido\n");
}

printf("Digite a Data do Ocorrido:\n");
	fgets(O->Data, 30, stdin);
	
	
printf("Digite a Hora do Ocorrido:\n");
	fgets(O->Hora, 30, stdin);


printf("Digite o Local do Ocorrido:\n");
	fgets(O->Local, 100, stdin);
}

void mostrarOcorrencia(Ocorrencia O){
printf("\n---dados adicionados até agora---\n");
printf("Tipo: %s\n", O.Tipo);
printf("Data: %s\n", O.Data);
printf("Hora: %s\n", O.Hora);
printf("Local: %s\n",O.Local);
}
int main(){
setlocale(LC_ALL,"portuguese");

Ocorrencia ocorrencia;

cadastrarOcorrencia(&ocorrencia);
mostrarOcorrencia(ocorrencia);

return 0;
}
