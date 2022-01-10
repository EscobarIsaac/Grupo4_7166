/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: Ejercicio Arbol B
*AUTOR(ES): CHRISTIAN ANDRANGO, ISAAC ESCOBAR, CRISTIAN MARANJE, DANIELA PILATAXI
*FECHA: DOMINGO 09 DE ENERO DE 2022
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#pragma once
#pragma once
#include <iostream>
#include <stdlib.h>
#define TAMANO 1000
using namespace std;
/*Estructura para construir un arbol-B para indicar una tabla de 1000 registros por el
campo valor.*/
class stclave {
public:
	int valor;
	long registro;
};
class bnodo {
public:
	bnodo(int nClaves);
	~bnodo();
private:
	int clavesUsadas;
	stclave* clave;
	bnodo** puntero;
	bnodo* padre;
	friend class btree;
};
typedef bnodo* pbnodo;
bnodo::bnodo(int nClaves)
{
	clavesUsadas = 0;
	clave = new stclave[nClaves];
	puntero = new pbnodo[nClaves + 1];
	padre = NULL;
}
bnodo::~bnodo()
{
	delete[] clave;
	delete[] puntero;
}
