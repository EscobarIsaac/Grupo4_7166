/*
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* TÍTULO: DEBER 8 - Listas Simples
* AUTHOR(es):  LUIS CUEVA, CHRISTIAN ANDRANGO, ARIEL JARA, JORGE PAUCAR, JORGE AGUAS
* FECHA: Domingo 21 DE NOVIEMBRE DEL 2021
* Version: 1
* ESTRUCTURA DE DATOS
* NRC: 7166
*/
#define NULL (0)
#include "Nodo.h"
Nodo::Nodo(int val, Nodo* sig = NULL) {
	this->valor = val;
	this->siguiente = sig;
}