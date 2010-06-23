#include "stdafx.h"
#include <stdio.h>
#include "tipos.h"
#include <stdlib.h>
#include <string.h>

#define NUMERO_ITEMS 7
#define OPCOES_MENU 5


void menu(CABECA *array_listas){
	char *item_menu[OPCOES_MENU] = {"Criar", "Remover", "Listar", "Pesquisa Geral", "Pesquisa Personalizada"};

	char *sub_item_menu[NUMERO_ITEMS] = {"Salas", "Espetaculos", "Reservas", "Espectadores",
		"Salas por Nome", "Espectaculos por Nome e Numero", "Espectaculos de Sala ou Sessao numa Data"};
	int escolha_menu, escolha_sub_menu;

	for(;;){
		imprimeCabecalho("\t\t\t\tCinemas Lusofona\n", 80, '*');
		imprimeMenu(item_menu, OPCOES_MENU, '1');		
		rewind(stdin);
		escolha_menu = getchar();
		switch(escolha_menu)
		{
		case '1':
			system("CLS");
			imprimeCabecalho("\t\t\t\t    Criar\n", 80, '*');
			imprimeMenu(sub_item_menu, 4, escolha_menu);
			fflush(stdin);
			escolha_sub_menu = getchar();
			subMenu(escolha_menu, escolha_sub_menu, array_listas);
			fflush(stdin);
			break;

		case '2':
			system("CLS");
			imprimeCabecalho("\t\t\t\t    Remover\n", 80, '*');
			imprimeMenu(sub_item_menu, 4, escolha_menu);
			rewind(stdin);
			escolha_sub_menu = getchar();
			subMenu(escolha_menu, escolha_sub_menu, array_listas);
			break;

		case '3':
			system("CLS");
			imprimeCabecalho("\t\t\t\tListar\n", 80, '*');
			imprimeMenu(sub_item_menu, 4, escolha_menu);
			rewind(stdin);
			escolha_sub_menu = getchar();
			subMenu(escolha_menu, escolha_sub_menu, array_listas);
			break;

		case '4':
			system("CLS");
			imprimeCabecalho("\t\t\t\tPesquisa Geral\n", 80, '*');
			imprimeMenu(sub_item_menu,4, escolha_menu);
			rewind(stdin);
			escolha_sub_menu = getchar();
			subMenu(escolha_menu, escolha_sub_menu, array_listas);
			break;

		case '5':
			system("CLS");
			imprimeCabecalho("\t\t\t\tPesquisa Personalizada\n", 80, '*');
			imprimeMenu(sub_item_menu, 4, escolha_menu);
			rewind(stdin);
			escolha_sub_menu = getchar();
			subMenu(escolha_menu, escolha_sub_menu, array_listas);
			break;
		case '6':
			exit(1);
			break;

		default :
			break;
		}
	}
}

void subMenu(int escolha_menu, int escolha_sub_menu, CABECA *array_listas){		
		switch(escolha_sub_menu)
		{
		case '1':

			break;
		case '2':

			break;
		case '3':			
			break;
		case '4':
			insereInicio(&array_listas[ORDEM_LISTA_PESSOA], leEspectador(&array_listas[ORDEM_LISTA_PESSOA]));
			break;
		case '5':
			menu(array_listas);
			break;

		}
	}



void imprimeMenu(char **vct_menu, int tamanho, int escolha){
	int i, indice = 1;
	if(escolha == '1' || escolha == '2' || escolha == '3'){
		for(i = 0; i < tamanho; i++, indice++){
			printf("%d - %s\n", i + 1, vct_menu[i]);
		}
	}else{		
		for(i = tamanho; i < NUMERO_ITEMS; i++, indice++){

			printf("%d - %s\n", indice, vct_menu[i]);
		}
	}
	printf("%d - Sair\n", indice);
}

/*
 *Imprime estrutura do cabeçalho, recebe apontador para caractere.
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