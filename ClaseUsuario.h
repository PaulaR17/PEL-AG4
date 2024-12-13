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

    void agregarContacto(const string& firstName, const string& lastName1, const string& lastName2, const string& phoneNumber, const string& email) {
        if (contactos.search_by_phone(phoneNumber) != nullptr) {
            cout << "Error: Ya existe un contacto con el numero de telefono " << phoneNumber << "." << endl;
            return;
        }

        Contact* nuevoContacto = new Contact(firstName, lastName1, lastName2, phoneNumber, email);
        contactos.insert_in_order(nuevoContacto); // Insertar en orden
        cout << "Contacto agregado correctamente." << endl;
    }

    void eliminarContacto(const string& criterio) {
        if (contactos.is_empty()) {
            cout << "No hay contactos en la lista para eliminar." << endl;
            return;
        }

        // Intentar eliminar por número de teléfono
        if (contactos.remove_by_phone(criterio)) {
            cout << "Contacto con el numero " << criterio << " eliminado correctamente." << endl;
            return;
        }

        // Intentar eliminar por nombre
        if (contactos.remove_by_name(criterio)) {
            cout << "Contacto con el nombre " << criterio << " eliminado correctamente." << endl;
            return;
        }
    }

    void buscarContacto(const string& criterio) {
        if (contactos.is_empty()) {
            cout << "No hay contactos en la lista." << endl;
            return;
        }

        // Buscar por número de teléfono
        Node* nodo = contactos.search_by_phone(criterio);

        // Si no se encuentra por número, buscar por nombre
        if (nodo == nullptr) {
            Node* current = contactos.get_first();
            while (current != nullptr) {
                if (current->data->firstName == criterio) {
                    nodo = current;
                    break;
                }
                current = current->next;
            }
        }

        // Mostrar el resultado
        if (nodo != nullptr) {
            cout << "Contacto encontrado:" << endl;
            nodo->data->print();
        } else {
            cout << "No se encontró ningún contacto con el criterio '" << criterio << "'." << endl;
        }
    }

    void mostrarContactosConDuplicados() {
        if (contactos.is_empty()) {
            cout << "No hay contactos en la lista." << endl;
            return;
        }

        Node* current = contactos.get_first();

        cout << "Lista de contactos:" << endl;
        while (current != nullptr) {
            current->data->print();
            current = current->next;
        }

        // Verificar duplicados manualmente
        cout << "\nVerificacion de duplicados:" << endl;
        bool hayDuplicados = false;
        Node* outer = contactos.get_first();

        while (outer != nullptr) {
            Node* inner = outer->next;
            while (inner != nullptr) {
                if (outer->data->phoneNumber == inner->data->phoneNumber) {
                    cout << "El numero de telefono " << outer->data->phoneNumber << " está duplicado entre contactos." << endl;
                    hayDuplicados = true;
                }
                inner = inner->next;
            }
            outer = outer->next;
        }

        if (!hayDuplicados) {
            cout << "No se encontraron duplicados en la lista de contactos." << endl;
        }
    }



};


#endif //CLASEUSUARIO_H
