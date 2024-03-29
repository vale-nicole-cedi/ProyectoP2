#ifndef user_h
#define user_h

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Usuario;
class Publicacion;

class RedSocial{
    vector<Usuario*> usuarios;
    vector<Publicacion*> publicaciones;

    public:
    string nombre;
    int numeroDeUsuarios;
    int numeroDePublicaciones;

    void agregarUsuario();
    void mostrarUsuarios();
    void mostrarPublicaciones();
    Usuario* getUsuario(int id);

    RedSocial(string nombre);
    RedSocial(string nombre, vector<Usuario*> usuarios);
    RedSocial(string nombre, vector<Usuario*> usuarios, vector<Publicacion*> publicaciones);
};

#endif