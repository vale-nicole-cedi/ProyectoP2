#include <bits/stdc++.h>
#include "rlutil.h"
#include "redsocial.h"
using namespace std;
using namespace rlutil;
Usuario* usuario, amigo;
int idUsuario, idAmigo;


int main()
{
    RedSocial Nonsense ("Nonsense");
    cout << "███╗   ██╗ ██████╗ ███╗   ██╗███████╗███████╗███╗   ██╗███████╗███████╗" << endl;
    cout << "████╗  ██║██╔═══██╗████╗  ██║██╔════╝██╔════╝████╗  ██║██╔════╝██╔════╝" << endl;
    cout << "██╔██╗ ██║██║   ██║██╔██╗ ██║███████╗█████╗  ██╔██╗ ██║███████╗█████╗  " << endl;
    cout << "██║╚██╗██║██║   ██║██║╚██╗██║╚════██║██╔══╝  ██║╚██╗██║╚════██║██╔══╝  " << endl;
    cout << "██║ ╚████║╚██████╔╝██║ ╚████║███████║███████╗██║ ╚████║███████║███████╗" << endl;
    cout << "╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚══════╝╚═╝  ╚═══╝╚══════╝╚══════╝" << endl;
                                                                       

inicio:
    cout << "Menu:" << endl;
    cout << "Da click en el numero indicado para continuar" << endl;

    cout << "1. Ver lista de usuarios" << endl; //ascii 49
    cout << "2. Ver lista de publicaciones" << endl;
    cout << "3. Entrar a un perfil de usuario" << endl;
    cout << "4. Agregar un nuevo usuario" << endl;
    cout << "0. Salir" << endl;

    while(true)
    {

        if(kbhit())
        {
            int k = getkey();

            if(k == 49) //lista usuarios
            {
                cout << "Lista de usuarios: "<<endl;
                Nonsense.mostrarUsuarios();
                break;
            }

            if(k == 50) //lista publicaciones
            {
                cout << "Lista de publicaciones: " <<endl;
                Nonsense.mostrarPublicaciones();
                break;
            }

            if(k == 51)//perfil de usuario
            { 
              cout << "Ingrese el ID de un usuario para acceder: "<<endl;
              cout << "ID: ";
                cin >> idUsuario;
                usuario = Nonsense.getUsuario(idUsuario);
                if (usuario != nullptr) {
                    cout<<"Haz accedido con exito!"<<endl;
                    cout<<"Da clic en el numero indicado para hacer alguna de estas opciones:"<<endl;
                    cout <<"1. Ver lista de amigos" << endl; //ascii 49
                    cout << "2. Ver lista de publicaciones" << endl;
                    cout << "3. Crear una nueva pulicacion" << endl;
                    cout << "4. Entrar al perfil de un amigo" << endl;
                    cout << "5. Agregar un nuevo amigo" <<endl;
                    cout << "0. salir" << endl;

                    while(true)
                    {
                        if (kbhit())
                        {
                            int j = getkey();

                            if(j == 49) //lista de amigos 
                            {
                                cout << "Esta es tu lista de amigos: " << endl;
                                usuario->mostrarAmigos();
                                break;
                            }

                            if(j == 50)//lista de publicaciones
                            {
                                cout << "Esta es tu lista de publicaciones: " << endl;
                                usuario->mostrarPublicaciones();
                                break;
                            }
                            if(j == 51)//crear publicacion
                            {
                                cout << "Nueva publicacion: " << endl;
                                usuario->crearPublicacion();
                                break;
                            }
                            if(j == 52) //entrar perfil amigo
                            {
                                cout << "Escribe el ID de tu amigo" << endl;
                                cout << "ID de amigo: ";
                                cin >> idAmigo;
                                amigo = Nonsense.getUsuario(idAmigo);
                                if (amigo != nullptr)
                                {
                                    cout << "Esta es la informacion de tu amigo: "<<endl;
                                    amigo->mostrar();
                                }
                                break;
                            }
                            if(j == 53) // agregar amigo
                            {
                                cout << "Agregar un amigo"<< endl;
                                cout << "Escribe el ID de tu nuevo amigo" << endl;
                                cout << "ID de nuevo amigo: ";
                                cin >> idAmigo;
                                amigo = Nonsense.getUsuario(idAmigo);
                                if (amigo != nullptr)
                                {
                                    cout << "Se ha agregado correctamente tu nuevo amigo!" << endl;
                                    usuario->agregarAmigo(amigo);
                                }
                                break;
                            }
                            if(j == 48)
                            {
                                goto inicio;
                            }

                        }
                    }


                    cout << "Perfil de Usuario:" << endl;
                    usuario->mostrar();
                    cout << endl;
                    cout << "Publicaciones:" << endl;
                    usuario->mostrarPublicaciones();
            }

            if(k == 52) //agregar usuario
            {
                cout << "Agregar usuario: " << endl;
                Nonsense.agregarUsuario();
                break;
            }

            if(k == 48) //salir
            {
                return 0;
            }

            }
        }   
    }
}