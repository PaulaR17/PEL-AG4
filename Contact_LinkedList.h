#ifndef CONTACT_LINKEDLIST_H
#define CONTACT_LINKEDLIST_H

#include <iostream>
#include <string>

class Contact {
public:
    std::string firstName;
    std::string lastName1;
    std::string lastName2;
    std::string phoneNumber;
    std::string email;

    Contact(std::string firstName, std::string lastName1, std::string lastName2, std::string phoneNumber, std::string email)
        : firstName(firstName), lastName1(lastName1), lastName2(lastName2), phoneNumber(phoneNumber), email(email) {}

    void print() const {
        std::cout << "Nombre: " << firstName << " " << lastName1 << " " << lastName2
                  << ", Telefono: " << phoneNumber << ", Email: " << email << std::endl;
    }
};

class Node {
public:
    Contact* data;
    Node* next;

    Node(Contact* data) : data(data), next(nullptr) {}

    ~Node() {
        // Mejor aqui no liberamos `data` para evitar conflictos si se comparte
    }
};

class LinkedList {
private:
    Node* first;
    Node* last;
    int size;

public:
    LinkedList() : first(nullptr), last(nullptr), size(0) {}

    ~LinkedList() {
        clear(true); //por defecto, libera los contactos
    }

    bool is_empty() const {
        return size == 0;
    }

    int get_size() const {
        return size;
    }

    void insert_tail(Contact* data) {
        Node* new_node = new Node(data);
        if (is_empty()) {
            first = last = new_node;
        } else {
            last->next = new_node;
            last = new_node;
        }
        size++;
    }

    void insert_head(Contact* data) {
        Node* new_node = new Node(data);
        if (is_empty()) {
            first = last = new_node;
        } else {
            new_node->next = first;
            first = new_node;
        }
        size++;
    }

    bool remove_by_phone(const std::string& phoneNumber, bool deleteData = true) {
        if (is_empty()) {
            std::cout << "Lista vacia!" << std::endl;
            return false;
        }

        if (first->data->phoneNumber == phoneNumber) {
            remove_head(deleteData);
            return true;
        }

        Node* current = first;
        while (current->next != nullptr && current->next->data->phoneNumber != phoneNumber) {
            current = current->next;
        }

        if (current->next == nullptr) {
            std::cout << "Contacto no encontrado!" << std::endl;
            return false;
        }

        Node* to_delete = current->next;
        current->next = to_delete->next;
        if (to_delete == last) {
            last = current;
        }
        if (deleteData) delete to_delete->data;
        delete to_delete;
        size--;
        return true;
    }

    void remove_head(bool deleteData = true) {
        if (is_empty()) {
            std::cout << "Lista vacia!" << std::endl;
            return;
        }

        Node* to_delete = first;
        first = first->next;
        if (first == nullptr) {
            last = nullptr;
        }
        if (deleteData) delete to_delete->data;
        delete to_delete;
        size--;
    }

    Node* search_by_phone(const std::string& phoneNumber) {
        Node* current = first;
        while (current != nullptr) {
            if (current->data->phoneNumber == phoneNumber) {
                return current;
            }
            current = current->next;
        }
        std::cout << "No se encontro el numero de telefono:" << phoneNumber << std::endl;
        return nullptr;
    }

    void print() const {
        if (is_empty()) {
            std::cout << "Lista vacia!" << std::endl;
            return;
        }

        Node* current = first;
        while (current != nullptr) {
            current->data->print();
            current = current->next;
        }
    }

    void clear(bool deleteData = true) {
        while (!is_empty()) {
            remove_head(deleteData);
        }
    }
};

#endif
