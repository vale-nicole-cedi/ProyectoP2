#include <iostream>
#include <string>
#include <vector>
#include "usuario.h"

using namespace std;

class Publicacion;

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
    for(int i=0; i<this->publicaciones.size(); i++){
        publicaciones[i]->mostrarPublicacion();
    }
    //mostrar todas las publicaciones del usuario
    //for->mostrarpublicacion()
}

void Usuario::agregarAmigo(Usuario* nuevoAmigo){
    this->amigos.push_back(nuevoAmigo);
    nuevoAmigo->amigos.push_back(this);
}

void Usuario::crearPublicacion(){
    string fecha;
    string contenido;
    Publicacion p(this, fecha, contenido);
    //agregar al vector de publicaciones
    this->publicaciones.push_back(&p);
}

Usuario* Usuario::getAmigo(int id){
    for(int i=0; i<amigos.size(); i++){
        if(amigos[i]->id == id){
            return amigos[i];
            break;
        }
    }
}

Usuario::Usuario(string nombre){
    //generar un id aleatorio
    this->nombre = nombre;
    this->edad = 0;
    this->nacionalidad = "no definida";
}

Usuario::Usuario(string nombre, int edad){
    //generar un id aleatorio
    this->nombre = nombre;
    this->edad = edad;
    this->nacionalidad = "no definida";
}
Usuario::Usuario(string nombre, int edad, string nacionalidad){
    //generar un id aleatorio
    this->nombre = nombre;
    this->edad = edad;
    this->nacionalidad = nacionalidad;
}