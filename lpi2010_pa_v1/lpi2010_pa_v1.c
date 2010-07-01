// teste1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"


int main(int argc, char* argv[])
{
	int i;
	CABECA array_listas[LISTAS];

	/*inicializacao do array de estruturas cabeca
	 */
	memset(array_listas, 0, sizeof(CABECA) * LISTAS);

	/* inicialização do ponteiro para o primeiro elemento da lista e
	 * numero do id do espectador
	 */
	for (i=0; i<LISTAS; i++){
		array_listas[i].id_espectador = 0;
		array_listas[i].id_espectaculo = 0;
		array_listas[i].id_sala = 0;
		array_listas[i].id_reserva = 0;
		array_listas[i].primeiro = NULL;
	}	

	menu(array_listas);

	system("pause");
	return 0;
}

