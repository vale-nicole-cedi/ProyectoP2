#include <iostream>
#include <string>
#include <vector>
#include "redsocial.h"
#include "publicacion.h"

using namespace std;

void RedSocial::agregarUsuario(){
 string nombreUsuario;
    cout << "Ingresa el nombre del nuevo usuario: ";
    cin >> nombreUsuario;

    Usuario* usuario = new Usuario(nombreUsuario);
    usuarios.push_back(usuario);
    numeroDeUsuarios++;
    cout << "El usuario: " << nombreUsuario << " agregado correctamente." << endl;
}

void RedSocial::mostrarUsuarios(){
        cout << "Usuarios en GossipNet" << ":" << endl;
    for (int i=0; i<this->usuarios.size(); i++) {
        cout << "- ";
        this->usuarios[i]->mostrar();
    }

}

void RedSocial::mostrarPublicaciones(){
    for(int i=0; i<this->publicaciones.size(); i++){
        publicaciones[i]->mostrarPublicacion();
    }
}

void RedSocial::mostrarPublicacionesPrivadas(){
    for(int i=0; i<this->publicaciones.size(); i++){
        publicacionesprivadas[i]->mostrarPublicacion();
    }
}

Usuario* RedSocial::getUsuario(int id)
{ 
    for (int i = 0; i < usuarios.size(); ++i) 
    { 
        Usuario* usuario = usuarios[i]; 
        if (usuario->getId() == id) 
        { return usuario; } 
    } 
    cout << "No se encontró un usuario con el ID " << id << endl; 
    return nullptr; 
}

void RedSocial::agregarpublicacion(Publicacion* pnew){
    this->publicaciones.push_back(pnew);
}

RedSocial::RedSocial(string nombre){
    this->nombre = nombre;
    this->numeroDeUsuarios = 0;
    this->numeroDePublicaciones = 0;

}

RedSocial::RedSocial(string nombre, vector<Usuario*> usuarios){
 this->nombre = nombre;
    this->usuarios = usuarios;

    this->numeroDeUsuarios = usuarios.size();
    this->numeroDePublicaciones = 0;
}

RedSocial::RedSocial(string nombre, vector<Usuario*> usuarios, vector<Publicacion*> publicaciones){
this->nombre = nombre;
    this->usuarios = usuarios;
    this->publicaciones = publicaciones;
    this->numeroDeUsuarios = usuarios.size();
    this->numeroDePublicaciones = publicaciones.size();
}
