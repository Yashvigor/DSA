#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* first = NULL;

void Display(){
    Node* temp = first;
    if(first == NULL){
        cout << "List is empty";
        return;
    }
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* Create(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void InsertFront(int val){
    Node* temp = Create(val);
    temp->next = first;
    first = temp;
}

void InsertEnd(int val){
    Node* temp = Create(val);
    if(first == NULL){
        first = temp;
        return;
    }
    Node* trav = first;
    while(trav->next != NULL){
        trav = trav->next;
    }
    trav->next = temp;
}

void DeleteFront(){
    if(first == NULL){
        cout << "List is empty";
        return;
    }
    Node* temp = first;
    first = first->next;
    delete temp;
}

void DeleteEnd(){
    if(first == NULL){
        cout << "List is empty";
        return;
    }
    if(first->next == NULL){
        delete first;
        first = NULL;
        return;
    }
    Node* trav = first;
    while(trav->next->next != NULL){
        trav = trav->next;
    }
    delete trav->next;
    trav->next = NULL;
}

void InsertAfter(int info, int val){
    Node* trav = first;
    while(trav != NULL && trav->data != info){
        trav = trav->next;
    }
    if(trav != NULL){
        Node* temp = Create(val);
        temp->next = trav->next;
        trav->next = temp;
    }
}

int main(){
    int choice, val, info;
    do{
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter the value to insert:";
                cin >> val;
                InsertFront(val);
                break;
            case 2:
                cout << "Enter the value to insert:";
                cin >> val;
                InsertEnd(val);
                break;
            case 3:
                cout << "Enter the info and val:";
                cin >> info >> val;
                InsertAfter(info, val);
                break;
            case 4:
                DeleteFront();
                break;
            case 5:
                DeleteEnd();
                break;
            case 6:
                Display();
                break;
        }
    }while(choice != 0);
    return 0;
}
