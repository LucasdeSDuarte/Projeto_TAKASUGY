#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <iostream>
#include <unistd.h>

void menuCadastros();

void cadastroClientes() // Criação da função cadastro de usuarios 
{
	char nome[50];
	char cpf[11];
	char tel[20];
	int tam, op; 

	FILE *fptr;
	fptr= fopen("cliente.txt", "a+");
	
	do{
		system("cls");

			fflush(stdin);
			printf(" Informe Nome / Razão Social: ");
			fflush(fptr);
			gets(nome);
			
			fflush(stdin);
			printf(" Informe CPF / CNPJ: ");  
			gets(cpf);
			
			fflush(stdin);
			printf(" Informe Telefone: ");
			gets(tel);
			
			tam = strlen(cpf); //validar tamanho de digitos pega a a quantidade e passa pra tam
	
			if(tam == 11){
				//printf(" \nCPF VALIDADO..\n\n");
			} else{
				printf(" \nCPF INVALIDADO.\n\n");
				sleep(2);
			}	
				}while(tam != 11);
				
				
			fflush(fptr);
			fprintf(fptr, "\nNOME:%s\nCPF:%s\nTEL:%s\n", nome, cpf, tel);
			printf("\n");
			printf("\n Dados Gravados com sucesso!\n\n");
			fclose (fptr);
			
			printf("\n");	
			system("pause");
			fflush(stdin);
			menuCadastros();
			
	}


