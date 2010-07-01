#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipos.h"
#include "tipos2.h"


/*leDadosDoFicheiro
recebe
	ponteiro para o array de listas
	filepointer do ficheiro onde ler, já aberto em modo leitura binaria

vai percorrer o ficheiro e gravar em ptr->dados as estruturas que encontrar para cada lista

no caso da estrutura ocupacao, a leitura obriga a mais trabalho
*/
void leDadosDoFicheiro(int array_listas[LISTAS], FILE *fp) {


//	struct temp novo [4];
	int n, i;
//	PTEMP ler;


	FILE *fp = fopen ("ficheiro.bin", "rb");
	ler = (PTEMP) malloc(sizeof (TEMP));
	while (fread (ler, sizeof(TEMP), 1, fp))
	{
		insInicio(ler);
		ler = (PTEMP) malloc(sizeof (TEMP));
	}
	fclose(fp);
}