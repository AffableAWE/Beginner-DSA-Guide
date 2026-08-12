#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

Node *insertAtEnd(Node *&head, int data) {

  // If the list is empty
  if (head == nullptr) {
    head = new Node(data);
    return head;
  }

  // Add a node to the end
  Node *temp = head;
  Node *newNode = new Node(data);
  while (temp->next != nullptr) {
    e temp = temp->next;
  }

  temp->next = newNode;
  return head;
}

void printList(Node *&head) {

  // If the list is empty
  if (head == nullptr)
    return;

  Node *temp = head;
  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

// Task 1: Insert at the Beginning
Node *insertAtBeginning(Node *&head, int data) {

  // If the list is empty
  if (head == nullptr) {
    Node *newNode = new Node(data);
    head = newNode;
    return head;
  }

  Node *newNode = new Node(data);
  newNode->next = head;
  head = newNode;

  return head;
}

// Task 2: Insert at a Specific Position
Node *insertAtSpecificPosition(Node *&head, int data, int position) {

  // If list is empty and Position is 0
  if (head == nullptr || position == 0) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return head;
  }

  Node *newNode = new Node(data);
  Node *current = head;
  int count = 0;

  // Traverse to the desired position or the end of the list
  while (current->next != nullptr && count < position - 1) {
    current = current->next;
    count++;
  }

  // Insert the new Node
  Node *temp = current->next;
  current->next = newNode;
  newNode->next = temp;

  return head;
}

// Deleting a node by value
Node *deleteByValue(Node *&head, int key) {

  // If the list is empty
  if (head == nullptr) {
    return head;
  }

  // If the first node matches the value
  if (head->data == key) {
    Node *temp = head;
    head = head->next;
    delete (temp);
    return head;
  }

  // Check for other nodes
  Node *temp = head;
  while (temp->next != nullptr) {
    if (temp->next->data == key) {
      Node *nodeToDelete = temp->next;
      temp->next = temp->next->next;
      delete (nodeToDelete);
      return head;
    } else {
      temp = temp->next;
    }
  }

  return head;
}

// Task 4: Free All Nodes (Memory Cleanup)
void freeAllNodes(Node *&head) {
  // If the list is empty
  if (head == nullptr) {
    return;
  }

  // Freeing all Nodes
  while (head != nullptr) {
    Node *temp = head;
    head = head->next;
    delete (temp);
  }
  head = nullptr;
}

// Task 5: Reverse the Linked List
Node *reverseTheList(Node *&head) {

  // If the list is empty
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  // Reversing all elements of the list
  Node *prev = nullptr;
  Node *curr = head;
  Node *next = nullptr;

  while (curr != nullptr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

int main() {
  Node *head = nullptr;
  head = insertAtEnd(head, 1);
  head = insertAtEnd(head, 3);
  head = insertAtEnd(head, 4);
  head = insertAtEnd(head, 5);

  cout << "Original List: " << endl;
  printList(head);

  insertAtBeginning(head, 0);
  cout << "After Inserting 0: " << endl;
  printList(head);

  insertAtSpecificPosition(head, 2, 2);
  cout << "After Insertion: " << endl;
  printList(head);

  cout << "List after deleting 5: " << endl;
  deleteByValue(head, 5);
  printList(head);

  cout << "After reversing the list: " << endl;
  reverseTheList(head);
  printList(head);
  return 0;
}
