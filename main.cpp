#include <iostream>
#include "Contact_LinkedList.h"
#include "ClaseUsuario.h"

using namespace std;

void inicializarUsuarios(Usuario*& usuario1, Usuario*& usuario2, Usuario*& usuario3) { //para crear los usuarios predeterminados

    //creamos los 3 usuarios predeterminados
    usuario1 = new Usuario("Paula", "Garcia", "Lopez", "paula@example.com", "649740755");
    usuario2 = new Usuario("Juan", "Perez", "Martinez", "juan@example.com", "689957019");
    usuario3 = new Usuario("Maria", "Fernandez", "Gomez", "maria@example.com", "676461747");

    //al ususario 1 le ponemos 3 contactos
    usuario1->getContactos().insert_tail(new Contact("Juan", "Magan", "Romero", "625149660", "john.doe@example.com"));
    usuario1->getContactos().insert_tail(new Contact("Javier", "Garcia", "Gonzalez", "612493423", "jane.doe@example.com"));
    usuario1->getContactos().insert_tail(new Contact("Maria", "Hernandez", "Stilton", "666672633", "alice.johnson@example.com"));

    //al usuario 2 le ponemos 2 contactos
    usuario2->getContactos().insert_tail(new Contact("Carlos", "Diaz", "Sanchez", "666964723", "carlos.diaz@example.com"));
    usuario2->getContactos().insert_tail(new Contact("Laura", "Lopez", "Martinez", "628560126", "laura.lopez@example.com"));

    //al usuario 3 le ponemos 4 contactos
    usuario3->getContactos().insert_tail(new Contact("Marta", "Blanco", "Perez", "690285432", "marta.blanco@example.com"));
    usuario3->getContactos().insert_tail(new Contact("Javier", "Gonzalez", "Lopez", "684270945", "javier.gonzalez@example.com"));
    usuario3->getContactos().insert_tail(new Contact("Lucia", "Hernandez", "Garcia", "607897394", "lucia.hernandez@example.com"));
    usuario3->getContactos().insert_tail(new Contact("Raul", "Gutierrez", "Diaz", "600424184", "raul.gutierrez@example.com"));

}

Usuario* iniciarSesion(Usuario* usuario1, Usuario* usuario2, Usuario* usuario3) { //todo el tema de inicio de sesion
    string nombre, apellido1, apellido2, telefono;

    //le preguntamos al usuario sus datos
    cout << "Introduce tu nombre: ";
    cin >> nombre;
    cout << "Introduce tu primer apellido: ";
    cin >> apellido1;
    cout << "Introduce tu segundo apellido: ";
    cin >> apellido2;
    cout << "Introduce tu numero de telefono: ";
    cin >> telefono;

    //al ser usuarios predeterminados y solo 3 nos podemos permitir el comprobar 1 por 1

    if (usuario1->getNombre() == nombre && usuario1->getApellido1() == apellido1 &&
        usuario1->getApellido2() == apellido2 && usuario1->getTelefono() == telefono) {
        cout << "Sesion iniciada como " << usuario1->getNombre() << endl;
        return usuario1;
        }

    if (usuario2->getNombre() == nombre && usuario2->getApellido1() == apellido1 &&
        usuario2->getApellido2() == apellido2 && usuario2->getTelefono() == telefono) {
        cout << "Sesion iniciada como " << usuario2->getNombre() << endl;
        return usuario2;
        }

    if (usuario3->getNombre() == nombre && usuario3->getApellido1() == apellido1 &&
        usuario3->getApellido2() == apellido2 && usuario3->getTelefono() == telefono) {
        cout << "Sesion iniciada como " << usuario3->getNombre() << endl;
        return usuario3;
        }

    cout << "Credenciales incorrectas. Intenta nuevamente." << endl; //si las creedenciales no corresponden...
    return nullptr;
}

int main() {
    Usuario* usuario1 = nullptr;
    Usuario* usuario2 = nullptr;
    Usuario* usuario3 = nullptr;
    inicializarUsuarios(usuario1, usuario2, usuario3); //inicializamos los users y sus contactos

    Usuario* usuarioActivo = nullptr; //usuario logueado actualmente (lo empezamos a 0 porque de momento no hay ningun user logueado)
    int opcion;

    //todo el menú del programa
    do {
        cout << "\n=== Menu de Inicio de Sesion ===\n";
        cout << "1. Iniciar sesion\n";
        cout << "2. Cerrar sesion\n";
        cout << "3. Mostrar contactos del usuario activo\n";
        cout << "4. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (usuarioActivo != nullptr) {
                    cout << "Ya hay un usuario logueado. Por favor, cierra sesion primero.\n";
                } else {
                    usuarioActivo = iniciarSesion(usuario1, usuario2, usuario3);
                }
            break;
            case 2:
                if (usuarioActivo == nullptr) {
                    cout << "No hay ningun usuario logueado.\n";
                } else {
                    cout << "Sesion cerrada para " << usuarioActivo->getNombre() << ".\n";
                    usuarioActivo = nullptr;
                }
            break;
            case 3:
                if (usuarioActivo == nullptr) {
                    cout << "No hay ningun usuario logueado. Por favor, inicia sesion primero.\n";
                } else {
                    usuarioActivo->imprimirInfo();
                }
            break;
            case 4:
                cout << "Saliendo del programa...\n";
            break;
            default:
                cout << "Opcion no valida. Intenta nuevamente.\n";
        }
    } while (opcion != 4);

    //liberanis la memoria de los usuarios al salir
    delete usuario1;
    delete usuario2;
    delete usuario3;

    return 0;
}
