#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <iostream>
#define MAX_SENHA 15
#define MAX_LOGIN 50
#define CLEAN_BUFF do{ int c; while((c = getchar()) != '\n' && c != EOF);}while(0)

void menuCadastros(); 
char* CriaSenha();

void cadastroUsuario() // Cria��o da fun��o para criar usuarios  e verifica��o de senhas iguais 
{
		FILE* fpIN;

	int option = 0;

	char *user  = (char*)malloc(sizeof *user * MAX_LOGIN);
	char *senha,
		 *confirmaSenha;
		 
		 printf("Usuarios: ");
		 fflush(stdin);
				gets(user);

				do
				{
					printf("Senha: ");
					fflush(stdin);
					senha = CriaSenha();
					printf("\nConfirmacao de senha: ");
					confirmaSenha = CriaSenha();
					printf("\n");

					if( !strcmp(senha, confirmaSenha) )
						break;
					else
						printf("As senhas n�o s�o iguais. Tente novamente.\n");
				}while(1);

				fpIN = fopen("usuarios.db", "a+");
				fprintf(fpIN, "%s %s\n", user, senha);
				fclose(fpIN);

				free(senha);
				free(confirmaSenha);
			
			menuCadastros(); 
	}

