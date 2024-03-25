#include <iostream>
#include <string>
#include <vector>
#include "publicacion.h"

using namespace std;

void Publicacion::mostrarPublicacion(){
    cout << this->fecha << endl;
    cout << this->contenido << endl;
    //cout nombre del usuario
}

Publicacion::Publicacion(Usuario* usuario, string fecha, string contenido){
    this->usuario = usuario;
    this->fecha = fecha;
    this->contenido = contenido;
    //push back a vector de publicaciones
}