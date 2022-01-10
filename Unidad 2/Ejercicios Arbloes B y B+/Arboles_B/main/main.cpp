/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: Ejercicio Arbol B
*AUTOR(ES): CHRISTIAN ANDRANGO, ISAAC ESCOBAR, CRISTIAN MARANJE, DANIELA PILATAXI
*FECHA: DOMINGO 09 DE ENERO DE 2022
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#include <iostream>
#include "btree.h"
int main()
{
	std::cout << "ARBOLES B!\n";
	int matriz[TAMANO];
	btree arbol(5);
	stclave clave;
	int i;
	// srand(time(NULL));
	for (i = 0; i < TAMANO; i++) {
		do {
			matriz[i] = rand() % 10000;
			clave.valor = matriz[i];
			clave.registro = i;
		} while (!arbol.Insertar(clave));
	}
		cout << "mostrar: " << endl;
	arbol.Mostrar();
	cout << "Buscar elemento 23: " << matriz[23] << " posicion: " <<
		arbol.Buscar(matriz[23]) << endl;
	system("PAUSE");
	for (i = 0; i < TAMANO; i++) {
		cout << "Borrar: [" << i << "]: " << matriz[i] << endl;
		arbol.Borrar(matriz[i]);
		// arbol.Mostrar();
	}
	arbol.Mostrar();
	return 0;
}