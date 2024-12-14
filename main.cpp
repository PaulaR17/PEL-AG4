#include <iostream>
#include "Contact_LinkedList.h"
#include "ClaseUsuario.h"
#include <limits> // Para std::numeric_limits

using namespace std;
void inicializarUsuarios(Usuario*& usuario1, Usuario*& usuario2, Usuario*& usuario3) {
    // Creamos los 3 usuarios predeterminados
    usuario1 = new Usuario("Paula", "Garcia", "Lopez", "paula@example.com", "649740755");
    usuario2 = new Usuario("Juan", "Perez", "Martinez", "juan@example.com", "689957019");
    usuario3 = new Usuario("Maria", "Fernandez", "Gomez", "maria@example.com", "676461747");

    // Al usuario 1 le ponemos 5 contactos únicos
    usuario1->getContactos().insert_tail(new Contact("Juan", "Magan", "Romero", "625149660", "juan.magan@example.com"));
    usuario1->getContactos().insert_tail(new Contact("Javier", "Garcia", "Gonzalez", "612493423", "javier.gonzalez@example.com"));
    usuario1->getContactos().insert_tail(new Contact("Maria", "Hernandez", "Stilton", "666672633", "maria.stilton@example.com"));
    usuario1->getContactos().insert_tail(new Contact("Ana", "Lopez", "Martinez", "611234567", "ana.lopez@example.com"));
    usuario1->getContactos().insert_tail(new Contact("Carlos", "Perez", "Diaz", "644789123", "carlos.perez@example.com"));

    // Al usuario 2 le ponemos 6 contactos únicos
    usuario2->getContactos().insert_tail(new Contact("Laura", "Lopez", "Martinez", "628560126", "laura.lopez@example.com"));
    usuario2->getContactos().insert_tail(new Contact("Carlos", "Diaz", "Sanchez", "666964723", "carlos.diaz@example.com"));
    usuario2->getContactos().insert_tail(new Contact("Luis", "Hernandez", "Garcia", "699876543", "luis.hernandez@example.com"));
    usuario2->getContactos().insert_tail(new Contact("Marta", "Rodriguez", "Lopez", "657456789", "marta.rodriguez@example.com"));
    usuario2->getContactos().insert_tail(new Contact("David", "Gomez", "Blanco", "609123987", "david.gomez@example.com"));
    usuario2->getContactos().insert_tail(new Contact("Elena", "Ramirez", "Santos", "652879431", "elena.ramirez@example.com"));

    // Al usuario 3 le ponemos 7 contactos únicos
    usuario3->getContactos().insert_tail(new Contact("Marta", "Blanco", "Perez", "690285432", "marta.blanco@example.com"));
    usuario3->getContactos().insert_tail(new Contact("Javier", "Gonzalez", "Lopez", "684270945", "javier.gonzalez@example.com"));
    usuario3->getContactos().insert_tail(new Contact("Lucia", "Hernandez", "Garcia", "607897394", "lucia.hernandez@example.com"));
    usuario3->getContactos().insert_tail(new Contact("Raul", "Gutierrez", "Diaz", "600424184", "raul.gutierrez@example.com"));
    usuario3->getContactos().insert_tail(new Contact("Sofia", "Martinez", "Fernandez", "631245678", "sofia.martinez@example.com"));
    usuario3->getContactos().insert_tail(new Contact("Pedro", "Suarez", "Lara", "678543210", "pedro.suarez@example.com"));
    usuario3->getContactos().insert_tail(new Contact("Carmen", "Diaz", "Lopez", "698123456", "carmen.diaz@example.com"));
}


