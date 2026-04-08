#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Dados do Suspeito pessoa fisica
typedef struct{
int Id_do_suspeito;
char nome[100];
char alcunha_vulgo[50];
char data_de_nascimento[11];//"xx/xx/xxxx"
int idade_aprox;
char CPF[15];
char RG[12];
char sexo[20];
char naturalidade[100];
char filiacao[500]; //Nome do pai e da mae
char endereco[100]; //Residencial ou de trabalho
char profissao[50];
}Identificacao_basica_pessoa_fisica;

//Descricao detalhada do suspeito
typedef struct{
float altura_aprox;
char cor_pele[30];
char cor_olhos[30];//cor,formato
char cabelo[50]; //cor,corte,tipo:cacheado,ondulado,liso,careca
char porte_fisico[50];//magro,atletico,obeso
char sinais_particulares[200];//tatuagens-local e desenho,cicatrizes,piercings,barba,bigode,uso de oculos
char vestuario[150];//descricao das roupas,cores,marca de bone/tenis,mochilas
char vicios_habitos[500];//Se e fumante,canhoto,possui tiques nervosos ou modo de falar especifico(girias,sotaque)
}Caracteristicas_fisicas;

//Dados de localizacao e contato
typedef struct{
char endereco_do_ocorrido[70];//bairro,cidade
char telefone_celular[20];//formato (xx) 9xxxx-xxxx
char redes_sociais[50];
char locais_frequentes[100];//onde costuma ser visto
char testemunhas_ou_vitimas[500];//informar dados de testesmunhas ou vitimas

}Dados_de_localizacao_e_contato;

//Dados da pessoa juridica envolvida (o vinculo)
typedef struct{
char razao_social[100];//nome social de registro da empresa
char nome_fantasia[100];//nome comercial/nome da fachada
char cnpj[20];//Cadastro Nacional da Pessoa Juridica- o "CPF" da empresa
char inscricao_estadual[20];//registro para pagamento de ICMS
char inscricao_municipal[20];//registro na prefeitura
char data_de_abertura[11];//data de fundacao da empresa. ex.: DD/MM/AAAA
char cnae[100];//Ramo de atividade.(O que a empresa faz legalmente)
char porte_da_empresa[50];//tamanho da empresa(MEI,Micro,Multinacional)
char endereco_da_sede[150];//endereco completo da matriz/sede
char telefone_fixo[20];//telefone comercial de contato
char email_corp[100];//E-mail oficial da empresa
char site_redes[100];//site oficial ou perfis em redes sociais
char nome_responsavel[100];//nome do socio ou administrador principal
char cargo_responsavel[50];//cargo de quem responde pela empresa
char vinculo_crime[500];//como a empresa foi usada no ocorrido
}Dados_PJ;

//Dados da fuga
typedef struct{
char modo_de_evasao[50];//especificar se foi a pe,em veiculo roubado ou em transporte publico
int tem_cumplices;//1 para sim, 0 para nao
char nome_ou_apelido_dos_cumplices[500];
char papel_dos_cumplices[200];//Se era o motorista,se deu cobertura ou se forneceu o veiculo
char descricao_cumplices[500];//descricao das caracteristicas dos envolvidos(ex.:roupa,cor e formato dos olhos,tipo de corte de cabelo,cor,bigode,etc)
char direcao_fuga[100];//para onde fugiu,localizacao de fuga
char ponto_de_referencia_de_fuga[100];//ex:passou em frente ao posto de saude
char ultima_visualizacao[50];//cruzamento exato ou ultima camera que registrou
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
}Dinamica_do_envolvimento;

