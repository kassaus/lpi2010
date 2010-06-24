#include "tipos.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

/* le um espectaculo 
* recebe ponteiro para a lista de espectaculos
* solicita ao utilizador todos os dados necessarios ao preenchimento dos campos para um espectaculo
* retorna um ponteiro para o novo espectaculo.
*/
P_ESPECTACULO leEspectaculo(CABECA *lista_espectaculo){
	P_ESPECTACULO novo;
	novo = malloc(sizeof(T_ESPECTACULO));

	if(!novo){
		printf("Lamentamos nao foi possivel criar o espectador.");
		system("PAUSE");
		return 0;

	} else {
		++lista_espectaculo->id_espectaculo;
		novo->id_espectaculo = lista_espectaculo->id_espectaculo;
		printf("Id-> %d\n", novo->id_espectaculo);
		leString(novo->nome_espectaculo, "Nome do espectaculo-> ", MAX_NOME_ESPECTACULO);
		leString(novo->desc_espectaculo, "Descricao do espectaculo-> ", MAX_DESC_ESPECTACULO);
		novo->sessao = leEnum("manha-> 1, tarde-> 2, noite-> 3: ", 1, 3);
		novo->data_inicial = lerData("Data inicial do espectaculo\n");
		novo->data_final = lerData("Data final do espectaculo\n");
	}
	return novo;
}

/* imprime espectaculo
* recebe um ponteiro para o espectaculo
*/
void imprimeEspectaculo(P_ESPECTACULO espectaculo){
	char *tipo_sessao[] =  { "manha", "tarde", "noite"};
	printf("\n");
	imprimeLimite(80,'-');
	printf("Id-> %d\n", espectaculo->id_espectaculo);
	printf("Nome-> %s\n", espectaculo->nome_espectaculo);
	printf("Descricao-> %s", espectaculo->desc_espectaculo);
	printf("Sessao-> %s\n", tipo_sessao[espectaculo->sessao - 1]);
	printf("Data inicio: %hu\\%hu\\%hu\n", espectaculo->data_inicial.dia, espectaculo->data_inicial.mes, espectaculo->data_inicial.ano);
	printf("Data inicio: %hu\\%hu\\%hu\n", espectaculo->data_final.dia, espectaculo->data_final.mes, espectaculo->data_final.ano);
	imprimeLimite(80,'-');	
}