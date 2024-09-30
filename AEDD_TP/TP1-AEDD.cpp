#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include "archivo.h"
#include "libro.h"
#include "login.h"
#include "LISTA.h"
#define SIZE 100
#define AHORCADO_WIDTH 60
#define NUMEROS_OTRO_IDIOMA_WIDTH 50
#define MENUPRINCIPAL_WIDTH 80
#define ABECEDARIOS_WIDTH 80
#define MEMORIA_WIDTH 80
#define LOGIN_WIDTH 50

using namespace std;
//Funciones de impresion de cadenas
void stringSeparated(string word, char fill, bool lastSeparator = true);//#1
void printCharacters(int len, char character);//#2
void printCentered(int len, string frase);//#3
void printNumerated(string words[], int wordsLen);//#4
//Funciones de manipulación y conteo de cadenas
void searchforRepetitions(string cadena, char caracter, int repetitions[], int & repSize);//#5
void fillString(string & cadena, int size, char fill);//#6
void fillPositions(string & cadena, const int positions [], int posSize, char fill);//#7
int indexSearcher(string words[], int wordsLen, string word);//#8
string tolower(string word);//#9
//Funciones de char a int y viceversa
char intToChar(int i);//#10
int charToInt(char a);//#11
//Funciones de ahorcado
void ahorcado(string [], user &);//#12
void ahorcadoPrint(string word,int points, string usedChar, string lastMessage);//#13
char gallow(int points, int i, int j);//#14
string message(int n);
//Funciones de numeros en otro idioma
void numerosOtroIdioma();//#15
string getNumber(int number, int country);//#16
int languageProcessor(string entrance, string options[], int);//#17
void numerosOtroIdiomaHeader();//#18
int numerosLanguageGet(string languages[],int languagesLen);//#19
int numerosNumberGet();//#20
int numerosIncreaseGet();//#21
int numberProcessor(string input);//#21
void sevenDigits(int increase, int number);//#22
bool numberSegment(int number, int segment);//#23
void horizontalSegment(int increase, bool showed);//#24
void verticalSegment(int increase, bool showed1,bool showed2);//#25
void numerosOutput(int number, string languages[], int language, int);//#26
//Funciones de configuración de ventana
void windowSize(int width,int heigth);//#27
//Pantalla Bienvenida
void startPage();//#28
//Desplazamientos en consola
void gotoxy(SHORT x,SHORT y);//#29
//Lineas de caracteres y palabras
//#30
void printLVd(int xi, int yi, int len, char caracter);
void printLVa(int xi, int yi, int len, char caracter);
void printLHa(int xi, int yi, int len, char caracter);
void printLHd(int xi, int yi, int len, char caracter);
void carruzelH(int xi,int yi, int len, string palabra,int, int despl);
void carruzelV(int xi,int yi, int len, string palabra,int, int despl);
void printArea(int xi, int yi,int lenx,int leny,char caracter);
//Letras en carruzel
//#31
void printBigIcarruzel(int xi,int yi, string palabra, int palabraLen, int despl);
void printBigPcarruzel(int xi,int yi, string palabra, int palabraLen, int despl);
void printBigAcarruzel(int xi,int yi, string palabra, int palabraLen, int despl);
void printDcarruzel(int xi,int yi, string palabra, int palabraLen, int despl);
void printIcarruzel(int xi,int yi, string palabra, int palabraLen, int despl);
void printOcarruzel(int xi,int yi, string palabra, int palabraLen, int despl);
void printMcarruzel(int xi,int yi, string palabra, int palabraLen, int despl);
void printAcarruzel(int xi,int yi, string palabra, int palabraLen, int despl);
void printScarruzel(int xi,int yi, string palabra, int palabraLen, int despl);
void printRcarruzel(int xi,int yi, string palabra, int palabraLen, int despl);
void printPcarruzel(int xi,int yi, string palabra, int palabraLen, int despl);
void printEcarruzel(int xi,int yi, string palabra, int palabraLen, int despl);
void printNcarruzel(int xi,int yi, string palabra, int palabraLen, int despl);
//Palabras en carruzel
void printIdiomas(int xi,int yi, string palabra, int palabraLen, int despl);//#32
void printPara(int xi,int yi,string  palabra,int  palabraLen,int  despl);//#33
void printAprender(int xi,int yi,string  palabra,int  palabraLen,int  despl);//#34
//Impresiones en coordenadas y en coordenadas centradas
void printIn(int xi,int yi,string word);//#35
void centerIn(int xi,int yi, int xf, string word);//#36
//Imprimir logo UTN
void logoUTN(int xi, int yi);//#37

string randomWord(string words[], int size);
void randomWords(string words[], int size, string[],int);
void fileExtractor(string arreglo[]);
void errorWithFile();
char tomayus(char a);

void MenuPrincipal(string size[], user &);
void InterfaceMenuPrincipal();

void ProcesadorTexto();
void InterfaceProcesadorTexto();

void Abecedarios();
void InterfaceAbecedarios();

void Espaniol();
void Ingles();
void Italiano();
void Portugues();
void Frances();

void AbecedarioBase(char abecedario[], int t);
void Impresion(char m[], int t);
void ImpresionSinLimite(char m[], int t);
void Mayuscula(char c[],int t);
void EliminarLetra(char vector[], int& t, char l);

void Juegos(string words[], user &);
void InterfaceJuegos();

void MEMORIA(string[], user &);
void InterfaceMemoria();

void MostrarPalabrasAleatorias(string,string,string,string,string);
void MostrarPalabra(string);
void unionPalabras(string& cadena,string p1,string p2,string p3,string p4,string p5);
void Minuscula(string & c);
void LetrasMasRepetidas(string cadena, char vLetras[], int vCantidad[], int& tl);
void VectorLetras(string cadena,char v[],int& tl);
void VectorCantidad(string cadena, char l[],int tl,int c[]);
void ordenDescendente(int c[],char l[], int tl);
void ordenDescendenteSTR(int c[],string l[], int tl);

int RespuestaA(char vLetras[], int cantidad[], int tl);
int cantidadVocales(const char vLetras[], int vCantidad[], int tl);
float RespuestaB(char vLetras[], int vCantidad[], int tl);
void palabraMasLarga(string palabras[], char palabraNumero[], int tamanios[], string palabra1,string palabra2,string palabra3,string palabra4,string palabra5);
int RespuestaC(string palabras[], string palabra1,string palabra2,string palabra3,string palabra4,string palabra5);


void puntuacion(int puntos[],int cantidad[], int t);
int CalculoPuntaje(char numero, int puntos[], char vector[], int t);

void StrToVec(string c, char v[], int & t);
void VecToStr(char v[], int t, string & c);

//cifrado de palabra
void palabraMayuscula(string &, int );
void llenarPalabraVacia(string &,int);
void llenarPalabraGuiones(string &,int tam);
void cifradoCesar(string , string & , int );
int cantIntentos(int &intentos,int tam);
void printCenteredN(int len, int longfrase);
//descubrir la palabra
void letraRepetida(int & , char &, string,string palabracifrada,int tam, string plantilla, int intentos );
void esLetra(char&letra, string palabracifrada, int tam, string plantilla );
void descubrirPalabra(string palabra, int tam, string &plantilla, int &intentos,char letra, int & i, string &);
void resultado(string palabra, string & plantilla, string &letrasingresadas, int &intetos, int tam,string palabracifrada);
void mensajeFinal(int intentos, string plantilla, string palabra,string palabracifrada);
void JuegoCifradocesar(string palabras[]);

int Contrasenia(int );
bool ValidacionDatos();
int Esnumero(string dato);

void setConsoleColor(int text,int background);
//Funciones del Login
bool loginScreen(user & usuario,int & pos);
void printBox(int x, int y);
void printBasicLogin(int id=0);
void printWelcome(user u);
void printSecurityIssue();
void updateLoginData(user u, int position);
void printDate(date d);
void printUser(user u);
void writeInTXT(user u,ofstream & o);
user userInput();
//
void lista();
void GenerarLista(ptrNodo &lista);
void GenerarArchivo(ptrNodo lista);



struct caracteres{
	char caracter;
	int frecuencia;
};
struct vectorCaracteres{
	caracteres vec [200];
	int tam;
};
struct palabra {
	string p ;
	int frec;
};

//caracteres
void burbujaCaracteres(vectorCaracteres & v);
void Crearvecfrecuencia(vectorCaracteres & v, file &);
void imprimir (vectorCaracteres v);
void archivofrecuencia(vectorCaracteres v);
//////////////////////////

//////////////////////////
//Palabras
void inicializarmatriz(int Palabras[][26]);
void matrizpalabras(int Palabras [][26], file & f,int &vocales, int &contador, int & suma);
void imprimirMatriz(int Palabras [][26] , file & f, int mayor);
int mayorlongitud(file &f);	
//item II
void PalabrasMayorOcurrencia(char c, file & f);
void burbujaPalabras(int tam, palabra vec[]);

//item  III
bool Vocal(char c);
void Porcentaje(int contador, int vocales);
//////OPCIONES/////
void opcion1();
void opcion2();
void opcion2_2();
void InterfaceOpcion2();
int main(int argc, char *argv[]) {
	srand(time(NULL));
	user currentUser;
	int position=0;
	string palabras[SIZE+1];
	fileExtractor(palabras);
	startPage();
	if(loginScreen(currentUser,position)){
	printWelcome(currentUser);
	MenuPrincipal(palabras,currentUser);
	updateLoginData(currentUser,position);
	}else{
	printSecurityIssue();
	}

	return 0;
}
user userInput(){
	char name[NAMESIZE];
	char surname[NAMESIZE];
	char sex;
	bool role;
	cin>>name>>surname>>sex>>role;
	return setUser(name,surname,sex,role,setActualDate());
}
void printDate(date d){															//Imprime struct tipo date
	cout<<d.day<<"/"<<d.month<<"/"<<d.year<<" "<<d.hours<<":"<<d.minutes<<":"<<d.seconds;
}
	
void printUser(user u){															//Imprime struct tipo user
	cout<<"Name: "<<u.name<<" Surname: "<<u.surname<<" Sex: "<<u.sex<<endl<<	
		"ID: "<<u.id<<" Password: "<<u.password<<" Is teacher?: "<< u.teacher<<endl
		<<"Points: "<<u.points<<endl;
	printDate(u.last_access);
}
void writeInTXT(user u,ofstream &o){											//Escrube en un archivo struct tipo user
	o<<"Name: "<<u.name<<" Surname: "<<u.surname<<endl<<"Sex: "<<u.sex<<endl<<
		"ID: "<<u.id<<" Password: "<<u.password<<endl<<"Is teacher?: "<< u.teacher<<endl
		<<"Points: "<<u.points<<endl;
}
			
