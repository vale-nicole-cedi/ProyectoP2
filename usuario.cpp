#include <iostream>
#include <string>
#include <vector>
#include "usuario.h"

using namespace std;

int Usuario::getId(){
return this->id;
}

void Usuario::mostrar(){
    cout << "ID: " << this->id << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Edad: " << this->edad << endl;
    cout << "Nacionalidad: " << this->nacionalidad << endl;
}

void Usuario::mostrarAmigos(){
    for(int i=0; i<amigos.size(); i++){
        amigos[i]->mostrar();
    }
}

void Usuario::mostrarPublicaciones(){
    //mostrar todas las publicaciones del usuario
}

void Usuario::agregarAmigo(Usuario* nuevoAmigo){
    this->amigos.push_back(nuevoAmigo);
    nuevoAmigo->amigos.push_back(this);
}

void Usuario::crearPublicacion(){
    //crea una nueva publicacion para el usuario
    //crea directamente desde el metodo y agrega el apuntador al listado de publicaciones del usuario
}

Usuario* Usuario::getAmigo(int id){
    for(int i=0; i<amigos.size(); i++){
        if(amigos[i]->id == id){
            return amigos[i];
            break;
        }
    }
}