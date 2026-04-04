#include <iostream>
using namespace std;

// Node in linked list using a class
class Node {
    public:
        int data;      // Holds the node's data
        Node* next;    // Pointer to the next node

        // Constructor to initialize the data and next pointer
        Node(int data) {
            this->data = data;  
            this->next = nullptr; 
        }
};

int main() {
    // Create a node dynamically in the heap and point to it using node1 (stored in the stack)
    Node* node1 = new Node(10);
    
    // Display the node's data and the next pointer
    cout << node1->data << endl;  // Outputs: 10
    cout << node1->next << endl;  // Outputs: 0 (nullptr)

    return 0;
}

// Node in Linked List using a structure
struct Node {
    int data;     // Holds the node's data
    Node* next;   // Pointer to the next node
};

int main() {
    Node* head = new Node(); // Create the first node dynamically
    head->data = 10;         
    head->next = nullptr;    

    // Add the second node and link it to the first node
    head->next = new Node();
    head->next->data = 20;
    head->next->next = nullptr;

    // Display the data and addresses of both nodes
    cout << "First Node Data: " << head->data << ", Next Node Address: " << head->next << endl;
    cout << "Second Node Data: " << head->next->data << ", Next Node Address: " << head->next->next << endl;

    // Reassign head to the second node, effectively losing the first node
    head = head->next;

    // Display the new head's data
    cout << "New Head Data: " << head->data << endl;  // Outputs: 20

}
