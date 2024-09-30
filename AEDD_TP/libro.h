#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct file{
	string name;
	string fisicalName;
	int position;
	int lineAmount;
	int wordAmount;
	ifstream * fhand;
	string lastWord;
};

file newFile(string name, string fileName);	//Crea un nuevo struct
bool openFile(file X);						//Abre el archivo en modo lectura
string readLine(file & X, bool &end);		//Lee una linea de tipo string,	cuenta en los contadores position y lineAmount
char readChar(file & X, bool &end);			//Lee un caracter como caracter,cuenta en los contadores position y lineAmount
string readWord(file & X, bool &end);		//Lee una palabra como string, cuenta en el contador wordAmount
int filePos(file X);						
int fileLine(file X);						
int fileWords(file X);						
bool fileClose(file& X);						//Cierra el archivo
