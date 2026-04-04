#include <iostream>

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

Node* createLinkedList(int arr[], int size) {
    Node* head = nullptr;

    for(int i = 0; i < size; i++) {
        head = insertAtEnd(head, arr[i]);
    }
    return head;
}

Node* mergeTwoLists(Node* list1, Node* list2) {
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;
    
    Node* head = nullptr;
    if(list1 -> data <= list2 -> data) {
        head = list1;
        list1 = list1 -> next;
    }
    else {
        head = list2;
        list2 = list2 -> next;
    }

    Node* current = head;
    while(list1 != nullptr && list2 != nullptr) {
        if(list1 -> data <= list2 -> data) {
            current -> next = list1; // Attaching L1's node to the
            list1 = list1 -> next; // moving l1 forward
        }
        else {
            current -> next = list2;
            list2 = list2 -> next;
        }
        current = current -> next;
    }
        // Attach the remaining nodes from the non-empty list
        if (list1 != nullptr) {
            current -> next = list1;
        }
        else if (list2 != nullptr) {
            current -> next = list2;
        }

    return head;

}
void printList(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout<< temp -> data << " " ;
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node* head = nullptr;

    int arr1[3] = {1, 2, 4};
    int arr2[3] = {1, 3, 4};
   
    Node* list1 = createLinkedList(arr1, 3);
    Node* list2 = createLinkedList(arr2, 3);

    cout<< "Original List 1: ";
    printList(list1);
    
    cout<< "Original List 2: ";
    printList(list2);
    
    cout<< "Merged List : ";
    Node* mergeList = mergeTwoLists(list1, list2);
    printList(mergeList);
    return 0;
}


