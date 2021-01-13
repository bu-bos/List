#ifndef MAIN_CPP_LIST_H
#define MAIN_CPP_LIST_H
#include <iostream>
using namespace std;
struct Node{
    int value;
    Node *next;
};

class List {
private:
    Node *head;
public:
    List() {
        head = nullptr;
    }

    int size() {
        Node *current = head;
        int i = 0;
        while (current != nullptr) {
            current = current->next;
            i++;
        }
        free(current);
        return i;
    }

    int change(int a, int b) {
        Node *current = head;
        Node *nd = new Node;
        if (head == nullptr) {
            cout << "No items" << endl;
            system("pause");
            return 1;
        } else {
            int i = size();
            if (a > i || a <= 0) {
                cout << "The number of elements does not allow changing" << endl;
                system("pause");
                return 1;
            } else {
                int j = 1;
                while (j < a) {
                    j++;
                    current = current->next;
                }
                nd->value = current->value;
                current->value = b;
                return nd->value;
            }
        }
        free(current);
        free(nd);
    }

    int pop(int a) {
        Node *current = head;
        Node *nd = new Node;
        int i = size();
        if (a > i || a <= 0) {
            cout << "The number of elements does not allow pop" << endl;
            system("pause");
            return 1;
        } else {
            if (a == 1) {
                head = head->next;
                return current->value;
            }
            else {
                int j = 1;
                while (j < a - 1) {
                    j++;
                    current = current->next;
                }
                nd = current->next;
                current->next = current->next->next;
                return nd->value;
            }
        }
        free(current);
        free(nd);
    }


    int Min() {
        Node *current = head;
        int i = size();
        if (i <= 1) {
            cout << "Number of elements < 2" << endl;
            system("pause");
            return 1;
        }else {
            int min;
            if (i >= 2) {
                min = current->value;
                for (int j = 0; j < i - 1; j++) {
                    if (min >= current->next->value)
                        min = current->next->value;
                    if (current->next != nullptr)
                        current = current->next;
                }
                return min;
            }
        }
        free(current);
    }


    int Max() {
        Node *current = head;
        int i = size();
        if (i <= 1) {
            cout << "number of elements < 2" << endl;
            system("pause");
            return 1;
        }
        else {
            int max;
            if (i >= 2) {
                max = current->value;
                for (int j = 0; j < i - 1; j++) {
                    if (max <= current->next->value)
                        max = current->next->value;
                    if (current->next != nullptr)
                        current = current->next;
                }
                return max;
            }
        }
        free(current);
    }


    int get(int a) {
        Node *current = head;
        Node *nd = new Node;
        int i = size();
        if (a > i || a <= 0) {
            cout << "number of elements does not allow get" << endl;
            system("pause");
            return 1;
        } else {
            int j = 1;
            while (j < a) {
                j++;
                current = current->next;
            }
            return current->value;
        }
        free(current);
    }

    void add(int a, int b) {
        Node *current = head;
        Node *nd = new Node;
        nd->value = b;
        if (head == nullptr && a == 1) {
            head = nd;
            head->next = nullptr;
            print_all();
        } else if (head == nullptr && a != 1)
            cout << "No";
        else if (a == 1) {
            head = nd;
            nd->next = current;
            print_all();
        } else {
            int i = size();
            if (a > i + 1 || a < 1) {
                cout << "No" << endl;
            } else {
                current = head;
                nd->value = b;
                int j = 1;
                while (j < a - 1) {
                    j++;
                    current = current->next;
                }
                nd->next = current->next;
                current->next = nd;
                print_all();
            }
        }
    }

    int find_val(int a) {
        Node *current = head;
        if (head == nullptr) {
            cout << "no items" << endl;
            system("pause");
            return 1;
        }
        int i = 1, c = 0;
        while (current->next != nullptr) {
            if (current->value == a) {
                c = i;
                if (c != 0)
                    cout << c << " ";
            }
            current = current->next;
            i++;
        }
        if (current->value == a) {
            c = i;
            cout << c;
        }
        if (c == 0) {
            cout << "not found" << endl;
            system("pause");
        }
        free(current);
    }

    void push(int d) {
        Node *nd = new Node;
        nd->value = d;
        nd->next = nullptr;
        if (head == nullptr)
            head = nd;
        else {
            Node *current = head;
            while (current->next != nullptr)
                current = current->next;
            current->next = nd;
        }
    }

    void print_all() {
        Node *current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        free(current);
    }
};












#endif //MAIN_CPP_LIST_H
