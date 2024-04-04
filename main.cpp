#include <bits/stdc++.h>
#include "rlutil.h"
#include "redsocial.h"
using namespace std;
using namespace rlutil;
Usuario* usuario;
Usuario* amigo;
int idUsuario, idAmigo;
int principal, user;


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
while(true)
    {
    cout << "Menu:" << endl;
    cout << "Da click en el numero indicado para continuar" << endl;

    cout << "1. Ver lista de usuarios" << endl; //ascii 49
    cout << "2. Ver lista de publicaciones" << endl;
    cout << "3. Entrar a un perfil de usuario" << endl;
    cout << "4. Agregar un nuevo usuario" << endl;
    cout << "0. Salir" << endl;

    cin>>principal;
    
    switch (principal)
        {

            case 1: //lista usuarios
            
                cout << "Lista de usuarios: "<<endl;
                Nonsense.mostrarUsuarios();
                break;
            

            case 2: //lista publicaciones
            
                cout << "Lista de publicaciones: " <<endl;
                Nonsense.mostrarPublicaciones();
                break;
            

            case 3: //perfil de usuario
                cout << "Ingrese el ID de un usuario para acceder: "<<endl;
                cout << "ID: ";
                cin >> idUsuario;
                usuario = Nonsense.getUsuario(idUsuario);
                if (usuario != nullptr) 
                {
                    cout<<"Haz accedido con exito!"<<endl;
menusuario:
                    cout<<"Da clic en el numero indicado para hacer alguna de estas opciones:"<<endl;
                    cout <<"1. Ver lista de amigos" << endl; //ascii 49
                    cout << "2. Ver lista de publicaciones" << endl;
                    cout << "3. Crear una nueva pulicacion" << endl;
                    cout << "4. Entrar al perfil de un amigo" << endl;
                    cout << "5. Agregar un nuevo amigo" <<endl;
                    cout << "0. salir" << endl;
                    cin>>user;

                    while (true) 
                    {
                        switch(user)
                        {
                            case 1://lista de amigos 
                                cout << "Esta es tu lista de amigos: " << endl;
                                usuario->mostrarAmigos();
                                break;
                            

                            case 2: //lista de publicaciones
                                cout << "Esta es tu lista de publicaciones: " << endl;
                                usuario->mostrarPublicaciones();
                                break;
                            
                            case 3://crear publicacion
                                cout << "Nueva publicacion: " << endl;
                                usuario->crearPublicacion();
                                break;
                            
                            case 4: //entrar perfil amigo
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
                            case 5: // agregar amigo
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
                            case 0:
                                goto inicio;
                                break;
                            default:
                                cout<<"Elige una de las opciones por favor"<<endl;
                                goto menusuario;
                                break;
                        }

                    }
                        
                }
                
                case 4: //agregar usuario
                    cout << "Agregar usuario: " << endl;
                    Nonsense.agregarUsuario();
                    break;

                case 0: //salir
                    return 0;

                default:
                    cout << "Escoge una de las opciones por favor" << endl;
                    goto inicio;
                    break;

            
             
        }
    }
}
