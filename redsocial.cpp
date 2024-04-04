#include <iostream>
#include <string>
#include <vector>
#include "redsocial.h"

using namespace std;

void RedSocial::agregarUsuario(){
 string nombreUsuario;
    cout << "Ingresa el nombre del nuevo usuario: ";
    cin >> nombreUsuario;

    Usuario usuario(nombreUsuario);
    usuarios.push_back(&usuario);
    numeroDeUsuarios++;
    cout << "El usuario: " << nombreUsuario << " agregado correctamente." << endl;
}

void RedSocial::mostrarUsuarios(){
        cout << "Usuarios en Nonsense" << ":" << endl;
    for (Usuario* usuario : usuarios) {
        cout << "- " << usuario->nombre << endl;
    }

}

void RedSocial::mostrarPublicaciones(){
    for(int i=0; i<this->publicaciones.size(); i++){
        //mostrar publicacion
    }
}

Usuario* RedSocial::getUsuario(int id){
 for (Usuario* usuario : usuarios) {
        if (usuario->getId() == id) {
            return usuario;
        }
 }
    std::cout << "No se encontró un usuario con el ID " << id << std::endl;
    return nullptr;
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