Usuario* iniciarSesion(Usuario* usuario1, Usuario* usuario2, Usuario* usuario3) { //todo el tema de inicio de sesion
    string nombre, apellido1;

    //le preguntamos al usuario sus datos
    cout << "Introduce tu nombre: ";
    cin >> nombre;
    cout << "Introduce tu primer apellido: ";
    cin >> apellido1;


    //al ser usuarios predeterminados y solo 3 nos podemos permitir el comprobar 1 por 1

    if (usuario1->getNombre() == nombre && usuario1->getApellido1() == apellido1) {
        cout << "Sesion iniciada como " << usuario1->getNombre() << endl;
        return usuario1;
        }

    if (usuario2->getNombre() == nombre && usuario2->getApellido1() == apellido1) {
        cout << "Sesion iniciada como " << usuario2->getNombre() << endl;
        return usuario2;
        }

    if (usuario3->getNombre() == nombre && usuario3->getApellido1() == apellido1) {
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
    inicializarUsuarios(usuario1, usuario2, usuario3); // Inicializamos los usuarios y sus contactos

    // Lista de todos los usuarios
    Usuario* usuarios[] = {usuario1, usuario2, usuario3};
    int totalUsuarios = 3;

    Usuario* usuarioActivo = nullptr; // Usuario logueado actualmente
    int opcion;

    // Menú del programa
    do {
        cout << "\n=== Menu de Inicio de Sesion ===\n";
        cout << "1. Iniciar sesion\n";
        cout << "2. Cerrar sesion\n";
        cout << "3. Mostrar contactos del usuario activo\n";
        cout << "4. Agregar Contacto\n";
        cout << "5. Eliminar contacto\n";
        cout << "6. Modificar contacto\n";
        cout << "7. Transferir contacto\n";
        cout << "8. Salir\n";
        cout << "Elige una opcion: ";

        cin >> opcion;

        // Manejar entradas no válidas
        if (cin.fail()) {
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta
            cout << "Entrada no valida. Por favor, introduce un numero.\n";
            continue; // Regresa al inicio del bucle
        }

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
                    cout << "\n=== Contactos del Usuario Activo ===\n";
                    usuarioActivo->mostrarContactosConDuplicados();
                }
                break;
            case 4:
                if (usuarioActivo == nullptr) {
                    cout << "No hay ningun usuario logueado. Por favor, inicia sesion primero.\n";
                } else {
                    string firstName, lastName1, lastName2, phoneNumber, email;
                    cout << "Introduce el nombre: ";
                    cin >> firstName;
                    cout << "Introduce el primer apellido: ";
                    cin >> lastName1;
                    cout << "Introduce el segundo apellido: ";
                    cin >> lastName2;
                    cout << "Introduce el numero de telefono: ";
                    cin >> phoneNumber;
                    cout << "Introduce el email: ";
                    cin >> email;
                    usuarioActivo->agregarContacto(firstName, lastName1, lastName2, phoneNumber, email);
                }
                break;
            case 5:
                if (usuarioActivo == nullptr) {
                    cout << "No hay ningun usuario logueado. Por favor, inicia sesion primero.\n";
                } else {
                    string criterio;
                    cout << "Introduce el nombre o el numero de telefono del contacto a eliminar: ";
                    cin >> criterio;
                    usuarioActivo->eliminarContacto(criterio);
                }
                break;
            case 6:
                if (usuarioActivo == nullptr) {
                    cout << "No hay ningun usuario logueado. Por favor, inicia sesion primero.\n";
                } else {
                    string criterio;
                    cout << "Introduce el nombre o el numero de telefono del contacto a buscar: ";
                    cin >> criterio;
                    usuarioActivo->buscarContacto(criterio);
                }
                break;
            case 7: // Transferir contacto
                if (usuarioActivo == nullptr) {
                    cout << "No hay ningun usuario logueado. Por favor, inicia sesion primero.\n";
                } else {
                    cout << "\n=== Transferencia de Contactos ===\n";
                    cout << "Esta opcion te permite transferir un contacto de tu lista a otro usuario.\n";
                    usuarioActivo->transferirContacto(usuarios, totalUsuarios); // Se pasa la lista de usuarios al método
                }
                break;
            case 8:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida. Intenta nuevamente.\n";
                break;
        }
    } while (opcion != 8);

    // Liberamos la memoria de los usuarios al salir
    delete usuario1;
    delete usuario2;
    delete usuario3;

    return 0;
}


