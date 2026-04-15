#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

//============ Estruturas ==============

//Dados do Suspeito 
 typedef struct{
 	 int Id_do_suspeito;
	 char nome[100];
	 char alcunha_vulgo[50];
	 char data_de_nascimento[11];//"xx/xx/xxxx"
     int idade_aprox;
	 char CPF[15];
	 char RG[12];
	 char sexo[1];//M para Masculino e F para Feminino
	 char naturalidade[50];
	 char filiacao[500]; //Nome do pai e da mae 
	 char endereco_suspeito[100]; //Residencial ou de trabalho
	 char profissao[50];
 }Identificacao_basica;
 
 //Descricao detalhada do suspeito
 typedef struct{
 	float altura_aprox;
 	char cor_pele[30];//informar a cor,textura e alterações de pigmentação da pele
 	char cor_olhos[30];//cor,formato
 	char cabelo[50]; //cor,corte,tipo:cacheado,ondulado,liso,careca
 	char porte_fisico[50];//magro,atletico,obeso
 	char sinais_particulares[200];//tatuagens-local e desenho,cicatrizes,piercings,barba,bigode,uso de oculos
 	char vestuario[150];//descricao das roupas,cores,marca de bone/tenis,mochilas
 	char vicios_habitos[500];//Se e fumante,canhoto,possui tiques nervosos ou modo de falar especifico(girias,sotaque)
 }Caracteristicas_fisicas ;
 
 //Dados de localizacao e contato do suspeito
 typedef struct{
 	char telefone_celular[20];//formato (xx) 9xxxx-xxxx
 	char redes_sociais[50];
 	char locais_frequentes[100];//onde costuma ser visto
 	
 }localizacao_e_contato_do_suspeito;
 	
//Dados da fuga
typedef struct{
	char modo_de_evasao[50];//especificar se foi a pe,em veiculo roubado ou em transporte publico
	int tem_cumplices;//S/N
	char nome_ou_apelido_dos_cumplices[500];
	char papel_dos_cumplices[200];//Se era o motorista,se deu cobertura ou se forneceu o veiculo
	char descricao_cumplices[500];//descricao das caracteristicas dos envolvidos(ex.:roupa,cor e formato dos olhos,tipo de corte de cabelo,cor,bigode,etc)
	char direcao_fuga[100];//para onde fugiu,localizacao de fuga 
	char ponto_de_referencia_de_fuga[100];//ex:passou em frente ao posto de saude
	char ultima_visualizacao[100];//cruzamento exato ou ultima camera que registrou 
}Informacao_da_fuga;

  //Dados sobre o veiculo(se envolvido)