////////////////////////////////
void opcion1(){
	file f;
	f=newFile("Amor de Perdicao", "AMOR DE PERDICAO.txt");
	if(openFile(f)){
	windowSize(50,30);
	vectorCaracteres v;
	Crearvecfrecuencia(v,f);
	burbujaCaracteres(v);
	imprimir(v);
	archivofrecuencia(v);
	fileClose(f);}
	else{
		cout<<"Error al abrir el archivo";
		exit(1);
	}
}
void opcion2(){
	file f;
	f=newFile("Amor de Perdicao", "AMOR DE PERDICAO.txt");
	if(openFile(f)){
	windowSize(150,30); 
	int Palabras [21][26];
	int vocales=0; int contador=0, suma=0;
	printCentered(150, "ESTADISTICAS A NIVEL DE PALABRAS");
	printCharacters(150, char(205));
	inicializarmatriz(Palabras);
	matrizpalabras(Palabras,f,vocales,contador,suma);
	
	ptrNodo lista;
	lista=NULL;
	GenerarLista(lista);
	
	system("pause");
	system("cls");
	char n;
	do{
	InterfaceOpcion2();
	cin>>n;
	while((n<'1' or n>'4') and n!='X' and n!='x'){
		system("cls");
		InterfaceOpcion2();
		cout<<"El caracter ingresado es incorrecto, ingresar un entero del 1 al 4 o X (o x): ";
		cin>>n;
	}
	if(n=='1'){
		system("cls");
		printCentered(MENUPRINCIPAL_WIDTH, "ESTADISTICAS A NIVEL DE PALABRAS");
		printCharacters(MENUPRINCIPAL_WIDTH, char(205));
		cout<<"La longitud de palabra promedio es : "<<suma/contador<<endl;
		system("pause");
	}
	else if (n=='2'){
		system("cls");
		printCentered(MENUPRINCIPAL_WIDTH, "ESTADISTICAS A NIVEL DE PALABRAS");
		printCharacters(MENUPRINCIPAL_WIDTH, char(205));
		opcion2_2();
		system("pause");
	}
	else if(n=='3'){
		system("cls");
		printCentered(MENUPRINCIPAL_WIDTH, "ESTADISTICAS A NIVEL DE PALABRAS");
		printCharacters(MENUPRINCIPAL_WIDTH, char(205));
		Porcentaje(contador,vocales);
		system("pause");
	}
	else if(n=='4'){
		system("cls");
		printCentered(MENUPRINCIPAL_WIDTH, "ESTADISTICAS A NIVEL DE PALABRAS");
		printCharacters(MENUPRINCIPAL_WIDTH, char(205));
		GenerarArchivo(lista);
		system("pause");
	}
	}while(n!='x' and n!='X');
	fileClose(f);
	}
	else{
		cout<<"Error al abrir el archivo";
		exit(1);
	}
}
void GenerarLista(ptrNodo &lista){
	file archivo = newFile("Texto","AMOR DE PERDICAO.txt");
	if(openFile(archivo)){
	string palabra;
	bool end=false;
	palabra=readWord(archivo,end);
	while(!end){
		Minuscula(palabra);
		insertarElemento(lista,palabra);//inserta las palabras de forma ordenada alfabetiamente
		palabra=readWord(archivo,end);
	}
	fileClose(archivo);
	ordenBurbujaLongitud(lista);
	ordenBurbujaApariciones(lista);
	//mostrarLista(lista);
	}else{
		cout<<"Error al abrir el archivo";
		exit(1);
	}
}
void GenerarArchivo(ptrNodo lista){
	ofstream registros;
	char inicial;
	cout<<"Ingrese la letra a la cual le desee generar un archivo: ";
	cin>>inicial;
	while(!isalpha(inicial)){
		cout<<"ERROR. Debe ingresar una letra :";
		cin>>inicial;
	}
	string inicialS="x";
	inicialS.at(0)=toupper(inicial);
	
	string nombreArchivo="palabras";
	nombreArchivo+=(inicialS+".txt");
	
	registros.open(nombreArchivo.c_str(),ios::out);
	
	if(registros.fail()){
		cout<<"ERROR AL CREAR EL ARCHIVO";
		exit(1);
	}else{
		
		ptrNodo aux=lista;
		while(aux!=NULL){
			if(aux->palabra.at(0)==tolower(inicial)){
				registros<<"Palabra: "<<aux->palabra<<" ; Apariciones: "<<aux->apariciones<<endl;
			}
			aux=aux->sig;
		}
		cout<<"Archivo creado :"<<nombreArchivo<<endl;
	}
	registros.close();
}
void InterfaceOpcion2(){//Muestra la interface del Procesador de texto
	windowSize(MENUPRINCIPAL_WIDTH,25);
	printCentered(MENUPRINCIPAL_WIDTH, "ESTADISTICAS A NIVEL DE PALABRAS");
	printCharacters(MENUPRINCIPAL_WIDTH, char(205));
	cout<<"1.- Longitud promedio de las palabras"<<endl;
	cout<<"2.- Palabras de mayor recurrencia con la letra 'X'"<<endl;
	cout<<"3.- Porcentaje de palabras"<<endl;
	cout<<"4.- Generar archivo de palabras que comienzan con la letra 'X'"<<endl;
	cout<<"X.- Continuar"<<endl;
	cout<<endl;
}
void opcion2_2(){
	file f;
	f=newFile("Amor de Perdicao", "AMOR DE PERDICAO.txt");
	if(openFile(f)){
	char c;
	cout<<"Ingrese una letra: "<<endl;
	cin>>c;
	while(!isalpha(c)){
		system("cls");
		printCentered(MENUPRINCIPAL_WIDTH, "ESTADISTICAS A NIVEL DE PALABRAS");
		printCharacters(MENUPRINCIPAL_WIDTH, char(205));
		cout<<"Ingreso invalido, ingrese una letra: "<<endl;
		cin>>c;
		
	}
	PalabrasMayorOcurrencia(c,f);
	fileClose(f);
	}
	else{
		cout<<"Error al abrir el archivo";
		exit(1);
	}
}
void inicializarmatriz(int Palabras[][26]){
	for (int i=0;i<21;i++){
		for(int j=0;j<26;j++){
			Palabras[i][j] = 0;
		}
	}
}
void archivofrecuencia(vectorCaracteres v){
	ofstream f;
	f.open("frecuencia.txt");
	for(int i=0;i<v.tam;i++){
		f<<v.vec[i].caracter<<" ";
		f<<v.vec[i].frecuencia<<endl;
	}
	f.close();
}
void Porcentaje(int contador, int vocales){
	int consonantes=contador-vocales;
	float pc;
	pc=consonantes*100.00/contador;
	float pv;
	pv=vocales*100.00/contador;
	cout<<"Palabras que comienzan con una vocal :"<<fixed<<setprecision(2)<<pv<<"%"<<endl;
	cout<<"Palabras que comienzan con una consonante :"<<fixed<<setprecision(2)<<pc<<"%"<<endl;
}
void matrizpalabras(int Palabras [][26], file & f, int &vocales, int &contador, int & suma){
	string palabra;
	int mayor=0;
	bool end=false;
	int longitud;
	int primeraletra;
	while(!end){
		
		palabra=readWord(f,end);
		
		if(!palabra.empty()){
			contador++;
			longitud = palabra.size();
			suma+=longitud;
			if(isalpha(palabra.at(0))){
				palabra.at(0)=toupper(palabra.at(0));
				primeraletra = palabra.at(0) - 'A';
				Palabras[longitud][primeraletra]++;
				
				
			}
			if(palabra.size()>mayor)
					   mayor=palabra.size();
			if(Vocal(palabra.at(0)))
				vocales++;
			
		}
	}
	
	imprimirMatriz(Palabras,f,mayor);
}
void imprimirMatriz(int Palabras [][26] , file & f, int mayor){
	cout<<" "<<" "<<" "<<" "<<" "<<" ";
	for(char c='A';c<='Z';c++){
		cout<<c<<" "<<" "<<" "<<" ";
		
	}
	cout<<endl;
	for (int i =1; i <=mayor ; i++) {
		cout<<"L :"<<i;
		if(i<10)
			cout<<" "<<" ";
		else 
			cout<<" ";
		
		for (int j = 0; j < 26; j++) {
			cout << Palabras[i][j];
			if(Palabras[i][j]>=1000)
				cout<<" " ;
			else if (Palabras[i][j]>=100)
				cout<<" "<<" " ;
			else if (Palabras[i][j]>=10)
				cout<<" "<<" "<<" " ;
			else
				cout<<" "<<" "<<" "<<" " ;
		}  
		cout<<endl;
	}
}

bool Vocal(char c){
	bool b=false;
	if(c=='A'|| c=='E' || c=='I'|| c=='O'|| c=='U' )
		b=true;
	return b;
}
void PalabrasMayorOcurrencia(char c, file & f){
	string a;
	bool end=false, found=false;
	palabra vec [5000];
	
	c=toupper(c);
	
	vec[0].frec=0;
	int tam=0;
	
	while(!end){
		
		
		a=readWord(f,end);
		
		if(!a.empty()){
			
			a.at(0)=toupper(a.at(0));
			
			if(c==a.at(0)){
				
				int i=0;
				while(i<tam and !found){
					
					if(vec[i].p==a){
						vec[i].frec++;
						found=true;
					}
					i++;		
				}
				
				if(!found){
					vec[tam].frec=0;
					vec[tam].p=a;
					vec[tam].frec++;
					tam++;
					
				}
				
			}
		}
		found=false;
	}
	
	burbujaPalabras(tam,vec);
	for(int i=0;i<5;i++){
		cout<<i+1<<". Palabra: "<<vec[i].p<<" ; Frecuencia: "<<vec[i].frec<<endl;
	}
}

void burbujaPalabras(int tam, palabra vec[]){
	for(int i=1;i<tam;i++){
		for(int j=0;j<tam-1;j++){
			if(vec[j].frec<vec[j+1].frec){
				palabra aux;
				aux=vec[j];
				vec[j]=vec[j+1];
				vec[j+1]=aux;
			}
		}
	}
}
void burbujaCaracteres(vectorCaracteres & v){//2
	
	for(int i=1;i<v.tam;i++){
		for(int j=0;j<v.tam-1;j++){
			if(v.vec[j].frecuencia<v.vec[j+1].frecuencia){
				caracteres aux;
				aux=v.vec[j];
				v.vec[j]=v.vec[j+1];
				v.vec[j+1]=aux;
			}
		}
	}
}
void Crearvecfrecuencia(vectorCaracteres & v, file & f){//1
	char cnuevo;
	bool found=false;
	bool end;
	
	cnuevo=readChar( f, end);
	v.vec[0].frecuencia=0;
	v.tam=0;
	while(!end){
		
		cnuevo=readChar( f, end);
		cnuevo=toupper(cnuevo);
		
		int i=0;	
		while(v.tam>i and !found){
			if(cnuevo==v.vec[i].caracter){	// compruebo si ya se encuentra en el arreglo de frecuencia el sig caracter
				v.vec[i].frecuencia++;
				found=true;
			}
			i++;}
		if(!found and isalpha(cnuevo)){
			v.vec[v.tam].frecuencia=0;
			v.vec[v.tam].caracter=cnuevo; //sino, lo agrego al arreglo de frecuancia
			v.vec[v.tam].frecuencia++;
			v.tam++;
		}
		found=false;
		
	}
}

void imprimir ( vectorCaracteres v){//3
	string a="ESTADISTICAS A NIVEL CARACTERES";
	printCenteredN(50,a.size());
	cout<<a<<endl;
	cout<<endl;
	for(int i=0;i<v.tam;i++){
		printCenteredN(50,3);
		cout<<v.vec[i].caracter<<" ";
		cout<<v.vec[i].frecuencia<<endl;
	}
}
//////////////////////////////

void updateLoginData(user u, int position){										//Actualiza los datos de usuario en el archivo
	fstream f;
	if(openUserList(f,"usuarios.bin")){
	updateAccess(u);
	updateUser(f,u,position);
	closeUserList(f);}
	else{
		cout<<"Error al abrir el archivo de información del usuario";
		exit(1);
	}
}

