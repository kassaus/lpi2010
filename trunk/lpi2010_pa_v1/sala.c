#include "tipos.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

/* le uma sala 
* recebe ponteiro para a lista de salas
* solicita ao utilizador todos os dados necessarios ao preenchimento dos campos para uma sala
* retorna um ponteiro para a nova sala.
*/
P_SALA leSala(CABECA *lista_sala){
	P_SALA novo;
	novo = malloc(sizeof(T_SALA));

	if(!novo){
		printf("Lamentamos nao foi possivel criar o espectador.");
		system("PAUSE");
		return 0;

	} else {
		++lista_sala->id_sala;
		novo->id_sala = lista_sala->id_sala;
		printf("Id-> %d\n", novo->id_sala);
		leString(novo->nome_sala, "Nome da sala: ", MAX_NOME_SALA);
		leString(novo->desc_sala, "Descricao da sala: ", MAX_DESC_SALA);
		novo->filas = leUnsignedShort("Insira o numero de filas: ");
		novo->lugares = leUnsignedShort("Insira o numero de lugares: ");
	}
	return novo;
}

/* imprime sala
* recebe um ponteiro para sala
*/
void imprimeSala(P_SALA sala){
	printf("\n");
	imprimeLimite(80,'-');
	printf("Id-> %d\n", sala->id_sala);
	printf("Nome-> %s\n", sala->nome_sala);
	printf("Descricao-> %s\n", sala->desc_sala);
	printf("%hu filas por %hu lugares\n", sala->filas, sala->lugares);
	printf("Total de lugares da sala %s-> %d\n", sala->nome_sala, (sala->filas * sala->lugares));
	imprimeLimite(80,'-');
}