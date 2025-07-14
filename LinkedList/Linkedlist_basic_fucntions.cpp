#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList {
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() {
        head = tail = NULL;
        size = 0;
    }

    void insertAtTail(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void insertAtHead(int val) {
        Node* temp = new Node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insertAtIndex(int idx, int val) {
        if (idx < 0 || idx > size) {
            cout << "Invalid Index" << endl;
            return;
        } else if (idx == 0) {
            insertAtHead(val);
        } else if (idx == size) {
            insertAtTail(val);
        } else {
            Node* t = new Node(val);
            Node* temp = head;
            for (int i = 1; i < idx; i++) {
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }

    int getAtIndex(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid index" << endl;
            return -1;
        } else if (idx == 0) return head->val;
        else if (idx == size - 1) return tail->val;
        else {
            Node* temp = head;
            for (int i = 0; i < idx; i++) {
                temp = temp->next;
            }
            return temp->val;
        }
    }

    void deleteAtHead() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        head = head->next;
        size--;
    }

    void deleteAtTail() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
        size--;
    }

    void deleteAtIndex(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid index" << endl;
            return;
        } else if (idx == 0) {
            deleteAtHead();
        } else if (idx == size - 1) {
            deleteAtTail();
        } else {
            Node* temp = head;
            for (int i = 1; i < idx; i++) {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            size--;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int getSize() {
        return size;
    }
};

int main() {
    LinkedList list;

    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtHead(5);
    list.insertAtIndex(2, 15);
    list.display(); // 5 -> 10 -> 15 -> 20 -> 30 -> NULL

    cout << "Value at index 3: " << list.getAtIndex(3) << endl;

    list.deleteAtHead();
    list.deleteAtTail();
    list.deleteAtIndex(1);
    list.display(); // 10 -> 20 -> NULL

    cout << "Size of list: " << list.getSize() << endl;

    return 0;
}
