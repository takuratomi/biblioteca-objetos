//
//  sistema_Usuarios.cpp
//  
//
//  Created by Toshiro on 20/02/13.
//
//

#include "sistema_Usuarios.h"

using namespace std;


void SUsuario::agregar_usuario_vector(Usuario monitor)
{
    Usuario usuario_nuevo;
    usuario_nuevo = NewUsuario(monitor);
    if (usuario_nuevo.get_Rol() != 0)
    {
        usuarios.push_back(usuario_nuevo);
        cout<<"Se guardo exitosamente el usuario."<<endl;
    }
    else{
        
        cout<<"No se pudo guardar el usuario.";
    }
}

Usuario SUsuario::get_usuario(int numero_identificador)
{
    int i;
    bool salir = false;
    Usuario temp;
    
    for (i=0; (i < usuarios.size() & salir == false); i++)
    {
        temp = usuarios[i];
        if (numero_identificador == temp.get_Id())
        {
            salir = true;
        }
    }
    
    return temp;
}


void SUsuario::borrar_usuario(Usuario monitor)
{
    int i, id_usuario_borrar;
    bool salir = false;
    Usuario temp;
    
    if ((monitor.get_Rol()) == 2)
    {
        cout<<"Escriba la identificacion del usuario que quiere borrar: ";
        cin>>id_usuario_borrar;
        cout<<endl;
        cout<<"Buscando..."<<endl;
        
        for (i=0; (i < usuarios.size() & salir == false); i++)
        {
            temp = usuarios[i];
            if (id_usuario_borrar == temp.get_Id())
            {
                if (temp.get_Rol() == 1)
                {
                    int seguro = 0;
                    cout<<"El nombre del estudiante es: "<<temp.get_Nombre()<<endl;
                    cout<<"Esta seguro de querer borrarlo (1)Si, (2)No: ";
                    cin>>seguro;
                    if (seguro == 1)
                    {
                        usuarios.erase(usuarios.begin()+i);
                        cout<<"Se a borrado satisfactoriamente el usuario. "<<endl;
                        salir = true;
                    }
                    else if(seguro == 2 & seguro != 1)
                    {
                        cout<<"funcion terminada"<<endl;
                    }

                }
                else if(temp.get_Rol() == 2)
                {
                    int seguro = 0;
                    cout<<"El nombre del monitor es: "<<temp.get_Nombre()<<endl;
                    cout<<"Esta seguro de querer borrarlo (1)Si, (2)No: ";
                    cin>>seguro;
                    if (seguro == 1)
                    {
                        usuarios.erase(usuarios.begin()+i);
                        cout<<"Se a borrado satisfactoriamente el usuario. "<<endl;
                        salir = true;
                    }
                    else if(seguro == 2 & seguro != 1)
                    {
                        cout<<"funcion terminada..."<<endl;
                    }
                    
                }
                                salir = true;
            }
        }
        
        
    }
    else{
        cout<<"esta opcion solo la puede hacer un monitor. "<<endl;
    }
    
}









