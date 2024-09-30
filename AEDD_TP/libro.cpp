#include "libro.h"
using namespace std;

file newFile(string name, string fileName){
	file aux;
	aux.fisicalName=fileName;
	aux.name=name;
	aux.position=0;
	aux.lineAmount=0;
	aux.wordAmount=0;
	aux.fhand=new ifstream;
	return aux;
}
bool openFile(file X){
	X.fhand->open(X.fisicalName.c_str());
	bool retorno=true;
	if(X.fhand->fail()){
		retorno = false;
	}
	return retorno;
}

string readLine(file & X, bool & end){
	string line;
	end=false;
	if (not X.fhand->eof()){
		getline(*X.fhand, line);
		X.position+=line.length()+1;
		X.lineAmount++;
	}else{
		end=true;
	}
	return line;
}
char readChar(file & X, bool & end){
	char c;
	end=false;
	if(not X.fhand->eof()){
		X.fhand->get(c);
		X.position++;
		if(c=='\n'){
			X.lineAmount++;
		}
	}else{
		end=true;
	}
	return c;
}
void pretrim(string &word){
	unsigned int first=0;
	while(first<word.size() and not isalpha(word.at(first))){
		first++;																//Busco la posicion de la primera letra
	}
	word = word.substr(first,word.size());										//Retorno de la primera letra hasta el final
}
void postrim(string &word){														
	int last=word.length();
	while(last>0 and not isalpha(word.at(last-1)) ){
		last--;																	//Busco la posicion de la ultiuma letra
	}
	word= word.substr(0,last);													//Retorno desde el principio hasta la ultima letra
}
void readNextWord(file & X, bool & end){
	string word;
	end=false;
	while(not end and word.empty())												
		if(not X.fhand->eof()){
		*X.fhand>>word;
		pretrim(word);
		postrim(word);
		
	}else{
			end=true;
		}
		X.wordAmount++;
		X.lastWord=word;
}
string readWord(file & X, bool & end){
	string word;
	if(X.lastWord.empty()){														//Si el acumulador X.lastWord está vacío pido una siguiente lectura
		readNextWord(X,end);													//Leo el siguiente conjunto de palabras
	}
	if(not X.lastWord.empty()){
		int pos=0, lastWordSize=X.lastWord.size();
		while(pos<lastWordSize and isalpha(X.lastWord.at(pos))){				//Obtengo la posición de finalizacion de la primera palabra
			pos++;
		}
		word=X.lastWord.substr(0,pos);											//Devuelvo la primera palabra
		X.lastWord=X.lastWord.substr(pos,lastWordSize-1);						//En el acumulador X.lastWord guardo el resto de las palabras
		pretrim(X.lastWord);													//Substraigo los posibles caracteres especiales de el acumulador X.lastWord
	}
	return word;
		
}

int filePos(file X){
	return X.position;
}
int fileLine(file X){
	return X.lineAmount;
}
int fileWords(file X){
	return X.wordAmount;
}
bool fileClose(file& X){
	X.fhand->close();
	bool retorno=true;
	if(X. fhand->fail()){
		retorno=false;
	}
	delete X.fhand;
	return retorno;
}
