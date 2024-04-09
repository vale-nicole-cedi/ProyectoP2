#include <iostream>
#include <string>
#include <vector>
#include "publicacion.h"
#include "usuario.h"

using namespace std;

void Publicacion::mostrarPublicacion(){
    cout << "Fecha: " << fecha << endl;
    cout << "Contenido: " << contenido << endl;
    cout << "Por: " << usuario->nombre << endl;
}

Publicacion::Publicacion(Usuario* usuario, string fecha, string contenido)
{
    this->usuario = usuario;
    this->fecha = fecha;
    this->contenido = contenido;
    
}
