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

    // Insert the Node at the beginning
    Node* temp = new Node(0);
    temp -> next = head;
    head = temp;

    // Insert the node at the end
    Node* current = head; // Start from the head node
    while(current -> next != nullptr) { // traverse till the last node
        current = current -> next;
    }
    current -> next = new Node(50); // Create and link the new node
 
    // Insert the node at the specific position 
    // Traverse to the node before the specific position
    current = head;
    int position = 3; // Lets say we want to insert at position 2
    int index = 1; 
    
    // Traverse to the node before the target position(pos - 1)
    while(index < position - 1 &&  current != nullptr) {
        current = current -> next;
        index++;
    }

    // Create the new node with desired data
    Node* newNode = new Node(25);

    // Link the new node to the node currently at position 2 
    newNode -> next = current -> next;

    // Link the node at position 1 to the new node
    current -> next = newNode;

    // Print the updated linked list to verify the insertions
    current = head;
    while(current != nullptr) {
        cout<< current -> data << " ";
        current = current -> next;
    }
    cout<<endl;
}
    

    

