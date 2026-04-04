#include<iostream>
using namespace std;

class Node {
    public:

        int data;
        Node* next;

        // Constructor to initialise the value
        Node(int data) {
            this -> data = data;
            this -> next = nullptr;
        }
};

int main() {
    // Create and link nodes
    Node* head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next= new Node(40);
    head -> next -> next -> next -> next = nullptr; // Indicate the end of the list

    // Deleting the head node
    // Store the current head in the temporary pointer
    Node* temp = head;

    // Update head to the second node
    head = head -> next;

    // Free the memory of the old temp
    delete temp;

    // Print the linked list
    Node* current = head;
    while(current != nullptr) {
        cout<< current -> data << " ";
        current = current -> next;
    }
    cout<<endl;
}




    

