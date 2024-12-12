#include <iostream>
#include "Contact_LinkedList.h"

int main() {
    // Crear la lista como un puntero
    LinkedList* contactList = new LinkedList();

    // Crear contactos
    Contact* contact1 = new Contact("John", "Doe", "Smith", "1234567890", "john.doe@example.com");
    Contact* contact2 = new Contact("Jane", "Doe", "Brown", "0987654321", "jane.doe@example.com");
    Contact* contact3 = new Contact("Alice", "Johnson", "White", "1122334455", "alice.johnson@example.com");

    // Insertar contactos en la lista
    std::cout << "Inserting contacts into the list...\n";
    contactList->insert_tail(contact1);
    contactList->insert_tail(contact2);
    contactList->insert_head(contact3);

    // Imprimir la lista
    std::cout << "\nCurrent contact list:\n";
    contactList->print();

    // Buscar un contacto por teléfono
    std::cout << "\nSearching for contact with phone number 0987654321...\n";
    Node* foundNode = contactList->search_by_phone("0987654321");
    if (foundNode) {
        std::cout << "Contact found:\n";
        foundNode->data->print();
    }

    // Modificar un contacto
    std::cout << "\nModifying contact with phone number 1234567890...\n";
    Contact* updatedContact = new Contact("John", "Doe", "Smith", "1234567890", "john.newemail@example.com");
    contactList->modify_contact("1234567890", updatedContact);

    std::cout << "\nCurrent contact list after modification:\n";
    contactList->print();

    // Eliminar un contacto por teléfono
    std::cout << "\nRemoving contact with phone number 1122334455...\n";
    if (contactList->remove_by_phone("1122334455")) {
        std::cout << "Contact removed successfully.\n";
    }

    // Intentar buscar un contacto eliminado
    std::cout << "\nSearching for removed contact with phone number 1122334455...\n";
    contactList->search_by_phone("1122334455");

    // Imprimir la lista después de eliminar
    std::cout << "\nCurrent contact list after deletion:\n";
    contactList->print();

    // Probar caso de lista vacía
    std::cout << "\nRemoving all contacts...\n";
    contactList->remove_by_phone("1234567890");
    contactList->remove_by_phone("0987654321");

    std::cout << "\nAttempting to print an empty list:\n";
    contactList->print();

    // Liberar la memoria
    delete contact1;
    delete contact2;
    delete contact3;
    delete updatedContact;
    delete contactList;

    return 0;
}