bool loginScreen(user & usuario,int & pos){
	int password,id, intentos=3;
	bool userFound, correctPassword=false;
	setConsoleColor(4,0);
	windowSize(LOGIN_WIDTH,23);
	fstream fhand;
	string filename = "usuarios.bin";
	if(openUserList(fhand,filename)){
		printBasicLogin();													
		do{
			cin.ignore(1);														//Ignora enter residual de el inicio
			gotoxy((3*LOGIN_WIDTH)/4-3,3);										//Posiciona el cursor en la casilla
			cin>>id;
			while(cin.fail()){													//Loop de ingreso de caracteres no numericos, mientras el buffer se encuentra en estado de falla
				cin.clear();
				cin.ignore(1000,'\n');
				printBasicLogin();
				gotoxy(0,8);
				printCentered(LOGIN_WIDTH,"POR FAVOR INGRESE SOLO CARACTERES NUMERICOS");
				gotoxy((3*LOGIN_WIDTH)/4-3,3);
				cin>>id;
			}
			usuario = getUser(fhand,id,userFound,pos);
			if(pos<0){															//Posicion por defecto -1, verificación de encuentro del usuario
				printBasicLogin();
				gotoxy(0,8);
				printCentered(LOGIN_WIDTH,"USUARIO NO ENCONTRADO");
			}
		}while(not userFound);
		printBasicLogin(id);
		do{
			gotoxy((3*LOGIN_WIDTH)/4-3,6);
			cin>>password;
			while(cin.fail()){													//Loop de ingreso de caracteres no numericos
				cin.clear();
				cin.ignore(1000,'\n');
				printBasicLogin(id);
				gotoxy(0,8);
				printCentered(LOGIN_WIDTH,"POR FAVOR INGRESE SOLO CARACTERES NUMERICOS");
				gotoxy((3*LOGIN_WIDTH)/4-3,6);
				cin>>password;
			}
			correctPassword=passwordCheck(usuario,password);
			if(not correctPassword){											//En caso de no ser correcta la contraseña se restan los intentos y se le informa al usuario
				printBasicLogin(id);
				gotoxy(0,8);
				printCentered(LOGIN_WIDTH,"CONTRASEÑA INCORRECTA");
				printCentered(LOGIN_WIDTH-10,"LE QUEDAN: ");
				gotoxy(26,9);
				intentos--;
				cout<<intentos<<" INTENTOS";
			}
		}while(not correctPassword and intentos>0);
		
		closeUserList(fhand);
	}else{
		cout<<"Error al encontrar el archivo de verificación";
		exit(1);
	}
	return correctPassword;
}
void printSecurityIssue(){														//Imprime alerta de seguridad
	system("cls");
	windowSize(60,11);
	gotoxy(0,2);
	cout<<"ERROR: POSIBLE VIOLACION DE SEGURIDAD";
	gotoxy(0,9);
	system("pause");
}
void printWelcome(user u){														//Imprime saludo de bienvenida
	system("cls");
	windowSize(60,11);
	gotoxy(0,2);
	if(u.sex=='F'){
		cout<<"Bienvenida ";
	}else{
		cout<<"Bienvenido ";
	}
	cout<<u.name;
	gotoxy(0,7);
	cout<<"Tu ultimo inicio de sesion fue el ";
	printDate(u.last_access);
	cout<<" Horas";
	gotoxy(0,8);
	system("pause");
}
void printBasicLogin(int id){													//Impresion de pantalla de login, en caso de ya tener id asignado se imprime
	system("cls");
	printCentered(50,"VERIFICACION DE CREDENCIALES");
	printLHa(0,1,50,char(205));
	cout<<endl;
	printIn(7,3,"NUMERO DE LEGAJO:");
	printBox((3*LOGIN_WIDTH)/4-4,2);
	if (id!=0){
		printIn((3*LOGIN_WIDTH)/4-3,3,to_string(id));
	}
	printIn(10,6,"CONTRASENIA:");
	printBox((3*LOGIN_WIDTH)/4-4,5);
}
void printBox(int x, int y){													//Imprime casillas de ingreso de datos
	printLHa(x+1,y+0,5,char(205));//Top
	printLHa(x+0,y+0,1,char(201));//Top Left
	printLHa(x+1,y+2,5,char(205));//Bottom
	printLHa(x+6,y+0,1,char(187));//Top Right
	printLVd(x+0,y+1,1,char(186));//Left
	printLVd(x+6,y+1,1,char(186));//Right
	printLHa(x+0,y+2,1,char(200));//Bot Left
	printLHa(x+6,y+2,1,char(188));//Bot Right
}
void setConsoleColor(int textColor,int backgroundColor){						//Modifica el color de la consola
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),backgroundColor*16+textColor);
}
void printHeader(int width,string text){															//Imprime el encabezado de las interfaces de numeros en otro idioma
	system("cls");
	printCentered(width,text);
	printCharacters(width,char(205));
	cout<<endl;
}
	
void stringSeparated(string word, char fill, bool lastSeparator){						//Imprime un string con sus caracteres separados por un separador
	int wordLen=word.length();
	for(int i =0; i<wordLen;i++){
		cout<<word[i];
		if(i!=wordLen-1 or lastSeparator){
			cout<<fill;
		}
	}
}
void printCharacters(int len, char character){											//Imprime una linea de longitud len del caracter
	for (int i=0;i<len;i++)
		cout<<character;
}
void printCentered(int len, string frase){												//Imprime la frase deseada centrada respecto a len
	int fraseLen = frase.length();
	for(int i=0; i<len/2-fraseLen/2;i++)
		cout<<' ';
	cout<<frase<<endl;
}
void printNumerated(string words[], int wordsLen){								//Imprime la lista de string numerada
	for(int i=0;i<wordsLen;i++){
		cout<<i+1<<".- "<<words[i]<<endl;
	}
}
void searchforRepetitions(string cadena, char caracter, int repetitions[], int & repSize){	//Ingresa un string y un caracter y te devuelve por referencia un vector con
	int pos=cadena.find(caracter);															//las posiciones de este caracter en el string
	while(pos!=-1){
		repetitions[repSize] = pos;
		repSize+=1;
		pos = cadena.find(caracter,pos+1);
	}
}
void fillString(string &  cadena, int size, char fill){									//llena un string vacio con un caracter
	for (int i=0; i<size;i++){
		cadena+= fill;
	}
}
void fillPositions(string & cadena, const int positions[], int posSize, char fill){		//Modifica las posiciones de un string con un caracter
	for(int i =0;i<posSize;i++){
		cadena[positions[i]]= fill;
	}
}
int indexSearcher(string word, string words[], int wordsLen){					//Verifica que el ingreso esté en una lista de palabras, devuelve el índice de la palabra si lo encuentra y -1 si no
	int i=0, index=-1;
	while(i<wordsLen and index==-1){
		if(tolower(words[i])==tolower(word))
			index=i;
		i++;
	}
	return index;
}
string tolower(string word){
	int wordLen=word.length();
	for(int i=0;i<wordLen;i++){
		word[i]=tolower(word[i]);
	}
	return word;
}

int charToInt(char a){
	return a-'0';
}	
char intToChar(int i){
	return i+'0';
}
void ahorcado(string words[], user & u){																//Proceso principal del juego Ahorcado
	windowSize(AHORCADO_WIDTH, 13);
	string secretWord = randomWord(words, SIZE);
	int secretWordLen = secretWord.length();
	string word, usedChar, mensaje= message(1);
	//word es la palabra que va descubriendo el usuario, usedChar las letras que va usando y message el mensaje al final de cada impresión del ahorcado
	fillString(word, secretWordLen,'_' );
	int repetitions[SIZE], repSize = 0;
	char ingressedChar;
	int points = 100, lettersFounded =0;
	bool isLetter, isRepeated;
	do{																			
		//Bucle principal del ahorcado, cada ciclo es un ingreso de caracteres
		system("cls");															
		ahorcadoPrint(word,points,usedChar, mensaje);
		scanf("%1s",&ingressedChar);
		ingressedChar = tolower(ingressedChar);
		if (ingressedChar == char(165)) ingressedChar-=1;
		isRepeated = usedChar.find(ingressedChar)+1;
		isLetter = isalpha(ingressedChar) or ingressedChar==char(164);
		//Se pasa a minuscula el ingreso, se verifica que sea letra y si ya se ingresó previamente
		if(not isRepeated and isLetter){
			//Caso que no esté repetida y sea letra, se concatena a usedChar la letra y se guarda en el vector repetitions
			//las posiciones dentro de la palabra en las que está la letra
			usedChar+=ingressedChar;
			searchforRepetitions(secretWord,ingressedChar,repetitions,repSize);
			if(repSize !=0){
				//Si el tamaño del vector de repeticiones no es cero, se reemplaza
				//en el vector word con la letra en sus correspondiente posición
				fillPositions(word,repetitions,repSize,ingressedChar);
				lettersFounded +=repSize;
				repSize=0;
				mensaje = message(2);
				PlaySoundA((LPCSTR) "respuestacorecta.wav",NULL,SND_FILENAME | SND_ASYNC);
			}else{
				//Si el tamaño del vector de repeticiones es cero, no está en la palabra
				//se restan putos
				points-=10;
				mensaje = message(3);
				PlaySoundA((LPCSTR) "respuestaincorrecta.wav",NULL,SND_FILENAME | SND_ASYNC);
			}
		}
		if(not isLetter){
			mensaje = message(4);
		}else if (isRepeated){
			mensaje = message(5);
		}
	}while(secretWordLen>lettersFounded and points>0);	//El juego se mantiene mientras las letras encontradas sean menores que las de la palabra secreta y los puntos mayores que cero
	if(points>0){
		mensaje = message(6);
		PlaySoundA((LPCSTR) "sonidovictoria.wav",NULL,SND_FILENAME | SND_ASYNC);
	}else{
		mensaje  =message(7);
		PlaySoundA((LPCSTR) "derrota.wav",NULL,SND_FILENAME | SND_ASYNC);
	}
	ahorcadoPrint(secretWord,points,usedChar, mensaje);
	cout<<endl;
	addPoints(u,points);
}	
string message(int n){
	string retorno;
	switch(n){
	case 1:
		retorno="Ingrese una letra para ir descubriendo la palabra oculta: ";
		break;
	case 2:
		retorno="Bien ahi, siga asi, cual sera su siguiente letra?: ";
		break;
	case 3:
		retorno="Que no decaiga, arriesgue de vuelta: ";
		break;
	case 4:
		retorno="Por favor, ingrese una letra: ";
		break;
	case 5:
		retorno="Letra ya ingresada, por favor ingrese otra: ";
		break;
	case 6:
		retorno="Felicitaciones, ha ganado!";
		break;
	case 7:
		retorno="Ha perdido, mas suerte la proxima!";
		break;
	}
	return retorno;
}
void ahorcadoPrint(string word,int points, string usedChar, string lastMessage){		//Interfaz gráfica del ahorcado
	system("cls");
	printCentered(AHORCADO_WIDTH,"AHORCADO");
	printCharacters(AHORCADO_WIDTH,char(205));
	cout<<endl;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<gallow(points,i,j);
		}
		if(i==2){
			cout<<"		";
			stringSeparated(word,' ');
		}
		if(i==5){
			cout<<" Letras ya usadas: ";
			stringSeparated(usedChar,',',false);
		}
		if(i==6){
			cout<<" Tiene "<<points<<" puntos";
		}
		cout<<endl;
	}
	cout<<lastMessage;
}
char gallow(int points, int i, int j){											//Ingresan la cantidad de puntos, las coordenadas i y j y devuelve el char de la horca correspondiente
	char retorno;																
	char hangingGuy[9][9]= 
	{
		{' ',' '      ,char(201),char(205),char(205),char(205),char(187),' ' ,' '},
		{' ',' '      ,char(186),' '      ,' '      ,' '      ,char(186),' ' ,' '},
		{' ',' '      ,char(186),' '      ,' '      ,' '      ,'O'      ,' ' ,' '},
		{' ',' '      ,char(186),' '      ,'_'      ,'/'      ,'|'      ,'\\','_'},	
		{' ',' '      ,char(186),' '      ,' '      ,' '      ,'|'      ,' ' ,' '},
		{' ',' '      ,char(186),' '      ,'_'      ,'/'      ,' '      ,'\\','_'},
		{' ',' '      ,char(219),' '      ,' '      ,' '      ,' '      ,' ' ,' '},
		{' ',char(219),char(219),char(219),' '      ,' '      ,' '      ,' ' ,' '}
	};
	int pointsMatrix[9][9]= 
	{
		{100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,90 ,100,100},
		{100,100,100,100,30 ,70 ,80 ,60 ,20 },	
		{100,100,100,100,100,100,80 ,100,100},
		{100,100,100,100,10 ,50 ,100,40 ,0  },
		{100,100,100,100,100,100,100,100,100},
		{100,100,100,100,100,100,100,100,100}
	};
	if(pointsMatrix[i][j]>=points){
		retorno = hangingGuy[i][j];
	}else{
		retorno = ' ';
	}
	return retorno;
}
void numerosOtroIdioma(){														//Proceso principal del juego Numeros en Otro Idioma
	int language, languagesLen=5, number, increase;
	string languages[]={
			"Espanol",		//0 es Español
			"Ingles",		//1 es Ingles
			"Italiano",		//2 es Italiano
			"Portugues",	//3 es Portugues
			"Frances"		//4 es Francés
	};
	language = numerosLanguageGet(languages,languagesLen);
	number = numerosNumberGet();
	increase = numerosIncreaseGet();
	numerosOutput(number, languages, language, increase);
}	
string getNumber(int number, int country){										//Devuelve el número escrito en el lenguaje correspondiente								
	string numbers[10][6] =
		{
		{"cero"  ,"cero" ,"zero"   ,"zero"  ,"zero"},
		{"uno"   ,"one"  ,"uno"    ,"um"    ,"un"},
		{"dos"   ,"two"  ,"due"    ,"dois"  ,"deux"},
		{"tres"  ,"three","tre"    ,"tres"  ,"trois"},
		{"cuatro","four" ,"quattro","quatro","quatre"},
		{"cinco" ,"five" ,"cinque" ,"cinco" ,"cinq"},
		{"seis"  ,"six"  ,"sei"    ,"seis"  ,"six"},
		{"siete" ,"seven","sette"  ,"sete"  ,"sept"},
		{"ocho"  ,"eight","otto"   ,"oito"  ,"huit"},
		{"nueve" ,"nine" ,"nove"   ,"nove"  ,"neuf"},
	};
	return numbers[number][country];
}
int languageProcessor(string input, string options[], int optionsLen){			//Discrimina si el ingreso es literal (escrito con una palabra) o numérico, y devuelve el índice del literal en una lista o el número		
	int retorno=-1;
	if (input.length()==1 and isdigit(input[0])and charToInt(input[0])<optionsLen+1 and charToInt(input[0])>0){
		retorno = charToInt(input[0])-1;
	}else{
		retorno=indexSearcher(input,options,optionsLen);
	}
	return retorno;
}
void numerosOtroIdiomaHeader(){															//Imprime el encabezado de las interfaces de numeros en otro idioma
	system("cls");
	printCentered(NUMEROS_OTRO_IDIOMA_WIDTH,"NUMEROS EN OTRO IDIOMA");
	printCharacters(NUMEROS_OTRO_IDIOMA_WIDTH,char(205));
	cout<<endl;
}
int numerosLanguageGet(string languages[],int languagesLen){					//Imprime interfaz para seleccionar idioma, y devuelve el numero de idioma
	bool error=false;
	int language=-1;
	string input;
	windowSize(NUMEROS_OTRO_IDIOMA_WIDTH, 9);
	while(language<0){
		system("cls");
		numerosOtroIdiomaHeader();
		printNumerated(languages,languagesLen);
		if(error)
			cout<<"Error, por favor escriba el nombre o numero del lenguage en el que desea el numero: ";
		else
			cout<<"Por favor escriba el nombre o numero del lenguaje en que desea el numero: ";
		cin>>input;
		language = languageProcessor(input,languages, languagesLen);
		if (language == -1)
			error = true;
	}
	return language;
}
int numerosNumberGet(){															//Ingreso de un dígito con interfaz
	bool error =false;
	int number;
	string input;
	windowSize(NUMEROS_OTRO_IDIOMA_WIDTH, 4);
	do{
		numerosOtroIdiomaHeader();
		if(error)
			cout<<"Error, por favor escriba un numero del 0 al 9: ";
		else
			cout<<"Ingrese el numero del 0 al 9 del cual desea saber su escritura: ";
		cin>>input;
		number = numberProcessor(input);
		if (number==-1)
			error=true;
	}while(number<0);
	return number;
	}
