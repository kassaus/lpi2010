#include "tipos.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>


P_RESERVA leReserva(CABECA *lista){
	P_RESERVA novo;
	CABECA *lista_reserva = &lista[ORDEM_LISTA_RESERVA];
	P_GENERICA espectador;
	P_PESSOA dados_espectador;
	novo = malloc(sizeof(T_RESERVA));

	if(!novo){
		printf("Lamentamos nao foi possivel criar o espectador.");
		system("PAUSE");
		return 0;

	} else {
		++lista_reserva->id_reserva;
		novo->id_reserva = lista_reserva->id_reserva;
		printf("Id-> %d\n", novo->id_reserva);
		espectador = pesquisa(&lista[ORDEM_LISTA_PESSOA], comparaIdEspectador, (int*)leUnsigned("Insira o Id do espectador: "), ORDEM_LISTA_PESSOA);
		if(espectador){
			dados_espectador = espectador->dados;
			system("CLS");
			imprimeCabecalho("\t\t\t\tReservas\n", 80, '*');
			imprimeEspectadorId(&lista[ORDEM_LISTA_PESSOA],dados_espectador->id_pessoa, imprimeEspectador);	
		} else{
			if(lista[ORDEM_LISTA_PESSOA].primeiro == NULL){
				printf("Nao existem espectadores!\n");
				--lista_reserva->id_reserva;
			}else{
			printf("Id nao encontrado!\nInsira primeiro o espectador.\n");
			--lista_reserva->id_reserva;
			}
		}

	}
	return novo;

}