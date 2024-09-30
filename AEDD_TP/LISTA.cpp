#include <iostream>
#include "LISTA.h"
#include <string>
using namespace std;

typedef nodo * ptrNodo;

void insertarElemento(nodo *&lista, string dato){
	ptrNodo aux1;
	//ptrNodo	nuevo, anterior;
	//anterior=NULL;
	//bool band=false;
	
	if(lista==NULL){
		lista=new nodo;
		lista->palabra=dato;
		lista->apariciones=1;
		lista->sig=NULL;
	}else{
	
		//ver si el dato que se esta por ingresar ya existe en la lista y donde
		aux1=lista;
		while(aux1->sig!=NULL and aux1->palabra!=dato){
			//anterior=aux1;
			aux1=aux1->sig;
		}
		/*
		if(aux1==NULL){//LA PALABRA AUN NO EXISTE EN LA LISTA. HAY QUE AGREGARLA. ANTERIOR MARCA EL ULTIMO NODO DE LA LISTA
			insertarEnOrden(lista,dato);
		}else{
			*/
			if(aux1->palabra==dato){//EL VALOR SE ENCONTRO EN LA PRIMERA POSICION DE LA LISTA. HAY QUE SUMAR UNO EN APARICIONES DE AQUI. AUX1 MARCA EL NODO DONDE AGREGAR
				aux1->apariciones++;
			}else{//EL VALOR SE ENCONTRO EN ALGUNA POSICION DESPUES DE LA PRIMERA. AUX1 MARCA LA POSICION. ANTERIOR MARCA LA ANTERIOR
				insertarEnOrden(lista,dato);
				
			//}
		}
	}
}
void insertarEnOrden(nodo*&lista, string dato){
	ptrNodo nuevo_nodo;
	nuevo_nodo= new nodo;
	nuevo_nodo->palabra=dato;
	nuevo_nodo->apariciones=1;
	
	ptrNodo aux1, aux2;
	aux1=lista;
	
	while((aux1 !=NULL) and (aux1->palabra<dato)){	//determina si al nodo hay que insertarlo en el principio (es menor al primer elemento de la lista)
		aux2=aux1;                        			//o si hay que insertarlo en el medio (cuando aux1->sig es mayor al dato a insertar)
		aux1=aux1->sig;					   			//o si hay que insertarlo al final (el while termina por el valor NULL de aux1)
	};//si eliminamos el condicional de aux1->info<dato entonces insertariamos al final siempre
	
	if(lista==aux1)
		lista=nuevo_nodo; //si aux1=lista entonces hay que agregarlo al comienzo
	else //sino hay que agregarlo en la posicion de aux2;
		aux2->sig=nuevo_nodo;
	
	nuevo_nodo->sig=aux1;//enlazamos el dato con el siguiente elemento de la lista
}
void mostrarLista(ptrNodo lista){
	ptrNodo actual;
	actual=new nodo();
	
	actual=lista;
	
	while(actual!=NULL){
		cout<<actual->palabra<<" ("<<actual->apariciones<<") -> ";
		actual=actual->sig;
	}
	cout<<"NULL"<<endl;
}
ptrNodo mayorLargo(ptrNodo lista){
	ptrNodo aux=lista, mayorptr=lista;
	int mayor=aux->palabra.size();
	
	while(aux!=NULL){
		if(aux->palabra.size()>mayor){
			mayor=aux->palabra.size();
			mayorptr=aux;
		}
		aux=aux->sig;
	}
	return mayorptr;
}
void ordenarLista(ptrNodo lista){
	if(lista==NULL or lista->sig==NULL)
		return;
	else{
		ptrNodo aux=mayorLargo(lista->sig);
		if(lista->palabra.size()<aux->palabra.size()){
			intercambiarPalabra(&(lista->palabra), &(aux->palabra));
			intercambiarApariciones(&(lista->apariciones), &(aux->apariciones));
		}
		ordenarLista(lista->sig);
	}
}
void ordenBurbujaLongitud(ptrNodo lista){
	ptrNodo aux1=lista, aux2=lista, anterior;
	while(aux1!=NULL){
		aux2=lista;
		anterior=aux2;
		while(aux2!=NULL){
			if(aux2->palabra.size()>anterior->palabra.size()){
				intercambiarPalabra(&aux2->palabra,&anterior->palabra);
				intercambiarApariciones(&aux2->apariciones,&anterior->apariciones);
			}
			anterior=aux2;
			aux2=aux2->sig;
		}
		aux1=aux1->sig;
	}
}
void ordenBurbujaApariciones(ptrNodo lista){
	ptrNodo aux1=lista, aux2=lista, anterior;
	while(aux1!=NULL){
		aux2=lista;
		anterior=aux2;
		while(aux2!=NULL){
			if(aux2->apariciones>anterior->apariciones){
				intercambiarPalabra(&aux2->palabra,&anterior->palabra);
				intercambiarApariciones(&aux2->apariciones,&anterior->apariciones);
			}
			anterior=aux2;
			aux2=aux2->sig;
		}
		aux1=aux1->sig;
	}
}
void intercambiarPalabra(string *a,string *b){
	string aux=*a;
	*a=*b;
	*b=aux;
}
void intercambiarApariciones(int *a,int *b){
	int aux=*a;
	*a=*b;
	*b=aux;
}
void imprimirPorLetra(ptrNodo lista, char inicial){
	ptrNodo aux=lista;
	
	while(aux!=NULL){
		if(aux->palabra.at(0)==inicial){
			cout<<aux->palabra<<" ("<<aux->apariciones<<")"<<endl;
		}
		aux=aux->sig;
	}
}
