//
// Created by Paula on 13/12/2024.
//

#include <iostream>
#include <string>
#include "Contact_LinkedList.h"
using namespace std;


#ifndef CLASEUSUARIO_H
#define CLASEUSUARIO_H


class Usuario {
private:
    string nombre;
    string apellido1;
    string apellido2;
    string email;
    string telefono; //lo ponemos como string porque por si a caso se decide poner el +34 o los 00 el int no los puede interpretar bien
    LinkedList contactos;

public:
    //constructor default vacio
    Usuario(): nombre(""), apellido1(""), apellido2(""), email(""), telefono(""), contactos(){}
    //constructor parametrizado, const para que no se modifique dentro del cosntructor y & porque lo pasamos por referencia
    Usuario(const string& nombre, const string& apellido1, const string& apellido2, const string& email, const string& telefono): nombre(nombre), apellido1(apellido1), apellido2(apellido2), email(email),telefono(telefono){}

    //getters y setters
    string getNombre() const {return nombre;}
    void setNombre(const string& nuevoNombre) {nombre = nuevoNombre;}

    string getApellido1() const {return apellido1;}
    void setApellido1(const string& nuevoApellido1) {nombre = nuevoApellido1;}

    string getApellido2() const {return apellido2;}
    void setApellido2(const string& nuevoApellido2) {nombre = nuevoApellido2;}

    string getEmail() const {return email;}
    void setEmail(const string& nuevoEmail) {nombre = nuevoEmail;}

    string getTelefono() const {return telefono;}
    void setTelefono(const string& nuevoTelefono) {nombre = nuevoTelefono;}

    LinkedList& getContactos() { return contactos; }

    //métodos
    void imprimirInfo() const { //para imprimir la información del usuario
        cout << "Nombre: " << nombre << " " << apellido1 << " " << apellido2 << endl;
        cout << "Email: " << email << ", Telefono: " << telefono << endl;
        cout << "Numero de contactos: " << contactos.get_size() << endl; //cuantos contactos tiene este usuario
        cout << "Contactos:" << endl;
        contactos.print(); //imprime todos los contactos de la lista enlazada
    }

};


#endif //CLASEUSUARIO_H
