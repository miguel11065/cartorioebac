#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsÃ¡vel por cuidar das string

int registro() // função responsavel por cadastrar os usuários no sistema
{
	// inicio da criação de varriaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informaões do usuário
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
		printf("Não foi possivel abrir  arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
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
		printf("O usuário não se enconta no sistema!\n");
		system("pause");
	}
}


int main()
{
	int opcao=0; //definindo variaveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("\t Cartório da EBAC \n\n");
	printf("Login do administrador! \n\n Digite a sua senha: ");
	scanf("%s", senhadigitada);
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		for(laco=1;laco=10;)
		{
			system("cls");
		
 	   		setlocale(LC_ALL, "portuguese"); //definindo linguagem
    	
			printf("\t Cartório da EBAC \n\n"); //inicio do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: "); //fim do menu
		
			scanf("%d", &opcao); //armazenando escokha do usuario
	
			system("cls"); // responsavel por limpar a tela
	
			switch(opcao) // inicio da seleão do menu
			{
				case 1:
				registro(); // chama a função registro
    			break;
    		
    			case 2:
    			consulta(); // chama a função consulta
				break;
			
				case 3:
				deletar(); // chama a função deletar
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Essa opção não está disponivel\n");
				system("pause");
				break;
			}
		}
    }
    else
    	printf("Senha incorreta!");
}