int numerosIncreaseGet(){															//Ingreso de un dígito con interfaz
	bool error =false;
	int increase=-1, aux;
	string input;
	windowSize(NUMEROS_OTRO_IDIOMA_WIDTH, 4);
	do{
		numerosOtroIdiomaHeader();
		if(error)
			cout<<"Error, por favor escriba un numero del 1 al 4: ";
		else
			cout<<"Ingrese el factor de incremento como un numero del 1 al 4: ";
		cin>>input;
		aux=numberProcessor(input);
		if (aux>0 and aux<5){
			increase = aux;}
		if (increase==-1)
			error=true;
	}while(increase<0);
	return increase;
}
int numberProcessor(string input){												//Devuelve entero si la entrada es un dígito del 1-9 y -1 si no
	int retorno = -1;
	if (input.length()==1 and isdigit(input[0])){
		retorno = charToInt(input[0]);
	}
	return retorno;
}
void sevenDigits(int increase, int number){										//Imprime el display 7 segmentos para el incremento correspondiente, la numeración de los segmentos se expresa a continuación
	// -----  -0
	//|     |
	//|-1   |-2
	//|     |
	// -----  -3
	//|     |
	//|-4   |-5
	//|     |
	// ----- -6
	horizontalSegment(increase,numberSegment(number,0));
	verticalSegment(increase,numberSegment(number,1),numberSegment(number,2));
	horizontalSegment(increase,numberSegment(number,3));
	verticalSegment(increase,numberSegment(number,4),numberSegment(number,5));
	horizontalSegment(increase,numberSegment(number,6));
	cout<<endl;
}
bool numberSegment(int number, int segment){									//Devuelve true si el segmento se debe mostrar para ese numero
	bool allsegments[][7] =
		{
			{1,1,1,0,1,1,1},//0
			{0,0,1,0,0,1,0},//1
			{1,0,1,1,1,0,1},//2
			{1,0,1,1,0,1,1},//3
			{0,1,1,1,0,1,0},//4
			{1,1,0,1,0,1,1},//5
			{1,1,0,1,1,1,1},//6
			{1,0,1,0,0,1,0},//7
			{1,1,1,1,1,1,1},//8
			{1,1,1,1,0,1,1}//9
	};
	return allsegments[number][segment];
}
void horizontalSegment(int increase, bool showed){								//Imprime los segmentos horizontales del display 7 segmentos
	cout<<' ';
	for(int i=0;i<increase;i++){
		if (showed)
			cout<<'-';
		else
			cout<<' ';
	}
	cout<<' ';
	cout<<endl;
}
void verticalSegment(int increase, bool showed1,bool showed2){					//Imprime los segmentos verticales del display 7 segmentos
	for(int i=0;i<increase;i++){
		if (showed1)
			cout<<'|';
		else
			cout<<' ';
		for(int j=0;j<increase;j++){
			cout<<' ';
		}
		if (showed2)
			cout<<'|';
		else
			cout<<' ';
		cout<<endl;
	}
}
void numerosOutput(int number, string languages[], int language, int increase){				//Imprime la salida de Numeros en Otro Idioma			
	windowSize(NUMEROS_OTRO_IDIOMA_WIDTH,40);
	numerosOtroIdiomaHeader();
	cout<<"Forma escrita en "<<languages[language]<<": "<<getNumber(number,language)<<endl;
	sevenDigits(increase,number);;
}
void windowSize(int width,int heigth){									//Configura el tamaño de la ventana
	string widthString = to_string(width), heigthString = to_string(heigth);
	string configuracion = "mode con: cols=";									
	configuracion.append(widthString);
	configuracion.append(" lines=");
	configuracion.append(heigthString);
	system(configuracion.c_str());	
}
void startPage(){																//Interfaz de inicio
	
	windowSize(120,50);
	system("color E4");
	int i=0;
	PlaySoundA((LPCSTR) "pantallainicio.wav",NULL,SND_FILENAME | SND_ASYNC|SND_LOOP);
	printArea(96,0,24,50,char(176));
	centerIn(96,47,120,"Presione ENTER");
	centerIn(96,48,120,"para continuar");
	centerIn(96,11,120,"UTN");
	centerIn(96,13,120,"Facultad Regional");
	centerIn(96,15,120,"Santa Fe");
	logoUTN(99,1);
	while(not GetAsyncKeyState(VK_RETURN)){
		//printBigIcarruzel(10,10,"ALGORITMOS",10,i);
		printIdiomas(1,1,"ALGORITMOS",10,i+2);
		printPara(1,17,"ALGORITMOS",10,i+18);
		printAprender(1,34,"ALGORITMOS",10,i+35);
		i++;
		Sleep(50);
		gotoxy(120,50);
	}
	PlaySoundA((LPCSTR) "pantallainicio.wav",NULL,SND_FILENAME | SND_ASYNC);
}
void gotoxy(SHORT x,SHORT y) {
	COORD cp = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}
