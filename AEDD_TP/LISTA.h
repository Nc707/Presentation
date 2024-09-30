#include <iostream>
#include <string>

using namespace std;



struct nodo{
	string palabra;
	int apariciones;
	nodo *sig;
};

typedef nodo * ptrNodo;

void insertarElemento(nodo *&, string);
void insertarEnOrden(nodo*&, string); 
void mostrarLista(ptrNodo lista);
ptrNodo mayorLargo(ptrNodo);
void ordenarLista(ptrNodo lista);
void intercambiarPalabra(string *,string *);
void intercambiarApariciones(int *,int *);
void ordenBurbujaLongitud(ptrNodo lista);
void ordenBurbujaApariciones(ptrNodo lista);
void imprimirPorLetra(ptrNodo lista, char inicial);
