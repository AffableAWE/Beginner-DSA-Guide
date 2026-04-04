#include<iostream> 
using namespace std;

Node* removeNthNodefromEnd(Node*& head, int n) {
    Node* slow = head;
    Node* fast = haed;

    for (int i = 0; i < n; i++) {
         fast = fast -> next;
    }

    if(fast == nullptr) {
        Node* temp = head -> next;
        head -> next = head -> next -> next;
        delete(temp);
    }

    while (fast -> != nullptr) {
        slow = slow -> next;
        fast = fast -> next;
    }

    Node* temp = slow -> next;
    slow -> next = slow -> next -> next;
    delete(temp);
    return head;

}

int main() {

}