void printArea(int xi, int yi,int lenx,int leny,char caracter){					//Imprime el caracter deseado en el área, mediante la esquina superior derecha y el tamaño
	for(int i=0;i<leny;i++){
		printLHa(xi,yi+i,lenx,caracter);
	}
}
void carruzelH(int xi,int yi, int len, string palabra,int palabraLen, int despl){//Imprime en la linea horizontal deseada de manera repetitiva el string con un defasaje despl
	gotoxy(xi,yi);
	for(int i=0;i<len;i++){
		cout<<palabra[(i+despl)%palabraLen];
	}
}
void carruzelV(int xi,int yi, int len,string palabra, int palabraLen,int despl){//Imprime en la linea vertical deseada de manera repetitiva el string con un defasaje despl
	for(int i=0;i<len;i++){
		gotoxy(xi,yi+i);
		cout<<palabra[(i+despl)%palabraLen];
	}
}
void printLVd(int xi, int yi, int len, char caracter){							//Imprime en la linea vertical deseada los caracteres, con alineacion partiendo desde arriba
	for(int i=0;i<len;i++){
		gotoxy(xi,yi+i);
		cout<<caracter;
	}
}
void printLVa(int xi, int yi, int len, char caracter){							//Imprime en la linea vertical deseada los caracteres, con alineacion partiendo desde abajo
	for(int i=0;i<len;i++){
		gotoxy(xi,yi-i);
		cout<<caracter;
	}
}
void printLHa(int xi, int yi, int len, char caracter){							//Imprime en la linea horizontal deseada los caracteres, con alineacion partiendo desde la izquierda
	for(int i=0;i<len;i++){
		gotoxy(xi+i,yi);
		cout<<caracter;
	}
}
void printLHd(int xi, int yi, int len, char caracter){							//Imprime en la linea horizontal deseada los caracteres, con alineacion partiendo desde la derecha
	for(int i=0;i<len;i++){
		gotoxy(xi-i,yi);
		cout<<caracter;
	}
}	
//Letras en carruzel
void printDcarruzel(int xi,int yi, string palabra, int palabraLen, int despl){//Imprime la d minuscula 9x11
	carruzelV(xi,yi,11,palabra,palabraLen,despl);
	carruzelV(xi+1,yi,11,palabra,palabraLen,despl+1);
	carruzelH(xi+2,yi,5,palabra,palabraLen,despl+2);
	carruzelH(xi+2,yi+10,5,palabra,palabraLen,despl+2);
	carruzelV(xi+7,yi+1,1,palabra,palabraLen,despl+8);
	carruzelV(xi+7,yi+9,1,palabra,palabraLen,despl+8);
	carruzelV(xi+8,yi+2,7,palabra,palabraLen,despl+10);
}
void printIcarruzel(int xi,int yi, string palabra, int palabraLen, int despl){//Imprime la i minuscula 2x14
	carruzelV(xi,yi,2,palabra,palabraLen,despl);
	carruzelV(xi,yi+4,10,palabra,palabraLen,despl+4);
	carruzelV(xi+1,yi,2,palabra,palabraLen,despl+1);
	carruzelV(xi+1,yi+4,10,palabra,palabraLen,despl+5);
}
void printOcarruzel(int xi,int yi, string palabra, int palabraLen, int despl){//Imprime la o minuscula 11x11
	carruzelV(xi,yi+2,7,palabra,palabraLen,despl+2);
	carruzelV(xi+10,yi+2,7,palabra,palabraLen,despl+12);
	carruzelH(xi+1,yi+1,2,palabra,palabraLen,despl+2);
	carruzelH(xi+1,yi+9,2,palabra,palabraLen,despl+10);
	carruzelH(xi+8,yi+1,2,palabra,palabraLen,despl+9);
	carruzelH(xi+8,yi+9,2,palabra,palabraLen,despl+17);
	carruzelH(xi+3,yi,5,palabra,palabraLen,despl+3);
	carruzelH(xi+3,yi+10,5,palabra,palabraLen,despl+13);
	
}
void printMcarruzel(int xi,int yi, string palabra, int palabraLen, int despl){//Imprime la m minuscula 15x11
	carruzelH(xi,yi,14,palabra,palabraLen,despl);
	carruzelV(xi,yi+1,10,palabra,palabraLen,despl+1);
	carruzelV(xi+1,yi+1,10,palabra,palabraLen,despl+2);
	carruzelV(xi+7,yi+1,10,palabra,palabraLen,despl+8);
	carruzelV(xi+8,yi+1,10,palabra,palabraLen,despl+9);
	carruzelV(xi+14,yi+1,10,palabra,palabraLen,despl+15);
	carruzelV(xi+15,yi+1,10,palabra,palabraLen,despl+16);
}
void printAcarruzel(int xi,int yi, string palabra, int palabraLen, int despl){//Imprime la a minuscula 11x11
	carruzelH(xi+1,yi+2,2,palabra,palabraLen,despl+2);
	carruzelH(xi+2,yi+1,7,palabra,palabraLen,despl+2);
	carruzelV(xi+9,yi+2,10,palabra,palabraLen,despl+10);
	carruzelV(xi+10,yi+2,3,palabra,palabraLen,despl+11);
	carruzelH(xi+2,yi+6,7,palabra,palabraLen,despl+7);
	carruzelH(xi+1,yi+7,2,palabra,palabraLen,despl+7);
	carruzelH(xi,yi+8,2,palabra,palabraLen,despl+7);
	carruzelH(xi,yi+9,2,palabra,palabraLen,despl+8);
	carruzelH(xi+1,yi+10,2,palabra,palabraLen,despl+10);
	carruzelH(xi+2,yi+11,7,palabra,palabraLen,despl+12);
	carruzelV(xi+10,yi+7,5,palabra,palabraLen,despl+16);
}
void printScarruzel(int xi,int yi, string palabra, int palabraLen, int despl){//Imprime la s minuscula 9x11
	carruzelH(xi+1,yi+1,7,palabra,palabraLen,despl);
	carruzelV(xi,yi+2,4,palabra,palabraLen,despl);
	carruzelV(xi+1,yi+2,5,palabra,palabraLen,despl+1);
	carruzelV(xi+8,yi+2,1,palabra,palabraLen,despl+8);
	carruzelH(xi+1,yi+6,6,palabra,palabraLen,despl+5);
	carruzelV(xi+7,yi+7,4,palabra,palabraLen,despl+12);
	carruzelV(xi+8,yi+7,3,palabra,palabraLen,despl+13);
	carruzelH(xi,yi+10,1,palabra,palabraLen,despl+8);
	carruzelH(xi+1,yi+11,6,palabra,palabraLen,despl+9);
}
void printRcarruzel(int xi,int yi, string palabra, int palabraLen, int despl){//Imprime la r minuscula 8x11
	carruzelV(xi,yi,11,palabra,palabraLen,despl);
	carruzelV(xi+1,yi,11,palabra,palabraLen,despl+1);
	carruzelH(xi+2,yi+1,5,palabra,palabraLen,despl+3);
	carruzelH(xi+2,yi+2,1,palabra,palabraLen,despl+4);
	carruzelH(xi+7,yi+2,1,palabra,palabraLen,despl+9);
}
void printPcarruzel(int xi,int yi, string palabra, int palabraLen, int despl){//Imprime la p minuscula 8x11
	carruzelV(xi,yi,11,palabra,palabraLen,despl);
	carruzelV(xi+1,yi,11,palabra,palabraLen,despl+1);
	carruzelH(xi+2,yi,5,palabra,palabraLen,despl+2);
	carruzelH(xi+2,yi+5,5,palabra,palabraLen,despl+7);
	carruzelV(xi+7,yi+1,4,palabra,palabraLen,despl+8);
}
void printEcarruzel(int xi,int yi, string palabra, int palabraLen, int despl){//Imprime la e minuscula 8x11
	carruzelH(xi+1,yi,6,palabra,palabraLen,despl+7);
	carruzelV(xi,yi+1,9,palabra,palabraLen,despl+1);
	carruzelV(xi+1,yi+1,6,palabra,palabraLen,despl+2);
	carruzelV(xi+1,yi+9,1,palabra,palabraLen,despl+10);
	carruzelH(xi+2,yi+5,7,palabra,palabraLen,despl+7);
	carruzelH(xi+6,yi+1,2,palabra,palabraLen,despl+7);
	carruzelH(xi+7,yi+2,2,palabra,palabraLen,despl+9);
	carruzelV(xi+8,yi+3,2,palabra,palabraLen,despl+11);
	carruzelH(xi+1,yi+10,7,palabra,palabraLen,despl+11);
	carruzelH(xi+7,yi+9,2,palabra,palabraLen,despl+16);
}
void printNcarruzel(int xi,int yi, string palabra, int palabraLen, int despl){//Imprime la n minúscula 13x11
	carruzelV(xi,yi,11,palabra,palabraLen,despl);
	carruzelV(xi+1,yi,11,palabra,palabraLen,despl+1);
	carruzelH(xi+2,yi,9,palabra,palabraLen,despl+2);
	carruzelV(xi+11,yi+1,10,palabra,palabraLen,despl+12);
	carruzelV(xi+12,yi+2,9,palabra,palabraLen,despl+14);
}
void printBigIcarruzel(int xi,int yi, string palabra, int palabraLen, int despl){//Imprime la I mayúscula en carruzel 13x16
	carruzelH(xi+1,yi,11,palabra,palabraLen,despl+1);
	carruzelH(xi,yi+1,13,palabra,palabraLen,despl+1);
	carruzelH(xi+1,yi+2,11,palabra,palabraLen,despl+3);
	carruzelV(xi+5,yi+3,9,palabra,palabraLen,despl+8);
	carruzelV(xi+6,yi+3,9,palabra,palabraLen,despl+9);
	carruzelV(xi+7,yi+3,9,palabra,palabraLen,despl+10);
	carruzelH(xi+1,yi+12,11,palabra,palabraLen,despl+13);
	carruzelH(xi,yi+13,13,palabra,palabraLen,despl+13);
	carruzelH(xi+1,yi+14,11,palabra,palabraLen,despl+15);
}
void printBigPcarruzel(int xi,int yi, string palabra, int palabraLen, int despl){//Imprime la P mayúscula en carruzel 14x15
	carruzelV(xi,yi,16,palabra,palabraLen,despl);
	carruzelV(xi+1,yi,16,palabra,palabraLen,despl+1);
	carruzelV(xi+2,yi,16,palabra,palabraLen,despl+2);
	carruzelH(xi+3,yi,6,palabra,palabraLen,despl+3);
	carruzelH(xi+3,yi+1,8,palabra,palabraLen,despl+4);
	carruzelH(xi+3,yi+9,6,palabra,palabraLen,despl+12);
	carruzelH(xi+3,yi+8,8,palabra,palabraLen,despl+11);
	carruzelH(xi+10,yi+2,3,palabra,palabraLen,despl+12);
	carruzelH(xi+10,yi+7,3,palabra,palabraLen,despl+17);
	carruzelV(xi+11,yi+3,4,palabra,palabraLen,despl+14);
	carruzelV(xi+12,yi+3,4,palabra,palabraLen,despl+15);
	carruzelV(xi+13,yi+3,4,palabra,palabraLen,despl+16);
}
void printBigAcarruzel(int xi,int yi, string palabra, int palabraLen, int despl){//Imprime la A mayuscula en carruzel 13x15 
	carruzelV(xi,yi+3,13,palabra,palabraLen,despl+3);
	carruzelV(xi+1,yi+2,14,palabra,palabraLen,despl+3);
	carruzelV(xi+2,yi+1,3,palabra,palabraLen,despl+3);
	carruzelV(xi+3,yi,3,palabra,palabraLen,despl+6);
	carruzelH(xi+4,yi,8,palabra,palabraLen,despl+12);
	carruzelH(xi+4,yi+1,9,palabra,palabraLen,despl+5);
	carruzelH(xi+2,yi+10,8,palabra,palabraLen,despl+12);
	carruzelH(xi+2,yi+11,8,palabra,palabraLen,despl+13);
	carruzelV(xi+10,yi+2,14,palabra,palabraLen,despl+12);
	carruzelV(xi+11,yi+2,14,palabra,palabraLen,despl+13);
	carruzelV(xi+12,yi+2,14,palabra,palabraLen,despl+14);
	
}
//Palabras en carruzel
void printIdiomas(int xi,int yi,string  palabra,int  palabraLen,int  despl){//Imprime la palabra idiomas con justificacion arriba a la izquierda	
	printBigIcarruzel(xi, yi,  palabra,  palabraLen,  despl);
	printDcarruzel(xi+15, yi+4,  palabra,  palabraLen,  despl+20);
	printIcarruzel(xi+26, yi+1,  palabra,  palabraLen,  despl+28);
	printOcarruzel(xi+30, yi+4,  palabra,  palabraLen,  despl+35);
	printMcarruzel(xi+43,yi+4,  palabra,  palabraLen,  despl+48);
	printAcarruzel(xi+61,yi+3,  palabra,  palabraLen,  despl+65);
	printScarruzel(xi+74,yi+3,  palabra,  palabraLen,  despl+78);
}
void printPara(int xi,int yi,string  palabra,int  palabraLen,int  despl){//Imprime la palabra para con justificación arriba a la izquierda
	printBigPcarruzel(xi, yi,  palabra,  palabraLen,  despl);
	printAcarruzel(xi+15, yi+4,  palabra,  palabraLen,  despl+19);
	printRcarruzel(xi+28, yi+5,  palabra,  palabraLen,  despl+32);
	printAcarruzel(xi+37, yi+4,  palabra,  palabraLen,  despl+41);
}
void printAprender(int xi,int yi,string  palabra,int  palabraLen,int  despl){//Imprime la palabra aprender con justificación arriba a la izquierda
	printBigAcarruzel(xi, yi,  palabra,  palabraLen,  despl);
	printPcarruzel(xi+15, yi+5,  palabra,  palabraLen,  despl+20);
	printRcarruzel(xi+25, yi+5,  palabra,  palabraLen,  despl+30);
	printEcarruzel(xi+35, yi+5,  palabra,  palabraLen,  despl+40);
	printNcarruzel(xi+46,yi+5,  palabra,  palabraLen,  despl+51);
	printDcarruzel(xi+62,yi+5,  palabra,  palabraLen,  despl+67);
	printEcarruzel(xi+74,yi+5,  palabra,  palabraLen,  despl+79);
	printRcarruzel(xi+85,yi+5,  palabra,  palabraLen,  despl+90);
	
}
void centerIn(int xi,int yi, int xf, string word){								//Imprime el string centrado entre xi y xf
	printIn(xi+((xf-xi-word.length())/2),yi,word);
}
void printIn(int xi,int yi,string word){										//Imprime el string en la posición deseada
	gotoxy(xi,yi);
	cout<<word;
}
void logoUTN(int xi, int yi){													//Imprime el logo de la utn res:18x9 con justificacion arriba a la izquierda
	char c= char(178);
	char b= ' ';
	char logo[][18]={
		{c,c,c,b,b,b,b,b,c,c,b,b,b,b,b,c,c,c},
		{c,c,c,b,b,b,b,b,c,c,b,b,b,b,b,c,c,c},
		{b,b,c,c,c,c,c,b,c,c,b,c,c,c,c,c,b,b},
		{b,b,b,b,b,b,c,c,c,c,c,c,b,b,b,b,b,b},
		{c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c},
		{b,b,b,b,b,b,c,c,c,c,c,c,b,b,b,b,b,b},
		{b,b,c,c,c,c,c,b,c,c,b,c,c,c,c,c,b,b},
		{c,c,c,b,b,b,b,b,c,c,b,b,b,b,b,c,c,c},
		{c,c,c,b,b,b,b,b,c,c,b,b,b,b,b,c,c,c}
	};
	for(int i=0;i<9;i++){
		for(int j=0;j<18;j++){
			gotoxy(xi+j,yi+i);
			cout<<logo[i][j];
		}
	}
}
string randomWord(string words[], int size){
	return words[rand()%size];
}
void randomWords(string arreglo [],int wordsAmount, string palabras[], int size){
	string palabra;
	for(int i=0;i<wordsAmount;i++){
		arreglo[i]=" ";
		do{
		palabra = palabras[rand()%SIZE];
		}while(indexSearcher(palabra,arreglo,i)!=-1);
		arreglo[i]=palabra;
	}
}
void fileExtractor(string arreglo[]){
	int i=0;
	string line;
	archivo Entrada;
	Entrada = setup("TPAEDD","palabras-3.txt");
	if (apertura(Entrada)==false){
		errorWithFile();
	} else{
		bool final=false;
		do{
			line=leerLinea(Entrada,final);
			if(not final)
			arreglo[i]=line;
			i++;
		}while(not final);
	}
	cierre(Entrada);
}
void errorWithFile(){
	cout<<"Error con la apertura del archivo";
}

	
void MenuPrincipal(string words[], user & u){

windowSize(MENUPRINCIPAL_WIDTH,25);

char opcion;
do{
system("cls");
system("color F4");
InterfaceMenuPrincipal();
cout<<"Ingrese una opcion: ";
cin>>opcion;
while((opcion<'1' or opcion>'3') and opcion!='X' and opcion!='x'){
	system("cls");
	InterfaceMenuPrincipal();
	cout<<"El caracter ingresado es incorrecto, ingresar un entero del 1 al 3 o X (o x): ";
	cin>>opcion;
}

switch(opcion){
case '1':
	system ("color F2");
	Abecedarios();
	
	break;
case '2':
	system ("color F5");
	Juegos(words, u);
	break;
case '3':
	system ("color F5");
	ProcesadorTexto();
	break;
}
}while(opcion!='x' and opcion!='X');

}

