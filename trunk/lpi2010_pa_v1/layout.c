#include "stdafx.h"
#include <stdio.h>
#include "tipos.h"
#include <stdlib.h>
#include <string.h>




void menu(CABECA *array_listas){
	char *item_menu[OPCOES_MENU] = {"Criar", "Remover", "Listar", "Pesquisas"};

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
		/* Criar sala
		*/
		if(escolha_menu == '1'){
			insereInicio(&array_listas[ORDEM_LISTA_SALA], leSala(&array_listas[ORDEM_LISTA_SALA]));
		}

		/* Imprime sala
		*/
		if(escolha_menu == '3'){
			imprimeLista(&array_listas[ORDEM_LISTA_SALA], imprimeSala);
			system("PAUSE");
		}

		break;
	case '2':
		/* Criar espectaculo
		*/
		if(escolha_menu == '1'){
			insereInicio(&array_listas[ORDEM_LISTA_ESPECTACULO], leEspectaculo(&array_listas[ORDEM_LISTA_ESPECTACULO]));
			system("PAUSE");
		}

		/* Imprime espectaculo
		*/
		if(escolha_menu == '3'){
			imprimeLista(&array_listas[ORDEM_LISTA_ESPECTACULO], imprimeEspectaculo);
			system("PAUSE");
		}

		break;
	case '3':
		/* Criar Reserva
		*/
		if(escolha_menu == '1'){
			insereInicio(&array_listas[ORDEM_LISTA_ESPECTACULO], leReserva(array_listas));
			system("PAUSE");
		}

		break;
	case '4':
		/* menu pesquisa, sub-menu opção sair = 4
		*/
		if(escolha_menu == '4' && escolha_sub_menu == '4'){
			menu(array_listas);
		}
		/* Ler espectador
		*/
		if(escolha_menu == '1'){
			insereInicio(&array_listas[ORDEM_LISTA_PESSOA], leEspectador(&array_listas[ORDEM_LISTA_PESSOA]));
		}	

		/* Imprime Espectadores
		*/
		if(escolha_menu == '3'){
			imprimeLista(&array_listas[ORDEM_LISTA_PESSOA], imprimeEspectador);
		}
		system("PAUSE");
		break;
	case '5':
		/* opção sair volta ao menu
		*/
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

