//
// Created by Cochise Cabau on 26/11/2024. Modified 12/12/2024.
//

#include <iostream>
#include <string>

#ifndef CONTACT_LINKEDLIST_H
#define CONTACT_LINKEDLIST_H

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
        std::cout << "Name: " << firstName << " " << lastName1 << " " << lastName2
                  << ", Phone: " << phoneNumber << ", Email: " << email << std::endl;
    }
};

class Node {
public:
    Contact* data;
    Node* next;

    Node(Contact* data) : data(data), next(nullptr) {}

    ~Node() {
        delete data;
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
        while (size > 0) {
            remove_head();
        }
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

    bool remove_by_phone(const std::string& phoneNumber) {
        if (is_empty()) {
            std::cout << "List is empty!" << std::endl;
            return false;
        }

        if (first->data->phoneNumber == phoneNumber) {
            remove_head();
            return true;
        }

        Node* current = first;
        while (current->next != nullptr && current->next->data->phoneNumber != phoneNumber) {
            current = current->next;
        }

        if (current->next == nullptr) {
            std::cout << "Contact not found!" << std::endl;
            return false;
        }

        Node* to_delete = current->next;
        current->next = to_delete->next;
        if (to_delete == last) {
            last = current;
        }
        delete to_delete;
        size--;
        return true;
    }

    void remove_head() {
        if (is_empty()) {
            std::cout << "List is empty!" << std::endl;
            return;
        }

        Node* to_delete = first;
        first = first->next;
        if (first == nullptr) {
            last = nullptr;
        }
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
        std::cout << "Contact with phone number " << phoneNumber << " not found!" << std::endl;
        return nullptr;
    }

    void modify_contact(const std::string& phoneNumber, Contact* new_data) {
        Node* target = search_by_phone(phoneNumber);
        if (target == nullptr) {
            std::cout << "Contact with phone number " << phoneNumber << " not found!" << std::endl;
            return;
        }

        delete target->data;
        target->data = new_data;
    }

    void print() const {
        if (is_empty()) {
            std::cout << "List is empty!" << std::endl;
            return;
        }

        Node* current = first;
        while (current != nullptr) {
            current->data->print();
            current = current->next;
        }
    }
};

#endif
