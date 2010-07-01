#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipos.h"
#include "tipos2.h"


/*escreveDadosNoFicheiro
recebe
	ponteiro para a estrutura cabeca
	filepointer do ficheiro onde gravar, já aberto em modo escrita binaria
	tamanho da estrutura a gravar no ficheiro

vai percorrer a lista e gravar as estruturas apontadas por ptr->dados no ficheiro

*/
void escreveDadosNoFicheiro(P_CABECA p_cabeca, FILE *fp, size_t tamanho_estrutura ){

	PGENERICA ptr;
	int gravado;

	for (ptr =p_cabeca->primeiro ; ptr->seg; ptr =ptr->seg){
		fwrite (ptr->dados , tamanho_estrutura, 1, fp);
		gravado++;
	}

	printf("Gravadas %d estruturas em ficheiro\n", gravado);
	
	return;
}