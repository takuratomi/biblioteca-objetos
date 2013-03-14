#ifndef USUARIO_H_
#define USUARIO_H_
#include <iostream>
#include <string>

using namespace std;

class Usuario{
	
private:
    // nombre del usuario
    string name;

    // identificador del usuario
    int identification;

    // tiene multa = true else false
    bool estado_cuenta;

    // cargo del usuario 1=Estudiante 2=Monitor
    int rol;
    
    // libros que el usuario tiene prestados
    // limite de libros que puede tener un usuario, 7 libros
    int librosPrestados[7];
	
public:
    //funcion construtora
    Usuario();
    
    Usuario(string nombre, int numero_cuenta, bool estadoCuenta, int cargo);
    
    //funcion destructura
    ~Usuario();
    
    // metodos set
    // asigna el nombre al usuario
    void set_Nombre(string nombre);
    
    // asigna un identificador al usuario
    void set_Id(int numero_identificacion);
    
    //asigna el estado del usuario es decir si tiene multa o no
    void set_EstadoCuenta(bool estado);
    
    // asigna un cargo al usuario
    void set_Rol(int cargo);
    
    //el usuario tiene un libro de indentificador_libro
    void set_LibrosPrestados(int identificador_libro);
    
    // metodos get
    // retorna el nombre
    string get_Nombre();
    
    // retorna la identificacion del usuario
    int get_Id();
    
    // retorna el estado del usuario
    bool get_EstadoCuenta();
    
    // retorna el cargo del usuario
    int get_Rol();
    
    // saca el identificador del libro que tiene el usuario
    int *get_LibrosPrestados(int identificador_libro);
    
    //otras operaciones
    
    // El usuario tiene algun libro prestado else no tiene ningun libro prestado
    bool estaVacio();
    
    // verifica si en una ubicacion librosPrestados[pos] esta vacia
    bool checkLibros(int pos);
    
    // cuantos libros tiene el usuario
    int numeroLibros();
    
};

// crea un usuario nuevo
Usuario NewUsuario(Usuario monitor);


// muestra por consola la informacion del usuario
void pintarInfoUsuario(Usuario u);

#endif
