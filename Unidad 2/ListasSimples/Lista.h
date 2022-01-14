/*
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* TÍTULO: DEBER 8 - Listas Simples
* AUTHOR(es):  LUIS CUEVA, CHRISTIAN ANDRANGO, ARIEL JARA, JORGE PAUCAR, JORGE AGUAS
* FECHA: Domingo 21 DE NOVIEMBRE DEL 2021
* Version: 1
* ESTRUCTURA DE DATOS
* NRC: 7166
*/
#include "Nodo.h"
#define NULL (0)

class Lista {
public:
	Lista();
	void ingreso();
	void insertar(int);
	void mostrar();
	void eliminar();
	void sumaLista();
	void buscar();

private:
	Nodo* primero;
	Nodo* actual;
	bool listaVacia() {
		return (this->primero == NULL);
	}

};
