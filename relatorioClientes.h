#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

	
void menuRelatorios();
void relatorioClientes(){

  	FILE *fptr;
	short int ch;
	
	fptr = fopen("cliente.txt","r");

	while((ch=fgetc(fptr)) != EOF)
	printf("%c", ch);
	fclose(fptr);
	getchar();
	
	system("pause");
	for (;;) menuRelatorios();
}
