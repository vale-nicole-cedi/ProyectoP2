#include <bits/stdc++.h>
#include "rlutil.h"
#include "redsocial.h"
using namespace std;
using namespace rlutil;
Usuario* usuario;
UsuarioPremium* usuariopremium;
Usuario* amigo;
int idUsuario, idAmigo;
int principal, user;



int main()
{
    Usuario *u1 = new Usuario ("DanielaUwuKawaii", 16, "Mexicana");
    Usuario *u2= new Usuario ("ValeriaOnichan", 17, "Espaniola");
    Usuario *u3 = new Usuario ("DaniArigato", 12, "Peruana");

    vector<Usuario*> listaUsuarios;
    listaUsuarios.push_back(u1);
    listaUsuarios.push_back(u2);
    listaUsuarios.push_back(u3);

    Publicacion *p1 = new Publicacion ( u1,"01/03/2008", "Hay/personas/falsas");
    Publicacion *p2 = new Publicacion (u2, "20/12/2014", "No/la/creo/vieron/lo/que/sucedio/hoy?");
    Publicacion *p3 = new Publicacion (u3, "29/02/2023", "UwU");

    vector<Publicacion*> listaPublicaciones;
    listaPublicaciones.push_back(p1);
    listaPublicaciones.push_back(p2);
    listaPublicaciones.push_back(p3);

    RedSocial gs("GossipNet", listaUsuarios, listaPublicaciones);

    cout<<"   __________  __________ ________     _   ______________"<<endl;
    cout<<"  / ____/ __ \\/ ___/ ___//  _/ __ \\   / | / / ____/_  __/"<<endl;
    cout<<" / / __/ / / /\\__ \\\\__ \\ / // /_/ /  /  |/ / __/   / /   "<<endl;
    cout<<"/ /_/ / /_/ /___/ /__/ // // ____/  / /|  / /___  / /    "<<endl;
    cout<<"\\____/\\____//____/____/___/_/      /_/ |_/_____/ /_/     "<<endl;
                                                                       
    while(true)
    {
        menuprincipal:
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
                gs.mostrarUsuarios();
                break;
            

            case 2: //lista publicaciones
            
                cout << "Lista de publicaciones: " <<endl;
                gs.mostrarPublicaciones();
                break;
            

            case 3: //perfil de usuario
                cout << "Ingrese el ID de un usuario para acceder: "<<endl;
                cout << "ID: ";
                cin >> idUsuario;
                usuario = gs.getUsuario(idUsuario);
                if (usuario != nullptr) 
                {
                    if(gs.revisarpremium(idUsuario) == true){
                        usuariopremium = gs.getUsuarioPremium(idUsuario);
                        cout<<"Haz accedido con exito!"<<endl;
                        
                    do 
                    {
                        menusuariopremium:
                        cout<<"Da clic en el numero indicado para hacer alguna de estas opciones:"<<endl;
                        cout <<"1. Ver lista de amigos" << endl; //ascii 49
                        cout << "2. Ver lista de publicaciones" << endl;
                        cout << "3. Crear una nueva pulicacion" << endl;
                        cout << "4. Entrar al perfil de un amigo" << endl;
                        cout << "5. Agregar un nuevo amigo" <<endl;
                        cout << "6. Ver todas las publicaciones privadas" << endl;
                        cout << "7. Crear una nueva publicacion privada" << endl;
                        cout << "0. salir" << endl;
                        cin>>user;

                        switch(user)
                        {
                            case 1://lista de amigos 
                                cout << "Esta es tu lista de amigos: " << endl;
                                usuario->mostrarAmigos();
                                break;
                            

                            case 2: //lista de publicaciones
                            {
                                cout << "Esta es tu lista de publicaciones: " << endl;
                                usuario->mostrarPublicaciones();
                                break;
                            }
                            
                            case 3://crear publicacion
                            {
                                cout << "Nueva publicacion: " << endl;
                                usuario->crearPublicacion();
                                Publicacion* newpub = usuario->publicaciones[(usuario->publicaciones.size())-1];
                                gs.agregarpublicacion(newpub);
                                break;
                            }
                            
                            case 4: //entrar perfil amigo
                            {
                                cout << "Escribe el ID de tu amigo" << endl;
                                cout << "ID de amigo: ";
                                cin >> idAmigo;
                                amigo = gs.getUsuario(idAmigo);
                                if (amigo != nullptr)
                                {
                                    cout << "Esta es la informacion de tu amigo: "<<endl;
                                    amigo->mostrar();
                                }
                                break;
                            }
                                
                            case 5: // agregar amigo
                            {
                                cout << "Agregar un amigo"<< endl;
                                cout << "Escribe el ID de tu nuevo amigo" << endl;
                                cout << "ID de nuevo amigo: ";
                                cin >> idAmigo;
                                amigo = gs.getUsuario(idAmigo);
                                if (amigo != nullptr)
                                {
                                    cout << "Se ha agregado correctamente tu nuevo amigo!" << endl;
                                    usuario->agregarAmigo(amigo);
                                }
                                break;
                            }

                            case 6: //ver todas las publicaciones privadas
                            {
                                cout << "Lista de publicaciones: " <<endl;
                                gs.mostrarPublicacionesPrivadas();
                                break;
                            }

                            case 7: //crear nueva publicacion privada
                            {
                                cout << "Nueva publicacion: " << endl;
                                usuariopremium->agregarPrivado();
                                Publicacion* newpub = usuariopremium->publicacionespriv[(usuariopremium->publicacionespriv.size())-1];
                                gs.agregarpublicacionprivada(newpub);
                                break;
                            }
                                
                            case 0:
                                break;
                            default:
                                cout<<"Elige una de las opciones por favor"<<endl;
                                goto menusuariopremium;
                                break;
                        }

                        
                    } while (user !=0);


                    } else {
                        cout<<"Haz accedido con exito!"<<endl;
                    do 
                    {
                        menusuario:
                        cout<<"Da clic en el numero indicado para hacer alguna de estas opciones:"<<endl;
                        cout <<"1. Ver lista de amigos" << endl; //ascii 49
                        cout << "2. Ver lista de publicaciones" << endl;
                        cout << "3. Crear una nueva pulicacion" << endl;
                        cout << "4. Entrar al perfil de un amigo" << endl;
                        cout << "5. Agregar un nuevo amigo" <<endl;
                        cout << "0. salir" << endl;
                        cin>>user;

                        switch(user)
                        {
                            case 1://lista de amigos 
                                cout << "Esta es tu lista de amigos: " << endl;
                                usuario->mostrarAmigos();
                                break;
                            

                            case 2: //lista de publicaciones
                            {
                                cout << "Esta es tu lista de publicaciones: " << endl;
                                usuario->mostrarPublicaciones();
                                break;
                            }
                            
                            case 3://crear publicacion
                            {
                                cout << "Nueva publicacion: " << endl;
                                usuario->crearPublicacion();
                                Publicacion* newpub = usuario->publicaciones[(usuario->publicaciones.size())-1];
                                gs.agregarpublicacion(newpub);
                                break;
                            }
                            
                            case 4: //entrar perfil amigo
                            {
                                cout << "Escribe el ID de tu amigo" << endl;
                                cout << "ID de amigo: ";
                                cin >> idAmigo;
                                amigo = gs.getUsuario(idAmigo);
                                if (amigo != nullptr)
                                {
                                    cout << "Esta es la informacion de tu amigo: "<<endl;
                                    amigo->mostrar();
                                }
                                break;
                            }
                                
                            case 5: // agregar amigo
                            {
                                cout << "Agregar un amigo"<< endl;
                                cout << "Escribe el ID de tu nuevo amigo" << endl;
                                cout << "ID de nuevo amigo: ";
                                cin >> idAmigo;
                                amigo = gs.getUsuario(idAmigo);
                                if (amigo != nullptr)
                                {
                                    cout << "Se ha agregado correctamente tu nuevo amigo!" << endl;
                                    usuario->agregarAmigo(amigo);
                                }
                                break;
                            }
                                
                            case 0:
                                break;
                            default:
                                cout<<"Elige una de las opciones por favor"<<endl;
                                goto menusuario;
                                break;
                        }

                        
                    } while (user !=0);
                    }
                        
                }
                break;
                
                case 4: //agregar usuario
                    cout << "Agregar usuario: " << endl;
                    int x;
                    do 
                    {
                        premium:
                        cout<<"Elige el tipo de usuario a crear:"<<endl;
                        cout << "1. Normal " << endl; 
                        cout << "2. Premium" << endl;
                        cin>>x;

                        switch(x)
                        {
                            case 1://Normal
                                cout << "Disfruta de Gossip Net como usuario normal!" << endl;
                                gs.agregarUsuario();
                                goto menuprincipal;
                                break;
                            

                            case 2: //Premium
                                cout << "Se te cobrara $50 pesos para ser un usuario premium" << endl;
                                gs.agregarUsuarioPremium();
                                goto menuprincipal;
                                break;
                            

                            default:
                                cout<<"Elige una de las opciones por favor"<<endl;
                                goto premium;
                                break;
                        }

                    } while (x !=0);
                    break;

                case 0: //salir
                    return 0;

                default:
                    cout << "Escoge una de las opciones por favor" << endl;

                    break;

            
             
        }
    }
    return 0;
}