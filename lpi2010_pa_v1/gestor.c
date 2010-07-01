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
void imprimeLista(CABECA *lista, void (*print)()){
	P_GENERICA ptr;
	for ( ptr =lista->primeiro; ptr ; ptr = ptr->seg){
		(*print)(ptr->dados);
	}
}

/* Imprime dados por Id
 
 */
void imprimeEspectadorId(CABECA *lista, int id, void (*print)()){
	P_GENERICA ptr;
	for ( ptr =lista->primeiro; ptr ; ptr = ptr->seg){
		if(pesquisa(lista, comparaIdSala,(int*) id, ORDEM_LISTA_PESSOA)){			
		(*print)(ptr->dados);
		}
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

/*
 * ComparaId compara dois numeros recebidos por parametro. Devolve
 * O se forem iguais ou -1 se forem diferentes.
*/
int comparaNumero(int num1,int num2 ) {
	if( num1 == num2 )
		return 1;
	return 0;
}

P_GENERICA comparaIdEspectador(CABECA *lista_espectadores, int valor){
		P_GENERICA ptr;
		P_PESSOA dados_pessoa;
	dados_pessoa = lista_espectadores->primeiro->dados;
	for(ptr = lista_espectadores->primeiro; ptr; ptr = ptr->seg){
		if(comparaNumero(dados_pessoa->id_pessoa, valor)){
			return ptr;
		}
	}
	return NULL;
}


P_GENERICA comparaIdSala(CABECA *lista_sala, int valor){
	P_GENERICA ptr;
	P_SALA dados_sala;
	dados_sala = lista_sala->primeiro->dados;
	for(ptr = lista_sala->primeiro; ptr; ptr = ptr->seg){
		if(comparaNumero(dados_sala->id_sala, valor)){
			return ptr;
		}
	}
	return NULL;
}


P_GENERICA pesquisa(CABECA *lista, P_GENERICA (*compara)(), void *valor, int index){
	
	if(index == ORDEM_LISTA_PESSOA)	
		return (*compara)(lista, valor);	

	return NULL;
	
}

/*
* Imprime estrutura do cabeçalho, recebe apontador para caractere.
*/
void imprimeCabecalho(char *str, int numero_caracteres, char limite){
	char cabecalho_tmp[100] = "\t\t\t\t**CINELUSO**\n\n";
	strcat(cabecalho_tmp,str);
	system("CLS");
	imprimeLimite(numero_caracteres, limite);
	printf(cabecalho_tmp);
	imprimeLimite(numero_caracteres, limite);

}

/* imrime n caracteres passados por parametro
*/
void imprimeLimite(int numero_caracteres, char limite){
	int i;
	for(i = 0; i < numero_caracteres; i++){
		printf("%c", limite);
	}

}


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