typedef struct{
 	char tipo_de_veiculo[20];//carro,moto,caminhao,etc
 	char placa[10];
 	char marca[30];//informar fabricante:Fiat,Ford,etc
 	char modelo[50];//informar o nome do carro:Uno,Gol,Onix,etc
 	char cor[20];//cor predominante
 	int ano;
 	char estado_de_conservacao[50];//muito velho,pintura nova 
 	char nivel_insulfilm[10];//pelicula de controle solar
    char tipo_pelicula[30];//comum,espelhada
 	char estado_pelicula[50];//rasgado,com bolhas 
 	char detalhe_das_rodas[50];//sem calota,roda esportiva
 	char caracteristicas_especificas[100];//adesivos,amassados,farois queimados
 }Dados_do_veiculo;
 
 //Dinamica do envolvimento
 typedef struct{
	 char relacao_com_a_vitima[50];//conhecido,vizinho,ex-parceiro,desconhecido
	 char papel_no_crime[50];//autor,coautor,mandante,receptador
	 char armamento_utilizado_no_crime[50];//arma de fogo,arma branca,sem arma
	 char forma_de_acao[60];//agressivo,calmo 
	 char objetos_envolvidos[500];//itens roubados, danificados, etc.
	 char relato_detalhado_do_crime[2000];//descricao de como o crime ocorreu	
 }Dinamica_do_envolvimento;		 	 

   //==========Estrutura Principal=============
  typedef struct{
	int id;
	Identificacao_basica identificacao;  
	Caracteristicas_fisicas caracteristicas;  
	localizacao_e_contato_do_suspeito  localizacao;  
	Informacao_da_fuga fuga;
	Dados_do_veiculo veiculo;  
	Dinamica_do_envolvimento dinamica_do_envolvimento;  
  }Registro_do_suspeito;

  //Vetor global 
  Registro_do_suspeito registros[100];

  //Variável para controlar quantos registros já foram preenchidos
  int contador_registro = 0;

  //==========Funções Auxiliares===============

 void limpartela() {
   #ifdef _WIN32
	system("cls");
   #else
	system("clear");
   #endif
 }
 void pausar() {
	printf("\nPressione ENTER para continuar...");
	getchar();
 }

 //======Sitema========
 void inicializarSistema(){
	int i;
	contador_registro = 0;

	for (i = 0; i < 100; i ++){
		registros [i].identificacao.Id_do_suspeito = 0;
	}
    printf("Dados do Suspeito inicializado com sucesso!\n");
 }

 void listarTodosSuspeitos(){
	printf("\n===== RELATÓRIO DE SUSPEITOS CADASTRADOS =====\n");

	if(contador_registro == 0) {
		printf("Nenhum registro encontrado.\n");
		return;
	}

	for (int i = 0; i< contador_registro; i++){
		printf("\n----------Ficha do Suspeito ID: %03d----------\n", registros[i]. identificacao.Id_do_suspeito);
		printf("NOME:          %s\n", registros[i].identificacao.nome);
		printf("CPF:           %s\n", registros[i]. identificacao.CPF);
		printf("-------------------------------------------------\n");
	}
}

 void registrarSuspeito(){
	if (contador_registro >= 100){
		printf("Limite de registros atingido!\n");
		return;
	}

	Registro_do_suspeito s;
    char possui_info;//Variável para controlar se tudo será opcional

	//Id automático
	s.identificacao.Id_do_suspeito = contador_registro +1 ;

	printf("\n-----CADASTRO (Id:%d)-----\n", s.identificacao.Id_do_suspeito);

	printf("Existem infomacoes sobre o suspeito para registro? (S/N):");
	scanf("%c", &possui_info);
	getchar();

	if(possui_info == 's' || possui_info == 'S'){
		
	//===========Dados do suspeito===========

	printf("\nDigite o nome do suspeito:");
	fgets(s.identificacao.nome, 100 , stdin );
	s.identificacao.nome[strcspn(s.identificacao.nome, "\n")] = 0;

	printf("\nDigite alcunha/vulgo:");
	fgets(s.identificacao.alcunha_vulgo, 50 , stdin );
	s.identificacao.alcunha_vulgo[strcspn(s.identificacao.alcunha_vulgo, "\n")] = 0;

	printf("\nDigite a data de nascimento:");
	fgets(s.identificacao.data_de_nascimento, 11 , stdin );
	s.identificacao.data_de_nascimento[strcspn(s.identificacao.data_de_nascimento, "\n")] = 0;

	printf("\nDigite a idade aproximada:");
	scanf("%d", &s.identificacao.idade_aprox );
	while(getchar() !='\n');

	printf("\nDigite o CPF:");
	fgets(s.identificacao.CPF, 15 , stdin );
	s.identificacao.CPF[strcspn(s.identificacao.CPF, "\n")] = 0;

	printf("\nDigite o RG:");
	fgets(s.identificacao.RG,12 , stdin );
	s.identificacao.RG[strcspn(s.identificacao.RG, "\n")] = 0;

	printf("\nDigite o sexo (M/F):");
	fgets(s.identificacao.sexo, 2 , stdin );
	s.identificacao.CPF[strcspn(s.identificacao.CPF, "\n")] = 0;

	printf("\nDigite a naturalidade:");
	fgets(s.identificacao.naturalidade, 50, stdin );
	s.identificacao.naturalidade[strcspn(s.identificacao.naturalidade, "\n")] = 0;

	printf("\nDigite a filiacao:");
	fgets(s.identificacao.filiacao, 500 , stdin );
	s.identificacao.filiacao[strcspn(s.identificacao.filiacao, "\n")] = 0;

	printf("\nDigite o endereco:");
	fgets(s.identificacao.endereco_suspeito, 100 , stdin );
	s.identificacao.endereco_suspeito[strcspn(s.identificacao.endereco_suspeito, "\n")] = 0;

	printf("\nDigite a profissao:");
	fgets(s.identificacao.profissao, 50 , stdin );
	s.identificacao.profissao[strcspn(s.identificacao.profissao, "\n")] = 0;

	//==========Descricao detalhada do suspeito============

	printf("\nDigite a altura:");
	scanf("%f", &s.caracteristicas.altura_aprox);
	while (getchar()!='\n');
	
	printf("\nInfome a cor e o fator cutaneo:");
	fgets(s.caracteristicas.cor_pele, 30 , stdin );
	s.caracteristicas.cor_pele[strcspn(s.caracteristicas.cor_pele, "\n")] = 0;

	printf("\nDescreva as caracteristicas oculares:");
	fgets(s.caracteristicas.cor_olhos, 30 , stdin );
	s.caracteristicas.cor_olhos[strcspn(s.caracteristicas.cor_olhos, "\n")] = 0;

	printf("\nDescreva as caracteristicas capilares:");
	fgets(s.caracteristicas.cabelo, 50 , stdin );
	s.caracteristicas.cabelo[strcspn(s.caracteristicas.cabelo, "\n")] = 0;

	printf("\nDescreva o porte fisico:");
	fgets(s.caracteristicas.porte_fisico, 40 , stdin );
	s.caracteristicas.porte_fisico[strcspn(s.caracteristicas.porte_fisico, "\n")] = 0;

	printf("\nDescreva os sinais particulares:");
	fgets(s.caracteristicas. sinais_particulares, 200 , stdin );
	s.caracteristicas.sinais_particulares[strcspn(s.caracteristicas.sinais_particulares, "\n")] = 0;

	printf("\nDescreva o vestuario:");
	fgets(s.caracteristicas.vestuario, 150 , stdin );
	s.caracteristicas.vestuario[strcspn(s.caracteristicas.vestuario, "\n")] = 0;

	printf("\nDescreva os vicios e habitos:");
	fgets(s.caracteristicas.cor_olhos, 30 , stdin );
	s.caracteristicas.cor_olhos[strcspn(s.caracteristicas.cor_olhos, "\n")] = 0;

    //========Localização e contato===========

	printf("\nInfome o numero do telefone/celular:");
	fgets(s.localizacao.telefone_celular, 20 , stdin );
	s.localizacao.telefone_celular[strcspn(s.localizacao.telefone_celular, "\n")] = 0;

	printf("\nInfome as redes sociais:");
	fgets(s.localizacao.redes_sociais, 50 , stdin );
	s.localizacao.redes_sociais[strcspn(s.localizacao.redes_sociais, "\n")] = 0;

	printf("\nInfome os locais frequentados:");
	fgets(s.localizacao.locais_frequentes, 100 , stdin );
	s.localizacao.locais_frequentes[strcspn(s.localizacao.locais_frequentes, "\n")] = 0;
   
	//===========Dados da fuga==========

    char tem_cumplices;
	printf("\nSuspeito agiu com cumplices? == (S/N):");
	scanf("%c", &tem_cumplices );
	getchar();

	if(tem_cumplices == 's' || tem_cumplices == 'S'){
		printf("Infome no nome ou apelido dos cumplices:");
		fgets(s.fuga.nome_ou_apelido_dos_cumplices,200, stdin);
		s.fuga.nome_ou_apelido_dos_cumplices [strcspn(s.fuga.nome_ou_apelido_dos_cumplices,"\n")] ='\0';

		printf("Qual era o papel dos cumplices? (Ex: motorista,olheiro, armado):");
		fgets(s.fuga.papel_dos_cumplices,200, stdin);
		s.fuga.papel_dos_cumplices [strcspn(s.fuga.papel_dos_cumplices,"\n")] ='\0';

		printf("Descreva a atuacaodos cumplices:");
		fgets(s.fuga.descricao_cumplices,500, stdin);
		s.fuga.descricao_cumplices [strcspn(s.fuga.descricao_cumplices,"\n")] ='\0';
	}
	else{
		strcpy(s.fuga.nome_ou_apelido_dos_cumplices, "Nenhum detectado");
		strcpy(s.fuga.papel_dos_cumplices, "Nao se aplica");
		strcpy(s.fuga.descricao_cumplices, "acao soitaria");
	}

	char sabe_fuga;
	printf("\nSabe a direcao da fuga? (S/N):  ");
	scanf("%c", &sabe_fuga );
	getchar();

	if(sabe_fuga == 's' || sabe_fuga == 'S'){
		printf("Informe a direcao:");
		fgets(s.fuga.direcao_fuga,100, stdin);
		s.fuga.direcao_fuga [strcspn(s.fuga.direcao_fuga,"\n")] ='\0';

		printf("Informe o ponto de referencia:");
		fgets(s.fuga.ponto_de_referencia_de_fuga,100, stdin);
		s.fuga.ponto_de_referencia_de_fuga [strcspn(s.fuga.ponto_de_referencia_de_fuga,"\n")] ='\0';

		printf("Informe o local da ultima visualizacao(Ex.: Em frente a camera do mercado x):");
		fgets(s.fuga.ultima_visualizacao,100, stdin);
		s.fuga.ultima_visualizacao [strcspn(s.fuga.ultima_visualizacao,"\n")] ='\0';
	}
	else{
		strcpy(s.fuga.direcao_fuga, "Direcao ignorada");
		strcpy(s.fuga.ponto_de_referencia_de_fuga, "Nao informado");
		strcpy(s.fuga.ultima_visualizacao, "acao capturada");
	}

	//-------Dados sobre o veículo----------

    char tem_veiculo;
	printf("\nHouve algum veiculo envolvido? == (S/N):");
	scanf("%c", &tem_veiculo);
	getchar();

	if(tem_veiculo == 's' || tem_veiculo == 'S'){
		printf("Informe o tipo do veiculo:");
		fgets(s.veiculo.tipo_de_veiculo,20, stdin);
		s.veiculo.tipo_de_veiculo [strcspn(s.veiculo.tipo_de_veiculo,"\n")] ='\0';

		printf("Informe a placa:");
		fgets(s.veiculo.placa,10, stdin);
		s.veiculo.placa [strcspn(s.veiculo.placa,"\n")] ='\0';

		printf("Informe a marca:");
		fgets(s.veiculo.marca,30, stdin);
		s.veiculo.marca[strcspn(s.veiculo.marca,"\n")] ='\0';

		printf("Informe o modelo:");
		fgets(s.veiculo.modelo,50, stdin);
		s.veiculo.modelo[strcspn(s.veiculo.modelo,"\n")] ='\0';

		printf("Informe a cor:");
		fgets(s.veiculo.cor,20, stdin);
		s.veiculo.cor[strcspn(s.veiculo.cor,"\n")] ='\0';

		printf("Informe o ano:");
		scanf("%d", &s.veiculo.ano);
		getchar();

		printf("Descreva o estado de conservacao:");
		fgets(s.veiculo.estado_de_conservacao,50, stdin);
		s.veiculo.estado_de_conservacao[strcspn(s.veiculo.estado_de_conservacao,"\n")] ='\0';

		printf("Informe o nivel do insulfilm: (Nivel de transparencia)");
		fgets(s.veiculo.nivel_insulfilm,10, stdin);
		s.veiculo.nivel_insulfilm[strcspn(s.veiculo.nivel_insulfilm,"\n")] ='\0';

		printf("Informe o tipo de pelicula (Ex.: Comum, espelhada, de seguranca):");
		fgets(s.veiculo.tipo_pelicula,30, stdin);
		s.veiculo.tipo_pelicula[strcspn(s.veiculo.tipo_pelicula,"\n")] ='\0';

		printf("Informe o estado da pelicula: (Ex.: Rasgada, com bolhas)");
		fgets(s.veiculo.estado_pelicula,50, stdin);
		s.veiculo.estado_pelicula[strcspn(s.veiculo.estado_pelicula,"\n")] ='\0';

		printf("Informe os detalhes da roda:(Ex.: Roda esportiva, sem calota)");
		fgets(s.veiculo.detalhe_das_rodas,50, stdin);
		s.veiculo.detalhe_das_rodas[strcspn(s.veiculo.detalhe_das_rodas,"\n")] ='\0';

		printf("Informe as caracteristicas especificas (Ex.: Adesivos, amassados):");
		fgets(s.veiculo.caracteristicas_especificas,10, stdin);
		s.veiculo.caracteristicas_especificas[strcspn(s.veiculo.caracteristicas_especificas,"\n")] ='\0';
	}
	else{
		strcpy(s.veiculo.tipo_de_veiculo, "Nenhum");
		strcpy(s.veiculo.placa, "Nao se aplica");
		strcpy(s.veiculo.marca, "Nao se aplica");
		strcpy(s.veiculo.modelo, "Nao se aplica");
		strcpy(s.veiculo.cor, "Nao se aplica");
		s.veiculo.ano = 0;
		strcpy(s.veiculo.estado_de_conservacao, "Nao se aplica");
		strcpy(s.veiculo.nivel_insulfilm, "Nao se aplica");
		strcpy(s.veiculo.tipo_pelicula, "Nao se aplica");
		strcpy(s.veiculo.estado_de_conservacao, "Nao se aplica");
		strcpy(s.veiculo.detalhe_das_rodas, "Padrao");
		strcpy(s.veiculo.caracteristicas_especificas, "Nenhuma");
	}

	//------Dinâmica do envolvimento-------

	printf("\nInforme a relacao com a vitima:");
	fgets(s.dinamica_do_envolvimento.relacao_com_a_vitima, 50 , stdin );
	s.dinamica_do_envolvimento.relacao_com_a_vitima[strcspn(s.dinamica_do_envolvimento.relacao_com_a_vitima, "\n")] = 0;

	printf("\nInforme o papel no crime: (Ex.: Autor, coautor, mandante)");
	fgets(s.dinamica_do_envolvimento.papel_no_crime, 50 , stdin );
	s.dinamica_do_envolvimento.papel_no_crime[strcspn(s.dinamica_do_envolvimento.papel_no_crime, "\n")] = 0;

	printf("\nInforme o armamento utilizado no crime:(Ex.: Arma de fogo, arma branca, sem arma)");
	fgets(s.dinamica_do_envolvimento.armamento_utilizado_no_crime, 50 , stdin );
	s.dinamica_do_envolvimento.armamento_utilizado_no_crime[strcspn(s.dinamica_do_envolvimento.armamento_utilizado_no_crime, "\n")] = 0;

	printf("\nInforme a forma de acao (Ex.: Agressivo, calmo):");
	fgets(s.dinamica_do_envolvimento.forma_de_acao, 60, stdin );
	s.dinamica_do_envolvimento.forma_de_acao[strcspn(s.dinamica_do_envolvimento.forma_de_acao, "\n")] = 0;

	printf("\nInforme os objetos envolvidos (Ex.: Itens roubados, danificados, etc.):");
	fgets(s.dinamica_do_envolvimento.objetos_envolvidos, 500 , stdin );
	s.dinamica_do_envolvimento.objetos_envolvidos[strcspn(s.dinamica_do_envolvimento.objetos_envolvidos, "\n")] = 0;
	}
	else
	{
		printf("\n[AVISO]: Prosseguindo sem dados detalhados do suspeito.\n");

		//Preenchimento padrão para evitar erros no relatório final
		strcpy(s.identificacao.nome,"Não identificado");
		s.identificacao.idade_aprox = 0;
		strcpy(s.fuga.modo_de_evasao, "N/A");
	}
 registros[contador_registro] = s;
 contador_registro++;
 printf("\n>>> Suspeito registrado com sucesso!<<<\n");
 pausar();//para o usuário conseguir ler a mensagem
 }

 






  int main() {
     int opcao;
    

    if  (!telamenu()) return 0; 

	do{
		limpartela();
		printf("\n\033[1;34m=========== MENU ===========\033[0m\n");
		printf("1. Cadrastrar Novo Suspeito\n");
		printf("2. Consultar Suspeito(por CPF/Nome)\n");
		printf("3. Listar todos os suspeitos\n");
		printf("4. Atualizar Dados\n");
		printf("5. Vincular Suspeito a Ocorrencia\n");
		printf("0. Sair\n");
		scanf("%d", &opcao);
		getchar();

		switch(opcao) {
			case 1: registrarSuspeito(); break;
			case 2: consultarsuspeito(); break;
			case 3: ListarTodosSuspeito(); break;
			case 4: atualizardados(); break;
			case 5: vincularSuspeitoOcorrencia(); break;
			case 0: 




		}






	}while (opcao !=0);//Repetição do menu
	
	





  }
