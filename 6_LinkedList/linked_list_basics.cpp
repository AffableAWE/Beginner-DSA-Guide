#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = nullptr;
    }
};

Node* deleteNode(Node* head, int value) {
    
    // If the list is empty
    if(head == nullptr) return nullptr;

    // Deletion of the head node
    if(head -> data == value) {
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }

    // Deletion of the other nodes
    Node* temp = head;
    while(temp -> next != nullptr) {
        if(temp -> next -> data == value) {
            Node* nodeToDelete = temp -> next;
            temp -> next = temp -> next -> next;
            delete nodeToDelete;
            return head;
        }
        temp = temp -> next;
    }
    return head;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = new Node(data);
    Node* temp = head;

    // If the linked list is empty
    if(head == nullptr) {
        return newNode;
    }

    // Adding the new node at the end
    while(temp -> next != nullptr) {
        temp = temp -> next;
    }

    temp -> next = newNode;
    return head;
}

void printList(Node* head) {
    Node* temp = head;

    while(temp != nullptr) {
        cout<< temp -> data << " " ;
        temp = temp -> next;
    }
    cout<< endl;
}

int main() {
    Node* head = nullptr;
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    
    cout<< "Original List: ";
    printList(head);
    
    cout<< "List after deleting 3 : ";
    head = deleteNode(head, 3);
    printList(head);

    cout<< "List after deleting 4 : ";
    head = deleteNode(head, 4);
    printList(head);

    cout<< "List after deleting 69 : ";
    head = deleteNode(head, 69);
    printList(head);
}






        
