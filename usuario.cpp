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
        cout << amigos[i]->nombre << endl;
    }
}

void Usuario::mostrarPublicaciones(){
    //mostrar todas las publicaciones del usuario
}