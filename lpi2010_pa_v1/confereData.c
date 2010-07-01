#include <stdio.h>

#include "tipos.h"
#include "tipos2.h"




int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* validaData
 *recebe apontador para estrutura data a verificar
 *	devolve 1 se data valida
 *			0 se invalida
 *
 */
int validaData( P_DATA data ){
		
	int bisexto;		
	bisexto = ( (data->ano%4 == 0 && data->ano%100 != 0) || data->ano%400 == 0);
	if (bisexto) dias_mes[1] = 29;

	if (data->dia <1 || data->dia >dias_mes[data->mes -1]) {
		printf("Data Invalida!\n");
		return 0;
	}
	return 1;
}

/* confereData
 *recebe dois apontadores para estruturas data
 *	devolve 1 se data1 maior que data2
 *			0 se data1 igual a data2
 *			-1 se data1 menor que data2
 */
int confereData(P_DATA data1, P_DATA data2){

	if (data1->ano < data2->ano)
		return -1;
	if (data1->ano > data2->ano)
		return 1;

	if (data1->mes < data2->mes)
		return -1;
	if (data1->mes > data2->mes)
		return 1;

	if (data1->dia < data2->dia)
		return -1;
	if (data1->dia > data2->dia)
		return 1;

	return 0;
}