#include <iostream>
#include <fstream>
#include <cstdlib>  
#include <string>
#include "archivo.h"

using namespace std;
int main(){    
string linea;
	
archivo Entrada;
Entrada=setup("Ahorcado en Español", "palabras-1.txt");
	
if (apertura(Entrada)==false){
	cout << "Error en apertura de archivo" << endl;
}
else {
	// leo todas las lineas hasta final del archivo
	bool final=false;
	do {
		linea= leerLinea(Entrada, final);
		cout << linea << " " << endl;
	} while (not final);
	cout << "Se leyeron " << leidas(Entrada) << " lineas" << "\n" << endl;
}
	
cierre(Entrada);
	
return 0;
}
