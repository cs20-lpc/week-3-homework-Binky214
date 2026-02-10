#include <iostream>
#include "LinkedList.hpp"
#include <sstream>

using namespace std;

int main() {
    LinkedList list;
    int choice;

    do {
        cout << "1. Insert Student" << endl
                  << "2. Delete Student by ID" << endl
                  << "3. Search Student by ID" << endl
                  << "4. Display All Students" << endl
                  << "5. Count Students" << endl
                  << "6. Add Course to Student" << endl
                  << "0. Exit" << endl
                  << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            double gpa;

            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter GPA: ";
            cin >> gpa;

            list.insertEnd(new Student(id, name, gpa));
        }

        else if (choice == 2) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            list.deleteById(id);
        }

        else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;

            Student* s = list.searchById(id);
            if (s)
                s->display();
            else
                cout << "Student not found.\n";
        }

        else if (choice == 4) {
            list.displayAll();
        }

        else if (choice == 5) {
            cout << "Total students: " << list.count() << endl;
        }

        else if (choice == 6) {
            int id;
            string cname, location;

            cout << "Enter Student ID: ";
            cin >> id;
            cin.ignore();

            Student* s = list.searchById(id);
            if (!s) {
                cout << "Student not found." << endl;
                continue;
            }

            cout << "Enter Course Name: ";
            getline(cin, cname);

            cout << "Enter Location: ";
            getline(cin, location);

            s->addCourse(cname, location);
        }

    } while (choice != 0);

    return 0;
}
