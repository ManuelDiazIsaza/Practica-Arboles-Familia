//
// Created by Manuel Diaz on 5/06/2018.
//

#include "Arbol.h"
#include <iostream>

using namespace std;

Arbol::Arbol()
{
    cab = nullptr;
}

Arbol::~Arbol()
{
    //MC)todo destructor
}

void Arbol::matrimonio()
{

    Familia *familia = new Familia();
    Persona *persona2 = new Persona();

    int id;

    if(cab == nullptr)
    {
        Persona *persona = new Persona();

        cout << "Ingrese los datos de las personas que se van a casar: " << endl;
        *persona = persona->crearPersona();

        cout << "Ingrese los datos de la otra persona que se va a casar: " << endl;
        *persona2 = persona2->crearPersona();

        if(persona->getEdad()<18 || persona2->getEdad()<18)
        {
            cout << "No se pueden casar ya que uno de los dos es menor de edad." << endl;
        }
        else
        {
            persona->setCasado(true);
            persona2->setCasado(true);
            if(persona->getHombre())
            {
                familia->setPadre(persona);
                familia->setMadre(persona2);
            }
            else
            {
                familia->setPadre(persona2);
                familia->setMadre(persona);
            }

            insertaFinal(familia);
        }
    }
    else
    {

        Persona *persona3 = nullptr;
        do
        {
            cout << "Ingrese el ID de la persona que se va a casar: ";
            cin >> id;
            persona3 = buscarPersona(id);
            if (persona3 == nullptr)
            {
                cout << "Persona no encontrada" << endl;
            }
            else if(persona3->getCasado())
            {
                cout << "Esta persona ya esta casada" << endl;
            }
        } while (persona3 == nullptr || persona3->getCasado());

        cout << "Ingrese los datos de la persona con la que se va a casar: " << endl;
        *persona2 = persona2->crearPersona();

        if(persona3->getEdad()<18 || persona2->getEdad()<18)
        {
            cout << "No se pueden casar ya que uno de los dos es menor de edad." << endl;
        }
        else
        {
            persona3->setCasado(true);
            persona2->setCasado(true);
        if(persona2->getHombre())
        {
            familia->setPadre(persona2);
            familia->setMadre(persona3);
        }
        else
        {
            familia->setMadre(persona2);
            familia->setPadre(persona3);
        }
        insertaFinal(familia);
        }
    }

}

Persona* Arbol::buscarPersona(int id)
{
    Familia *desplazaF = cab;
    //Persona *encontrado;

    while(desplazaF != nullptr)
    {
        if(desplazaF->getPadre()->getId() == id)
        {
            return desplazaF->getPadre();
        }
        else if(desplazaF->getMadre()->getId() == id)
        {
            return desplazaF->getMadre();
        }
        else
        {
        Persona *desplazaH = desplazaF->getHijosCab();
        while(desplazaH != nullptr)
        {
            if(desplazaH->getId() == id)
            {
                return desplazaH;
            }
            else
            {
                desplazaH = desplazaH->getSig();
            }
        }}
        desplazaF = desplazaF->getSig();
    }
    return nullptr;
}

void Arbol::insertaFinal(Familia *familia)
{
    Familia *desplaza = cab;
    if(cab==nullptr)
    {
        cab = familia;
    }
    else
    {
        while(desplaza!= nullptr)
        {
            if(desplaza->getSig()== nullptr)
            {
                desplaza->setSig(familia);
                familia->setAnt(desplaza);
                desplaza= nullptr;
            }
            else
            {
                desplaza=desplaza->getSig();
            }
        }
    }
    //cout << familia->getMadre()->getNombre() << " - " << familia->getPadre()->getNombre();
}
/*
void Arbol::imprimir()
{
    Familia *desplaza = cab;
    while (desplaza != nullptr)
    {

        cout << desplaza->getPadre()->getNombre() << endl;
        cout << desplaza->getMadre()->getNombre() << endl;
        desplaza = desplaza->getSig();
    }
    cout << endl;
}
*/

void Arbol::imprimir()
{
    Familia *desplaza = cab;
    int i=1;
    while (desplaza != nullptr)
    {

        cout<<"\nFamilia "<<i<<endl;
        cout<<"Padre: " << desplaza->getPadre()->getNombre() << endl;
        cout<<"Madre: " << desplaza->getMadre()->getNombre() << endl;
        desplaza->imprimirHijos();
        desplaza = desplaza->getSig();
        i++;
    }
    cout << endl <<endl;
}

void Arbol::nacimiento()
{
    bool encontro = false;
    Familia *pos1;
    int id=0;
    do
    {
    Familia *desplaza = cab;
    cout << "Ingrese el id de la persona que tuvo un hijo: " ;
    cin >> id;

    while (desplaza != nullptr)
    {
        if(desplaza->getPadre()->getId() == id || desplaza->getMadre()->getId() == id)
        {
            pos1 = desplaza;
            encontro = true;
            desplaza = desplaza->getSig();
        }
        else
        {
            desplaza = desplaza->getSig();
        }
    }
    if(!encontro)
    {
        cout << "Esta persona no esta casada o no pertenece a la familia." << endl;
    }
    }while(!encontro);

    int cantidad;
    cout << "Cuantos hijos tuvo: " ;
    cin >> cantidad;

    for(int i=0;i<cantidad;i++)
    {
    pos1->nacimiento();
    }
}

