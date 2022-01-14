/*
*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* TÍTULO: DEBER 8 - Listas Simples
* AUTHOR(es):  LUIS CUEVA, CHRISTIAN ANDRANGO, ARIEL JARA, JORGE PAUCAR, JORGE AGUAS
* FECHA: Domingo 21 DE NOVIEMBRE DEL 2021
* Version: 1
* ESTRUCTURA DE DATOS
* NRC: 7166
*/
#include "Lista.h"
#include <iostream>

using namespace std;
Lista::Lista() {
	this->primero = NULL;
	this->actual = NULL;
}
void Lista::ingreso() {
	int n;
	do
	{
		cout << "Ingrese el valor : ";
		cin >> n;
		insertar(n);
		cout << "Desea Ingresar otro numero (si-1/no-0): ";
		cin >> n;
	} while (n != 0);
}
void Lista::insertar(int val) {
	Nodo* nuevo = new Nodo(val, NULL);
	if (listaVacia()) {
		this->primero = nuevo;
	}
	else {
		this->actual->siguiente = nuevo;
	}
	this->actual = nuevo;
}
void Lista::mostrar() {
	Nodo* tmp = this->primero;
	while (tmp) {
		cout << tmp->valor << "-->";
		tmp = tmp->siguiente;
	}
	cout << "NULL\n";
}
void Lista::buscar() {
	int val;
	cout << "\nIngrese el valor a Buscar: ";
	cin >> val;
	int aux = 0;
	Nodo* num = new Nodo(val, NULL);
	Nodo* tmp = this->primero;
	while (tmp)
	{
		if (tmp->valor == num->valor)
		{
			aux++;
		}
		tmp = tmp->siguiente;
	}
	if (aux == 0)
	{
		cout << "El numero no existe";
	}
	else
	{
		cout << "El numero existe";
	}
}
void Lista::eliminar() {
	int val;
	cout << "\nIngrese el valor a Eliminar: ";
	cin >> val;
	Nodo* num = new Nodo(val, NULL);
	Nodo* tmp = this->primero;
	Nodo* aux = tmp;
	Nodo* final = this->actual;
	aux = tmp;
	while (aux)
	{
		if (aux->valor == num->valor)
		{
			if (aux == tmp)
			{
				*tmp = *tmp->siguiente;
			}
			else {
				final->siguiente = aux->siguiente;
			}

		}
		final = aux;
		aux = aux->siguiente;
	}
}
void Lista::sumaLista() {
	Nodo* tmp = this->primero;
	int valor=0;
	while (tmp) {
		valor += tmp->valor;
		tmp = tmp->siguiente;
	}
	cout << "La suma total de la lista es:"<<valor<<endl;
}