//Dados do ocorrido
typedef struct{
char natureza_do_ocorrido[50];//roubo,furto,dano,trafico,etc
char status_do_fato[20];//se o crime foi concluido ou interrompido
char data_e_hora[20];//ex.: "xx/xx/xxxx xx:xx"
char endereco_completo_do_local[100];//rua,numero,bairro,cidade,UF
char tipo_de_local[50];//via publica,residencia,comercio,interior de veiculo
char ponto_de_referencia[50];//esquina, nome da loja proxima,etc
char relato_detalhado_do_crime[2000];//descricao de como o crime ocorreu
char tipo_de_objeto_envolvido[50];//celular,dinheiro,joia,documento,etc
char descricao_do_objeto[50];//marca,modelo,cor,estado de conservacao
char identificacao_tecnica_do_objeto[50];//IMEI de celular ou numero de serie
int quantidade_de_objetos;
float valor_do_prejuizo;
char meio_empregado[50];//arrombamento,chave falsa,escalada,destreza
char uso_de_violencia_ou_ameaca[50];//sim ou nao e qual tipo
char preservacao_do_local[10];//se o local foi isolado para a policia
char vestigios_deixados_no_local[70];//objetos esquecidos pelo suspeito,sangue,etc
char existencia_de_cameras_de_monitoramento[5];//sim ou nao
}Dados_do_ocorrido;

// Estrutura principa/mestra
typedef struct{
Identificacao_basica_pessoa_fisica identificacao;
Caracteristicas_fisicas caracteristicas;
Dados_de_localizacao_e_contato localizacao_e_contato;
Dados_PJ PJ;
Informacao_da_fuga fuga;
Dados_do_veiculo veiculo;
Dinamica_do_envolvimento dinamica_do_envolvimento;
Dados_do_ocorrido ocorrido;
}Registro_do_suspeito;

