#ifndef publicacion_h
#define publicacion_h
#include "usuario.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Usuario; 

class Publicacion{
    int id;

    public:
    string fecha;
    string contenido;
    Usuario* usuario;

    void mostrarPublicacion();
    Publicacion(Usuario* usuario, string fecha, string contenido);

};

#endif