void InterfaceMenuPrincipal(){//Muestra la interface del menu principal
printCentered(MENUPRINCIPAL_WIDTH,"MENU PRINCIPAL");
printCharacters(MENUPRINCIPAL_WIDTH, char(205));
cout<<"1.- Abecedarios"<<endl;
cout<<"2.- Juegos"<<endl;
cout<<"3.- Procesador de texto"<<endl;
cout<<"X.- Salir de la aplicacion"<<endl;
cout<<endl;
}

void ProcesadorTexto(){//Funcion del menu del procesador de texto
	char opcion;
	do{
		windowSize(MENUPRINCIPAL_WIDTH,25);
		system("cls");
		InterfaceProcesadorTexto();
		cout<<"Ingrese una opcion: ";
		cin>>opcion;
		while((opcion<'1' or opcion>'2') and opcion!='X' and opcion!='x'){
			system("cls");
			InterfaceProcesadorTexto();
			cout<<"El caracter ingresado es incorrecto, ingresar un entero del 1 al 2 o X (o x): ";
			cin>>opcion;
		}
		switch(opcion){
		case '1':
			system("cls");
			printCentered(MENUPRINCIPAL_WIDTH, "ESTADISTICAS A NIVEL DE CARACTERES");
			printCharacters(MENUPRINCIPAL_WIDTH, char(205));
			opcion1();
			system("pause");
			break;
		case '2':
			system("cls");
			printCentered(MENUPRINCIPAL_WIDTH, "ESTADISTICAS A NIVEL DE PALABRAS");
			printCharacters(MENUPRINCIPAL_WIDTH, char(205));
			opcion2();
			/*system("cls");
			printCentered(MENUPRINCIPAL_WIDTH, "ESTADISTICAS A NIVEL DE PALABRAS");
			printCharacters(MENUPRINCIPAL_WIDTH, char(205));
			lista();*/
			break;
		}
	}while(opcion!='x' and opcion!='X');
}
	void InterfaceProcesadorTexto(){//Muestra la interface del Procesador de texto
		printCentered(MENUPRINCIPAL_WIDTH, "MENU PROCESADOR DE TEXTO");
		printCharacters(MENUPRINCIPAL_WIDTH, char(205));
		cout<<"1.- Estadisticas a nivel caracteres"<<endl;
		cout<<"2.- Estadisticas a nivel palabras"<<endl;
		cout<<"X.- Volver al menu principal"<<endl;
		cout<<endl;
	}
void Abecedarios(){//Funcion del menu de abecedarios
	
	windowSize(ABECEDARIOS_WIDTH,25);
	char opcion;
	do{
		system("cls");
		InterfaceAbecedarios();
		cout<<"Ingrese una opcion: ";
		cin>>opcion;
		while((opcion<'1' or opcion>'5') and opcion!='X' and opcion!='x'){
			system("cls");
			InterfaceAbecedarios();
			cout<<"El caracter ingresado es incorrecto, ingresar un entero del 1 al 5 o X (o x): ";
			cin>>opcion;
		}
		switch(opcion){
		case '1':
			system("cls");
			printCentered(ABECEDARIOS_WIDTH, "ABECEDARIO ESPANIOL");
			printCharacters(ABECEDARIOS_WIDTH, char(205));
			Espaniol();
			break;
		case '2':
			system("cls");
			printCentered(ABECEDARIOS_WIDTH, "ABECEDARIO INGLES");
			printCharacters(ABECEDARIOS_WIDTH, char(205));
			Ingles();
			break;
		case '3':
			system("cls");
			printCentered(ABECEDARIOS_WIDTH, "ABECEDARIO ITALIANO");
			printCharacters(ABECEDARIOS_WIDTH, char(205));
			Italiano();
			break;
		case '4':
			system("cls");
			printCentered(ABECEDARIOS_WIDTH, "ABECEDARIO PORTUGUES");
			printCharacters(ABECEDARIOS_WIDTH, char(205));
			Portugues();
			break;
		case '5':
			system("cls");
			printCentered(ABECEDARIOS_WIDTH, "ABECEDARIO FRANCES");
			printCharacters(ABECEDARIOS_WIDTH, char(205));
			Frances();
			break;
		}
	}while(opcion!='x' and opcion!='X');
}
void InterfaceAbecedarios(){//Muestra la interface del menu abecedarios
	printCentered(ABECEDARIOS_WIDTH, "MENU ABECEDARIOS");
	printCharacters(ABECEDARIOS_WIDTH, char(205));
	cout<<"1.- Espanol"<<endl;
	cout<<"2.- Ingles"<<endl;
	cout<<"3.- Italiano"<<endl;
	cout<<"4.- Portugues"<<endl;
	cout<<"5.- Frances"<<endl;
	cout<<"X.- Volver al menu principal"<<endl;
	cout<<endl;
}
		
void Espaniol(){//Muestra los alfabetos y caracteres especiales del Espaniol
	char abcEspanol[27];
	int t=26;
	AbecedarioBase(abcEspanol, t);
	int i=t+1;
	while(abcEspanol[i]!='o'){
		abcEspanol[i]=abcEspanol[i-1];
		i--;
	}
	abcEspanol[i]=char(164);
	t=27;
	system("cls");
	windowSize(ABECEDARIOS_WIDTH,25);
	printCentered(ABECEDARIOS_WIDTH, "ABECEDARIO ESPANOL");
	printCharacters(ABECEDARIOS_WIDTH, char(205));
	
	cout<<"ABECEDARIO EN MINUSCULAS:"<<endl<<endl;
	Impresion(abcEspanol, t);
	cout<<endl<<endl;
	
	Mayuscula(abcEspanol, t);
	abcEspanol[i]=char(165);
	
	cout<<"ABECEDARIO EN MAYUSCULAS:"<<endl<<endl;
	Impresion(abcEspanol, t);
	cout<<endl<<endl;
	char minusculasAcentuadas[6]={char(160),char(130),char(161),char(162),char(163), char(129)};
	
	cout<<"CARACTERES ESPECIALES:"<<endl<<endl;
	Impresion(minusculasAcentuadas, 6);
	cout<<endl<<endl;
	system("pause");
					}
void Ingles(){//Muestra los alfabetos y caracteres especiales del Ingles
	char abcIngles[30];
	int t=26;
	AbecedarioBase(abcIngles,t);
	system("cls");
	windowSize(ABECEDARIOS_WIDTH,25);
	printCentered(ABECEDARIOS_WIDTH, "ABECEDARIO INGLES");
	printCharacters(ABECEDARIOS_WIDTH, char(205));
	cout<<"ABECEDARIO EN MINUSCULAS:"<<endl<<endl;
	Impresion(abcIngles, t);
	cout<<endl<<endl;
	
	cout<<"ABECEDARIO EN MAYUSCULAS:"<<endl<<endl;
	Mayuscula(abcIngles, t);
	Impresion(abcIngles, t);
	cout<<endl<<endl;
	
	cout<<"CARACTERES ESPECIALES:"<<endl<<endl;
	cout<<"No posee caracteres especiales";
	cout<<endl<<endl;
	system("pause");
}
void Italiano(){//Muestra los alfabetos y caracteres especiales del Italiano
	char abcItaliano[26];
	int t=26;
	AbecedarioBase(abcItaliano, t);
	
	EliminarLetra(abcItaliano, t, 'j');
	EliminarLetra(abcItaliano, t, 'k');
	EliminarLetra(abcItaliano, t, 'w');
	EliminarLetra(abcItaliano, t, 'x');
	EliminarLetra(abcItaliano, t, 'y');
	system("cls");
	windowSize(ABECEDARIOS_WIDTH,25);
	printCentered(ABECEDARIOS_WIDTH, "ABECEDARIO ITALIANO");
	cout<<"ABECEDARIO EN MINUSCULAS:"<<endl<<endl;
	Impresion(abcItaliano,t);
	cout<<endl<<endl;
	
	Mayuscula(abcItaliano, t);
	
	cout<<"ABECEDARIO EN MAYUSCULAS:"<<endl<<endl;
	Impresion(abcItaliano,t);
	cout<<endl<<endl;
	
	char minusculasAcentuadas[]={char(133),char(138),char(130),char(141),char(161),char(140),char(149),char(162),char(151),char(163)};
	
	cout<<"CARACTERES ESPECIALES:"<<endl<<endl;
	ImpresionSinLimite(minusculasAcentuadas, 10);
	cout<<endl<<endl;
	system("pause");
}
	
