#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX_SENHA 6
#define MAX_LOGIN 50
#define CLEAN_BUFF do{ int c; while((c = getchar()) != '\n' && c != EOF);}while(0)



int Usuario( FILE* file, char* user, char* senha ) //valida usuario
{
	char tmpLogin[MAX_LOGIN];
	char tmpSenha[MAX_SENHA];

	fscanf(file, "%s", tmpLogin);

	while( !feof(file) )
	{
		if( !strcmp(tmpLogin, user))
		{
			fscanf(file, "%s", tmpSenha);

			if( !strcmp(tmpSenha, senha))
				return 1;
		}
		else
		{
			fscanf(file, "%*s");
		}

		fscanf(file, "%s", tmpLogin);
	}

	return 0;
}

char* CriaSenha()
{
    register int i;

	char* senha = (char*)malloc(sizeof *senha * MAX_SENHA);

    for(i = 0; i < MAX_SENHA; i++)
	{
        senha[i] = getch();
        if(senha[i] == '\r')
            break;
        else
            printf("*");
    }
	senha[i] = '\0';

	return senha;
	}
