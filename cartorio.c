#include <stdio.h>  //comunicação com o usuário
#include <stdlib.h> //alocação de espaço em memória
#include <locale.h> //alocação de texto por região
#include <string.h> //responsável por cuidar das string

int registro() //cadastro de usuários no sistema
{
	//inicio da criação de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //refere-se à string cpf
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo (w significa escrever)
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //altera o arquivo aberto
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()

{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível localizar o arquivo. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file); //fecha o arquivo lido, assim podemos deletá-lo sem precisar reiniciar o programa.
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file != NULL)
	{
		fclose(file);
		remove(cpf);
		printf("O usuário foi deletado com sucesso! \n");
		system("pause");
	}

	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
		
	}
	

}

int alterar()
{
    char novasenha[40];
    
    printf("Digite sua nova senha:");
    scanf("%s",novasenha);
    
    FILE *fp;
    fp=fopen("password.txt","w");
    fprintf(fp,novasenha);
    fclose(fp);
    
    printf("Sua nova senha foi salva com sucesso!\n\n");
    system("pause");
    


}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	char senhadigitada[40]="a";
	char  password[40];
	
	
	printf("###Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha:");
	scanf("%s",senhadigitada);
	
	
    FILE *fp;
    fp=fopen("password.txt","r");
    fgets(password,40,fp);
    
    if(strcmp(senhadigitada,password) == 0)
    {
	
	   for(laco=1;laco=1;)
	   {
    	
			system("cls");

    		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
    	
    		printf("###Cartório da EBAC ###\n\n"); //Início do menu
    		printf("Escolha a opção desejada do menu \n\n");
    		printf("\t1 - Registrar nomes \n");
    		printf("\t2 - Consultar nomes \n");
    		printf("\t3 - Deletar nomes \n");
    		printf("\t4 - Sair do sistema\n");
    		printf("\t5 - Alterar a senha\n\n");
    		printf("Opção:"); //Fim do menu
    	
    		scanf("%d", &opcao); //Armazenando a escolha do usuário
    	
    		system("cls"); //Limpa tudo o que estiver na tela
		
    		switch(opcao) //Início da seleção do menu
    		{
    			case 1:
    			registro(); //chamada de funções
    			break;
			
    			case 2:
    			consulta();
    			break;
			
    			case 3:
    			deletar();
    			break;
    			
    			case 4:
                printf("Obrigado por utilizar o sistema!\n");
                system("pause");
                return 0;
                break;
                
                case 5:
                alterar();
                break;
              
			
    			default:
    			printf("Essa opção não está disponível\n");
    			system("pause");
    			break;
    		} //Fim da seleção
	
		
	
	   }

    }
        else
        {
            printf("senha incorreta\n\n");
            system("pause");
        }


    
}

