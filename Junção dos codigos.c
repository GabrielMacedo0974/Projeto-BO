#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

//Limpar Tela e Pausar
void limparTela(){
	system("cls  || clear");
}

void pausar(){
	printf("Pressione ENTER para voltar ao menu...");
	getchar();
}

//===Struct dos Dados do Boletim de Ocorrencia===
typedef struct{
int id;
char Cpf[16];
char Tipo[50];
char Data[20];
char Hora[20];
char Local[50];
}Ocorrencia;

//===Struct com os Dados da Vitima===
typedef struct {
char nome[70];
char cpf[16];
char contato[15];
char residencia[50];
} Pessoa;

//===Busca de Pessoa por CPF===
int buscarPessoaPorCpf(Pessoa pessoas[], int total, char cpf[]){
	for(int i=0;i<total;i++){
		if(strcmp(pessoas[i].cpf, cpf) == 0){
			return i;
		}
	}
	return -1;
}

// ===Função para Cadastrar a Vitima===
void cadastrarPessoa(Pessoa *P){
printf("=== Cadastro de usuario ===\n");

printf("Nome: ");
fgets(P->nome, sizeof(P->nome),stdin);
P->nome[strcspn(P->nome,"\n")] = '\0';

printf("CPF: ");
fgets(P->cpf, sizeof(P->cpf),stdin);
P->cpf[strcspn(P->cpf,"\n")] = '\0';

printf("Contato: ");
fgets(P->contato, sizeof(P->contato),stdin);
P->contato[strcspn(P->contato,"\n")] = '\0';

printf("Residencia: ");
fgets(P->residencia, sizeof(P->residencia),stdin);
P->residencia[strcspn(P->residencia,"\n")] = '\0';
}

//===Void de Cadastrar Ocorrencias===
int cadastrarOcorrencia(Ocorrencia *O, Pessoa pessoa[], int totalPessoas, int proximoID){
	
O->id = proximoID;
printf("digite o CPF da pessoa envolvida: ");
fgets(O->Cpf, sizeof(O->Cpf), stdin);
O->Cpf[strcspn(O->Cpf,"\n")] = '\0';

int pos = buscarPessoaPorCpf(pessoa,totalPessoas, O->Cpf);

if(pos == -1){
	printf("Pessoa não encontrada! Por favor realize o cadastro primeiro.\n");
	return 0;
}
	printf("Pessoa encontrada: %s\n", pessoa[pos]. nome);
int opcao;
printf("Digite o Numero da Ocorrencia:\n");
printf("1-Furto\n2-Roubo\n3-Homicidio\n4-Feminicidio\n5-Acidente\n6-Desaparecimento\n7-Nao criminal\n");
scanf("%d", &opcao);
while(getchar() != '\n');

switch(opcao) {

	case 1:
		strcpy(O->Tipo,"Furto");
	break;
	
	case 2:
		strcpy(O->Tipo,"Roubo");
	break;
		
	case 3:
		strcpy(O->Tipo,"Homicidio");
	break;
	
	case 4:
		strcpy(O->Tipo,"Feminicidio");
	break;
		
	case 5:
		strcpy(O->Tipo,"Acidente");
	break;
	
	case 6:
		strcpy(O->Tipo,"Desaparecimento");
	break;
		
	case 7:
		strcpy(O->Tipo,"Nao criminal");
	break;
	
	default:
		strcpy(O->Tipo,"Invalido");
}

//Dados da Ocorrencia Escritos
printf("Digite a Data do Ocorrido:");
	fgets(O->Data, sizeof(O->Data), stdin);
	O->Data[strcspn(O->Data,"\n")] = '\0';
	
printf("Digite a Hora do Ocorrido:");
	fgets(O->Hora, sizeof(O->Hora), stdin);
	O->Hora[strcspn(O->Hora,"\n")] = '\0';

printf("Digite o Local do Ocorrido:");
	fgets(O->Local, sizeof(O->Local), stdin);
	O->Local[strcspn(O->Local,"\n")] = '\0';
	
	return 1;
}

// ===Void de Mostrar Ocorrencias===
void mostrarOcorrencia(Ocorrencia O, Pessoa pessoas [], int totalPessoas){
int pos = buscarPessoaPorCpf(pessoas,totalPessoas,O.Cpf);

printf("\n--- OCORRENCIA ---\n");
printf("ID: %d\n", O.id);
printf("CPF: %s\n", O.Cpf);

if(pos != -1)
	printf("Pessoa: %s\n", pessoas[pos].nome);

printf("\n---Dados Adicionados Até Agora---\n");
printf("Tipo: %s\n", O.Tipo);
printf("Data: %s\n", O.Data);
printf("Hora: %s\n", O.Hora);
printf("Local: %s\n",O.Local);
}

// função para mostrar dados
void mostrarPessoa(Pessoa P) {
printf("\n=== Dados Cadastrados ===\n");
printf("Nome :%s\n", P.nome);
printf("CPF :%s\n", P.cpf);
printf("Contato :%s\n", P.contato);
printf("Residencia :%s\n", P.residencia);
}

//Void Para Salvar Pessoas Cadastradas
void salvarPessoas(Pessoa pessoas[], int total){
	FILE *f = fopen("pessoas.dat","wb");
	if(f == NULL){
		printf("Erro ao Salvar Pessoa!\n");
		return;
	}
	fwrite(&total, sizeof(int), 1, f);
	fwrite(pessoas, sizeof (Pessoa), total, f);
	fclose(f);
}

