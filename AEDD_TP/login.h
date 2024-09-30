#include <iostream>
#include <fstream>
#include <time.h>
#include <cstring>
#define SIZE 100
#define NAMESIZE 30

using namespace std;
struct date{
	int day;
	int month;
	int year;
	int hours;
	int minutes;
	int seconds;
};
struct user{
	char name[NAMESIZE];
	char surname[NAMESIZE];
	char sex;
	int id, password;
	bool teacher;//1 for teacher, 0 for student
	int points;
	date last_access;
};
struct users{
	user list[SIZE];
};

bool openUserList(fstream & ,string fileName);									//Abre un archivo binario en modo lectura-escritura
bool closeUserList(fstream&);													//Cierra un archivo fstream
user setUser(char name[NAMESIZE],char surname[NAMESIZE],char sex, bool role,date fecha);	//Inicializa y setea un usuario
int password(int id);															//Retorna la contraseña correspondiente al usuario id
void writeUsers(fstream & ,const users &data);									//Escribe en un archivo un vector de usuarios
user readUser(fstream & ,int userNumber, int & userPos);						//Lee de un archivo de usuarios el usuario userNumber, devuelve su posicion en el archivo mediante la veriable de salida userPos
void updateUser(fstream & ,user u, int userPos);								//Escribe el usuario u en un archivo de usuarios en la posición userPos
user getUser(fstream & ,int userId, bool & found, int & pos);					//Busca el usuario por ID en un archivo de usuarios, devuelve el mismo, por variable de salida devuelve su posición y un booleano si lo encontró
bool passwordCheck(user, int password);											//Verifica si una contraseña corresponde a un usuario
void updateAccess(user & u);													//Actualiza la fecha de acceso de un usuario
void addPoints(user & u,int points);											//Añade los puntos a un usuario
date setActualDate();															//Devuelve un dato tipo date con la información de la fecha actual

