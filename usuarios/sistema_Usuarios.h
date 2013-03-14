//
//  sistema_Usuarios.h
//  
//
//  Created by Toshiro on 20/02/13.
//
//

#ifndef ____sistema_Usuarios__
#define ____sistema_Usuarios__

#include <iostream>
#include <vector>
#include "usuario.h"


//clase sistema de usuarios
class SUsuario {

    // vector de usuarios
    vector<Usuario> usuarios;
    
public:
    // el monitor crea un nuevo usuario y despues lo agrega al sistema de usuarios
    void agregar_usuario_vector(Usuario monitor);
    
    // se busca un usuario usando su numero de identificacion
    Usuario get_usuario(int numero_identificador );
    
    // el monitor borra un usuario del sistema de usuarios
    void borrar_usuario(Usuario monitor);
};

#endif /* defined(____sistema_Usuarios__) */
