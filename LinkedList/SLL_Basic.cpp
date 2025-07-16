#include<iostream>
using namespace std;
struct Node{
int data;
Node* next;
};
Node* first=NULL;

void Display(){
Node* temp=first;
if(first==NULL){
    cout<<"List is empty";
    return;
}
while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
}
}

Node* Create(int val){
Node* temp=new Node;
temp->data=val;
temp->next=NULL;

return temp;

}

void InsertFront(int val){
    Node* temp=Create(val);
    temp->next=first;
    first=temp;
}
void InsertEnd(int val){
    if(first==NULL){
        cout<<"List is Empty";
        return;
    }
    Node* temp=Create(val);
    Node* trav=first;
    if(first->next==NULL){
        first->next=temp;
    }
    while(trav->next!=NULL){
        trav=trav->next;
    }
    trav->next=temp;

}
void DeleteFront(){
Node* trav;
trav=first;

if(trav==NULL){
    cout<<"List is empty";
    return;
}
if(trav->next==NULL){
    trav->data=NULL;
    return;
}
first=first->next;
}
void DeleteEnd(){
Node*trav;
trav=first;

while(trav->next->next!=NULL){
trav=trav->next;
}
trav->next=NULL;
}

int main(){
int choice,val,info;
do{
cout<<"Enter your choice: ";
cin>>choice;

    switch(choice){
case 1:
     cout<<"Enter the value to insert:";
     cin>>val;
     InsertFront(val);
     break;
case 2:
    cout<<"Enter the value to insert:";
    cin>>val;
    InsertEnd(val);
    break;
case 3:
    cout<<"Enter the info and val:";
    cin>>info>>val;
 //   InsertAfter(info,val);
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

}while(choice!=0);


return 0;

}