void Arbol::fallecimiento()
{
    int id;
    cout << "Ingrese el id de la persona que fallecio:";
    cin >> id;
    Persona *persona =  buscarPersona(id);
    if(persona== nullptr)
    {
        cout << "No se encontro la persona. Compruebe el ID de la persona" << endl;
    }
    else
    {
    if(persona->getVivo())
    {
        persona->setVivo(false);
        cout << "Se ha registrado el fallecimiento." << endl;
    }
    else
    {
        cout << "Esta persona ya habia fallecido anteriormente." << endl;
    }
    }
}

void Arbol::hijosPersona()
{
    int id;
    cout << "Ingrese el id de la persona de la cual quiera consultar sus hijos:";
    cin >> id;
    Persona *persona =  buscarPersona(id);
    if(persona == nullptr)
    {
        cout << "No se encontro la persona. Compruebe el ID de la persona" << endl;
    }
    else
    {
        if(!persona->getCasado())
        {
            cout << "Esta Persona no esta casada, por lo tanto no es padre o madre en una familia" << endl;
        }
        else
        {
            Familia *desplaza = cab;
            Familia *pos1;
            while (desplaza != nullptr)
            {
                if(desplaza->getPadre()->getId() == id || desplaza->getMadre()->getId() == id)
                {
                    pos1 = desplaza;
                    desplaza = desplaza->getSig();
                }
                else
                {
                    desplaza = desplaza->getSig();
                }
            }
            pos1->imprimirHijos();
        }
    }
}

void Arbol::estadoCivil()
{
    int id;
    cout << "Ingrese el id de la persona que desea consultar su estado civil:";
    cin >> id;
    Persona *persona =  buscarPersona(id);
    if(persona== nullptr)
    {
        cout << "No se encontro la persona. Compruebe el ID de la persona" << endl;
    }
    else
    {
        if(persona->getCasado())
        {
            cout << "Esta persona se encuentra casado(a)." << endl;
        }
        else
        {
            cout << "Esta persona es soltera o viudo(a)." << endl;
        }
    }
}

void Arbol::nietosPersona()
{
    int id;

    cout << "Ingrese el id de la persona que desea consultar sus nietos:";
    cin >> id;
    Persona *persona =  buscarPersona(id);
    bool nietos= false;


    if(persona== nullptr)
    {
        cout<< "No se encontro el id de esa persona, por favor verifique los datos" << endl;
        nietos = true;
    }
    else if(!persona->getCasado())
    {
        cout<<"Esta persona no esta casado, no tiene nietos" << endl;
        nietos = true;
    }
    else
    {
        Familia *desplazaF = cab;

        while(desplazaF != nullptr){

            if(desplazaF->getPadre()->getId() == id || desplazaF->getMadre()->getId() == id)
            {
                Persona *desplazaH = desplazaF->getHijosCab();

                while(desplazaH!= nullptr)
                {

                    if(desplazaH->getCasado())
                    {
                    Familia *desplazaF2 = cab;
                    while(desplazaF2!= nullptr)
                    {
                        if(desplazaF2->getPadre()->getId() == desplazaH->getId() || desplazaF2->getMadre()->getId() == desplazaH->getId())
                        {
                            if(desplazaF2->getHijosCab()== nullptr)
                            {
                                desplazaF2 = desplazaF2->getSig();
                            }
                            else
                            {
                            cout << "Nietos de " << persona->getNombre() << " por parte de "<< desplazaH->getNombre() << ": ";
                            desplazaF2->imprimirNietos();
                            desplazaF2 = desplazaF2->getSig();
                            nietos = true;
                            }
                        }
                        else
                        {
                            desplazaF2 = desplazaF2->getSig();
                        }
                    }
                    desplazaH = desplazaH->getSig();
                    }
                    else
                    {
                        desplazaH = desplazaH->getSig();
                    }
                }
                desplazaF = desplazaF ->getSig();
            }
            else
            {
                desplazaF = desplazaF->getSig();
            }
        }


    }

    if(!nietos)
    {
        cout << "Esta persona no tiene nietos." << endl;
    }

}

void Arbol::interfazPPal()
{
    int opcion = 0;

            do
            {
                cout << ":::::::::::::::::::::::::::::MENU PRINCIPAL:::::::::::::::::::::::" << endl;
                cout << "------------- Arbol Genealogico -------------" << endl;
                cout << "1: Nuevo Matrimonio" << endl;
                cout << "2: Nuevo Nacimiento" << endl;
                cout << "3: Fallecimiento" << endl;
                cout << "4: Mostrar todas las familias." << endl;
                cout << "5: Consultar hijos de una persona" << endl;
                cout << "6: Consultar estado civil de una persona." << endl;
                cout << "7: Consultar nietos de una persona." << endl;
                cout << "8: Consultar abuelos de una persona." << endl;
                cout << "9: Consultar padres y hermanos de una persona." << endl;

                cout << "Su opcion: " << endl;
                cin >> opcion;
                switch (opcion) {
                    case 1:
                        matrimonio();
                        break;
                    case 2:
                        nacimiento();
                        break;
                    case 3:
                        fallecimiento();
                        break;
                    case 4:
                        imprimir();
                        break;
                    case 5:
                        hijosPersona();
                        break;
                    case 6:
                        estadoCivil();
                        break;
                    case 7:
                        nietosPersona();
                        break;
                    default:
                        if (opcion != 10)
                            cout << endl << "=== Opcion no valida ===" << endl;
                }

            } while (opcion != 10);
}