//Void Para Carregar Pessoas Cadastradas
int carregarPessoas(Pessoa pessoas[]){
	FILE *f = fopen ("pessoas.dat","rb");
	if(f == NULL) return 0;
	
	int total;
	fread(&total, sizeof(int), 1, f);
	fread(pessoas, sizeof(Pessoa), total, f);
	fclose(f);
	return total;
}

//Void Para Salvar Ocorrencias Cadastradas
void salvarOcorrencias(Ocorrencia ocorrencias[], int total){
	FILE *f = fopen("ocorrencias.dat","wb");
	if(f == NULL){
		printf("Erro ao Salvar Ocorrencia!\n");
		return;
	}
	fwrite(&total, sizeof(int), 1, f);
	fwrite(ocorrencias, sizeof (Ocorrencia), total, f);
	fclose(f);
}

//Void Para Carregar Ocorrencia Salva
int carregarOcorrencias(Ocorrencia ocorrencias[]){
	FILE *f = fopen ("ocorrencias.dat","rb");
	if(f == NULL) return 0;
	
	int total;
	fread(&total, sizeof(int), 1, f);
	fread(ocorrencias, sizeof(Ocorrencia), total, f);
	fclose(f);
	return total;
}

//Int do ID da Ocorrencia
int gerarProximoID(Ocorrencia ocorrencias[], int total){
	if(total == 0)
		return 1;
	else
		return ocorrencias[total-1].id + 1; 
}

//Void Deletar Ocorrencia
void removerOcorrencia(Ocorrencia ocorrencias[], int *total){
	int id;
	printf("Digite o ID da Ocorrencia que Deseja Remover: ");
	scanf("%d",&id);
	while(getchar()!='\n');
	
	int encontrado = -1;
	
	for(int i=0;i<*total;i++){
		if(ocorrencias[i].id == id){
			encontrado = i;
			break;
		}
	}
	
	if(encontrado == -1){
		printf("Ocorrencia não encontrada\n");
		return;
	}
	
	for(int i=encontrado;i< *total - 1;i++){
		ocorrencias[i] = ocorrencias[i+1];
	}
	(*total)--;
	
	salvarOcorrencias(ocorrencias,*total);
	
	printf("Ocorrencia removida com sucesso\n");
}


int main () {
setlocale(LC_ALL,"portuguese");

Pessoa pessoas[MAX];
Ocorrencia ocorrencias[MAX];

int totalPessoas = carregarPessoas(pessoas);
int totalOcorrencias = carregarOcorrencias(ocorrencias);

int opcao;

do{
	limparTela();
	
	printf("\n===== MENU =====\n");
	printf("1 - Cadastrar Pessoa\n");
	printf("2 - Cadastrar Ocorrencia\n");
	printf("3 - Listar Pessoas\n");
	printf("4 - Listar Ocorrencias\n");
	printf("5 - Remover Ocorrencia\n");
	printf("0 - Sair\n");
	printf("Escolha: ");
	scanf("%d",&opcao);
	while(getchar()!='\n');
	
	switch(opcao){
	
	case 1:
		limparTela();
		if(totalPessoas < MAX){
			cadastrarPessoa(&pessoas[totalPessoas]);
			totalPessoas++;
			salvarPessoas(pessoas,totalPessoas);
			printf("Pessoa Salva Com Sucesso!\n");
		}else{
			printf("Limite de Pessoas Cadastradas Atingido!\n");
		}
	pausar();
	break;

	case 2:
		limparTela();
		if(totalOcorrencias < MAX){
			
			int novoID = gerarProximoID(ocorrencias, totalOcorrencias);
			
			if (cadastrarOcorrencia(&ocorrencias[totalOcorrencias], pessoas, totalPessoas, novoID)){
			
			totalOcorrencias++;
			salvarOcorrencias(ocorrencias,totalOcorrencias);
			printf("Ocorrencia Salva Com Sucesso!\n");
			printf("\nCodigo do Boletim: %d\n", novoID);
		}
		}else{
			printf("Limite de Ocorrencias Cadastradas Atingido!\n");
		}
	pausar();
	break;
	
	case 3:
		limparTela();
		printf("\n---Lista de Pessoas---\n");
		for(int i=0;i<totalPessoas;i++){
			printf("\nPessoa %d\n", i+1);
			mostrarPessoa(pessoas[i]);
		}
	pausar();	
	break;
		
	case 4:
		limparTela();
		printf("\n===Lista de Ocorrencias===\n");
		for(int i=0;i<totalOcorrencias;i++){
			printf("\nOcorrencia %d\n", i+1);
			mostrarOcorrencia(ocorrencias[i], pessoas, totalPessoas);
		}
	pausar();
	break;
	
	case 5:
		limparTela();
		if(totalOcorrencias == 0){
			printf("Nao existem ocorrencias cadastradas.\n");
			}else{
				removerOcorrencia(ocorrencias, &totalOcorrencias);
			}
			pausar();
			break;
		
	case 0:
		printf("Encerrando Sistema...\n");
		break;
		
	default:
		printf("Opcao Invalida!\n");
}

}while(opcao !=0);

return 0;
}
