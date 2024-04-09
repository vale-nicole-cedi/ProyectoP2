#ifndef usuario_h
#define usuario_h

#include <iostream>
#include <string>
#include <vector>
#include "publicacion.h"
using namespace std;

class Publicacion;

class Usuario{
    int id;

    public:
    string nombre;
    int edad;
    string nacionalidad;
    vector<Usuario*> amigos;
    vector<Publicacion*> publicaciones;

    Usuario(string nombre);
    Usuario(string nombre, int edad);
    Usuario(string nombre, int edad, string nacionalidad);

    int getId();
    void mostrar();
    void mostrarAmigos();
    void mostrarPublicaciones();
    void agregarAmigo(Usuario* nuevoAmigo);
    void crearPublicacion();
    Usuario* getAmigo(int id);

};

class UsuarioPremium: public Usuario{
    public:
    vector<Publicacion*> publicacionespriv;

    UsuarioPremium(string nombre):Usuario(nombre){}
    UsuarioPremium(string nombre, int edad):Usuario(nombre, edad){}
    UsuarioPremium(string nombre, int edad, string nacionalidad):Usuario(nombre, edad, nacionalidad){}

    void verPrivados();
    void agregarPrivado();

};

#endif