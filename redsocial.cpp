#include <iostream>
#include <string>
#include <vector>
#include "redsocial.h"
#include "publicacion.h"

using namespace std;

void RedSocial::agregarUsuario(){
 string nombreUsuario;
 int edad;
 string nacionalidad;
    cout << "Ingresa tu nombre del nuevo usuario: ";
    cin >> nombreUsuario;
 

     cout << "Ingresa tu edad: ";
    cin >> edad;


     cout << "Ingresa tu nacionalidad: ";

    cin >> nacionalidad;
            cout <<endl;

    Usuario* usuario = new Usuario(nombreUsuario,edad,nacionalidad);
    usuarios.push_back(usuario);
    numeroDeUsuarios++;
    cout << "El usuario: " << nombreUsuario << " agregado correctamente." << endl;
        cout <<endl;

}

void RedSocial::agregarUsuarioPremium(){
string nombreUsuario;
 int edad;
 string nacionalidad;
    cout << "Ingresa tu nombre del nuevo usuario: ";
    cin >> nombreUsuario;
        cout <<endl;

     cout << "Ingresa tu edad ";
    cin >> edad;
        cout <<endl;

     cout << "Ingresa tu nacionalidad ";
    cin >> nacionalidad;
        cout <<endl;


    UsuarioPremium* usuario = new UsuarioPremium(nombreUsuario,edad,nacionalidad);
    usuarios.push_back(usuario);
    usuariospremium.push_back(usuario);
    numeroDeUsuarios++;
    cout << "El usuario: " << nombreUsuario << " agregado correctamente." << endl;
        cout <<endl;

}

void RedSocial::mostrarUsuarios(){
        cout << "Usuarios en GossipNet" << ":" << endl;
    for (int i=0; i<this->usuarios.size(); i++) {
        cout << "- ";
        this->usuarios[i]->mostrar();
    }
    cout <<endl;

}

void RedSocial::mostrarPublicaciones(){
    for(int i=0; i<this->publicaciones.size(); i++){
        publicaciones[i]->mostrarPublicacion();
    }
}

void RedSocial::mostrarPublicacionesPrivadas(){
    cout << "CHISMES CEDI:"<<endl;
    cout <<"- Hay alguien que le tomaba fotos a los pies de las personas en los baños"<<endl;
    cout <<"  y las publicaba en insta"<<endl;
    cout<<endl;
    
    for(int i=0; i<this->publicacionesprivadas.size(); i++){
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
        cout <<endl;

    return nullptr; 
}

UsuarioPremium* RedSocial::getUsuarioPremium(int id)
{ 
    for (int i = 0; i < usuariospremium.size(); ++i) 
    { 
        UsuarioPremium* usuario = usuariospremium[i]; 
        if (usuario->getId() == id) 
        { return usuario; } 
    } 
    cout << "No se encontró un usuario con el ID " << id << endl; 
        cout <<endl;

    return nullptr; 
}

void RedSocial::agregarpublicacion(Publicacion* pnew){
    this->publicaciones.push_back(pnew);
}

void RedSocial::agregarpublicacionprivada(Publicacion* pnew){
    this->publicacionesprivadas.push_back(pnew);
}

bool RedSocial::revisarpremium(int id){
    for (int i = 0; i < usuariospremium.size(); ++i) 
    { 
        Usuario* usuario = usuariospremium[i]; 
        if (usuario->getId() == id) 
        { return true; } 
    } 
    return false; 
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