void Portugues(){//Muestra los alfabetos y caracteres especiales del Portugues
	char abcPortugues[30];
	int t=26;
	AbecedarioBase(abcPortugues,t);
	system("cls");
	windowSize(ABECEDARIOS_WIDTH,25);
	printCentered(ABECEDARIOS_WIDTH, "ABECEDARIO PORTUGUES");
	cout<<"ABECEDARIO EN MINUSCULAS:"<<endl<<endl;
	Impresion(abcPortugues, t);
	cout<<endl<<endl;
	
	Mayuscula(abcPortugues, t);
	
	cout<<"ABECEDARIO EN MAYUSCULAS:"<<endl<<endl;
	Impresion(abcPortugues, t);
	cout<<endl<<endl;
	char minusculasAcentuadas[12]={char(160),char(133),char(131),'a',char(135),char(130),char(136),char(161),char(162),char(147),'o',char(163)}; //el caracter 'o' en realidad seria 'õ' pero este tiene un codigo ascii mayor a 200 por lo que no aparece
	//reemplazamos 'ã' por 'a' ya que el "char(198)" no retorna la letra sino otro simbolo
	cout<<"CARACTERES ESPECIALES:"<<endl<<endl;
	ImpresionSinLimite(minusculasAcentuadas, 12);                       
	cout<<endl<<endl;
	system("pause");
}
void Frances(){//Muestra los alfabetos y caracteres especiales del Frances
	char abcFrances[50];
	int t=26;
	AbecedarioBase(abcFrances,t);
	char AlfabetoPropio[]={char(133),char(131),char(145),char(135),char(130),char(138),char(136),char(137),char(140),char(139),char(147),'æ',char(151),char(150),char(129),char(152)}; //utilizamos 'æ' en vez de 'œ' ya que tampoco esta en el ascii
	system("cls");
	windowSize(ABECEDARIOS_WIDTH,25);
	printCentered(ABECEDARIOS_WIDTH, "ABECEDARIO FRANCES");
	cout<<"ABECEDARIO EN MINUSCULAS:"<<endl<<endl;
	Impresion(abcFrances,t);
	cout<<endl<<endl;
	
	cout<<"ABECEDARIO EN MAYUSCULAS:"<<endl<<endl;
	Mayuscula(abcFrances, t);
	Impresion(abcFrances, t);
	cout<<endl<<endl;
	
	cout<<"CARACTERES ESPECIALES:"<<endl<<endl;
	ImpresionSinLimite(AlfabetoPropio, 16);
	cout<<endl<<endl;
	system("pause");
	
}
void AbecedarioBase(char abecedario[], int t){//crea un abecedario que es base para los idiomas a analizar. Este es el abecedario ingles
	char l='a';
	for(int i=0;i<t;i++){
		abecedario[i]=l+i;
	}
}
void Impresion(char m[], int t){//Imprime los caracteres de los abecedarios respetando que en cada fila solo haya 10 caracteres como maximo
	for(int i=0;i<t;i++){
		cout<<m[i]<<" ";
		if(i==9 or i==19)
			cout<<endl;
	}
}
void ImpresionSinLimite(char m[], int t){//Permite imprimir los caracteres sin limite por fila, la usamos para los caracteres especiales 
	for(int i=0;i<t;i++){
		cout<<m[i]<<" ";
	}
}
void Mayuscula(char c[],int t){//convierte todos los elementos de un arreglo a mayusculas
	for(int i=0;i<t;i++){
		c[i]=tomayus(c[i]);
	}
}
void EliminarLetra(char vector[], int& t, char l){//elimina una letra de un arreglo
	int i=0;
	while(vector[i]!=l)
		i++;
	while(i<t){
		vector[i]=vector[i+1];
		i++;
	}
	t--;	
}
void Juegos(string words[], user & u){//Funcion del menu de juegos
	char opcion;
	do{
		system("cls");
		windowSize(ABECEDARIOS_WIDTH,25);		
		InterfaceJuegos();
		cout<<"Tus puntos: "<<u.points<<endl;
		cout<<"Ingrese una opcion: ";
		cin>>opcion;
		while((opcion<'1' or opcion>'4') and opcion!='X' and opcion!='x'){
			system("cls");
			InterfaceJuegos();
			cout<<"El caracter ingresado es incorrecto, ingresar un entero del 1 al 4 o X (o x): ";
			cin>>opcion;
		}
		switch(opcion){
		case '1':
			ahorcado(words, u);
			system("pause");
			break;
		case '2':
			system("cls");
			JuegoCifradocesar(words);
			system("pause");
			break;
		case '3':
			numerosOtroIdioma();
			system("pause");
			break;
		case '4':
			system("cls");
			MEMORIA(words,u);
			system("pause");
			break;
		}
	}while(opcion!='x' and opcion!='X');
}
	
void InterfaceJuegos(){//muestra la interface del menu de juegos
	printCentered(ABECEDARIOS_WIDTH, "MENU JUEGOS");
	printCharacters(ABECEDARIOS_WIDTH, char(205));
	cout<<"1.- Ahorcado"<<endl;
	cout<<"2.- Palabra cifrada"<<endl;
	cout<<"3.- Numeros en otro idioma"<<endl;
	cout<<"4.- Memoria"<<endl;
	cout<<"X.- Volver al menu principal"<<endl;
	cout<<endl;
}
void MEMORIA(string words[], user & u){//Funcion del juego "MEMORIA"
	windowSize(MEMORIA_WIDTH,13);
	string cadena,palabras[5];
	InterfaceMemoria();
	cout<<"Observe con atencion las siguientes palabras"<<endl<<endl;
	system("pause");
	system("cls");
	randomWords(palabras,5,words,SIZE);
	unionPalabras(cadena,palabras[0],palabras[1],palabras[2],palabras[3],palabras[4]);
	
	MostrarPalabrasAleatorias( palabras[0], palabras[1], palabras[2], palabras[3], palabras[4]);
	
	int tl, cantidad[100]; char letras[100];
	
	LetrasMasRepetidas(cadena,letras,cantidad,tl);
	
	float puntaje=0;
	float LetraRepetida=RespuestaA(letras, cantidad, tl);
	float cVocales=RespuestaB(letras, cantidad, tl);
	string palabMasLarga[5];
	float PalabraLarga=RespuestaC(palabMasLarga,palabras[0],palabras[1],palabras[2],palabras[3],palabras[4]);
	
	puntaje=LetraRepetida+cVocales+PalabraLarga;
	system("cls");
	InterfaceMemoria();
	cout<<"La letra/s mas repetida/s es: ";
	int j=0;
	do{
		if(j!=0)
			cout<<", ";
		cout<<letras[j];
		j++;
	} while(cantidad[j]==cantidad[j-1]);
	cout<<endl;
	cout<<"Puntaje en la primera pregunta: "<<fixed<<setprecision(2)<<LetraRepetida<<"/10"<<endl;
	cout<<"La cantidad de vocales es: "<<cantidadVocales(letras,cantidad,tl)<<endl;
	cout<<"Puntaje en la segunda pregunta: "<<cVocales<<"/10"<<endl;
	cout<<"La palabra/s mas larga/s es: ";
	int i=0;
	do{
		if(i!=0)
			cout<<", ";
		cout<<palabMasLarga[i];
		i++;
	} while(palabMasLarga[i].size()==palabMasLarga[i-1].size());
	cout<<endl;
	cout<<"Puntaje en la tercera pregunta: "<<PalabraLarga<<"/10"<<endl;
	cout<<"\nPuntaje total obtenido: "<<puntaje<<"/30"<<endl;
	addPoints(u,puntaje);
}												
			
void InterfaceMemoria(){//muestra la interface del juego "Memoria"
	printCentered(MEMORIA_WIDTH, "MEMORIA");
	printCharacters(MEMORIA_WIDTH,char(205));
}
void MostrarPalabrasAleatorias(string palabra1,string palabra2,string palabra3,string palabra4,string palabra5){
	//muestra las palabras de a una
	MostrarPalabra(palabra1);
	MostrarPalabra(palabra2);
	MostrarPalabra(palabra3);
	MostrarPalabra(palabra4);
	MostrarPalabra(palabra5);
}
void MostrarPalabra(string palabra){//Muestra una palabra 2 segundos
	InterfaceMemoria();
	printCentered(MEMORIA_WIDTH,palabra);
	Sleep(2000);
	system("cls");
}
void unionPalabras(string& cadena,string p1,string p2,string p3,string p4,string p5){//une las 5 palabras en un solo string para luego contar letras y cantidades
	cadena=p1+p2+p3+p4+p5;
	Minuscula(cadena);
}
void Minuscula(string & c){
	//convierte a minuscula la palabra para comprar
	for(int i=0;i<c.size();i++){
		c[i]=tolower(c[i]);
	}
}
void LetrasMasRepetidas(string cadena, char vLetras[], int vCantidad[], int& tl){//crea y ordena dos vectores, uno con las letras y otro con las repeticiones de cada una de estas, se ordenan ambos en orden descendente desde la letra que mas aparece a la que menos
	VectorLetras(cadena,vLetras,tl);
	VectorCantidad(cadena,vLetras,tl,vCantidad);
	ordenDescendente(vCantidad,vLetras,tl);
}
void VectorLetras(string cadena,char v[],int& tl){
	//se fija que letras hay en las palabras 
	Minuscula(cadena);
	int j=0;
	for(int i='a';i<='z';i++){
		if(cadena.find(i)!=-1){
			v[j]=i;
			j++;
		}
	}
	tl=j;
}
		
void VectorCantidad(string cadena, char l[],int tl,int c[]){
	//cuenta cuantas veces aparece cada letra. La posicion de la letra de "l[]" coincide con la posicion de su cantidad en "c[]"
	for(int i=0;i<tl;i++){
		int contador=0;
		for(int j=0;j<cadena.size();j++){
			if(cadena[j]==l[i]){
				contador++;
			}
		}
		c[i]=contador;
	}
}
void ordenDescendente(int c[],char l[], int tl){ //ordena el vector c y el l (se respetan las posiciones relativas entre los vectores) dependiendo de los valores de c
	int pasada=1, k, intercambios=1;
	
	while(pasada<tl and intercambios){
		intercambios=0;
		for(k=0;k<tl-pasada;k++){
			if(c[k]<c[k+1]){
				swap(c[k],c[k+1]);
				swap(l[k],l[k+1]);
				intercambios=1;
			}
		}
		pasada++;
	}
}
void ordenDescendenteSTR(int c[],char l[], string p[], int tl){ //ordena el vector c y el l (se respetan las posiciones relativas entre los vectores) dependiendo de los valores de c
		int pasada=1, k, intercambios=1;
		
		while(pasada<tl and intercambios){
			intercambios=0;
			for(k=0;k<tl-pasada;k++){
				if(c[k]<c[k+1]){
					swap(c[k],c[k+1]);
					swap(l[k],l[k+1]);
					swap(p[k],p[k+1]);
					intercambios=1;
				}
			}
			pasada++;
		}
	}
int RespuestaA(char vLetras[], int cantidad[], int tl){//El usuario ingresa la respuesta y la funcion devuelve el puntaje obtenido en dicha pregunta
	InterfaceMemoria();
	
	int puntos[26]={0};
	puntos[0]=10; puntos[1]=8; puntos[2]=6; puntos[3]=4; puntos[4]=2;
	
	puntuacion(puntos, cantidad, 26); 
	printCentered(MEMORIA_WIDTH,"PRIMER PREGUNTA");
	
	int puntaje;
	char letra; 
	
	cout<<"Ingrese la letra que mas se repite en las palabras mostradas anteriormente: ";
	cin>>letra;
	while(!isalpha(letra)){
		cout<<"ERROR. Debe ingresar una letra:";
		cin>>letra;
	}
	
	
	letra=tolower(letra);
	/*para aproximar el puntaje en esta respuesta usamos un sistema de puntos
	dependiendo de si se elije alguna de las 5 letras que mas aparecen, si esta
	es la que mas aparece entonces su puntaje es 10, si es la segunda entonces es 8,
	asi hasta la quinta letra que mas aparece, luego de esta, todas suman 0.
	*/
	puntaje=CalculoPuntaje(letra,puntos,vLetras, 26);
	
	return puntaje; 
}
int cantidadVocales(const char vLetras[], int vCantidad[], int tl){
	//toma ambos vectores y se fija en que posiciones hay una vocal. Suma los valores de las posiciones donde hay una vocal 
	int cantidad=0;
	
	for(int i=0;i<tl;i++){
		if(vLetras[i]=='a' or vLetras[i]=='e' or vLetras[i]=='i' or vLetras[i]=='o' or vLetras[i]=='u'){
			cantidad+=vCantidad[i];
		}
	}
	return cantidad;
}
float RespuestaB(char vLetras[], int vCantidad[], int tl){//Permite al usuario ingresar una respuesta y evalua que tan cerca se encuentra esta del resultado real
	printCentered(MEMORIA_WIDTH,"SEGUNDA PREGUNTA");
	cout<<"Ingrese la cantidad total de vocales entre las 5 palabras: ";
	float puntaje, cantidad; 
	cin>>cantidad;
	while(cin.fail()){
		cout<<"ERROR. Debe ingresar un numero entero:";
		cin.clear();
		cin.ignore(1000,'\n');
		cin>>cantidad;
	}
	while(cantidad<0){//no se puede ingresar un valor negativo
		cout<<"El valor ingresado debe ser positivo. Vuelva a ingresarlo: ";
		cin>>cantidad;
		while(cin.fail()){
			cout<<"ERROR. Debe ingresar un numero entero:";
			cin.clear();
			cin.ignore(1000,'\n');
			cin>>cantidad;
		}
	}
	int vocales=cantidadVocales(vLetras,vCantidad,tl);
	/*este puntaje lo asignamos segun la proporcion de la respuesta con el
	resultado real, esta se aplica al puntaje total para asi obtener un puntaje 
	en proporcion con la distancia de la respuesta con el resultado
	*/
	if(cantidad<=vocales){
		puntaje=10.0*(cantidad/vocales);
	}else{
		puntaje=10.0*(1-((cantidad-vocales)/vocales));
	}
	
	return puntaje;
}
void palabraMasLarga(string palabras[], char palabraNumero[], int tamanios[], string palabra1,string palabra2,string palabra3,string palabra4,string palabra5){
		char n='1';
		for(int i=0;i<5;i++){
			palabraNumero[i]=n;//para cada posicion se asigna una etiqueta dependiendo del numero de la palabra (del 1 al 5) 
			n++;
		}
		palabras[0]=palabra1;
		palabras[1]=palabra2;
		palabras[2]=palabra3;
		palabras[3]=palabra4;
		palabras[4]=palabra5;
		tamanios[0]=palabra1.size();
		tamanios[1]=palabra2.size();
		tamanios[2]=palabra3.size();
		tamanios[3]=palabra4.size();
		tamanios[4]=palabra5.size();
		//devuelve el vector palabraNumero ordenado de la palabra mayor a la menor 
		ordenDescendenteSTR(tamanios, palabraNumero,palabras,5);
	}
