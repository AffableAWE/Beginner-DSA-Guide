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

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while(curr != nullptr) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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

    cout<< "List after reversal: ";
    head = reverseList(head);
    printList(head);
    return 0;
}


