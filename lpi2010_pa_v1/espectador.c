#include "tipos.h"
#include <stdlib.h>
#include <stdio.h>



void leEspectador(){

	static unsigned short int num_espectador;	
	P_PESSOA novo;
	num_espectador++;
	novo = malloc (sizeof(T_PESSOA));
	novo->nome_pessoa = malloc(sizeof (char) * TAMANHO_NOME_PESSOA);
	if(!novo){
		printf("Lamentamos nao foi possivel criar o espectador.");
	} else {
		printf("Id Espectador -> %d\n", num_espectador);
		leString(novo->nome_pessoa,"Nome: ", TAMANHO_NOME_PESSOA);
		leEnum("bi-> 1, ci-> 2, passaporte-> 3\ntipo de Identificacao:",1, 3);
	}

}