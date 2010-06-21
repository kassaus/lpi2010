#include "tipos.h"
#include <stdlib.h>
#include <stdio.h>



void leEspectador(){

	static unsigned short int num_espectador;	
	P_PESSOA novo;
	num_espectador++;
	novo = malloc (sizeof(T_PESSOA));
	if(!novo){
		printf("Lamentamos nao foi possivel criar o espectador.");
	} else {
		printf("Id Espectador -> %d\n", num_espectador);
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
}