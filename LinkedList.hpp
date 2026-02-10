#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Student.hpp"

struct Node {
    Student* student;
    Node* next;

    Node(Student* student);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void insertEnd(Student* student);
    void deleteById(int id);
    Student* searchById(int id) const;
    void displayAll() const;
    int count() const;
};

#endif
