#include <ctime>
#include <cstdlib>
#include <iostream>
#include "login.h"
#define SIZE 100
#define NAMESIZE 30
using namespace std;

bool openUserList(fstream & users_fhand,string fileName){
	bool success=true;
	users_fhand.open(fileName.c_str(),ios_base::binary|ios_base::in|ios_base::out);
	if(users_fhand.fail()){
		success=false;
	}
	return success;
}
bool closeUserList(fstream & users_fhand){
	bool retorno = true;
	users_fhand.close();
	if(users_fhand.fail()){
		retorno = false;
	}
	return retorno;
}

user setUser(char name[NAMESIZE],char surname[NAMESIZE],char sex, bool role,date fecha){
	user nuevoUsuario;
	strcpy(nuevoUsuario.name,name);
	strcpy(nuevoUsuario.surname,surname);
	nuevoUsuario.sex=sex;
	nuevoUsuario.teacher=role;
	nuevoUsuario.id=rand()%79999+10000;
	nuevoUsuario.password=password(nuevoUsuario.id);
	nuevoUsuario.points=0;
	nuevoUsuario.last_access=fecha;
	return nuevoUsuario;
}
int password(int id){//Devuelve la contraseña en base al usuario
	int c5=id%10;
	int c1=((id/10000)+c5)%10;
	int c2=(id/1000)%10;
	int c3=(id/100)%10;
	int c4=(id/10)%10;
	
	int pass=c5*10000+c4*1000+c3*100+c2*10+c1;
	
	return pass;
}
	
void writeUsers(fstream & users_fhand,const users &data){
	users_fhand.write((char*)(&data),sizeof(data));
}

user readUser(fstream & users_fhand,int userNumber, int & userPos){
	user aux;
	users_fhand.seekg(sizeof(user)*userNumber);
	userPos =users_fhand.tellg();
	users_fhand.read((char*)(&aux),sizeof(aux));
	return aux;
}
void updateUser(fstream & users_fhand,user u, int userPos){
	users_fhand.seekp(userPos);
	users_fhand.write((char*)(&u),sizeof(u));
}
user getUser(fstream & users_fhand,int userId, bool & found, int & pos){
	int i=0;
	found= false;
	user aux;
	do{
		aux=readUser(users_fhand,i,pos);
		if(aux.id==userId){
			found=true;
		}
		i++;
	}while(i<100 and not found);
	if(not found){
		pos=-1;
	}
	return aux;
}
bool passwordCheck(user check_user,int password){
	bool success=true;
	if(check_user.password!=password){
			success=false;
	}
	return success;
	
}
void updateAccess(user & u){
	u.last_access = setActualDate();
}
void addPoints(user & u,int points){
	u.points +=points;
}
date setActualDate(){
	date now;
	time_t actualTime;
	time(&actualTime);
	tm* day;
	day = localtime(&actualTime);
	now.day = day->tm_mday;
	now.month = day->tm_mon+1;
	now.year = day->tm_year+1900;
	now.hours = day->tm_hour;
	now.minutes = day->tm_min;
	now.seconds = day->tm_sec;
	return now;
}
