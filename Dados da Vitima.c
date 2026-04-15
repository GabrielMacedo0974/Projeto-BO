#include <stdio.h>
#include <string.h>

// struct com os dados
typedef struct {
char nome[70];
char cpf[16];
char contato[15];
char residencia[50];
} Pessoa;

// função para cadastrar
void cadastrarPessoa(Pessoa *P){
printf("=== Cadastro de usuario ===\n");

printf("nome: ");
fgets(P->nome, sizeof(P->nome),stdin);
P->nome[strcspn(P->nome,"\n")] = '\0';

 printf("CPF ");
fgets(P->cpf, sizeof(P->cpf),stdin);
P->cpf[strcspn(P->cpf,"\n")] = '\0';

 printf("contato: ");
fgets(P->contato, sizeof(P->contato),stdin);
P->contato[strcspn(P->contato,"\n")] = '\0';

 printf("residencia: ");
fgets(P->residencia, sizeof(P->residencia),stdin);
P->residencia[strcspn(P->residencia,"\n")] = '\0';
}

// função para mostrar dados
void mostrarPessoa(Pessoa P) {
printf("\n=== Dados cadastrados ===\n");
printf("Nome :%s\n", P.nome);
printf("CPF :%s\n", P.cpf);
printf("contato :%s\n", P.contato);
printf("residencia :%s\n", P.residencia);
}

int main () {
Pessoa pessoa;

cadastrarPessoa(&pessoa);
mostrarPessoa(pessoa);

return 0;
}
