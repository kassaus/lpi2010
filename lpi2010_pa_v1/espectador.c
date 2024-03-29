#include "tipos.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>


/* le um espectador 
* recebe ponteiro para a lista de espectadores
* solicita ao utilizador todos os dados necessarios ao preenchimento dos campos para um espectador
* retorna um ponteiro para o novo espectador.
*/
P_PESSOA leEspectador(CABECA *lista_espectador){
	P_PESSOA novo;	
	novo = malloc (sizeof(T_PESSOA));
	if(!novo){
		printf("Lamentamos nao foi possivel criar o espectador.");
		system("PAUSE");
		return 0;

	} else {
		++lista_espectador->id_espectador;
		novo->id_pessoa = lista_espectador->id_espectador;
		printf("Id Espectador -> %d\n", novo->id_pessoa);
		leString(novo->nome_pessoa,"Nome: ", MAX_PESSOA);
		novo->identificacao.tipo_identificacao = leEnum("bi-> 1, cc-> 2, passaporte-> 3\ntipo de Identificacao:",1, 3);
		switch(novo->identificacao.tipo_identificacao)
		{
		case 1:
			leString(novo->identificacao.numero, "Numero BI: ", MAX_NUM_ID);
			break;
		case 2:
			leString(novo->identificacao.numero, "Numero cc: ", MAX_NUM_ID);
			break;
		case 3:
			leString(novo->identificacao.numero, "Numero Passaporte: ", MAX_NUM_ID);
			break;
		}

		novo->contacto.tipo_contacto = leEnum("Email-> 1, contacto telefonico-> 2\n", 1,2);
		switch(novo->contacto.tipo_contacto)
		{
		case 1:
			leString(novo->contacto.contacto, "Email: ", MAX_CONTACTO);
			break;
		case 2:
			leString(novo->contacto.contacto, "Contacto Telefonico: ", MAX_CONTACTO);
			break;
		}
	}
	return novo;
}

/* imprime espectador
* recebe um ponteiro para o espectador
*/
void imprimeEspectador(P_PESSOA espectador){
	char *tipos_identificacao[] = {"bi", "cc", "passaporte"};
	char *tipos_contactos[] = {"email", "telefone"};

	printf("\n");
	imprimeLimite(80,'-');
	printf("Id-> %d\n", espectador->id_pessoa);
	printf("Nome-> %s\n", espectador->nome_pessoa);
	printf("%s-> %s\n", tipos_identificacao[espectador->identificacao.tipo_identificacao - 1], espectador->identificacao.numero);
	printf("%s-> %s\n", tipos_contactos[espectador->contacto.tipo_contacto - 1], espectador->contacto.contacto);
	imprimeLimite(80,'-');	
}