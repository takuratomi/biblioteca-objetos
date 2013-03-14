#include "usuario.h"
#include <iostream>
using namespace std;

Usuario::Usuario()
{
    int i;
    
    for (i=0; i<7; i++)
    {
        librosPrestados[i] = 0;
    }
}

Usuario::Usuario(string nombre, int numero_cuenta, bool estadoCuenta, int cargo): name(nombre), identification(numero_cuenta), estado_cuenta(estadoCuenta), rol(cargo)
{
    int i;
    for (i=0; i<8; i++)
    {
        this->librosPrestados[i] = 0;
    }
}


Usuario::~Usuario(){}

void Usuario::set_Nombre(string nombre)
{
    this->name = nombre;
}


void Usuario::set_Id(int identificador)
{
    this->identification = identificador;
}


void Usuario::set_EstadoCuenta(bool estado)
{
    this->estado_cuenta = estado;
}


void Usuario::set_Rol(int cargo)
{
    this->rol = cargo;
}


void Usuario::set_LibrosPrestados(int identificador_libro)
{
    int i, salir = 0;
    
    if (estaVacio() == true)
    {
        cout<<"el usuario no puede tener mas libros"<<endl;
    }
    else{
        for (i=0;(i<7 & salir == 0);i++)
        {
            if (checkLibros(i) == true)
            {
                librosPrestados[i] = identificador_libro;
                salir = 1;
                cout<<"se a guardado el libro"<<endl;
            }
            
        }
    }
    
}



string Usuario::get_Nombre()
{
    return name;
}


int Usuario::get_Id()
{
    return identification;
}

bool Usuario::get_EstadoCuenta()
{
    return estado_cuenta;
}

int Usuario::get_Rol()
{
    return rol;
}


int* Usuario::get_LibrosPrestados(int identificador_libro)
{
    int i, salir = 0, *puntero;
    
    if (estaVacio() == true)
    {
        cout<<"no hay ningun libro"<<endl;
    }
    else
    {
        for (i=0; (i<7 & salir == 0); i++)
        {
            puntero = &librosPrestados[i];
            if (*(puntero) == identificador_libro)
            {
                salir = 1;
            }
        }
    }
    
    if (salir == 0)
    {
        cout<<"ese libro no lo tiene el usuario"<<endl;
    }
    
    return puntero;
}


bool Usuario::checkLibros(int pos)
{
    bool verificadora = false;
    if (librosPrestados[pos] == 0)
    {
        verificadora = true;
    }
    
    return verificadora;
}

bool Usuario::estaVacio()
{
    int i, contador = 0;
    bool temp = false;
    
    for (i=0; i<7 & contador == 0; i++)
    {
        if (librosPrestados[i] != 0)
        {
            contador++;
        }
    }
    
    if (contador != 0)
    {
        temp = true;
    }
    
    return temp;
}

int Usuario::numeroLibros()
{
    int i, contador = 0;
    
    for (i=0; i<7; i++)
    {
        if (librosPrestados[i] != 0)
        {
            contador++;
        }
    }
    
    return contador;
}


Usuario NewUsuario(Usuario monitor)
{
    Usuario temp;
    string nombre;
    int NumeroCuenta, cargo;
    
    if (monitor.get_Rol() == 2)
    {
        cout<<"Que va a crear:  (1) Estudiante (2) Monitor "<<endl;
        cin>>cargo;
        cout<<"Escriba el nombre del usuario: ";
        cin>>nombre;
        cout<<"Escriba el numero de cedula/tarjeta de identidad: ";
        cin>>NumeroCuenta;
        temp.set_Nombre(nombre);
        temp.set_Id(NumeroCuenta);
        temp.set_Rol(cargo);
        temp.set_EstadoCuenta(false);
        cout<<"La creacion del usuario fue exitosa."<<endl;
    }
    else{
        cout<<"esta opcion solo la puede hacer un monitor. "<<endl;
    }
        
    
    
    return temp;
}

void pintarInfoUsuario(Usuario u)
{
    
    cout<<"----------- Su informacion ----------------------------"<<endl;
    cout<<"Su nombre es: "<<u.get_Nombre()<<endl;
    cout<<"Su identificacion es: "<<u.get_Id()<<endl;
    if(u.get_EstadoCuenta() == false)
    {
        cout<<"No debe multas"<<endl;
    }
    else{
        cout<<"Tiene multa"<<endl;
    }
    if (u.get_Rol() == 1)
    {
        cout<<"Usted es un Estudiante"<<endl;
    }
    else if(u.get_Rol() == 2)
    {
        cout<<"Usted es un Monitor"<<endl;
    }
    
    cout<<"------------------------------------------"<<endl;
}












