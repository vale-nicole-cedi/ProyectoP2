#ifndef redSocial_h
#define redSocial_h
#include "usuario.h"
#include "publicacion.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Usuario;
class Publicacion;

class RedSocial{
    vector<Usuario*> usuarios;
    vector<UsuarioPremium*> usuariospremium;
    vector<Publicacion*> publicaciones;
    vector<Publicacion*> publicacionesprivadas;

    public:
    string nombre;
    int numeroDeUsuarios;
    int numeroDePublicaciones;

    void agregarUsuario();
    void agregarUsuarioPremium();
    void mostrarUsuarios();
    void mostrarPublicaciones();
    void mostrarPublicacionesPrivadas();
    bool revisarpremium(int id);
    void agregarpublicacion(Publicacion* pnew);
    void agregarpublicacionprivada(Publicacion* pnew);
    Usuario* getUsuario(int id);
    UsuarioPremium* getUsuarioPremium(int id);

    RedSocial(string nombre);
    RedSocial(string nombre, vector<Usuario*> usuarios);
    RedSocial(string nombre, vector<Usuario*> usuarios, vector<Publicacion*> publicaciones);
};

#endif