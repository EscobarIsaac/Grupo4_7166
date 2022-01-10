/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: Ejercicio Arbol B
*AUTOR(ES): CHRISTIAN ANDRANGO, ISAAC ESCOBAR, CRISTIAN MARANJE, DANIELA PILATAXI
*FECHA: DOMINGO 09 DE ENERO DE 2022
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#include "b-plus.h"
#include <iostream>
using namespace std;
void menu() {
	BLinkTree<3, int> a;
	int opc = 0, dato = 0;
	while (opc != 4) {
		cout << "\n 1. Insertar nodo";
		cout << "\n 2. Mostrar arbol";
		cout << "\n 3. Borrar un dato";
		cout << "\n 4. Salir";
		cout << "\n\nDigite una opcion: ";
		cin >> opc;
		if (opc == 1) {
			cout << "Ingrese un dato: ";
			cin >> dato;
			a.insert(dato);

				cout << endl;
			system("pause");
			system("cls");
		}
		else if (opc == 2) {
			cout << "A R B O L B+ " << endl;
			a.print(a.root_ptr_);
			cout << endl;
			system("pause");
			system("cls");
		}
		else if (opc == 3) {
			cout << "Digite un elemento a eliminar: ";
			cin >> dato;
			a.remove(dato);
			cout << endl;
			system("pause");
			system("cls");
		}
	}
}
int main() {
	menu();
	system("pause");
	return 0;
}