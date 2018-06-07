/*
  Archivo: Nodo.cpp
  Autor: Luis Yovany Romo Portilla
  Email: luis.romo@correounivalle.edu.co
  Fecha creaciC3n: 2017-08-31
  Fecha C:ltima modificaciC3n: 2017-08-31
  VersiC3n: 0.1
  Licencia: GPL
*/

#include <iostream>
#include "Familia.h"

Familia::Familia()
{
    padre = nullptr;
    madre = nullptr;
    hijoscab = nullptr;
    ant = nullptr;
    sig = nullptr;
}

Familia::Familia(Persona *padre, Persona *madre)
{
    this -> padre = padre;
    this -> madre = madre;
    hijoscab = nullptr;
    ant = nullptr;
    sig = nullptr;
}

Familia::~Familia()
{
    //MC)todo destructor
}

void Familia::setPadre(Persona *padre)
{
    this -> padre = padre;
}

Persona* Familia::getPadre(){
    return this -> padre;
}

void Familia::setMadre(Persona *madre)
{
    this -> madre = madre;
}

Persona* Familia::getMadre(){
    return this -> madre;
}

void Familia::nacimiento()
{
    int id,edad;
    string nombre, apellido, hombre;
    bool hombre2;
    bool generoValido=false;
    cout << "ingrese el id de la persona que acaba de nacer: " ;
    cin >> id;
    cout << "ingrese el nombre de la persona que acaba de nacer: " ;
    cin >> nombre;
    cout << "ingrese el apellido de la persona que acaba de nacer: " ;
    cin >> apellido;
    while(!generoValido)
    {
    cout << "Es hombre el nuevo integrante de la familia: " ;
    cin >> hombre;
    if(hombre == "si")
    {
        hombre2 = true;
        generoValido = true;
    }
    else if(hombre == "no")
    {
        hombre2 = false;
        generoValido = true;
    }
    else
    {
        cout << "ingresaste una opcion incorrecta." << endl;
    }
    }
    cout << "Ingrese la edad del nuevo integrante de la familia " ;
    cin >> edad;

    Persona *nuevo = new Persona();
    nuevo->setId(id);
    nuevo->setNombre(nombre);
    nuevo->setApellidos(apellido);
    nuevo->setHombre(hombre2);
    nuevo->setEdad(edad);
    nuevo->setVivo(true);
    nuevo->setPapa(padre);
    nuevo->setMama(madre);

        if(hijoscab==nullptr)
        {
           hijoscab = nuevo;
        }
        else
        {
            hijoscab->setAnt(nuevo);
            nuevo->setSig(hijoscab);
            hijoscab = nuevo;
            nuevo->setAnt(nullptr);
     }

}

void Familia::nacimiento(int id,string nombre, string apellido, bool hombre,int edad)
{

    Persona *nuevo = new Persona();
    nuevo->setId(id);
    nuevo->setNombre(nombre);
    nuevo->setApellidos(apellido);
    nuevo->setHombre(hombre);
    nuevo->setEdad(edad);
    nuevo->setVivo(true);
    nuevo->setPapa(padre);
    nuevo->setMama(madre);

    if(hijoscab==nullptr)
    {
        hijoscab = nuevo;
    }
    else
    {
        hijoscab->setAnt(nuevo);
        nuevo->setSig(hijoscab);
        hijoscab = nuevo;
        nuevo->setAnt(nullptr);
    }

}

void Familia::imprimirHijos()
{
        Persona *desplaza = hijoscab;

        if(hijoscab == nullptr)
        {
            cout << "Esta familia no tiene hijos.";
        }
        else
        {
        cout << "Hijo(s): ";
        while (desplaza != NULL)
        {
            cout << desplaza->getNombre() << " - ";
            desplaza = desplaza->getSig();
        }
        }
        cout << endl;
}

Persona* Familia::getHijosCab()
{
    return this -> hijoscab;
}

void Familia::setSig(Familia *sig){
    this -> sig = sig;
}

Familia* Familia::getSig()
{
    return this -> sig;
}

void Familia::setAnt(Familia *ant){
    this -> ant = ant;
}

Familia* Familia::getAnt()
{
    return this -> ant;
}
