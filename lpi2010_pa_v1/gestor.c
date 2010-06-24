#include <stdio.h>
#include <string.h>
#include "tipos.h"
#include <stdlib.h>

/* insereInicio recebe ponteiro para a lista correspondente,
*vai inserir nova estrutura generica em cabeca.primeiro
*/
void insereInicio(CABECA *lista, void  *dados){

	P_GENERICA item, ptr;

	item = malloc(sizeof(GENERICA));

	if(!item){
		printf("Lamentamos nao foi possivel reservar memoria.");
	} else {

		if ( lista->primeiro == NULL){		//se a lista estiver vazia
			lista->primeiro = item;
			item->seg = NULL;
			item->ant = NULL;
		}
		else {							//se a lista tiver elementos
			ptr = lista->primeiro;
			lista->primeiro = item;
			item->ant = NULL;
			item->seg = ptr;
			ptr->ant = item;
		}
		item->dados = dados;
	}
}

/* Imprime uma lista
 * recebe um ponteiro para a lista e um ponteiro para função 
 */
void imprime(CABECA *lista, void (*print)()){
	P_GENERICA ptr;
	for ( ptr =lista->primeiro; ptr ; ptr = ptr->seg){
		(*print)(ptr->dados);
	}
}

/*
*Lê data recebe um ponteiro para um array a imprimir no ecrâ, devolve uma data dd-mm-aaaa.
*/
T_DATA lerData(char *str){
	T_DATA tmp;
	printf(str);
	tmp.dia = leUnsignedShort("Insira o dia:");
	tmp.mes = leUnsignedShort("Insira o mes:");
	tmp.ano = leUnsignedShort("Insira o ano:");
	return tmp;
}



//P_GENERICA pesquisa(CABECA *lista, void *valor){
//	P_GENERICA ptr;
//	for(ptr = lista->primeiro; ptr; ptr->seg){
//
//	}
//}


//void idEspectador(CABECA lista_espectador){
//	P_PESSOA tmp;
//	lista_espectador.primeiro->dados = tmp;
//
//	if(lista_espectador.primeiro == NULL){
//		lista_espectador.id_espectador = 1;
//	} else {
//
//		
//	}
//
//}