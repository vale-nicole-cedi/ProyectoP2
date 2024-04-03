#include <iostream>
#include <string>
#include <vector>
#include "publicacion.h"
#include "usuario.h"

using namespace std;

void Publicacion::mostrarPublicacion(){
    cout << this->fecha << endl;
    cout << this->contenido << endl;
    cout << this->usuario->nombre;
}

Publicacion::Publicacion(Usuario* usuario, string fecha, string contenido){
    this->usuario = usuario;
    this->fecha = fecha;
    this->contenido = contenido;
}