#include <iostream>
#include <unordered_set>

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

bool hasCycle(Node* head) {
    unordered_set<Node*> visited;

    Node* current = head;
    while(current != nullptr) {
        if(visited.find(current) != visited.end()) {
            // Cycle Detected
            return true;
        }
        visited.insert(current);
        current = current -> next;
    }
    return false;
}

int main() {
    Node* head = nullptr;

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 1);
    
    cout<< hasCycle(head) << endl;
   
 
}