int RespuestaC(string palabras[], string palabra1,string palabra2,string palabra3,string palabra4,string palabra5){//Permite al ususario ingresar una palabra como respuesta y este retorna el puntaje obtenido. Tambien de aqui obetenemos la letra que mas se repite
	Minuscula(palabra1); Minuscula(palabra2); Minuscula(palabra3); Minuscula(palabra4); Minuscula(palabra5);
	printCentered(MEMORIA_WIDTH,"TERCER PREGUNTA");
	char NumeroDePalabra[5];
	int puntaje=0;
	int tamanios[5];
	palabraMasLarga(palabras, NumeroDePalabra,tamanios,palabra1,palabra2,palabra3,palabra4,palabra5);
	//devuelve el vector NumeroDePalabra con el orden segun el numero de la palabra (del 1 al 5)
	cout<<"Ingrese la palabra de mayor longitud: ";
	string palabra;
	cin>>ws;
	getline(cin,palabra);
	bool j=1;
	while(j){
		j=0;
		int i=0;
		while(i<palabra.size() and !j){
			if(!(isalpha(palabra[i]) or palabra[i]==char(164) or palabra[i]==char(165)))
				j=1;
			i++;
		}
		if(j){
			cout<<"ERROR. Debe ingresar la PALABRA mas larga: ";
			cin>>ws;
			getline(cin,palabra);
		}
	}
	char numero='0';
	if(palabra==palabra1){
		numero='1';
	} else
	if(palabra==palabra2){
		numero='2';
	} else
	if(palabra==palabra3){
		numero='3';
	} else
	if(palabra==palabra4){
		numero='4';
	} else
	if(palabra==palabra5){
		numero='5';
	}
	int puntos[]={10,8,6,4,2};
	puntuacion(puntos, tamanios, 5);
	puntaje=CalculoPuntaje(numero,puntos,NumeroDePalabra, 5);
	return puntaje;
}
void puntuacion(int puntos[],int cantidad[], int t){ //asigna los mismos puntos a dos o mas palabras o letras que midan o se repitan la misma cantidad.
	for(int i=0;i<t;i++){
		if(cantidad[i]==cantidad[i+1]){
			puntos[i+1]=puntos[i];
		}
	}
}
int CalculoPuntaje(char numero, int puntos[], char vector[], int t){//analiza si el numero ingresado coincide con alguno de los valores del vector y devuelve los puntos[i] que coincide con vector[i]
	int puntaje=0;
	for(int i=0;i<t;i++){
		if(numero==vector[i]){
			puntaje=puntos[i];
		}
	}
	return puntaje;
}
void VecToStr(char v[], int t, string & c){               //copia los datos de un vector de caracteres a un string
	for(int i=0; i<t; i++){
		c[i]=v[i];
	}
}
void StrToVec(string c, char v[], int & t){                               //copia los datos de un strign a un vector de caracteres
	for(int i=0;i<c.size();i++){
		v[i]=c[i];
	}
	t=c.size();
}
void palabraMayuscula(string & palabra, int tam){
	for(int i=0; i<tam;i++){
		palabra[i]=tomayus(palabra[i]);
	}
}
void llenarPalabraVacia(string &palabra,int tam){
	for (int i=0; i<tam;i++)
		palabra.append(" ");
	
}
void llenarPalabraGuiones(string &palabra,int tam){
	for (int i=0; i<tam;i++)
		palabra.append("_");
	
}
void cifradoCesar(string  palabra, string &palabracifrada, int tam){
	char pos;
	for(int i=0;i<tam;i++){ 
		if (palabra[i]>'N')
			pos=palabra[i]+15;
		else 
			pos=palabra[i]+14;
		
		palabracifrada[i]=(char)pos;
		
		if (palabra[i]>'L')
			palabracifrada[i]=pos+6;
		if(palabra[i]=='Z')
			palabracifrada[i]=char(165);
		if ( palabra[i]==char(165) or palabra[i]==char(164))
			palabracifrada[i]='C';
	}
	
}
int cantIntentos(int &intentos,int tam){
	if(tam*2<12)
		intentos=tam*2;
	else
		intentos=12;
	return intentos;
}
void letraRepetida(int & letrarepetida, char &letra, string letrasingresadas, string palabracifrada,int tam, string plantilla, int intentos){
	while(letrarepetida!=string::npos){
		system("cls");
		printCentered(50,"Cifrado Cesar");
		printCentered(50,palabracifrada);
		printCenteredN(50,tam*2);
		stringSeparated(plantilla,' ');
		cout<<endl;
		cout<<"Tienes "<<intentos<<" intentos"<<endl;
		cout<<"Letra ingresada repetida. Ingrese una letra: ";
		cin>>letra;
		letra=tomayus(letra);
		letrarepetida= letrasingresadas.find(letra);
	}
}

void esLetra(char&letra, string palabracifrada, int tam, string plantilla ){
	while(letra!=char(165) and not isalpha(letra)){
		system("cls");
		printCentered(50,"Cifrado Cesar");
		printCentered(50,palabracifrada);
		printCenteredN(50,tam*2);
		stringSeparated(plantilla,' ');
		cout<<endl;
		cout<<"Valor inavlido, ingrese una letra: "<<endl;
		cin>>letra;
		letra=tomayus(letra);
	}
}
void descubrirPalabra(string palabra, int tam, string &plantilla, int &intentos, string palabracifrada,char letra,
int & i, string & letrasingresadas){

	
	if(letra==palabra.at(i)) 
	plantilla.at(i)=letra;
	
		  
	
	system("cls");
	printCentered(50,"PALABRA CIFRADA");
	printCentered(50,palabracifrada);
	printCenteredN(50,tam*2);
	stringSeparated(plantilla,' ');
	cout<<endl;
	
	if(letra!=palabra.at(i)){
		PlaySoundA((LPCSTR) "respuestaincorrecta.wav",NULL,SND_FILENAME | SND_ASYNC);
	intentos--;
	letrasingresadas+=letra;
	}
	else {
		PlaySoundA((LPCSTR) "respuestacorecta.wav",NULL,SND_FILENAME | SND_ASYNC);
		i++;
		letrasingresadas.erase();
	}
	
}

void resultado(string palabra, string & plantilla, string &letrasingresadas, int & intentos, int tam,string palabracifrada){
	char letra;
	int i=0;
	do{
		
		cout<<"Tienes "<<intentos<<" intentos"<<endl;
		cout<<"Intenta descubrir la Palabra Cifrada! Ingrese una letra: ";
		cin>>letra;
		letra=tomayus(letra);
		 int letrarepetida=letrasingresadas.find(letra);
		
		letraRepetida(letrarepetida,letra,letrasingresadas,palabracifrada,tam, plantilla, intentos );
		esLetra(letra,  palabracifrada, tam, plantilla);
		
		letrasingresadas+=letra;
		descubrirPalabra(palabra,tam,plantilla,intentos,palabracifrada,letra,i,letrasingresadas);
		
	}while(intentos>0 and plantilla!=palabra);
	if (plantilla ==palabra)
		PlaySoundA((LPCSTR) "sonidovictoria.wav",NULL,SND_FILENAME | SND_ASYNC);
	else
		PlaySoundA((LPCSTR) "derrota.wav",NULL,SND_FILENAME | SND_ASYNC);
}
void mensajeFinal(int intentos, string plantilla, string palabra,string ){
	
	string mensaje;
	if(intentos==0){
		
		cout<<"La Palabra Cifrada era : "<<endl;
		printCentered(50,palabra);
		mensaje ="Te quedaste sin intentos!";
		printCentered(50,mensaje);
	}
	else if (plantilla==palabra){
		
		
		cout<<endl;
		mensaje="Felicitaciones, descubriste la Palabra Cifrada";
		printCentered(50,mensaje);
	}
}
											
	
void printCenteredN(int len, int longfrase){
	int fraseLen = longfrase;
	for(int i=0; i<(len/2-fraseLen/2)+1;i++)
		cout<<' ';
	
}
void JuegoCifradocesar(string palabras[]){	
	windowSize(50,25); 
	string palabra=randomWord(palabras,100);
	
	string palabracifrada;
	
	string plantilla;
	string letrasingresadas;
	
	int intentos;
	int tam=palabra.length(); 
	palabraMayuscula(palabra,tam);
	llenarPalabraVacia(palabracifrada, tam);
	cifradoCesar(palabra,palabracifrada,tam);
	palabraMayuscula(palabracifrada,tam);
	llenarPalabraGuiones(plantilla, tam);
	//mostramos palabracifrada y guiones
	printCentered(50,"PALABRA CIFRADA");
	printCentered(50,palabracifrada);
	printCenteredN(50,tam*2);
	stringSeparated(plantilla,' ');
	cout<<endl;
	
	llenarPalabraVacia(letrasingresadas, 20);
	cantIntentos(intentos,tam);
	
	resultado(palabra,plantilla,letrasingresadas,intentos,tam,palabracifrada);
	
	mensajeFinal(intentos,plantilla,palabra,palabracifrada);
	
}
	
int Contrasenia(int usuario){//Devuelve la contraseña en base al usuario
	int c5=usuario%10;
	int c1=((usuario/10000)+c5)%10;
	int c2=(usuario/1000)%10;
	int c3=(usuario/100)%10;
	int c4=(usuario/10)%10;
	
	int contrasenia=c5*10000+c4*1000+c3*100+c2*10+c1;
	
	return contrasenia;
}
bool ValidacionDatos(){	//Funcion principal de login
	
	int i=0;
	string usuario, contrasenia;
	int nrousuario, nrocontrasenia;
	bool success=true;
	do{
		system("cls");
		system ("color F0");
		if(i>0){
		cout<<"Validacion incorrecta, ingrese nuevamente los datos: "<<endl;
		}
		cout<<"Usuario: ";
		cin>>usuario;	
		cout<<"Contrasena: "<<endl;
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),255);
		
		cin>>contrasenia;
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),240);
		i++;
		nrousuario=Esnumero(usuario);
		nrocontrasenia=Esnumero(contrasenia);
	}while(i<3 && (( nrousuario==-1 || nrocontrasenia==-1) || nrocontrasenia!=Contrasenia(nrousuario)));
	if (i==3 and nrocontrasenia!=Contrasenia(nrousuario)){
		cout<<"Se produjeron 3 intentos no validos."<<endl;
		success=false;
	}
	return success;
}
int Esnumero(string dato){//Devuelve el numero en entero si es valido y -1 si no
	int retorno;
	bool esNumero=true;
	int largo=dato.size();
	if(largo!=5){
		esNumero=false;
	}
	for(int i=0;i<largo;i++){
		if(dato[i]<'0' or dato[i]>'9')
			esNumero=false;
	}
	if (esNumero){
		retorno=stoi(dato);
	}
	else
		retorno=-1;
	return retorno;
}
char tomayus(char a){
	char retorno; 
	if(a==char(164)){
		retorno=char(165);
	}else{
		retorno=toupper(a);
	}
	return retorno;
}
