/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: Arboles AVL
*AUTOR(ES): Christian Andrango, Isaac Escobar. Cristian Maranje, Daniela Pilataxi
*FECHA: JUEVES 6 DE ENERO DE 2022
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#include <iostream>
#include "Arbol.h"
using namespace std;
Node<int>* arbol = NULL;
void subMenu() {
	AVL<int> objArbol;
	int subOpcion = 0;
	while (subOpcion != 2) {
		cout << "\n 1. Inorden";
		cout << "\n 2. Regresar";
		cout << "\n\nDigite una opcion: ";
		cin >> subOpcion;
		system("cls");
		if (subOpcion == 1) {
			objArbol.inorder();
			cout << endl;
			system("pause");
			system("cls");
		}
	}
}
void menu() {
	AVL<int> objArbol;
	int contador = 0, opcion = 0, dato = 0;
	while (opcion != 4) {
		cout << "\n 1. Insertar nodo";
		cout << "\n 2. Eliminar elemento del arbol";
		cout << "\n 3. Recorrido del arbol";
		cout << "\n 4. Salir";
		cout << "\n\nDigite una opcion: ";
		cin >> opcion;
		system("cls");
		if (opcion == 1) {
			cout << "Ingrese un dato: ";
			cin >> dato;
			objArbol.insert(dato);
			/*llammos al objeto para usar el metodo*/
			cout << endl;
			system("pause");
			system("cls");
		}
		else if (opcion == 2) {
			cout << "Digite un elemento a eliminar: ";
			cin >> dato;
			objArbol.remove(dato);
			cout << endl;
			system("pause");
			system("cls");
		}
		else if (opcion == 3) {
			cout << endl;
			system("pause");
			system("cls");
		}
	}
}
int main()
{
	cout << "Arbol AVL\n";
	menu(); /* llamando a la funcion menu */
	cout << endl;
	return 0;
}
