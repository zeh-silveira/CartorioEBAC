#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca das strings

int registrar()
{	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char arquivo[40];
	
	printf("-----Registro de novos cadastros-----\n\n");
	printf("ATENÇÃO: para fins de padronização de informações, ao cadastrar, não utilizar caracteres especiais!!!\n");
	printf("\t\t\t\t\t\t   ¯¯¯\n");
	printf("Digite o CPF a ser cadastrado:\n\n");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file, cpf); 
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("\nDigite o nome a ser cadastrado:\n\n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fprintf(file, " ");
	fclose(file);
	
	printf("\nDigite o sobrenome a ser cadastrado:\n\n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fprintf(file, ", ");
	fclose(file);
	
	printf("\nDigite o cargo a ser cadastrado:\n\n");
	scanf("%s", cargo);
	printf("\n");
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file, ". ");
	fclose(file);

	system("pause");	
}

int consultar()
{	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[400];
	
	printf("-----Consulta de cadastros-----\n\n");
	printf("Digite o CPF (somente os números) a ser consultado:\n\n");
	scanf("%s", cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf, "r");
	
	system("cls");
	printf("-----Consulta de cadastros-----\n\n");
	
	if(file == NULL)
	{
		printf("CPF não localizado no sitema.\n\n");
	}
	
	while(fgets(conteudo, 400, file) !=NULL)
	{
		printf("Essas são as informações do usuário (CPF, nome e cargo):\n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("-----Exclusão de cadastros-----\n\n");
	printf("Digite o CPF (somente os números) a ser excluído:\n\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("\nCPF não localizado no sistema.\n\n");
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("\nCPF excluído do sistema.\n\n");
		system("pause");
	}	
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	 	system("cls");
	 	
		printf("-----Cartório da EBAC-----\n\n");
		printf("Escolha a opção desejada; pressione Enter para seguir.\n\n");
		printf("\t1 - Registrar novos cadastros\n");
		printf("\t2 - Consultar cadastros\n");
		printf("\t3 - Excluir cadastros\n\n");
		printf("Opção: ");
		scanf("%d", &opcao);
		
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Opção inválida, gentileza escolher entre 1, 2 ou 3.\n\n");
			system("pause");
			break;	
		}
	}
}
