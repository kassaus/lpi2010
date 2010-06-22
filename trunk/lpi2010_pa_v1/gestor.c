#include <stdio.h>
#include <string.h>
#include "tipos.h"
#include <stdlib.h>

/* insereInicio recebe ponteiro para a lista correspondente,
 *vai inserir nova estrutura generica em cabeca.primeiro
 */
void insereInicio(CABECA lista, void  *dados){

	PGENERICA item, ptr;

	item = malloc(sizeof(GENERICA));

	if(!item){
		printf("Lamentamos nao foi possivel reservar memoria.");
	} else {

		if ( lista.primeiro == NULL){		//se a lista estiver vazia
			lista.primeiro = item;
			item->seg = NULL;
			item->ant = NULL;
		}
		else {							//se a lista tiver elementos
			ptr = lista.primeiro;
			lista.primeiro = item;
			item->ant = NULL;
			item->seg = ptr;
			ptr->ant = item;
		}
		item->dados = dados;
	}
}

//void idEspectador(CABECA lista_espectador){
//	P_PESSOA tmp;
//	lista_espectador.primeiro->dados = tmp;
//
//	tmp = lista_espectador.primeiro->dados;
//	if(lista_espectador.primeiro == NULL){
//		lista_espectador.id_espectador = 1;
//	} else {
//
//		
//	}
//
//}