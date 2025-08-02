#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

Node* create(int val) {
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void Display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void Insert_at_front(int val) {
    Node* newNode = create(val);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        head = newNode;
        temp->next = head;
    }
}

void Insert_at_end(int val) {
    Node* newNode = create(val);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

void Delete_front() {
    if (head == NULL) return;
    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        Node* last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
        delete temp;
    }
}

void Delete_end() {
    if (head == NULL) return;
    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }
}

void Insert_after(int key, int val) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        if (temp->data == key) {
            Node* newNode = create(val);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Key not found\n";
}

void Insert_before(int key, int val) {
    if (head == NULL) return;
    if (head->data == key) {
        Insert_at_front(val);
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    do {
        prev = temp;
        temp = temp->next;
        if (temp->data == key) {
            Node* newNode = create(val);
            newNode->next = temp;
            prev->next = newNode;
            return;
        }
    } while (temp != head);
    cout << "Key not found\n";
}

void Delete_at_index(int index) {
    if (head == NULL) return;
    if (index == 0) {
        Delete_front();
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    int count = 0;
    do {
        prev = temp;
        temp = temp->next;
        count++;
    } while (temp != head && count < index);
    if (temp == head) {
        cout << "Index out of bounds\n";
        return;
    }
    prev->next = temp->next;
    delete temp;
}

int main() {
    Insert_at_end(10);
    Insert_at_end(20);
    Insert_at_end(30);
    Display();

    Insert_at_front(5);
    Display();

    Insert_after(20, 25);
    Display();

    Insert_before(10, 7);
    Display();

    Delete_front();
    Display();

    Delete_end();
    Display();

    Delete_at_index(2);
    Display();

    return 0;
}
