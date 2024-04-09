#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // para que se genere  los id aleatorios
#include "usuario.h"

using namespace std;

class Publicacion;

int Usuario::getId(){
return this->id;
}

void Usuario::mostrar(){
    cout << "ID: " << this->id << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Edad: " << this->edad << endl;
    cout << "Nacionalidad: " << this->nacionalidad << endl;
}

void Usuario::mostrarAmigos(){
    if(this->amigos.size() == 0){
        cout << "no tienes amigos" << endl;
    } else {
        for(int i=0; i<amigos.size(); i++){
        amigos[i]->mostrar();
    }
    }
}

void Usuario::mostrarPublicaciones(){
    for(int i=0; i<this->publicaciones.size(); i++){
        publicaciones[i]->mostrarPublicacion();
    }
    //mostrar todas las publicaciones del usuario
    //for->mostrarpublicacion()
}

void Usuario::agregarAmigo(Usuario* nuevoAmigo){
    this->amigos.push_back(nuevoAmigo);
    nuevoAmigo->amigos.push_back(this);
}

void Usuario::crearPublicacion() {
    string fecha, contenido;

    cout << "Ingrese la fecha de la publicación: "<<endl;
    cout<<"Recuerda no usar espacios, puedes usar diagonales (/)";
    cin >> fecha;

    cout << "Ingrese el contenido de la publicación: ";
    cout<<"Recuerda no usar espacios, puedes usar diagonales (/)";
    cin >> contenido;
    cin.ignore();//ignora cualquier carácter adicional

    Publicacion* p = new Publicacion(this, fecha, contenido);
    // Agregar al vector de publicaciones del usuario
    this->publicaciones.push_back(p);

    cout << "Publicación agregada exitosamente." << endl;
}

void UsuarioPremium::verPrivados(){
    for(int i=0; i<this->publicacionespriv.size(); i++){
        publicacionespriv[i]->mostrarPublicacion();
    }
}

void UsuarioPremium::agregarPrivado(){
    string fecha, contenido;

    cout << "Ingrese la fecha de la publicación: ";
    cin >> fecha;

    cout << "Ingrese el contenido de la publicación: ";
    cin >> contenido;
    cin.ignore();//ignora cualquier carácter adicional

    Publicacion* p = new Publicacion(this, fecha, contenido);
    // Agregar al vector de publicaciones del usuario
    this->publicacionespriv.push_back(p);

    cout << "Publicación privada agregada exitosamente." << endl;
}

void UsuarioPremium::borrarPublicacion(){
    int ans;
    cout << "Desea borrar una publicación publica o privada?" << endl;
    cin>> ans;
    switch(ans){
        case 1:
        cout << "Ingrese el ID de la publicación" << endl;
        for(int i=0; i<this->publicacionespriv.size(); i++){

        }
    }
    cout << "Ingrese el ID de la publicación" << endl;

}

Usuario* Usuario::getAmigo(int id){
    for(int i=0; i<amigos.size(); i++){
        if(amigos[i]->id == id){
            return amigos[i];
            break;
        }
    }
}

Usuario::Usuario(string nombre){
    this->id = rand() % 10000; //generar un id aleatorio
    this->nombre = nombre;
    this->edad = 0;
    this->nacionalidad = "no definida";
}

Usuario::Usuario(string nombre, int edad){
    this->id = rand() % 10000; //generar un id aleatorio
    this->nombre = nombre;
    this->edad = edad;
    this->nacionalidad = "no definida";
}
Usuario::Usuario(string nombre, int edad, string nacionalidad){
    this->id = rand() % 10000; //generar un id aleatorio
    this->nombre = nombre;
    this->edad = edad;
    this->nacionalidad = nacionalidad;
}