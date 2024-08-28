#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;

    // Default constructor
    node() {
        data = 0;
        next = NULL;
    }

    // Parameterized constructor
    node(int d) {
        data = d;
        next = NULL;
    }
};

class linked_list {
    node *head;

public:
    void insert_start(int d) {
        node *nn = new node(d);
        if(head==NULL){
            cout<<"List is empty..";
            head = nn;
            return;
        }
        else{
        nn->next = head; 
        head = nn;  
        }
            
    }

    
    void display() {
        node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl; 
    }
};

int main() {
    linked_list ll;
    ll.insert_start(10);
    ll.insert_start(20);
    ll.insert_start(30);

    cout << "Linked List: ";
    ll.display(); 
    return 0;
}
