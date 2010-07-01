#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tam;

struct temp
{
	int numero;
	char letra[1];
	struct temp *prox;
};

typedef struct temp TEMP;
typedef TEMP *PTEMP;

PTEMP start = NULL;

PTEMP criaTemp()
{
	system ("cls");
	PTEMP novo, ptr;
	novo = (PTEMP) malloc(sizeof(TEMP));/*reserva espaço na memória para o novo elemento da lista*/
	printf("Insira o numero: \n");
	scanf("%d", &novo->numero);
	printf("Insira a letra: \n");
	scanf("%s", &novo->letra[0]);
	novo->prox = NULL;
	return novo;/*devolve a nova sala criada para ser inserida na proxima função*/
}
void insInicio(PTEMP novo)
{
	novo->prox = start;
	start = novo;
}

void read()
{
	system ("cls");
	struct temp novo [4];
	int n, i;
	PTEMP ler;
	FILE *fp = fopen ("ficheiro.bin", "rb");
	ler = (PTEMP) malloc(sizeof (TEMP));
	while (fread (ler, sizeof(TEMP), 1, fp))
	{
		insInicio(ler);
		ler = (PTEMP) malloc(sizeof (TEMP));
	}
	fclose(fp);
}

void gravar()
{
	system ("cls");
	int total=0;
	PTEMP ptr;
	FILE *fp;
	fp = fopen("ficheiro.bin", "wb");
	for (ptr = start; ptr->prox; ptr = ptr->prox)
	{
		fwrite (ptr, sizeof(struct temp), 1, fp);
		total += 1;
	}
	fclose(fp);
	printf("%d", total);
	tam = total;
}
void main()
{
	int opcao;
	do
	{
		printf("\nInserir novo elemento:  [1]\n"
			   "Gravar:                 [2]\n"
			   "Ler do ficheiro:        [3]\n"
			   "Impressao de teste:     [4]\n"
		       "SAIR:                   [0]\n");
		scanf("%d", &opcao);
		switch(opcao)
		{
		case 1:
			PTEMP a;
			a = criaTemp();
			PTEMP ptr;
			insInicio(a);
			for (ptr=start; ptr; ptr = ptr->prox)
			{
				printf("numero: %d letra: %c",ptr->numero, ptr->letra[0]);
			}
			printf("\n");
			break;
		case 2:
			gravar();
			break;
		case 3:
			read();
			break;
		case 4:
			system ("cls");
			for (ptr=start; ptr; ptr = ptr->prox)
			{
				printf("numero: %d letra: %c\n",ptr->numero, ptr->letra[0]);
			}
			printf("\n");
		}
	}
	while(opcao!=0);
}