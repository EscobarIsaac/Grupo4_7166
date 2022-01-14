/*
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* TÍTULO: DEBER 8 - Listas Simples
* AUTHOR(es):  LUIS CUEVA, CHRISTIAN ANDRANGO, ARIEL JARA, JORGE PAUCAR, JORGE AGUAS
* FECHA: Domingo 21 DE NOVIEMBRE DEL 2021
* Version: 1
* ESTRUCTURA DE DATOS
* NRC: 7166
*/
#include <iostream>
#include "Lista.h"
#include "Nodo.h"
using namespace std;
int main()
{
	Lista lst;
	lst.ingreso();
	lst.mostrar();
	lst.buscar();
	printf_s("\n");
	lst.eliminar();
	lst.mostrar();
	lst.sumaLista();
	return 0;
}
