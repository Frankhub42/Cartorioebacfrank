#include <stdio.h>  //comunica��o com o usu�rio
#include <stdlib.h> //aloca��o de espa�o em mem�ria
#include <locale.h> //aloca��o de texto por regi�o
#include <string.h> //respons�vel por cuidar das string

int registro() //cadastro de usu�rios no sistema
{
	//inicio da cria��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //refere-se � string cpf
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo (w significa escrever)
	fprintf(file, cpf); //salva o valor da vari�vel
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
		printf("N�o foi poss�vel localizar o arquivo. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file); //fecha o arquivo lido, assim podemos delet�-lo sem precisar reiniciar o programa.
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
		printf("O usu�rio foi deletado com sucesso! \n");
		system("pause");
	}

	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
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
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[40]="a";
	char  password[40];
	
	
	printf("###Cart�rio da EBAC ###\n\n");
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
    	
    		printf("###Cart�rio da EBAC ###\n\n"); //In�cio do menu
    		printf("Escolha a op��o desejada do menu \n\n");
    		printf("\t1 - Registrar nomes \n");
    		printf("\t2 - Consultar nomes \n");
    		printf("\t3 - Deletar nomes \n");
    		printf("\t4 - Sair do sistema\n");
    		printf("\t5 - Alterar a senha\n\n");
    		printf("Op��o:"); //Fim do menu
    	
    		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
    	
    		system("cls"); //Limpa tudo o que estiver na tela
		
    		switch(opcao) //In�cio da sele��o do menu
    		{
    			case 1:
    			registro(); //chamada de fun��es
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
    			printf("Essa op��o n�o est� dispon�vel\n");
    			system("pause");
    			break;
    		} //Fim da sele��o
	
		
	
	   }

    }
        else
        {
            printf("senha incorreta\n\n");
            system("pause");
        }


    
}

