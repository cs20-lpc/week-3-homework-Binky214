#include "LinkedList.hpp"
#include <iostream>

Node::Node(Student* student) : student(student), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp->student;
        delete temp;
    }
}

void LinkedList::insertEnd(Student* student) {
    Node* newNode = new Node(student);

    if (!head) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

void LinkedList::deleteById(int id) {
    if (!head) return;

    if (head->student->getId() == id) {
        Node* temp = head;
        head = head->next;
        delete temp->student;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next && current->next->student->getId() != id) {
        current = current->next;
    }

    if (current->next) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp->student;
        delete temp;
    }
}

Student* LinkedList::searchById(int id) const {
    Node* current = head;
    while (current) {
        if (current->student->getId() == id)
            return current->student;
        current = current->next;
    }
    return nullptr;
}

void LinkedList::displayAll() const {
    Node* current = head;
    if (!current) {
        std::cout << "No students in the list.\n";
        return;
    }

    while (current) {
        current->student->display();
        std::cout << "-------------------\n";
        current = current->next;
    }
}

int LinkedList::count() const {
    int c = 0;
    Node* current = head;
    while (current) {
        c++;
        current = current->next;
    }
    return c;
}
