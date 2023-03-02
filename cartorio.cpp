#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca responsável por cuidar das string

int registro() // fun��o responsavel por cadastrar os usu�rios no sistema
{
	// inicio da cria��o de varriaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa�es do usu�rio
	scanf("%s", cpf); // %s se refere as strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir  arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se enconta no sistema!\n");
		system("pause");
	}
}


int main()
{
	int opcao=0; //definindo variaveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("\t Cart�rio da EBAC \n\n");
	printf("Login do administrador! \n\n Digite a sua senha: ");
	scanf("%s", senhadigitada);
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		for(laco=1;laco=10;)
		{
			system("cls");
		
 	   		setlocale(LC_ALL, "portuguese"); //definindo linguagem
    	
			printf("\t Cart�rio da EBAC \n\n"); //inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: "); //fim do menu
		
			scanf("%d", &opcao); //armazenando escokha do usuario
	
			system("cls"); // responsavel por limpar a tela
	
			switch(opcao) // inicio da sele�o do menu
			{
				case 1:
				registro(); // chama a fun��o registro
    			break;
    		
    			case 2:
    			consulta(); // chama a fun��o consulta
				break;
			
				case 3:
				deletar(); // chama a fun��o deletar
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Essa op��o n�o est� disponivel\n");
				system("pause");
				break;
			}
		}
    }
    else
    	printf("Senha incorreta!");
}