int main(){
int status= 1, id=0, c;
Registro_do_suspeito registros[99];

while(status){
    printf("Escolha:");
	int escolha;
	scanf("%d", &escolha);
	
	switch(escolha){
		case 1:
		    //Dados do Suspeito 
		    registros[id].identificacao.Id_do_suspeito= id;
		    printf("registro Id_do_suspeito: %d", id + 1);
		    float total_de_registros= 0
		        
                for(int i = 0; i < 99; i++){
		    	while((c= getchar()) != '\n' && c!=EOF);
		    	
		    	printf("Digite o nome do suspeito:");
				char nome[100];
				fgets(nome, sizeof(nome), stdin);
				
				printf("Digite o alcunha/vulgo:");
                char alcunha_vulgo[50];
                fgets(alcunha_vulgo, sizeof(alcunha_vulgo), stdin);
                
                printf("Digite a data de nascimento:");
                char data_de_nascimento[11];
                fgets(data_de_nascimento, sizeof(data_de_nascimento), stdin);
                
                printf("Digite a idade aproximada:");
                int idade_aprox;
                scanf("%d", &idade_aprox);
                getchar();
                
                printf("Digite o CPF:");
                char CPF[15];
                fgets(CPF, sizeof(CPF), stdin);
                
                printf("Digite o RG:");
                char RG[12];
                fgets(RG, sizeof(RG), stdin);
                
                printf("Digite o sexo:");
                char sexo[20];
                fgets(sexo, sizeof(sexo), stdin);
                
                printf("Digite a naturalidade:");
                char naturalidade[100];
                fgets(naturalidade, sizeof(naturalidade), stdin);
                
                printf("Digite a filiacao:");
                char filiacao[500]; 
                fgets(filiacao, sizeof(filiacao), stdin);
				 
				printf("Digite o endereco:"); 
                char endereco[100]; 
                fgets(endereco, sizeof(endereco), stdin);
                
                printf("Digite a profissao:");
                char profissao[50];
                fgets(profissao, sizeof(profissao), stdin);
                
                 //Descricao detalhada do suspeito
                
                 printf("Digite a altura aproximada:");
                char altura_aprox[10];
                fgets(altura_aprox, sizeof(altura_aprox), stdin);
                
                printf("Digite a cor de pele:");
                char cor_pele[30];
                fgets(cor_pele, sizeof(cor_pele), stdin);
                
                printf("Digite a cor dos olhos:");
                char cor_olhos[30];
                fgets(cor_olhos, sizeof(cor_olhos), stdin);
                
                printf("Digite o cabelo:");
                char cabelo[50]; 
                fgets(cabelo, sizeof(cabelo), stdin);
                
                printf("Digite o porte fisico:");
                char porte_fisico[50];
                fgets(porte_fisico, sizeof(porte_fisico), stdin);
                
                printf("Digite sinais particulares:");
                char sinais_particulares[200];
                fgets(sinais_particulares, sizeof(sinais_particulares), stdin);
                
                printf("Digite vestuario:");
                char vestuario[150];
                fgets(vestuario, sizeof(vestuario), stdin);
                
                printf("Digite vicios/habitos:");
                char vicios_habitos[500];
                fgets(vicios_habitos, sizeof(vicios_habitos), stdin);
                
                
                 //Dados de localizacao e contato

				printf("Digite o endereco do ocorrido:");
                char endereco_do_ocorrido[70];
                fgets(endereco_do_ocorrido, sizeof(endereco_do_ocorrido), stdin);
                
                printf("Digite o telefone/celular:");
            	char telefone_celular[20];
            	fgets(telefone_celular, sizeof(telefone_celular), stdin);
            	
            	printf("Digite as redes sociais: ");
                char redes_sociais[50];
                fgets(redes_sociais, sizeof(redes_sociais), stdin);
                
                printf("Digite os locais frequentes:");
                char locais_frequentes[100];
                fgets(locais_frequentes, sizeof(locais_frequentes), stdin);
                
                printf("Digite testemunhas ou vitimas:");
             	char testemunhas_ou_vitimas[500];
             	fgets(testemunhas_ou_vitimas, sizeof(testemunhas_ou_vitimas), stdin);
             	
             	//Dados da pessoa jurídica envolvida (o vínculo)
             	
                printf("Digite razao social:");
             	char razao_social[100];
             	fgets(razao_social, sizeof(razao_social), stdin);
             	
 	            printf("Digite nome fantasia:");
                char nome_fantasia[100];
                fgets(nome_fantasia, sizeof(nome_fantasia), stdin);  
                  
                printf("Digite CNPJ:");
                char cnpj[20];
                fgets(cnpj, sizeof(cnpj), stdin);
                
                printf("Digite inscricao estadual:"); 
                char inscricao_estadual[20];
                fgets(inscricao_estadual, sizeof(inscricao_estadual), stdin);
                
                printf("Digite inscricao municipal:"); 
                char inscricao_municipal[20];
                fgets(inscricao_municipal, sizeof(inscricao_municipal), stdin);
                
                printf("Digite data de abertura:"); 
                char data_de_abertura[11];
                fgets(data_de_abertura, sizeof(data_de_abertura), stdin);
                
                printf("Digite CNAE:");  
                char cnae[100];
                fgets(cnae, sizeof(cnae), stdin);
                
                printf("Digite porte da empresa:"); 
                char porte_da_empresa[50];
                fgets(porte_da_empresa, sizeof(porte_da_empresa), stdin);
                
                printf("Digite endereco da sede:"); 
                char endereco_da_sede[150];
                fgets(endereco_da_sede, sizeof(endereco_da_sede), stdin);
                
                printf("Digite telefone fixo:"); 
                char telefone_fixo[20];
                fgets(telefone_fixo, sizeof(telefone_fixo), stdin);
                
                printf("Digite email corp:"); 
                char email_corp[100];
                fgets(email_corp, sizeof(email_corp), stdin);
                
                printf("Digite site redes:"); 
                char site_redes[100];
                fgets(site_redes, sizeof(site_redes), stdin);
                
                printf("Digite nome responsavel:"); 
                char nome_responsavel[100];
                fgets(nome_responsavel, sizeof(nome_responsavel), stdin);
                
                printf("Digite cargo responsavel:"); 
            	char cargo_responsavel[50];
            	fgets(cargo_responsavel, sizeof(cargo_responsavel), stdin);
            	
                printf("Digite vinculo crime:");	
                char vinculo_crime[500];
             	fgets(vinculo_crime, sizeof(vinculo_crime), stdin);
        	
             	
             	//Dados da fuga
             	
             	printf("Digite o modo de evasao:");
             	char modo_de_evasao[50];
             	fgets(modo_de_evasao, sizeof(modo_de_evasao), stdin);
             	
             	printf("Digite tem cumplices?");
                int tem_cumplices;
                scanf("%d", &tem_cumplices);
                getchar();
                
                printf("Digite nome ou apelido dos cumplices:");
                char nome_ou_apelido_dos_cumplices[500];
                fgets(nome_ou_apelido_dos_cumplices, sizeof(nome_ou_apelido_dos_cumplices), stdin);
                
                printf("Digite papel dos cumplices:");
                char papel_dos_cumplices[200];
                fgets(papel_dos_cumplices, sizeof(papel_dos_cumplices), stdin);
                
                printf("Digite descricao dos cumplices:");
                char descricao_cumplices[500];
                fgets(descricao_cumplices, sizeof(descricao_cumplices), stdin);
                
                printf("Digite direcao da fuga:");
                char direcao_fuga[100];
                fgets(direcao_fuga, sizeof(direcao_fuga), stdin);
                
                printf("Digite ponto de referencia:");
                char ponto_de_referencia_de_fuga[100];
                fgets(ponto_de_referencia_de_fuga, sizeof(ponto_de_referencia_de_fuga), stdin);
                
                printf("Digite ultima visualizacao:");
                char ultima_visualizacao[50];
                fgets(ultima_visualizacao, sizeof(ultima_visualizacao), stdin);
                
                
                //Dados sobre o veiculo(se envolvido)
                
                printf("Digite tipo de veiculo:");
                char tipo_de_veiculo[20];
                fgets(tipo_de_veiculo, sizeof(tipo_de_veiculo), stdin);
                
                printf("Digite placa:");
                char placa[10];
                fgets(placa, sizeof(placa), stdin);
                
                printf("Digite marca:");
                char marca[30];
                fgets(marca, sizeof(marca), stdin);
                
                printf("Digite modelo:");
                char modelo[50];
                fgets(modelo, sizeof(modelo), stdin);
                
                printf("Digite cor:");
                char cor[20];
                fgets(cor, sizeof(cor), stdin);
                
                printf("Digite ano:");
                int ano;
                scanf("%d", &ano);
                getchar();
                
                printf("Digite estado de conservacao:");
            	char estado_de_conservacao[50];
            	fgets(estado_de_conservacao, sizeof(estado_de_conservacao), stdin);
            	
            	printf("Digite nivel de insulfilm:");
            	char nivel_insulfilm[10];
                fgets(nivel_insulfilm, sizeof(nivel_insulfilm), stdin);
            	 
                printf("Digite tipo de pelicula:");
                char tipo_pelicula[30];
            	fgets(tipo_pelicula, sizeof(tipo_pelicula), stdin);
            	
            	printf("Digite estado da pelicula:");
                char estado_pelicula[50]; 
                fgets(estado_pelicula, sizeof(estado_pelicula), stdin);
                
                printf("Digite detalhe das rodas:");
                char detalhe_das_rodas[50];
                fgets(detalhe_das_rodas, sizeof(detalhe_das_rodas), stdin);
                
                printf("Digite caracteristicas especificas:");
                char caracteristicas_especificas[100];
                fgets(caracteristicas_especificas, sizeof(caracteristicas_especificas), stdin);
                
                
                //Dinamica do envolvimento
                
                printf("Digite relacao_com _a _ vitima:");
                char relacao_com_a_vitima[50];
                fgets(relacao_com_a_vitima, sizeof(relacao_com_a_vitima), stdin);
                
                printf("Digite papel no crime:");
                char papel_no_crime[50];
                fgets(papel_no_crime, sizeof(papel_no_crime), stdin);
                
                printf("Digite armamento utilizado no crime:");
                char armamento_utilizado_no_crime[50];
                fgets(armamento_utilizado_no_crime, sizeof(armamento_utilizado_no_crime), stdin);
                
                printf("Digite forma de acao:");
                char forma_de_acao[60];
                fgets(forma_de_acao, sizeof(forma_de_acao), stdin);
                
                //Dados do ocorrido
                
                printf("Digite natureza do ocorrido:");
                char natureza_do_ocorrido[50];
                fgets(natureza_do_ocorrido, sizeof(natureza_do_ocorrido), stdin);
                
                printf("Digite status do fato:");
                char status_do_fato[20];
                fgets(status_do_fato, sizeof(status_do_fato), stdin);
                
                printf("Digite data e hora:");
                char data_e_hora[20];
                fgets(data_e_hora, sizeof(data_e_hora), stdin);
                
                printf("Digite endereco completo do local:");
                char endereco_completo_do_local[100];
                fgets(endereco_completo_do_local, sizeof(endereco_completo_do_local), stdin);
                
                printf("Digite tipo de local:");
                char tipo_de_local[50];
                fgets(tipo_de_local, sizeof(tipo_de_local), stdin);
                
                printf("Digite  ponto de referencia:");
                char ponto_de_referencia[50];
                fgets(ponto_de_referencia, sizeof(ponto_de_referencia), stdin);
                
                printf("Digite relato detalhado do crime:");
                char relato_detalhado_do_crime[2000];
				fgets(relato_detalhado_do_crime, sizeof(relato_detalhado_do_crime), stdin);
				
				printf("Digite  tipo de objeto envolvido:");	
                char tipo_de_objeto_envolvido[50];
                fgets(tipo_de_objeto_envolvido, sizeof(tipo_de_objeto_envolvido), stdin);
                
                printf("Digite descricao do objeto:");
                char descricao_do_objeto[50];
                fgets(descricao_do_objeto, sizeof(descricao_do_objeto), stdin);
                
                printf("Digite identificacao tecnica do objeto:");
                char identificacao_tecnica_do_objeto[50];
                fgets(identificacao_tecnica_do_objeto, sizeof(identificacao_tecnica_do_objeto), stdin);
                
                printf("Digite quantidade de objetos:");
                int quantidade_de_objetos;
                scanf("%d", &quantidade_de_objetos);
                
                printf("Digite valor do prejuizo:");
                float valor_do_prejuizo;
                scanf("%f", &valor_do_prejuizo);
                getchar();
                
                printf("Digite meio empregado:");
                char meio_empregado[50];
                fgets(meio_empregado, sizeof(meio_empregado), stdin);
                
                printf("Digite uso de violencia ou ameaca?");
                char uso_de_violencia_ou_ameaca[50];
                fgets(uso_de_violencia_ou_ameaca, sizeof(uso_de_violencia_ou_ameaca), stdin);
                
                printf("Digite preservacao do local?");
                char preservacao_do_local[10];
                fgets(preservacao_do_local, sizeof(preservacao_do_local), stdin);
                
                printf("Digite vestigios deixados no local:");
                char vestigios_deixados_no_local[70];
                fgets(vestigios_deixados_no_local, sizeof(vestigios_deixados_no_local), stdin);
                
                printf("Digite existencia de cameras de monitoramento?");
                char existencia_de_cameras_de_monitoramento[5];
                fgets(existencia_de_cameras_de_monitoramento, sizeof(existencia_de_cameras_de_monitoramento), stdin);
                
                Suspeito suspeito = {.Idade = idade};
                strcpy(suspeito. Nome, nome);
                
                registros[id].suspeito]i= suspeito;
                
                total+= idade * nome;
                
                printf("Ha outros dados que auxiliem na identificacao? [s/n]");
                char novodado;
                scanf("%c", &novodado);
                
                if (novodado != 's'){
                 break;	
				} 
			 
				}
	}
	d++;
		case 2:
			for(int i = 0; )
            break;
        case 3:
            status= 0;
            break;
 


}

 return 0;	 
}