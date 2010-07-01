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
 * ComparaId compara dois numeros recebidos por parametro. 
 * Devolve 1 se forem iguais ou 0 se forem diferentes.
 */
int comparaNumero(int num1,int num2 ) {
	if( num1 == num2 )
		return 1;
	return 0;
}

/*
 * ComparaNome compara duas strings recebidas por parametro. 
 * Devolve 1 se forem iguais ou 0 se forem diferentes.
 */
int comparaNome( char *nome1, char *nome2 ) {
	if(strcmp(nome1, nome2))
		return 0;
	return 1;
}



/* Pesquisa em espectaculo
 *
 */
int pesquisaEspectaculoId(P_ESPECTACULO dados, int *valor){	
	return ( comparaNumero(dados->id_espectaculo , *valor) );
}

int pesquisaEspectaculoNome(P_ESPECTACULO dados, char *valor){	
	return ( comparaNome(dados->nome_espectaculo , valor) );
}


/* Pesquisa em Sala
 *
 */
int pesquisaSalaId(P_SALA dados, int *valor){
	return ( comparaNumero(dados->id_sala , *valor) );
}


int pesquisaSalaNome(P_SALA dados, char *valor){	
	return ( comparaNome(dados->nome_sala , valor) );
}


/* Pesquisa em Pessoa
 *
 */
int pesquisaPessoaId(P_PESSOA dados, int *valor){
	return ( comparaNumero(dados->id_pessoa , *valor) );
}


int pesquisaPessoaNome(P_PESSOA dados, char *valor){	
	return ( comparaNome(dados->nome_pessoa , valor) );
}

/* Pesquisa em Reserva
 *
 */
int pesquisaReservaId(P_RESERVA dados, int *valor){
	return ( comparaNumero(dados->id_reserva , *valor) );
}

int pesquisaReservaIdPessoa(P_RESERVA dados, int *valor){
	return ( comparaNumero(dados->id_pessoa.int_id , *valor) );
}

int pesquisaReservaIdExibicao(P_RESERVA dados, int *valor){
	return ( comparaNumero(dados->id_exibicao.int_id , *valor) );
}


/* Pesquisa em Exibicao
 *
 */
int pesquisaExibicaoId(P_EXIBICAO dados, int *valor){
	return ( comparaNumero(dados->id_exibicao , *valor) );
}

int pesquisaExibicaoIdEspectaculo(P_EXIBICAO dados, int *valor){
	return ( comparaNumero(dados->id_espectaculo.int_id , *valor) );
}

int pesquisaExibicaoIdSala(P_EXIBICAO dados, int *valor){
	return ( comparaNumero(dados->id_sala.int_id , *valor) );
}

int pesquisaExibicaoIdOcupacao(P_EXIBICAO dados, int *valor){
	return ( comparaNumero(dados->id_ocupacao.int_id , *valor) );
}

/* Pesquisa em Ocupacao
 *
 */
int pesquisaOcupacaoId(P_OCUPACAO dados, int *valor){
	return ( comparaNumero(dados->id_ocupacao , *valor) );
}


P_GENERICA pesquisa(P_GENERICA primeiro, P_GENERICA (*compara)(), void *valor){

	P_GENERICA ptr, ret=NULL;
	int i;

	for (ptr= primeiro; ptr; ptr= ptr->seg){
		if (ret= (*compara)(ptr->dados, valor) ) break;		
	}

	return ret;		
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
